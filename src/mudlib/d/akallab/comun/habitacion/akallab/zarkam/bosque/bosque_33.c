/*
DESCRIPCION  : Orilla del Zarmaii.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("el río Zarmaii");
  SetIntLong(
"Estas en un penyasco que se alza sobre el río Zarmaii, su cauce fluye bajo "
"tus pies. Al norte divisas un pequenyo puente que comunica las dos orillas "
"del río, y un poquito mas al norte ves una cabanya un tanto extranya, ya "
"que tambien esta atraviesa todo el cauce del río, de orilla a orilla. "
"El paisaje en combinacion con el rumor del agua te provocan una muy grata "
"sensacion de calma y tranquilidad.\n");
  SetIndoors(0);
  AddExit("oeste",Z_BOSQUE("bosque_32"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"cabanya"}),
  "Ves en la lejania una cabanya que atraviesa el río de una orilla a otra, "
  "como si formara una presa artificial.\n");
  AddDetail(({"puente"}),
  "Un poco mas al norte se encuentra un puente que te permitiria cruzar el río.\n");
  AddDetail(({"piedra","penyasco"}),
  "El penyasco en el que te encuentras es extremadamente liso, lo que, junto con "
  "la humedad, obliga a andar con cuidado para no caer al río.\n");
  SetIntNoise("Oyes el rumor del agua bajo tus pies.\n");
  SetIntSmell("El aire es fresco en esta zona.\n");
  SetLocate("bosque de Zarkam");
  AddItem(QUEST+"amuleto/urraca", REFRESH_DESTRUCT);
}