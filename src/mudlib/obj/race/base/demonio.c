/*
DESCRIPCION  : un demonio
FICHERO      : /obj/race/base/demonio.c
BASADO       : /obj/race/base/demon.c [wurzel@nightfall] [matesse@nightfall]
--------------------------------------------------------------------------------
*/

#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <races.h>
#include <combat.h>
#include <properties.h>
inherit "/obj/raceobj";

create_blueprint()
{
  ::create_blueprint();
  SetAlign  (-500);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (10);
  SetWeight (80000);
  SetSize(P_SIZE_MEDIUM);

  AddHand("garra derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("garra izquierda", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("cola", DT_FIRE, 2); /* algo que los haga unicos */

  SetStatBonus(P_CON, -3);
  SetStatBonus(P_DEX,  3);
  SetStatBonus(P_INT,  3);
  SetStatBonus(P_STR, -3);
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetLong("\
@@Nombre@@ es @@ind@@ demonio. Su cuerpo brilla con un color rojo oscuro\n\
incandescente. La cola larga con garras que nace de su espalda ondea libre\n\
al viento.\n");
  SetRaceDescription ("\
Los demonios son maldad pura y no adulterada. Sus cuerpos estan formados con la\n\
esencia misma de las llamas del infierno. Utilizan los poderes de los dioses\n\
para obtener asi un cuerpo material que envuelva sus almas. Son seres fieros y\n\
agresivos que luchan viciosamente con sus mortiferas garras y su cola prensil.\n\
En general desprecian la luz del sol como parte de su maldicion.\n\
Son seres habiles que ademas dominan magia poderosa. Suelen emplear una gran\n\
variedad de hechizos, casi siempre de origen maligno. Por contra son mas\n\
debiles y menos resitentes que otras razas de este mundo.\n\
Son de naturaleza solitaria, por lo que suelen merodear por lugares apartados\n\
del mundo como las cuevas, los acantilados o las llanuras heladas del norte.\n\
Fueron los mas seducidos por los dioses rebeldes durante la Epoca Oscura de\n\
Simauria. Aun se recuerda su derrota y poseen un innato deseo de venganza.\n");
}
