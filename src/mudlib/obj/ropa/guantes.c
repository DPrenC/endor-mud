/*unos guantes, parte del equipo básipo  del mud.*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
    SetStandard(AT_GUANTES, 0, P_SIZE_GENERIC, M_CUERO);
SetShort("unos guantes de cuero");
SetLong(
"Son unos guantes de cuero fino y blando que se ajustan perfectamente a las manos y las "
"cubre hasta la muñeca.\n"
"Formados por dos piezas de cuero cosidas, son muy utilizados para proteger las manos en "
"la realización de trabajos manuales o en el manejo de armas y herramientas.\n");
SetIds(({"guantes","ropa", "guantes de cuero"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_PLURAL);

}