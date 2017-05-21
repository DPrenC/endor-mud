/**
 * /sys/domain.h
 */

/*
NOTA: El fichero que haga un #include a este debe definir la constante
      DOMINIO con el nombre del dominio al que se pertenezca. Este
      fichero sera en principio el fichero base de cada dominio. Ej:
      En el dominio "dominio_de_ejemplo" se tiene el siguiente fichero
      /d/dominio_de_ejemplo/sys/dominio_de_ejemplo.h, este debera tener
      estas dos lineas
      #define DOMINIO "dominio_de_ejemplo"
      #include <domain.h>
*/

/*
.-----------------------------------------------------------------------.
|  DIRECTORIOS                                                          |
'-----------------------------------------------------------------------'
*/

/* includes standard */
#ifndef __DOMINIO_H__
#define __DOMINIO_H__

//#include <combat.h>
#include <rooms.h> // Para los refresh...
//#include <properties.h>
#include <config.h>
//#include <moving.h>
//#include <attributes.h>

/* Directorios principales */

/*
#ifndef DOMINIO
#define DOMINIO "limbo"
#endif
*/

#define RAIZ  	DPATH DOMINIO "/"   // Dir. Raiz
#define COMUN   RAIZ "comun/"       // Direc. Comun
#define DOM_STD RAIZ "std/"         // Direc. Estandares
#define DOM_SYS RAIZ "sys/"	        // Direc. sistema
#define LOGS    DOMAINLOGPATH DOMINIO "/"        // Logs

/* Directorios standard con codigo */
#define HABITACION        COMUN "habitacion/" // Direc. Habitaciones
#define GREMIO            COMUN "gremio/"     // Direc. Gremios
#define QUEST             COMUN "quest/"      // Direc. Quests
#define PNJ(x)            COMUN "pnj/"+x      // Npc's
#define OBJETO            COMUN "objeto/"     // Objetos
#define TRANSPORTE        COMUN "transporte/"

/* Directorios con codigo de objetos */

#define ARMA(x)            OBJETO "arma/"+x        // Armas
#define PROT(x)            OBJETO "proteccion/"+x   // Proteccion
#define BEBIDA(x)          OBJETO "bebida/"+x       // Bebida
#define COMIDA(x)          OBJETO "comida/"+x       // Comidas
#define HECHIZO(x)         OBJETO "hechizo/"+x      // Hechizos
#define MAGIA(x)           OBJETO "magia/"+x        // Obj. magicos
#define OTRO(x)            OBJETO "otro/"+x         // Otros

/* Directorios con codigo de transportes */

#define DILIGENCIA(x)     TRANSPORTE + "diligencia/" + x
#define CARAVANA(x)       TRANSPORTE + "caravana/" + x
#define BARCO(x)          TRANSPORTE + "barco/" + x

/* Directorios de la bilioteca de objetos estándares del mud */

#define ARMAS(x)	    "/obj/armas/"+x		//Biblioteca de armas
#define ARMADURAS(x)	"/obj/armaduras/"+x	//Biblioteca de armaduras
#define ROPA(x)	"/obj/ropa/"+x	//Biblioteca de ropa
#define ANIMALES(x)	"/obj/npc/animales/"+x	//Biblioteca de animales standard
#define OTROS(x)    "/obj/otros/"+x  // objetos que hay en /obj/otros
#endif /* __DOMINIO_H */