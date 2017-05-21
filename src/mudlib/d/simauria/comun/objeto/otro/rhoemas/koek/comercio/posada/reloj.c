/***************************************************************************************
 ARCHIVO:	reloj.c
 AUTOR:		[z] Zomax
 FECHA:		05-11-2001
 COMENTARIOS:	Reloj - Calendario de arena.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

int hora,minuto,dia,mes,anyo,estacion;
string season;

int freloj()
{
	hora=CHRONOS->QueryHour();
	minuto=CHRONOS->QueryMinute();
	dia=CHRONOS->QueryDay();
	mes=CHRONOS->QueryMonth();
	anyo=CHRONOS->QueryYear();
	switch(CHRONOS->QueryEstacion())
	{
		case 1: season="invierno";	break;
		case 2: season="primavera";	break;
		case 3: season="verano";	break;
		case 4: season="oto�o";		break;
		default:season="una estacion muy rara";	break;
	}
	return 1;
}

int fmirar(string str)
{
	if ((str=="reloj") || (str=="calendario") ||(str=="reloj calendario"))
	{
		freloj();
		SetLong(W(
 		"Es un bonito reloj de arena que funciona s�lo y que ayuda a saber "
 		"la hora que es. Tiene dos peque�as c�psulas llenas de arena "
 		"sujetadas por unas peque�as varillas de metal y cuando se vac�an "
 		"las c�psulas giran y vuelven a contar. Por la cantidad de arena "
 		"que hay en ellas puedes saber m�s o menos la hora y los minutos. "
 		"Adem�s, en las varillas tiene marcados los d�as y meses del a�o.\n"
 		"[52m\n"+
 		"                    Ahora mismo son las "+hora+":"+minuto+"\n"
 		"            Estamos a d�a "+dia+" del mes "+mes+" del a�o "+anyo+"\n"
 		"                            Es "+season+"[0m\n\n"));
 		return 0;
 	}
    return 0;
}

create () {
 ::create();

  SetShort("un reloj");
  SetLong(W("Es un bonito reloj de arena que funciona s�lo y que ayuda a saber "
  	"la hora que es. Tiene dos peque�as c�psulas llenas de arena sujetadas por "
  	"unas peque�as varillas de metal y cuando se vac�an las c�psulas giran y "
  	"vuelven a contar. Por la cantidad de arena que hay en ellas puedes saber "
  	"m�s o menos la hora y los minutos. Adem�s, en las varillas tiene marcados "
  	"los d�as y meses del a�o.\n"));
  AddSubDetail(({"capsula","capsulas","c�psula","c�psulas"}),W("Hay un par de c�psulas "
  	"que encierran la arena y giran seg�n les toca.\n"));
  AddSubDetail(({"varilla","varillas"}),W("Son unos finos trozos de metal que soportan "
  	"la estructura y hacen de eje e improvisado calendario.\n"));
  SetIds(({"reloj","calendario","reloj calendario"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(100);
  SetValue(5000);
}

void init() {
  ::init();
  add_action("fmirar","mirar");
  add_action("fmirar","m");
}
