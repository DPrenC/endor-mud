/*
DESCRIPCION  : Guardian orco,
FICHERO      : /d/akallab/comun/pnj/skar.c
BASADO EN    : masoch.c [Joern@nightfall]
MODIFICACION : 16-08-97 [angor] Adaptacion y nuevos dialogos
*/

#include "path.h"
#include <living.h>
#include <combat.h>
#include <gremios.h>
#include <properties.h>

inherit NPC;

create() {
  ::create();
 SetStandard("Masoch","orco",([GC_LUCHADOR: 5]),GENDER_MALE);
  SetShort("Masoch, el guardián orco");
  SetLong("Masoch es uno de los guardianes de la ciudad de Zarkam.\n");
  SetWeight(80000);
  SetGoChance(0);

  SetAlign(-500);
  SetAC(5);

  SetStr(10);
  SetDex(4);
  SetCon(10);
  SetInt(1);

  SetIds(({"masoch"}));
  AddId("guardia");
  AddId("orco");

  InitChats(10,({
  "Masoch murmura algo entre dientes.\n",
  "Masoch repasa su armadura cabizbajo.\n"}) );

// AddItem(PROT("casco_orco"), REFRESH_REMOVE, SF(wearme));
// AddItem(PROT("escudo_orco"), REFRESH_REMOVE, SF(wearme));
// AddItem(PROT("botas_orco"), REFRESH_REMOVE, SF(wearme));
   AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
    ([P_SHORT: "una enorme espada",
      P_LONG: "Una espada metalica, un poco desgastada pero muy peligrosa...\n",
      P_IDS: ({"espada",}),
      P_ADS: ({"enorme","gran"}),
      P_WC: 6, //antes era 12.. pero es un tio de nivel 5!!!!!
      P_SIZE:P_SIZE_MEDIUM,
      P_NUMBER_HANDS: 1,
      P_RESET_QUALITY: 100,
      P_WEIGHT: 8500,
      P_VALUE:  5000,
//      P_WEAPON_TYPE: WT_SWORD,
      P_WEAPON_TYPE: WT_ESPADA,
      P_DAM_TYPE: DT_SLASH]) );
}
