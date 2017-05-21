/* **********************************************************************
   *  DESCRIPCION  : Casas de Krigor
   *  FICHERO      : casa.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit SIM_ROOM;

create()
{
	::create();

	SetIntShort("el interior de una casa");
  	SetIntLong("Te encuentras dentro de una casa con las paredes de madera. Hay "
  		"una cocina peque�ita y dos habitaciones confortables.\n");

  	SetIndoors(1);
    SetIntBright(50);
	SetIntSmell("Hueles a comida.\n");
	SetIntNoise("Oyes a una mujer en la cocina.\n");

  	//aqui se a�adiran bastantes mas detalles en un futuro
  	AddDetail(({"cocinas","cocina"}), "Es una cocina tipica de le�a, donde "
  	        "los habitantes hacen la comida.\n");

  	SetLocate("Krigor");
	AddItem(PNJKRIG("krigoriano"),REFRESH_DESTRUCT,random(2)+2);

}