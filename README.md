# Práctica Rutas Aéreas

![](https://github.com/Ismael-Sallami/Air-lines-Project/raw/main/rutas_aereas/doc/fondo.png)

# Introducción

En el transcurso de esta práctica, hemos explorado una fascinante opción: la capacidad de crear un sistema de rutas aéreas mediante la provisión de diversos datos al programa. Estos datos incluyen información crucial como el tipo de avión a utilizar, su máscara, las coordenadas geográficas de los países en el mapa terrestre, el lienzo donde se trazarán las rutas, las respectivas banderas de los países y un archivo con diversas rutas predefinidas. La singularidad de esta experiencia radica en la capacidad del programa para generar la ruta deseada a partir de los datos suministrados.

Desde una perspectiva educativa, esta práctica ha sido sumamente enriquecedora, ya que ha abordado una amplia gama de conceptos y estructuras aprendidas a lo largo de la asignatura de Estructura de Datos. La complejidad del proyecto no solo ha puesto a prueba nuestra comprensión de los fundamentos teóricos, sino que también ha demandado la aplicación práctica de dichos conocimientos en un contexto real y desafiante.

La intersección de variables como el tipo de avión y sus especificaciones, junto con la geografía detallada de los países, ha exigido una cuidadosa manipulación de datos y un diseño eficiente de algoritmos. La necesidad de incorporar un mapa visual y las banderas de los países ha añadido una dimensión estética al proyecto, demostrando la importancia de la usabilidad y la presentación en el desarrollo de software.

En este proceso, hemos tenido la oportunidad de consolidar nuestros conocimientos sobre estructuras de datos, algoritmos y técnicas de programación avanzadas. La resolución de problemas prácticos, como la generación de rutas aéreas, ha requerido una combinación de creatividad y rigurosidad técnica. Además, la gestión eficiente de recursos y la optimización de la ejecución del programa han sido aspectos fundamentales para lograr un sistema robusto y eficaz

# Ejecutables

![](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/doc/rotacion.png)
## Roatción de una imagen

Rota la imagen proporcionando una serie de parámetros

> __Pruebarotacion__ \<FichImagenOriginal\> \<ánguloRotación\> \<FichImagenDestino\>
@param "<FichImagenOriginal>" Imagen PGM que se va a rotar.
@param "<ánguloRotación>" ángulo que vamos a rotar la imagen.
@param <FichImagenDestino> Imagen PGM resultado, donde vamos a almacenar la imagen rotada.

La función "Pruebarotacion" tiene como objetivo principal rotar una imagen en formato PGM (Portable Gray Map) mediante la aplicación de un ángulo de rotación especificado.

![](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/doc/pegado.png)
## Pegado de una imagen en otra:
Pega la imagen en otra, seleccionando el tipo Opaco o Blending

> __pruebapegado__ \<Imagendondepegar\> \<Imagenquepegar\> \<mascaradelaimagenquepegar\> \<filapegado\> \<columnapegado\> \<tipopegado\>
@param "<Imagendondepegar>" Imagen  donde pegar la otra imagen pgm.
@param <Imagenquepegar> Imagen para pegar en la imagen anterior 
@param <mascaradelaimagenquepegar> Máscara de la imagen para pegarla.
@param <filapegado> fila a partir de la cual comienza el pegado.
@param <columnapegado> columna a partir de la cual comienza el pegado.
@param <tipopegado> 0 es opaco, y 1 es blending

La función "pruebapegado" tiene como finalidad unir dos imágenes, permitiendo al usuario seleccionar entre dos tipos de pegado: opaco (0) o blending (1). 

![](https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/doc/PLANE.png)
## Generar y pintar ruta aérea

Este programa obtiene un mapa del mundo sobre el que se ha pintado una ruta elegida. Para
tal objetivo el usuario insertará un fichero con un conjunto de países y un almacén de rutas y una imagen de un mapa del mundo
junto con la imagen del avión y su máscara. Además se debe indicar el directorio donde se
almacena las banderas de cada país (en el ejemplo siguiente dir_banderas). 
> __ruta_aerea__ \<paises.txt\> \<mapa.ppm\> \<dir_banderas\> \<almacen_rutas.txt\> \<avion.ppm\> \<mascara_avion.ppm\>
@param <paises.txt> fichero de paises para leerlo.
@param <mapa.ppm> mapa donde pegar la ruta.
@param <dir_banderas> directorio con las banderas.
@param <almacen_rutas.txt> fichero con las rutas para elegir la que deseamos pintar en el mapa.
@param <avion.ppm> imagen de avion para pegar
@param <mascara_avion.ppm> mascara del avion para pegar


# Conclusión: 

Durante esta práctica, creamos un sistema de generación de rutas aéreas que destaca por su versatilidad al procesar diversos datos, como tipo de avión, coordenadas geográficas y elementos visuales. Esta experiencia enriqueció nuestra comprensión de estructuras de datos y algoritmos, exigiendo la aplicación práctica de estos conceptos.

Desde el manejo eficiente de datos hasta la integración de elementos visuales como mapas y banderas, enfrentamos desafíos que resaltaron la importancia de la usabilidad en el desarrollo de software. Consolidamos conocimientos en programación avanzada, resolviendo problemas prácticos con creatividad y precisión técnica. En conclusión, esta práctica representó una valiosa oportunidad para aplicar teorías en un proyecto significativo, destacando la complejidad y diversidad de desafíos en el desarrollo de software para manipulación de imágenes y datos geográficos.

# Realizado por:

Ismael Sallami Moreno & Fernando José Gracia Choin

ALUMNOS DE 2 DEL DOBLE GRADO INFORMÁTICA-ADE
UNIVERSIDAD DE GRANADA

# Author:
<img src="https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/Ismael_sallami.png" width="300"/>



