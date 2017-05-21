/* Esta es una elfa muy poderosa que aparte de ser la chica de Tagoras, hace de questor */
/* Tipos de miniquest:
1: Ir a buscar algo (el questazo) en algún lado y traerselo a Darwen.
2: Ir a matar a alguien.
3: Ir a dar algo a alguien.
4: Dar dinero a alguien.
*/

#include "path.h"
#include <guild.h>
#include <properties.h>
#include <money.h>
#include <moving.h>
#include <sounds.h>
#include <time.h>
#include <files.h>

inherit NPC;
inherit "/lib/money";

#define AO					((TP->QueryGender() == 2)?"a":"o")

#define QUEST_INTERTIME		1800			// 30 minutos

#define QUEST_TYPE_FIND		0				// Encontrar algo
#define QUEST_TYPE_KILL		1				// Matar a alguien
#define QUEST_TYPE_TAKE		2				// Llevar algo a alguien
#define QUEST_TYPE_MONEY	3				// Dar dinero a alguien
#define QUEST_TYPE_COUNT	4				// Numero de tipos de quest

#define QUEST_COST_NEW		5000			// Coste quest nuevo (1mt)
#define QUEST_COST_CLUE1	10000			// Coste primera pista (2mt)
#define QUEST_COST_CLUE2	20000			// Coste segunda pista (4mt)

#define QUEST_ITEMS			({"broche_darwen", "collar_darwen", "pendientes_darwen", "tiara_darwen"})

#define QUEST_VICTIM_DELTA	3				// Diferencia de nivel entre el criminal y el player que ha de matarlo

int check_must_wait();
int check_expired();
public string quest_info(object watch);
public string item_info(string id);
int quest_clue();
int quest_end();
int quest_new();
int quest_recall();

public int QueryDarwen() { return 1; }

public string QuerySmell()
{
	string * smells = ({
		"Huele a un conjunto de esencias florales que resulta muy cautivador.\n",
		"Huele a un suave perfume de lavanda muy fresco.\n",
		"Huele a un perfume de mandarina.\n",
		"Huele a un perfume de mirra.\n",
		"Huele a un delicado perfume de jazmín que te resulta embriagador.\n",
		"Huele a un perfume a base de vainilla que resulta penetrante.\n",
		"Huele a un perfume fresco basado en la salvia.\n",
		});
	return smells[gmtime()[TM_WDAY]];
}

