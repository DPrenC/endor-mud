#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("oeste",BOSQUE_NYN("bosque005"));
 AddExit("sudeste",BOSQUE_NYN("bosque014"));
}
