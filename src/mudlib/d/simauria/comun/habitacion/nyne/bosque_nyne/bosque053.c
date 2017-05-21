#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque041"));
 AddExit("noroeste",BOSQUE_NYN("bosque040"));
}
