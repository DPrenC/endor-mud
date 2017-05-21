/****************************************************************************
Fichero: entrada_posada.c
Autor: Kastwey
		[T] Tagoras
Creación: 28/07/2005
Descripción: Entrada de la posada de Annufam
[T] 23/03/2009: Añado sonido de campanilla
****************************************************************************/

#include "./path.h"
#include <keeper.h>
#include <nightday.h>
#include <moving.h>
#include <combat.h>
#include <properties.h>
#include <sounds.h>


#define A		 (TP->QeryGender() == 2?"a":"")
#define TOCAR	   ({"campana","campanilla","campanita","la campana","la \
campanilla","la campanita","la campana del mostrador","la campanilla del \
mostrador","la campanita del mostrador"})
#define COGER_LLAVE ({"llave del gancho","llave de gancho","llave de techo",\
"llave del techo","llave del gancho del techo","llave del gancho de techo"\
"llave de gancho de techo"})

#define MALAS_HORAS ({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE})

#define PUERTA_CASA ({"puerta","puerta de casa","puerta de la casa","puerta \
de la casa del posadero"})

inherit BASE_CIUDAD_ANNUFAM;
inherit KEEPER;

int pEmpleado, pLlave;
public int SetEmpleado(int i)
{
	if (!i)
	// el empleado ha muerto
	{
		// borramos al empleado para que no se regenere con un reset
		RemoveItem(PNJ_CIUDAD_ANNUFAM("roin"));
	}
	return pEmpleado = i;
}
public int QueryEmpleado() { return pEmpleado; }

public int SetLlave(int i) { return pLlave = i; }
public int QueryLlave() { return pLlave; }



int cmd_abrir_cerrar(string str)
{
	if (!str || member(PUERTA_CASA,str) < 0) return 0;
	if (query_verb() == "abrir")
	{
		write("La puerta está cerrada con llave. No puedes abrirla.\n");
		return 1;
	}
	write("La puerta ya está cerrada.\n");
	return 1;
}
void quitar_empleado()
{
	object keeper;
	object *inv;
	if (!(keeper = QueryKeeper())) return;
	if (keeper->Fightin())
	{
		call_out("quitar_empleado",20+random(20));
		return;
	}
	inv = all_inventory(keeper);
	if (sizeof(inv))
	// tiene cosas
	{
		KeeperEmote("suelta " + enumerar(map(inv,(:   $1->QueryShort()
												  || $1->QueryName():)),1) +
					", y se dirige hacia la puerta de su casa.\n");
	}
	else
	{
		KeeperEmote("sale del mostrador y se dirige hacia su casa.\n");
	}
	RemoveKeeper();
}

