/*unas botas, parte del equipo básipo  del mud.*/
#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_GENERIC, M_CUERO);
SetShort("unas botas de cuero");
SetLong(
"Son unas botas de cuero curtido pero sin teñir, cuya  sencilla caña está realizada con "
"un rectángulo de cuero cerrado con una poco discreta costura. La suela elaborada con "
"varias láminas,  protege la planta del pie de los accidentes del terreno.\n"
"Gruesos cordones del mismo material, permiten ajustar la caña a la pantorrilla "
"con una serie de lazadas.\n");
SetIds(({"botas","ropa", "botas de cuero"}));
SetAds(({"de","cuero"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_PLURAL);

}