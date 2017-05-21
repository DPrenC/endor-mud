/*
DESCRIPCION  : Parte superior de las escaleras en el edificio de los siervos
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/escaleras.c
MODIFICACION : 30-09-98 [Angor@Simauria] Creacion.
               10-10-99 [woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

int ir_oeste();

create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("las escaleras");
  SetIntLong(
"Te encuentras en un rellano. Al norte de aqu� se halla la habitaci�n de reposo "
"a la que trasladan a los pacientes de Asthar tras la operaci�n para que se "
"recuperen y al sur queda una peque�a biblioteca. Unas escaleras permiten bajar "
"a la planta baja del edificio y al oeste hay una puerta cerrada.\n");

AddDetail(({"biblioteca"}), "Es la habitaci�n que queda al sur de aqu�.\n");
AddDetail(({"habitacion de reposo","reposo"}), "Es la habitaci�n que queda al norte de aqu�.\n");

AddDetail(({"escaleras"}),
 "Son unas anchas escaleras de madera adosadas a la pared que permiten bajar a la "
 "planta baja del edificio.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("No huele a nada en especial.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);

 AddExit("norte",TEMPLO("reposo"));
 AddExit("sur",TEMPLO("biblioteca"));
 AddExit("abajo",TEMPLO("entrada_sum"));
 AddExit("oeste",TEMPLO("pasillo"));
 SetSafe(1);
}
