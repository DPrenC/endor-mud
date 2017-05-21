/***************************************************************************************
 ARCHIVO:	herreria.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	La herreria de Flenton
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit "/room/herreria";
inherit "/lib/money";

int encendida;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas el ruido que produce el martillo al golpear el acero.\n");
  SetIntSmell("Hmm... no huele a nada especial.\n");

  SetIntShort("la herrería de Flenton");
  SetIntLong("Esta es la vieja herrería de Flenton. Está habitada desde "
  	"su fundación por el viejo y simpático humano ManodeHierro. Al entrar "
  	"sientes el calor que desprende la fragua. De las paredes cuelgan "
  	"muchas armas. Parecen todas nuevas. Frente a la fragua hay una mesa "
  	"de hierro, y encima un yunque y diversas herramientas típicas de una "
  	"herrería. Está herreria también tiene fama de hacer buenas reparaciones "
  	"de armas.\n");

  AddRoomCmd("matar","fmatar");

  AddExit("norte",FLENHAB+"calles/kendarg_00");

  AddArticle(FLENARM+"daga",REFRESH_REMOVE,5);
  AddArticle(FLENARM+"espada_corta",REFRESH_REMOVE,3);
  AddArticle(FLENVAR+"cubo",REFRESH_REMOVE,10);
  AddArticle(FLENVAR+"clavos",REFRESH_REMOVE,10);
  AddArticle(FLENVAR+"martillo",REFRESH_REMOVE,10);
  SetShopkeeper(FLENPNJ+"poblado/manodehierro");
}

int fmatar(string str)
{
	if(!str) return 0;
	write("El tendero pone cara de malos amigos y de una patada en el "
		"trasero te pone de patitas en la calle\nEl tendero grita: ¡Aquí "
		"no se mata a nadie!\n");
	say("El tendero echa a "+CATP+".\n");
	TP->move(FLENHAB+"calles/kendarg_00",M_GO);
	return 1;
}
