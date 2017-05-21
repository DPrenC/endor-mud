//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   ayun1.c                           *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 20.10.98                  *
//* Modificacion: 20.10.98              *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
inherit KHA_ROOM;

// hall de los enanos donde se controla el censo

create() {
 ::create();

 SetIntShort("el jardín central del hall");
 SetIntLong("Es un pequeño jardin, lleno de flores y plantas, en el centro hay "
 "una gran estatua. Debajo hay un pequeño lago, escavado en la roca, que se "
 "llena con un chorro natural, que sale de la roca sobre la que esta construida "
 "la estatua. Detras de esta y a su derecha hay varios arcos que pasan a otras "
 "dependencias.\n");
 SetIndoors(1);
 SetIntBright(50);
 SetIntNoise("Oyes el ruido de las oficinas y repicar del agua sobre la roca.\n");
 SetIntSmell("Hueles el aroma de las flores y plantas, este lugar no parece enano.\n");

 AddDetail(({"estatua"}),
 "Esta es la gran estatua de los grandes padres enanos, creadores de Kha-annu.\n"
 "Es una gran estatua compuesta por varios personajes enanos, uno forjando, otro "
 "haciendo ladrillos, otro cavando, otro conjurando unos faroles y otro sembrando "
 "una granja.\n"
 "Debajo hay una placa dorada.\n");
 AddReadMsg(({"placa","nota"}),
 "Lees en la placa dorada:\n" // [o] Esto define un cartel, nota o cualquier
 "Dedicada a todos aquellos que contribuyeron a construir Kha-annu:\n"
 "Izet, Heimy, Fran, Yandros, Woo, Ghandor, Kitai, Krunch, Parsifal, Tannis "
 "Yashiva y Gorthem.\n");

 AddExit("oeste",("porkha"));
 AddExit("norte",("censo"));
 AddExit("este",("ayun2"));
 AddExit("sur",CIUDAD+"avcastle5");
 }