varargs int cmd_tocar(string str, int silent)
{
	string raza;
	if (!str || member(TOCAR,str) < 0)
	{
		return notify_fail("¿Tocar qué?",NOTIFY_NOT_VALID);
	}
	if (!silent)
	{
		play_sound(TO, SND_SUCESOS("campanilla"));
		write("Tocas la campanilla...\n"
			  "¡TIILIIIN! ¡TIILIIIN!\n");
		say(CAP(TNAME) + " toca la campanilla...\n"
			"¡TIILIIIN! ¡TIIILIIIIN!\n");
	}
	if (QueryKeeper())
	// el empleado ya está aquí
	{
		KeeperEmote(({"te mira con mala cara y te dice: '¿Para qué tocas "
					  "la campanita si estoy aquí? ¿o es que no me ves?'\n",
					  "mira a " + CAP(TNAME) + " con mala cara y le dice: "
					  "'¿Para qué tocas la campanita si estoy aquí? ¿o es "
					  "que no me ves?\n"}));
		if (find_call_out("quitar_empleado"))
		{
			remove_call_out("quitar_empleado");
			call_out("quitar_empleado",20+random(20));
		}
		return 1;
	}
	// no hay empleado.
	// ¿ha sido asesinado?
	if (!pEmpleado)
	// ¡si! así que no lo traemos
	{
		if (!silent) write ("No ocurre nada.\n");
		return 1;
	}
	// No ha sido asesinado, así que lo traemos.
	SetKeeper(PNJ_CIUDAD_ANNUFAM("roin"));
	if (member(MALAS_HORAS,SERVER->QueryState()) >= 0)
	// ¿Qué horas son estas de tocar a la campanita? ;)
	{
		if (member(RAZASENEMIGAS,(raza = TP->QueryRace())) >= 0)
		// eres un enemigo
		{
			KeeperEmote(({"te mira y sus facciones toman de repente un aire "
						 "amenazador mientras te grita:\n",
						 "mira a " + CAP(TNAME) + " y sus facciones toman "
						 "un aire amenazador mientras le grita:\n"}));
			tell_room(TO,W("'¡Pero maldita escoria!!! ¿Crees que un " +
							A + raza + " como tú tiene derecho a despertarme "
							"a esta hora y a hacerme venir hasta la "
							"posada?'\n\n" + KeeperName(K_CAP) +
							" saca un garrote de detrás del mostrador.\n"));
			write(W("Después de esto, decides no jugarte más el tipo y "
					"abandonar la posada antes de que le dé por meterte un "
					"buen garrotazo.\n"));
			say(W(CAP(TNAME) + " mira el garrote y con paso rápido sale de la "
				  "posada.\n"));
			TP->command_me("norte");
		}
		else
		{
			// no es enemigo
			KeeperEmote(({"te mira y te dice: 'Hola foraster" + AO + "... "
			"Espero que tengas alguna razón convincente para haber tocado la "
			"campanita a estas horas.'\n",
						  "mira a " + CAP(TNAME) + " y le dice algo.\n"}));
		}
	}
	else
	// es una hora normalita.
	{
		if (member(RAZASENEMIGAS,(raza = TP->QueryRace())) >= 0)
		{
			KeeperEmote(({"te mira y pone cara de disgusto mientras grita:",
						  "mira a " + CAP(TNAME) + " con cara de disgusto "
						  "mientras grita:\n"}));
			tell_room(TO,W("'¡Lo que me quedaba por ver! ¿De verdad te crees "
						   "que voy a atender a un " + raza + " en mi posada? "
						   "Pues andas tú list" + AO + "! ¡Lárgate "
						   "ahora mismo de aquí!\n"));
		}
		else
		{
			KeeperEmote(({"te sonríe y te dice: 'Hola foraster" + AO + ". "
						  "¿Deseabas algo?'\n",
						  "sonríe a " + CAP(TNAME) + " y le dice algo.\n"}));
		}
	}



	call_out("quitar_empleado",20+random(20));
	return 1;
}


string mirar_gancho()
{
	if (   TP && !TP->QueryAttribute("llave_posada_annufam")
		&& QueryLlave())
	{
		TP->SetAttribute("llave_posada_annufam",1);
	}

	return W("Te acercas al mostrador y miras hacia arriba. Colgado en el "
	"techo, ves un gancho " + (QueryLlave() ? "con una gran llave "
							   "enganchada" : " sin nada enganchado") + ".\n");
}


string mirar_llave()
{
	if (   !TP || !QueryLlave()
		|| !TP->QueryAttribute("llave_posada_annufam"))
	// no hay llave que valga
	{
		return 0;
	}
	// ponemos el atributo de la llave encontrada a todos los players
	// que haya en la habitación, pues se han dado cuenta de lo que miraba
	// este jugador
	filter(all_inventory(),(:(query_once_interactive($1)
							  && !$1->QueryAttribute("llave_posada_annufam") ?
							  $1->SetAttribute("llave_posada_annufam",1):0):));
	return W("Se trata de una gran llave plateada. Supones que será la llave "
			 "maestra de las habitaciones del piso de arriba.\n");
}

