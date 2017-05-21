#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque208"));
 AddExit("oeste",BOSQUE_NYN("bosque206"));
 AddExit("nordeste",BOSQUE_NYN("bosque196"));
}