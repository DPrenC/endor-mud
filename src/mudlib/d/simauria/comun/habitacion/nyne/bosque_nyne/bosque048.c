#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("noroeste",BOSQUE_NYN("bosque035"));
 AddExit("sudeste",BOSQUE_NYN("bosque060"));
}
