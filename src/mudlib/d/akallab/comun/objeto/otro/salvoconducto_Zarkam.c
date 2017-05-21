/*
DESCRIPCION  : Salvoconducto de Zarkam
FICHERO      : /d/akkallab/comun/objeto/otro/salvoconducto_Zarkam.c
MODIFICACION : 09-11-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit OTRO("salvoconducto");

create(){
  ::create();
 SetZona("Zarkam");
}