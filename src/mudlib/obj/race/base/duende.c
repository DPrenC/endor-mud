/*
DESCRIPCION  : un duende
FICHERO      : /obj/race/base/duende.c
BASADO       : Los duendes son unos seres diminutos (aprox 10-20 cm) fisicamente
               parecidos a los gnomos. Como guerreros no tienen nada que hacer,
               pero la magia es tan natural para ellos como el respirar. Son
               unos maestros de las ilusiones. Son burlones y escurridizos, asi
               que pobre de aquel a quien decidan marear.
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
  SetAlign(0); /* ni buenos ni malos, cachondos */
  SetMaxFood(50); /* no necesitan demasiado */
  SetMaxDrink(50);
  SetMaxAlcohol(100); /* pero aguantan la bebida */
  SetWeight(1000); /* realmente pequenyos */
  SetSize(P_SIZE_SMALL);

  AddHand("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,0); /* constitucion normal */
  SetStatBonus(P_DEX,6); /* muy escurridizos */
  SetStatBonus(P_INT,8); /* magia, si gracias */
  SetStatBonus(P_STR,-14); /* mejor no intentar luchar cuerpo a cuerpo */
  SetIVision(-(MAX_SUNBRIGHT / 2));
  SetUVision(MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ duende. Su cuerpo es diminuto. Te observa con un gesto\n\
burlón en su cara y sus ojillos centellean. Unas pequenyas chispas luminosas\n\
revolotean alrededor de su cuerpo. La magia se siente en el ambiente.\n");
  SetRaceDescription(
"Los duendes son seres diminutos que rara vez alcanzan los 10 o 20 cm de\n\
altura. Son seres antropomorfos aunque su cuerpo es muy delgado si se compara\n\
con las proporciones de un humano. Poseen una larga y afilada nariz y unas\n\
orejas puntiagudas. Algunos de ellos tienen dos pequenyos cuernos sobre su\n\
cabeza y una delgada cola. Suelen usar ropa muy gastada o hecha con retales.\n\
Dado su tamanyo y su escasa fuerza fisica, hace que no tengan nada que hacer\n\
como guerreros, pero dada su gran agilidad, hace que sea muy dificil\n\
alcanzarles. El uso de la magia es tan natural para ellos como el\n\
respirar. Son unos maestros de las ilusiones. Aquel que desee conocer los\n\
profundos secretos de la magia deberia aprender de estos seres.\n\
Viven en bosques fantasticos en los que todo esta empapado de magia. Son un\n\
lugar en el cual quien no posea dominio de la magia no deberia adentrarse, ya\n\
que dado el caracter burlon y escurridizo de estos seres puede ser mareado en\n\
ellos y pasar un mal rato.\n");
}
