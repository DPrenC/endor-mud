#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque007"));
 AddExit("este",BOSQUE_NYN("bosque016"));
 AddExit("sudeste",BOSQUE_NYN("bosque026"));
 AddExit("suroeste",BOSQUE_NYN("bosque024"));

}
