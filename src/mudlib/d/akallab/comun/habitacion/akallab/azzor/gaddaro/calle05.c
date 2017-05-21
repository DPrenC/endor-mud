/*
DESCRIPCION  : Calle de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/calle05.c
MODIFICACION : 18-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("la calle del pueblo de Gaddaro");
  SetIntLong(
  "Esta calle secundaria acaba aquí junto al templo del pueblo. El templo es "
  "una baja construcción de piedra que se halla al oeste de aquí. Una vieja "
  "verja de barras de metal permite entrar en el cementerio del pueblo que "
  "observas al norte de la calle. Al sur de la calle se alza una casa.\n");

  AddDetail(({"cementerio","verja","muro"}),
  "El cementerio del pueblo se halla al norte de aquí. Esta rodeado por un "
  "muro de piedra y una vieja verja de metal es la puerta que permite "
  "acceder a él.\n");

#include "geografia.ic"

  SetIntNoise("Este es un lugar tranquilo. No escuchas nada de interes.\n");
  SetIntSmell("No huele a nada en especial.\n");
  SetLocate("pueblo de Gaddaro");
  SetIndoors(0);

 AddExit("este",GADDARO("calle04"));
 AddExit("sur",GADDARO("casa00"));
 AddExit("norte",GADDARO("cement00"));
 AddExit("oeste",GADDARO("templo"));
}
