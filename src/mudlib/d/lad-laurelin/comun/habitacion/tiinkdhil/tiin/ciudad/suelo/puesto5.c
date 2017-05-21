/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:       [l] lonerwolf
MODIFICACION :
              19/10/00 [l] añadi las descripciones pertinentes
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("el puesto de guardia");
SetIntLong(
"Esta pequenya estancia da cobijo a los guardias que custodian la salida oeste\n"
"de la ciudad de Tiinkel. Dispuestas por toda la pared estan colgadas las armas\n"
"y armaduras que los guardias de reserva no estan usando. El moviliario es muy\n"
"escaso, un par de sillas y una mesa. Tambien hay un pequenyo barril de agua y\n"
"un pequenyo armario para guardar las provisiones. La unica salida visible es\n"
"hacia el norte.\n");

AddDetail (({"arma","armas","armadura","armaduras"}),
"Dispuestas en perfecto orden se encuentran las armas y armaduras que usan los\n"
"guardias. Estan en perfecto estado y brillan magestuosamente.\n");

AddDetail (({"mesa"}),
"Como si fuese un apendice mas del arbol, la mesa surge directamente desde el\n"
"suelo de la habitacion. Sobre ella hay varios papeles oficiales, unos botes\n"
"de tinta y unas plumas para poder escibir.\n");

AddDetail (({"silla","sillas"}),
"Son sillas de madera con tres patas y respaldo de varillas.\n");

SetIntBright(20);
SetIntNoise(
"El mas minimo murmullo procedente de la calle se oye desde este lugar.\n");
SetIntSmell(
"El olor a savia que desprende el interior del arbol impregna todo el ambiente.\n");
SetLocate("Ciudad Tiink");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("norte",TCSUELO("salida2"));
}
