#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque023"));
 AddExit("sur",BOSQUE_NYN("bosque044"));
}
