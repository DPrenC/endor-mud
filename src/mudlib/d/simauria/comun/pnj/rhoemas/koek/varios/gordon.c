/***************************************************************************************
 ARCHIVO:	gordon.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Gordon, el alcalde del pueblo
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Gordon el alcalde","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Gordon");
  SetIds(({"humano","gordon","Gordon","alcalde"}));
  SetShort("Gordon el alcalde");
  SetLong(W("Gordon es el alcalde del pueblo, una persona de porte serio y sereno "
  	"que inspira mucha calma y confianza. Lleva unas lentes para poder leer "
  	"todo el papeleo que su cargo le exige. Parece muy buena persona.\n"));
  AddQuestion(({"papeleo"}),W("Gordon te dice: Sí, ser alcalde requiere toneladas de papeleo, pero "
  	"a veces, cuando tienes insomnio, resulta de lo más eficaz... jeje.\n"),1);
  AddQuestion(({"guardia","guardias","patrullero","patrulleros"}),W("Gordon te dice: La guardia de "
  	"Koek, junto con los patrulleros, son unos esforzados funcionarios que "
  	"protegen a cualquier persona que pase o resida en el valle. Sin duda se "
  	"merecen nuestra admiración.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Gordon te dice: Koek es un sitio bastante tranquilo, aunque ultimamente se está masificando algo. "
	"tengo más trabajo que nunca.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Gordon te dice: Un consejo... no vayas a verlo nunca... y si piensas en ir, mejor pásate por "
	"aquí antes a ver si te podemos convencer.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Gordon te dice: El templo es nuestra fuente de ingresos. Además nos protege del bosque.\n"),1);
  AddItem(RHOEVAR("koek/varios/lentes"),REFRESH_REMOVE);
  AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":random(20),"platino":random(10)])]));
  InitChats(5,({"Gordon empieza a leer papeles.\n",
  		"Gordon te mira y dice: ¡Hola forastero, bienvenido a Koek!.\n",
		"Gordon dice: ¡Qué bonito se nos va a quedar Koek!.\n",
		"Gordon dice: Um... los presupuestos no salen...\n"}));
  InitAChats(5,({"Gordon grita: [52m ¡A mi la guardia![0m.\n"}));
}
