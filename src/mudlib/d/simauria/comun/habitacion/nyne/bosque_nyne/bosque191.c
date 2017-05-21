#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque178"));
 AddExit("oeste",BOSQUE_NYN("bosque190"));
 AddExit("nordeste",BOSQUE_NYN("bosque179"));
}
