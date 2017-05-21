/***************************************************************************************
 ARCHIVO:	kiran.c
 AUTOR:		[z] Zomax
 FECHA:		23-12-2001
 COMENTARIOS:	Kiran, el bardo del pueblo
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

int fcantar(int numero_cancion)
{
	string estrofa;
	mixed cancion;
	int linea;
	write(W("Kiran te dice: ¿Quieres que toque algo? Está bien, tocaré una de mis "
		"viejas canciones.\nEl bardo coge su laúd y comienza a cantar:\n\n"));
	say("El bardo coge su laúd y comienza a cantar:\n\n",TP);
	switch (numero_cancion)
	{
		case 0: cancion=RHOETXT("canciones/cancion_00.t"); break;
		case 1: cancion=RHOETXT("canciones/cancion_01.t"); break;
		case 2: cancion=RHOETXT("canciones/cancion_02.t"); break;
		case 3: cancion=RHOETXT("canciones/cancion_03.t"); break;
		case 4: cancion=RHOETXT("canciones/cancion_04.t"); break;
		default:cancion=RHOETXT("canciones/cancion_00.t"); break;
	}
	linea=1;
	while (estrofa=read_file(cancion,linea,1))
	{
		estrofa=read_file(cancion,linea,1);
		if (environment(TO))
		{
			tell_room(environment(TO),("\t"+estrofa));
		}
		linea++;
	}
	tell_room(environment(TO),"\n\nKiran acaba entre lágrimas emocionado.\n");
	return 1;
}

string ftocar()
{
	if (present("laud",TO))
	{
		call_out("fcantar",1,random(5));
		return " ";
	}
	else return "Kiran te dice: lo siento, no tengo el laúd a  mano, no puedo cantar sin música.\n";
}

create(){
  ::create();
  SetStandard("Kiran el bardo","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Kiran");
  SetIds(({"humano","kiran","Kiran","bardo"}));
  SetShort("Kiran el bardo");
  SetLong(W("Kiran es el bardo. Es un humano de cabellos rubios y algo largos que "
  	"se dedica fundamentalmente a componer canciones y alegrar las fiestas de "
  	"los habitantes de Koek con ellas. Ahora tiene el semblante un tanto triste, "
  	"como si la inspiración le hubiera abandonado.\n"));
  AddQuestion(({"tristeza","inspiración","inspiracion"}),W("Kiran te dice: ¡Oh cruel "
  	"destino!. Hace meses que no consigo componer ninguna obra de calidad. Antes "
  	"me salian de las manos con tanta rapidez como ahora desaparecen mis ahorros.\n"),1);
  AddQuestion(({"ahorros"}),W("Kiran te dice: La falta de inspiración afecta a la falta de dinero. "
  	"Por desgracia el arte no es fácil de mantener. Si sigo así tendré que buscarme "
  	"un empleo, pero eso no me dejará tiempo para componer.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Kiran te dice: Koek es un lugar demasiado exigente. Porque alguien tenga una mala racha no "
	"se le debe dejar de contratar para animar las fiestas.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Kiran te dice: No lo conozco, pero estoy pensando en ir para ver si encuentro allí mi inspiración.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Kiran te dice: Menos mal que aún tengo algo de clientela en el templo. Muchas veces me llaman "
	"para tocar en las celebraciones.\n"),1);
  AddQuestion(({"musica","música","poesia","obra","obras","composición","composicion","tocar","cancion","canción","arte","obra"}),SF(ftocar));
  InitChats(5,({"Kiran se lamenta de su suerte: ¿por qué las musas me abandonan?.\n",
  		"Kiran se esfuerza por componer nuevas canciones.\n",
		"Kiran dice: Con las composiciones que tengo a mis espaldas...\n",
		"Kiran dice: Amargo destino. Voy a tener que trabajar si esto sigue así.\n",
		"Kiran solloza: ¿Por qué a mi?.\n"}));
  InitAChats(5,"[32mKiran dice:[53m ¡Si venga... húndeme más en la miseria!.[0m\n");
  AddItem(RHOEVAR("koek/varios/laud"),REFRESH_REMOVE);
  AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":random(10)])]));
}
