/**************************************************************************
fichero: annufam.h
Autor: kastwey
Creación: 20/07/2005
Descripción: Fichero h para annufam
[t] 19/02/2007 Añadido P_SIZE_NORMAL como P_SIZE_GENERIC
**************************************************************************/

#ifndef __ANNUFAM_H__
#define __ANNUFAM_H__


// servidor de climas de la zona de Annufam
#define SERVER_ANNUFAM        DOM_STD "annufam/server_climas"

// habitación base de la zona de Annufam
#define BASE_ANNUFAM           DOM_STD "annufam/base_annufam.c"


// habitación base de la ciudad de annufam
#define BASE_CIUDAD_ANNUFAM    DOM_STD "annufam/ciudad_base.c"



// Directorios de annufam
#define HAB_ANNUFAM(x)         HABITACION "annufam/" + x
#define PNJ_ANNUFAM(x)         PNJ("annufam/" + x)
// defensor base de las murallas
#define DEFENSOR_BASE_ANNUFAM  PNJ_ANNUFAM("defensor_base")
// PNJ base de annufam
#define PNJ_BASE_ANNUFAM      PNJ_ANNUFAM("pnj_base")


// directorios de la ciudad de Annufam
#define HAB_CIUDAD_ANNUFAM(x)  HAB_ANNUFAM("ciudad/" + x)
#define HAB_CALLES_ANNUFAM(x)  HAB_CIUDAD_ANNUFAM("calles/" + x)
#define HAB_AVENIDA_ANNUFAM(x) HAB_CALLES_ANNUFAM("avenida/" + x)
#define HAB_THUALIN_ANNUFAM(x)  HAB_CALLES_ANNUFAM("thualin/" + x)
#define HAB_UNGRIM_ANNUFAM(x)   HAB_CALLES_ANNUFAM("ungrim/" + x)
#define HAB_POSADA_ANNUFAM(x)   HAB_CIUDAD_ANNUFAM("posada/" + x)
#define HAB_FOSO_ANNUFAM(x)     HAB_CIUDAD_ANNUFAM("foso/" + x)
#define HAB_TABERNAS_ANNUFAM(x) HAB_CIUDAD_ANNUFAM("tabernas/" + x)
#define HAB_TIENDAS_ANNUFAM(x)  HAB_CIUDAD_ANNUFAM("tiendas/" + x)
#define HAB_HERRERIA_ANNUFAM(x) HAB_TIENDAS_ANNUFAM("herreria/" + x)
#define HAB_MURALLAS_ANNUFAM(x) HAB_CIUDAD_ANNUFAM("murallas/" + x)
#define HAB_SENDERO_ANNUFAM(x)  HAB_ANNUFAM("sendero/" + x)
#define HAB_CAMINO_ANNUFAM(x)  HAB_ANNUFAM("sendero/" + x)
#define HAB_CENTRO_ANNUFAM(x)  HAB_ANNUFAM("centro_entrenamiento/" + x)


// objetos de la ciudad de Annufam
#define COMIDA_ANNUFAM(x)      COMIDA("annufam/" + x)
#define BEB_ANNUFAM(x)         BEBIDA("annufam/" + x)
#define ARMA_ANNUFAM(x)        ARMA("annufam/" + x)
#define PROT_ANNUFAM(x)        PROT("annufam/" + x)
#define OTRO_ANNUFAM(x)        OTRO("annufam/" + x)

// pnjs de la ciudad de Annufam
#define PNJ_CIUDAD_ANNUFAM(x)  PNJ_ANNUFAM("ciudad/" + x)
#define PNJ_CENTRO_ANNUFAM(x)  PNJ_ANNUFAM("centro_entrenamiento/" + x)
#define PNJ_SENDERO_ANNUFAM(x) PNJ_ANNUFAM("sendero/" + x)



//Directorios del centro de entrenamiento.
#define HAB_ARENA_ANNUFAM(x)      HAB_CENTRO_ANNUFAM("arena/"+x)
#define HAB_PRIMERA_ANNUFAM(x)    HAB_CENTRO_ANNUFAM("planta01/"+x)
#define HAB_SEGUNDA_ANNUFAM(x)    HAB_CENTRO_ANNUFAM("planta02/"+x)
#define HAB_TERCERA_ANNUFAM(x)    HAB_CENTRO_ANNUFAM("planta03/"+x)


// objetos del centro de entrenamiento
#define ARMA_CENTRO_ANNUFAM(x)   ARMA_ANNUFAM("centro_entrenamiento/" + x)
#define PROT_CENTRO_ANNUFAM(x) PROT_ANNUFAM("centro_entrenamiento/" + x)
#define OTRO_CENTRO_ANNUFAM(x) OTRO_ANNUFAM("centro_entrenamiento/" + x)

// tipos de estandartes
#define EST_NORMAL             0
#define EST_SALA               1
#define EST_DESPACHO           2

// razas enemigas de los enanos
#define RAZASENEMIGAS          ({"gigante","troll","demonio","orco"})

// tiempo en el que el portón permanece cerrado
#define HORAS_PORTON_CERRADO   ({ND_NIGHT, ND_PREDAWN})

// CAGE
#define CAGE_TESTER				"tagoras"
#define CAGE_LICENSED			"cage_licensed"
#define CAGE_MIN_LEVEL			6
#define CAGE_PLACAS				OTRO_ANNUFAM("placas")
#define CAGE_TRAITOR			"cage_traitor"

// macros
#ifndef AO
#define AO                     (TP->QueryGender() == 2 ? "a" : "o")
#endif
#ifndef OBAO(x)
#define OBAO(x)                (x->QueryGender() == 2 ? "a" : "o")
#endif
#ifndef LALO
#define LALO                   (TP->QueryGender() == 2 ?"la" : "lo")
#endif


#define P_SIZE_NORMAL	P_SIZE_GENERIC
#endif
