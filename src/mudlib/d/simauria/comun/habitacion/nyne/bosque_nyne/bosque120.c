#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque109"));
 AddExit("noroeste",BOSQUE_NYN("bosque108"));
 AddExit("sudeste",BOSQUE_NYN("bosque136"));

}
