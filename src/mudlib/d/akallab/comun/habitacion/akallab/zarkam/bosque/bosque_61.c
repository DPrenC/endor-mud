/*
DESCRIPCION  : Orilla este del río Zarmaii, en el bosque de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetPreIntShort("tras");
  SetIntShort("la cabaña");
  SetIntLong(
"Estas detras de lo que parece una simple cabanya, aunque al mirar hacia el "
"río, compruebas que esta lo atraviesa de un lado a otro, formando una pequenya "
"presa por la que el agua escapa con mucha fuerza. Deduces que la utilizan "
"para aprovechar esta fuerza en el movimiento de algun tipo de maquinaria, por "
"el ruido que puedes oir dirias que se trata de un aserradero. "
"No hay ninguna puerta que te permita el acceso desde aqui, solo puedes ver "
"un par de ventanas y estan bien cerradas.\n");
  SetIndoors(0);
  AddExit("sur",Z_BOSQUE("bosque_56"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"ventana","ventanas"}),
  "Al mirar a traves de las ventanas de la cabanya descubres en su interior dos "
  "grandes literas y unas cuantas mesas, las literas no han sido usadas hace "
  "mucho, alguien vive ahi dentro.\n");
  AddDetail(({"presa"}),
  "Es una presa formada por grandes troncos de madera, muy resistente. Ves como "
  "el agua sale con fuerza por unos conductos destinados a tal fin, comprendiendo "
  "que la presa no se ha construido para retener el agua sino para aprovechar al "
  "maximo su fuerza.\n");
  SetIntNoise("El ruido del agua se funde con el de sierras y engranajes.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  AddItem(OTRO("hierb_curativa"), REFRESH_REMOVE);
}
