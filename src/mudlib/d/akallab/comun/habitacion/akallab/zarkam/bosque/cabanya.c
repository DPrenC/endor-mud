/*
DESCRIPCION  : Cabanya (Aserradero en el bosque)
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la cabaña del aserradero");
  SetIntLong(
     "Estas en el interior de una cabanya de madera, los unicos muebles que puedes "
     "apreciar son una mesa redonda en el centro y dos sillas toscamente labradas. "
     "Esta cabanya la habitan los orcos encargados de la presa, los cuales llevan "
     "tanto tiempo en ella que han olvidado viejas rencillas con otras razas, por "
     "lo que evitan cualquier tipo de confrontamiento o pelea. A traves de una puerta "
     "abierta que hay en el norte de la habitacion, ves algun tipo de maquinaria.\n");

  AddDetail(({"mesa"}), "Una mesa redonda preside el centro de la estancia.\n");

  AddDetail(({"silla","sillas"}),
    "Dos viejas sillas de madera son los unicos muebles, junto con la mesa, que ves "
    "en esta habitacion.\n");

  SetIntNoise("Oyes un ruido constante y monotono proviniente del norte.\n");
  SetIntSmell("Uele a madera.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("sur",Z_BOSQUE("bosque_54"));
  AddExit("norte",Z_BOSQUE("maquinaria"));

  AddItem(PNJ("z_valle/akront"),REFRESH_DESTRUCT);
}
