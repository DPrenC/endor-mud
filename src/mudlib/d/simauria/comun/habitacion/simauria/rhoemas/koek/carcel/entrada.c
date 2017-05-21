/***************************************************************************************
 ARCHIVO:	entrada.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Entrada a la cárcel
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetLocate("Koek");
  SetIntShort("la entrada a la cárcel");
  SetIntLong(W("Estás en la entrada a la cárcel municipal. Por aquí desfilan todos "
  	"los días muchos incautos que se dedicaron a molestar a los habitantes de "
  	"Koek. La verdad es que incluso la cárcel parece más acogedora de lo normal. "
  	"Todo en este pueblo parece bastante cuidado. Parece que tiene muy buenas "
  	"medidas de seguridad y que no es nada fácil escapar de aquí.\n"));

  SetIntBright(30);
  AddExit("este",RHOEHAB("koek/carcel/centro"));
  AddExit("oeste",RHOEHAB("koek/calles/folker_10"));

  AddItem(RHOEPNJ("koek/varios/guardia"),1,1);
  AddItem(RHOEPNJ("koek/varios/guardia"),1,1);

  carcel=(RHOEHAB("koek/carcel/centro"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
}