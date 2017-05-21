#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();
 // AQUI PODRIA IR ALGO MAS QUE UNA HAB. DE BOSQUE ESTANDAR. HABRA QUE PENSARLO.
 AddExit("oeste",BOSQUE_NYN("bosque029"));
}