public string choose_room()
{
	string * rooms = ({
		"/d/akallab/comun/habitacion/akallab/azzor/bosque_morak/",
		"/d/akallab/comun/habitacion/akallab/azzor/bosque_talek/",
		"/d/akallab/comun/habitacion/akallab/azzor/puerto/",
		"/d/goldhai/comun/habitacion/bosque_norte/",
		"/d/goldhai/comun/habitacion/bosque_oscuro/",
		"/d/goldhai/comun/habitacion/bosque_wald/",
		"/d/goldhai/comun/habitacion/glucksfall/",
		"/d/goldhai/comun/habitacion/tierras_altas/",
		"/d/kenton/comun/habitacion/flenton/empalizada/",
		"/d/kha-annu/comun/habitacion/caminos/kha-kenton/",
		"/d/kha-annu/comun/habitacion/kha-annu/castillo/piso1/",
		"/d/kha-annu/comun/habitacion/kha-annu/castillo/piso2/",
		"/d/kha-annu/comun/habitacion/kha-annu/ciudad/",
		"/d/kha-annu/comun/habitacion/kha-annu/minas/planta01/",
		"/d/kha-annu/comun/habitacion/kha-annu/minas/planta02/",
		"/d/kha-annu/comun/habitacion/kha-annu/minas/planta03/",
		"/d/lad-laurelin/comun/habitacion/atbalnin/bosque/",
		"/d/lad-laurelin/comun/habitacion/atbalnin/ciudad/",
		"/d/lad-laurelin/comun/habitacion/tiinkdhil/tiin/cementerio/",
		"/d/limbo/comun/habitacion/limbo/limbo/",
		"/d/limbo/comun/habitacion/limbo/stonehenge/",
		"/d/simauria/comun/habitacion/betwa/gorat/calles/",
		"/d/simauria/comun/habitacion/betwa/gorat/casa_impreso/",
		"/d/simauria/comun/habitacion/betwa/gorat/casas/",
		"/d/simauria/comun/habitacion/betwa/gorat/playa/",
		"/d/simauria/comun/habitacion/betwa/psionics/",
		"/d/simauria/comun/habitacion/caminos/berat-rhoemas/",
		"/d/simauria/comun/habitacion/caminos/gremio/",
		"/d/simauria/comun/habitacion/caminos/nandor-sherek/",
		"/d/simauria/comun/habitacion/caminos/nandor-simauria/",	// Tiene base en camino.c
		"/d/simauria/comun/habitacion/caminos/norte_marhalt/",		// Tiene base en camino_base.c
		"/d/simauria/comun/habitacion/caminos/nyne_berat/",			// Tiene base en camino.c
		"/d/simauria/comun/habitacion/caminos/simauria-berat/",		// Tiene base en camino.c
		"/d/simauria/comun/habitacion/caminos/simauria-gorat/",		// Tiene base en camino_base.c
		"/d/simauria/comun/habitacion/marhalt/cueva/",				// Tiene base en cueva_base.c
		"/d/simauria/comun/habitacion/marhalt/enalel/poblado/calles/",
		"/d/simauria/comun/habitacion/marhalt/enalel/poblado/manzanal/",
		"/d/simauria/comun/habitacion/marhalt/fortaleza/bosque/",
		"/d/simauria/comun/habitacion/marhalt/fortaleza/fortaleza/",
		"/d/simauria/comun/habitacion/marhalt/fortaleza/senda/",
		"/d/simauria/comun/habitacion/marhalt/nandor/bosque/",
		"/d/simauria/comun/habitacion/marhalt/nandor/cementerio/",
		"/d/simauria/comun/habitacion/marhalt/nandor/granja/",
		"/d/simauria/comun/habitacion/marhalt/pomar/",
		"/d/simauria/comun/habitacion/nyne/bosque_nyne/",
		"/d/simauria/comun/habitacion/nyne/krigor/",
		"/d/simauria/comun/habitacion/sherek/aldea/calles/",
		"/d/simauria/comun/habitacion/sherek/aldea/campo/",
		"/d/simauria/comun/habitacion/sherek/aldea/casas/",
		"/d/simauria/comun/habitacion/sherek/aldea/granja/",
		"/d/simauria/comun/habitacion/sherek/aldea/pastos/",
		"/d/simauria/comun/habitacion/sherek/aldea/pradera/",
		"/d/simauria/comun/habitacion/simauria/berat/",
		"/d/simauria/comun/habitacion/simauria/gundistyr/superficie/",
		"/d/simauria/comun/habitacion/simauria/gundistyr/sotano_1/",
		"/d/simauria/comun/habitacion/simauria/gundistyr/sotano_2/",
		"/d/simauria/comun/habitacion/simauria/rhoemas/koek/calles/",
		"/d/simauria/comun/habitacion/simauria/rhoemas/koek/campos/",
	});
	string * dir_content;
	string room;
//get_dir("/d/kha-annu/comun/habitacion/annufam/ciudad/*.c", 16)
	dir_content = get_dir(rooms[random(sizeof(rooms))]+"*.c", GETDIR_PATH);
	room = dir_content[random(sizeof(dir_content))][..<3];
	// Para evitar los archivos que son base (no tendrán salidas)
	if (!find_object(room))
		load_object(room);
	if (!room->QueryExits())
		return choose_room();				// Recursivo (probamos de nuevo)
	else
		return room;
}

