/*
DESCRIPCION  : un medio elfo
FICHERO      : /obj/race/base/medio-elfo.c--------------------------------------------------------------------------------
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
  SetAlign(45);
  SetBando(P_BANDO_LUZ); 
  SetMaxFood(95);
  SetMaxDrink(105);
  SetMaxAlcohol(95);
  SetWeight(85000);
  SetSize(P_SIZE_LARGE);

  AddHand("firme mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("firme mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,1); 
  SetStatBonus(P_DEX,1);  
  SetStatBonus(P_INT,2);  
  SetStatBonus(P_STR,1); 
SetStatBonus(P_WIS, 1);
SetStatBonus("Cha", 1);
SetResistance(DT_COLD,5);
SetResistance(DT_GAS,-5);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,5);
SetResistance(DT_NOAIR,-5);
                  SetResistance(DT_ACID,  -5);
  SetIVision(REL_STATE(ND_DAWN,MAX_SUNBRIGHT));
  SetUVision(2*MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Medio elf@@suf@@, y por sus venas corre la sangre de los Primeros "
"Nacidos y los Hombres.\n"
"Sus nobles rasgos, su piel libre de toda mácula, el brillo de sus ojos y la majestad "
"que irradia denotan la herencia élfica, aunque su robustez, mayor que la de cualquier "
"elfo,  y la energía que transmiten sus movimientos descubren que @@Nombre@@ también "
"desciende de la línea de los Hombres.\n"
"@@Nombre@@ es alt@@suf@@, de constitución estilizada pero más robusta que la de un "
"Elfo, de rostro más hermoso y noble que el de cualquier mortal, y en sus ojos grises "
"se puede percibir tanto la profunda tristeza y sabiduría de los Elfos como el fuego "
"interior, intenso pero breve,  de la corta vida de la raza de los hombres.\n"); 
 SetRaceDescription(
  "Los Medio Elfos son el fruto de las escasas uniones entre Elfos y Hombres, "
  "habitualmente Dúnedain.\n"
  "Comparten rasgos físicos y mentales de ambas razas, y en cierto momento de su vida "
  "pueden elegir si unen su destino al pueblo de los Elfos y se convierten en "
  "inmortales o escogen el destino de los Hombres y tienen una vida larga aunque "
  "finalmente mueren.\n"
  "Son gentes habitualmente solemnes y graves cuya lealtad se divide entre las dos "
  "razas a las que pertenecen y que en ocasiones no se sienten cómodas entre ninguna de "
  "las dos.\n"
  "No obstante, muchos forman un nexo de unión entre Elfos y Hombres y colaboran en la "
  "cooperación y la alianza entre ambas razas.\n"
  "Habitualmente, son buenos guerreros y exploradores y poseen un amplio abanico de "
  "habilidades y poderes de los que los Hombres nunca podrían soñar en tener.\n");

}
