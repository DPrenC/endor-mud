/* Este es el asesino drow que envia Rak-nal-turi */

#include "path.h"
#include <colours.h>			// Para quitar los colores del terminal en catch_tell
#include <properties.h>			// GENDER_MALE
#include <guild.h>				// GC_ASESINO
#include <moving.h>				// M_GO

inherit NPC;

int barrer();
int eliminar (object cosa);
string *cosas;
string *mensajes = ({});
mapping objetos = ([]);

create()
{
	::create();
	SetStandard ( "un barrendero", "elfo-oscuro", ([GC_AVENTURERO:60]), GENDER_MALE);
	SetLong("Es el típico barrendero que esperas encontrar en cualquier ciudad mínimamente decente. Lleva un mono azul y una gorra con la insignia del gremio de los barrenderos. Empuja un carro con un bidón para la basura. Además tiene a mano un recogedor y una escoba con la que barrer la porquería de las calles.\n");
	SetIds(({"barrendero"}));
	SetAds(({"un"}));
	SetAlign(0);
	SetWeight(75000);			// 75 Kg
	SetSmell("De tanto estar entre basura y desperdicios, algo de olor se le ha pegado.\n" );
	SetWhimpy(0);
	SetAggressive(0);
	//AddWalkZones(CIUDAD);
	SetGoChance(40);
	InitAChats(10,({"Un barrendero dice: '¡Cuánta porquería!. Estos jugadores son un poco guarretes.'\n",
					"Un barrendero dice: 'Vamos a ver si dejo esto un poco limpio'\n",
					"Un barrendero canta: 'Si yo tuviera una escoba...'\n"}));
	AddItem("/d/akallab/comun/objeto/arma/escoba.c", REFRESH_REMOVE, SF(wieldme));	// PAra poder defenderse.
	AddItem(PROT("mono_azul"), REFRESH_REMOVE, SF(wearme));
	AddItem(PROT("gorra"), REFRESH_REMOVE, SF(wearme));
	AddItem("/obj/sunglasses", REFRESH_REMOVE, SF(wearme));			// Para que puedan ver.
	//AddItem("/d/simauria/comun/objeto/otro/escoba", REFRESH_REMOVE);	// Para que pueda barrer.
	//enable_commands();
}

public varargs int move(mixed dest, int method, mixed extra)
{
	int res = ::move(dest, method, extra);
	barrer();
	return res;
}

int barrer()
{
	object *inventario, *contenido;
	int i, j;
	string descripcion, *indices;
	inventario = all_inventory(environment(TO));
	inventario = filter(inventario,SF(eliminar));
	for (i=sizeof(inventario);i--;)
	{
		contenido = deep_inventory(inventario[i]);
		for (j=sizeof(contenido);j--;)
		{
			descripcion = contenido[j]->QueryShort() || contenido[j]->QueryName() || "algo";
			contenido[j]->remove();
			if (contenido[j]) destruct(contenido[j]);
			if (!contenido[j]) objetos[descripcion]++;
		}
		descripcion = inventario[i]->QueryShort() || inventario[i]->QueryName() || "algo";
		inventario[i]->remove();
		if (inventario[i]) destruct(inventario[i]);
		if (!inventario[i]) objetos[descripcion]++;
	}
	if (sizeof((indices = m_indices(objetos))))
	{
		for (i=sizeof(indices);i--;)
		{
			if (objetos[indices[i]] > 1) mensajes+=({indices[i] + " [" + objetos[indices[i]] + "]"});
			else mensajes+=({indices[i]});
		}
		say("El barrendero suelta la escoba.\n", TO);
		tell_room(ENV(TO),"Al instante, se pone a girar sobre sí misma, mientras se ilumina inténsamente.\n"
						  "Notas como un extraño viento comienza a surgir de ella, "
						  "arremolinando a su alrededor todos los objetos que hay "
						  "tirados.\nLa escoba se eleva del suelo, mientras el "
						  "viento se hace más intenso, absorviendo todos los objetos.\n" +
						  implode(mensajes[0..<2],", ")+(sizeof(mensajes[0..<2])?" y ":"")+mensajes[<1] + " " + (sizeof(mensajes) > 1?"han":"ha") + " sido destruido" + (sizeof(mensajes) > 1?"s":"") + ".\n");
		objetos = ([]);
		mensajes = ({});
	}
	else
	{
		say("El barrendero suelta la escoba, y al darse cuenta de que no hace "
			"nada, la vuelve a coger.\n", TO);
	}
	return 1;
}

int eliminar(object cosa)
{
	if ( !cosa->QueryClassIds() || living(cosa) || cosa->QueryNoTake()
		|| cosa->QueryNoDrop() || cosa->QueryCreator() == object_name(ENV(TO)))
	{
		return 0;
	}
	return 1;
}

