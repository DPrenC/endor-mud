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
SetStandard("un sargento","humano",([GC_LUCHADOR: 25+random(5)]),GENERO_MASCULINO);
SetShort("un sargento");
SetLong(W("Es un sargento de la banda que habita esta fortaleza. La rígida jerarquía "
"se ha acabado imponiendo en esta enorme banda. El sargento parece haber vivido bastantes "
"escaramuzas a lo largo de su vida.\n"));
SetIds(({"humano","sargento"}));
SetAggressive(0);
SetAlign(-50);
SetSize(P_SIZE_MEDIUM);
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
}

