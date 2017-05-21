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
SetStandard("un soldado","humano",([GC_LUCHADOR: 23+random(3)]),GENERO_MASCULINO);
SetShort("un soldado");
SetLong(W("Es un soldado de la banda que habita esta fortaleza. La rígida jerarquía "
"se ha acabado imponiendo en esta enorme banda. Este soldado parece inexperto, perteneciendo "
"al escalón más bajo de la organización.\n"));
SetIds(({"humano","soldado"}));
SetAggressive(0);
SetAlign(-50);
SetSize(P_SIZE_MEDIUM);
InitChats(3,"El soldado dice: Que día más aburrido.\n");
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
}

