/*Una túnica, parte del equipo básico de Endor*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("una túnica");
SetLong(
"Es una prenda de tela gruesa, vasta y sin teñir, que en forma holgada cubre el tronco y"
" las piernas hasta la rodilla.\n"
"Sus mangas son anchas y llegan hasta el codo.\n"
"Es utilizada como prenda exterior por ambos sexos, sobretodo en climas más cálidos.\n");
SetIds(({"túnica","ropa", "tunica"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_PLURAL);

}