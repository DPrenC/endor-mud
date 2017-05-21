/* Este es un demonio que debería ser HECHICERO, pero de momento es CONJURADOR. Su nivel es nivel maximo de los jugadores conectados + n (parámetro). Mínimo 110

El demonio es un spellmonster de nivel 110 minimo pero es 15 niveles por encima del nivel maximo que hay de jugador, es decir que si el nivel maximo del jugador mas alto conectado está por debajo de 100, el nivel del bicho es 110 y si hay algun jugador de nivel mayo a 100 sera su nivel + n (paráemtro).
Cada cierto tiempo el demonio busca un a victima para asesinar: Sólo jugadores (de nivel superior a 5 -parámetro-) y que haya 3 -parámetro- o más. Si no encuentra vuelve a buscar en 5 minutos -parámetro-. Si lo encuentra le envia los asesinos y espera 30 minutos -parámetro-  para volver a buscar.

Los asesinos ahora son unos drows (elfos oscuros con equipo y nivel):
Estos son el el nivel del jugador mas un 1 nivel por cada 20 -paráemtro- del jugador hasta un maximo de 3 niveles más -paráemtro- y se envian 2 asesinos -parámetro-.

Nota: Todos los paráemtros se pueden cambiar con el rak-nal-turi ya cargado en el mud.
*/


#include "path.h"
#include <properties.h>
#include <guild.h>						// GC_CONJURADOR
#include <colours.h>					// Para quitar los colores del terminal en catch_tell
#include <moving.h>						// M_SILENT
#include <spellmonster.h>
#include <damage.h>						// DT_MAGIC
#include <sounds.h>						// DT_MAGIC
#include "/secure/wizlevels.h"			// IS_BEGINNER

#define RAK_VER_MICRO			4
#define RAK_LEVEL_MIN			110		// Mínimo nivel de Rak-nal-turi
#define RAK_LEVEL_DELTA			30		// Diferencia de nivel mínima entre el atacante y Rak-nal-turi
#define RAK_CHOOSE_TIME			3600	// Cada este tiempo busca una victima
#define RAK_CHOOSE_RETRY		300		// Si no hay victimas volveremos a probar en este tiempo
#define RAK_CHOOSE_MIN_PJS		3		// Tiene que haber este número mínimo de jugadores para que Rak-nal-turi ataque
#define RAK_CHOOSE_MIN_LEVEL	5		// El PJ ha de tener mínimo este nivel
#define DROW_NUMBER				2		// Número de asesinos a enviar
#define DROW_LEVEL_MAXDELTA		3		// Diferencia de nivel máxima entre los drows y la victima
#define DROW_LEVEL_PER_LEVELS	20		// El drow tendrá un nivel más que la victima por cada tantos niveles de la victima

inherit SPELLMONSTER;

private object pTagoras;		// Yo

private int		rak_lvl_d = RAK_LEVEL_DELTA;
private int		rak_ch_time = RAK_CHOOSE_TIME;
private int		rak_ch_retry = RAK_CHOOSE_RETRY;
private int		rak_ch_minp = RAK_CHOOSE_MIN_PJS;
private int		rak_ch_minl = RAK_CHOOSE_MIN_LEVEL;
private int		drow_n = DROW_NUMBER;
private int 	drow_lvl_maxd = DROW_LEVEL_MAXDELTA;
private int		drow_lvl_x_lvls = DROW_LEVEL_PER_LEVELS;

private void	RakChannel(string ch,string msg,int emote);
public void		RakChoose(object wiz);
public mapping	RakDrainLife(mapping sp, object *vic);
public int		RakDeathFinger();
public void		RakExec(object wiz, string comando);
private void	RakHelp(object wiz);
private void	RakKill(object wiz, string objetivo);
private void	RakSet(object wiz, string name, int value);
private void	RakStatus(object wiz);

public void dialogo()
{
	object * players;

	players = filter(all_inventory(environment(TO)), (:$1->QueryIsPlayer() && !$1->QueryInvis() && !query_wiz_level($1):));
	if (sizeof(players))
		tell_room (environment(TO), "Rak-nal-turi dice: '¿Quieres morir " + CAP(players[random(sizeof(players))]->QueryRealName()) + "?'\n");
	else
		tell_room (environment(TO), "Rak-nal-turi dice: '¿Quieres morir, saco de carne?'\n");
}