int cmd_coger(string str)
{
	if (   !str || member(COGER_LLAVE,str) < 0
		|| !TP->QueryAttribute("llave_posada_annufam") || !pLlave)
	{
		return 0;
	}
	// va a intentar coger la llave.
	if (QueryKeeper())
	// si está el posadero, como que no
	{
		return notify_fail(W("Miras hacia la llave, luego miras a " +
							 KeeperName() + ", y sabiamente, decides "
							 "que no parece el momento más adecuado para "
							 "intentar hacerte con ella.\n"),
							 NOTIFY_NOT_VALID);
	}
	play_sound(TO, SND_SUCESOS("campanilla"));
	write(W("Aprovechando la ausencia de los dueños de la posada, te pones "
			"manos a la obra.\n"
			"Con cuidado, te encaramas al mostrador. Sin embargo, tus pies "
			"chocan contra la campanita y la hacen sonar estruendosamente.\n"));
		say(W(CAP(TNAME) + " se encarama al mostrador, haciendo sonar "
			  "inadvertidamente la campanita de encima.\n"));
	if (pEmpleado)
	// el empleado no está, pero sigue vivito en su casa
	{
		write(W("Asustad" + AO + ", te dispones a bajar del mostrador antes "
				"de que venga el empleado. En tu prisa por bajar, pierdes pie "
				"y caes de espaldas al duro suelo.\n"));
		say(W("Con las prisas por bajar del mostrador, " + CAP(TNAME) +
			  " pierde pie y cae de espaldas al suelo.\n"));
		TP->Defend(5 + random(10),DT_BLUDGEON,DEFEND_F_NOMSG);
		cmd_tocar("campanita",1);
	}
	else
	// no hay empleado... ha sido asesinado
	{
		object llave;
		int val;
		write(W("Sin perder tiempo, " + (TP->QuerySize() == P_SIZE_LARGE ?
										 "coges la llave":
										 "das un salto y coges la llave") +
				". Rápidamente, bajas del mostrador.\n"));
		say("Rápidamente, coge la llave y baja del mostrador.\n");
		pLlave = 0;
		llave = clone_object(OTRO_ANNUFAM("llave_maestra_posada"));
		if ((val = llave->move(TP,M_GET)) != ME_OK)
		// no la ha podido coger
		{
			write("Sin poder evitarlo, la llave se te cae al suelo.\n");
			say(W("Sin poder evitarlo, a " + CAP(TNAME) + " se le cae la "
				  "llave al suelo.\n"));
			llave->move(TO,M_SILENT);
		}
	}
	return 1;
}




public void create()
{
	::create();
	SetIntShort("la posada de Annufam");
	SetIntLong(W("Acabas de llegar a la recepción de la posada de la ciudad. "
				 "Observas en la pared este una bandera con el escudo del "
				 "dominio enano. Al frente hay un mostrador con una "
				 "campanilla para cuando el posadero no se encuentre aquí. "
				 "Una puerta cerrada al oeste lleva a la casa del posadero "
				 "y su familia. También ves unas escaleras que "
				 "supones llevarán al piso superior donde se ubican las "
				 "habitaciones de hospedaje.\n"));

	SetIndoors(1);
	SetIntBright(75);

	AddDetail(({"escalera","escaleras"}),
			  W("Son unas escaleras de toda la vida, en este caso, en "
				"forma de caracol. Comunican los dos pisos de la posada.\n"));

	AddDetail("puerta",W("Se trata de la puerta que da a parar a la casa de "
						 "la familia del posadero.\n"));

	AddDetail("mostrador",(:W("Es el mostrador donde el posadero o su mujer "
							  "atienden a los clientes que vienen a la posada. "
							  "Tiene una campanilla para cuando ellos no se "
							  "encuentran aquí, poder avisar.\n"
							  "Por encima del mismo y colgado en el techo, "
							  "observas una especie de gancho " +
							  (QueryLlave() ? "con algo "
							   "enganchado" : " que parece estar vacío") +
							  ".\n"):));

	AddDetail(({"gancho","gancho del techo","gancho de techo"}),
			   #'mirar_gancho);


	AddDetail(({"llave","llave del gancho","llave de gancho"}),
			  #'mirar_llave);

	AddDetail(({"campana","campanilla"}),
			  "Es una campanilla plateada, si la tocas puede que suene.\n");

	AddEstandarte(EST_NORMAL);
	pEmpleado = 1; // se pone el empleado a 1... Es decir, vendrá cuando
				  // se toque la campanita... Cuando muera, se pondrá a 0 hasta
				  // que se haga un reset en la habitación.
	pLlave = 1; // la llave maestra está en el gancho

	AddRoomCmd("tocar","cmd_tocar");
	AddRoomCmd("coger","cmd_coger");
	AddRoomCmd(({"abrir","cerrar"}),"cmd_abrir_cerrar");



	AddExit("norte",HAB_THUALIN_ANNUFAM("thualin_03"));
	AddExit("arriba",HAB_POSADA_ANNUFAM("pasillo_piso1"));
	AddExit("oeste",(:return write("La puerta de la casa del posadero está "
							"cerrada.\n"), 1;:));

}

public void reset()
{
	::reset();
	pEmpleado = 1; // cuando suene la campanita vendrá el empleado
	pLlave = 1; // la llave maestra está en el gancho
}
