#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("norte",KRIGOR("sendero01"));
 AddExit("sur",BOSQUE_NYN("bosque011"));
 AddExit("este",BOSQUE_NYN("bosque005"));
 AddExit("oeste",BOSQUE_NYN("bosque003"));
}
