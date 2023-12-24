#include "Paises.h"
Paises::Paises(){}
void Paises::Insertar(const Pais& P ){
    datos.insert(P);
}
void Paises::Borrar(const Pais& P){
     set<Pais>::iterator it=datos.begin();
	 for(;it!=datos.end();++it){
        if((*it).GetPais()==P.GetPais()){
            datos.erase(it);
        }
    }
}
Paises:: iterator Paises::end(){
	  iterator it;
	  it.p = datos.end();
	  return it;
}
Paises::iterator Paises::begin(){
	iterator it;
	it.p= datos.begin();
	return it;
}
Paises::const_iterator Paises::end()const{
	  const_iterator it;
	  it.p = datos.end();
	  return it;
}
Paises::const_iterator Paises::begin()const{
	  const_iterator it;
	  it.p = datos.begin();
	  return it;
}
Paises::iterator Paises::find(const Pais &p){
	iterator it;
	set<Pais>::iterator i;
	for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
	it.p=i;
	return it;
}
Paises::iterator Paises::find(const Punto &p){
	iterator it;
	set<Pais>::iterator i;
	for (i=datos.begin(); i!=datos.end() && !((*i).GetPunto()==p);++i);
	it.p=i;
	return it;
}
//iterador
set<Pais>::iterator Paises::iterator::getp(){
    return p;
}

Paises::iterator& Paises::iterator::operator=(const iterator& orig){
    if (this != &orig) {
        p = orig.p;
    }
    return *this;
}
const Pais& Paises::iterator::operator*(){
    return *p;
}


Paises::iterator& Paises::iterator::operator++(){
    ++p;
    return *this;
}

Paises::iterator& Paises::iterator::operator--(){
    --p;
    return *this;
}

bool Paises::iterator::operator!=(const iterator& v)const{
    return p!=v.p;
}

bool Paises::iterator::operator==(const iterator& v)const{
    return p==v.p;
}
//const iterador
set<Pais>::const_iterator Paises::const_iterator::getp(){
    return p;
}
const Pais& Paises::const_iterator::operator*()const{
    return *p;
}
Paises::const_iterator& Paises::const_iterator::operator=(const const_iterator& orig){
    if (this != &orig) {
        p = orig.p;
    }
    return *this;
}
Paises::const_iterator& Paises::const_iterator::operator++(){
    ++p;
    return *this;
}

Paises::const_iterator& Paises::const_iterator::operator--(){
    --p;
    return *this;
}

bool Paises::const_iterator::operator!=(const const_iterator& v)const{
    return p!=v.p;
}

bool Paises::const_iterator::operator==(const const_iterator& v)const{
    return p==v.p;
}
istream & operator>>(istream & is, Paises & R){
	Paises rlocal;
	//leemos el comentario
	if (is.peek()=='#'){
	string a;
	getline(is,a);
	}	
	      
	Pais P;
	while (is>>P){
	rlocal.Insertar(P);
		  
	}
	R=rlocal;
	return is;
}
ostream & operator<<(ostream & os, const Paises &R){
	  
	Paises::const_iterator it;
	for (it=R.begin(); it!=R.end(); ++it){
	os<<*it<<"\t";
	}
	return os;
}