#include<iostream>
#include<map>
#include"Ruta.h"

/*
@author Ismael Sallami Moreno
@author Fernando José Gracía Choin
*/

/**
 * @brief Clase que representa un Almacén de Rutas.
 */
class Almacen_Rutas{
    private:
    map<string,Ruta> rutas; 
    public:
    /**
     * @brief Constructor por defecto de Almacen_Rutas.
     */
    Almacen_Rutas();

      /**
     * @brief Inserta una nueva Ruta en el Almacén.
     * @param R La Ruta a insertar.
     */
    void Insertar(const Ruta& R);

    /**
     * @brief Borra una Ruta del Almacén.
     * @param R La Ruta a borrar.
     */
    void Borrar (const Ruta & R);

    /**
     * @brief Obtiene una Ruta por su nombre.
     * @param s El nombre de la Ruta a obtener.
     * @return La Ruta correspondiente al nombre.
     */
    Ruta GetRuta(const string & s);

    class const_iterator;

    /**
     * @brief Clase iterator para iterar sobre las Rutas en el Almacén.
     */
    class iterator{
        private:
        map<string,Ruta>::iterator p; ///< Iterador interno.
        public:
        iterator(); ///< Constructor por defecto de iterator.
        Ruta& operator*()const; ///< Sobrecarga del operador de desreferenciación.
        iterator& operator++(); ///< Sobrecarga del operador de incremento.
        iterator& operator--(); ///< Sobrecarga del operador de decremento.
        bool operator!=(const iterator& v)const; ///< Sobrecarga del operador de desigualdad.
        bool operator==(const iterator& v)const; ///< Sobrecarga del operador de igualdad.
        friend class const_iterator; ///< Permite el acceso de const_iterator a los miembros privados.
        friend class Almacen_Rutas; ///< Permite el acceso de Almacen_Rutas a los miembros privados.
    };

     /**
     * @brief Clase const_iterator para iterar sobre las Rutas en el Almacén (constante).
     */
    class const_iterator{
        private:
        map<string,Ruta>::const_iterator p;///< Iterador constante interno.
        public:
        const_iterator();///< Constructor por defecto.
        const_iterator(const iterator& it);///< Constructor de const_iterator a partir de un iterator.
        const Ruta& operator*()const;///< Sobrecarga del operador de desreferenciación constante.
        const_iterator& operator++();///< Sobrecarga del operador de incremento constante.
        const_iterator& operator--();///< Sobrecarga del operador de decremento constante.
        bool operator!=(const const_iterator& v)const;///< Sobrecarga del operador de desigualdad constante
        bool operator==(const const_iterator& v)const;///< Sobrecarga del operador de igualdad constante.
        friend class Almacen_Rutas;///< Permite el acceso de Almacen_Rutas a los miembros privados de la clase.
    };

    /**
     * @brief Obtiene un iterator que apunta al primer elemento del Almacén.
     * @return Un iterator que apunta al primer elemento.
     */
    iterator begin();

    /**
     * @brief Obtiene un const_iterator que apunta al primer elemento del Almacén (constante).
     * @return Un const_iterator que apunta al primer elemento.
     */
    const_iterator begin() const;

      /**
     * @brief Obtiene un iterator que apunta al final del Almacén.
     * @return Un iterator que apunta al final.
     */
    iterator end();

     /**
     * @brief Obtiene un const_iterator que apunta al final del Almacén (constante).
     * @return Un const_iterator que apunta al final.
     */
    const_iterator end() const;

    /**
     * @brief Busca una Ruta en el Almacén.
     * @param p La Ruta a buscar.
     * @return Un iterator que apunta a la Ruta encontrada, o end() si no se encuentra.
     */
    iterator find(const Ruta &p);

     /**
     * @brief Sobrecarga del operador de entrada para leer un Almacén_Rutas desde un flujo de entrada.
     * @param is El flujo de entrada.
     * @param R La instancia de Almacen_Rutas a leer.
     * @return La referencia al flujo de entrada.
     */
    friend istream & operator>>(istream & is, Almacen_Rutas & R);

    /**
     * @brief Sobrecarga del operador de salida para escribir un Almacén_Rutas en un flujo de salida.
     * @param os El flujo de salida.
     * @param R La instancia de Almacen_Rutas a escribir.
     * @return La referencia al flujo de salida.
     */
    friend ostream & operator<<(ostream & os, const Almacen_Rutas & R);
};
