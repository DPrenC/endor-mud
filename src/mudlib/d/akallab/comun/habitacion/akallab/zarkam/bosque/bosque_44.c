/*
DESCRIPCION  : bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("un puente sobre el Zarmaii");
  SetIntLong(
"El puente sobre el que te encuentras fue construido hace mucho tiempo, aun "
"asi se haya en perfectas condiciones. Esta formado por resistentes maderas "
"cubiertas de algun tipo de barniz para evitar que se pudra debido al efecto "
"de la humedad. Parece bastante seguro y es el unico punto a traves del que "
"se puede cruzar el río. "
"Atravesando el puente hacia el sudeste podrias llegar facilmente a la otra "
"orilla.\n");
  SetIndoors(0);
  AddExit("sudeste",Z_BOSQUE("bosque_35"));
  AddExit("oeste",Z_BOSQUE("bosque_43"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"puente"}),
  "Te hayas sobre el puente que permite cruzar el río Zarmaii sin grandes "
  "problemas hacia el sudeste.\n");
  AddDetail(({"barniz","maderas"}),
  "El puente lo forman anchos y gruesos tablones de madera cubiertos de una capa "
  "que no sabes identificar exactamente pero que parece algun tipo de barniz, "
  "posiblemente para prolongar la vida del puente.\n");
  SetIntNoise("Oyes como corre el agua bajo tus pies.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
}
