/*
DESCRIPCION  : Aken, orco encargado de la presa.
FICHERO      : /d/akallab/comun/pnj/aken.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
               26-10-99 [woo] Ahora usa NUMBER hands, que petaba..
--------------------------------------------------------------------------------
*/

#include <properties.h>
#include <combat.h>
#include <money.h>
#include <rooms.h>
#include <gremios.h>

inherit NPC;

create () {

  ::create();
 SetStandard("Aken","orco",([GC_LUCHADOR:10]),1);
  SetShort("Aken, el lenyador");
  SetLong(
"Ves a Aken, un orco que ha dedicado toda su vida al cuidado de la presa "
"y a cortar lenya. A primera vista no notas ninguna diferencia con los "
"demas orcos que has visto, hasta que te fijas en que tiene dos dedos menos "
"en la mano izquierda, seguramente los habra perdido en un accidente laboral. "
"Notas que es un orco apacible y que no tiene ganas de luchar con nadie, "
"pero seguro que se sabe denfender.\n");
  SetWeight(90000);
  SetGoChance(0);
  SetAlign(-200);
  SetAggressive(0);

  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney((random(15)+10),
    ({"plata","cobre"}))]));
  AddItem("/std/weapon", REFRESH_REMOVE|REFRESH_FUNC
         , ([ P_SHORT: "un hacha"
            , P_LONG:
"Es un hacha de tamanyo mediano. No parece de muy buena calidad, pero si "
"lo suficiente como para cortar arboles o producir graves heridas.\n" //
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
"lo suficiente como para cortar arboles o producir graves heridas.\n" //
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
"abdominal y el pecho, pero no los brazos.\n" //
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
  "Aken escupe una masa verde al suelo.\n",
  "Aken dice: Hace tiempo, un accidente, mis dedos...\n",
  "Aken grita: Agh... Hoy tengo un mal dia. "
                })
           );

  InitAChats (20, ({
  "Aken dice: Yo perdi los dedos, tu perderas la cabeza.\n",
  "Aken pregunta: Por que nos molestas?\n",
  "Aken escupe algo de sangre al suelo. "
                      })
                 );
}
