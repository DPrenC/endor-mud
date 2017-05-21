/*
DESCRIPCION : aventurero (clavaito al de Maler)
FICHERO     : aventurero.c
MODIFICACION: 11-06-01 [Tirdos] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <rooms.h>
#include <gremios.h>

inherit NPC;

create ()
{
  ::create();
seteuid(getuid());
SetStandard("un aventurero","humano",([GC_AVENTURERO: 27+random(5)]),GENERO_MASCULINO);
SetShort("un aventurero");
SetLong(("Es un intrepido aventurero, su rostro esta curtido por el sol, sin duda"
"seria un buen compañero de viaje, de complexión fuerte su mirada penetrante te"
"indica que el peligro no le provoca temor.\n"));
SetIds(({"humano","aventurero"}));
SetAggressive(0);
SetAlign(75);
SetSize(P_SIZE_MEDIUM);
SetAC(12);
InitChats(3,"El aventurero canta: 'Un intrepido aventurero soy... viajando por el mundo voy... lalala'.\n");
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
}