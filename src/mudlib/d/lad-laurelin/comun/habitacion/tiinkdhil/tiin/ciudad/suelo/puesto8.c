/*
DESCRIPCION  :
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/
NOTAS:       [l] lonerwolf
MODIFICACION : sandalin
               19/10/00 [l] quiete el cementerio del mapa

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("el puesto de guardia");
  SetIntLong(
"Esta pequeña estancia da cobijo a los guardias que custodian la salida sur de\n"
"la ciudad de Tiink. Hay armas apiladas en un rincon y a su lado una serie de\n"
"lustrosas armaduras. Adornando las paredes hay un enorme tapiz. En el centro\n"
"de la estancia hay una vasija de barro que recoge la savia que cae del arbol\n"
"sangrante.\n");
AddDetail (({"tapiz","mapa","tapices"}),
"      CIUDAD DE TIINK\n"
"    -----------------------------------------      LEYENDA\n"
"    |                                       |      ----------\n"
"    |                   (C1)                |       * - Situacion actual.\n"
"    |                    |                  |      C1 - Calle del Viajero.\n"
"    |                O - O - O              |      C2 - Calle del Anochecer.\n"
"    |                    |                  |      C3 - Calle Hirak.\n"
"    |                    O - O              |      C4 - Calle Fanan.\n"
"    |                    |                  |      C5 - Calle del Amanecer.\n"
"    |                    O                  |\n"
"    |       (C2)         |                  |\n"
"    |   (C3) O - O - O - O - O - O - O      |\n"
"    |        |   |      -|-  |   |   |      |\n"
"    |        O   O      | |  O   O   O - O  |\n"
"    |        |      /---' `---\      |      |\n"
"    |    O   O - O  |  ARBOL  |      O   O  |_\n"
"    |    |   |  |---'         `----| |   |  |\n"
"    |  - O - O -     DE     LA     - O - O - |\n"
"    |    |   |  |---.         .----| |   |  |_\n"
"    |    O   O      |  VIDA   |  O - O   O  |\n"
"    |        |      \---.  .--/      |      |\n"
"    |        O   O   O  |  |     O - O      |\n"
"    |        |   |   |  -|--         |      |\n"
"    |   (C4) O - O - O - O - O - O - O      |\n"
"    |                    |          (C5)    |\n"
"    |                    O                  |\n"
"    |                    |                  |\n"
"    |                O - O - *              |\n"
"    |                    |                  |\n"
"    |                                       |\n"
"    -----------------------------------------\n"
"\n");

AddDetail (({"arma","armas","armadura","armaduras"}),
"Se encuentran apiladas en un rincon. Lustrosas. Apesar de la oscuridad del\n"
"rincon, brillan.\n");
AddDetail (({"vasija"}),
"Una vasija de barro algo deteriorada qeu sirve para recoger la savia que cae\n"
"del arbol.\n");
SetIntBright(20);
SetIntNoise(
"El mas minimo murmullo procedente de la calle se oye desde este lugar. Ademas, oyes como la sangre del arbol emite un seco sonido cuando llega a la vasija\n");
SetIntSmell(
"El olor a savia que desprende el interior del arbol impregna todo el ambiente.\n ");
SetLocate("Tiink");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("oeste",TCSUELO("salida4"));

}