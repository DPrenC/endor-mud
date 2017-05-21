/***************************************************************************************
 ARCHIVO:	lago.c
 AUTOR:		[k] Korsario
 FECHA:		02-12-1998
 COMENTARIOS:	El lago donde está el pescador anciano de la quest de Kendarg.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Hay mucha paz aquí, aparte del canto de algunos pájaros no se "
  	"oye nada.");
  SetIntSmell("Huele a frescor primaveral.\n");

  SetIntShort("un pequeño lago");
  SetIntLong("Llegas a la orilla de un pequeño lago. Está rodeado "
  	"totalmente por el bosque. El agua esta de color azúl cristalino. "
  	"Hay tanta paz aquí... es un lugar ideal para relajarte y no pensar "
  	"en nada.\n");

  AddDetail(({"lago","agua"}),"Ves un lago de aguas cristalinas. Es muy hermoso.\n");

  AddRoomCmd("norte","fnorte");

  AddExit("sur",FLENHAB+"empalizada/empalizada_20");
  AddExit("norte",FLENHAB+"pantano/pantano_00");
  HideExit("norte",1);
  AddItem(FLENPNJ+"pantano/anciano",REFRESH_DESTRUCT);
}

reset(){
  ::reset();

  HideExit("norte",1);
}

int fnorte()
{
	mapping salidas;
	salidas=TO->QueryExits();
	if (member(salidas,"norte") && salidas["norte",2])
	{
		write("No hay salida hacia allí.\n");
		return 1;
	}
	else
	{
		TP->move(FLENHAB+"pantano/pantano_00",M_GO);
		HideExit("norte",1);
		tell_room(TO,"Los arbustos vuelven a su posición natural.\n");
		return 1;
	}
}