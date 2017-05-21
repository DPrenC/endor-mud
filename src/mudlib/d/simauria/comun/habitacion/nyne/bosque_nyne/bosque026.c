#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque027"));
 AddExit("oeste",BOSQUE_NYN("bosque025"));
 AddExit("noroeste",BOSQUE_NYN("bosque015"));
}
