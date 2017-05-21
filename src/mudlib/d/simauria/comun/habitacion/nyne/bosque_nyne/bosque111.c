#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("entrada_gremio"));
 AddExit("sur",BOSQUE_NYN("bosque127"));
}
