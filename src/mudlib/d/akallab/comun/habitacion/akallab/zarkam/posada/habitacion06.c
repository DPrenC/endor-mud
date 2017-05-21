/*
DESCRIPCION : habitacion de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/habitacion06.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_POSADA("habitacion");

create() {
  nom_posada="'el Cuervo Blanco'";
  tipo=1;
  huesped=1;
  vista="";

  ::create();

  AddExit("norte",Z_POSADA("pasillo01"));
}
