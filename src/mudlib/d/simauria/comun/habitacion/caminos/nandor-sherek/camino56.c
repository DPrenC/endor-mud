/* Archivo        camino56.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;

create ()
{
    ::create();
    SetIntLong("Llegado a este recodo del camino, puedes ver al suroeste y en la lejan�a algo "
               "que se asemeja a una edificaci�n en lo alto de la monta�a cercana. Por lo "
               "dem�s, el paisaje es igual que en el resto del camino.");
    AddDetail(({"suroeste", "construcci�n", "construccion", "edificaci�n", "edificacion"}), "Entre "
                "los �rboles puedes ver a lo lejos unas viejas ruinas.");
    AddDetail(({"ruinas", "ruina"}), "No ves muy bien los detalles porque est�n demasiado lejos, "
                "pero en su d�a debi� ser una edificaci�n impresionante ya que todav�a son "
                "imponentes aun vi�ndolas desde aqu�. Crees reconocer en ellas, por su posicionamiento, "
                "que quiz�s pueda tratarse de las legendarias ruinas de gundistir");
    AddExit("sur", CNSH("camino55"));
    AddExit("noroeste", CNSH("camino57"));
    Bichejo();
}
