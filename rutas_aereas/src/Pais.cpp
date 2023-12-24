#include "Pais.h"
Pais::Pais(){
    p=Punto();
    pais="";
    bandera="";
}
string Pais::GetPais()const{return pais;}

Punto Pais::GetPunto()const{return p;}

string Pais::GetBandera()const{return bandera;}


bool Pais::operator==(const Pais &P)const{
    return (pais==P.GetPais());
}

bool Pais::operator==(const Punto &P)const{
    return (p==P);
}
istream & operator>>(istream & is, Pais & P){
    double lat,lng;
	
	is>>lat>>lng>>P.pais>>P.bandera;
	
	P.p=Punto(lat,lng);
	return is;
}
ostream & operator<<(ostream & os, const Pais &P){
	os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
	return os;
}

bool Pais::operator<(const Pais &P)const{
	return (p.GetLongitud()<P.GetPunto().GetLongitud());
}


