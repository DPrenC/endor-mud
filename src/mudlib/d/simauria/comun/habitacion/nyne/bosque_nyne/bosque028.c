#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque018"));
 AddExit("oeste",BOSQUE_NYN("bosque027"));
}
