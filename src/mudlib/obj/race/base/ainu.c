/*
DESCRIPCION: raza de los Ainur que forman Valar y Maiar por igual.
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
  SetAlign(500);
  SetBando(P_BANDO_LUZ);
  SetMaxFood(200);
  SetMaxDrink(200);
  SetMaxAlcohol    (200);
  SetWeight (71000);
  SetSize(P_SIZE_LARGE);
AddHand("bendita mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("bendita mano izquierda", 0, WEAPON_CLASS_OF_HANDS);
  SetIVision(0); //SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT*3);
  SetLong("@@Nombre@@ es uno de los Ainur, uno de los seres angélicos que estaban con "
  "Eru al principio de los tiempos.\n");

  SetResistance(MT_COLD, 100);
  SetResistance(DT_COLD, 100);
  SetResistance(MT_POISON, 100);
  SetResistance(DT_POISON, 100);
  SetResistance(DT_GAS, 100);
  SetResistance(MT_GAS, 100);
  SetResistance(DT_NOAIR, 100);
  SetResistance(MT_NOAIR, 100);
  SetResistance(DT_FIRE, 100);
  SetResistance(MT_FIRE, 100);
  SetResistance(DT_PSYCHO, 100);
  SetResistance(MT_PSYCHO, 100);
  SetResistance(DT_PIERCE, 100);
  SetResistance(MT_PIERCE, 100);
  SetResistance(DT_SLASH,  100);
  SetResistance(MT_SLASH,  100);
    SetResistance(MT_WATER, 100);
      SetResistance(DT_WATER,  100);
        SetResistance(MT_BLUDGEON,  100);
          SetResistance(DT_BLUDGEON,  100);
            SetResistance(MT_ELECTRO,  100);
              SetResistance(DT_ELECTRO,  100);
                SetResistance(MT_ACID,  100);
                  SetResistance(DT_ACID,  100);

  SetStatBonus (P_CON,5);
  SetStatBonus (P_DEX,5);
  SetStatBonus (P_INT,5);
  SetStatBonus (P_STR,5);
    SetStatBonus("Cha",5);
      SetStatBonus(P_WIS,5);

}