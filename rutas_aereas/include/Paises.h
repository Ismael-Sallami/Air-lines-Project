#include "Pais.h"
#include <set>
using namespace std;

#ifndef PAISES
#define PAISES

/*
@author Ismael Sallami Moreno
@author Fernando José Gracía Choin
*/

/**
 * @brief Clase que representa un conjunto de países.
 */
class Paises {
private:
    set<Pais> datos; ///< Conjunto de países.

public:
    /**
     * @brief Constructor por defecto de la clase Paises.
     */
    Paises();

    /**
     * @brief Inserta un país en el conjunto.
     * @param P País a insertar.
     */
    void Insertar(const Pais &P);

    /**
     * @brief Borra un país del conjunto.
     * @param P País a borrar.
     */
    void Borrar(const Pais &P);

    /**
     * @brief Clase iterator para iterar sobre los países en el conjunto.
     */
    class iterator {
    private:
        set<Pais>::iterator p; ///< Iterador interno al conjunto de países.

    public:
        /**
         * @brief Obtiene el iterador interno al conjunto de países.
         * @return Iterador interno al conjunto de países.
         */
        set<Pais>::iterator getp();

        /**
         * @brief Sobrecarga del operador de asignación.
         * @param orig Iterador a copiar.
         * @return Referencia al iterador actual.
         */
        iterator &operator=(const iterator &orig);

        /**
         * @brief Sobrecarga del operador de desreferenciación.
         * @return Referencia al país actual.
         */
        const Pais &operator*();

        /**
         * @brief Sobrecarga del operador de incremento.
         * @return Referencia al iterador incrementado.
         */
        iterator &operator++();

        /**
         * @brief Sobrecarga del operador de decremento.
         * @return Referencia al iterador decrementado.
         */
        iterator &operator--();

        /**
         * @brief Sobrecarga del operador de desigualdad.
         * @param v Otro iterator a comparar.
         * @return `true` si los iteradores son diferentes, `false` en caso contrario.
         */
        bool operator!=(const iterator &v) const;

        /**
         * @brief Sobrecarga del operador de igualdad.
         * @param v Otro iterator a comparar.
         * @return `true` si los iteradores son iguales, `false` en caso contrario.
         */
        bool operator==(const iterator &v) const;

        friend class Paises;
        friend class const_iterator;
    };

    /**
     * @brief Clase const_iterator para iterar sobre los países en el conjunto (constante).
     */
    class const_iterator {
    private:
        set<Pais>::const_iterator p; ///< Iterador constante interno al conjunto de países.

    public:
        /**
         * @brief Obtiene el iterador constante interno al conjunto de países.
         * @return Iterador constante interno al conjunto de países.
         */
        set<Pais>::const_iterator getp();

        /**
         * @brief Sobrecarga del operador de asignación.
         * @param orig Iterador constante a copiar.
         * @return Referencia al iterador constante actual.
         */
        const_iterator &operator=(const const_iterator &orig);

        /**
         * @brief Sobrecarga del operador de desreferenciación constante.
         * @return Referencia constante al país actual.
         */
        const Pais &operator*() const;

        /**
         * @brief Sobrecarga del operador de incremento constante.
         * @return Referencia al iterador constante incrementado.
         */
        const_iterator &operator++();

        /**
         * @brief Sobrecarga del operador de decremento constante.
         * @return Referencia al iterador constante decrementado.
         */
        const_iterator &operator--();

        /**
         * @brief Sobrecarga del operador de desigualdad constante.
         * @param v Otro const_iterator a comparar.
         * @return `true` si los const_iteradores son diferentes, `false` en caso contrario.
         */
        bool operator!=(const const_iterator &v) const;

        /**
         * @brief Sobrecarga del operador de igualdad constante.
         * @param v Otro const_iterator a comparar.
         * @return `true` si los const_iteradores son iguales, `false` en caso contrario.
         */
        bool operator==(const const_iterator &v) const;

        friend class Paises;
    };

    /**
     * @brief Obtiene un iterator que apunta al primer país en el conjunto.
     * @return Iterator que apunta al primer país.
     */
    iterator begin();

    /**
     * @brief Obtiene un const_iterator que apunta al primer país en el conjunto (constante).
     * @return Const_iterator que apunta al primer país.
     */
    const_iterator begin() const;

    /**
     * @brief Obtiene un iterator que apunta al final del conjunto de países.
     * @return Iterator que apunta al final del conjunto.
     */
    iterator end();

    /**
     * @brief Obtiene un const_iterator que apunta al final del conjunto de países (constante).
     * @return Const_iterator que apunta al final del conjunto.
     */
    const_iterator end() const;

    /**
     * @brief Busca un país en el conjunto.
     * @param p País a buscar.
     * @return Iterator que apunta al país encontrado, o end() si no se encuentra.
     */
    iterator find(const Pais &p);

    /**
     * @brief Busca un país en el conjunto por su ubicación (Punto).
     * @param p Punto a buscar.
     * @return Iterator que apunta al país encontrado, o end() si no se encuentra.
     */
    iterator find(const Punto &p);

    /**
     * @brief Sobrecarga del operador de entrada para leer un conjunto de países desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param R Conjunto de países a leer.
     * @return Referencia al flujo de entrada.
     */
    friend istream &operator>>(istream &is, Paises &R);

    /**
     * @brief Sobrecarga del operador de salida para escribir un conjunto de países en un flujo de salida.
     * @param os Flujo de salida.
     * @param R Conjunto de países a escribir.
     * @return Referencia al flujo de salida.
     */
    friend ostream &operator<<(ostream &os, const Paises &R);
};

#endif 
