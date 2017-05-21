#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque076"));
 AddExit("sur",BOSQUE_NYN("bosque097"));
 AddExit("suroeste",BOSQUE_NYN("bosque096"));

}
