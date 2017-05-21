#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("oeste",BOSQUE_NYN("bosque200"));
 AddExit("nordeste",BOSQUE_NYN("bosque189"));
 AddExit("noroeste",BOSQUE_NYN("bosque187"));
}