create()
{
	::create();
	string dest;
	SetStandard ( "Darwen", "elfo", ([GC_CONJURADOR:300]), GENDER_FEMALE);
	SetShort("Dama Darwen");
	SetLong("Dama Darwen es una elfa cuya belleza no consigues abarcar, sacude todo tu ser al contemplarla y no comprendes como alguien puede ni siquiera llegar a soñar con pasar la eternidad con ella ya que te parece inalcanzable.\n"
		"Ella y Tagoras el Duida han unido sus destinos de forma tan sublime que no puede parecerte sino lógico y evidente que así ha de ser.\n"
		"La dama es alta y esbelta como suelen ser la elfas aunque aquí el nivel de refinamiento ha superado el máximo de la raza. Su pelo es dorado y baja, todo liso, por su cabeza y sus hombros. Su piel es de un rosa pálido precioso, sus ojos son de un gris verdoso y sus labios de un rojo vivo.\n"
		"No dirías por su físico que pudiera ser un oponente formidable pero tal vez te lleves una inesperada sorpresa si en pos de la locura se te ocurriera atacarla.\n"
		);
	SetAlign(1000);
	SetWeight(59000);										// 59 Kg
	SetSmell("Huele a un perfume floral que te resulta muy cautivador.\n");
	SetWhimpy(0);
	AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["mithril":random(9)+1,"platino":random(3)+1])]));
	SetAggressive(0);
	SetAttackOwnRace(1000);
	SetAttackChance(1000);
	Set(P_CANT_LURE, 1);
	Set(P_CANT_FIGHT, 1);
	//Set(P_CANT_FIGHT, "Intentas atacar a Darwen pero, por un momento, piensas en lo que Tagoras te haría, y desistes.\n");
	enable_commands();
	InitChats(10,({"Dama Darwen dice: 'Yo soy Dama Darwen, si me ayudas te recompensaré.'\n",
		"Dama Darwen dice: 'Mi corazón pertenece a un sólo elfo por siempre jamás.'\n",
		"Dama Darwen dice: 'Si quieres ayudarme escribe: reto ayuda'\n",
		"Dama Darwen suspira.\n",
		"Dama Darwen parece pensativa, ¿en quién estará pensando?\n",
					}));
	InitAChats(5,({"Dama Darwen dice: 'Insensato!!! Atacas poderes que no entiendes.'\n",
		"Dama Darwen dice: 'Si yo muero Tagoras te persiguirá por toda la eternidad.'\n"}));

	AddQuestion(({"ayuda", "ayudar", "problema", "problemas", "quest", "quests", "reto", "retos", "mision", "misión", "misiones"}), "Dama Darwen dice: 'Simauria es muy vasta y, de vez en cuando, hay que buscar algo que se ha perdido, castigar a alguien o enviar algún mensaje.\n"
		"En esos casos si colaboras conmigo sabré recompensarte merecidamente.'\n");
	AddQuestion(({"tagoras","druida"}),"Dama Darwen dice: 'Mi corazón, mi alma, mi destino está ligados al suyo de forma tan indisoluble como que la noche sigue al día.'\n");
}

init()
{
	::init();
	add_action("cmd_reto", "reto");
}

int cmd_reto(string str)
{
	if (!str)
	{
		write("Dama Darwen facilita retos a aquellos lo suficientemente atrevidos para enfrentarse al peligro.\nEscribe 'reto ayuda' para saber más\n");
		return 1;
	}
	if ("ayuda" == trim(LOWER(str)))
	{
		write(
			"Los retos de Dama Darwen\n"
			"---------------------------------------------------------------------\n"
			"reto nuevo:    Solicitar un nuevo reto (1 mt).\n"
			"reto recordar: Recordar el objetivo del reto (gratis).\n"
			"reto pista:    Pedir una pista para solucionar el reto (2 mt - 4 mt).\n"
			"reto acabar:   Decir a Darwen que has acabado el reto.\n"
			"reto ayuda:    Esta ayuda.\n\n" );
		return 1;
	}
	if ("nuevo" == LOWER(str))
	{
		return quest_new();
	}
	if ("recordar" == LOWER(str))
	{
		return quest_recall();
	}
	if ("pista" == LOWER(str))
	{
		return quest_clue();
	}
	if ("acabar" == LOWER(str))
	{
		return quest_end();
	}
	// El nuevo da el QueryLocate, la primera pista da el QueryIntShort y la segunda pista el QueryIntLong de la qroom

	return 0;
}

