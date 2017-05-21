#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque100"));
 AddExit("sur",BOSQUE_NYN("bosque121"));
 AddExit("oeste",BOSQUE_NYN("bosque109"));
}
