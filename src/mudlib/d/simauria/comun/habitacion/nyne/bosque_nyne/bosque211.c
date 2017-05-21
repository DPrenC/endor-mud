#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("bosque204"));
 AddExit("oeste",BOSQUE_NYN("bosque210"));
 AddExit("nordeste",BOSQUE_NYN("bosque205"));
 
}