int quest_end ()
{
	object watch;
	object qobj;
	string qitem;
	

	watch = present("reloj_darwen", TP);
	if (!watch)
		return notify_fail("Dama Darwen te dice: No recuerdo haberte encomendado ninguna misión.\n", NOTIFY_NOT_VALID);
	if (watch->IsExpired())
	{
		watch->Destroy();
		return notify_fail("Dama Darwen te dice: Es una lástima pero no has completado la misión en el tiempo asignado.\n", NOTIFY_NOT_VALID);
	}
	
	switch (watch->QueryType())
	{
		case QUEST_TYPE_FIND:
			qitem = watch->QueryItemId();
			qobj = present_clone(qitem, TP);
			if (!qobj)
				return notify_fail("Dama Darwen te dice: No veo que hayas encontrado aquello que te encargué.\n", NOTIFY_NOT_VALID);
			if (qobj->QueryPlayer() != TP->QueryRealName())
			{
				// TODO: qobj->Destroy();
				return notify_fail("Dama Darwen te regaña: ¿Cómo osas intentar entregarme algo que no es tuyo?\n", NOTIFY_NOT_VALID);
			}
			write ("Le das "+qobj->QueryArtDetString()+" "+(qobj->QueryIds()[0])+" a Darwen.\n");
			qobj->remove();
			//move_object(qobj, TO);
			write ("¡Gracias "+CAP(TNAME)+"! Tu ayuda será recompensada.\n");
			break;
		case QUEST_TYPE_KILL:
			if (!watch->QueryTargetDone())
				return notify_fail("Dama Darwen te dice: Me temo que no has castigado a quien debías.\n", NOTIFY_NOT_VALID);
			write ("¡Gracias "+CAP(TNAME)+"! Tu ayuda será recompensada.\n");
			break;
		case QUEST_TYPE_TAKE:
			break;
		case QUEST_TYPE_MONEY:
			break;
	}

	// TODO: Dar recompensa
/*
MONEY_LIB->AdjustMoney(TP,MONEY_DEMON->CreateMoney(remaining,
                                                       MONEY_LIB->QueryValuta()));
*/
	switch(random(10))
	{
		case 0..8:
			MONEY_LIB->AdjustMoney(TP, MONEY_DEMON->CreateMoney(35000+random(15000), MONEY_LIB->QueryValuta()));
			write("Dama Darwen te da algo de dinero.\n");
			play_sound(environment(TP), SND_SUCESOS("dinero"));
			break;
		case 9:
			TP->AddXP(level2xp(TP->QueryGuildLevel()+1)-level2xp(TP->QueryGuildLevel()))/10;
			write("Has aumentado tu experiencia.\n");
			break;
	}
/* XP
	TP->AddXP(level2xp(TP->QueryGuildLevel()+1)-level2xp(TP->QueryGuildLevel()))/10;
*/

	// --------------------
	watch->Destroy();

	return 1;
}

