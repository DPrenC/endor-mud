/* Herrería estándar de Lad Laurelin
   [t] Theuzifan

   31-03-99 [t] Creación. La tienda está cerrada por la noche por defecto.
*/
	
#include "path.h"
#include "/secure/wizlevels.h"
#include <nightday.h>

inherit DOM_STD+"hab_horario";
inherit PUB;

create()
{
  ::create();
  SetIntLong("Estás en una tienda de Lad Laurelin.\n");
  SetIntShort("una tienda");
  SetLocate("Lad Laurelin");
  SetCommerceOpenTime(ND_SUNRISE);
  SetCommerceCloseTime(ND_PRENIGHT);
  SetClosedShopString("La tienda está cerrada.\n");
}


