/* psi_ruins08.c
   Escaleras del norte
   Creación: [n] Nemesis, 19-Abr-2001 01:11:34 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("un pasillo sombrío");
SetIntLong(
"Te encuentras en un estrecho pasillo al final del cual hay unas escaleras\
 que conducen al piso de arriba. No hay mucho que ver, salvo un par de viejos\
 cuadros en la pared.\n\
Hay una puerta que conduce a la entrada del Gremio al sur.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"escaleras"}),
"Unas sólidas escaleras de piedra que parecen conducir al piso de arriba.\n");
AddDetail(({"cuadros","viejos cuadros"}),
"Al acercarte mejor, descubres que no son cuadros. La humedad ha producido "
"extrañas e inquietantes formas dentro del cerco que dejaron dos cuadros "
"que desaparecieron tiempo ha. La escasa luz hace que parezcan dos severos "
"rostros que te contemplan, rodeados de siniestras figuras que parecen "
"enfrascadas en un macabro baile. Un súbito cambio de iluminación hace que "
"la ilusión desaparezca... ¿o no es una ilusión? Decides que no tienes "
"interés en saberlo.\n");

AddExit("sur","./psi_ruins01");
AddExit("arriba","./psi_ruins11");

}

