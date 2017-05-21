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
SetStandard("bandido","orco",([GC_LUCHADOR: 22+random(5)]),GENERO_MASCULINO);
SetShort("un bandido orco");
SetLong(W("Es un bandido orco. Lleva los ropajes negros típicos de la profesión. "
"Parece dispuesto a atacarte en cualquier momento.\n"));
SetIds(({"orco","bandido"}));
SetAggressive(1);
SetAlign(-200);
SetSize(P_SIZE_MEDIUM);
InitChats(3,"El bandido te enseña sus afilados dientes.\n");
AddItem(ARMA("daga2"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("daga2"),REFRESH_REMOVE,SF(wieldme));
}

