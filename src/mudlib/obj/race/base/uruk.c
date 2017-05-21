/*
DESCRIPCION  : Un Uruk-hai, la raza más poderosa, brutal y grande de todas las razas órquicas.
FICHERO      : /obj/race/base/uruk.c
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

  SetAlign  (-50);
  SetBando(P_BANDO_OSCURIDAD);
  
  SetMaxFood   (135);
  SetMaxDrink  (70);
  SetMaxAlcohol    (140);
  SetWeight (90000);
  SetSize(P_SIZE_LARGE);

  AddHand("férrea garra derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("férrea garra izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,  3); 
  SetStatBonus(P_DEX, 0); 
  SetStatBonus(P_INT,  -1); 
  SetStatBonus(P_STR,  2);
    SetStatBonus("Cha",  1);  
  SetStatBonus(P_WIS,  -2);  
SetResistance(DT_FIRE,30);
SetResistance(DT_COLD,5);
SetResistance(DT_GAS,15);
SetResistance(DT_NOAIR,15);
SetResistance(DT_WATER,-30);
                  SetResistance(DT_ACID,  5);
  SetIVision(-(MAX_SUNBRIGHT / 2));
  SetUVision(MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es un uruk, uno de los grandes Orcos Negros.\n"
"Mide más del metro ochenta y ronda los noventa kilos de huesos, piel y músculos.\n"
"@@Nombre@@ es extremadamente fornido, con gruesos brazos cuajados de músculos, "
"piernas robustas ligeramente arqueadas y manos dotadas de negras y férreas garras.\n"
"Una áspera piel, tan negra como el cerdoso pelaje que la recubre, da "
"a @@Nombre@@ un aspecto tétrico y bestial, acentuado por el cráneo grueso y anguloso, "
"sus orejas puntiagudas y peludas, y los grandes colmillos que surgen de la pronunciada "
"mandíbula inferior.\n"
"Los ojos de @@Nombre@@ , similares a los de un gato, refulgen rojos, crueles y "
"malvados con ardiente y casi permanente furia.\n");
  SetRaceDescription (
  "Los uruk-hai son la raza orca de más reciente aparición.\n"
  "Criados por Sauron hace unos pocos siglos y más recientemente por Saruman, tienen la "
  "altura de un hombre, una gran fuerza y brutalidad, y una  crueldad y maldad mayores si "
  "cabe que las de un Orco y el Sol no los amilana ni los debilita.\n"
  "Poseen un espeso pelo oscuro que les cubre todo el cuerpo, espaldas y hombros "
  "poderosos, piernas mucho más rectas que las de un orco y brazos fuertes más "
  "proporcionados.\n"
  "Sus rostros, aunque brutales son más humanos que los de sus congéneres menores y "
  "tienen ojos rojos o amarillos y grandes colmillos que muestran y usan como signo de "
  "estatus y poderío.\n"
  "No hay mejores soldados orcos que los Uruk-hai, pues nacen y viven para el combate "
  "y se vanaglorian de su ardor y capacidad combativa.\n"
  "Suelen ser más organizados que los Orcos y los Trasgos y a veces se los encuentra "
  "como caudillos de estas razas.\n"
  "Sus fortalezas y enclaves están mucho mejor organizados aunque la mayoría viven en "
  "Isengard o Mordor bajo la égira de Saruman o Sauron.\n"
  "Son grandes herreros y fabricantes de armas y son las tropas orcas mejor equipadas "
  "de la Tierra Media.\n");
//AddEquipment("gafas ahumadas", "/obj/sunglasses", 0, 0, ({ "gafas" }));
}
