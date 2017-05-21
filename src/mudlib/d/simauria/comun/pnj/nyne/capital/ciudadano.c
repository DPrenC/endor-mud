/*
DESCRIPCION : ciudadano
FICHERO     : ciudadano.c
MODIFICACION: 11-06-01 [Tirdos] Creacion
--------------------------------------------------------------------------------
*/
inherit NPC;
#include <properties.h>
#include <combat.h>
#include <rooms.h>
#include "./path.h"
create ()
{
  ::create();
seteuid(getuid());
SetStandard("un ciudadano","humano",20+random(5),GENERO_MASCULINO);
SetShort("un ciudadano");
SetLong(W("Es uno de los habitantes de la capital, va bien vestido y parece que "
"mire con cierto desden a todos los extranjeros que se cruzan en su camino. No "
"parece demasiado fuerte.\n"));
SetIds(({"humano","ciudadano"}));
SetAggressive(0);
SetAlign(50);
SetSize(P_SIZE_MEDIUM);
SetAC(10);
InitChats(3,"El ciudadano dice: Bienvenido extranjero.\n");
AddItem(ARMA("daga"),REFRESH_REMOVE,SF(wieldme));
}