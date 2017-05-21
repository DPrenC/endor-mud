#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("nordeste",BOSQUE_NYN("bosque134"));
 AddExit("noroeste",BOSQUE_NYN("bosque132"));
 AddExit("sudeste",BOSQUE_NYN("bosque167"));
}
