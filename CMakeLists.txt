cmake_minimum_required(VERSION 3.16)
project(practicafinal)

set(CMAKE_CXX_STANDARD 14)
set(BASE_FOLDER rutas_aereas)

include_directories(${BASE_FOLDER}/include)

add_library(image ${BASE_FOLDER}/src/imagen.cpp  ${BASE_FOLDER}/src/imagenES.cpp)
add_library(almacen_rutas ${BASE_FOLDER}/src/Punto.cpp ${BASE_FOLDER}/src/Pais.cpp ${BASE_FOLDER}/src/Paises.cpp
${BASE_FOLDER}/src/Ruta.cpp ${BASE_FOLDER}/src/Almacen_Rutas.cpp)

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebarotacion.cpp)
add_executable(pruebarotacion ${BASE_FOLDER}/src/pruebarotacion.cpp)
target_link_libraries(pruebarotacion LINK_PUBLIC image)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebapegado.cpp)
add_executable(pruebapegado ${BASE_FOLDER}/src/pruebapegado.cpp)
target_link_libraries(pruebapegado LINK_PUBLIC image)
endif()
if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebamia.cpp)
add_executable(pruebamia ${BASE_FOLDER}/src/pruebamia.cpp)
target_link_libraries(pruebamia LINK_PUBLIC image)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/ruta_aerea.cpp)
add_executable(ruta_aerea ${BASE_FOLDER}/src/ruta_aerea.cpp)
target_link_libraries(ruta_aerea LINK_PUBLIC image)
target_link_libraries(ruta_aerea LINK_PUBLIC almacen_rutas)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/prueba_punto.cpp)
add_executable(prueba_punto ${BASE_FOLDER}/src/prueba_punto.cpp)
target_link_libraries(prueba_punto LINK_PUBLIC image)
target_link_libraries(prueba_punto LINK_PUBLIC almacen_rutas)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/prueba_pais.cpp)
add_executable(prueba_pais ${BASE_FOLDER}/src/prueba_pais.cpp)
target_link_libraries(prueba_pais LINK_PUBLIC image)
target_link_libraries(prueba_pais LINK_PUBLIC almacen_rutas)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/prueba_paises.cpp)
add_executable(prueba_paises ${BASE_FOLDER}/src/prueba_paises.cpp)
target_link_libraries(prueba_paises LINK_PUBLIC image)
target_link_libraries(prueba_paises LINK_PUBLIC almacen_rutas)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/prueba_ruta.cpp)
add_executable(prueba_ruta ${BASE_FOLDER}/src/prueba_ruta.cpp)
target_link_libraries(prueba_ruta LINK_PUBLIC image)
target_link_libraries(prueba_ruta LINK_PUBLIC almacen_rutas)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/prueba_almacen_rutas.cpp)
add_executable(prueba_almacen_rutas ${BASE_FOLDER}/src/prueba_almacen_rutas.cpp)
target_link_libraries(prueba_almacen_rutas LINK_PUBLIC image)
target_link_libraries(prueba_almacen_rutas LINK_PUBLIC almacen_rutas)
endif()

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
