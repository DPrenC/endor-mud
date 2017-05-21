/*Hobbit peloso, el m�s com�n*/

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
AddHand("peque�a mano derecha", 0, WEAPON_CLASS_OF_HANDS);
AddHand("peque�a mano izquierda", 0, WEAPON_CLASS_OF_HANDS);
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
    SetLong("@@Nombre@@ es @@ind@@ hobbit peloso, la variante m�s com�n de Hobbit.\n"
    "@@Nombre@@ ronda el metro de altura y pesar� alrededor de los veinte kilos.\n"
    "De abundante pelo casta�o y rostro totalmente lampi�o, tiene una piel morena, "
    "facciones bonachonas y ojos oscuros de mirada alegre y amistosa.\n"
    "Sus manos son de dedos largos y �giles, y sus pies, algo mayores de lo que "
    "corresponder�a a un humano de su estatura, est�n recubiertos por abundante vello, "

"lo que le permite moverse descalz@@suf@@ con gran facilidad y sigilo.\n");
        
SetRaceDescription(
"Los Pelosos son el grupo m�s numeroso y com�n de hobbits.\n"
"De car�cter tranquilo, alegre y conservador, pocos de ellos se atreven a cruzar sus fronteras hacia el mundo exterior.\n"
"Gustan de vivir en las tierras altas y en las laderas de las colinas, y a�n siguen muy apegados a la antigua tradici�n de vivir en agujeros excavados, tambi�n llamados Smials, edificando muy raramente.\n");
}