#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("nordeste",BOSQUE_NYN("gremio_contrabandistas"));
 AddExit("suroeste",BOSQUE_NYN("tienda06"));
}