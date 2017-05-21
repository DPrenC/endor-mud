#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("gremio_contrabandistas"));
 AddExit("sur",BOSQUE_NYN("tienda07"));

}