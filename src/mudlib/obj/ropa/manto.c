/*un manto, parte del equipo b�sico de Endor*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_MANTO, 0, P_SIZE_GENERIC, M_TELA);
SetShort("un manto");
SetLong(
"Es una prenda de gruesa tela vasta y sin te�ir que cuelga de los hombros cubriendo "
"parte del pecho y los brazos, cayendo hasta los tobillos por detr�s.\n"
"M�s amplio y pesado que la capa, puede proteger mejor del fr�o y tener diversas "
"utilidades para cualquier aventurero, como oficiar de refugio o de lecho.\n");
SetIds(({"manto","ropa"}));
SetAds(({"de","tela"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}