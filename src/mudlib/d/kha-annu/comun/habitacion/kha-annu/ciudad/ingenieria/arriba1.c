//arriba1.c
//Hecho por Ghandor
//2 de Diciembre de 1997

#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

 SetIntShort("el primer piso de la Escuela de Ingeniería");

 SetIntLong(
"Estas en el primer piso de la Escuela de Ingenieria. Aqui hay muchos mas "
"cuadros que en el piso de abajo. La pared esta tapizada de cuadros y tapices.\n"
"Ves unas escaleras hechas de mithril que llevan al piso de arriba. Unas "
"antorchas iluminan la sala. Al norte de aqui hay una tienda donde puedes "
"comprar cosas utiles.\n");

 SetIndoors(1);

 SetIntBright(80);

 SetIntNoise("Silencio sepulcral, mejor no hagas mucho ruido.\n");

 AddDetail(({"escaleras","escalones"}),
 "Son unas escaleras hechas a base de mithril que llevan al piso de arriba.\n");
 AddDetail(({"antorchas","luces"}),
 "Son unas antorchas hechas de mithril. En su cumbre arden unas brasas que dan "
 "una luz impresionante.\n");
 AddDetail(({"cuadros","tapices"}),
 "Son dibujos de armas y armaduras. En varios de ellos se ven escenificaciones "
 "de varias batallas para demostrar su eficacia.\n");

// AddExit("norte",INGE+"tienda");
 AddExit("arriba",INGE+"arriba2");
 AddExit("abajo",INGE+"entrada");

 SetLocate("ingenieria");
}