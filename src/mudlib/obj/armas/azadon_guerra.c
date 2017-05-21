/* azadon_guerra.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_AZADON,9,P_SIZE_GENERIC,M_HIERRO);
 SetShort("un azad�n de guerra");
SetAds(({"pesado"}));
 SetIds(({"azadon","azad�n", "azad�n de guerra", "arma"}));
 SetLong(
 "El azad�n de guerra est� compuesto por un grueso mango de algo m�s de un metro de "
 "longitud, rematado por una cabeza de azad�n triangular m�s gruesa, ancha y pesada de lo "
 "habitu�l, con una corta punta rematando el mango para punzar al oponente y otra en el "
 "reverso de la hoja, con forma curva para poder enganchar la armadura del oponente, "
 "herirlo o derribarlo.\n"
 "El azad�n de guerra es un arma pesada y dif�cil de manejar, de golpes lentos pero "
 "demoledores. Es una de las armas favoritas de los enanos.\n");
}