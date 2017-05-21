#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque123"));
 AddExit("oeste",BOSQUE_NYN("bosque121"));
 AddExit("sudeste",BOSQUE_NYN("bosque138"));
}
