//arriba2m.c
//Hecho por Ghandor
//4 de Diciembre de 1997

#include "./path.h"
inherit KHA_ROOM;

create() {
 ::create();

 SetIntShort("el segundo piso de la Escuela de Metalurgia");

 SetIntLong(
"Estas en el segundo piso de la Escuela de Metalurgia. Aqui hay muchos mas "
"cuadros que en el piso de abajo. La pared esta tapizada de cuadros y tapices.\n"
"Ves una pared muy peculiar con una boletin de noticias. Aqui es donde se pueden "
"ver las grandes novedades de todo el mundo. Unas antorchas iluminan la sala.\n"
"Hay unas escaleras que llevan hacia abajo.\n");

 SetIndoors(1);

 SetIntBright(80);

 SetIntNoise("Silencio sepulcral, mejor no hagas mucho ruido.\n");

 AddDetail(({"escaleras","escalones"}),
 "Son unas escaleras hechas a base de mithril que llevan al piso de arriba.\n");
 AddDetail(({"antorchas","luces"}),
 "Son unas antorchas hechas de mithril. En su cumbre arden unas brasas que dan "
 "una luz impresionante.\n");
 AddDetail(({"cuadros","tapices"}),
 "Son dibujos de armas y armaduras con la mezcla de metales mas moderna que "
 "hayas visto jamas!.\n");

 AddItem(MONS+"grehk",REFRESH_DESTRUCT,1);

 AddExit("abajo",META+"arriba1m");

}
