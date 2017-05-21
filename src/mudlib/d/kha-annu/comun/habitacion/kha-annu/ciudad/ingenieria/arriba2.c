//arriba2.c
//Hecho por Ghandor
//4 de Diciembre de 1997

#include "./path.h"
#include <rooms.h>

inherit KHA_ROOM;

create() {
 ::create();

 SetIntShort("el segundo piso de la Escuela de Ingeniería");

 SetIntLong(
"Estas en el segundo piso de la Escuela de Ingenieria. Aqui hay muchos más "
"cuadros que en el piso de abajo. La pared esta tapizada de cuadros y tapices.\n"
"Ves una pared muy peculiar con una boletin de noticias. Aqui es donde se pueden "
"ver las grandes novedades de todo el mundo. Unas antorchas iluminan la sala.\n"
"Hay unas escaleras que llevan hacia abajo.\n");

 SetIndoors(1);

 SetIntBright(80);

 SetIntNoise("Silencio sepulcral, mejor no hagas mucho ruido.\n");

 AddDetail(({"escaleras","escalones"}),
 "Son unas escaleras hechas a base de mithril que llevan al piso de arriba.\n");
 AddDetail(({"marco","titulo","titulo de ingenieria","titulo de ingeniero"}),
"Podrias intentar leerlo.\n");
 AddDetail(({"antorchas","luces"}),
 "Son unas antorchas hechas de mithril. En su cumbre arden unas brasas que dan "
 "una luz impresionante.\n");
 AddDetail(({"cuadros","tapices"}),
 "Son dibujos de armas y armaduras. En varios de ellos se ven escenificaciones "
 "de varias batallas para demostrar su eficacia.\n");

 AddItem(MONS+"shalok",REFRESH_DESTRUCT,1);

 AddExit("abajo",INGE+"arriba1");

 AddReadMsg(({"marco","titulo","titulo de ingeniera","titulo de ingeniero"}),
"\nLees el titulo de ingenieria:\n "
"Al estudiante Shalok, por su notable inteligencia y su arte del pensamiento, se "
"le concede el Titulo de Ingeniero Ilustrisimo de la comarca de Kha-annu.\n"
"\n\tFdo."
"\n\t________________________________________________________"
"\n\tAdministracion de la Excelentisima Escuela de Ingenieria"
"\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
 SetLocate("ingenieria");
}
