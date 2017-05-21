/* cruce_sur.c
   Camino hacia el Gremio de Psi�nicos
   Creaci�n: [n] Nemesis, 10-Abr-2001 23:54:31 CEST
   NOTA: Podr�a ser el inicio del camino a la tumba de Gnudur
         (Quest del Secreto del Acero)
*/

#include <colours.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetPreIntShort("fin de");
SetIntShort("el ramal");
SetIntLong(
"Est�s frente a una pared bas�ltica. No comprendes muy bien la raz�n de\
 construir un camino que conduce directamente a una pared, aunque tambi�n\
 podr�a ser que una convulsi�n tect�nica bloqueara el camino. En cualquier\
 caso, lo cierto es que s�lo puedes ir hacia el norte.\n");
SetIndoors(0);

AddDetail(({"pared","pared bas�ltica","pared basaltica"}),
"Se trata de uno de los flancos de la monta�a. No puedes trepar ni rodearla, "
"as� que lo mejor es que vuelvas sobre tus pasos.\n");

AddExit("norte","camino05");

}
