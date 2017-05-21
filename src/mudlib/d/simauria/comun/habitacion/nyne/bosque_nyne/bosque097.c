#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque086"));
 AddExit("sudeste",BOSQUE_NYN("bosque108"));
 AddExit("suroeste",BOSQUE_NYN("bosque106"));

}
