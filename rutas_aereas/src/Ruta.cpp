#ifndef RUTA_H
#define RUTA_H

#include"Ruta.h"

Ruta::Ruta(){
    code="";
    list<Punto>::iterator p;
    for(p=puntos.begin();p!=puntos.end();++p){
        (*p).SetLatitud(0);
        (*p).SetLongitud(0);
    }
}

int Ruta::size() const{
    return puntos.size();
}

void Ruta::Insertar (const Punto & p){
    puntos.push_back(p);
}

bool Ruta::Borrar (const Punto & p){
    bool result=false;
    list<Punto>::iterator i;
    for(i=puntos.begin();i!=puntos.end();++i){
        if((*i)==p){
            puntos.erase(i);
            result=true;
        }
    }
    return result;
}

string Ruta::GetCode()const{
    return code;
}

void Ruta::SetCode(const string & cod){
    code=cod;
}

bool Ruta::operator==(const Ruta &R)const{
    return (code==R.GetCode());
}

bool Ruta::operator<(const Ruta &R)const{
    return puntos.size()<R.puntos.size();
}
//iterator

Ruta::iterator::iterator(){};

Punto& Ruta::iterator::operator*() const {
    return *p;
}

Ruta::iterator& Ruta::iterator::operator++(){
    ++p;
    return *this;
}

Ruta::iterator& Ruta::iterator::operator--(){
    --p;
    return *this;
}

bool Ruta::iterator::operator!=(const iterator& v)const{
    return p!=v.p;
}

bool Ruta::iterator::operator==(const iterator& v)const{
    return p==v.p;
}

//const_iterator

const Punto& Ruta::const_iterator::operator*() const {
    return *p;
}

Ruta::const_iterator& Ruta::const_iterator::operator++(){
    ++p;
    return *this;
}

Ruta::const_iterator& Ruta::const_iterator::operator--(){
    --p;
    return *this;
}

bool Ruta::const_iterator::operator!=(const const_iterator& v)const{
    return p!=v.p;
}

bool Ruta::const_iterator::operator==(const const_iterator& v)const{
    return p==v.p;
}
Ruta::const_iterator::const_iterator(){}
Ruta::const_iterator::const_iterator(const iterator & it){
    p=it.p;
}
//public
Ruta::iterator Ruta::begin(){
    Ruta::iterator it;
    it.p=puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::begin() const{
    Ruta::const_iterator it;
    it.p=puntos.begin();
    return it;
}

Ruta::iterator Ruta::end(){
    Ruta::iterator it;
    it.p=puntos.end();
    return it;
}

Ruta::const_iterator Ruta::end() const{
    Ruta::const_iterator it;
    it.p=puntos.end();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p){
    Ruta::iterator i;
    Ruta::iterator result;
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

istream & operator>>(istream & is, Ruta & R){
    R=Ruta();
    string c;
    is >> c;
    R.SetCode(c);
    int tam;
    is >> tam;
    if(tam){
        Punto p;
        for(int i=0;i<tam;i++){
            is >> p;
            R.Insertar(p);
        }
    }
    return is;
}
ostream & operator<<(ostream & os, const Ruta & R){
    int tam=R.puntos.size();
    os << R.GetCode() << " " <<  tam << " ";
    Ruta::const_iterator it=R.begin();
    for(;it!=R.end();++it){
        os << (*it) << " ";
    }
    return os;
}

#endif // RUTA_H



