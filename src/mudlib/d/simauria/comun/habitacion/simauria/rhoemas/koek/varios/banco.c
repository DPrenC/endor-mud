/***************************************************************************************
 ARCHIVO:	banco.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Banco de Koek
 ***************************************************************************************/

#include "path.h"

inherit BANK;

#include RHOEPRESO

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(30);
  SetLocate("Koek");
  SetBankName("koek");

  carcel=(RHOEHAB("koek/calles/folker_08"));

  SetIntShort("el banco de Koek");
  SetIntSmell("Huele a ... mithriles...\n");
  SetIntNoise("No se oye nada especial.\n");
  SetIntLong("Este es el banco de Koek, un lugar de mucha actividad dado "
  	"el carácter comercial del pueblo.\n Tiene unas muy buenas medidas "
  	"de seguridad y algo te dice que hacer algo malo aquí se paga más que "
  	"con mithriles, con la vida.\n");
  AddDetail(({"suelo"}),W("Es un suelo muy normal, hecho con tablones de "
  	"madera un poco gastados.\n"));
  AddDetail(({"pared","paredes"}),W("Son paredes hechas de un material muy "
  	"resistente, para evitar los robos.\n"));
  AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");


  SetKeeper(RHOEPNJ("koek/varios/nyrem"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("koek/varios/guardia"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("koek/varios/guardia"),REFRESH_DESTRUCT,1);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");

  AddExit("sur",RHOEHAB("koek/calles/folker_08"));
  SetLastDest(RHOEHAB("koek/calles/folker_08"));
  SetNotifyExits("sur");
}
