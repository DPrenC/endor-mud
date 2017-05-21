/*
FICHERO: cam01.c
CREACION: 10-11-2001 [B] Bomber@simauria.upv.es
DESCRIPCION: Camino de Nyne a Berat. Coge las descripciones de camino.c
*/

#include "./path.h"
inherit CNYNEBERAT("camino");

create() {
    ::create();
    SetIntLong(QueryIntLong()+" Hacia el norte se espesa el bosque, desde aquí parece "
    "oscuro y lleno de misterio.\n");
    AddExit("norte",BOSQUE_NYN("bosque176"));
//AddExit("norte",BOSQUE_NYN("aduanase"));
    AddExit("sur",CNYNEBERAT("cam02"));
}