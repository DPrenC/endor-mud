#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque075"));
 AddExit("oeste",BOSQUE_NYN("bosque066"));
 AddExit("noroeste",BOSQUE_NYN("bosque055"));
}
