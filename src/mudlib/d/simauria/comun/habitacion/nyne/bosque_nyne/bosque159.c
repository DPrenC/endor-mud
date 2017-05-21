#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("nordeste",BOSQUE_NYN("bosque143"));
 AddExit("noroeste",BOSQUE_NYN("bosque141"));
 AddExit("sudeste",BOSQUE_NYN("bosque176"));
}
