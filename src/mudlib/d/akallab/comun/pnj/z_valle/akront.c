/*
DESCRIPCION  : Akront, orco encargado de la presa.
FICHERO      : /d/akallab/comun/pnj/akront.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include <properties.h>   //por el PSIZE
#include <combat.h>
#include <money.h>
#include <rooms.h>       //por el REFRESH_REMOVE
#include <gremios.h>

inherit NPC;

create () {

  ::create();
 SetStandard("Akront","orco",([GC_LUCHADOR: 11]),1);
  SetShort("Akront, el lenyador");
  SetLong(
 "Ves a Akront, un lenyador orco al que su trabajo ha proporcionado una "
 "extraordinaria musculatura en sus brazos, podria matar a cualquier "
 "animal con una simple caricia. Son estos, los brazos, la unica parte de "
 "su cuerpo que no esta cubierta por la armadura, pero no parecen, ni "
 "mucho menos, su punto debil.\n");
  SetIds(({"orco","lenyador","akront","Akront"}));
  SetWeight(90000);
  SetGoChance(0);
  SetAlign(-200);
  SetAggressive(0);
  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney((random(25)+12),
    ({"plata","cobre"}))]));
  AddItem("/std/weapon", REFRESH_REMOVE|REFRESH_FUNC
         , ([ P_SHORT: "un hacha a dos manos"
            , P_LONG:
  "Es un hacha de doble filo, demasiado pesada para llevarla con una sola "
  "mano. Tiene algunas inscripciones en el mango, pero no logras descrifarlas. "
  "Las muescas que se han producido en los filos dejan al descubierto que se "
  "han cortado muchos arboles con ella.\n"//
            , P_VALUE: 10000
            , P_WEIGHT: 15000
            , P_IDS: ({ "hacha" })
            , P_WEAPON_TYPE: WT_ESPADA
            , P_DAM_TYPE: DT_SLASH
            , P_WC: 8
            , P_NUMBER_HANDS: 2
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

  InitChats (10, ({
  "Akront se rasca la cabeza.\n",
  "Akront dice: Cortar lenya es mi trabajo, me gusta.\n",
  "Akront dice: Mejor que no intentes ninguna tonteria.\n",
                })
           );

  InitAChats (20, ({
  "Ves como se hinchan los musculos de los brazos de Akront.\n",
  "Akront exclama: Te abrire la tapa de los sesos!!\n",
  "Akront dice: A eso llamas tu luchar...? "
                      })
                 );
}
