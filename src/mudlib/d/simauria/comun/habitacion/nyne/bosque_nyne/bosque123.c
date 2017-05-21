#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque124"));
 AddExit("oeste",BOSQUE_NYN("bosque122"));
 AddExit("sudeste",BOSQUE_NYN("bosque139"));
 AddExit("suroeste",BOSQUE_NYN("bosque137"));

}
