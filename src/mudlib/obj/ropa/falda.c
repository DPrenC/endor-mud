/*Una falda, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_PANTALONES, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("una falda");
SetLong(
"Una falda larga de tela vasta y color indefinido, con amplio vuelo y que llega "
"hasta los tobillos.\n"
"Prenda típicamente femenina, es utilizada por las mujeres de muchas culturas y latitudes.\n");
SetIds(({"falda","ropa"}));
SetAds(({"larga","vasta"}));
Set(P_NUMBER,NUMBER_SINGULAR);
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}