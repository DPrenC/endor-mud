#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("este",BOSQUE_NYN("bosque013"));
 AddExit("sudeste",BOSQUE_NYN("bosque021"));
 AddExit("suroeste",BOSQUE_NYN("bosque019"));

}
