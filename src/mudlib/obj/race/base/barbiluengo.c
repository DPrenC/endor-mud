/*
DESCRIPCION  : un enano  Barbiluengo.
FICHERO      : /obj/race/base/barbiluengo.c
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
  SetAlign(15);
  SetMaxFood(115);
  SetMaxDrink(90);
  SetMaxAlcohol(200);
  SetWeight(75000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_LUZ);
  AddHand("callosa mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("callosa mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,3);
  SetStatBonus(P_DEX,-3);
  SetStatBonus(P_INT,0);
  SetStatBonus(P_STR,2);
  SetStatBonus(P_WIS, 1);
SetStatBonus("Cha", -1);
  SetResistance(DT_FIRE,20);
SetResistance(DT_COLD,10);
SetResistance(DT_GAS,5);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,40);
SetResistance(DT_NOAIR,5);
SetResistance(DT_WATER,-35);
SetResistance(MT_WATER,-25);
                  SetResistance(DT_ACID,  5);
  SetIVision(-REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT);

  SetLong(
  "@@Nombre@@ es @@ind@@ enan@@suf@@ del clan de los Barbiluengos o Pueblo de Durin.\n"
  "Es  de apostura noble, robust@@suf@@ como lo son todos los "
  "miembros de su raza.\n"
  "El cabello de @@Nombre@@ es muy oscuro y lo lleva largo sobre sus hombros y "
  "espalda, pues  los Barbiluengos se enorgullecen del vello de cara y cr�neo.\n"
  "El rostro de facciones anchas, parece noble, reservado, y la seria mirada de sus "
  "oscuros ojos, le da cierta solemnidad, aunque en sus ademanes y actitud se puede "
  "percibir que @@Nombre@@ puede estallar de furia si se le provoca u ofende.\n"
  "En conjunto, su porte, aspecto y maneras dan la impresi�n de ser @@ind@@ enan@@suf@@ "
  " de gran nobleza, no exenta de orgullo.\n");
  
  SetRaceDescription(
  "Los Barbiluengos, tambi�n llamados Pueblo de Durin son el primer y m�s afamado pueblo "
  "o casa de las siete que forman la raza enana.\n"
  "Son el pueblo del primer Padre de los Enanos, Durin, tenido por se�or supremo de la "
  "raza enana.\n"
  "Anta�o su fortaleza ancestral fue Kh�zad-D�m, la m�s extensa, rica y poderosa "
  "mansi�n enana que el mundo jam�s viera.\n"
  "Tras varias edades de las estrellas y tres del Sol, un demonio del mundo antiguo "
  "fue sacado de su sue�o en las entra�as de la tierra por los mineros que cavaban "
  "muy hondo en busca del preciado metal llamado Mithril.\n"
  "Este Balrog mat� al rey y su heredero y destruy� el reino, y el Pueblo de Durin se "
  "convirti� en fugitivo.\n"
  "Desde entonces, erraron por muchos lugares y levantaron nuevas moradas, en "
  "muchas ocasiones saqueadas por orcos y dragones, aunque la m�s importante de "
  "todas, Erebor, la Monta�a Solitaria, fue reconquistada y a fines de la "
  "Tercera Edad es el m�s poderoso y rico basti�n de los enanos en el noroeste de la "
  "Tierra Media.\n"
  "Los Barbiluengos, como todos los enanos son excelentes artesanos, mineros, "
  "constructores y herreros y su tenacidad, fiereza y valor los convierten en "
  "formidables guerreros que persiguen a orcos, dragones y huargos con un odio ancestral.\n"
  "Siempre han sido af�rrimos enemigos del mal y Sauron los ha odiado y perturbado "
  "siempre que le ha sido posible.\n"
  "El nombre del clan proviene de las frondosas y luengas barbas que suelen lucir con "
    "gran orgullo y que consideran muestra de su edad, sabidur�a y estatus social.\n");
}