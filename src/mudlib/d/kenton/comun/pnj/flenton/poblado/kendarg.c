/***************************************************************************************
 ARCHIVO:	kendarg.c
 AUTOR:		[k] Korsario
 		[z] Zomax
 FECHA:		05-04-1998
 COMENTARIOS:	Kendarg, el héroe local
 		20-02-2002  [z] Modifico las add_actions decir y hablar y las sustituyo
 				por catch_tell
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("Kendarg, el héroe local","kender",15,GENERO_MASCULINO);
  SetIds(({"kendarg","kender","heroe","héroe"}));
  SetName("kendarg");
  SetAlign(55);

  SetShort("Kendarg, el héroe local");
  SetLong(W("Kendarg el héroe local. Es un Kender bien parecido, aunque "
  	"algunas cicatrices surcan su cara. Se ve que ha vivido muchas "
  	"aventuras, y ha hecho honor a su apodo. Parece bastante ágil, "
  	"a pesar de que ya no es un joven.\n"));

  AddQuestion(({"piedra","piedra verde","gema"}),W("Me gustaba mucho, tanto que la "
  	"escondí para que no 'desapareciera', pero ya no me acuerdo dónde la puse, "
  	"aunque seguro que fue en el poblado.\n"));
  AddQuestion(({"pocion","poción"}),W("Yo le encargué algo al shamán... pero no me "
  	"acuerdo para qué era y como él tampoco dice nada, supongo que estaremos así "
  	"muuuucho tiempo.\n"));
  AddQuestion(({"maldicion","maldición","maldicion del pantano","maldición del pantano"}),W(
	"Kendarg dice: Si... fue un duro trabajo... aún recuerdo lo mal que "
	"lo pasé en el pantano, con esas arenas movedizas... pero al final "
	"todo salió bien, ¿no?, aunque dicen que el espectro ha vuelto, pero "
	"yo no estoy para esos trotes.\n"));
  AddQuestion(({"espectro","espectro del pantano"}),W("El espectro ha vuelto al pantano "
  	"de la muerte, pero yo ya no estoy para esos trotes. ¿Puedes encargarte tú de él?\n"));
  AddQuestion(({"espada","espada sagrada","kimera"}),W("Kendarg dice: ¿a que es bonita?\nKendarg "
  	"te muestra su espada Kimera.\n"));
  AddQuestion(({"pantano","pantano de la muerte"}),W("Kendarg dice: es un lugar "
  	"donde te pierdes sin remedio desde el primer paso que das. Recuerdo lo que "
  	"me costó salir.\n"));

  AddItem(FLENARM+"kimera",REFRESH_REMOVE);

  InitChats(5,({
  	"Kendarg sonrie y dice: ¡Hola! ¿quién eres?\n",
	W("Kendarg dice: Un dia de estos tengo que ir a buscar al shamán "
		"la poción que le encargué, aunque ahora no recuerdo para "
		"que era... Hmmm\n"),
	"Kendarg desenfunda su espada y le saca brillo. Parece estar muy orgulloso.\n",
	"Kendarg enfunda su espada y te mira fijamente.\n",
	W("Kendarg dice: Yo tenia una piedra verde muy bonita... me pregunto "
		"dónde la habre escondido... tiene que estar en el poblado...\n"),
	"Kendarg dice: ¿Y bien, deseas algo? ¿Qué te trae hasta aquí forastero?\n"}));
}

Defend (dam, dam_type)
{
	if (TP)
	{
		TP->StopAttack();
		say (" pero salta hacia atras evitando el ataque.\n");
		write(W("Kendarg grita: ¿Atacarme a mí? ¿No te da vergüenza? "
			"Con esa actitud no coseguirás nada de mí.\n"));
     		return 1;
	}
}

init(){
  ::init();

  add_action("fdar","dar");
}

void catch_tell(string str)
{
	if ((lower_case(str))=="cobarde")
	{
		say(W("Kendarg dice: ¿¿Cobarde?? jajajajajajaja\n""Kendarg "
			"dice: Como se ve que no conoces a los Kenders. Los "
			"Kenders no conocemos el significado del miedo. Somos "
			"inmunes a él.\n"));
	}
	else if ((lower_case(str))=="ladron" || (lower_case(str))=="ladrón")
	{
		say(W("Kendar grita: ¿¿ME ESTAS LLAMANDO LADRÓN??\nKendarg "
			"desenvaina su espada, se le ve muy enfadado.\n"));
		TO->Kill(TP);
	}
	else if ((lower_case(str))=="quest")
	{
		say("Kendarg dice: ¿Qué es un quest? ¿Se puede comer?.\n");
	}
	else if ((lower_case(str))=="espada")
	{
		 say(W("Kendarg dice: ¿Espada? ¿Te gusta mi espada? ¿Verdad "
		 	"que es muy bonita? Kendarg sonrie.\n"));
	}
}

int fdesaparece()
{
	write(W("Kendarg tras unos segundos de estudio se bebe la poción... "
		"Al instante... ¡Pufff! ¡Desaparece ante tus ojos!\nAlguien dice: "
		"¡ahora recuerdo para que era la poción.!\nSe escucha una risa "
		"traviesa...\n"));
	TO->remove();
	return 1;
}

int fespada(object espada)
{
	espada->move(environment(TO),M_SILENT);
	call_out("fdesaparece",2);
	return 1;
}

int fdar(string str)
{
	object pocion;
	object espada;
	pocion=present("poción shaman",TP);
	espada=present("kimera",TO);
	if((str=="pocion a kendarg" || str=="poción a kendarg" || str=="pocion a Kendarg" || str=="poción a Kendarg") && pocion)
	{
		if(espada)
		{
			pocion->remove();
			say("Kendarg dice: ¡Anda! ¡La poción que había encargado al "
			    "Shaman!\nKendarg dice: ¡Muchas gracias!.\nKendarg dice: "
			    "¡Hmmm me pregunto para que será... ya no me acuerdo!.\n");
    		say("Kendarg tira despreocupadamente su espada y estudia con "
	    		"detenimiento la poción.\n");
		 	fespada(espada);
      		return 1;
      	}
      	else
      	{
      		pocion->remove();
			say("Kendarg dice: ¡Anda! ¡La poción que había encargado al "
			    "Shaman!\nKendarg dice: ¡Muchas gracias!.\nKendarg dice: "
			    "¡Hmmm me pregunto para que será... ya no me acuerdo!.\n");
			return 1;
		}
      }
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="flenton")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
