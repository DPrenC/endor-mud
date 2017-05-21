/**************************************************************************
fichero: minas.h
Autor: Riberales
Creación: 10/10/05
Descripción: El archivo h para las minas de Kha-annu.
**************************************************************************/

#ifndef __MINAS_H__
#define __MINAS_H__



// Define para el contador.
#define CONTADOR (DOM_STD "contador_minas")

//define para la salida, a ver si se pone en kha-annu.h:
#define CAM_KHA_KEN(x)    HABITACION "caminos/kha-kenton/" + x

// Directorios de las minas
#define HAB_MINAS(x)         HABITACION "kha-annu/minas/" + x
#define PNJ_MINAS(x)         PNJ("minas/" + x)

// habitación base de las minas de Kha-annu
#define BASE_MINAS           HAB_MINAS("base_minas")


// directorios de las plantas de las minas
#define HAB_PRIMERA_MINAS(x)  HAB_MINAS("planta01/" + x)
#define HAB_SEGUNDA_MINAS(x)  HAB_MINAS("planta02/" + x)
#define HAB_TERCERA_MINAS(x)  HAB_MINAS("planta03/" + x)


// objetos de la zona de minas de Kha-annu
#define ARMA_MINAS(x)        ARMA("minas/" + x)
#define PROT_MINAS(x)        PROT("minas/" + x)
#define OTRO_MINAS(x)        OTRO("minas/" + x)

// Macro:

#ifndef SEXO
#define SEXO TP->QueryGenderEndString()
#endif

#endif