int quest_new ()
{
	int chk_ret, dinero;									// El dinero que lleva encima el player
	object watch, qroomobj, qobj;
	string msg;
	int expiry;												// Cuando expira el reto
	string qdesc;											// Descripción del quest;
	int qtype;												// Tipo de quest
	string qroom;											// Room donde ha de ir
	string qitem;											// ID del item
	int nTarget;											// El objetivo

	watch = present("reloj_darwen", TP);
	if (watch)
	{
		if (!watch->IsExpired())
			return notify_fail("Dama Darwen te dice: Pero si todavía estás en mitad de un reto.\n", NOTIFY_NOT_VALID);
		else
		//if (check_expired())
			watch->Destroy();
	}
	else
		if (check_must_wait())
			return notify_fail("Dama Darwen te dice: Has completado un reto hace poco, descansa un rato.\n", NOTIFY_NOT_VALID);

	dinero = QuerySomeonesValue(TP);
	if (dinero < QUEST_COST_NEW)
		return notify_fail("Sopla!!! No tienes suficiente dinero encima para financiarte un nuevo reto.\n", NOTIFY_NOT_VALID);

	// Si llego aquí, no tiene reloj y ya ha pasado el tiempo minimo entre pedir 2 quests.
	// TODO: Aquí genero el quest
	// El quest puede ser:
	// - buscar algo, el questazo de Darwen por ejemplo una joya
	// - matar a alguien
	// - llevarle algo a alguien ?
	// - darle dinero a alguien ?
// De momento solo QUEST_TYPE_FIND
//	qtype = random(QUEST_TYPE_COUNT);
//qtype = QUEST_TYPE_FIND;
qtype=random(2);
// -------------------------------
	expiry = time()+QUEST_INTERTIME;
	watch = clone_object(OTRO("reloj_darwen"));
	watch->SetClue(0);
	watch->SetType(qtype);
	watch->SetExpiry(expiry);
	switch (qtype)
	{
		case QUEST_TYPE_FIND:
			// De momento:
/*
xlpc tell_object(find_object("tagoras"),implode(get_dir("/d/kha-annu/comun/habitacion/annufam/ciudad/*.c", 1),"\n")+"\n");
banco.c
xlpc tell_object(find_object("tagoras"),implode(get_dir("/d/kha-annu/comun/habitacion/annufam/ciudad/*.c", 16),"\n")+"\n");
/d/kha-annu/comun/habitacion/annufam/ciudad/banco.c
*/
			// Seleccionar room donde estará el objeto
			qroom = choose_room();
			// TODO: Comprobar que la room se carga bien.
			watch->SetRoom(qroom);
			// Seleccionar objeto de quest
			qitem = ITEM_DARWEN(QUEST_ITEMS[random(sizeof(QUEST_ITEMS))]);
			watch->SetItemId(qitem);
			qobj = clone_object(qitem);
			// Este el item que sólo vale para este player.
			qobj->SetPlayer(TP->QueryRealName());
			// Para que el item a recuperar sólo valga para este reto.
			qobj->SetExpiry(expiry);
			// TODO: Se tendría que comprobar que esto devuelve ME_OK
			qobj->move(qroom);
			// Descripción del reto
			msg = "Dama Darwen te dice: "+quest_info(watch);
			break;
		case QUEST_TYPE_KILL:
			qroom = choose_room();
			watch->SetRoom(qroom);
			nTarget = random(10);		// TODO: Hay 10 posibles victimas, pero preferiria qu ese pudiera leer de la victima
			watch->SetTarget(nTarget);
			qobj = clone_object(PNJ_DARWEN("victima_darwen"));
			qobj->SetTarget(nTarget);
			qobj->SetPlayer(TP->QueryRealName());
			qobj->SetLevel(TP->QueryGuildLevel()+QUEST_VICTIM_DELTA);
/*
			qobj->SetLevel(TP->QueryLevel()+3);
			qobj->SetGuildLevel(TP->QueryGuildLevel()+3);	// TODO: Cambiar el 3 por un define
*/
			qobj->move(qroom);
			msg = "Dama Darwen te dice: "+quest_info(watch);
			break;
		case QUEST_TYPE_TAKE:
			break;
		case QUEST_TYPE_MONEY:
			break;
		default:
			// Algo ha ido muy mal si hemos llegado aquí
			return notify_fail("Avisa a Tagoras que te han intentado dar un reto que no existe.\n",  NOTIFY_NOT_VALID);;
	}

	if (watch->move(TP) != ME_OK)
	{
		watch->remove();
		// Desmontamos el reto
		switch (qtype)
		{
			case QUEST_TYPE_FIND:
				qobj->remove();
				break;
			case QUEST_TYPE_KILL:
				qobj->remove();
				break;
		}
		return notify_fail("Dama Darwen te dice: Hummm!!! Parece que no puedes acarrear ni un sencillo reloj de arena\nDeberías desprenderte de alguna de tus posesiones primero y volverlo a intentar.\n", NOTIFY_NOT_VALID);
	}
	else
	{
		write (msg+"Dama Darwen te da un reloj de arena que te indica el tiempo que tienes hasta completar el reto.\n");
		PayValue(TP, QUEST_COST_NEW);
		write ("Le das a Dama Darwen una pequeña cantidad de dinero por las molestias originadas.\n");
		play_sound(environment(TP), SND_SUCESOS("dinero"));
	}
		
	TP->Set(P_AUX2, expiry);
	TP->save();
	return 1;
}

