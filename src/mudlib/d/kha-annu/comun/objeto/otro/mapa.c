/* Mapa de la ciudad de Kha-annu- Creado por [Y] Yandros a 20.11.98 */

#include "path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();

  SetShort("un mapa de Kha-annu");
  SetLong(
"Mapa de la Ciudad de Kha-annu. Capital del Imperio de los enanos.\n"
"\n"
"x--x--x--x--x--x--x--x--x--x--x--x--x   1.- Tienda de armas\n"
"|  |        |     |     |     |  |  |   2.- Herreria\n"
"x--1--x     2     A     3     x--4  x   3.- Tienda de utensilios\n"
"|     |     |     |     |     |  |  |   4.- Tienda de armaduras\n"
"x--x--x--x--x--x--x--x--x--x--x--x--x   5.- Escuela de metalurgia\n"
"|     |           |        |     |      6.- Escuela de ingenieria\n"
"x     x  XXXXXXXX x XXXXXX x     X--X   7.- Diligencia 'El Tuerto\n"
"|     |  XXXXXXXX | XXXXXX |        |   8.- Herbolario\n"
"x--5--x  XXXXXXXXXXXXXXXXX x--x     x   p.- Puente Kilok\n"
"|     |  XXXXXXXXXXXXXXXXX    |     |   A.- Ayuntamiento\n"
"x     x  XXXXXXXXXXXXXXXXXXXX x     x   a.- Taberna\n"
"|     |  XXXX CASTILLO XXXXXX |     |   b.- Gremio de guerreros\n"
"x--x--x  XXXXXX  DE  XXXXXXXX x     p   c.- Templo\n"
"|     |  XXXX KHA-ANNU XXXXXX |     |   d.- Posada\n"
"x     x  XXXXXXXXXXXXXXXXXXXX x     x   S.- Puerta Sur\n"
"|     |  XXXXXXXXXXXXXXXXX    |     |\n"
"x--6--x  XXXXXXXXXXXXXXXXX x--x  7--x--8\n"
"|     |  XXXXXXXXXXXXXXXXX |        |\n"
"x     x  XXXXXXXXXXXXXXXXX x     x--x\n"
"|     |                    |     |\n"
"x--x--x--x--x--x--x--x--x--x--x--x--x\n"
"|  |  |     |     |     |     |  |  |\n"
"x--a--x     b     x     c     x  d--x\n"
"|     |     |     |     |     |  |  |\n"
"x--x--x--x--x--x--S--x--x--x--x--x--x\n");


  SetIds(({"mapa de Kha-annu","mapa de la ciudad de Kha-annu","mapa"}));
  SetAds(({"un","el"}));
  SetWeight(15);
  SetValue(12);
  Set(P_GENDER,GENDER_MALE);
}
