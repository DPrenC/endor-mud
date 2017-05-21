/* vi: set tabstop=4 */
/** @file celda.c
	@brief la celda de castigo de Tagoras
	@author SimBuilder
	@version 1.00
	@date 2009-03-28

Es una celda de 3 por 3 metros excavada mágicamente en la roca. La altura de la estancia es de 2 metros. Por lo que puedes ver hay una litera para poder dormir, algún tipo de luz mágica para poder ver, un agujero por el que aliviarse cuando la fisiología de cada uno lo reclama y un grifo para beber. También hay un cartel, una pizarra, una tiza y un borrador, seguramente elementos claves para poder cumplir tu penitencia. No ves ninguna puerta y sólo un ventanuco con rejas te permite ver algo de lo que hay afuera de esta celda.
*/

#include "./path.h"
#include <magia.h>
#include <moving.h>
#include <properties.h>
#include <sounds.h>

inherit ROOM;

#define ASTHAR			"/d/limbo/comun/habitacion/limbo/templo/altar"
#define CELDA			"/d/limbo/comun/habitacion/limbo/torrewiz/rooms/tagoras/celda"
#define MULTIPLO_VECES	10
#define AO				(TP->QueryGender()==GENERO_FEMENINO?"a":"o")

public void ChecPhrase(object player, string phrase);
public void EndPenalty(object player, int silent);
public void StartPenalty(object player, string phrase);
int cmd_beber(string str);

public void CheckPhrase(object player, string phrase)
{
	string p_phrase;

	if (p_phrase=player->QueryAttribute(TAGORAS_CASTIGO_FRASE))
	{
		if (LOWER(trim(p_phrase)) == LOWER(trim(phrase)))
		{
			player->SetAttribute(TAGORAS_CASTIGO_VECES, player->QueryAttribute(TAGORAS_CASTIGO_VECES)+1);
			if (player->QueryAttribute(TAGORAS_CASTIGO_VECES) < (MULTIPLO_VECES*player->QueryAttribute(TAGORAS_CASTIGO_NUMERO)))
				tell_object(player, "Bien hecho, ya te falta una menos.\n");
			else
				EndPenalty(player, 0);
		}
	}
}

public void EndPenalty(object player, int silent)
{
	object tiza = present("tiza", player);
	object borrador = present("borrador", player);

	if (tiza)
		tiza->move(TO, M_SILENT);
	if (borrador)
		borrador->move(TO, M_SILENT);

	player->RemoveAttribute(TAGORAS_CASTIGO_VECES);
	player->RemoveAttribute(TAGORAS_CASTIGO_FRASE);

	if (! silent)
		tell_object(player, "Has cumplido tu penitencia, esperemos que no vuelvas por aquí.\n");

	player->move(ASTHAR, M_TELEPORT);
}

public void StartPenalty(object player, string phrase)
{
	player->SetAttribute(TAGORAS_CASTIGO_NUMERO, player->QueryAttribute(TAGORAS_CASTIGO_NUMERO)+1);
	player->SetAttribute(TAGORAS_CASTIGO_FRASE, trim(phrase));
	player->SetAttribute(TAGORAS_CASTIGO_VECES, 0);
	player->move(CELDA, M_SILENT);
	tell_object(player, "Por graves ofensas contra los mismisimos dioses has sido castigado a cumplir tu penitencia a esta celda de castigo.\n");
	player->LookAfterMove();
}

public string LeerCartel()
{
	if (!TP->QueryAttribute(TAGORAS_CASTIGO_NUMERO) || !TP->QueryAttribute(TAGORAS_CASTIGO_FRASE))
	{
		call_out("EndPenalty", 2, TP, 1);
		return "Tú no deberías estar aquí.\n";
	}

	return ("Tu penitencia para poder salir de esta celda consistirá en escribir "+10*TP->QueryAttribute(TAGORAS_CASTIGO_NUMERO)+" veces la frase: '"+TP->QueryAttribute(TAGORAS_CASTIGO_FRASE)+"' en la pizarra.\n");
}

public string MirarVentanuco()
{
	return "Es un ventanuco por el que puedes ver el tiempo que hace en el exterior. Ahora mismo "+LOWER("/obj/chronos"->QueryWeatherMsg());
}

create() {
	::create();
	SetLocate("Workroom de Tagoras");
	SetIntShort("la celda de castigo de Tagoras");
	SetIntLong("Es una celda de 3 por 3 metros excavada mágicamente en la roca. La altura de la estancia es de 2 metros. Por lo que puedes ver hay una litera para poder dormir, algún tipo de luz mágica para poder ver, un agujero por el que aliviarse cuando la fisiología de cada uno lo reclama y un grifo para beber. También hay un cartel, una pizarra, una tiza y un borrador, seguramente elementos claves para poder cumplir tu penitencia. No ves ninguna puerta y sólo un ventanuco con rejas te permite ver algo de lo que hay afuera de esta celda.\n");
	SetIntBright(35);
	AddDetail(({"pared", "paredes", "suelo", "techo"}), "Es de roca maciza inexpugnable.\n");
	AddDetail(({"ventana", "ventanuco"}), SF(MirarVentanuco));
	AddDetail("cartel", "En este cartel está escrita tu penitencia. Deberías leerlo.\n");
	AddDetail("litera", "Es un camastro de madera y paja donde se puede descansar un poco.\n");
	AddDetail("grifo", "Es un grifo de agua corriente; parece que gotea.\n");
	AddReadMsg("cartel", SF(LeerCartel));
	SetIntNoise("De vez en cuando oyes el goteo del grifo.\n");
	SetIntSmell("Huele a orines y otras deposiciones.\n");
	SetSafe(1);
	ForbidAllMagic("Los hechizos que ha puesto Tagoras en esta celda te impiden invocar ninguna clase de magia.\n");
	AddItem(TAGORAS_OTRO_CASTIGO("tiza"), REFRESH_REMOVE, 3);
	AddItem(TAGORAS_OTRO_CASTIGO("borrador"), REFRESH_REMOVE);
	AddItem(TAGORAS_OTRO_CASTIGO("pizarra"), REFRESH_REMOVE);
	AddItem(TAGORAS_OTRO_CASTIGO("mendrugo"), REFRESH_REMOVE, 1+random(3));
	AddRoomCmd("beber", "cmd_beber");
	SetSoundEnvironment(SND_AMBIENTES("gotas"), 50);
}

int cmd_beber(string str)
{
	if (!str || str=="agua"){
		if (TP->QueryDrink() >= TP->QueryMaxDrink())
			return notify_fail("Ya estás llen"+AO+" de agua, no puedes beber más.\n", NOTIFY_NOT_VALID);
		TP->AddDrink(5);
		write("Acercas la boca al grifo y bebes un poco de agua.\n");
		say(CAP(TNAME)+" se acerca al grifo y bebe un poco de agua.\n");
		return 1;
	}
	return notify_fail("Tienes abundante agua en el grifo para beber, aprovéchala.\n", NOTIFY_NOT_VALID);
}
