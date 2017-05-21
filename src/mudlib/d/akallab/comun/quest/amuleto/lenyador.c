/*
DESCRIPCION  : Senko, orco que repara el aseradero (quest amuleto perdido)
FICHERO      : /d/akallab/comun/quest/amuleto/lenyador.c
MODIFICACION : 26-10-99 [angor] Creacion
--------------------------------------------------------------------------------
*/

#include <properties.h>
#include <combat.h>
#include <money.h>
#include <rooms.h>

#include "path.h"
#include AK_MACRO

inherit NPC;

create () {
  ::create();
  SetName("Senko");
  SetShort("Senko, el lenyador");
  SetLong(
  "Senko es un lenyador orco que trabaja en el aserradero de la presa. "
  "Es un orco fornido con una fea cicatriz que le recorre el rostro y le "
  "proporciona un aspeto aun mas rudo si cabe. No para de forcejear con "
  "uno de los engranajes de las sierras que no parece ir muy bien.\n");
  SetRace("orco");
  SetSize(P_SIZE_MEDIUM);
  SetGender(1);
  SetWeight(90000);
  SetGoChance(0);
  SetLevel(10);
  SetAlign(-200);
  SetAggressive(0);
  SetMaxHP(180);
  SetHP(155);
  SetHands(({ ({ "la garra derecha", 0, 2 })
            , ({ "la garra izquierda", 0, 2 })
            })
     );

  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney((random(15)+10),
    ({"plata","cobre"}))]));
  AddItem("/std/weapon", REFRESH_REMOVE|REFRESH_FUNC
         , ([ P_SHORT: "un hacha"
            , P_LONG:
"Es un hacha de tamanyo mediano. No parece de muy buena calidad, pero si "
"lo suficiente como para cortar arboles o producir graves heridas.\n"//
            , P_VALUE: 4000
            , P_WEIGHT: 3500
            , P_IDS: ({ "hacha" })
            , P_WEAPON_TYPE: WT_ESPADA
            , P_DAM_TYPE: DT_SLASH
            , P_WC: 5
            , P_NUMBER_HANDS: 1
            , P_MATERIAL: 7
           ])
         , SF(wieldme)
         );

  AddItem("/std/weapon", REFRESH_REMOVE|REFRESH_FUNC
         , ([ P_SHORT: "un hacha"
            , P_LONG:
"Es un hacha de tamanyo mediano. No parece de muy buena calidad, pero si "
"lo suficiente como para cortar arboles o producir graves heridas.\n"//
            , P_VALUE: 4000
            , P_WEIGHT: 3500
            , P_IDS: ({ "hacha" })
            , P_WEAPON_TYPE: WT_ESPADA
            , P_DAM_TYPE: DT_SLASH
            , P_WC: 5
            , P_NUMBER_HANDS: 1
            , P_MATERIAL: 7
           ])
         , SF(wieldme)
         );

  SetAC(3);
  AddItem("/std/armour", REFRESH_REMOVE|REFRESH_FUNC
         , ([ P_SHORT: "una armadura de cuero"
            , P_LONG:
"Es una armadura de cuero curtido, algo vieja y llena de aranyazos como "
"muestra de que ha sido sometida a duros trabajos. Protege toda la zona "
"abdominal y el pecho, pero no los brazos.\n"//
            , P_VALUE: 5000
            , P_WEIGHT: 3000
            , P_IDS: ({ "armadura", "cuero" })
            , P_ARMOUR_TYPE: AT_ARMOUR
            , P_AC: 2
            , P_MATERIAL: 2
           ])
         , SF(wearme)
         );

  InitChats (15, ({
  "Senko escupe una masa verde al suelo.\n",
  "Senko te dice: Eh tu! ayudame con este maldito engranaje.\n",
  "Senko grita: Aken! Donde demonios estas cuando se te necesita!. "
                })
           );

  InitAChats (20, ({
  "Senko grita: Hijo de mala madre!.\n",
  "Senko te grita: Vas a morir miserable?\n",
  "Senko escupe algo de sangre al suelo. "
                      })
                 );
 AddQuestion(({"ayuda","engranaje","sierra"}),
 "Senko te dice: Maldita sierra! ultimamente va bastante mal y con la "
   "cantidad de trabajo que tengo pendiente... Debe ser este engranaje. "
   "Tendria que arreglarlo pero no tengo aqui lo que necesito, un tablon, "
   "un cubo y un serrucho. Ese desgraciado de Aken debe estar durmiendo "
   "por ahi en vez de echarme una mano...\n");

 }
