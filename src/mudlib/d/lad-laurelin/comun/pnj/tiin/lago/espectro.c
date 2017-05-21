/*
DESCRIPCION    : Espectro
FICHERO        : /d/lad-laurelin/comun/pnj/tiin/lago/momia.c
CREACION       : 30-05-01 (Alura)
U.MODIFICACION :
*/

#include "path.h"
#include <combat.h>
#include <living.h>
#include <spellmonster.h>
#include <colours.h>
#include <magia.h>
#include <properties.h>


inherit "/obj/monster/spellundead";

//declaracion de hechizos:
public int drenar_energia();

int nivel;

create() {
  ::create();
  nivel=15+random(5);
  SetStandard("un espectro","no-muerto",nivel,GENDER_MALE);
  SetShort("espectro");
  SetLong(
" Este ser no tiene cuerpo, lo que ves no es mas que la imagen translúcida de\n"
"un ente etéreo, sin forma, que levita a tu alrededor.\n");
  SetIds(({"espectro","fantasma"}));   //identificativos
  SetAds(({"un"}));   //adjetivos feo, alto...
  SetAlign(-100);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetHands(({({"mano izquierda",0,5}),({"mano derecha",0,5})}));  //manos o garras o ...

  SetAggressive(1);  // agresivo 1=si, 0=no 2=con otros mobs

  AddSpell("drenarEnergia",
           ([
             S_SP:20,
	     S_CHANCE:10,
             S_COMBAT_DELAY:0,
             S_DELAY:30,
             S_SIMULT:1,
             S_VICTIMS:1,
             S_DAMTYPE:ST_PSYCHO,
             S_FUN:SF(drenar_energia),
	     S_GLOBAL_ENVMSG:(TC_WHITE"El espectro se ilumina levemente. @@VicName@@ pierde algo de energia.\n"TC_NORMAL),
             S_VICMSG:([
                      MSG_NORMAL: ("Has perdido energia.\n"),

                      MSG_DEAD: ({"El espectro ha absorbido toda la energia que te quedaba. Tu final ha llegado.\n"})
                      ]),
           ])
  );
}
drenar_energia(mapping sp, object *vic){
  object *en,ene;

  en=QueryEnemies()||({});
  if (!(vic=({ene=en[random(sizeof(en))]}))) return 0;
  ene->SetmpConMalus(1);
  ene->SetmpStrMalus(1);
  ene->SetmpIntMalus(1);
  ene->SetmpDexMalus(1);
  return sp;
}

