/* un vestido sencillo, parte del equipo básico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("un vestido");
SetLong("Es un vestido de tela sin teñir, amplio, de manga larga y que llega hasta los "
"tobillos y que no muestra ningún adorno ni bordado.\n"
"Es una prenda típicamente utilizada por las mujeres de muchas culturas y latitudes.\n");
SetIds(({"vestido","ropa"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}