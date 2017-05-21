/*
DESCRIPCION  : un troll de la guardia personal del jefe de la tribu
FICHERO      : /d/akallab/comun/pnj/k_cueva/guardia_jefe.c
MODIFICACION : 03-12-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include <properties.h>
#include AK_MACRO
#include <gremios.h>
#include <combat.h>


inherit NPC;

create() {
  int sexo;

  ::create();
 SetStandard("guardia","troll",([GC_LUCHADOR:20+random(5)]),GENDER_MALE);
  sexo=(random(4)==1?GENDER_FEMALE:GENDER_MALE);
  SetGender(sexo);
  SetShort("un"+A_2+" corpulent"+AO2+" guardia troll");
  SetLong(
    "Es un"+AO2+" corpulent"+AO2+" guardia troll de ojos brilantes. Lleva "
   	  "un colgante caracterirstico de la guardia personal del jefe de la "
	  "tribu. Es un"+AO2+" individu"+AO2+" bastante alt"+AO2+" y corpulent"+AO2+", y "
	  "debe ser ademas un"+A_2+" muy buen"+A_2+" guerrer"+AO2+" para haber "
	  "llegado a formar parte de la guardia personal. Va bien armad"+AO2+
	  " y parece muy peligros"+AO2+".\n");

  AddId(({"guardia","troll"}));

  InitChats(8,({
    "El guardia grita:'Eh tu! Adonde se supone que vas?.\n",
    "El guardia pasea de un lado a otro vigilando tus movimientos.\n",
    "El guardia repasa sus armas sin quitarte la vista de encima.\n",
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
      P_WC: 8,
      P_SIZE:P_SIZE_LARGE,
      P_NUMBER_HANDS: 2,
      P_RESET_QUALITY: 100,
      P_WEIGHT: 8500,
      P_VALUE:  5000,
      P_WEAPON_TYPE: CS_MAZA,
      P_DAM_TYPE: DT_BLUDGEON]) );
}
