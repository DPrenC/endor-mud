/*unos brazales de cuero, parte del equipo básico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_BRAZALES, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("unos brazales de cuero");
SetLong(
"Son unos ligeros brazales de cuero curtido y sin teñir, formados por largas secciones "
"de cuero que van del codo a la muñeca, con el extremo que apunta al codo en forma "
"triangular para proteger la articulación y unas correas, también de cuero, que "
"mediante unas hebillas los ajustan al brazo e impiden que resbalen.\n"
"Son utilizados por aventureros y exploradores por su ligereza y por brindar una "
"cierta protección contra rasguños, cortes o golpes livianos.\n");
SetIds(({"brazales","ropa", "BRAZALES de cuero", "cuero"}));
SetAds(({"de", "cuero"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_MALE);
}