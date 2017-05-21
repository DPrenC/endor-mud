/* psi_ruins02.c
   Sala dentro del Gremio
   Creación: [n] Nemesis, 16-Abr-2001 01:05:47 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("una oscura sala");
SetIntLong(
"Estás en una pequeña sala tenuemente iluminada. No parece haber nada de\
 valor por aquí. Una desvencijada puerta al oeste parece conducir al\
 exterior, mientras que otra puerta conduce hacia la entrada, al este.\n\
Hay una trampilla abierta en el suelo.\n");
SetIndoors(1);
SetIntBright(15);

AddDetail(({"trampilla","reja"}),
"Una gran reja de hierro en el centro de la sala. Está abierta y se pueden "
"intuir unas escaleras. Te preguntas dónde llevarán...\n");
AddDetail(({"escaleras","escaleras hacia abajo"}),
"Parecen llevar abajo...\n");

AddExit("este","./psi_ruins01");
AddExit("oeste","psi_ruins03");
AddExit("abajo","./psi_ruinsS1");
HideExit("abajo",1);

}

