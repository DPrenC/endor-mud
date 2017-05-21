#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque027"));
 AddExit("este",BOSQUE_NYN("bosque018"));
 AddExit("oeste",BOSQUE_NYN("bosque016"));
 AddExit("noroeste",BOSQUE_NYN("bosque008"));
}
