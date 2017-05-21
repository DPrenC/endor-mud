/*
DESCRIPCION  : un guardia troll
FICHERO      : /d/akallab/comun/pnj/k_cueva/guardia.c
MODIFICACION : 21-10-98 [Angor@Simauria] Creacion
*/

#include "path.h"
#include <properties.h>
#include AK_MACRO
#include <gremios.h>
#include <combat.h>


inherit NPC;

create() {

  ::create();
 SetStandard("guardia","troll",([GC_LUCHADOR:10+random(5)]), (random(4)==1)?GENDER_FEMALE:GENDER_MALE);
  SetShort("un"+A_2+" guardia troll");
  SetLong(
    "Es un"+AO2+" corpulent"+AO2+" troll de ojos brilantes. Es un"+AO2+
	  " de los guardias troll que se encargan de defender la Gran Caverna "
	  "de los posibles intrusos. Va bien armad"+AO2+" y parece peligros"+
	  AO2+".\n");

  AddId(({"guardia","troll"}));
  SetAlign(-500);
  InitChats(8,({
    "El guardia grita:'Eh tu! Adonde se supone que vas?.\n",
    "El guardia pasea de un lado a otro vigilando tus movimientos.\n",
    "El guardia repasa sus armas sin quitarte la vista de encima.\n",
    "El guadia murmura:'Hoy se esta retrasando mi relevo. Se va a enterar...'\n",
    "El guardia advierte: Cuidado con lo que haces en la Gran Caverna.\n"
    "El guardia te dice: Y tu que demonios miras?.\n"
    }));

  InitAChats(10,({
    "El guardia grita:'Moriras!.\n",
    "El guardia te ataca violentamente.\n",
    "El guardia grita con fuerza.\n",
    "El guadia tiene los ojos inyectados en sangre.'\n",
    "El guardia te grita: Miserable! vas a morir ahora!.\n"
    }));

  //AddItem(PROT("casco_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("escudo_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("guantes_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("botas_orco"), REFRESH_REMOVE, SF(wearme));

  AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
    ([P_SHORT: "una enorme maza",
      P_LONG: "Una enorme maza de madera, un poco desgastada pero muy peligrosa...\n",
      P_IDS: ({"maza",}),
      P_ADS: ({"enorme","gran"}),
      P_WC: 12,
      P_SIZE:P_SIZE_LARGE,
      P_NUMBER_HANDS: 2,
      P_RESET_QUALITY: 100,
      P_WEIGHT: 8500,
      P_VALUE:  5000,
      P_WEAPON_TYPE: CS_MAZA,
      P_DAM_TYPE: DT_BLUDGEON]) );
}
