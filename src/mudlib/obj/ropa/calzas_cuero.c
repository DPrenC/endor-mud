/*Unas calzas de cuero, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PANTALONES, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("unas calzas  de cuero blando");
SetLong(
"Es una prenda que cubre pies, piernas y llega hasta la cintura, fabricada con cuero "
"blando, curtido pero sin teñir.\n"
"Es una prenda formada por dos piezas, una para cada pierna, unidas en la entrepierna "
"por un conjunto de prietas cintas de cuero que se sujetan en una serie de ojales "
"remachados en cobre que jalonan el borde de la otra pieza.\n"
"Unas bandas del mismo material, cosidas con hilo marrón refuerzan las costuras 
"
"externas, y la parte en la que encaja el pie va forrada de una capa extra de cuero por "
"fuera, y de  lana por dentro para que el pie se encuentre confortable.\n"
"Es una prenda resistente, que protege bien del calor y el frío, utilizada por "
"aventureros, viajeros y guerreros por igual, pues resulta ideal para largos y azarosos viajes.\n");
SetIds(({"calzas","ropa", "calza", "calzas de cuero", "cuero"}));
SetAds(({"vastas", "curtidas", "blando", "de cuero"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_FEMALE);
}