#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque111"));
 AddExit("oeste",BOSQUE_NYN("bosque126"));
 AddExit("sudeste",BOSQUE_NYN("bosque143"));
}
