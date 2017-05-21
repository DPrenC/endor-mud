/*
DESCRIPCION : habitacion de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/habitacion02.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit Z_POSADA("habitacion");

create() {
  nom_posada="'el Cuervo Blanco'" ;
  tipo=0;
  huesped=random(2);
  vista="Ves la plaza central de Zarkam en medio de la cual se halla un patibulo.\n";

  ::create();

  AddExit("sur",Z_POSADA("pasillo02"));
}
