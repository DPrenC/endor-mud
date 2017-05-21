/* Archivo        camino61.c
   Autor:         Yalin y Lug
   Fecha:         30/04/2006
   Descripción:   Camino a la abadía (proyecto)
*/

#include "path.h"
inherit ABDCAM;
create ()
{
    ::create();
    SetIntLong("Continúas caminando por el viejo camino que une Nandor con "
        "la abadía de Sherek.\nGrandes árboles te impiden salir de la ruta, "
        "y te bloquean la visión en todas direcciones.\nEn este punto, "
        "tras rodear la montaña donde se asientan las ruinas de la antigua "
        "torre de Gundistir, el camino hace un giro brusco hacia el este, "
        "para alejarse definitivamente de la región de Marhalt.\n");
    AddExit("oeste", CNSH("camino60"));
    AddExit("sureste", CNSH("camino62"));
    Bichejo();
}
