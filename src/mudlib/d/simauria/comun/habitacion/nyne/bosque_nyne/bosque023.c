#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque033"));
 AddExit("oeste",BOSQUE_NYN("bosque022"));
 AddExit("noroeste",BOSQUE_NYN("bosque014"));
}
