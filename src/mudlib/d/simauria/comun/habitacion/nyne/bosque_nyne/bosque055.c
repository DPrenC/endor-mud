#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("nordeste",BOSQUE_NYN("bosque044"));
 AddExit("noroeste",BOSQUE_NYN("bosque042"));
 AddExit("sudeste",BOSQUE_NYN("bosque067"));

}
