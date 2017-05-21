/* vi: set tabstop=4 */
/** @file camino_12.c
	@brief un pequeño sendero
	@author [T] Tagoras
	@version 1.00
	@date 2009-04-15

Parece que el fácil sendero que lleva a Annufam queda cortado aquí por una escarpada pared.
*/

#include "./path.h"
#include <combat.h>
#include <moving.h>
#include <properties.h>
#include <skills.h>

#define TREPAR ({"pared", "barranco", "pared escarpada", "barranco escarpado", "por pared", "por pared escarapada", "por barranco", "por barranco escarpado", "por la pared", "por el barranco", "por la pared escarpada", "por el barranco escarpado"})

#define HAB_ARRIBA HAB_SENDERO_ANNUFAM("sendero1")

inherit HAB_CAMINO_ANNUFAM("sendero_base");

public void create() {
	::create();
	SetLocate("Camino Annufam");
	SetIntShort("un pequeño sendero");
	SetIntLong("Parece que el fácil sendero que lleva a Annufam queda cortado aquí por una escarpada pared.\n");
	AddDetail(({"pared", "barranco"}), "Es un barranco de roca que parece cortar el camino, aunque algunos ruidos parecen que vienen de arriba. Tal vez deberías probar a escalar un poco.\n");
	AddExit("suroeste", "camino_11");
	//AddExit("arriba", "sendero1");
	AddRoomCmd(({"trepar", "escalar", "subir", "arriba"}), "cmd_trepar");
	AddItem(PNJ_SENDERO_ANNUFAM("lobo_base"), REFRESH_DESTRUCT, 1+random(2));
}

public int cmd_trepar(string str)
{
	int hab;

	if (!str ||member(TREPAR,LOWER(trim(str))) < 0)
		return notify_fail("¿" + CAP(query_verb()) + " por dónde?\n", NOTIFY_NOT_VALID);

	hab = TP->UseSkill(HAB_TREPAR);
	// Si lleva puestas botas de escalada se añade una bonificación al uso de la habilidad.
	if (sizeof(filter(TP->QueryArmours() ||({}),(:$1->id("botas_escalada"):))))
		hab += 50;
	// Imposible subir
	if (hab < -50)
	{
		write("Comienzas a escalar pero a los pocos pasos te resbalas y caes de culo al suelo.\n");
		say(CAP(TNAME)+" comienza a escalar pero a los pocos paso se resbala y cae de cuelo al suelo.\n", TP);
		TP->Defend(20+random(5), DT_BLUDGEON, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
		return 1;
	}
	if (hab < -20)
	{
		write("Temblorosamente escalas el barranco pero a media altura tu pie pierde agarre y te precipitas al suelo con gran estruendo.\n");
		say(CAP(TNAME)+" temblorosamente escala el barranco pero a media altura su pie pierde agarre y se precipita al suelo con gran estruendo.\n");
		TP->Defend(30+random(10), DT_BLUDGEON, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
		return 1;
	}
	if (hab < 0)
	{
		write("Con gran esfuerzo escalas el barranco procurándote un buen agarre y cuando estás a punto de llegar a la cima una ráfaga súbita de viento te descentra y caes al vacío. Toda tu vida pasa ante tus ojos en los segundos que dura el vertiginoso descenso. Con pesar observas que no has realizado nada de lo que puedas enorgullecerte.\n");
		say(CAP(TNAME)+" con gran esfuerzo escala el barranco y cuando está a punto de llegar a la cima una ráfaga súbita de viento le descentra y cae al vacío.\n");
		TP->Defend(40+random(15), DT_BLUDGEON, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
		return 1;
	}
	// Lo logra
	TP->move(HAB_ARRIBA, M_SPECIAL, ({CAP(TNAME)+" parece que ha hecho esto toda la vida porque en un tris tras alcanza la cima y desaparece de tu campo de visión.\n", CAP(TNAME)+" aparece por la cornisa del barranco\n",
		"Con mucha maña vas asiéndote a los recovecos de la roca para asegurar tu posición y en menos tiempo del que inicialmente habías supuesto alcanzas la cima.\n"}));
	return 1;
}
