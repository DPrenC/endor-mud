#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque172"));
 AddExit("noroeste",BOSQUE_NYN("bosque138"));
 AddExit("sudeste",BOSQUE_NYN("bosque173"));
 AddExit("suroeste",BOSQUE_NYN("bosque171"));

}
