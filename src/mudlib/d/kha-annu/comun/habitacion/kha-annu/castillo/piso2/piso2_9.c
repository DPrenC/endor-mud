/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Fran@Simauria modificandorrrr	
 *   Ultima modificacion: 26 Sep, 2000.
 */

#include "path.h"
inherit KHA_ROOM;

create() {
  ::create();
  SetIntShort("el segundo piso del castillo Kha-annu");
  SetIntLong(
"Este es el segundo piso del castillo, justamente la parte mas hacia el oeste "
"del Castillo Kha-annu. A tu alrededor ves lujuria por doquier... el suelo "
"esta hecho de marmol, las paredes retocadas con finas lineas de oro y mithril "
"y unas hermosas lamparas de diamante cuelgan del techo por todo este piso "
"a lo largo de cada uno de los corredores.\n");
  SetIntBright(80);

  AddExit("norte",PISO2+"piso2_8");
  AddExit("abajo",PISO1+"stair2");
AddDetail( ({"lampara","lamparas"}),
"Ves lamparas de diamante que cuelgan del techo y que despiden una luz "
"azulada.\n");

   AddDetail(({"paredes","pared",}),
"Al fijarte bien notas que las paredes, realmente, estan hechas de oro!\n");
  AddDetail("suelo","Puedes ver el reflejo de las lamparas sobre el suelo\n");

  AddItem(MONS+"guardia",REFRESH_DESTRUCT,1);
}