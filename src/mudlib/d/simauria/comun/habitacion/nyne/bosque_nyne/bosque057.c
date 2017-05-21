#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque070"));
 AddExit("este",BOSQUE_NYN("bosque058"));
 AddExit("nordeste",BOSQUE_NYN("bosque047"));
 AddExit("suroeste",BOSQUE_NYN("bosque069"));

}
