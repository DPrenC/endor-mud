/*          cemen4o.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 30-10-97
            Ultima modificacion : 9-1-01
            Modificado por:
	    [Nemesis]   Anyadida la tumba del propio jugador.
	                Eso le pasa por mirar :) . Cambios en las descripciones y en
			los AddDetails.
	   [N] Cambiada la funci�n TuTumba para corregir bugs,	castellanizado y
	                a�adido un punto de Exploraci�n
    	    [Jessy]	Castellanizaci�n de los ficheros y cambio de la ermita a templo.

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
    return"Al mirar a la tumba, observas esta inscripci�n:\n\n"
          "\tAqu� yace "+capitalize(TP->QueryRealName())+".\n"
          "\tMuri� en este mismo\n"
          "\tcementerio a manos\n"
          "\tde un malvado ghoul.\n"
          "\t  Descanse En Paz\n\n";
}

create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el extremo noroeste del cementerio");
SetIntLong(
           "El espect�culo es dantesco. Todas las tumbas de esta zona han sido abiertas "
           "y sus ocupantes yacen medio despedazados por todas partes. Caminos hacia el "
           "norte, sur y este te invitan a salir de aqu� cuanto antes.\n");
SetIndoors(0);

AddDetail("tumbas",
          "Hay muchas y todas est�n profanadas, salvo una que parece m�s reciente.\n");
AddDetail(({"tumba","tumba reciente","tumba intacta"}), SF(TuTumba));
AddDetail(({"muertos","cadaveres","ocupantes","cad�veres"}),
            "�Un poco morbosillo t�, no? Est�n todos despedazados. La carne les ha sido "
            "arrancada a mordiscos con gran fiereza.\n");
AddExit("sur","cemen3o");
AddExit("norte","cemen4no");
AddExit("este","cemen4");
}
