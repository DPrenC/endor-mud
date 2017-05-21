#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque010"));
 AddExit("este",BOSQUE_NYN("bosque004"));
 AddExit("oeste",BOSQUE_NYN("bosque002"));
}
