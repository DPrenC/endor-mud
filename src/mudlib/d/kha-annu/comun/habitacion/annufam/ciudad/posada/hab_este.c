/****************************************************************************
Fichero: hab_este.c
Autor: Kastwey
		[T] Tagoras
Creación: 19/08/2005
Descripción: habitación oeste de la posada de Annufam
[T] 22/03/2009: Pongo puertas estandar
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <moving.h>
#include <sounds.h>

#define PASILLO			  (HAB_POSADA_ANNUFAM("pasillo_piso1.c"))
#define MENSAJES_CERRAR	  ({"escuchas ruidos en la habitación este...\n",\
"escuchas pasos que se acercan a la puerta, y vislumbras una silueta \
recortada contra la misma. Sin darte tiempo a ver más, la figura \
cierra la puerta violentamente.\n"})

#define MAX_VECES_MOLESTADOS 3
// las veces que se puede molestar al soldado y a la novia antes de que
// el soldado salga y te ataque

inherit HAB_POSADA_ANNUFAM("hab_base_posada");

int msg_count; // el contador para los mensajes de la pareja de la habitación

int veces_molestados; // las veces que se les ha molestado.
					  // a la tercera, sale el soldado pa fuera y te
					  // endiña

public void notify_close();
public void notify_open();

public object SoldadoDisponible()
// está el soldado en la habitación y puede cerrar la puerta y todo eso?
{
	int players;
	object soldado, novia;
	if (   !(soldado = present("soldado_en_el_lio",TO)) || !living(soldado)
		|| soldado->Fighting()) return 0;
	if (   !(novia = present("novia_soldado",TO)) || !living(novia)
		|| novia->Fighting()) return 0;

	players = sizeof(filter(all_inventory(TO),
							(:query_once_interactive($1):)));

	if (players) return 0;

	return soldado;
}

void mensajes()
// función para lanzar mensajitos a la room del pasillo con lo del soldado y todo eso...
{
	if (!SoldadoDisponible()) return;
	tell_room(PASILLO,MENSAJES_CERRAR[msg_count]);
	if (msg_count == sizeof(MENSAJES_CERRAR) - 1)
	{
		play_sound(load_object(PASILLO), SND_SUCESOS("cerrar_puerta"));
		FindDoor("oeste")->SetDoorState(DOOR_CLOSED, 0);
		msg_count = 0;
	}
	else
	{
		msg_count++;
		call_out("mensajes",random(10));
	}
}

void ataque(object victim, object soldado)
{
	object hacha;

	if (!victim ||!soldado) return;
	if (!present(victim))
	{
		play_sound(load_object(PASILLO), SND_SUCESOS("cerrar_puerta"));
		tell_room(PASILLO,W("La puerta de la habitación este se cierra "
							"violentamente. Supones que tu vista te ha "
							"jugado una mala pasada, pero jurarías haber "
							"visto que tras la puerta había un enano "
							"desnudo...\n"));
		FindDoor("oeste")->SetDoorState(DOOR_CLOSED, 0);
		PASILLO->FindDoor("este")->SetDoorState(DOOR_CLOSED, 0);
		while (find_call_out("mensajes") != -1) { remove_call_out("mensajes");}
		return;
	}


	tell_object(victim,W("El soldado se levanta de la cama y te lanza una "
						 "mirada furibunda mientras te grita:\n"));
	tell_room(TO,W("El soldado se levanta de la cama, y mirando a " +
					CAP(victim->QueryName()) + " con ojos llameantes le "
					"grita:\n"),({victim}));
	tell_room(TO,W("'¡¡Pero ¿qué demonios haces tú aquí? ¿Acaso no te "
				   "ha dicho Roin que todas las habitaciones estaban "
				   "ocupadas?!!!'\n\n"));

	if ((hacha = present("hacha_soldados_annufam",TO)))
	// el hacha está en la room
	{
		if ((hacha->move(soldado)) == ME_OK)
		{
			tell_room(TO,W("El soldado se agacha rápidamente y coge el hacha "
						   "que hay en el suelo.\n"));
			soldado->command_me("empuñar hacha");
		}
	}
	soldado->AddEnemy(victim);
}

public void create()
{
	::create();
	SetIntShort("la habitación este en la posada de Annufam");
	SetIntLong((:W("Esta es la habitación este de la posada de "
				   "Annufam. Como el resto de las habitaciones, puedes "
				   "observar una mesita de noche, un armario y una "
				   "cama al lado de la ventana que da al norte. " +
				   (find_call_out("ataque") != -1 ? "Parece que no has "
													"entrado en buen "
													"momento...":"") +
				   "\n"):));
	AddDetail(({"norte","ventana","ventana norte"}),
			  W("A través de la ventana ves la calle Thualin, y al frente "
				"el Centro de Adiestramiento.\n"));

	AddItem(PNJ_CIUDAD_ANNUFAM("soldado_posada"),REFRESH_DESTRUCT,1);
	AddItem(PNJ_CIUDAD_ANNUFAM("novia_soldado"),REFRESH_DESTRUCT);
	AddItem(PROT_CENTRO_ANNUFAM("sandalias_soldados"),REFRESH_REMOVE);
	AddItem(ARMA_CENTRO_ANNUFAM("hacha_guerreros"),REFRESH_REMOVE);
	AddItem(PROT_CENTRO_ANNUFAM("uniforme_soldados"),REFRESH_REMOVE);

	AddExit("oeste", "pasillo_piso1");
	AddDoor("oeste", "una puerta", "Es una puerta normal y corriente.\n", "", ([P_DOOR_LOCK_STATE: DOOR_LOCKED]));
}

public int allow_enter(mixed from, int method, mixed extra)
{
	int val = ::allow_enter(from, method, extra);
	object soldado = SoldadoDisponible();
	if (val == ME_OK && query_once_interactive(PO) && soldado)
	// se ve que no has entrado en buen momento...
	{
		tell_object(PO,W("Al entrar escuchas una exclamación de sorpresa "
						 "proveniente de algún punto de la habitación.\n"));
		call_out("ataque",3,PO, soldado);
	}
	return val;

}

public void notify_close()
// se notifica que se ha cerrado la puerta
{
//if (find_object("tagoras")) dtell("tagoras","La puerta se cierra.\n");
	// ponemos los mensajes de la parejita a 0, y quitamos los
	// posibles call_outs para la función de los mensajes
	{
		msg_count = 0;
		while (find_call_out("mensajes") >= 0)
		{
			remove_call_out("mensajes");
		}
	}
}

public void notify_open()
// se notifica que se ha abierto la puerta
{
	object soldado;
//if (find_object("tagoras")) dtell("tagoras","La puerta se abre.\n");
	if (   veces_molestados >= MAX_VECES_MOLESTADOS
		&& (soldado = SoldadoDisponible()))
	// ale machote, la has cagado...
	// ahora el soldado sale y te ataca
	{
		soldado->move(PASILLO,M_GO,"oeste");
		tell_room(PASILLO,W("Sale un soldado totalmente desnudo de la "
							"habitación este.\n"
							"Con una cara que denota cláramente las ganas de "
							"matar a alguien, el soldado grita: '¡¡¿Pero es "
							"que ni en esta posada puede estar uno "
							"tranquilo?!!! ¡A ver! ¿Quién ha sido el gracioso "
							"que no hace más que abrir la maldita puerta?\n"));

		write(W("Avergonzad" + AO + ", miras hacia otro lado. El "
				"soldado, que lo advierte, te mira fijamente y murmura "
				"con los dientes apretados: la madre que te parió... Te vas "
				"a enterar...\n"));

		tell_room(PASILLO,W(CAP(TNAME) + " mira hacia otro lado. El soldado, "
							"que lo advierte, " + LALO + " mira y murmura "
							"con los dientes apretados: 'La madre que te "
							"parió... Te vas a enterar...\n"),({TP}));

		soldado->AddEnemy(TP);
	}
	else if (SoldadoDisponible())
	// aún no es hora... pero ya mismo, ya...
	{
		veces_molestados++;
		call_out("mensajes",random(10));
	}
}
