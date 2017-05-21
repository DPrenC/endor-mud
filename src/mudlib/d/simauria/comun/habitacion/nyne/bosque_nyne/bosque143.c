#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("nordeste",BOSQUE_NYN("bosque129"));
 AddExit("noroeste",BOSQUE_NYN("bosque127"));
 AddExit("sudeste",BOSQUE_NYN("bosque161"));
 AddExit("suroeste",BOSQUE_NYN("bosque159"));

}
