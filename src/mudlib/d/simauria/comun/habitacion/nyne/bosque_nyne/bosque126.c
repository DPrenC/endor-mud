#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque127"));
 AddExit("oeste",BOSQUE_NYN("bosque125"));
 AddExit("suroeste",BOSQUE_NYN("bosque140"));

}
