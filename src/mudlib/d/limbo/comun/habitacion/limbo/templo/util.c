/*
DESCRIPCION  : Seccion de cosas utiles en el edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/util.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

// NOTA: La ropas son protecciones que adornan mas que proteger

#include "./path.h"
inherit TEMPLO("suministros");

create() {
  tipo="cosas utiles";
  path="";
  productos=(({"antorcha","cuerda", "gafas", "encendedor", "aceite"}));
  prod_fich=(({"/obj/torch","/obj/cuerda", "/obj/sunglasses", "/obj/lighter", "/obj/oil_bottle"}));
  ::create();
  AddExit("norte",TEMPLO("ropa"));
  AddExit("sur",TEMPLO("otras"));
  AddExit("este",TEMPLO("proteccion"));
}
