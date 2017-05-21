/*
DESCRIPCION    : El nigromante que lleva la tienda del Boque de la Batalla Perdida
FICHERO        : /d/lad-laurelin/comun/pnj/tiin/lago/Lioua-gan.c
CREACION       : Junio 2001 (Alura)
*/

#include "path.h"
#include <combat.h>
#include <living.h>
#include <spellmonster.h>
#include <colours.h>
#include <magia.h>
#include <properties.h>

inherit SPELLMONSTER;

//declaracion de hechizos:
public int drenar_magia();

create() {
  ::create();
 SetStandard("Lioua-gan","humano",27+random(5),GENERO_MASCULINO);
  SetLong(
" Es un humano, vestido con la túnica oscura de los nigromantes. Su cuerpo es robusto\n"
"aunque de complexión delgada, y lleva el cabello largo recogido.\n");
  //  SetIds(({"nigromante","Lioua-gan"}));   //identificativos
  SetAlign(-10);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetHands(({({"mano izquierda",0,5}),({"mano derecha",0,5})}));  //manos o garras o ...

  SetAggressive(0);  // agresivo 1=si, 0=no 2=con otros mobs

  AddResistance(DT_COLD, 100);
  AddResistance(DT_POISON, 100);
  AddResistance(DT_PSYCHO, 60);

  AddDefence(DT_BLUDGEON, 2);
  AddDefence(DT_PIERCE, 5);
  AddDefence(DT_SLASH, 3);
  AddDefence(DT_MAGIC, 4);
  AddDefence(DT_FIRE, 9);
  AddDefence(DT_ACID, -2);
  AddDefence(DT_ELECTRO, -1);

  AddSpell("drenarMagia",
           ([
             S_SP:20,
	     S_CHANCE:10,
             S_COMBAT_DELAY:0,
             S_DELAY:30,
             S_SIMULT:1,
             S_VICTIMS:1,
             S_DAMTYPE:ST_CHANGE,
             S_FUN:SF(drenar_magia),
	     S_GLOBAL_ENVMSG:(TC_GREEN"El nigromante toca a @@VicName@@ y una aura azul aparece entorno a él.\n"TC_NORMAL),
             S_VICMSG:([
                      MSG_NORMAL:
                      ("Tu energía mágica disminuye.\n"),

                      MSG_DEAD:
                      ({"Lioua-gan ha absorbido toda la energia mágica que te quedaba. Tu final ha llegado.\n"
                      })
           ]),


])
  );

  AddSpell("relampagos",
           ([
             S_SP:27,
		 S_CHANCE:10,
             S_COMBAT_DELAY:0,
             S_DELAY:20,
             S_MINDAM:30,
             S_MAXDAM:40,
             S_SIMULT:1,
             S_VICTIMS:0,
             S_DAMTYPE:ST_ELECTRO,
		 S_GLOBAL_ENVMSG:(TC_YELLOW"Varios rayos salen de los dedos del nigromante.\n"TC_NORMAL),
             S_VICMSG:([
                      MSG_NORMAL:
                      (TC_CYAN"Una descarga eléctrica impacta dolorasemente en todo tu cuerpo\n"TC_NORMAL),

                      MSG_DEAD:
                      ({TC_RED"Lo último que has visto antes de que se quemen tus entrañas es un rayo.\n"TC_NORMAL
                      })
           ]),


])
  );

}

drenar_magia(mapping sp, object *vic){
//Recuerdo pa quien no lo sepa q si personalizas la funcion de cast, tienes que
//comprobar a mano las defensas magicas del jugador
 object *en,ene;
  //Que resistencia uso para parar el cambio de una caracteristica?
 en=QueryEnemies()||({});
 ene=en[random(sizeof(en))];
 ene->AddSP(-30);
 vic=({ene});
 return sp;
}

