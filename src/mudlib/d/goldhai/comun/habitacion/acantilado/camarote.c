
#include "./path.h"
#include <magia.h>

inherit GROOM;

create()
{
::create();
SetIntShort("el camarote de popa");
SetIntLong(
"Todo est� por los suelos en este camarote, sin duda debido al naufragio "
"del barco o quiz� de los saqueadores que probablemente han debido pasar por "
"aqu� tras �l. Ves jirones de mapas y los trozos de madera de lo que alguna "
"vez debieron ser muebles por todas partes.\n");

 SetTPort(TPORT_NO);
 AddExit("sur",ACANTILADO("barco"));
 AddItem(QUEST "hardester/hrdaga",REFRESH_REMOVE,1);
 SetLocate("acantilado del suroeste de Goldhai");
}