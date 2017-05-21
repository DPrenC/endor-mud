#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque079"));
 AddExit("sur",BOSQUE_NYN("bosque100"));
 AddExit("suroeste",BOSQUE_NYN("bosque099"));

}
