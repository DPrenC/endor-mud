#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque009"));
 AddExit("este",BOSQUE_NYN("bosque003"));
 AddExit("oeste",BOSQUE_NYN("bosque001"));
}
