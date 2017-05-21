/***************************************************************************************
 ARCHIVO:	laud.c
 AUTOR:		[z] Zomax
 FECHA:		23-12-2001
 COMENTARIOS:	Un laúd (para el bardo)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un laúd");
  SetLong(W("Es un pequeño laúd de madera, un pequeño instrumento de cuerda para "
  	"acompañar los cantos con algo de música. Quizás puedas tocarlo.\n"));
  SetIds(({"laud","laúd"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_MEDIUM);
  SetWeight(450);
  SetValue(1500);
  SetMaterial(M_MADERA);
}

init(){
  ::init();
  add_action("ftocar","tocar");
}

int ftocar(string str)
{
	write(W("Te pones a tocar algo con el laúd. Tus manos son como estropajos frotando "
		"rosas, y haces un ruido espantoso que te pone los pelos de punta. Quizás "
		"debieras dejar esto para profesionales.\n"));
	say(W(CATP+" se pone a tocar el laúd. Hace un ruido tan penetrante como desagradable "
		"que recordarás toda tu vida. El pelo se te pone de punta. Parece que a "
		+CATP+" tampoco el ha gustado la melodía, porque ha parado en seco. Das gracias "
		"a los dioses de que al menos "+CATP+" tenga sentido del gusto.\n"),TP);
	return 1;
}
