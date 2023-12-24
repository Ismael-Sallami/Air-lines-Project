#include"Punto.h"

Punto::Punto():longitud(0),latitud(0){

}

Punto::Punto(double l,double L,const string &id):longitud(L),latitud(l),_id(id){

}

double Punto::GetLatitud()const{
    return latitud;
}
double Punto::GetLongitud()const{
    return longitud;
}
void Punto::SetLatitud(double l) {
    latitud=l;
}
void Punto::SetLongitud(double l){
    longitud=l;
}
bool Punto::operator<(const Punto &p) const{
    bool menor=true;
    if(GetLongitud()<p.GetLongitud()) menor=true;

    else if(GetLongitud()==p.GetLongitud()){
        if(GetLatitud()<p.GetLatitud()){
            menor=true;
        }
    }
    return  menor;
}
bool Punto::operator==(const Punto &p)const{
    return (longitud==p.longitud && latitud==p.latitud);
}
istream & operator>>(istream & is, Punto &p){
    p.SetLatitud(0);
    p.SetLongitud(0);
    double l;
    char c;
    is >> c;
    is >> l;
    p.SetLatitud(l);
    is >> c;
    is >> l;
    p.SetLongitud(l);
    is >> c;
    return is;
}
ostream & operator<<(ostream & os, const Punto &p){
    os <<"( " << p.GetLatitud() << ", " << p.GetLongitud() << " )";
    return os;
}

