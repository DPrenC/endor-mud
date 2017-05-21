/**************************************************************************
Fichero: anglhanail.c
Autor: Tagoras
Creación: 28/02/2009
Descripción: El anciano sanador del centro
***************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit PNJ_BASE_ANNUFAM;
inherit "/lib/money";

#define COSTE 1000
#define COSTE_STR "una moneda de platino"

public void create()
{
    ::create();
    SetStandard("anglhanail","enano",80,GENDER_MALE);
    AddId(({"anglhanail","sanador"}));
    SetShort("Anglhanail el sanador");
    SetLong("Es un anciano enano que trabaja en el centro desde hace muchos años pero que todavía mantiene mucha energía. Se gana la vida ofreciendo sus servicios de sanador a los reclutas y soldados. Quizá si le pagas bien esté dispuesto a sanar tus heridas.\n");
	InitChats(10, ({"Por "+COSTE_STR+" te puedo dar uno de mis famosos masajes.\n",
					"Si quieres puedes contratar mis servicios, soy un buen sanador.\n"}));
}

init()
{
	::init();
	add_action("cmd_contratar", "contratar");
	add_action("cmd_masaje", "'");
	add_action("cmd_masaje", "decir");
	add_action("cmd_masaje", "pagar");
}

int cmd_contratar(string str)
{
	string servicio, trabajador;

	if (!str) return notify_fail("¿Contratar qué de quién? \n", NOTIFY_NOT_VALID);
	if (sscanf(LOWER(str), "%s de %s", servicio, trabajador)!=2)
		return notify_fail("¿Contratar qué de quién? \n",NOTIFY_NOT_VALID);
	if (("anglhanail" != trabajador) && ("enano" != trabajador) && ("sanador" != trabajador))
		return notify_fail(CAP(trabajador)+" no ofrece servicios.\n", NOTIFY_NOT_VALID);
	if ("servicios" != servicio)
		return notify_fail(CAP(trabajador)+" no ofrece ese servicio.\n", NOTIFY_NOT_VALID);

	write("Anglhanail te dice: El servicio te costará "+COSTE_STR+". ¿Estás dispuest"+AO+" a pagar esa cantidad?\n");

	return 1;
}

int cmd_masaje(string str)
{
	int dinero;
	string trabajador;

	if (!str)
	{
		if (("'" == query_verb()) || ("decir" ==  query_verb()))
			return notify_fail("¿Decir qué?\n", NOTIFY_NOT_VALID);
		if ("pagar" == query_verb())
			return notify_fail("¿Pagar a quién?\n", NOTIFY_NOT_VALID);
	}
	if (("'" == query_verb()) || ("decir" ==  query_verb()))
	{
		if (("si" != LOWER(str)) && ("sí" != LOWER(str)))
			return 0;
	}
	if ("pagar" == query_verb())
	{
		if (sscanf(LOWER(str), "a %s", trabajador) != 1)
			return notify_fail("¿Pagar a quién?\n", NOTIFY_NOT_VALID);
		if (("anglhanail" != trabajador) && ("enano" != trabajador) && ("sanador" != trabajador))
			return notify_fail(CAP(trabajador)+" no ofrece servicios.\n", NOTIFY_NOT_VALID);
	}

	dinero = QuerySomeonesValue(TP);
	if (dinero < COSTE)
        return notify_fail("Cuando vas a pagarle, te das cuenta de que no llevas suficiente dinero encima.\n", NOTIFY_NOT_VALID);;

	write ("Anglhanail asiente con la cabeza y te invita a tumbarte en uno de los cómodos sillones que hay en la sala. Después de estar un rato dándote masaje te levantas con mucho mejor aspecto. Te sientes tan bien que le das a Anglhanail todo tu dinero de propina y sales de la habitación.\n");
	PayValue(TP, dinero);
	TP->SetHP(TP->QueryMaxHP());
	TP->move(HAB_SEGUNDA_ANNUFAM("c114"), M_GO);
	return 1;
}