create()
{
	::create();
	string dest;
	SetStandard ( "rak-nal-turi", "demonio", ([GC_CONJURADOR:RAK_LEVEL_MIN]), GENDER_MALE);
	AddId (({"rak"}));
	SetShort("Rak-nal-turi el Demonio");
	SetLong("Rak-nal-turi el Demonio es el servidor más fiel de Sharanna, Diosa de la Muerte. En base a esa servidumbre se dedica a dar caza a todo aquel que se encuentra. Pero como es un demonio muy poderoso cree que es indigno que él se manche sus manos con la sangre de tan birriosas criaturas. Es por ello que recurre a los asesinos Drow (elfos oscuros) a los que lanza en contra de su presa.\n" 
		"En el aspecto físico es lo que se puede esperar al hablar de un demonio, es decir, un ser horrible de color rojo con sus cuernos, poderosas garras y una larga cola. En su caso además se puede observar que los eones han pasado por sus carnes. Así que se podría decir que Rak-nal-turi es anciano, si el concepto de vejez se puede aplicar a los demonios. No obstante, eso no ha mellado su poder físico, si no al contrario. Parece que su propia piel ha endurecido y dificilmente un arma no mágica pueda llegar a herirle.\n"
		"En el campo mágico el pasar del tiempo le ha proporcionado mayores conocimientos, y pocos seres mágicos pueden llegar a ser rival para su talento en el dominio de las artes oscuras. Teniendo esto en cuenta, sólamente un grupo escogido con diferentes habilidades luchando conjuntamente podrían llegar a liquidarlo. Eso o algún wizard de inmenso poder.\n"
		"Y aún así, siendo el siervo más leal de Sharanna, Diosa de la Muerte, muy posiblemente, vuelva de entre los muertos alimentado con el poder de la mismísima Sharanna, esto es con mayor poder del que puedas llegar a imaginar.\n" ); 
	SetAlign(-1000);
	SetWeight(120000);			// 120 Kg
	SetSmell("Huele a muerte y putrefacción.\n");
	SetWhimpy(0);
	AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["mithril":random(9)+1,"platino":random(3)+1])]));
	SetAggressive(2);
	SetAttackOwnRace(1000);
	SetAttackChance(1000);
	enable_commands();
	InitChats(5,({"Rak-nal-turi dice: 'Yo soy Rak-nal-turi, el servidor más fiel de Sharanna, Diosa de la Muerte.'\n",
					"Rak-nal-turi dice: 'Matar es mi único propósito de existir.'\n",
					//"Rak-nal-turi dice: '¿Quieres morir " + capitalize(TP->QueryRealName()) + "?'\n",
					//"Rak-nal-turi dice: '¿Quieres morir, saco de carne?'\n",
					SF(dialogo),
					"Rak-nal-turi dice: 'Mi único propósito es matar a todo ser vivo.'\n",
					"Rak-nal-turi reza: 'Oh Sharanna!!! Dáme poder para servirte mejor.'\n",
					"Rak-nal-turi dice: 'Pocos han conseguido matarme y ninguno ha conseguido destruirme totalmente.'\n"}));
	InitAChats(10,({"Rak-nal-turi dice: '¿Cómo osas atacar a Rak-nal-turi, el siervo de Sharanna?'\n",
					"Rak-nal-turi dice: 'MUEEEEERE!!!!!'\n"}));
	
	AddQuestion(({"muerte","sharanna","diosa de la muerte"}), "Rak-nal-turi dice: 'Sharanna es aquella a la que sirvo y a la que ofrezco todas mis víctimas en sacrificio. Ella me guía y me hace más fuerte.'\n");
	AddQuestion(({"tagoras","druida"}),"Rak-nal-turi dice: 'Aaaaargh!!! Ese druida apestoso es uno de los pocos que han conseguido darme muerte. Cosa futil por otra parte ya que mi señora se encargó de devolverme al mundo para seguir mi mortífera misión. Sí, lo conozco bien, un poderoso druida es Tagoras, el último de una estirpe ya olvidada de la que esos guardachopos abrazaárboles son simplemente una sombra carente de poder.'\n");
	AddQuestion(({"drow","drows"}),"Rak-nal-turi dice: 'Aaahhh!!! Sí. Los drows. Me son muy útiles como agentes para recoger los regalos que le hago a mi señora. Son una rama escindida de los elfos-oscuros a los que he convencido para que adoren a Sharanna en luegar de a su reina. Muy útiles y totalmente prescindibles. Sí.'\n" );
	// TODO: crear un cayado negro
	AddItem(ARMA("cayado_rak"),REFRESH_REMOVE, SF(wieldme));
	AddItem(PROT("grebas_rak"),REFRESH_REMOVE, SF(wearme));
	AddItem(PROT("coraza_rak"),REFRESH_REMOVE, SF(wearme));
	AddItem(PROT("corona_rak"),REFRESH_REMOVE, SF(wearme));
	AddItem(PROT("guanteletes_rak"),REFRESH_REMOVE, SF(wearme));
	AddItem("/obj/sunglasses", REFRESH_REMOVE, SF(wearme));			// Para que pueda ver.

	// Spells
	// Copiado de /d/lad-laurelin/comun/pnj/tiin/lago/Radhul.c
	AddSpell("RakDrainLife",
			([
				S_CHANCE:70,
				S_COMBAT_DELAY:1,
				S_DELAY:2,
				S_SIMULT:1,
				S_VICTIMS:1,
				S_DAMTYPE:DT_MAGIC,
				S_MINDAM:10,
				S_MAXDAM:20,
				S_FUN:SF(RakDrainLife),
				S_GLOBAL_ENVMSG:(TC_RED"Los ojos de Rak-nal-turi se vuelven rojos.\n"TC_NORMAL),
				S_ENVMSG:([
						MSG_NORMAL:
							({"Rak-nal-turi alza su garra y señala a @@VicName@@ y ves como este palidece.\n", "@@VicName@@ siente como se le escapa la vida.\n" }),
						MSG_DEAD:
							({"@@VicName@@ lanza su último estertor y fallece.\n", "Oyes como el cuerpo inerte de @@VicName@@ cae al suelo.\n" }),
						]),
				S_VICMSG:([
						MSG_NORMAL:
							({"Rak-nal-turi alza su garra y te señala. Notas como si la vida se te escapara.\n" }),
						MSG_DEAD:
							({"Exhalas tu útlimo suspiro y falleces en medio de grandes dolores.\n" }),
						]),
			])
		);
	// Copiado de /d/lad-laurelin/comun/pnj/tiin/lago/lich.c
	AddSpell("RakDeathFinger",
			([
				S_SP:20,
				S_CHANCE:30,
				S_COMBAT_DELAY:1,
				S_DELAY:30,
				S_SIMULT:0,
				S_VICTIMS:1,
				S_DAMTYPE:MT_PSYCHO,
				S_FUN:SF(RakDeathFinger),
				S_GLOBAL_ENVMSG:(TC_GREEN"\n Rak-nal-turi lanza su DEDO MORTAL.\n"TC_NORMAL),
				S_VICMSG:([
						MSG_NORMAL:
							("Rak-nal-turi te señala y de su dedo sale un rayo verde que te inflinge mucho dolor...\n"),
						MSG_DEAD:
							("Rak-nal-turi te señala y de su dedo sale un rayo verde que te fulmina..\n"
						)]),
			])
		);

