#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("norte",BOSQUE_NYN("tienda01"));
 AddExit("sur",BOSQUE_NYN("tienda04"));

}