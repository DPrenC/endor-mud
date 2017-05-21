/*
DESCRIPCION  : Seccion de magia en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/magia.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               10-10-99 [woo] Toqueteado...
--------------------------------------------------------------------------------
*/

// NOTA: A rellenar cuando se implemente la magia

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="magia";
  ::create();
  AddExit("norte",TEMPLO("bebida"));
  AddExit("sur",TEMPLO("proteccion"));
  AddExit("este",TEMPLO("entrada_sum"));
  AddExit("oeste",TEMPLO("ropa"));
}
