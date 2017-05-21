#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 //AddExit("sur",BOSQUE_NYN("aduanaso"));
 AddExit("este",BOSQUE_NYN("bosque207"));
 AddExit("oeste",BOSQUE_NYN("bosque205"));
 AddExit("noroeste",BOSQUE_NYN("bosque193"));
}