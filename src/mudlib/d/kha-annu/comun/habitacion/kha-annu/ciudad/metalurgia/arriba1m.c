//arriba1m.c
//Hecho por Ghandor
//4 de Diciembre de 1997

#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

 SetIntShort("el primer piso de la Escuela de Metalurgia");

 SetIntLong(
"Estas en el primer piso de la Escuela de Metalurgia. Aqui hay muchos mas "
"cuadros que en el piso de abajo. La pared esta tapizada de cuadros y tapices.\n"
"Ves unas escaleras hechas de mithril que llevan al piso de arriba. Unas "
"antorchas iluminan la sala.\n");

 SetIndoors(1);

 SetIntBright(80);

 SetIntNoise("Silencio sepulcral, mejor no hagas mucho ruido.\n");

 AddDetail(({"escaleras","escalones"}),
 "Son unas escaleras hechas a base de mithril que llevan al piso de arriba.\n");
 AddDetail(({"antorchas","luces"}),
 "Son unas antorchas hechas de mithril. En su cumbre arden unas brasas que dan "
 "una luz impresionante.\n");
 AddDetail(({"cuadros","tapices"}),
 "Son dibujos de armas y armaduras con mezclas de varios metales un poco mas "
 "modernos que los anteriores.\n");

 AddExit("arriba",META+"arriba2m");
 AddExit("abajo",META+"entradam");

}