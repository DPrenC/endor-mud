/*
DESCRIPCION  : Presa (Aserradero en el bosque)
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
			   26-10-99 [Angor@Simauria] Modificada/quest
--------------------------------------------------------------------------------
*/


#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("lapresa del aserradero");
  SetIntLong(
  "La presa sobre la que te encuentras se encarga de retener el cauce del "
  "Zarmaii, dejando tan solo unas cuantas vias de escape. De esta forma se "
  "aprovecha la fuerza del agua al pasar por ellas para mover los engranajes "
  "de las sierras que cortan la madera. Al elevar la mirada hacia el norte "
  "ves el lugar donde nace el río, una profunda e inexpugnable cueva "
  "excavada en las montanyas. Unas barandillas se encargan se prevenir "
  "posibles caidas a la presa.\n");

  AddDetail(({"presa"}),"Es una gran cantidad de agua, no te parece?\n");

  AddDetail(({"barandilla","barandillas"}),
  "Te acercas a una de las barandillas y miras hacia abajo, por unos "
  "momentos te sientes mareado. Pero solo es agua y te recuperas rapidamente, "
  "aunque no quisieras caer al río.\n");

  AddDetail(({"río","afluente","Zarmaii","zarmaii"}),
  "El río Zarmaii es retenido en esta zona para poder aprevechar toda la "
  "fuerza de su considerable caudal de agua. Al norte puedes divisar el "
  "nacimiento del río.\n");

  AddDetail(({"nacimiento","cueva"}),
  "En la lejania aprecias como el Zarmaii surge del interior de una "
  "cueva entre las montanyas.\n");

  SetIntNoise("El ruido del agua que escapa de la presa se confunde "
  "con el de la maquinaria.\n");
  SetIntSmell("El aire es extremadamente humedo aqui...\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_BOSQUE("habitaciones"));
  AddExit("oeste",Z_BOSQUE("maquinaria"));
  AddItem(QUEST+"amuleto/cubo", REFRESH_DESTRUCT);
}
