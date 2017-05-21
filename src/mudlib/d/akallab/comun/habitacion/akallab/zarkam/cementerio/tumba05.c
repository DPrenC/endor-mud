/*
DESCRIPCION  : cementerio de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/cementerio/tumba05.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
	19-07-03 [Theuzifan] Arreglado el bug reportado por sorgin: salidas
		incorrectas.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_CEMENTERIO("cementerio");

create() {
  lugar="Zarkam";
  abierta=1;
  amedida=0;

  ::create();
  AddExit("oeste",Z_CEMENTERIO("tumba08"));
  AddExit("este",Z_CEMENTERIO("tumba02"));
  AddExit("sur",Z_CEMENTERIO("tumba04"));
  AddExit("abajo",Z_CEMENTERIO("fosa05"));
}

