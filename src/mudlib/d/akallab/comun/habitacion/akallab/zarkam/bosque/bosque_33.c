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
  SetIntShort("el r�o Zarmaii");
  SetIntLong(
"Estas en un penyasco que se alza sobre el r�o Zarmaii, su cauce fluye bajo "
"tus pies. Al norte divisas un pequenyo puente que comunica las dos orillas "
"del r�o, y un poquito mas al norte ves una cabanya un tanto extranya, ya "
"que tambien esta atraviesa todo el cauce del r�o, de orilla a orilla. "
"El paisaje en combinacion con el rumor del agua te provocan una muy grata "
"sensacion de calma y tranquilidad.\n");
  SetIndoors(0);
  AddExit("oeste",Z_BOSQUE("bosque_32"));
  AddDetail(({"r�o","zarmaii","Zarmaii","afluente"}),
  "Este es el r�o Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"cabanya"}),
  "Ves en la lejania una cabanya que atraviesa el r�o de una orilla a otra, "
  "como si formara una presa artificial.\n");
  AddDetail(({"puente"}),
  "Un poco mas al norte se encuentra un puente que te permitiria cruzar el r�o.\n");
  AddDetail(({"piedra","penyasco"}),
  "El penyasco en el que te encuentras es extremadamente liso, lo que, junto con "
  "la humedad, obliga a andar con cuidado para no caer al r�o.\n");
  SetIntNoise("Oyes el rumor del agua bajo tus pies.\n");
  SetIntSmell("El aire es fresco en esta zona.\n");
  SetLocate("bosque de Zarkam");
  AddItem(QUEST+"amuleto/urraca", REFRESH_DESTRUCT);
}