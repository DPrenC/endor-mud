#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("tienda05"));
 AddExit("sur",BOSQUE_NYN("tienda08"));
 AddExit("oeste",BOSQUE_NYN("g13"));
 AddExit("este",BOSQUE_NYN("entrada_gremio"));

}