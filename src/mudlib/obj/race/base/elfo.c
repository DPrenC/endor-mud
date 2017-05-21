/*
DESCRIPCION  : un elfo
FICHERO      : /obj/race/base/elfo.c
BASADO       : /obj/race/base/elf.c [randyandy@nightfall] [cadra@nightfall]
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
  SetMaxFood(100);
  SetMaxDrink(100);
  SetMaxAlcohol(80);
  SetWeight(65000);
  SetSize(P_SIZE_MEDIUM);

  AddHand("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus (P_CON,-3);
  SetStatBonus (P_DEX,1);
  SetStatBonus (P_INT,6);
  SetStatBonus (P_STR,-4);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(2 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ elf@@suf@@ alt@@suf@@. @@Nombre@@ es más bien bell@@suf@@. Su cara\n\
es palida y parece aristocratica. Los ojos son diferentes de cualesquiera otros\n\
que alguna vez hayas visto. Te parecen sabios, aunque un poco arrogantes y\n\
parecen ver todo lo que sientes. Percibes una sensacion extraña.\n");
  SetRaceDescription(
"Los Elfos o Primeros Nacidos despertaron en la noche de los tiempos al este de la "
"Tierra Media, junto a las aguas de Cuivienen.\n"
"Fue la primera raza de criaturas parlantes en aparecer, de ahí que se llamen así mismos "
"Quendi, los que hablan con voces.\n"
"En un principio se dividían en tres estirpes: Vanyar, Noldor y Teleri.\n"
	"Estos pueblos dieron a su vez origen a muchas otras subdivisiones a lo largo de su "
	"dilatada historia.\n"
	"Algunos de sus pueblos emigraron a Valinor y crecieron en poder y sabiduría junto a "
	"los Valar, mientras que otros permanecieron en la Tierra Media.\n"
	"Los Elfos son criaturas inmortales e intemporales, mueren solo por heridas muy graves, "
	"por cansancio del mundo o de pena, son inmunes a las enfermedades y más resistentes "
	"a las temperaturas extremas que los humanos.\n"
	"Indenpedientemente de su estirpe, son criaturas de alta estatura, grácil esbeltez y "
	"belleza sobrehumanas, y los Hombres los han temido, reverenciado, amado y envidiado "
	"en distintas proporciones a lo largo del tiempo.\n"
	"Son extremadamente ágiles, sigilosos, están en comunión con la naturaleza de una "
	"forma mucho más pronunciada que cualquier otra raza y su vista y oído no tienen "
	"parangón. Aún así, a fines de la Tercera Edad son una raza muy menguada,en franco "
	"declive, viven en refugios o hierran por el mundo sumidos en la melancolía, y se "
	"mezclan poco en los asuntos de las otras razas.\n"
	"Cada día son más los que parten hacia el Oeste, abandonando la Tierra Media para "
	"nunca más regresar.\n"
	"Actualmente existen tres estirpes de Elfos en la Tierra Media: "
	"Noldor, Sindar y Elfos Silvanos.\n");
		
		}