/*
DESCRIPCION : esqueleto guerrero
FICHERO     : /d/akallab/comun/pnj/monstruo/esqueleto.c
MODIFICACION: 27-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit NPC;

create() {
  ::create();
 SetName("un guerrero esqueleto");
  SetShort("un esqueleto guerrero");
  SetLong(
    "Es un esqueleto al que algun oscuro maleficio ha levantado de la tumba. Está "
    "fuertemente armado y parece muy fiero. En las vacias cuencas de sus ojos "
    "brilla una diablólica llama.\n");

  SetIds(({"esqueleto","guerrero","nomuerto"}));
  SetAds(({"esqueleto","nomuerto"}));
  SetRace("nomuerto");
  SetSize(P_SIZE_MEDIUM);
  SetLevel(20+random(10));
  SetAlign(-900);
  SetAC(5);
  AddDefence(DT_PIERCE,30);

  AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "una cota de malla",
      P_LONG: "Es una vieja y oxidada cota de malla.\n",
      P_IDS: ({"cota de malla","cota","armadura"}),
      P_AC: 4,
      P_ARMOUR_TYPE: AT_ARMOUR,
      P_SIZE:P_SIZE_MEDIUM,
      P_WEIGHT: 12000,
      P_VALUE: 2000,
      P_RESET_QUALITY:random(40)+1,
      P_GENDER:GENDER_MALE]));

  AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "un casco con cuernos",
      P_LONG: "Un antiguo casco de metal con dos cuernos de hueso.\n",
      P_IDS: ({"casco"}),
      P_ADS: ({"antiguo","con cuernos"}),
      P_AC: 1,
      P_SIZE:P_SIZE_MEDIUM,
      P_WEIGHT: 2000,
      P_ARMOUR_TYPE:AT_HELMET,
      P_RESET_QUALITY:random(80)+1,
      P_VALUE: 300,
      P_GENDER:GENDER_FEMALE]));

  AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
    ([P_SHORT: "una mellada hacha de combate",
      P_LONG: "Es una vieja y mellada hacha de combate orca.\n",
      P_IDS: ({"hacha","arma"}),
      P_ADS: ({"de combate","mellada"}),
      //P_WEAPON_TYPE:WT_AXE,
      P_WEAPON_TYPE:CS_HACHA,
      P_DAM_TYPE:DT_SLASH,
      P_WEIGHT: 9000,
      P_SIZE:P_SIZE_MEDIUM,
      P_WC: 15,
      P_RESET_QUALITY:random(60)+1,
     P_GENDER:GENDER_MALE]));
}
