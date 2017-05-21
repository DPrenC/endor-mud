#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque049"));
 AddExit("este",BOSQUE_NYN("bosque038"));
 AddExit("nordeste",BOSQUE_NYN("bosque027"));
 AddExit("sudeste",BOSQUE_NYN("bosque050"));
}