//	"/obj/chmaster"->SendEmote("mud", "Rak-nal-turi entra al mundo", SND_SUCESOS("entrar_mud"));
	// Movernos a algún sitio
/*
	switch ( random(10) )
	{
		case 0..9:
			dest="/d/goldhai/comun/habitacion/glucksfall/piso2_"+(random(31)+1);
			if (find_object("tagoras")) dtell("tagoras",sprintf("Rak-nal-turi está en %s\n",dest));
			move(dest,M_SILENT);
			break;
	}
*/
	call_out ( "RakChoose", 5, 0 );
}

public void create_clone()
{
	::create_clone();
	"/obj/chmaster"->SendEmote("mud", "Rak-nal-turi entra al mundo", SND_SUCESOS("entrar_mud"));
}

// Ajusta el nivel de Rak a como mínimo 10 por encima del máximo de nuestros enemigos
public void Attack()
{
	int i,victim_level;
	object *enemigos;
	enemigos=QueryEnemies()||({});
	if (sizeof(enemigos))
	{
		victim_level=max(map(enemigos, (:$1->QueryGuildLevel():)));
		if (QueryLevel()<(victim_level+rak_lvl_d))
			SetLevel(rak_lvl_d+victim_level);
	}
	return ::Attack();
}

// Envia un emote de Die como si fuera un jugador
public varargs void Die(mixed silent)
{
	object attacker_ob;
	string killer;

	attacker_ob = QueryKiller();
	if (attacker_ob)
		killer=capitalize(attacker_ob->QueryRealName());
	else
		killer="Alguien";

	//RakChannel ( "info", "Rak-nal-turi murió a manos de "+killer+".", 1);
	"/obj/chmaster"->SendEmote("info", "Rak-nal-turi murió a manos de "+killer+".", SND_SUCESOS("muerte_jugador"));
	::Die(silent);
}

