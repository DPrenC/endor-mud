/*
DESCRIPCION : cruce de calles junto a la puerta sur
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_10.c
MODIFICACION: 11-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 object ob;
 ::create();
 SetIntShort("una calle junto a la muralla sur");
 SetIntLong(
     "La calle continua a avanzando junto a la alta muralla que protege a la ciudad "
     "de Zarkam. En el bajo del edificio que queda al norte debia haber una tienda, "
     "pero por su aspecto viejo y descuidado dirias que hace ya bastante que debio "
     "cerrar sus puertas. Observas un cruce mas al oeste.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  AddDetail(({"tienda"}),
     "En el bajo del edificio al norte parece que hubo una tienda, pero hace tiempo "
     "que debio cerrar. De letrero solo quedan un par de tablones descoloridos y el "
     "hueco del escaparate se halla tapiado con tablones, ya que sus cristales estan "
     "casi todos rotos.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_CIUDAD("calle_11"));
  AddExit("este",Z_CIUDAD("calle_09"));

ob=clone_object("/obj/monolito");
ob->SetRaza("elfo-oscuro");
ob->move(TO);
AddItem(OTRO("en_obras"),REFRESH_ALWAYS,3);
}
