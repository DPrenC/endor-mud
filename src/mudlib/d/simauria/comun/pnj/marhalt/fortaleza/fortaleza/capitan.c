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
#include <gremios.h>
#include <combat.h>

inherit NPC;


create ()
{
  ::create();
seteuid(getuid());
SetStandard("un capit�n","humano",([GC_LUCHADOR: 30+random(5)]),GENERO_MASCULINO);
SetShort("un capit�n");
SetLong(W("Es un capit�n de la banda que habita esta fortaleza. La r�gida jerarqu�a "
"se ha acabado imponiendo en esta enorme banda. El capit�n posee una mirada de inteligencia "
"que te intranquiliza.\n"));
SetIds(({"humano","bandido","capitan","capit�n"}));
SetAggressive(1);
SetAlign(-50);
SetSize(P_SIZE_MEDIUM);
AddItem(ARMA("espada2"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("espada2"),REFRESH_REMOVE,SF(wieldme));
}

