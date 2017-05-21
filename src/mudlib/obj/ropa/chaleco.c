/* un chaleco, parte del equipo básico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TABARDO, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("un chaleco");
SetLong(
"Es una prenda exterior de tela vasta y sin teñir, ajustada al tronco, que llega hasta "
"la cintura y está desprovista de mangas.\n"
"Unos botones de estaño permiten cerrar la prenda en su parte delantera, junto a un par "
"de grandes bolsillos.\n"
"Suele llevarse sobre una camisa y al no llevar mangas permite gran libertad de "
"movimientos, aunque ofrece una protección muy deficiente ante el frío.\n");
SetIds(({"chaleco","ropa"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}