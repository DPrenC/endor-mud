#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();

 AddExit("nordeste",BOSQUE_NYN("bosque102"));
 AddExit("noroeste",BOSQUE_NYN("entrada_gremio"));
 AddExit("sudeste",BOSQUE_NYN("bosque129"));

}
