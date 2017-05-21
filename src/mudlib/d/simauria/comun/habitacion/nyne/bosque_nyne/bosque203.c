#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("oeste",BOSQUE_NYN("bosque202"));
 AddExit("nordeste",BOSQUE_NYN("bosque192"));
 AddExit("suroeste",BOSQUE_NYN("bosque209"));

}
