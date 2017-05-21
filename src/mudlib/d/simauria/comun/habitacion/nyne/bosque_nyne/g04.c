#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 AddExit("noroeste",BOSQUE_NYN("tienda01"));
 AddExit("sudeste",BOSQUE_NYN("gremio_contrabandistas"));

}