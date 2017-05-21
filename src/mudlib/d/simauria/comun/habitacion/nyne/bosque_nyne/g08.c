#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("oeste",BOSQUE_NYN("tienda04"));
 AddExit("este",BOSQUE_NYN("gremio_contrabandistas"));

}