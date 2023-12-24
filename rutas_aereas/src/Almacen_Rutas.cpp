#include"Almacen_Rutas.h"

Almacen_Rutas::Almacen_Rutas(){
    rutas.clear();
}

void Almacen_Rutas::Insertar(const Ruta& R){
    rutas[R.GetCode()] = R;
}

void Almacen_Rutas::Borrar (const Ruta & R){
    map<string,Ruta>::iterator it=rutas.begin();
    for(;it!=rutas.end();++it){
        if((*it).first==R.GetCode()){
            rutas.erase(it);
        }
    }
}

Ruta Almacen_Rutas::GetRuta(const string & s){
    map<string,Ruta>::iterator it=rutas.begin();
    Ruta r;
    for(;it!=rutas.end();++it){
        if((*it).first==s){
           r=(*it).second;
        }
    }
    return r;
}
//iterator
Almacen_Rutas::iterator::iterator(){}

Ruta& Almacen_Rutas::iterator::operator*()const{
    return p->second;
}

Almacen_Rutas::iterator& Almacen_Rutas::iterator::operator++(){
    ++p;
    return *this;
}

Almacen_Rutas::iterator& Almacen_Rutas::iterator::operator--(){
    --p;
    return *this;
}

bool Almacen_Rutas::iterator::operator!=(const iterator& v)const{
    return p!=v.p;
}

bool Almacen_Rutas::iterator::operator==(const iterator& v)const{
    return p==v.p;
}
//const iterator
Almacen_Rutas::const_iterator::const_iterator(){};
Almacen_Rutas::const_iterator::const_iterator(const iterator & it){
    p=it.p;
};

const Ruta& Almacen_Rutas::const_iterator::operator*()const{
    return p->second;
}

Almacen_Rutas::const_iterator& Almacen_Rutas::const_iterator::operator++(){
    ++p;
    return *this;
}

Almacen_Rutas::const_iterator& Almacen_Rutas::const_iterator::operator--(){
    --p;
    return *this;
}

bool Almacen_Rutas::const_iterator::operator!=(const const_iterator& v)const{
    return p!=v.p;
}

bool Almacen_Rutas::const_iterator::operator==(const const_iterator& v)const{
    return p==v.p;
}
//public
Almacen_Rutas::iterator Almacen_Rutas::begin(){
    iterator it;
    it.p=rutas.begin();
    return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::begin() const {
    const_iterator it;
    it.p=rutas.begin();
    return it;
}

Almacen_Rutas::iterator Almacen_Rutas::end(){
    iterator it;
    it.p=rutas.end();
    return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::end() const{
    const_iterator it;
    it.p=rutas.end();
    return it;
}

Almacen_Rutas::iterator Almacen_Rutas::find(const Ruta &p){
    Almacen_Rutas::iterator i;
    Almacen_Rutas::iterator result;
    for(i=begin();i!=end();++i){
        if(*i==p){
            result=i;
        }
        else{
            result=end();
        }
    }
    return result;
}

istream & operator>>(istream & is, Almacen_Rutas & R){
    string word;
    Ruta r;
    Ruta Puntos_interes;
    Punto p;
    is >> word;
    string MAGIC="#Rutas";
    string MAGIC_point="#Puntos_de_Interes";
    if(word==MAGIC){
        while(is >> r){
            R.Insertar(r);
            r=Ruta();
        }
    }
    return is;
}
ostream & operator<<(ostream & os, const Almacen_Rutas & R) {
    os << "#Rutas" << endl;
    Almacen_Rutas::const_iterator it = R.begin();  
    while (it != R.end()) {
        os << *it << endl << endl << endl;  
        ++it;  
    }
    return os;
}


