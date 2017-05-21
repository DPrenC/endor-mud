/* fichero: espada_eowyn.c 
Autor: Aulë
Fecha: 16/11/2014
Descripción: espada de Eowyn, que probablemente entregue en quest.
*/
#include <combat.h>
#include <properties.h>
#include <colours.h>
#define MIN_LEVEL 40

inherit WEAPON;


create() {
  ::create();
  SetStandard(WT_ESPADA, 6, P_SIZE_LARGE, M_ACERO);
  AddAdjective(({"una","ancha", "ligera", "de acero", "rohir",}));
  AddId(({"espada","arma","espada ancha", "espada rohir"}));
  SetShort("la espada de Eowyn");
  SetLong(
"Es una ligera espada de porte noble y elegante. La hoja, algo más ancha de lo común, "
"está confeccionada en refulgente acero de gran calidad, con filos rectos que hacia el "
"final de la hoja se estrechan y acaban en una aguzada punta.\n"
"Un amplio vaceo recorre los planos del arma en sus tres cuartas partes, y ninguna mácula "
"o mella puede advertirse en toda su espejada superficie.\n"
"La empuñadura está envuelta en suave cuero marrón, y tanto el pomo como los gavilanes de"
" la cruceta están realizados en bronce dorado finamente forjado simulando cabezas de "
"caballos tan bien realizados que hasta la más fina de sus crines ha sido moldeada con "
"un cuidado exquisito. En conjunto resulta un arma liviana y veloz, mortífera en manos de"
" un hábil espadachín. Pequeños detalles como su ligereza y el hecho de tener la hoja  "
"más corta y liviana que la de otras espadas, hacen pensar en que este arma ha sido "
"forjada para la mano de una doncella guerrera del pueblo rohir.\n");
 SetWeight(2400);
 SetMagic(1);
}


public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
  if (wielder->QueryGender() == "female")
  {
    tell_object(wielder,"Tu mano se cierra con firmeza alrededor de la empuñadura de esta bella espada que parece hcha a medida para ti.\n"
    "El arma te parece ligera pero contundente y bien equilibrada.\n");
    SetWC(10);
  }
  return ::ChkEquip(wielder, weapon, flags);
}

public varargs mixed ChkUnequip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
  SetWC(6);
  return ::ChkUnequip(wielder, weapon, flags);
}