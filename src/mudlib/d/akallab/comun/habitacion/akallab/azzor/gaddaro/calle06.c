/*
DESCRIPCION  : Frente al pueblo de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/calle06.c
MODIFICACION : 18-02-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

#define DESTINO BOSQUE_MORAK("camino00")
#include FILTRO_PNJ_ZONA
//#define MARCA_PNJ_ZONA "pnj_zona"

create() {
  ::create();
 SetIntShort("las afueras del pueblo de Gaddaro");
  SetIntLong(
  "Estas a las afueras del pequeño pueblo de Gaddaro que se halla al oeste "
  "de aqui. Este camino de tierra conduce desde el hacia el cercano bosque "
  "de Morak, donde los habitantes del pueblo suelen proverse de madera. "
  "Del norte baja una fresca brisa desde la cercana cordillera de Kova.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("nordeste",SF(FiltroPnjZona));
 //AddExit("nordeste",BOSQUE_MORAK("camino00"));
 AddExit("oeste",GADDARO("calle03"));
}
