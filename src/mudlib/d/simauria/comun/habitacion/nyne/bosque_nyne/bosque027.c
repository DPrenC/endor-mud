#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque017"));
 AddExit("este",BOSQUE_NYN("bosque028"));
 AddExit("oeste",BOSQUE_NYN("bosque026"));
 AddExit("sudeste",BOSQUE_NYN("bosque039"));
 AddExit("suroeste",BOSQUE_NYN("bosque037"));

}
