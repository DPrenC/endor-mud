#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque135"));
 AddExit("oeste",BOSQUE_NYN("bosque151"));
 AddExit("noroeste",BOSQUE_NYN("bosque134"));
 AddExit("suroeste",BOSQUE_NYN("bosque167"));

}
