/*unas botas, parte del equipo b�sipo  del mud.*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_GENERIC, M_CUERO);
SetShort("unas botas de cuero");
SetLong(
"Son unas botas de cuero curtido pero sin te�ir, cuya  sencilla ca�a est� realizada con "
"un rect�ngulo de cuero cerrado con una poco discreta costura. La suela elaborada con "
"varias l�minas,  protege la planta del pie de los accidentes del terreno.\n"
"Gruesos cordones del mismo material, permiten ajustar la ca�a a la pantorrilla "
"con una serie de lazadas.\n");
SetIds(({"botas","ropa", "botas de cuero"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_PLURAL);

}