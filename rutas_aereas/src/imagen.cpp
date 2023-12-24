#include"imagen.h"
#include<cassert>
#include"imagenES.h"

//IMPLEMENTACIÓN DEL ITERADOR
Imagen::Iterator::Iterator(Pixel **ptr, int filas, int columnas)
    : puntero(ptr), filas(filas), columnas(columnas), fila_actual(0), columna_actual(0) {}

// Implementación de la sobrecarga de operadores del Iterador
Pixel& Imagen::Iterator::operator*() {
    return puntero[fila_actual][columna_actual];
}

Imagen::Iterator& Imagen::Iterator::operator++() {
    if (++columna_actual == columnas) {
        columna_actual = 0;
        ++fila_actual;
    }
    return *this;
}

bool Imagen::Iterator::operator!=(const Imagen::Iterator& otro) const {
    return fila_actual != otro.fila_actual || columna_actual != otro.columna_actual;
}

// Implementación de los métodos begin() y end()
Imagen::Iterator Imagen::begin() {
    return Iterator(datos, nf, nc);
}

Imagen::Iterator Imagen::end() {
    return Iterator(datos + nf, nf, nc);
}

//FINALIZA LA IMPLEMENTACIÓN DEL ITERADOR

//IMPLEMENTACIÓN DEL CONST_ITERATOR
Imagen::const_iterator::const_iterator(Pixel **ptr, int filas, int columnas)
    : puntero(ptr), filas(filas), columnas(columnas), fila_actual(0), columna_actual(0) {}

// Implementación de la sobrecarga de operadores del Iterador
Pixel& Imagen::const_iterator::operator*() {
    return puntero[fila_actual][columna_actual];
}

Imagen::const_iterator& Imagen::const_iterator::operator++() {
    if (++columna_actual == columnas) {
        columna_actual = 0;
        ++fila_actual;
    }
    return *this;
}

bool Imagen::const_iterator::operator!=(const Imagen::const_iterator& otro) const {
    return fila_actual != otro.fila_actual || columna_actual != otro.columna_actual;
}

// Implementación de los métodos begin() y end()
Imagen::const_iterator Imagen::begin() const{
    return const_iterator(datos, nf, nc);
}

Imagen::const_iterator Imagen::end() const{
    return const_iterator(datos + nf, nf, nc);
}
//FINALIZA LA IMPLEMENTACIÓN DEL CONST_ITERATOR
void Imagen::Borrar(){
    for(int i=0;i<nf;++i){
        delete[]datos[i];
    }

    delete[] datos;
}

void Imagen::Copiar(const Imagen &I){
    nf = I.nf;
    nc = I.nc;
    datos = new Pixel*[nf];
    for (int i = 0; i < nf; ++i) {
        datos[i] = new Pixel[nc];
        for (int j = 0; j < nc; ++j) {
            datos[i][j] = I.datos[i][j];
        }
    }
}

Imagen::Imagen(){
    nf=0;
    nc=0;
    datos=nullptr;
}

Imagen::Imagen(const Imagen &I){
    Copiar(I);
}

Imagen::Imagen(int f,int c){
  nf = f;
  nc = c;
  datos = new Pixel*[nf];
  for (int i=0;i<nf;i++){
    datos[i]=new Pixel[nc];
    for (int j=0;j<nc;j++){
	datos[i][j].r=255;
	datos[i][j].g=255;
	datos[i][j].b=255;
	datos[i][j].transp=255;
    }
  }  


}


Imagen::~Imagen(){
    if(datos){
        Borrar();
    }
    nc=nf=0;
    datos=0;
}

Imagen & Imagen::operator =(const Imagen & I){
    if(this!=&I){
        Borrar();
        Copiar(I);
    }
    return *this;
}

int Imagen::num_filas()const{
    return nf;
}
int Imagen::num_cols()const{
    return nc;
} 


Pixel & Imagen::operator()(int i,int j){
    assert(i>=0 && i<nf && j>=0 && j<nc);
    return datos[i][j];
}
const Pixel & Imagen::operator()(int i,int j) const{
    assert(i>=0 && i<nf && j>=0 && j<nc);
    return datos[i][j];
}

