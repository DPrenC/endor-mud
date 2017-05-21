/* templo6.c : Cementerio de Nandor
 Creado por : Blackrider
 Fecha : 1-11-97
 Ultima modificacion : 18-09-02
 Modificaciones:
 [Jessy] Castellanizaci�n del fichero y cambio en las descripciones
         del templo que antes era una ermita.
 [Zomax] Comento la salida a templo7.c dado que el archivo a dia de
	 hoy no existe en ese directorio al menos.
 [Nemesis] Descomentado el templo7, que ahora s� existe. Tengo profundas
           dudas sobre de qui�n es el responsable, as�n que de momento
	   el "premio" recae sobre Jessy...
*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

hacer_sonar(string str){
  if (str!="cuerda") {
    write ("Agarrar �QU�?\n");
    return 1 ;
  }
  write("Pegas un salto y te coges fuertemente a la cuerda.........\n"
        "......... tu cuerpo se balancea arriba y abajo al comp�s "
        "del movimiento de la cuerda.\n");
  tell_room(MARH("/nandor/cementerio/templo7"),
                 "DOOONNNNNGGGG, DOOOONNNNNGGGG, DOOOOONNNNGGG...\n"
                 "El ruido que provoca la campana es ensordecedor.");
  tell_room(MARH("/nandor/cementerio/templo1"),
                 "DOOONNNNNGGGG, DOOOONNNNNGGGG, DOOOOONNNNGGG...\n"
                 "Alguien debe de estar tocando una campana... Suena por "
                 "encima de ti... Debe de haber alg�n campanario.\n");
  tell_room(MARH("/nandor/cementerio/templo6"),
                  "DOOONNNNNGGGG, DOOOONNNNNGGGG, DOOOOONNNNGGG...\n");

  write("Te resbalas de la cuerda y caes al suelo.\n");
  TP->SetExplored();
  return 1;
}

init () {
    ::init ();
    add_action("hacer_sonar","agarrar");
}


create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el campanario del Templo de la Se�ora de la Noche");
SetIntLong(W(
             "Est�s en las escaleras que suben a lo alto del campanario. "
	     "Por un hueco que hay en el techo sale una cuerda que "
	     "se enrosca en el suelo. Hacia abajo vas al interior del "
	     "templo. Arriba se encuentra el campanario.\n"));
SetIndoors(1);
SetIntBright(20);

AddDetail("cuerda","Fijo que tiene alguna relaci�n con la campana...\n");
AddExit("arriba","templo7");
AddExit("abajo","templo5");
}
