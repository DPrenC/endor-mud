#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("noroeste",BOSQUE_NYN("bosque006"));
 AddExit("sudeste",BOSQUE_NYN("bosque023"));
}
