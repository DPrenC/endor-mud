#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque061"));
 AddExit("oeste",BOSQUE_NYN("bosque059"));
 AddExit("noroeste",BOSQUE_NYN("bosque048"));
}
