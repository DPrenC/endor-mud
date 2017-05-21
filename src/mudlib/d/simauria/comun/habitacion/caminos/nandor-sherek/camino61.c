/* Archivo        camino61.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripci�n:   Camino a la abad�a (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    SetIntLong("Contin�as caminando por el viejo camino que une Nandor con "
        "la abad�a de Sherek.\nGrandes �rboles te impiden salir de la ruta, "
        "y te bloquean la visi�n en todas direcciones.\nEn este punto, "
        "tras rodear la monta�a donde se asientan las ruinas de la antigua "
        "torre de Gundistir, el camino hace un giro brusco hacia el este, "
        "para alejarse definitivamente de la regi�n de Marhalt.\n");
    AddExit("oeste", CNSH("camino60"));
    AddExit("sureste", CNSH("camino62"));
    Bichejo();
}
