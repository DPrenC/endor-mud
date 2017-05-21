/*
DESCRIPCION    : Una momia con el hechizo "Contagio"
FICHERO        : /d/lad-laurelin/comun/pnj/tiin/lago/momia.c
CREACION       : 16-05-01 (Alura)
U.MODIFICACION :
*/

#include "path.h"
#include <combat.h>
#include <living.h>
#include <spellmonster.h>
#include <colours.h>
#include <magia.h>
#include <money.h>
#include <properties.h>


inherit "/obj/monster/spellundead";

//declaracion de hechizos:
public int contagio();

int nivel;

create() {
  ::create();
 seteuid(getuid());
  nivel=20+random(5);
  SetStandard("una momia","no-muerto",nivel,GENDER_FEMALE);
  SetShort("momia");
  SetLong(
"Su cuerpo está cubierto por viejas vendas deshilachadas. Camina lentamente y\n"
"sin pausa, arrastrando sus pies. Se dirige hacia ti emitiendo un gemido\n"
"lastimero que no espera ser contestado.\n");
  SetIds(({"momia"}));   //identificativos
  SetAds(({"la","una"}));   //adjetivos feo, alto...
  SetAlign(-500);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetHands(({({"mano izquierda",0,12}),({"mano derecha",0,12})}));  //manos o garras o ...
  SetDex(nivel-10);
  SetInt(nivel-17);
  SetCon(nivel+17);
  SetStr(nivel+10);
  SetAggressive(1);  // agresivo 1=si, 0=no 2=con otros mobs

  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney((random(20)+1)*50,({"oro"}))]));

  AddSpell("Contagio",
           ([
             S_SP:30,
	     S_CHANCE:10,
             S_COMBAT_DELAY:0,
             S_DELAY:50,
             S_SIMULT:1,
             S_VICTIMS:1,
             S_DAMTYPE:ST_POISON,
             S_FUN:SF(contagio),
	     S_GLOBAL_ENVMSG:(TC_YELLOW"Un fulgor verde destellea en los brazos de la momia cuando toca\n"+
					"a @@VicName@@.\n"TC_NORMAL),
             S_VICMSG:([
                      MSG_NORMAL:
                      ("Te sientes enfermo..\n"),

                      MSG_DEAD:
                      ({"Caes al suelo con temblores catalepticos hasta que no sientes nada...\n"
                      })
           ]),


])
  );
}

contagio(mapping sp, object *vic){
 object *en,ene;
 int danyo;
 int danyoIni;

 en=QueryEnemies()||({});
 ene=en[random(sizeof(en))];
 //contagio pasa una enfermedad con daño inmediato que poco a poco va quitando mas vida

 danyoIni=ene->QueryMaxPoison();
 if (ene->QueryPoison()<(danyoIni/2)) danyo=danyoIni+random(70);
 else danyo=random(70);
 ene->SetPoison(danyo);
 vic=({ene});
 return sp;
}


