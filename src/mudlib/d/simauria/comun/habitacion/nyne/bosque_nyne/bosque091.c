#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque081"));
 AddExit("noroeste",BOSQUE_NYN("bosque080"));
}
