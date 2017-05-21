/*Hobbit albo, el m�s raro*/

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

SetMaxFood(70);
SetMaxDrink(75);
SetMaxAlcohol(50);
SetSize(P_SIZE_SMALL);
SetWeight(19000);
AddHand("peque�a mano derecha", 0, WEAPON_CLASS_OF_HANDS);
AddHand("peque�a mano izquierda", 0, WEAPON_CLASS_OF_HANDS);
SetStatBonus(P_CON, 1);
SetStatBonus(P_INT, 1);
SetStatBonus(P_DEX, 3);
SetStatBonus(P_STR,     -4);
SetStatBonus(P_WIS, -1);
SetStatBonus("Cha", -1);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,15);
SetResistance(MT_POISON,5);
SetResistance(MT_PSYCHO,15);
SetResistance(DT_WATER,-5);
SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
SetUVision(2 * MAX_SUNBRIGHT);
    SetLong("@@Nombre@@ es @@ind@@ hobbit albo.\n"
    "Ronda el metro veinte de estatura y pesa unos diecinueve kilos.\n"
    "De constituci�n m�s gr�cil y esbelta que otros grupos hobbits, @@Nombre@@ "
    "es rubi@@suf@@,de piel clara, facciones regulares y ojos azules cuya inquieta "
    "mirada lo revisa todo con sumo inter�s.\n"
    "Sus �giles pies de largos dedos recubiertos de una dura pero flexible plantilla "
    "natural, le permiten moverse con gran ligereza y en total silencio sin necesidad "
    "de calzado alguno.\n");
SetRaceDescription(
"Los Albos son el tipo m�s raro de hobbit.\n"
"M�s altos y esbeltos que sus otros parientes, son los m�s parecidos a los humanos, "
"siendo confundidos en ocasiones con comunidades de �stos.\n"
"Gustan del contacto con otras razas e incluso de viajar y vivir aventuras en el ancho "
"mundo, y su carisma y osad�a les han erigido en caudillos de los grupos hobbits, cuando "
"esta raza emigr� y err� por la Tierra Media en el pasado.\n"
"Prefieren vivir en tierras frescas y boscosas y aunque algunos habitan en grandes "
"smials, la mayor�a ha comenzado a edificar casas en la superficie como otras razas.\n");
}