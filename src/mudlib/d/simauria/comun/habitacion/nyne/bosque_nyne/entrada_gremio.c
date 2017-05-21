#include "path.h"
inherit BOSQUE_NYN("b_nyne");

create(){
 ::create();
 
 // Aqui hay una pista para saber donde esta la entrada oculta al gremio de
 // los contrabandistas. Un sonido no es gran cosa, pero ya pondremos un guia en
 // Krigor que te traiga directamente... por un precio nada justo :)

 SetIntNoise("Oyes un ligero murmullo desde el oeste.\n");

 AddExit("sudeste",BOSQUE_NYN("bosque112"));
 AddExit("este",BOSQUE_NYN("bosque101"));
 AddExit("norte",BOSQUE_NYN("bosque090"));
 AddExit("sur",BOSQUE_NYN("bosque111"));
 AddExit("oeste",BOSQUE_NYN("g14"));
 HideExit("oeste",1);
 AddRoomCmd("rastrear","_rastrear");
}

reset()
{
 ::reset();
 HideExit("oeste",1);
}

init()
{
 ::init();
}


int _rastrear(string str)
{
 write("¡¡Hay una salida oculta hacia el oeste!!.\n");
 HideExit("oeste",0);
 return 1;
}