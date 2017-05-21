/*
FICHERO: cam37.c
CREACION: 10-11-2001 [B] Bomber@simauria.upv.es
DESCRIPCION: Camino de Nyne a Berat. Coge las descripciones de camino.c
*/

#include "./path.h"
inherit CNYNEBERAT("camino");

create() {
::create();

AddExit("suroeste",CNYNEBERAT("cam36"));
AddExit("este",CNYNEBERAT("cam38"));
}