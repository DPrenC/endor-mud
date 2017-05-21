#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("g14"));
 AddExit("noroeste",BOSQUE_NYN("gremio_contrabandistas"));
 AddExit("sudeste",BOSQUE_NYN("tienda08"));
}