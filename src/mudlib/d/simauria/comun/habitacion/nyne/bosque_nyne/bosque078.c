#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque069"));
 AddExit("oeste",BOSQUE_NYN("bosque077"));
 AddExit("suroeste",BOSQUE_NYN("bosque087"));

}
