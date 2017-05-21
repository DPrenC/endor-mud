#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque029"));
 AddExit("sudeste",BOSQUE_NYN("bosque053"));
 AddExit("suroeste",BOSQUE_NYN("bosque051"));

}
