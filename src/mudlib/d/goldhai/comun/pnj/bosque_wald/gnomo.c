/*********************************************************/
//		"Ychnglldyl"
//	Ychnglldyl el implacable, el gnomo más fiero de toda simauria
//	es un archimago invulnerable a paralisis, echadle un ojo
//	al aura de llamas ;)
//		11-12-01: Kodex-> creación
//		10-01-02: Kodex-> última modificación
//	*Ahora quita la maldición el mismo, he suprimido
//	 su tienda, era innecesaria.
/*********************************************************/



#include <spellmonster.h>
#include <properties.h>
#include "./path.h"
#include <moving.h>
#include <money.h>
#include <combat.h>
#include <colours.h>
#include <gremios.h>
#include <sounds.h>
inherit SPELLMONSTER;

/*la abusiva cantidad de 400 mithriles!!! yo no he tenido nada que ver xDD*/
#define COSTE 2000000

int aura = 0;

public status check_sp();
public int magia();

quitar_cmd(string strg)
{
	object ob,dinero,dinero_jugador;
	string str;
	if (sscanf(strg,"maldición a %s", str) == 1 || sscanf(strg,"maldicion a %s", str) == 1 )
	{
		if (!str) return notify_fail("Ychnglldyl te dice: '¿A qué le quieres quitar la maldición?'\n"),0;
		ob = present(str,TP);
		if (!ob) return notify_fail("Ychnglldyl te dice: 'No tienes " + str + " para que le quite la maldición.'\n"),0;
		if (!(ob->QueryMaldita())) return notify_fail("Ychnglldyl te dice: 'Ese objeto no está maldito.'\n"),0;

		dinero_jugador="/lib/money"->QuerySomeonesValue(TP);
		if(dinero_jugador < COSTE)
   		{
    		return notify_fail("Ychnglldyl te dice: 'Por menos de 400 monedas de mithril "
    		"no utilizaré mi magia.'\n");
   		}
		dinero="/lib/money"->PayValue2(TP,COSTE);
		if (intp(dinero))
        		write("Pagas "+dinero+".\n");
   		else
           		write("Pagas "+dinero[0]+(dinero[1] ? " y recibes "+dinero[1] : "")+".\n");
           	tell_room(environment(TO),"Ychnglldyl pronuncia unas palabras místicas...\n"
           	"...Ychnglldyl mueve las manos y ves la energía recorriendo el ambiente...\n");
		ob->SetMaldita(0);
		return 1;
	}


}

create() {
    ::create();
    SetStandard("Ychnglldyl","gnomo",([GC_MAGO: 50]),GENERO_MASCULINO);
    SetShort("Ychnglldyl el brujo");
    SetLong("Ychnglldyl es un gnomo, su tamaño no dice gran cosa de él,"
    " pero por el brillo de sus ojos y las chispas eléctricas que saltan "
    "de vez en cuando entre sus dedos puedes intuir que Ychnglldyl no es un "
    "gnomo corriente. Puede ser peligroso enfrentarse con él, no se puede deducir "
    "de lo que realmente es capaz esta criatura.\n");
    SetIds(({"ychnglldyl","ychnglldyl el brujo","brujo"}));
    Set(P_CANT_LURE,1);
    SetAggressive(0);
    SetAC(35);
    SetSP(1000);
    SetMaxHP(700);
    SetHP(700);
    AddQuestion(({"scyla","maldición","maldicion","Scyla"}),
    "Ychnglldyl dice: 'Yo puedo librar a la pobre "
    "Scyla de su maldición. ¡¡Pero te costará caro!!'\n"
    "Ychnglldyl sonríe mientras te señala un letrero.\n");
    SetSpellChance(100);
    AddSpell("conjuros",
      ([
      S_CHECKFUN:SF(check_sp),
      S_FUN:SF(magia), S_SP:2,
      S_CHANCE:95,
      S_VICTIMS:1,
      ]));
}

aviso() {
    write("Ychnglldyl mueve la cabeza demostrándote que tu intento de inmovilizarle fué inútil.\n");
}

mixed SetCombatDelay(int time , string s) {
	call_out("aviso",1);
	return 1;
}

public status check_sp() {
    return QuerySP()>0;
}

quitar_aura() {
    say(TC_YELLOW+"El aura de llamas desaparece.\n"+TC_NORMAL);
    aura = 0;
}

public int magia()
{
	int pv,i;
    object *en,ene,bicho;

    bicho=TO;
    en=QueryEnemies()||({});
    if(!sizeof(en)) return 0;
    ene=en[random(sizeof(en))];
	switch (random(10))
	{
		case 0 .. 2:/*bola de fuego*/
				bicho->AddSP(-20);
				pv=d20();
				play_sound(environment(),SND_MAGIA("bolafuego"));
				tell_room(environment(),TC_RED+"Ychnglldyl enciende su mirada,"
           			" de repente de entre las nubes aparece una gran bola de fuego "
           			"que impacta sobre todos sus adversarios.\n"+TC_NORMAL);

           			for(i=0;i<sizeof(en);i++)
 					{
   					en[i]->Defend(pv, TD_CALOR, DEFEND_SPELL);
   					}
           			break;
		case 3 .. 5:/*relámpagos*/ //de 1 a 30 a un blanco
           			bicho->AddSP(-25);
           			pv=d20(2);
           			tell_room(environment(),TC_CYAN+"Ychnglldyl lanza varios relámpagos"
           			" por la punta de sus dedos "
           			"electrocutando a "+ene->QueryName()+".\n"+TC_NORMAL,(({ene})));
           			tell_object(ene,TC_CYAN+"Ychnglldyl lanza varios relámpagos por "
           			"la punta de sus dedos electrocutándote.\n"+TC_NORMAL);
           			ene->Defend(pv, TD_ELECTRICIDAD, DEFEND_SPELL);
           			return 0; break;

		case 6 .. 7:/*aura de llamas*/ //durante 14 segundos este aura dañará a todo el que le acierte
				bicho->AddSP(-90);
				say(TC_BOLD+TC_RED+"¡¡¡Ychnglldyl conjura un aura de"
				" llamas a su alrededor!!!.\n"+TC_NORMAL);
				aura = 1;
				call_out("quitar_aura",14);break;

		case 8 .. 9:/*elemental*/ //el típico elemental de fuego
				bicho->AddSP(-60);
				bicho = clone_object(PNJ("bosque_wald/elemental"));
				bicho-> move(environment(TO));
				tell_room(environment(),TC_YELLOW+"Ychnglldyl comienza a girar"
				" sobre sí mismo. De repente se para en seco y alza las "
				"manos hacia el cielo. Un elemental "
				"aparece a su lado.\n"+TC_NORMAL);
 				for(i=0;i<sizeof(en);i++)
 					{
   					en[i]->Kill(bicho);
 					}
 				break;
		default: break;
	}
return 0;
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
    if (aura) {
	    tell_object(TP, TC_RED+"El aura de llamas te causa daño.\n"+TC_NORMAL);
	    say(TC_RED+"El aura de llamas causa daño a "
	     + capitalize(TP->QueryRealName()) + ".\n"+TC_NORMAL,TP);
	    TP->Defend(random(20)+1,DT_FIRE,DEFEND_NOMSG);
	}
	return ::DoDamage ( damage,  type,  gentle,  xtras);
}

saludo() {
    tell_object(TP,"Ychnglldyl dice: 'Hola extranjero, ¿qué te ha traido "
    "hasta mí? ¿Necesitas de mi sabiduría?\n");
}

init() {
    ::init();
    call_out("saludo",1);
    add_action("quitar_cmd","quitar");
}
