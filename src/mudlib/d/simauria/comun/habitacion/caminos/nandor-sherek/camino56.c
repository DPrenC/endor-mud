/* Archivo        camino56.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;

create ()
{
    ::create();
    SetIntLong("Llegado a este recodo del camino, puedes ver al suroeste y en la lejanía algo "
               "que se asemeja a una edificación en lo alto de la montaña cercana. Por lo "
               "demás, el paisaje es igual que en el resto del camino.");
    AddDetail(({"suroeste", "construcción", "construccion", "edificación", "edificacion"}), "Entre "
                "los árboles puedes ver a lo lejos unas viejas ruinas.");
    AddDetail(({"ruinas", "ruina"}), "No ves muy bien los detalles porque están demasiado lejos, "
                "pero en su día debió ser una edificación impresionante ya que todavía son "
                "imponentes aun viéndolas desde aquí. Crees reconocer en ellas, por su posicionamiento, "
                "que quizás pueda tratarse de las legendarias ruinas de gundistir");
    AddExit("sur", CNSH("camino55"));
    AddExit("noroeste", CNSH("camino57"));
    Bichejo();
}
