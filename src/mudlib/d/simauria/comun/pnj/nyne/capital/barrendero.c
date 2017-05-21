/*
DESCRIPCION : Barrendero de Simauria
FICHERO     : barrendero.c
MODIFICACION: 10-06-01 [Tirdos] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit NPC;
#include <properties.h>
#include <rooms.h>
#include <combat.h>
create() {
::create();
SetStandard("Barrendero","humano",20+random(5),GENERO_MASCULINO);
SetShort("Un barrendero");
SetLong(W("Es un simple barrendero y su mision es mantener limpia la ciudad, aunque no "
"parece que tenga mucho exito en su empeño.\n"));
SetIds(({"humano","barrendero","barrendero humano"}));
InitChats(5,({"El barrendero dice: Cuanta porqueria por el suelo.\n",
"El barrendero exclama: Necesito vaciones!\n",
"El barrendero te mira y dice: No vayas dejando cosas de tus victimas por ahi\n"}) );
SetAggressive(0);
SetAlign(100);
SetAC(10);
//AddItem(ARMA("escoba"),REFRESH_REMOVE,SF(wieldme));
}