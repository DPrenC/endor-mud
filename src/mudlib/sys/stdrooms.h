/**
 * ENDOR-MUD '/sys/stdroom.h'
 */

#ifndef __STDROOMS_H__
#define __STDROOMS_H__
// rutas de endor
#define ENCRUCIJADA_BREE         "/d/pais-bree/comun/habitacion/caminos/encrucijada"
#define PONEY_PISADOR         "/d/pais-bree/comun/habitacion/bree/poney_pisador/arcada"


#define AMAN      "/d/aman/comun/habitacion/valinor/valmar/ciudad/antepuertao"
#define INICIO     AMAN
#define AJUSTES     "/room/ajustes"
#define MANDOS      "/d/aman/comun/habitacion/valinor/valmar/ciudad/estancias_mandos"

#define TEMPORAL    ENCRUCIJADA_BREE


// rooms de destino según ciudadanías.
#define B_FOROCHEL  TEMPORAL
#define B_DRUADAN   TEMPORAL
#define BREE         PONEY_PISADOR
#define CALEMBEL    TEMPORAL
#define CARROCA     TEMPORAL
#define C_PUKEL     TEMPORAL
#define C_BOSQUE    TEMPORAL
#define C_TRASGOS   TEMPORAL
#define C_LAGO      TEMPORAL
#define C_HIERRO    TEMPORAL
#define CUERNAVILLA TEMPORAL
#define AMROTH      TEMPORAL
#define EDORAS      TEMPORAL
#define EREBOR      TEMPORAL
#define E_HARAD     TEMPORAL
#define E_ESTE      TEMPORAL
#define GORGOROTH   TEMPORAL
#define IMLADRIS    TEMPORAL
#define ISENGARD    TEMPORAL
#define LOSSARNACH  TEMPORAL
#define LOTHLORIEN  TEMPORAL
#define M_KHAND     TEMPORAL
#define M_MORGUL    TEMPORAL
#define M_TIRITH    TEMPORAL
#define MITHLOND    TEMPORAL
#define MORIA       TEMPORAL
#define NAUGRIM     TEMPORAL
#define PELARGIR    TEMPORAL
#define R_DUNADAN   TEMPORAL
#define R_THRANDUIL TEMPORAL
#define T_BRUNAS    TEMPORAL
#define UMBAR       TEMPORAL
#define VALLE       TEMPORAL
#define ERRANTES    ENCRUCIJADA_BREE
#define DESCAMPADO_1 TEMPORAL

// Habitaciones estandard de simauria, eliminar cuando no se use.
#define RESUCITAR    MANDOS
#define CENTER      AMAN
#define ADV_GUILD   AMAN
#define ASTHAR    AMAN
#define CHURCH    AMAN

#define NETDEATH  "/room/netdeath"
#define RESTROOM  "/room/restroom"  // no existe
#define SHUTSHOP "/room/armagedon/final" // no existe

#define VOID      "/std/void"
#define REPOSO      INICIO
#endif