public string item_info(string id)
{
	string mi_mis = ((id->Query(P_NUMBER)==NUMERO_SINGULAR)?"mi":"mis");
	string el_la_los_las;

	switch (id->Query(P_NUMBER))
	{
		case NUMERO_SINGULAR:
			el_la_los_las = ((id->QueryGender()==GENERO_FEMENINO)?"la":"el"); break;
		case NUMERO_PLURAL:
			el_la_los_las = ((id->QueryGender()==GENERO_FEMENINO)?"las":"los"); break;
	}

	return "Tu misión será encontrar "+mi_mis+" "+id->QueryIds()[0]+"; que en uno de mis interminables viajes por Simauria debí de perder.\nSi "+el_la_los_las+" encuentras sabré recompensarte como mereces.\n";
}

public string quest_info(object watch)
{
	object qroomobj;
	string qroom;
	string info;
	string id;

	if (!watch)
		return ("Uy, uy, uy!!! Ha habido algún error, comentáselo a mi chico Tagoras si lo ves.\n");

	qroom=watch->QueryRoom();
	if (!(qroomobj = find_object(qroom)))
		qroomobj = load_object(qroom);
	if (!qroomobj)
		return ("Vaya parece que algo nubla mi visión, comentáselo a mi chico Tagoras si lo ves.\n");
	switch (watch->QueryType())
	{
		case QUEST_TYPE_FIND:
			id = watch->QueryItemId();
			info = item_info(id);
			if (qroomobj->QueryLocate())
				info += "Creo que tiene"+((id->Query(P_NUMBER)==NUMERO_PLURAL)?"n":"")+" que estar en "+qroomobj->QueryLocate()+".\n";
			else
				info += "No sé muy bien donde puede"+((id->Query(P_NUMBER)==NUMERO_PLURAL)?"n":"")+" estar.\n";
			break;
        case QUEST_TYPE_KILL:
			info = "Tu misión será encontrar a un peligroso criminal y darle su justo castigo. Si lo haces sabré recompensarte como mereces.\n";
			if (qroomobj->QueryLocate())
				info += "Creo que tiene que estar en "+qroomobj->QueryLocate()+".\n";
			else
				info += "No sé muy bien donde puede estar.\n";
            break;
        case QUEST_TYPE_TAKE:
            break;
        case QUEST_TYPE_MONEY:
            break;
        default:
            // Algo ha ido muy mal si hemos llegado aquí
            return ("Y, ¿cuándo te he dado yo esa misión?, comentáselo a mi chico Tagoras si lo ves.\n");
	}
	switch (watch->QueryClue())
	{
		case 1: // Sólo la primera pista.
			info += "Si me concentro un poco puedo ver que has de buscar "+qroomobj->QueryIntShort()+".\n";
			break;
		case 2: // Las 2 pistas.
			info += "Si me concentro un poco puedo ver que has de buscar "+qroomobj->QueryIntShort()+".\n";
			info += "Si me esfuerzo mucho te puedo decir que lo que tú verías si estuvieses allí sería lo siguiente:\n"+qroomobj->QueryIntLong()+".\n";
			break;
	}

	return info;
}

