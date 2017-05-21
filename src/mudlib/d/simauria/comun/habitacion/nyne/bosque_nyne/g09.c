#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("tienda05"));
 AddExit("oeste",BOSQUE_NYN("gremio_contrabandistas"));

}