// Copiado de /obj/chmaster.c
private string _build_str(object to, string from, string ch, string what, int emote)
{
	string msg;
	string color, txtcolor;
	string tmp;

	color = TC_KEY + capitalize(ch) + "Who" + TC_KEY;
	txtcolor = TC_KEY + capitalize(ch) + "Msg" + TC_KEY;

	msg = "";
	if (!to->QueryChLine())
		msg = "\n";
	msg += color + "[";
	if (emote)
	{
		switch (ch)
		{
			case "info":
				msg += capitalize(ch) + ": " + TC_NORMAL + txtcolor + what + TC_NORMAL + color + "]" + TC_NORMAL + "\n";
				break;
		}
	}
	else
	{
		switch (ch)
		{
			case "jugadores":
				msg += TC_NORMAL + from;
				if (IS_LEARNER(to))
					msg += color + ":" + ch + TC_NORMAL;
				msg += color + "] " + TC_NORMAL + txtcolor + what + TC_NORMAL + "\n";
				break;
		}
	}
	return msg;
}

private void RakChannel(string ch,string msg,int emote)
{
	object *u;
	int s;

	s=sizeof(u=users());
	while (s--)
	{
		if (!IS_BEGINNER(u[s]))
		{
			tell_object(u[s], _build_str(u[s], "Rak-nal-turi", ch, msg, emote));
			if (strstr(LOWER(msg), LOWER(u[s]->QueryRealName())) != -1)
				play_sound(u[s], SND_CANALES("tunombre"));
			else
				play_sound(u[s], SND_CANALES("canal_jugadores"));
		}
	}
}

public void RakChoose(object wiz)
{
	object *usuarios, *jugadores;
	int i;
	mixed callouts;
	string * choose_msg;

	choose_msg = ({ "Sigo tus preceptos Sharanna, Diosa de la Muerte. Busco un sacrificio que ofrecerte.",
				"He de encontrar un regalo apropiado para mi señora Sharanna.",
				"Sniiiiif!!!! Capto el olor de seres vivos. Vivos por poco tiempo.",
				"¿Quien? ¿Quien de vosotros, sacos de carne, es suficientemente valioso para mi ama?",
				"Este no..., este tampoco..., este ni que lo suplique. Vaya, tendré que esperar." });
	if ( !clonep() ) return;
	RakChannel("jugadores", choose_msg[random(sizeof(choose_msg))],0);

	jugadores = filter(filter(users(), (:!query_wiz_level($1):)), (:$1->QueryGuildLevel()>=rak_ch_minl:));
	if (find_object("tagoras")) dtell("tagoras",sprintf("Número de jugadores %d\n",sizeof(jugadores)));
	if (wiz)
		tell_object(wiz, sprintf("Número de jugadores %d\n",sizeof(jugadores)));
	//while (remove_call_out("RakChoose") != -1) /* continue */ ;
	if ( sizeof(jugadores) >= rak_ch_minp )
	{
		RakKill (0, jugadores[random(sizeof(jugadores))]->QueryRealName());
		if ( !wiz )
			call_out("RakChoose", rak_ch_time, 0);		// Si ha podido escoger a la media hora
	}
	else
	{
		if ( !wiz )
			call_out("RakChoose", rak_ch_retry, 0);		// Si no ha podido esocger a los 5 minutos
	}
/*
if (find_object("tagoras")) dtell("tagoras",sprintf("Llamadas pendientes %d\n", sizeof(call_out_info())));
callouts=call_out_info();
for (i=0; i<sizeof(callouts);i++)
	if (find_object("tagoras")) dtell("tagoras",sprintf("Llamada %d -> %s\n", i, callouts[i][1]));
*/
}

// Copiado de /d/lad-laurelin/comun/pnj/tiin/lago/Radhul.c
public mapping RakDrainLife(mapping sp, object *vic)
{
	object *en,ene,bicho;
	int danyo;

	bicho=TO;
	en=QueryEnemies()||({});
	if(!sizeof(en)) return 0;
	ene=en[random(sizeof(en))];
	if (!ene->QueryIsNpc() && !ene->QueryIsPet())
	{
		danyo=25+random(15);
		ene->AddHp(-danyo);
		bicho->AddHp(danyo);
		vic=({ene});
	}
	return sp;
}

