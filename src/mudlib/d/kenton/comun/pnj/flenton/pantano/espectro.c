/***************************************************************************************
 ARCHIVO:	espectro.c
 AUTOR:		[k] Korsario
 FECHA:		13-11-1998
 COMENTARIOS:	El espectro del pantano
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un espectro","espectro",20,GENERO_MASCULINO);
  SetIds(({"espectro","espectro del pantano"}));

  SetShort("un espectro");
  SetLong(W("Ves un terrorífico espectro de casi dos metros de altura. No tiene una"
	"forma definida, cambia a cada instante. Dos puntos brillantes de color "
	"verdoso que se asemejan a ojos no se apartan de tí.\n"));

  InitChats(5,({"Escuchas un agonizante grito de dolor...\n",
  		"El espectro mira a través tuyo como si fueras transparente.\n",
  		"El espectro dice: ¿Quién osa molestar mi descanso eterno?\n",
  		"El espectro se desvanece y aparece al momento en otra parte de la estancia.\n"}) );
}

int fmuertos(int num,object player)
{
	object muerto;
	int i;
	if(!num) return 0;
	write(W("El espectro dice: ¡Levantaos y luchad!\nOyes el crujir de huesos y "
		"el roce de armaduras y armas.\n"));
	say(W("Escuchas una voz de ultratumba que dice: ¡Levantaos y luchad!\nOyes el "
		"crujir de huesos y el roce de armaduras y armas.\n"),TP);
	for(i=0;i<num;i++)
	{
		if (environment(TO))
		{
			muerto=clone_object(FLENPNJ+"pantano/esqueleto");
 			muerto->move(environment(TO),M_SILENT);
 		}
	}
	return 1;
}

int ffalla(object player)
{
	write(W("El espectro dice: Estos mortales nunca aprenderan... ¡Necesitas "
		"una lección!\n"));
	fmuertos(10,player);
	write("El espectro se desvanece en una nuve de humo.\n");
	TO->remove();
	return 1;
}


Defend (dam, dam_type)
{
	object esp;
  	if (TP)
	{
		TP->StopAttack();
		if((esp=present("kimera con piedra verde",TP))&&(esp->QueryEquipped()))
		{
			write(" y le das de lleno con tu espada.\n");
			say(" y le da de lleno con su espada.\n");
			write(W("La espada Kimera que empuñas comienza a despedir destellos "
				"azules de luz. Cuando la espada atraviesa al espectro "
				"este da un escalofriante grito de agonía y desaparece en "
				"un fogonazo de luz que te ciega por un momento.\n\n"));
			say(W("La espada Kimera que empuña "+CATP+" comienza a despedir "
				"destellos azules de luz. Cuando la espada atraviesa al "
				"espectro este da un escalofriante grito de agonía y "
				"desaparece en un fogonazo de luz que te ciega por un "
				"momento.\n\n"));
			CHMASTER->SendMsg("info", "La paz ha vuelto al pantano de la muerte gracias a "+CATP);
       		QUESTMASTER->SetPlayerQuest("maldicion_pantano",TP);
       		write_file (LOGS "pantano",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] ha llevado la paz al pantano de la muerte.\n");
       		write("[56m¡Enhorabuena!, has conseguido acabar con la maldición del pantano de la muerte![0m\n\n");
        	write("La espada empieza a brillar y a emitir un zumbido... De repente desaparece\n");
        	say(W("La espada de "+CATP+" empieza a brillar y a emitir un zumbido... De repente desaparece.\n"),TP);
			esp->remove();
			TO->remove();
			return 1;
		}
		else
		{
			write(" pero es como si atravesaras el aire...\n");
			say(" pero es como si atravesara el aire...\n",TP);
			ffalla(2,TP);
			return 1;
		}
	}
}
