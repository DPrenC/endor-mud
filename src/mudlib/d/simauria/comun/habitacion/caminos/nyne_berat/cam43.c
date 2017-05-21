/*
FICHERO: cam43.c
CREACION: 10-11-2001 [B] Bomber@simauria.upv.es
DESCRIPCION: Camino de Nyne a Berat. Coge las descripciones de camino.c
*/

#include "./path.h"
inherit CNYNEBERAT("camino");

create() {
::create();
 SetIntLong(W("Hacia el oeste empieza el camino que lleva a Nyne. Nyne es una"
              " zona bastante importante en la faz de Simauria, ya que"
              " posee uno de los puertos mas importantes y transitados que"
              " existe. Si tienes algo de tiempo libre, deberias visitar la ciudad.\n"));

AddExit("oeste",CNYNEBERAT("cam42"));
AddExit("este","/d/simauria/comun/habitacion/caminos/simauria-berat/cam21");
}