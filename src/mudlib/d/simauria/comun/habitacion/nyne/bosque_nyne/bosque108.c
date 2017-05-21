#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("noroeste",BOSQUE_NYN("bosque097"));
 AddExit("sudeste",BOSQUE_NYN("bosque120"));
 AddExit("suroeste",BOSQUE_NYN("bosque118"));

}
