#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque025"));
 AddExit("nordeste",BOSQUE_NYN("bosque015"));
 AddExit("suroeste",BOSQUE_NYN("bosque034"));

}
