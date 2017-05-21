/*
 camino07.c
 Inicio del camino que lleva al gremio de psi�nicos
 Creaci�n: [n] Nemesis, 10-Abr-2001 23:35:04 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetIntShort("un camino empedrado");
SetIntLong(
"En este lugar el camino est� casi borrado por la vegetaci�n y el paso del\
 tiempo. Apenas conserva un atisbo de su gloria anterior. No obstante, algunos\
 restos de la antigua calzada aqu� y all� permiten decir que se interna en las\
 monta�as hacia el oeste, mientras que pasa a trav�s de algunos matorrales\
 hacia el sudeste.\n");
SetIndoors(0);

AddDetail(({"camino","calzada"}),
"Esta parte del camino no parece haber sido pisada por nadie en siglos. S�lo "
"algunas piedras aqu� y all� dan testimonio de que una vez fue una calzada "
"importante.\n");

AddDetail(({"matorrales"}),
"Al sureste, el camino ha sido casi cubierto por unos espesos matorrales.\n");

AddExit("sureste","../../caminos/gremio/cam_cortado06");
AddExit("oeste","./camino06");

}
