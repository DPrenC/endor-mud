/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:
MODIFICACION : [l] lonerwolf
               19/10/00 creacion :)
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("el puesto de Guardia");
SetIntLong(
"Esta pequenya estancia da cobijo a los guardias que custodian la salida este\n"
"de la ciudad de Tiinkel. Hay bastante espacio libre, debido a la ausencia del\n"
"mobiliario. Dispuestas por toda la pared estan colgadas las armas y armaduras\n"
"que los guardias de reserva no estan usando. La unica salida visible es hacia\n"
"el norte.\n");

AddDetail (({"arma","armas","armadura","armaduras"}),
"Dispuestas en perfecto orden se encuentran las armas y armaduras que usan los\n"
"guardias. Estan en perfecto estado y brillan magestuosamente.\n");

SetIntBright(20);
SetIntNoise(
"Te paras a escuchar y llegan hasta ti todos los sonidos procedentes del\n"
"exterior de la estancia.\n");
SetIntSmell("Un lijero olor a savia inunda la habitacion.\n");
SetLocate("Ciudad Tiink");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("norte",TCSUELO("salida3"));
}