#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque063"));
 AddExit("sur",BOSQUE_NYN("bosque080"));
}
