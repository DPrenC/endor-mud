/*
FICHERO      : /d/simauria/sys/simauria.h
DESCRIPCION  : Contiene abreviaciones, paths, valores y objetos pertenecientes
               al dominio de Simauria.
MODIFICACION :
[n] Nemesis, [m] Mirill, [Ch] Chaos, [B] Bomber, [z] Zomax, [T] Tyflos,
[a] angor
                        
31-10-97 [n][m] Creacion
02-10-01 [Ch][B] Modificacion parte Nyne 
??-??-?? [n] Y parte de los otros defines, mamones, que os habéis cargado 
         medio dominio... Y por cierto, Maler... haz el favor de comentar 
         en la cabecera los cambios que haces, ¿quieres?
??-??-?? [n] Añadida la variable para SetLocate(Simauria City) 
??-??-?? [z] Defines para Rhoemas y añado 3 lineas en las funciones de libreria
??-??-?? [n] Insertados los defines para las Grutas de Azmodan que ha realizado
         Kodex con sus patitas. 
??-??-?? [n] Insertados los defines para la Torre de Gundistyr que realizó 
         Articman para poder ser wiz del rollo
14-01-05 [T] Insertados los defines para el poblado de Enalel
03-06-08 [a] organiza esto un poco contra su voluntad por que esta hecho unos zorros...

*/

#ifndef __SIMAURIA_H__
#define __SIMAURIA_H__

/* Nombre del dominio */

#define DOMINIO  "simauria"

/* include standard para todos los dominios */
#include <domain.h>    // estructura de dominios standard
#include <weather.h>    // funciones pal clima

/*
.-----------------------------------------------------------------------.
|  PARTE PARTICULAR PARA ESTE DOMINIO                                   |
'-----------------------------------------------------------------------'
*/

#define SIM_SYS         "/d/simauria/sys/"    // El directorio de los includes

// a cargarse este alias?
#define ROOMS           HABITACION

#define SIM_ROOM        DOM_STD "sim_room"  // habitacion simauria
#define SERVER          DOM_STD "clima" // Servidor de Clima
#define PAL_ROOM        DOM_STD "sim_pal" // habitacion del Palacio de Simauria
#define JR_ROOM         DOM_STD "jard_room" // habitacion de los Jardines Reales
#define CAMINOS         "/d/simauria/comun/habitacion/caminos"
#define CNS(x)          CAMINOS "/nandor-simauria/" + x
#define GUILDS          "/guilds/"
#define GORPNJ(x)       PNJ("gorat/" + x)

/* diligencias */
#define RHOEK(x)        DILIGENCIA("rhoek/" + x)
#define ZEPAR(x)        DILIGENCIA("zepar/" + x)
#define MASHER(x)       DILIGENCIA("masher/" + x)
#define PORHALT(x)       DILIGENCIA("porhalt/" + x)

/* barcos */
#define RADIANTE(x)     BARCO("radiante/" + x)

// Dominios o regiones de los humanos
#define SIMAURIA        HABITACION "simauria/"
#define BETWA           HABITACION "betwa/"
#define SORQUER         HABITACION "sorquer/"
#define HALIBUT         HABITACION "halibut/"
#define MARHALT         HABITACION "marhalt/"
#define GALAHUD         HABITACION "galahud/"
#define NYNE            HABITACION "nyne/"

// Subdominios de la region de Simauria
#define SIMA(x)         SIMAURIA + x
#define LOCATE_CAPI     "Simauria Capital"

// Subdominios de la region de Betwa
#define BET(x)          BETWA + x
#define GORAT(x)        BETWA "gorat/" +x

// Subdominios de la region de Sorquer
#define SORQ(x)         SORQUER + x

// Subdominios de la region de Halibut
#define HALIB(x)        HALIBUT + x

// Subdominios de la region de Marhalt
#define MARH(x)         MARHALT + x
#define MARHCUEVA(x)    MARH("cueva/" + x)	//cueva trolls
// castillo Marhalt
#define CASTILLO(x)     MARH("nandor/castillo/" + x) 	
#define PNJCASTILLO(x)  PNJ("marhalt/castillo/" + x)	
#define PROTNANDOR(x)   PROT("marhalt/nandor/" + x)	
#define ARMANANDOR(x)   ARMA("marhalt/nandor/" + x)	
// Fortaleza de Cored en Marhalt
#define PNJFB(x)        "/d/simauria/comun/pnj/marhalt/fortaleza/bosque/" + x
#define ROOMFB(x)       "/d/simauria/comun/habitacion/marhalt/fortaleza/bosque/" + x
#define ROOMFS(x)       HABITACION "marhalt/fortaleza/senda/"+x
#define PNJFS(x)        PNJ("marhalt/fortaleza/bosque/" + x
#define ROOMFF(x)       HABITACION "marhalt/fortaleza/fortaleza/"+x
#define PNJFF(x)        PNJ("marhalt/fortaleza/fortaleza/"+x)

// Subdominios de la region de Galahud
#define GALH(x)         GALAHUD + x

// Nyne
#define NYN(x)         NYNE + x
#define BOSQUE_NYNE    ROOMS "nyne/bosque_nyne/"
#define BOSQUE_NYN(x)  BOSQUE_NYNE + x
#define KRIG           NYNE "krigor/"
#define KRIGOR(x)      KRIG + x
#define MAINAR         NYNE "mainar/"
#define MAINA(x)       MAINAR + x
#define NCAPITAL       NYNE "capital/"
#define NCAP(x)        CAPITAL + x
#define CUEVAS         NYNE "cuevas/"
#define CUEV(x)        CUEVAS + x
#define MONTANYAS      NYNE "montanyas/"
#define MONTANY(x)     MONTANYAS + x
#define CNB            CAMINOS "/nyne_berat/"
#define CNYNEBERAT(x)  CNB + x
#define CNM            CAMINOS "/nyne_mainar/"
#define CNYNEMAINAR(x) CNM + x
#define PNJNYNE        PNJ("nyne/")
#define PNJNYN(x)      PNJNYNE + x
#define PNJKRIG(x)     PNJNYNE "krigor/" + x
#define PNJMAINA(x)    PNJNYNE "mainar/" + x
#define PNJCAP(x)      PNJNYNE "capital/" + x

