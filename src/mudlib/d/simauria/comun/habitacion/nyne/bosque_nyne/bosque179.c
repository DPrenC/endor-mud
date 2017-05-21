#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("noroeste",BOSQUE_NYN("bosque164"));
 AddExit("sudeste",BOSQUE_NYN("bosque193"));
 AddExit("suroeste",BOSQUE_NYN("bosque191"));

}
