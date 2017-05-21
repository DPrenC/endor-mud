#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque098"));
 AddExit("nordeste",BOSQUE_NYN("bosque078"));
 AddExit("sudeste",BOSQUE_NYN("bosque099"));
}