void Imagen::EscribirImagen (const char *nombre){
    unsigned char * aux = new unsigned char [nf*nc*3];
    unsigned char * m = new unsigned char [nf*nc];
      
    int total = nf*nc*3;
    for (int i=0;i<total;i+=3){
	    int posi = i /(nc*3);
	    int posj = (i%(nc*3))/3;
	    
	    aux[i]=datos[posi][posj].r;
	    aux[i+1]=datos[posi][posj].g;
	    aux[i+2]=datos[posi][posj].b;
	    m[i/3]=datos[posi][posj].transp;
	     
	 }    
	
    if (!EscribirImagenPPM (nombre, aux,nf,nc)){
	    cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
    }	  
    delete[]aux;
    string n_aux = "mascara_";
    n_aux =n_aux+nombre;
    std::size_t found =n_aux.find(".ppm");
    if (found!=std::string::npos){
	    n_aux =n_aux.substr(0,found);
    }
    n_aux =n_aux+".pgm";

      
    if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
	  cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
    }	    
    delete []m;
}

void Imagen::LeerImagen(const char *nombre, string nombre_mascara){
    int f,c;
    unsigned char * aux,*aux_mask ;
      
    LeerTipoImagen(nombre, f, c);
    aux = new unsigned char [f*c*3];
    LeerImagenPPM (nombre, f,c,aux);
    if (nombre_mascara!=""){
        int fm,cm;
        LeerTipoImagen(nombre_mascara.c_str(), fm, cm);
        aux_mask = new unsigned char [fm*cm];
        LeerImagenPGM(nombre_mascara.c_str(), fm,cm,aux_mask);
    }
    else{
	    aux_mask=0;
    }	
      
    Imagen I(f,c);
    int total = f*c*3;
    for (int i=0;i<total;i+=3){
	   int posi = i /(c*3);
	   int posj = (i%(c*3))/3;
	    //cout<<posi<<" " <<posj<<endl;
	    I.datos[posi][posj].r=aux[i];
	    I.datos[posi][posj].g=aux[i+1];
	    I.datos[posi][posj].b=aux[i+2];
	    if (aux_mask!=0)
	      I.datos[posi][posj].transp=aux_mask[i/3];
	     else  
	       I.datos[posi][posj].transp=255;
	}    
	  
    *this = I;   
    if (aux_mask!=0) delete[]aux_mask;
      delete []aux;
      
}

void Imagen::PutImagen(int posi,int posj, const Imagen & I, Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);
    
    for (int i=0;i<I.nf;i++)
      for (int j=0;j<I.nc;j++)
	        if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
	            if (I.datos[i][j].transp!=0){
	                if (tippegado==OPACO)
	                    datos[i+posi][j+posj]=I.datos[i][j];
	                else{
                        datos[i+posi][j+posj].r=(datos[i+posi][j+posj].r+I.datos[i][j].r)/2;
                        datos[i+posi][j+posj].g=(datos[i+posi][j+posj].r+I.datos[i][j].g)/2;
                        datos[i+posi][j+posj].b=(datos[i+posi][j+posj].r+I.datos[i][j].b)/2;
	                }  
	  
	            }  
	        }       
}

void Imagen::LimpiarTransp(){
    for (int i = 0; i < nf; ++i) {
        for (int j = 0; j < nc; ++j) {
            datos[i][j].transp = 0;  // Establecer la transparencia a cero para cada píxel
        }
    }

}

Imagen Imagen::ExtraeImagen(int posi,int posj,int dimi,int dimj){
     // Verificar si las coordenadas están dentro de los límites de la imagen
    assert(posi >= 0 && posi + dimi <= nf && posj >= 0 && posj + dimj <= nc);

    // Crear una nueva instancia de Imagen con las dimensiones especificadas
    Imagen imagenExtraida(dimi, dimj);

    // Copiar los píxeles de la región de la imagen original a la nueva instancia
    for (int i = 0; i < dimi; ++i) {
        for (int j = 0; j < dimj; ++j) {
            imagenExtraida.datos[i][j] = datos[posi + i][posj + j];
        }
    }

    return imagenExtraida;
}
