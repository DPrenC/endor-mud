/*          cemen4o.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 30-10-97
            Ultima modificacion : 9-1-01
            Modificado por:
	    [Nemesis]   Anyadida la tumba del propio jugador.
	                Eso le pasa por mirar :) . Cambios en las descripciones y en
			los AddDetails.
	   [N] Cambiada la función TuTumba para corregir bugs,	castellanizado y
	                añadido un punto de Exploración
    	    [Jessy]	Castellanización de los ficheros y cambio de la ermita a templo.

*/
#include <properties.h>
#include <messages.h>
#include "./path.h"

inherit SIM_ROOM;
string TuTumba()
{
    if (!TP) return "";
    say(TP->QueryName()+" mira la tumba reciente.\n",TP);
    TP->SetExplored();
    return"Al mirar a la tumba, observas esta inscripción:\n\n"
          "\tAquí yace "+capitalize(TP->QueryRealName())+".\n"
          "\tMurió en este mismo\n"
          "\tcementerio a manos\n"
          "\tde un malvado ghoul.\n"
          "\t  Descanse En Paz\n\n";
}

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el extremo noroeste del cementerio");
SetIntLong(
           "El espectáculo es dantesco. Todas las tumbas de esta zona han sido abiertas "
           "y sus ocupantes yacen medio despedazados por todas partes. Caminos hacia el "
           "norte, sur y este te invitan a salir de aquí cuanto antes.\n");
SetIndoors(0);

AddDetail("tumbas",
          "Hay muchas y todas están profanadas, salvo una que parece más reciente.\n");
AddDetail(({"tumba","tumba reciente","tumba intacta"}), SF(TuTumba));
AddDetail(({"muertos","cadaveres","ocupantes","cadáveres"}),
            "¿Un poco morbosillo tú, no? Están todos despedazados. La carne les ha sido "
            "arrancada a mordiscos con gran fiereza.\n");
AddExit("sur","cemen3o");
AddExit("norte","cemen4no");
AddExit("este","cemen4");
}
