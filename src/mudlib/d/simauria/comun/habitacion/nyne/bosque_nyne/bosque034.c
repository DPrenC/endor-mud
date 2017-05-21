#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque046"));
 AddExit("nordeste",BOSQUE_NYN("bosque024"));
 AddExit("suroeste",BOSQUE_NYN("bosque045"));

}