// Copiado de /d/lad-laurelin/comun/pnj/tiin/lago/lich.c
public int RakDeathFinger()
{
	object *en,ene,bicho;
	int danyo;
	int resist;
	mapping hechizos;
	bicho=TO;
	hechizos=bicho->QuerySpells();
	AddSP(-(int)(hechizos["RakDeathFinger"][S_SP]));
	en=QueryEnemies()||({});
	ene=en[random(sizeof(en))];
	resist=(ene->Resistance(12)/100);
	if (ene->Resistance(12)>(20+random(10)))
		return 0; //se salva si tiene la resistencia necesaria
	else {
		if (ene->QueryHP()<50) {
			ene->SetHP(-1);
			tell_object(ene,hechizos["RakDeathFinger"][S_VICMSG][MSG_DEAD]);
			tell_room(environment(),hechizos["RakDeathFinger"][S_GLOBAL_ENVMSG]);
		}
		if (ene->QueryHP()>=120 && ene->QueryHP()<200) {
			danyo=(50+random(50));
			ene->SetHP(danyo-(danyo*resist));
			tell_object(ene,hechizos["RakDeathFinger"][S_VICMSG][MSG_NORMAL]);
			tell_room(environment(),hechizos["RakDeathFinger"][S_GLOBAL_ENVMSG]);
		}
		else
		{
			tell_object(ene,"Rak-nal-turi conjura un rayo verde que no te afecta.\n");
			tell_room(environment(),hechizos["RakDeathFinger"][S_GLOBAL_ENVMSG]);
		}
	}
	return 0;
}

public void RakExec(object wiz, string comando)
{
	string accion;
	mixed extra;
	string name;									// Para el "set"
	int value;										// Para el "set"
	int n;

	comando = trim(comando);
	accion = explode(comando, " ")[0];
	if ((n = strstr(comando, " ")) >= 0) extra = comando[n+1..];
	switch(accion)
	{
		case "ayuda":
			RakHelp(wiz);
			return;
		case "estado":
			RakStatus(wiz);
			return;
		case "escoge":
			RakChoose(wiz);
			return;
		case "matar":
			RakKill(wiz, extra);
			return;
		case "set":
			if (sscanf(extra, "%s %d", name, value) == 2)
				RakSet(wiz, name, value);
			return;
	}
	tell_object(wiz, "\nRak-nal-turi te dice: No entiendo qué quieres decir con: "+comando+"\n");
	return;
}

private void RakHelp(object wiz)
{
	tell_object(wiz, sprintf( "Rak-nal-turi v0.0."+RAK_VER_MICRO+" - Help\n\
--------------------------------------------------------------------------\n\
Todos los comandos se da de viva voz anteponiendo Rak{espacio} al comando.\n\
--------------------------------------------------------------------------\n\
ayuda                    Esta ayuda.\n\
estado                   Saca el estado del NPC.\n\
escoge                   Lanza un ciclo de selección de objetivo.\n\
matar <objetivo>         Envia drows a matar al objetivo.\n\
set <name> <value>       Pone el valor en la variable.\n\
\n"));
}

private void RakKill(object wiz, string objetivo)
{
	object victim, killer;
	int i, victim_level;

	if (!sizeof(objetivo)) return;
	victim=find_object(objetivo);
	if (!victim) return;
	RakChannel("jugadores","Muerte a "+capitalize(objetivo)+"!!! Aniquiladl"+((GENDER_FEMALE==victim->QueryGender())?"a":"o")+" mis fieles drows.\n",0);
	if (wiz)
		tell_object(wiz ,sprintf("Rak-nal-turi te dice: Voy a matar a %s\n",objetivo));
	if ( victim )
	{
		victim_level=victim->QueryGuildLevel();
		for(i=0;i<drow_n;i++)
		{
			killer=clone_object(PNJ("drow"));
			// Jugadores altos
			if (victim_level>=(drow_lvl_maxd*drow_lvl_x_lvls))
				killer->SetLevel(victim_level+drow_lvl_maxd);
			// Jugadores intermedios
			if (victim_level<(drow_lvl_maxd*drow_lvl_x_lvls))
				killer->SetLevel(victim_level+(victim_level/drow_lvl_x_lvls));
			// Jugadors bajos
			if (victim_level<drow_lvl_x_lvls)
				killer->SetLevel(victim_level+1);
			// A los conjuradores se los dejamos al mismo nivel, de momento
			// TODO: Esto hay que probarlo
			if ("conjurador" == victim->QueryGuild())
				killer->SetLevel(victim_level);
			// Tanto dinero en oro como nivel tiene la victima.
			killer->AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["platino":floor(victim_level/10)+1,"oro":(victim_level-10*(floor(victim_level/10))+1)])]));
			killer->AddEnemy(victim);
			//killer->move(environment(victim), M_SILENT);
			// TODO: Aquí habría que mirar si el move devuelve ME_OK
			killer->move(environment(victim), M_TELEPORT);
			killer->Kill(victim);
		}
	}
}

