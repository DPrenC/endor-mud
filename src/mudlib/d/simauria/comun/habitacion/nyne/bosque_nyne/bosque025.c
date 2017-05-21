#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("sur",BOSQUE_NYN("bosque036"));
 AddExit("este",BOSQUE_NYN("bosque026"));
 AddExit("oeste",BOSQUE_NYN("bosque024"));
}
