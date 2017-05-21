/*Una t�nica, parte del equipo b�sico de Endor*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
    SetShort("una t�nica");
SetLong(
"Es una prenda de tela gruesa, vasta y sin te�ir, que en forma holgada cubre el tronco y"
" las piernas hasta la rodilla.\n"
"Sus mangas son anchas y llegan hasta el codo.\n"
"Es utilizada como prenda exterior por ambos sexos, sobretodo en climas m�s c�lidos.\n");
SetIds(({"t�nica","ropa", "tunica"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_PLURAL);

}