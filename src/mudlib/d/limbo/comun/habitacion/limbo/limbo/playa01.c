/*
DESCRIPCION  : desembocadura del arroyo en la playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/playa01.c
MODIFICACION : 24-07-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit LIMBO("playa");

create() {
  ::create();
  SetIntShort("la desembocadura del arroyo");
  SetIntLong(
"En este lugar de la playa es donde viene a desembocar el arroyo que atraviesa el "
"bosque que queda al oeste. El arroyo ha producido un surco en la arena de la "
"playa, ancho pero poco profundo, de tal forma que puede atravesarse a pie. "
"Observas un sendero que lleva al bosque desde la playa al norte de aquí.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n");

 AddDetail(({"arroyo","desembocadura"}),
"El arroyo de aguas cristalinas que atraviesa en bosque desemboca aquí finalmente "
"en el mar. Su corriente ha arrastrado la arena de su cauce al atravesar la playa "
"produciendo un ancho surco en la playa.\n");

 AddDetail(({"playa","playa de Levante"}), QueryIntLong());

SetIntNoise("Oyes las olas al llegar a la orilla.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);

AddExit("norte",LIMBO("playa00"));
AddExit("sur",LIMBO("playa03"));
}