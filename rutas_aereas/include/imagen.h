#include<iostream>
using namespace std; 
/*
@author Ismael Sallami Moreno
@author Fernando José Gracía Choin
*/


/**
 * @brief Enumeración que representa los tipos de pegado para la clase Imagen.
 */
enum Tipo_Pegado{
    OPACO, ///< Pegado opaco.
    BLENDING ///< Pegado con blending.
};

/**
 * @brief Estructura que representa un píxel en una imagen.
 */
struct Pixel{
    unsigned char r, g, b; ///< Componentes de color: rojo, verde y azul.
    unsigned char transp; ///< Transparencia (0 si no es transparente, 255 si es transparente).
};

/**
 * @brief Clase que representa una imagen.
 */
class Imagen{
private:
    Pixel **datos; ///< Puntero bidimensional donde se almacena la información de la imagen.
    int nf, nc; ///< Número de filas (nf) y columnas (nc) de la imagen.

    // Funciones privadas para gestionar la memoria
    void Borrar(); ///< Libera la memoria ocupada por la imagen.
    void Copiar(const Imagen &I); ///< Copia la imagen.

public:
    /**
     * @brief Constructor por defecto de la clase Imagen.
     */
    Imagen();

    /**
     * @brief Constructor de copia de la clase Imagen.
     * @param I Imagen a copiar.
     */
    Imagen(const Imagen &I);

    /**
     * @brief Constructor de la clase Imagen con parámetros.
     * @param f Número de filas.
     * @param c Número de columnas.
     */
    Imagen(int f, int c);

    /**
     * @brief Destructor de la clase Imagen.
     */
    ~Imagen();

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param I Imagen a asignar.
     * @return Referencia a la imagen asignada.
     */
    Imagen &operator=(const Imagen &I);

    /**
     * @brief Devuelve el número de filas de la imagen.
     * @return Número de filas.
     */
    int num_filas() const;

    /**
     * @brief Devuelve el número de columnas de la imagen.
     * @return Número de columnas.
     */
    int num_cols() const;

    /**
     * @brief Sobrecarga del operador de acceso para modificar un píxel.
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @return Referencia al píxel en la posición (i, j).
     */
    Pixel &operator()(int i, int j);

    /**
     * @brief Sobrecarga del operador de acceso para leer un píxel.
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @return Referencia constante al píxel en la posición (i, j).
     */
    const Pixel &operator()(int i, int j) const;

    /**
     * @brief Escribe la imagen en disco.
     * @param nombre Nombre del archivo de salida.
     */
    void EscribirImagen(const char *nombre);

    /**
     * @brief Lee una imagen de disco.
     * @param nombre Nombre del archivo de entrada.
     * @param nombre_mascara Nombre de la máscara opcional.
     */
    void LeerImagen(const char *nombre, string nombre_mascara = "");

    /**
     * @brief Limpia la transparencia de la imagen.
     */
    void LimpiarTransp();

    /**
     * @brief Pega una imagen sobre otra en una posición específica.
     * @param posi Posición vertical de la esquina superior izquierda.
     * @param posj Posición horizontal de la esquina superior izquierda.
     * @param I Imagen a pegar.
     * @param tippegado Tipo de pegado (OPACO o BLENDING).
     */
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado = OPACO);

    /**
     * @brief Extrae una subimagen de la imagen.
     * @param posi Posición vertical de la esquina superior izquierda de la subimagen.
     * @param posj Posición horizontal de la esquina superior izquierda de la subimagen.
     * @param dimi Número de filas de la subimagen.
     * @param dimj Número de columnas de la subimagen.
     * @return Subimagen extraída.
     */
    Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);

    /**
     * @brief Clase Iterator para iterar sobre los píxeles de la imagen.
     */
    class Iterator{
    private:
        Pixel **puntero; ///< Puntero al píxel actual.
        int filas, columnas; ///< Número de filas y columnas de la imagen.
        int fila_actual, columna_actual; ///< Posición actual del iterador.

    public:
        /**
         * @brief Constructor del Iterator.
         * @param ptr Puntero al píxel actual.
         * @param filas Número de filas de la imagen.
         * @param columnas Número de columnas de la imagen.
         */
        Iterator(Pixel **ptr, int filas, int columnas);

        /**
         * @brief Sobrecarga del operador de desreferenciación.
         * @return Referencia al píxel actual.
         */
        Pixel &operator*();

        /**
         * @brief Sobrecarga del operador de incremento (pre-incremento).
         * @return Referencia al iterador incrementado.
         */
        Iterator &operator++();

        /**
         * @brief Sobrecarga del operador de desigualdad.
         * @param otro Otro Iterator a comparar.
         * @return `true` si los iteradores son diferentes, `false` en caso contrario.
         */
        bool operator!=(const Iterator &otro) const;
    };

    /**
     * @brief Clase Iterator para iterar sobre los píxeles de la imagen.
     */
    class const_iterator{
    private:
        Pixel **puntero; ///< Puntero al píxel actual.
        int filas, columnas; ///< Número de filas y columnas de la imagen.
        int fila_actual, columna_actual; ///< Posición actual del iterador.

    public:
        /**
         * @brief Constructor del Iterator.
         * @param ptr Puntero al píxel actual.
         * @param filas Número de filas de la imagen.
         * @param columnas Número de columnas de la imagen.
         */
        const_iterator(Pixel **ptr, int filas, int columnas);

        /**
         * @brief Sobrecarga del operador de desreferenciación.
         * @return Referencia al píxel actual.
         */
        Pixel &operator*();

        /**
         * @brief Sobrecarga del operador de incremento (pre-incremento).
         * @return Referencia al iterador incrementado.
         */
        const_iterator &operator++();

        /**
         * @brief Sobrecarga del operador de desigualdad.
         * @param otro Otro Iterator a comparar.
         * @return `true` si los iteradores son diferentes, `false` en caso contrario.
         */
        bool operator!=(const const_iterator &otro) const;
    };

    /**
     * @brief Método para obtener el Iterator de inicio de la imagen.
     * @return Iterator que apunta al primer píxel de la imagen.
     */
    Iterator begin();

    /**
     * @brief Método para obtener el Iterator de fin de la imagen.
     * @return Iterator que apunta al píxel siguiente al último de la imagen.
     */
    Iterator end();

    /**
     * @brief Método para obtener el Iterator de inicio de la imagen.
     * @return Iterator que apunta al primer píxel de la imagen.
     */
    const_iterator begin()const;

    /**
     * @brief Método para obtener el Iterator de fin de la imagen.
     * @return Iterator que apunta al píxel siguiente al último de la imagen.
     */
    const_iterator end() const;
};
