/*Una blusa, parte del equipo básico de Endor*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("una blusa");
SetLong(
"Es una prenda para la parte superior del cuerpo, con mangas hasta el codo y fabricada "
"en tela vasta y sin teñir, utilizada habitualmente por las mujeres.\n");
SetIds(({"blusa","ropa"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);

}