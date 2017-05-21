/* psi_ruins12.c
   Escaleras del primer piso (ala sur)
   Creación: [n] Nemesis, 19-Abr-2001 01:33:41 CEST
   Notas: Esta habitación también daba acceso a la Biblioteca, pero
         la puerta está atascada, y no se puede abrir. Por tanto, es
	 un simple camino cortado, aunque es probable que haga que
	 el busto contenga una piedra de memoria.
*/

#include "./path.h"
inherit SIM_ROOM;

int abrir(string arg) {
 if (arg == "puerta" || arg == "puerta corredera" ||
     arg == "vieja puerta corredera") {
  write("La puerta lleva tanto tiempo cerrada que ahora es imposible abrirla.\n");
  return 1;
 }
 return 0;
}

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("un pasillo del primer piso");
SetIntLong(
"Te encuentras en un estrecho pasillo al final del cual hay unas escaleras\
 que conducen al piso de abajo. Al norte hay una vieja puerta corredera que\
 tiene un cartel sobre ella. En el centro de la habitación hay tirado un\
 viejo busto de bronce.\n\
Unas escaleras conducen al piso de abajo.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"escaleras"}),
"Unas sólidas escaleras de piedra que parecen conducir al piso de abajo.\n");
AddDetail(({"cartel"}),
"Los signos están tan deteriorados que no podrías leerlos.\n");
AddDetail(({"busto","busto de bronce"}),
"Un viejo busto de bronce que sin duda representa a alguien importante. "
"Ahora, sin embargo, sólo es un pedazo de chatarra medio oxidado.\n");
AddDetail(({"puerta","puerta corredera",
            "vieja puerta","vieja puerta corredera"}), "Está cerrada.\n");

AddRoomCmd("abrir",SF(abrir));
AddExit("abajo","./psi_ruins07");

}

