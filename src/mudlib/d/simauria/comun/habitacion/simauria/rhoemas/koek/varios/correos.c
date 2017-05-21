/***************************************************************************************
 ARCHIVO:	correos.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Correos de Koek
 ***************************************************************************************/

#include "path.h"

inherit "/std/correo";
#include RHOEPRESO

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(30);
  SetLocate("Koek");

  carcel=(RHOEHAB("koek/calles/folker_10"));

  SetIntShort("la oficina de correos");
  SetIntSmell("Huele a papel por todas partes.\n");
  SetIntNoise("No se oye nada especial.\n");
  SetIntLong(W("Estás en la oficina de correos de Koek, que permanece abierta "
  	"las 24 horas del día. Aquí suele haber mucho jaleo de cartas y solo "
  	"un cartero para atenderlo todo, asi que no esperes mucho de él, puede "
  	"que se quede traspuesto de vez en cuando.\n"));
  AddDetail(({"suelo"}),W("Es un suelo muy normal, hecho con tablones de "
  	"madera un poco gastados.\n"));
  AddDetail(({"pared","paredes"}),W("Son paredes hechas de un material muy "
  	"resistente, para evitar los robos.\n"));
  AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");

  AddExit("sur",RHOEHAB("koek/calles/folker_10"));

  AddItem(RHOEPNJ("koek/varios/faulker"),REFRESH_DESTRUCT,1);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
}

int fcoger(string str)
{
	object folleto;
	if (str=="folleto" || str=="folleto informativo" || str=="folletos")
	{
		write("Coges un folleto informativo.\n");
		say(W(CATP+" coge un folleto informativo.\n"),TP);
		folleto=clone_object(RHOEVAR("koek/varios/folletoc"));
		folleto->move(TP,M_SILENT);
		return 1;
	}
}

int QueryEntrarPatrullero()
{
	return 1;
}
