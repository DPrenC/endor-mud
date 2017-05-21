/* Este es el asesino drow que envia Rak-nal-turi */

#include "path.h"
#include <colours.h>			// Para quitar los colores del terminal en catch_tell
#include <properties.h>			// GENDER_MALE
#include <guild.h>				// GC_ASESINO
#include <moving.h>				// M_GO

inherit NPC;

#define DROW_PURSUE		2		// Los segundos que tarda el Drow en perseguir a la victima.
#define DROW_LIFETIME	900		// Para no tener los drows por ahí danzando a los 15 minutos desaparecen

public void endkill();

create()
{
	::create();
	SetStandard ( "drow", "elfo-oscuro", ([GC_ASESINO:55]), GENDER_MALE);
	SetLong("Pocos han visto a un asesino drow y han vivido para contarlo, pero es tal como te esperabas. Un elfo oscuro de piel cetrina y cabello cano enfundando en ropajes negros para confundirse con la noche. Cuando está de misión se cubre la cabeza y sólo pueden verse sus ojos grises. Son fríos y letales.\n"
		"Entre su armamento de combate destaca la katana larga a dos manos que en las misiones nocturnas pintan de negro para que el brillo acerado de su filo no les descubra. Son muy diestros en su uso, pero para las misiones que requieren sutileza prefieren acercarse sigilosamente a su victima y clavarles un kukri en la espalda.\n"
		"Son conocidos también por el uso de diferentes venenos y ungüentos en sus armas, con lo que se aseguran que aunque la herida no parezca fatal en un principio, la toxina que lleva la hoja penetre en la victima, la cual, sin tratamiento, se expone a una muerte lenta y dolorosa.\n" );
	SetAlign(-1000);
	SetWeight(82000);			// 82 Kg
	SetSmell("Extrañamente no huele a nada, será alguna habilidad drow para enmascarar el olor.\n" );
	SetWhimpy(0);
	SetAggressive(1);
	SetAttackOwnRace(1000);
	SetAttackChance(1000);
	InitAChats(10,({"El drow dice: 'Por orden de mi amo, Rak-nal-turi, debes morir.'\n",
					//"El drow dice: 'He sido enviado para matarte "+capitalize(TP->QueryRealName())+"!!!'\n",
					"El drow dice: 'He sido enviado para matarte!!!'\n",
					"El drow dice: 'Podrás huir pero no escapar.'\n"}));
	AddItem(ARMA("katana_drow"), REFRESH_DESTRUCT, SF(wieldme));
	AddItem(PROT("botas_drow"), REFRESH_DESTRUCT, SF(wearme));
	AddItem(PROT("pantalones_drow"), REFRESH_REMOVE, SF(wearme));
	AddItem(PROT("guantes_drow"), REFRESH_REMOVE, SF(wearme));
	AddItem(PROT("coraza_drow"), REFRESH_REMOVE, SF(wearme));
	AddItem("/obj/sunglasses", REFRESH_REMOVE, SF(wearme));			// Para que puedan ver.
	call_out ( "endkill", DROW_LIFETIME );
}

public void endkill ()
{
	object * cosas;
	int i;

	if (TO->Fighting())
	{
		say ( "No me puedo entretener en peleas absurdas, mi amo me reclama.\n" );
		//call_out ( "endkill", 5 );
		//return;
	}
	else
		say ( "El drow da por concluida su misión y vuelve con Rak-nal-turi.\n" );
	say ( "Ves como el drow desaparece en una nube tan negra como el corazón de su amo.\n" );
	cosas = all_inventory(TO);
	if (sizeof(cosas))
		for(i=0; i<sizeof(cosas); i++)
			cosas[i]->remove();
	TO->remove();
}

// Para perseguir a las victimas
public void pursue (string victima)
{
	int move_result;

	//move_result = ::move(environment(victima), M_GO, ({"persiguiendo a " + capitalize(victima), "corriendo tras " + capitalize(victima), "Persigues a tu victima"}));
	say("El drow se va persiguiendo a " + capitalize(victima) + "\n");
	move_result = ::move(environment(victima), M_NOCHECK, ({"se va persiguiendo a " + capitalize(victima), "llega corriendo tras " + capitalize(victima), "Persigues a tu victima"}));
	say("El drow llega corriendo tras " + capitalize(victima) + "\n");
	if (find_object("tagoras")) dtell("tagoras",sprintf("Drow: persiguiendo %s -> result move: %d\n", victima, move_result));
	//if ( ME_NO_LEAVE == move_result )
	//	call_out ( "pursue", DROW_PURSUE, victima );
}

public void catch_tell(string str)
{
	int i;
	string victima, salida;
	object *enemigos, oldenv;

	str=LOWER(terminal_colour(str, NO_COLOURS));

	//if (sscanf(str, "tagoras %s\n", victima) == 1)
		//if (find_object("tagoras")) dtell("tagoras",sprintf("Drow: detectado [%s]\n", victima));
	//if (find_object("tagoras")) dtell("tagoras",sprintf("Drow: leido [%s]\n", str));
	if (sscanf(str, "%s se va hacia el %s.", victima, salida) == 2)
	{
		enemigos=QueryEnemies();
//if (find_object("tagoras")) dtell("tagoras",sprintf("esto: %s\n", QueryName()));
//if (find_object("tagoras")) dtell("tagoras",sprintf("TO: %s\n", TO->QueryName()));
//if (find_object("tagoras")) dtell("tagoras",sprintf("TP: %s\n", TP->QueryName()));
		for (i=0;i<sizeof(enemigos);i++)
		{
//if (find_object("tagoras")) dtell("tagoras",sprintf("Drow: enemigo [%s] <-> victima [%s]\n", LOWER(enemigos[i]->QueryName()), victima));
			if (LOWER(enemigos[i]->QueryName())==victima)
			{
				if (find_object("tagoras")) dtell("tagoras",sprintf("Drow: %s se ha ido hacia el %s\n", victima, salida));
//if (find_object("tagoras")) dtell("tagoras",sprintf("Drow: nos vamos al %s\n", salida));
				// No se puede usar el move inmediatamente porque estamos luchando y devuelve ME_NO_LEAVE
				// La victima tiene posibilidad de escapar si se mueve rápido y algún Drow se puede perder por el camino.
				call_out ( "pursue", DROW_PURSUE, victima );
				//call_out ( "command_me", DROW_PURSUE, salida );
/** Esto funciona pero va muy a pelo. (/d/std/thing/moving.c) Los mensajes salen antes que la descripción de la room, xddd.
					oldenv=environment();
					move_object(TO, environment(victima));
					if (oldenv) oldenv->notify_leave(environment(victima), M_GO);
					environment(victima)->notify_enter(oldenv, M_GO);
**/
				return;
			}
		}
	}
	if (sscanf(str, "%s se va hacia %s.", victima, salida) == 2)
	{
		if ( ( "abajo" == salida ) || ( "arriba" == salida ) )
		{
			enemigos=QueryEnemies();
			for (i=0;i<sizeof(enemigos);i++)
			if (LOWER(enemigos[i]->QueryName())==victima)
			{
				if (find_object("tagoras")) dtell("tagoras",sprintf("Drow: %s se ha ido hacia %s\n", victima, salida));
				call_out ( "pursue", DROW_PURSUE, victima );
				//call_out ( "command_me", DROW_PURSUE, salida );
				return;
			}
		}
	}
}
