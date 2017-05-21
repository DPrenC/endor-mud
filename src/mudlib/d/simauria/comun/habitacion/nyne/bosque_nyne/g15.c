#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("tienda07"));
 AddExit("oeste",BOSQUE_NYN("tienda06"));
}