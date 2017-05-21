/*
DESCRIPCION  : un draconiano
FICHERO      : /obj/race/base/draconiano.c
BASADO       : Creado especificamente para este MUD. Son antropomorfos con
               ciertas caracteristicas de los reptiles. Su cultura esta basada
               en la de los dragoneros de Pern de la novela "El vuelo del
               dragon" ("Dragonflight") de Anne McCaffrey.
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
inherit "/obj/raceobj";

create_blueprint()
{
  ::create_blueprint();
  SetAlign  (25);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (80);
  SetSize(P_SIZE_MEDIUM);

  SetWeight (60000);
  AddHand("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON, -1);
  SetStatBonus(P_DEX, 0);
  SetStatBonus(P_INT, 3);
  SetStatBonus(P_STR, -2);
  SetIVision(-REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT + MAX_SUNBRIGHT / 2 );
  SetLong(
"@@Nombre@@ es @@ind@@ draconian@@suf@@. @@Nombre@@ es de tamaño medio. Se parece algo\n\
a un humano, pero el color de su piel y algunos de los rasgos de su cara\n\
muestran claramente su origen. Sus grandes ojos felinos ponen nervioso a\n\
cualquiera cuando le miran fijamente.\n");
  SetRaceDescription("\
Los draconianos son una raza que fisicamente se parecen a los humanos. Su piel\n\
es de un color pardo grisaceo o rojizo segun el sexo del individuo. Carecen de\n\
pelo en todo el cuerpo. Sus orejas abacaban en punta, sus ojos son grandes y\n\
pupilas se parecen a las de un felino. Son algo mas bajos y delgados que los\n\
humanos, pero no por ello son debiles. Su cuerpo esta adaptado para la monta de\n\
dracos (reptiles voladores emparentados con los dragones), para lo cual se\n\
necesita poco peso y gran inteligencia y agilidad ademas de una fuerza y\n\
resistencia moderadas. Son capaces de ver en la oscuridad.\n\
Son inteligentes y usan la magia con facilidad. Esto es especialmente\n\
necesario para montar y comunicarse con sus dracos.\n\
Socialmente se agrupan en clanes gobernados por un consejo de ancianos. Cada\n\
clan cuenta con la proteccion por lo menos algun Weyr en las cercanias de su\n\
ciudad principal donde viven los dragoneros.\n\
Su raza esta historicamente relacionada con la de los demonios, de la cual son\n\
enemigos irreconciliables desde que mundo es mundo.\n");
}
