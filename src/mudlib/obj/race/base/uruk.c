/*
DESCRIPCION  : Un Uruk-hai, la raza m�s poderosa, brutal y grande de todas las razas �rquicas.
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

  AddHand("f�rrea garra derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("f�rrea garra izquierda", 0, WEAPON_CLASS_OF_HANDS);

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
"Mide m�s del metro ochenta y ronda los noventa kilos de huesos, piel y m�sculos.\n"
"@@Nombre@@ es extremadamente fornido, con gruesos brazos cuajados de m�sculos, "
"piernas robustas ligeramente arqueadas y manos dotadas de negras y f�rreas garras.\n"
"Una �spera piel, tan negra como el cerdoso pelaje que la recubre, da "
"a @@Nombre@@ un aspecto t�trico y bestial, acentuado por el cr�neo grueso y anguloso, "
"sus orejas puntiagudas y peludas, y los grandes colmillos que surgen de la pronunciada "
"mand�bula inferior.\n"
"Los ojos de @@Nombre@@ , similares a los de un gato, refulgen rojos, crueles y "
"malvados con ardiente y casi permanente furia.\n");
  SetRaceDescription (
  "Los uruk-hai son la raza orca de m�s reciente aparici�n.\n"
  "Criados por Sauron hace unos pocos siglos y m�s recientemente por Saruman, tienen la "
  "altura de un hombre, una gran fuerza y brutalidad, y una  crueldad y maldad mayores si "
  "cabe que las de un Orco y el Sol no los amilana ni los debilita.\n"
  "Poseen un espeso pelo oscuro que les cubre todo el cuerpo, espaldas y hombros "
  "poderosos, piernas mucho m�s rectas que las de un orco y brazos fuertes m�s "
  "proporcionados.\n"
  "Sus rostros, aunque brutales son m�s humanos que los de sus cong�neres menores y "
  "tienen ojos rojos o amarillos y grandes colmillos que muestran y usan como signo de "
  "estatus y poder�o.\n"
  "No hay mejores soldados orcos que los Uruk-hai, pues nacen y viven para el combate "
  "y se vanaglorian de su ardor y capacidad combativa.\n"
  "Suelen ser m�s organizados que los Orcos y los Trasgos y a veces se los encuentra "
  "como caudillos de estas razas.\n"
  "Sus fortalezas y enclaves est�n mucho mejor organizados aunque la mayor�a viven en "
  "Isengard o Mordor bajo la �gira de Saruman o Sauron.\n"
  "Son grandes herreros y fabricantes de armas y son las tropas orcas mejor equipadas "
  "de la Tierra Media.\n");
//AddEquipment("gafas ahumadas", "/obj/sunglasses", 0, 0, ({ "gafas" }));
}
