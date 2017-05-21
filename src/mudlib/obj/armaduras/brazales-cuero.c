/*unos brazales de cuero, parte del equipo b�sico de Endor*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_BRAZALES, 1, P_SIZE_GENERIC, M_CUERO);
    SetShort("unos brazales de cuero");
SetLong(
"Son unos ligeros brazales de cuero curtido y sin te�ir, formados por largas secciones "
"de cuero que van del codo a la mu�eca, con el extremo que apunta al codo en forma "
"triangular para proteger la articulaci�n y unas correas, tambi�n de cuero, que "
"mediante unas hebillas los ajustan al brazo e impiden que resbalen.\n"
"Son utilizados por aventureros y exploradores por su ligereza y por brindar una "
"cierta protecci�n contra rasgu�os, cortes o golpes livianos.\n");
SetIds(({"brazales","ropa", "BRAZALES de cuero", "cuero"}));
SetAds(({"de", "cuero"}));
Set(P_NUMBER,NUMBER_PLURAL);
Set(P_GENDER,GENDER_MALE);
}