// Rhoemas    No me los toqueis... que se están en ruta completa pero los ultimos sino
//        no se incluyen bien.
#define RHOEHAB(x)  "/d/simauria/comun/habitacion/simauria/rhoemas/" + x
#define RHOECAM(x)  "/d/simauria/comun/habitacion/caminos/berat-rhoemas/" + x
#define RHOEPNJ(x)  "/d/simauria/comun/pnj/rhoemas/" + x
#define RHOEARM(x)  "/d/simauria/comun/objeto/proteccion/rhoemas/" + x
#define RHOEWEA(x)  "/d/simauria/comun/objeto/arma/rhoemas/" + x
#define RHOEVAR(x)  "/d/simauria/comun/objeto/otro/rhoemas/" + x
#define RHOETXT(x)  "/d/simauria/comun/habitacion/simauria/rhoemas/txt/" + x
#define RHOESTD(x)  "/d/simauria/comun/habitacion/simauria/rhoemas/std/" + x
#define RHOEPRESO   "/d/simauria/comun/habitacion/simauria/rhoemas/sys/preso.h"
#define RHOEPARADA  "/d/simauria/comun/habitacion/simauria/rhoemas/sys/parada.h"
#define RHOEDANYO   "/d/simauria/comun/habitacion/simauria/rhoemas/sys/danyo.h"
#define RHOELINK    "/d/simauria/comun/habitacion/simauria/berat/camino1"

// defines para las Grutas de Azmodan by Kodex
#define ARMA_AZMODAN(x)     "/d/simauria/comun/objeto/arma/azmodan/" + x
#define ARMADURA_AZMODAN(x) "/d/simauria/comun/objeto/proteccion/azmodan/" + x
#define NPC_AZMODAN(x)      "/d/simauria/comun/pnj/azmodan/" + x
#define OBJETO_AZMODAN(x)   "/d/simauria/comun/objeto/otro/azmodan/" + x
#define VALLE_AZMODAN(x)    "/d/simauria/comun/habitacion/simauria/azmodan/" + x
#define MINA_AZMODAN(x)     "/d/simauria/comun/habitacion/simauria/azmodan/" + x
#define CAMINO_AZMODAN(x)   "/d/simauria/comun/habitacion/simauria/azmodan/camino/" + x
#define STD_AZMODAN(x)      "/d/simauria/comun/habitacion/simauria/azmodan/std/" + x
#define LABERINTO_AZMODAN(x) "/d/simauria/comun/habitacion/simauria/azmodan/laberinto_0" + x

// defines para la Torre de Gundistyr by Articman
#define GD(x)           "/d/simauria/comun/habitacion/simauria/gundistyr/" + x
#define GSUP(x)         GD("/superficie/" + x)
#define GSOT1(x)        GD("/sotano_1/" + x)
#define GSOT2(x)        GD("/sotano_2/" + x)
#define GSOT3(x)        GD("/sotano_3/" + x)
#define PNJGD(x)        "/d/simauria/comun/pnj/gundistyr/" + x
#define GOBJETO(x)      "/d/simauria/comun/objeto/" + x

// defines para las Cavernas del Caos, Sendero del Pomar y Poblado Enanel Remodelados
#define POMARHAB    "/d/simauria/comun/habitacion/marhalt/pomar/"
#define POMARNANDOR "/d/simauria/comun/habitacion/marhalt/nandor/cruce_cam"
#define POMARCAOS   "/d/simauria/comun/habitacion/marhalt/caos/entrada_00"
#define ENALPRT     "/d/simauria/comun/objeto/proteccion/marhalt/enalel/"
#define ENALHAB     "/d/simauria/comun/habitacion/marhalt/enalel/"
#define ENALPNJ     "/d/simauria/comun/pnj/marhalt/enalel/"
#define ENALCOM     "/d/simauria/comun/objeto/comida/marhalt/enalel/"
#define ENALOBJ     "/d/simauria/comun/objeto/otro/marhalt/enalel/"
#define CAOSHAB     "/d/simauria/comun/habitacion/marhalt/caos/"
#define CAOSPNJ     "/d/simauria/comun/pnj/marhalt/caos/"
#define CAOSARM     "/d/simauria/comun/objeto/arma/caos/"

// Sherek
#define CNSH(x)    CAMINOS "/nandor-sherek/" + x
#define ABDCAM      CNSH("camino")
#define SHEREK  "/d/simauria/comun/habitacion/sherek"
#define SHERAB(x)       SHEREK "/abadia/" + x
#define SHERALD(x)      SHEREK "/aldea/" + x
#define SHERCAN(x)     SHEREK "/cantera/" + x

/*
.-------------------------------------------------------------------.
|              FUNCIONES DE LIBRERIA                                |
|  Y SOLO FUNCIONES DE LIBRERÍA, NADA DE DEFINES DE DOMINIOS OK?    |
'-------------------------------------------------------------------'
*/

//    [z] Espero no petar mucho a los demás.
#define CATP        capitalize(this_player()->QueryRealName())

#endif /* __SIMAURIA_H */
