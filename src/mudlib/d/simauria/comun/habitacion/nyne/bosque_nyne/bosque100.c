#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque089"));
 AddExit("sur",BOSQUE_NYN("bosque110"));
 AddExit("suroeste",BOSQUE_NYN("bosque109"));

}
