/*
FICHERO: cam13.c
CREACION: 10-11-2001 [B] Bomber@simauria.upv.es
DESCRIPCION: Camino de Nyne a Berat. Coge las descripciones de camino.c
*/

#include "./path.h"
inherit CNYNEBERAT("camino");

create() {
::create();

AddExit("sur",CNYNEBERAT("cam12"));
AddExit("norte",CNYNEBERAT("cam14"));
}