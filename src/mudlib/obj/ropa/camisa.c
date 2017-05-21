/*una camisa, parte del equipo básico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
SetShort("una camisa");
SetLong(
"Es una prenda que cubre la parte superior del tronco, de tela vasta y sin teñir y de manga "
"larga hasta la muñeca.\n"
"Una serie de simples botones de cobre permiten que la prenda se cierre por delante, "
"así como en la parte baja de las mangas.\n"
"No presta gran protección contra el frío puesto que suele llevarse con otra prenda más "
"abrigada encima.\n");
SetIds(({"camisa","ropa"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}