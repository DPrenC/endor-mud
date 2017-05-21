 /*
DESCRIPCION : puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/muelle01.c
MODIFICACION:
30-10-98 [Angor@Simauria] Creacion
07-02-00 [Angor@Simauria] Modificaciones varias
*/

#include "path.h"
#include AK_MACRO
inherit PORT;

create(){
 ::create();
SetIntShort("el puerto de Azzor");
 SetIntLong(
	"Te encuentras en el muelle de la dársena del puerto de la ciudad de "
	"Azzor. Ante ti observas multitud de barcos fondeados en este protegido "
	"puerto orco. Al este del puerto se hallan los macizos malecones que "
	"protegen a los barcos del fuerte oleaje. El edificio con pórtico que "
	"que queda al oeste es la posada del 'Lobo de Mar' como se lee en el "
	"cartel que cuelga de su fachada. La fortaleza de Azzor se alza amenazante "
      	"al norte del puerto. En esta parte del muelle hace escala la goleta "
      	"Tempestad, que realiza el trayecto entre Goldhai y Azzor.\n");

#include "puerto_detail.h"

 AddDetail(({"posada","edificio"}),
	"Es un gran edificio de tres plantas de altura. Su fachada esta llena "
	"de ventanas y sobre la puerta principal cuelga un cartel de madera con "
	"el dibujo de una gran jarra de cerveza y el texto 'Posada el Lobo de "
	"Mar' pintado en él.\n");

 AddDetail(({"jarra","cartel","rotulo","rótulo"}),
  	"Sobre la puerta principal de la posada y colgando de una barra de "
    	"metal hay un cartel de madera. En el se halla pintada una gran jarra "
	"de cerveza y el texto 'Posada el Lobo de Mar'. La brisa marina hace "
	"balancearse ruidosamente al rótulo sobre sus viejos y oxidados "
	"goznes.\n");

 SetIntNoise("Por encima de las olas escuchas el rechinar de los goznes del "
             "rótulo de la posada.\n");

 AddShip(BAR_TEMPEST("tempestad"));

 //AddExit("norte",AZ_PUERTO("muelle00"));
 //AddExit("oeste",AZ_POSADA("entrada"));
 AddExit("oeste",AZ_PUERTO("portico01"));
 AddExit("sur",AZ_PUERTO("muelle02"));
}
