#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque183"));
 AddExit("oeste",BOSQUE_NYN("bosque195"));
 AddExit("suroeste",BOSQUE_NYN("bosque207"));

}
