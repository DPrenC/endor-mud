#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("nordeste",BOSQUE_NYN("tienda03"));
 AddExit("suroeste",BOSQUE_NYN("gremio_contrabandistas"));
}