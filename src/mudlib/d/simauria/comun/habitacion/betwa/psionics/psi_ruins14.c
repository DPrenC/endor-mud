/* psi_ruins14.c
   El Vórtice
   Creación: [n] Nemesis, 19-Abr-2001 02:15:38 CEST
   Notas: Un puntito de exploración por "tocarlo" y un pedrusco que
          andará por aquí.
*/

#include "./path.h"
inherit SIM_ROOM;

int vortex(string arg) {
 if (arg == "vórtice" || arg == "monolito" || arg == "vortice" ||
     arg == "Vórtice" || arg == "Vortice") {
  write("Armándote de valor, acercas tus manos al monolito....\n");
  write("Una fuerza invisible coge tus manos e inmediatamente todo\
  desaparece. Sientes que sales fuera del espacio y el tiempo, mientras\
 visiones de hechos pasados, presentes y futuros se mezclan\
 en un caleidoscópico remolino de sensaciones. Finalmente,\
 todo estalla en un cegador relámpago azulado.\n\
Lo que sea que haya dentro de Vórtice no se ha mostrado, pero sabes\
 que es real, que está ahí y que en él vive todavía parte del poder que una\
 vez habitó entre estos muros. Debilitado, mas no destruído...\n"
);
 // Antes de activarlo, meterlo en el explorer.ic
  TP->SetExplored();
  return 1;
 }
 else return 0;
}


create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("las ruinas del Vórtice");
SetIntLong(
"Comienzas a temblar al entrar en la sala. Hay una extraña luz que lo impregna\
 todo, pero que no viene de ningún sitio en particular. Es como si el centro\
 de toda la Fuerza psiónica, el Vórtice, todavía resonase entre estos muros con\
 todo su poder. A pesar de ser sólo un reflejo de lo que fue, lo cierto es que\
 todavía impresiona, y sientes un fuerte impulso de dejar el lugar.\n\
Puedes dejar este lugar hacia el este.\n");
SetIndoors(1);
SetIntBright(35);

AddDetail(({"luz"}),
"Es una luz suave que lo impregna todo, pero que no parece venir de ningún "
"sitio en concreto.\n");
AddDetail(({"vórtice","Vórtice","vortice","Vortice","monolito"}),
"Parece un simple monolito de color negro con forma piramidal. A pesar de "
"estar partido en dos y completamente resquebrajado, tienes la sensación "
"de que un poder dormido te vigila desde dentro del monolito. Mientras "
"piensas en ello, no puedes reprimir un escalofrío ¿de verdad hace tanto "
"frío aquí...?\n");

AddRoomCmd("tocar",SF(vortex));

AddExit("este","./psi_ruins13");
}

