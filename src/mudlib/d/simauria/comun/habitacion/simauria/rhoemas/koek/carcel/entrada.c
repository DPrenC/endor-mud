/***************************************************************************************
 ARCHIVO:	entrada.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Entrada a la c�rcel
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetLocate("Koek");
  SetIntShort("la entrada a la c�rcel");
  SetIntLong(W("Est�s en la entrada a la c�rcel municipal. Por aqu� desfilan todos "
  	"los d�as muchos incautos que se dedicaron a molestar a los habitantes de "
  	"Koek. La verdad es que incluso la c�rcel parece m�s acogedora de lo normal. "
  	"Todo en este pueblo parece bastante cuidado. Parece que tiene muy buenas "
  	"medidas de seguridad y que no es nada f�cil escapar de aqu�.\n"));

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