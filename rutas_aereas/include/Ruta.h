#include<iostream>
#include"Punto.h"
#include<list>
using namespace std;

/*
@author Ismael Sallami Moreno
@author Fernando José Gracía Choin
*/

/**
 * @brief Clase que representa una ruta compuesta por una lista de puntos.
 */
class Ruta{
private:
    list<Punto> puntos; ///< Lista de puntos que conforman la ruta.
    string code; ///< Código único de la ruta.

public:
    /**
     * @brief Constructor por defecto de la clase Ruta.
     */
    Ruta();

    /**
     *@return devuelve el tamaño de nuestra estructura list<Punto> puntos.
     */
    int size() const; 
	
    /**
     * @brief Inserta un punto en la ruta.
     * @param p Punto a insertar.
     */
    void Insertar(const Punto &p);

    /**
     * @brief Borra un punto de la ruta.
     * @param p Punto a borrar.
     * @return `true` si se eliminó el punto, `false` si el punto no estaba en la ruta.
     */
    bool Borrar(const Punto &p);

    /**
     * @brief Obtiene el código único de la ruta.
     * @return Código único de la ruta.
     */
    string GetCode() const;

    /**
     * @brief Sobrecarga del operador de comparación menor que.
     * @param R Ruta a comparar.
     * @return `true` si la ruta actual es menor que R, `false` en caso contrario.
     */
    bool operator<(const Ruta &R) const;

    /**
     * @brief Establece el código único de la ruta.
     * @param cod Nuevo código de la ruta.
     */
    void SetCode(const string &cod);

    /**
     * @brief Sobrecarga del operador de igualdad.
     * @param R Ruta a comparar.
     * @return `true` si las rutas son iguales, `false` en caso contrario.
     */
    bool operator==(const Ruta &R) const;

    /**
     * @brief Clase iterator para iterar sobre los puntos de la ruta.
     */
    class iterator{
    private:
        list<Punto>::iterator p; ///< Iterador interno a la lista de puntos.

    public:
        /**
         * @brief Constructor por defecto del iterator.
         */
        iterator();

        /**
         * @brief Sobrecarga del operador de desreferenciación.
         * @return Referencia al punto actual.
         */
        Punto& operator*() const;

        /**
         * @brief Sobrecarga del operador de incremento.
         * @return Referencia al iterator incrementado.
         */
        iterator& operator++();

        /**
         * @brief Sobrecarga del operador de decremento.
         * @return Referencia al iterator decrementado.
         */
        iterator& operator--();

        /**
         * @brief Sobrecarga del operador de desigualdad.
         * @param v Otro iterator a comparar.
         * @return `true` si los iterators son diferentes, `false` en caso contrario.
         */
        bool operator!=(const iterator& v) const;

        /**
         * @brief Sobrecarga del operador de igualdad.
         * @param v Otro iterator a comparar.
         * @return `true` si los iterators son iguales, `false` en caso contrario.
         */
        bool operator==(const iterator& v) const;

        friend class Ruta;
        friend class const_iterator;
    };

    /**
     * @brief Clase const_iterator para iterar sobre los puntos de la ruta (constante).
     */
    class const_iterator{
    private:
        list<Punto>::const_iterator p; ///< Iterador constante interno a la lista de puntos.

    public:
        /**
         * @brief Constructor por defecto del const_iterator.
         */
        const_iterator();

        /**
         * @brief Constructor del const_iterator a partir de un iterator.
         * @param it Iterator a convertir en const_iterator.
         */
        const_iterator(const iterator &it);

        /**
         * @brief Sobrecarga del operador de desreferenciación constante.
         * @return Referencia constante al punto actual.
         */
        const Punto& operator*() const;

        /**
         * @brief Sobrecarga del operador de incremento constante.
         * @return Referencia al const_iterator incrementado.
         */
        const_iterator& operator++();

        /**
         * @brief Sobrecarga del operador de decremento constante.
         * @return Referencia al const_iterator decrementado.
         */
        const_iterator& operator--();

        /**
         * @brief Sobrecarga del operador de desigualdad constante.
         * @param v Otro const_iterator a comparar.
         * @return `true` si los const_iterators son diferentes, `false` en caso contrario.
         */
        bool operator!=(const const_iterator& v) const;

        /**
         * @brief Sobrecarga del operador de igualdad constante.
         * @param v Otro const_iterator a comparar.
         * @return `true` si los const_iterators son iguales, `false` en caso contrario.
         */
        bool operator==(const const_iterator& v) const;

        friend class Ruta;
    };

    /**
     * @brief Obtiene un iterator que apunta al primer punto de la ruta.
     * @return Iterator que apunta al primer punto.
     */
    iterator begin();

    /**
     * @brief Obtiene un const_iterator que apunta al primer punto de la ruta (constante).
     * @return Const_iterator que apunta al primer punto.
     */
    const_iterator begin() const;

    /**
     * @brief Obtiene un iterator que apunta al final de la lista de puntos de la ruta.
     * @return Iterator que apunta al final de la lista.
     */
    iterator end();

    /**
     * @brief Obtiene un const_iterator que apunta al final de la lista de puntos de la ruta (constante).
     * @return Const_iterator que apunta al final de la lista.
     */
    const_iterator end() const;

    /**
     * @brief Busca un punto en la ruta.
     * @param p Punto a buscar.
     * @return Iterator que apunta al punto encontrado, o end() si no se encuentra.
     */
    iterator find(const Punto &p);

    /**
     * @brief Sobrecarga del operador de entrada para leer una ruta desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param R Ruta a leer.
     * @return Referencia al flujo de entrada.
     */
    friend istream &operator>>(istream &is, Ruta &R);

    /**
     * @brief Sobrecarga del operador de salida para escribir una ruta en un flujo de salida.
     * @param os Flujo de salida.
     * @param R Ruta a escribir.
     * @return Referencia al flujo de salida.
     */
    friend ostream &operator<<(ostream &os, const Ruta &R);
};