int quest_complete()
{
	object watch;
	string msg;

	watch = present("reloj_darwen", TP);
	if (!watch)
	{
		write ("Dama Darwen te dice: Vaya!!! Me temo que no tienes ninguna misión encomendada.\n");
		return 1;
	}
}

int quest_recall()
{
	object watch;
	string msg;
	
//write ("TP es :"+CAP(TP->QueryName())+"\n");
	watch = present("reloj_darwen", TP);
	if (!watch) 
		return notify_fail("Dama Darwen te dice: Vaya!!! Me temo que no tienes ninguna misión encomendada.\n", NOTIFY_NOT_VALID);
	 

	msg = "Dama Darwen te regaña: ¡Hay que ver lo desmemoriad"+AO+" que eres!. Bueno, te recordaré la misión que te encomendé.\n";
	msg += quest_info(watch);
	write(msg);
	return 1;
}

int quest_clue()
{
	object watch, qroomobj;
	string qroom;
	int dinero;

	watch = present("reloj_darwen", TP);
	if (!watch)
		return notify_fail("Dama Darwen te dice: Vaya!!! Me temo que no tienes ninguna misión encomendada.\n", NOTIFY_NOT_VALID);
	
	dinero = QuerySomeonesValue(TP);
	qroom=watch->QueryRoom();
	if (!(qroomobj = find_object(qroom)))
		qroomobj = load_object(qroom);
	switch (watch->QueryClue())
	{
		case 0:
			if (dinero < QUEST_COST_CLUE1)
				write("Dama Darwen te dice: Sopla!!! No tienes suficiente dinero encima para pagar por una pista.\n");
			else
			{
				write("Dama Darwen te dice: Lo que buscas está "+qroomobj->QueryIntShort()+".\n");
				PayValue(TP, QUEST_COST_CLUE1);
				write ("Le das a Dama Darwen una modesta cantidad de dinero por las molestias originadas.\n");
				play_sound(environment(TP), SND_SUCESOS("dinero"));
				watch->SetClue(1);
			}
			break;
		case 1:
			if (dinero < QUEST_COST_CLUE2)
				write("Dama Darwen te dice: Sopla!!! No tienes suficiente dinero encima para pagar por una segunda pista.\n");
			else
			{
				write("Dama Darwen se concentra y te dice: Veo que tu destino está en un lugar que sólo puedo describir con las siguientes palabras:\n"+qroomobj->QueryIntLong()+".\n");
				PayValue(TP, QUEST_COST_CLUE2);
				write ("Le das a Dama Darwen una generosa cantidad de dinero por las molestias originadas.\n");
				play_sound(environment(TP), SND_SUCESOS("dinero"));
				watch->SetClue(2);
			}
			break;
		default:
			write("Dama Darwen te dice: Lo siento "+CAP(TNAME)+" pero ya no tengo más información que darte.\n");
	}

	return 1;
}

// Para evitar que un player este haciendo demasiados retos seguidos
int check_must_wait()
{
	int limit;
	
	limit = TP->Query(P_AUX2) || 0;
	return (limit > time());
}

// Comprobar si ha expirado el reto
int check_expired()
{
	int limit;

	limit = TP->Query(P_AUX2) || 0;
	return (limit < time());
}

public void auto_end_item (object obj, object player)
{
	obj->move(player, M_SILENT);
	player->command_me("reto acabar");
}

// Autoacabar cuando se le da el item a Darwen
public void notify_enter(mixed from, int method, mixed extra)
{
	object obj = PO;
	object player = to_object(from);

	if (!player || !obj || method != M_GIVE || (-1 == member(QUEST_ITEMS, obj->QueryIds()[(sizeof(obj->QueryIds())-1)])))
		return;

	// Se lo devolvemos al player y le forzamos a hacer reto acabar
	call_out("auto_end_item", 1, obj, player);
}
