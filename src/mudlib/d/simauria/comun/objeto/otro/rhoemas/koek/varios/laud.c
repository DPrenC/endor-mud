/***************************************************************************************
 ARCHIVO:	laud.c
 AUTOR:		[z] Zomax
 FECHA:		23-12-2001
 COMENTARIOS:	Un la�d (para el bardo)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un la�d");
  SetLong(W("Es un peque�o la�d de madera, un peque�o instrumento de cuerda para "
  	"acompa�ar los cantos con algo de m�sica. Quiz�s puedas tocarlo.\n"));
  SetIds(({"laud","la�d"}));
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
	write(W("Te pones a tocar algo con el la�d. Tus manos son como estropajos frotando "
		"rosas, y haces un ruido espantoso que te pone los pelos de punta. Quiz�s "
		"debieras dejar esto para profesionales.\n"));
	say(W(CATP+" se pone a tocar el la�d. Hace un ruido tan penetrante como desagradable "
		"que recordar�s toda tu vida. El pelo se te pone de punta. Parece que a "
		+CATP+" tampoco el ha gustado la melod�a, porque ha parado en seco. Das gracias "
		"a los dioses de que al menos "+CATP+" tenga sentido del gusto.\n"),TP);
	return 1;
}
