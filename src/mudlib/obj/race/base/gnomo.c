/*
DESCRIPCION  : un gnomo
FICHERO      : /obj/race/base/gnomo.c
BASADO       : /obj/race/base/gnome.c [suamor@nightfall]
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
  SetAlign(50);
  SetMaxFood(80);
  SetMaxDrink(80);
  SetMaxAlcohol(110);
  SetWeight(30000);
  SetSize(P_SIZE_SMALL);

  AddHand("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,0);
  SetStatBonus(P_DEX,5);
  SetStatBonus(P_INT,3);
  SetStatBonus(P_STR,-8);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(2 * MAX_SUNBRIGHT);
  SetLong(
    "@@Nombre@@ es @@ind@@ gnom@@suf@@. Su cuerpo es liviano y tiene la\n"
    "piel tostada por el sol. A pesar de su pequeño tamaño sus ojos parecen\n"
    "brillar todo el tiempo que los miras. Sobre la cabeza lleva un gracioso\n"
    "sombrero cónico de color rojo.\n");
  SetRaceDescription(
"Los gnomos son pequenyas criaturas, algo mayores que los duendes, pero mucho\n\
menores que los enanos. Son seres inteligentes y habiles, pero por contra\n\
no son muy fuertes. Su caracter es tolerante y abierto. Les desagrada la\n\
violencia y no suelen luchar.\n\
La Naturaleza tiene pocos secretos para ellos, por lo que son buenos\n\
preparando todo tipo de pociones y unguentos. Son habiles curanderos y\n\
medicos. Tienen una gran relacion con los animales salvajes, y algunos de\n\
ellos les sirven como medio de transporte. Este hecho les ha convertido en\n\
excelentes mensajeros: no hay lugar en el mundo al que no pueda llegar un\n\
gnomo a montado sobre un ganso o un lobo.\n\
Aunque no estan tan dotados para la magia como los duendes, saben usarla.\n\
Su magia esta basada en la esencia de la Naturaleza.\n\
Suelen vivir bajo tierra, o en pequenyas casas construidas en las raices de\n\
los arboles de los bosques.\n\
");
}
