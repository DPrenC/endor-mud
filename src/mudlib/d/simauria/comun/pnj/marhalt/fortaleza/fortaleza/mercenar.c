/*=============================================================*
 |             << Fortaleza:Simauria [m] Maler >> 		       |
 *=============================================================*
 |               Creacion............. 03-07-00                |
 |               Ultima Modificacion.. 03-07-00                |
 |                                                             |
 |															   |
 *=============================================================*/
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <gremios.h>

inherit NPC;


create ()
{
  ::create();
seteuid(getuid());
SetStandard("un mercenario","humano",([GC_LUCHADOR: 24+random(5)]),GENERO_MASCULINO);
SetShort("un mercenario");
SetLong(W("Es un mercenario humano. Su rostro esta enmarcado por un increíble "
"número de profundas cicatrices. Viste ropas amplias que no impiden sus movimientos, "
"y parece un luchador difícil en combate.\n"));
SetIds(({"humano","mercenario"}));
SetAggressive(1);
SetAlign(-50);
SetSize(P_SIZE_MEDIUM);
InitChats(3,"El mercenario te mira y dice: 'Mmmm no te reconozco'.\n");
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
}

