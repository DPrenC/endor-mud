/*
DESCRIPCION : mercenario (clavaito al de Maler)
FICHERO     : mercenario.c
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
SetStandard("un mercenario","humano",([GC_LUCHADOR: 26+random(5)]),GENERO_MASCULINO);
SetShort("un mercenario");
SetLong(("Es un mercenario humano. Su rostro esta enmarcado por un increíble "
"número de profundas cicatrices. Viste ropas amplias que no impiden sus movimientos, "
"y parece un luchador difícil en combate.\n"));
SetIds(({"humano","mercenario"}));
SetAggressive(0);
SetAlign(-50);
SetSize(P_SIZE_MEDIUM);
SetAC(10);
InitChats(3,"El mercenario te mira y dice: 'Mmmm no te reconozco'.\n");
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
}