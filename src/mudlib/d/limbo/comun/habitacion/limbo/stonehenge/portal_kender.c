/*
DESCRIPCION  : Portal de los kenders en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_kender.c
MODIFICACION : 24-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>
#include <properties.h>

inherit STONE("portal_tipo");

portal_aux();
create() {
   destino="/d/kenton/comun/habitacion/ent_kender";
   raza="kender";
  newbiehome=STONE("portal_kender");
  muro="exterior";
  ::create();
  AddExit("oeste",STONE("portal_enano"));
  AddExit("noroeste",STONE("st_tierra"));
  AddExit("norte",STONE("portal_6"));
  AddExit("nordeste",STONE("portal_7"));
/*
  AddExit("portal",SF(portal));
*/
  AddExit("portal",SF(portal_aux));
}
portal_aux(){
   if(TP->QuerySize()!=P_SIZE_SMALL)
       return notify_fail(
"Lo siento, por mas que lo intentas no cabes por el portal..\n");
TP->move("/d/kenton/comun/habitacion/flenton/calles/entrada",M_GO);
    return 1;
}
