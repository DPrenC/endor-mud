/**************************************************************************
fichero: sendero1.c
Autor: kastwey
		[T Tagoras
Creación: 23/07/2005
Descripción: Sendero hacia la ciudad de Annufam
[T] 15/04/2009: Cambio un poco el mensaje descripctiovo y la habitación destino
**************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>
#include <combat.h>

#define ATAR ({"cuerda al pino","cuerda a pino","cuerda en el pino","cuerda en pino"})

#define EL_ELLA (TP->QueryGender() == GENDER_FEMALE ? "ella" : "él")

//#define HAB_ABAJO	AFUERAS_KHA + "carasurd/cam1.c"
#define HAB_ABAJO	HAB_CAMINO_ANNUFAM("camino_12")

inherit HAB_SENDERO_ANNUFAM("sendero_base");

int bajar_barranco();		// salida abajo
int cmd_atar(string str);	// atar una cuerda al pino

int pCuerdaAtada;			// una cuerda para atarla en un pino y bajar mejor

public void create()
{
	::create();
	SetIntShort("un sendero en las montañas de Kha-annu");
	SetIntLong(W("Te encuentras en lo alto de las montañas que dividen el "
				 "dominio enano con el elfo. Esta zona está llena de pinos, "
				 "hayas y matorrales. Al este puedes ver un gran barranco, "
				 "y el camino a Kha-annu abajo. Parece que hay un pequeño "
				 "sendero natural que va en dirección noroeste.\n"));
	AddExit("noroeste", HAB_SENDERO_ANNUFAM("sendero2"));
	AddExit("abajo", #'bajar_barranco);
	AddRoomCmd(({"atar", "amarrar", "anudar"}), "cmd_atar");
	AddDetail("barranco", "Te acercas al límite del barranco y casi te mareas de la altura. Crees que en estas condiciones te iría muy bien una cuerda para atarla a un grueso pino y bajar por ella.\n");
}

int cmd_atar(string str)
{
	object cuerda;
	string short;
	if (!str || member(ATAR,str) < 0)
	{
		return notify_fail("¿Atar qué dónde?\n", NOTIFY_NOT_VALID);
	}
	if (!(cuerda = present("cuerda",TP)))
	{
		return notify_fail("No encuentras cuerda que atar.\n", NOTIFY_NOT_VALID);
	}
	short = cuerda->QueryShort() || "algo";
	if (member(inherit_list(cuerda),"/obj/cuerda.c") < 0)
	{
		return notify_fail("No puedes atar " + short + ".\n", NOTIFY_NOT_VALID);
	}
	// TODO: Esto es imposible porque al atar la cuerda, el player baja y la cuerda se la lleva consigo
	if (pCuerdaAtada)
	// ya hay una cuerda atada
	{
		return notify_fail(W("Ya hay una cuerda atada a un pino.\n"
							 "¿Para qué atar otra?\n"),NOTIFY_NOT_VALID);
	}
	write(W("Atas " + short + " a un pino cercano. Sin duda, "
			"ahora te será más fácil descender por el barranco.\n"));
			TP->move(HAB_ABAJO, M_SPECIAL,
					 ({"ata " + short + " en un pino cercano y comienza a "
					   "descender........................................."
					   ".........................\n"
					   "Cuando " + LALO + " pierdes de vista, observas como "
					   "la cuerda se suelta del pino y desaparece "
					   "arrastrada por " + EL_ELLA + ".\n"
					   "Escuchas un golpe sordo.\n",
					   "cae desde el barranco",
					   "Comienzas a bajar..............................."
					   ".......................\n"
					   "A falta de pocos metros para llegar al suelo, "
					   "notas que el nudo de la cuerda cede. Suerte que "
					   "casi estás allí y apenas sufres daños.\n"}));
	TP->Defend(1 + random(10), DT_BLUDGEON, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
	return 1;
}

int bajar_barranco()
{
	TP->move(HAB_ABAJO, M_SPECIAL,
			 ({"comienza a bajar con cuidado por la escarpada pared del "
			   "barranco. Al poco, ves como comienza a escurrirse, y en "
			   "cuestión de segundos se precipita al vacío",
			   "cae desde lo alto del barranco... Eso ha debido doler",
			   "Comienzas a descender, pero como ya habías previsto, era "
			   "muy difícil bajar por aquí sin tener complicaciones. La "
			   "pared es tan lisa que comienzas a escurrirte y a caer"}));
	TP->Defend(40 + random(11), DT_BLUDGEON, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
	return 1;
}
