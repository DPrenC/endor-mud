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
SetStandard("un perro","perro",([GC_LUCHADOR: 20+random(5)]),GENERO_MASCULINO);
SetShort("un perro de combate");
SetLong(W("Es un inmenso perro negro. Su boca esta abierta, y su lengua se balancea "
"dejando ver dos hileras de afilados dientes blancos. Parece dispuesto a atacar.\n"));
SetIds(({"perro","perro de combate"}));
SetAggressive(1);
SetInt(QueryInt()-9);
SetDex(QueryDex()+9);
SetAlign(0);
SetSize(P_SIZE_MEDIUM);
InitChats(3,"El perro ladra.\n");
SetHands(({({"boca",0,6})}));
}

