/* azadon_guerra.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_AZADON,9,P_SIZE_GENERIC,M_HIERRO);
 SetShort("un azadón de guerra");
SetAds(({"pesado"}));
 SetIds(({"azadon","azadón", "azadón de guerra", "arma"}));
 SetLong(
 "El azadón de guerra está compuesto por un grueso mango de algo más de un metro de "
 "longitud, rematado por una cabeza de azadón triangular más gruesa, ancha y pesada de lo "
 "habituál, con una corta punta rematando el mango para punzar al oponente y otra en el "
 "reverso de la hoja, con forma curva para poder enganchar la armadura del oponente, "
 "herirlo o derribarlo.\n"
 "El azadón de guerra es un arma pesada y difícil de manejar, de golpes lentos pero "
 "demoledores. Es una de las armas favoritas de los enanos.\n");
}