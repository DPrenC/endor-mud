/*
DESCRIPCION  : un wose, hombres salvajes del bosque, especie de pigmeos
FICHERO      : /obj/race/base/wose.c
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

  SetAlign  (0);
 SetBando(P_BANDO_NEUTRO);
 
  SetMaxFood   (60);
  SetMaxDrink  (110);
  SetMaxAlcohol    (20);
  SetSize(P_SIZE_MEDIUM);

  SetWeight (70000);
  AddHand   ("pesada mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("pesada mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 2);
  SetStatBonus   (P_INT, -1);
  SetStatBonus   (P_STR, 0);
    SetStatBonus   ("Cha", -2);
      SetStatBonus   (P_WIS, 1);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Wose, @@ind@@ primitiv@@suf@@ habitante de los bosques.\n"
"@@Nombre@@ no llega al metro y medio de altura y pesar� unos setenta kilos.\n"
"Su cuerpo, cubierto por una �spera piel rojiza,  es rechoncho, achaparrado y compacto, "
"de brazos nervudos, pesado est�mago y piernas cortas y robustas.\n"
"Su gran rostro de facciones chatas, posee una boca amplia bajo una nariz grande, muy "
"diestra en olfatear criaturas a gran distancia.\n"
"@@Nombre@@ es calv@@suf@@ escepto por unos largos mechones de pelo negro trenzado que le "
"crecen en los lados y la parte posterior de su rechoncho cr�neo.\n"
"Bajo su abultado entrecejo, sus negros ojos son como pozos oscuros en los que solo "
"acerc�ndose se puede apreciar alg�n leve movimiento, aunque cuando @@Nombre@@ se "
"enfurece sus pupilas arden con col�rico rojizo resplandor.\n");

  SetRaceDescription(
  "Los Woses son una antigua y casi desaparecida estirpe de hombres que actualmente "
  "solo sobreviven en algunos rec�nditos lugares de la Tierra Media como en el Pa�s del "
  "Viejo P�k�l o en el Bosque de Dr�adan.\n"
  "Son hombres bajos, achaparrados, de gruesos brazos y piernas, vientres abultados, y "
  "cabezas habitualmente calvas, con rostros anchos, grandes entrecejos y narices "
  "achatadas y ojos oscuros albergados en profundas cuencas oculares.\n"
  "Rara vez les sale barba y cuando esto ocurre es se�al de gran orgullo y respeto.\n"
  "Considerados primitivos y repulsivos por otras razas y el resto de Hombres,  quienes "
  "llegan a tenerlos por aliados descubren su inquebrantable lealtad y amistad.\n"
  "Son un pueblo primitivo, que lleva una vida r�stica en los bosques y colinas, "
  "viviendo de la caza la pesca y la recolecci�n y conviviendo en perfecta armon�a con "
  "la naturaleza.\n"
  "Sus armas, utensilios y vestimentas est�n hechos de madera, piedra, hueso y pieles "
  "y no usan ni conocen los metales.\n"
  "Su olfato est� muy desarrollado, de forma  que pueden detectar  e identificar a una "
  "criatura a gran distancia e incluso pronosticar los cambios clim�ticos.\n"
  "Son excelentes cazadores, rastreadores ,exploradores, y son grandes curanderos y "
  "maestros en el uso de hierbas y pociones.\n"
);
}

