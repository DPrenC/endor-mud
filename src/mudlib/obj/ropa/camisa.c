/*una camisa, parte del equipo b�sico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
SetShort("una camisa");
SetLong(
"Es una prenda que cubre la parte superior del tronco, de tela vasta y sin te�ir y de manga "
"larga hasta la mu�eca.\n"
"Una serie de simples botones de cobre permiten que la prenda se cierre por delante, "
"as� como en la parte baja de las mangas.\n"
"No presta gran protecci�n contra el fr�o puesto que suele llevarse con otra prenda m�s "
"abrigada encima.\n");
SetIds(({"camisa","ropa"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}