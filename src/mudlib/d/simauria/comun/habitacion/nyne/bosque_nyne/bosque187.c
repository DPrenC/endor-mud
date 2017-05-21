#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("oeste",BOSQUE_NYN("bosque186"));
 AddExit("nordeste",BOSQUE_NYN("bosque174"));
 AddExit("sudeste",BOSQUE_NYN("bosque201"));

}
