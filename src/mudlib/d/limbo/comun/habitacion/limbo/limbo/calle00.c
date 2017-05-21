/*
DESCRIPCION  : Entrada al pueblo de la isla Limbo
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/calle00.c
MODIFICACION : 13-07-98 [Angor@Simauria] Creacion.
               29-06-99 [Angor@Simauria] wrapeado
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la entrada al pueblo");
  SetIntLong(W("El camino del Sur llega aquí a un pequeño pueblo de "
    "pescadores situado al sur de la isla Limbo. Está compuesto por un "
    "grupo de bajas casas de madera y algunas otras edificaciones de piedra. "
    "Hacia el sur, distingues un puerto en la orilla en cuyo muelle se hallan "
    "varias barcas de pesca. Al nordeste de aquí, el camino asciende hasta "
    "adentrarse en un un frondoso bosque a lo lejos.\n"));

AddDetail(({"casas","casas de madera"}),
    W("Las casas de los pescadores son pequeñas construcciones rectangulares "
    "de madera con techo plano. Es frecuente encontrar a algun viejo pescador "
    "que remienda una vez más las gastadas redes de pesca bajo la sombra de "
    "sus porches.\n"));

AddDetail(({"puerto","muelle","barcas"}),
 "A lo lejos ves el puerto con barcas amarradas en su muelle. Deberias acercarte "
 "si quieres verlo con mas detalle.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias a "
 "ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
 "primeros pasos para vivir en este mundo.\n");

AddDetail(({"camino del sur","camino","camino del Sur"}),
 "El camino del Sur conduce desde el claro del bosque, que se encuentra en el "
 "centro de la isla, hacia la zona sur de la misma en la que existe un pequeño "
 "pueblo de pescadores.\n");

SetIntNoise("Oyes el murmullo de la actividad en el pueblo.\n");
SetIntSmell("Hueles el fresco aroma del campo.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("nordeste",LIMBO("camino14"));
AddExit("suroeste",LIMBO("calle01"));
}