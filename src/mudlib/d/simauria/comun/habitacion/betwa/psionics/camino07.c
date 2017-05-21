/*
 camino07.c
 Inicio del camino que lleva al gremio de psiónicos
 Creación: [n] Nemesis, 10-Abr-2001 23:35:04 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Antiguo Camino");
SetIntShort("un camino empedrado");
SetIntLong(
"En este lugar el camino está casi borrado por la vegetación y el paso del\
 tiempo. Apenas conserva un atisbo de su gloria anterior. No obstante, algunos\
 restos de la antigua calzada aquí y allí permiten decir que se interna en las\
 montañas hacia el oeste, mientras que pasa a través de algunos matorrales\
 hacia el sudeste.\n");
SetIndoors(0);

AddDetail(({"camino","calzada"}),
"Esta parte del camino no parece haber sido pisada por nadie en siglos. Sólo "
"algunas piedras aquí y allí dan testimonio de que una vez fue una calzada "
"importante.\n");

AddDetail(({"matorrales"}),
"Al sureste, el camino ha sido casi cubierto por unos espesos matorrales.\n");

AddExit("sureste","../../caminos/gremio/cam_cortado06");
AddExit("oeste","./camino06");

}
