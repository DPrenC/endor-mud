#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque206"));
 AddExit("noroeste",BOSQUE_NYN("bosque192"));
 AddExit("suroeste",BOSQUE_NYN("bosque211"));

}