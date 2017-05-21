/* psi_ruins08.c
   Escaleras del norte
   Creaci�n: [n] Nemesis, 19-Abr-2001 01:11:34 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("un pasillo sombr�o");
SetIntLong(
"Te encuentras en un estrecho pasillo al final del cual hay unas escaleras\
 que conducen al piso de arriba. No hay mucho que ver, salvo un par de viejos\
 cuadros en la pared.\n\
Hay una puerta que conduce a la entrada del Gremio al sur.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"escaleras"}),
"Unas s�lidas escaleras de piedra que parecen conducir al piso de arriba.\n");
AddDetail(({"cuadros","viejos cuadros"}),
"Al acercarte mejor, descubres que no son cuadros. La humedad ha producido "
"extra�as e inquietantes formas dentro del cerco que dejaron dos cuadros "
"que desaparecieron tiempo ha. La escasa luz hace que parezcan dos severos "
"rostros que te contemplan, rodeados de siniestras figuras que parecen "
"enfrascadas en un macabro baile. Un s�bito cambio de iluminaci�n hace que "
"la ilusi�n desaparezca... �o no es una ilusi�n? Decides que no tienes "
"inter�s en saberlo.\n");

AddExit("sur","./psi_ruins01");
AddExit("arriba","./psi_ruins11");

}

