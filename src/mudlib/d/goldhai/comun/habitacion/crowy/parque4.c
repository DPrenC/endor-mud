#include "./path.h"
inherit GROOM;

create()
{
 ::create();

 SetIntLong(
"El muro de la ciudad te impide continuar mas al oeste de aqui. En esta zona "
"hay matorrales bajos y abundan las flores. Los insectos zumban a tu alrededor.\n");

 AddExit("este",CROWY("parque3"));
 AddExit("norte",CROWY("parque6"));

#include "./parque.inc"

}


