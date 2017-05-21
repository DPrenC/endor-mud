#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("noroeste",BOSQUE_NYN("bosque112"));
 AddExit("sudeste",BOSQUE_NYN("bosque145"));
 AddExit("suroeste",BOSQUE_NYN("bosque143"));

}
