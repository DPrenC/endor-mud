#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque071"));
 AddExit("sur",BOSQUE_NYN("bosque090"));
 AddExit("nordeste",BOSQUE_NYN("bosque072"));
 AddExit("sudeste",BOSQUE_NYN("bosque091"));
}