private void RakSet(object wiz, string name, int value)
{
	int ok = 0;

	if (-1 != member(({"rak_lvl_d", "rak_ch_time", "rak_ch_retry", "rak_ch_minp", "rak_ch_minl", "drow_n", "drow_lvl_maxd", "drow_lvl_x_lvls"}), name))
		ok = 1;
	if ("rak_lvl_d" == name)
		rak_lvl_d = value;
	if ("rak_ch_time" == name)
		rak_ch_time = value;
	if ("rak_ch_retry" == name)
		rak_ch_retry = value;
	if ("rak_ch_minp" == name)
		rak_ch_minp = value;
	if ("rak_ch_minl" == name)
		rak_ch_minl = value;
	if ("drow_n" == name)
		drow_n = value;
	if ("drow_lvl_maxd" == name)
		drow_lvl_maxd = value;
	if ("drow_lvl_x_lvls" == name)
		drow_lvl_x_lvls = value;

	tell_object(wiz, sprintf("Rak-nal-turi te dice: He asignado a %s el valor %d.\n", name, value));
}

private void RakStatus(object wiz)
{
	tell_object(wiz, sprintf("Rak-nal-turi v0.0."+RAK_VER_MICRO+" - Status\n\
--------------------------------------------------------------------------\n\
Rak-nal-turi:\n\
Diferencia de nivel con jugadores (rak_lvl_d):        %d\n\
Tiempo después de encontrar un jugador (rak_ch_time): %d\n\
Tiempo entre dos búsquedas (rak_ch_retry):            %d\n\
Mínimo número de jugadores (rak_ch_minp):             %d\n\
Mínimo nivel de los jugadores (rak_ch_minl):          %d\n\
Drows:\n\
Número de drows a enviar (drow_n):                    %d\n\
Máxima diferencia de nivel (drow_lvl_maxd):           %d\n\
Escala de nivel (drow_lvl_x_lvls):                    %d\n\
\n", rak_lvl_d, rak_ch_time, rak_ch_retry, rak_ch_minp, rak_ch_minl, drow_n, drow_lvl_maxd, drow_lvl_x_lvls ));
}

public void catch_tell(string str)
{
	string objetivo;
	string var_name;
	int var_value;

	str=LOWER(terminal_colour(str, NO_COLOURS));

	//if (find_object("tagoras")) dtell("tagoras",sprintf("RakKill: str %s\n",str));

	if ((str == "tagoras dice: 'rak ayuda'\n") || (str == "tagoras dice: ' rak ayuda'\n"))
	{
		RakHelp(find_object("tagoras"));
		return 0;
	}
	if ((str == "tagoras dice: 'rak escoge'\n") || (str == "tagoras dice: ' rak escoge'\n"))
	{
		RakChoose(find_object("tagoras"));
		return 0;
	}
	if ((str == "tagoras dice: 'rak estado'\n") || (str == "tagoras dice: ' rak estado'\n"))
	{
		RakStatus(find_object("tagoras"));
		return 0;
	}
	if (sscanf(str, "tagoras dice: 'rak matar %s'\n", objetivo) == 1)
		RakKill(find_object("tagoras"), objetivo);
	if (sscanf(str, "tagoras dice: ' rak matar %s'\n", objetivo) == 1)
	{
		RakKill(find_object("tagoras"), objetivo);
		return 0;
	}
	if (sscanf(str, "tagoras dice: ' rak set %s %d'\n", var_name, var_value) == 2)
	{
		if (find_object("tagoras")) dtell("tagoras",sprintf("Rak: var_name[%s] - var_value[%d]\n", var_name, var_value));
		RakSet(find_object("tagoras"), var_name, var_value);
		return 0;
	}
}
