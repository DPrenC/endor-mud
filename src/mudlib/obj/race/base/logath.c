/*
DESCRIPCION  : un logath
FICHERO      : /obj/race/base/logath.c
BASADO       : Libremente inspirado en la raza beornida de el juego de rol del
               senyor de los anillos, cheewabaka el woocky y el yeti. Podria
               decirse que son unos hominidos altos, delgados y peludos. Dada
               su gran habilidad y su curiosidad innata (herencia primate) son
               buenos exploradores. Es por ellos que se han convertido en los
               mejores marinos de Simauria
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
  SetAlign  (0);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (100);
  SetWeight (95000);

  SetSize(P_SIZE_MEDIUM);
  AddHand("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON, -2);   /* constiticion algo floja*/
  SetStatBonus(P_DEX,  2);   /* Muy agiles */
  SetStatBonus(P_INT,  2);       /* no son tontos */
  SetStatBonus(P_STR, -2);       /* no demasiado fuertes */
  SetIVision(-REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetUVision(REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetLong   (
    "@@Nombre@@ es @@ind@@ logath. Su cuerpo es más alto, delgado y ágil que el de\n"
    "un humano. @@Pron@@ tiene todo el cuerpo cubierto de un pelo largo y liso, de\n"
    "forma que te recuerda a un primate. Parece un individuo muy curioso ya\n"
    "que continuamente mira a su alrededor, analizando lo que le rodea.\n");

  SetRaceDescription (
"Los logath son unas criaturas antropomorfas que fisicamente se parecen a\n\
los primates. Si se los compara con un hombre, los logath son algo mas altos,\n\
mas delgados y mas agiles que aquel. Su cabeza recuerda a la de un simio y todo\n\
su cuerpo esta recubierto de un denso y largo pelaje liso, generalmente rojizo\n\
o marron. Para alguien que no sea de su raza es dificil distinguir entre ellos,\n\
ya que fisicamente son bastante parecidos. Sus manos son muy habiles.\n\
Aunque en general no suelen usar magia, tienen habilidad para ello y algunos\n\
de ellos dominan la magia basada en la naturaleza. Son capaces de ver en la\n\
oscuridad. Son muy curiosos, por lo que son grandes exploradores y marinos.\n\
Socialmente se organizan el clanes matriarcales dirigidos por un consejo de\n\
ancianos. Cada individuo lleva encima, prendido en el pelo, una serie de\n\
adornos que representan el totem de su clan y muestran su pertenencia a el.\n\
Existe un odio intenso entre los logath y sus vecinos los gigantes desde\n\
tiempos inmemoriales, debido a los continuas incursiones de los gigantes.\n\
\n");
}

