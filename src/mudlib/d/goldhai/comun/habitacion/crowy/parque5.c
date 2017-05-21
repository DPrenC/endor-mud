#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntLong(
"En esta zona del parque alguien contruyó un banco de madera. Esta viejo y "
"ajado, pero aun se pueden dormir buenas siestas en él a la sombra del muro "
"de la ciudad.\n");
 AddDetail("banco","Es un viejo banco de madera.\n");
 
 AddExit("oeste",CROWY("parque7"));
 AddExit("este",CROWY("parque9"));
 AddExit("sur",CROWY("parque3"));

#include "./parque.inc"
}


