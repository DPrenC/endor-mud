/*
DESCRIPCION    : Duende del manantial (sirve para resolver dudas
			sobre muertos vivientes y para restringir el acceso)
FICHERO        : /d/lad-laurelin/pnj/lago/monjef.c
CREACION       : Junio [Alura]
*/

#include "path.h"
#include <spellmonster.h>
#include <magia.h>
#include <colours.h>
#include <properties.h>

inherit "obj/monster/spellmonster";

int car;
object *en,ene;


int chequeo_cs(){
  en=QueryEnemies()||({});
  ene=en[random(sizeof(en))];
  if (ene->QueryAlign()<0) return 1; else return 0;
}

/* int c_s(){
 int resist,danyo;
 resist=ene->Resistance(35);
 danyo=10+random(25);
 ene->AddHP(-(danyo -(int)((danyo*resist)/100)));
 return 1;
} */

create() {
  ::create();
  car=random(2)+26;
  SetStandard("Vexsohuydsets","duende",random(2)+10,GENDER_MALE);
  SetShort("un duende");
  SetLong("Vexsohuydsets es el ser que se encargaba de cuidar este hermoso lugar cuando el mal lo abordó."
	" No sale de este sitio, pues tiene miedo de los muertos vivientes.. aunque él nunca te lo confesará.\n");
  SetIds(({"duende","Vexsohuydsets"}));
  SetAlign(200);
  SetHands(({({"mano izquierda",0,3}),({"mano derecha",0,3})}));
  SetAggressive(0);
  SetWhimpy(40);
  SetCastChance(80);
  InitChats(2,({"Un duende aparece de repente anti ti y al momento desaparece.\n",
		"Un duende te mira curioso mientras juega con una flor.\n",
		"Un duende te mira y te dice: Aqui pueden descansar los seres benignos.. los malvados no.\n",
		"Un duende te dice: Hola soy Vexsohuydsets, estas huyendo de los muertos vivientes?\n"}));
  AddQuestion(({"muertos","muertos vivientes"}),
    "El duende te dice: Asi que no sabes qué son? Pues son seres de ultratumba resucitados mediante magia "
	"por alguna mente maligna. No les afectan las armas normales, las de plata son más efectivas con ellos.\n"
	"Tienen ciertas defensas y defectos que me encantará ver si los averiguas jeje.\n");
  AddDefence(DT_FIRE, 4);
 //Hechizos: Castigo Sagrado, Teletransporte y conjurar bicho (elemental, genio, pantera, lo que sea)
  AddSpell("CastigoSagrado",
           ([
             S_SP:30,
             S_CHANCE:100,
             S_COMBAT_DELAY:1,
             S_DELAY:6,
             S_SIMULT:0,
             S_VICTIMS:1,
             S_DAMTYPE:ST_HEAL,
		 S_MINDAM:10,
             S_MAXDAM:40,
  		 S_CHECKFUN :SF(chequeo_cs),
             S_GLOBAL_ENVMSG:("EL duende invoca a los dioses del bien contra @@VicName@@.\n"),
		 S_VICMSG:([
                      MSG_NORMAL:
                      (TC_BLUE"Vexsohuydsets junta las manos y reza una pequeña plegaria contra ti.\n"+
				"Sientes la ira de los dioses del bien.\n"TC_NORMAL),

                      MSG_DEAD:
                      ({TC_BLUE"Vexsohuydsets junta las manos y reza una pequeña plegaria contra ti y.. MUERES.\n"TC_NORMAL
                      })]),
		])

 );

AddItem("/d/lad-laurelin/comun/objeto/arma/dagaBien",REFRESH_REMOVE,SF(wieldme));
}

int ataque(){
	if (TP->QueryAlign()<0) TO->SetAggressive(2); else TO->SetAggressive(0);
	return 1;
}


