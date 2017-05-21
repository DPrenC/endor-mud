#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque144"));
 AddExit("oeste",BOSQUE_NYN("bosque160"));
 AddExit("noroeste",BOSQUE_NYN("bosque143"));
}
