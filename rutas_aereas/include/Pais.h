#include "Punto.h"
#include <string>
using namespace std;

/*
@author Ismael Sallami Moreno
@author Fernando José Gracía Choin
*/

/**
 * @brief Clase que representa un país.
 */
class Pais {
private:
    Punto p; ///< Objeto Punto que representa la ubicación del país.
    string pais; ///< Nombre del país.
    string bandera; ///< Ruta o descripción de la bandera del país.

public:
    /**
     * @brief Constructor por defecto de la clase Pais.
     */
    Pais();

    /**
     * @brief Obtiene el objeto Punto que representa la ubicación del país.
     * @return Objeto Punto que representa la ubicación del país.
     */
    Punto GetPunto() const;

    /**
     * @brief Obtiene el nombre del país.
     * @return Nombre del país.
     */
    string GetPais() const;

    /**
     * @brief Obtiene la ruta o descripción de la bandera del país.
     * @return Ruta o descripción de la bandera del país.
     */
    string GetBandera() const;

    /**
     * @brief Sobrecarga del operador de comparación menor que.
     * @param P Objeto Pais a comparar.
     * @return `true` si el país actual es menor que P, `false` en caso contrario.
     */
    bool operator<(const Pais &P) const;

    /**
     * @brief Sobrecarga del operador de igualdad entre dos objetos Pais.
     * @param P Objeto Pais a comparar.
     * @return `true` si los países son iguales, `false` en caso contrario.
     */
    bool operator==(const Pais &P) const;

    /**
     * @brief Sobrecarga del operador de igualdad entre un objeto Pais y un objeto Punto.
     * @param P Objeto Punto a comparar.
     * @return `true` si el país actual tiene la misma ubicación que P, `false` en caso contrario.
     */
    bool operator==(const Punto &P) const;

    /**
     * @brief Sobrecarga del operador de entrada para leer un objeto Pais desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param P Objeto Pais a leer.
     * @return Referencia al flujo de entrada.
     */
    friend istream &operator>>(istream &is, Pais &P);

    /**
     * @brief Sobrecarga del operador de salida para escribir un objeto Pais en un flujo de salida.
     * @param os Flujo de salida.
     * @param P Objeto Pais a escribir.
     * @return Referencia al flujo de salida.
     */
    friend ostream &operator<<(ostream &os, const Pais &P);
};
