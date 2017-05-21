/*Hobbit peloso, el más común*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <bandos.h>

inherit "/obj/raceobj";

create_blueprint(){
::create_blueprint();

SetAlign(30);
SetBando(P_BANDO_LUZ);

SetMaxFood(75);
SetMaxDrink(75);
SetMaxAlcohol(50);
SetSize(P_SIZE_SMALL);
SetWeight(20000);
AddHand("pequeña mano derecha", 0, WEAPON_CLASS_OF_HANDS);
AddHand("pequeña mano izquierda", 0, WEAPON_CLASS_OF_HANDS);
SetStatBonus(P_CON, 1);
SetStatBonus(P_INT, 0);
SetStatBonus(P_DEX, 3);
SetStatBonus(P_STR,     -4);
SetStatBonus(P_WIS, -3);
SetStatBonus("Cha", -3);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,15);
SetResistance(MT_POISON,5);
SetResistance(MT_PSYCHO,15);
SetResistance(DT_WATER,-5);
SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
SetUVision(2 * MAX_SUNBRIGHT);
    SetLong("@@Nombre@@ es @@ind@@ hobbit peloso, la variante más común de Hobbit.\n"
    "@@Nombre@@ ronda el metro de altura y pesará alrededor de los veinte kilos.\n"
    "De abundante pelo castaño y rostro totalmente lampiño, tiene una piel morena, "
    "facciones bonachonas y ojos oscuros de mirada alegre y amistosa.\n"
    "Sus manos son de dedos largos y ágiles, y sus pies, algo mayores de lo que "
    "correspondería a un humano de su estatura, están recubiertos por abundante vello, "

"lo que le permite moverse descalz@@suf@@ con gran facilidad y sigilo.\n");
        
SetRaceDescription(
"Los Pelosos son el grupo más numeroso y común de hobbits.\n"
"De carácter tranquilo, alegre y conservador, pocos de ellos se atreven a cruzar sus fronteras hacia el mundo exterior.\n"
"Gustan de vivir en las tierras altas y en las laderas de las colinas, y aún siguen muy apegados a la antigua tradición de vivir en agujeros excavados, también llamados Smials, edificando muy raramente.\n");
}