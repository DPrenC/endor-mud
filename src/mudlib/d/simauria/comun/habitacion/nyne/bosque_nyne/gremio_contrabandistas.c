#include "path.h"
inherit BOSQUE_NYN("c_nyne");

create(){
 ::create();

 SetIntShort("el Gremio de los Contrabandistas");
 SetIntLong(W("Estas en... ¿¡¿¡el Gremio de los Contrabandistas?!?! ¿!Como?!"
              " ¿¡¿¡Pero si esto es el claro de un bosque?!?! No crees que"
              " el Gremio de los Contrabandistas sea asi de cutre. Tal vez"
              " deberias preguntar a Mordekai sobre el gremio para saber mas.\n"));

 AddExit("norte",BOSQUE_NYN("g05"));
 AddExit("sur",BOSQUE_NYN("g12"));
 AddExit("este",BOSQUE_NYN("g09"));
 AddExit("oeste",BOSQUE_NYN("g08"));
 AddExit("nordeste",BOSQUE_NYN("g06"));
 AddExit("noroeste",BOSQUE_NYN("g04"));
 AddExit("sudeste",BOSQUE_NYN("g13"));
 AddExit("suroeste",BOSQUE_NYN("g11"));

 AddItem(PNJNYN("Mordekai"),REFRESH_DESTRUCT,1);
}

