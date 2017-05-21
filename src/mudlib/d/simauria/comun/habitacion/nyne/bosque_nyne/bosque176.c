#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
    ::create();
    SetIntLong(QueryIntLong()+
    " Hacia el sur se abre un camino que parece salir del bosque.\n");
    AddExit("sur", CNYNEBERAT("cam01"));
 //AddExit("sur",BOSQUE_NYN("aduanase"));
    AddExit("este",BOSQUE_NYN("bosque177"));
    AddExit("noroeste",BOSQUE_NYN("bosque159"));
    AddExit("suroeste",BOSQUE_NYN("bosque189"));

}
