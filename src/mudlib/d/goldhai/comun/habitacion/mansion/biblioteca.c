#include "./path.h"
#include <magia.h>

inherit GROOM;

create()
{
 ::create();
 SetIntShort("la biblioteca");
SetIntLong(
"Altas estanterias cubren las paredes de esta estancia. En ellas se apilan "
"innumerables libros. Llevaria toda una vida el poder leerlos.\n");

AddDetail(({"estanterias"}),
"En ellas se apilan los libros.\n");

AddDetail(({"libros"}),
"Los hay por todas partes.\n");

 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(50);
 SetIntNoise("No oyes nada especial.\n");
 SetIntSmell("No huele a nada especial.\n");
 SetTPort(TPORT_NO);
 AddExit("este",MANSION("comedor"));
 SetLocate("mansión de Hardester Rankomme");
}