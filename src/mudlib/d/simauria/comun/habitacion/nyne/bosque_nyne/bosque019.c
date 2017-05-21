#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("oeste",BOSQUE_NYN("bosque018"));
 AddExit("nordeste",BOSQUE_NYN("bosque012"));
 AddExit("noroeste",BOSQUE_NYN("bosque010"));
}
