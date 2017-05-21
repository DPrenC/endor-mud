/*
DESCRIPCION  : Un rohir, habitante de Rohan
FICHERO      : /obj/race/base/rohir.c
BASADO       : /obj/race/base/human.c de NightFall
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <bandos.h>
inherit "/obj/raceobj";

create_blueprint()
{
  ::create_blueprint();

  SetAlign  (20);
  SetBando(P_BANDO_LUZ);
   SetMaxFood   (105);
  SetMaxDrink  (100);
  SetMaxAlcohol    (115);
  SetSize(P_SIZE_LARGE);

  SetWeight (83000);
  AddHand   ("firme mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("firme mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 1);
  SetStatBonus   (P_INT, 0);
  SetStatBonus   (P_STR, 0);
    SetStatBonus   ("Cha", 0);
      SetStatBonus   (P_WIS, 0);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Rohir.\n"
"De complexión fuerte y alta estatura, posee una constitución flexible y ágil, y sus "
"andares indican que está hech@@suf@@ para pasar la mayor parte de su vida a lomos de "
"una montura.\n"
"Su piel es clara, sus cabellos rubios, largos y lisos, y su rostro de hermosas "
"facciones, adopta una expresión amistosa de alegre camaradería.\n"
"Pese a ello, adviertes que en el limpio azul de sus ojos, @@Nombre@@ esconde  el "
"ardiente hielo de una ira fácil de desencadenar y difícil de apagar.\n");

  SetRaceDescription("\
Los Rohirrim o Jinetes de la Marca son un pueblo nórdico que hace unos "
"quinientos años se asentó en su actual reino, cedido por los Senescales de Gondor, "
"con los que siempre han vivido en estrecha alianza.\n"
"Son un pueblo de Hombres altos y apuestos, habitualmente rubios y de ojos claros, que "
"aman las grandes llanuras y praderas donde habitan con sus manadas de excelentes "
"caballos, a los que estiman por encima de todo.\n"
"Jinetes sin par, y grandes guerreros montados, los Rohirrim defienden con fiereza sus "
"tierras y las de sus aliados Dúnedain de Gondor, a los que han socorrido en numerosas "
"ocasiones.\n"
"Son de caracter alegre y vivo, amigos fieles y leales y enemigos feroces y despiadados.\n"
"Su vestimenta, armas, armaduras y artesanías están bellamente fabricados, adornados "
"con motivos ecuestres y habitualmente adaptados para utilizarlos a caballo.\n"
);
}

