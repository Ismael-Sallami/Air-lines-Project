#include<iostream>
#include<string>
using namespace std;

#ifndef PUNTO_H
#define PUNTO_H

/*
@author Ismael Sallami Moreno
@author Fernando José Gracía Choin
*/

/**
 * @brief Clase que representa un punto en el mapa con coordenadas geográficas.
 */
class Punto {
private:
    double latitud; ///< Latitud del punto.
    double longitud; ///< Longitud del punto.
    string _id; ///< Identificador del punto.

public:
    /**
     * @brief Constructor por defecto de la clase Punto.
     */
    Punto();

    /**
     * @brief Constructor de la clase Punto con parámetros.
     * @param l Latitud del punto.
     * @param L Longitud del punto.
     * @param d Identificador del punto (por defecto, cadena vacía).
     */
    Punto(double l, double L, const string &d = "");

    /**
     * @brief Obtiene la latitud del punto.
     * @return Latitud del punto.
     */
    double GetLatitud() const;

    /**
     * @brief Obtiene la longitud del punto.
     * @return Longitud del punto.
     */
    double GetLongitud() const;

    /**
     * @brief Establece la latitud del punto.
     * @param l Nueva latitud del punto.
     */
    void SetLatitud(double l);

    /**
     * @brief Establece la longitud del punto.
     * @param l Nueva longitud del punto.
     */
    void SetLongitud(double l);

    /**
     * @brief Sobrecarga del operador de comparación menor que.
     * @param p Punto a comparar.
     * @return `true` si el punto actual es menor que p, `false` en caso contrario.
     */
    bool operator<(const Punto &p) const;

    /**
     * @brief Sobrecarga del operador de igualdad.
     * @param p Punto a comparar.
     * @return `true` si los puntos son iguales, `false` en caso contrario.
     */
    bool operator==(const Punto &p) const;

    /**
     * @brief Sobrecarga del operador de entrada para leer un Punto desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param p Punto a leer.
     * @return Referencia al flujo de entrada.
     */
    friend istream &operator>>(istream &is, Punto &p);

    /**
     * @brief Sobrecarga del operador de salida para escribir un Punto en un flujo de salida.
     * @param os Flujo de salida.
     * @param p Punto a escribir.
     * @return Referencia al flujo de salida.
     */
    friend ostream &operator<<(ostream &os, const Punto &p);
};

#endif // PUNTO_H
