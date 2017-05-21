#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque120"));
 AddExit("este",BOSQUE_NYN("bosque110"));
 AddExit("nordeste",BOSQUE_NYN("bosque100"));
}
