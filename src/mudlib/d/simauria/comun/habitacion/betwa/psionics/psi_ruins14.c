/* psi_ruins14.c
   El V�rtice
   Creaci�n: [n] Nemesis, 19-Abr-2001 02:15:38 CEST
   Notas: Un puntito de exploraci�n por "tocarlo" y un pedrusco que
          andar� por aqu�.
*/

#include "./path.h"
inherit SIM_ROOM;

int vortex(string arg) {
 if (arg == "v�rtice" || arg == "monolito" || arg == "vortice" ||
     arg == "V�rtice" || arg == "Vortice") {
  write("Arm�ndote de valor, acercas tus manos al monolito....\n");
  write("Una fuerza invisible coge tus manos e inmediatamente todo\
  desaparece. Sientes que sales fuera del espacio y el tiempo, mientras\
 visiones de hechos pasados, presentes y futuros se mezclan\
 en un caleidosc�pico remolino de sensaciones. Finalmente,\
 todo estalla en un cegador rel�mpago azulado.\n\
Lo que sea que haya dentro de V�rtice no se ha mostrado, pero sabes\
 que es real, que est� ah� y que en �l vive todav�a parte del poder que una\
 vez habit� entre estos muros. Debilitado, mas no destru�do...\n"
);
 // Antes de activarlo, meterlo en el explorer.ic
  TP->SetExplored();
  return 1;
 }
 else return 0;
}


create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("las ruinas del V�rtice");
SetIntLong(
"Comienzas a temblar al entrar en la sala. Hay una extra�a luz que lo impregna\
 todo, pero que no viene de ning�n sitio en particular. Es como si el centro\
 de toda la Fuerza psi�nica, el V�rtice, todav�a resonase entre estos muros con\
 todo su poder. A pesar de ser s�lo un reflejo de lo que fue, lo cierto es que\
 todav�a impresiona, y sientes un fuerte impulso de dejar el lugar.\n\
Puedes dejar este lugar hacia el este.\n");
SetIndoors(1);
SetIntBright(35);

AddDetail(({"luz"}),
"Es una luz suave que lo impregna todo, pero que no parece venir de ning�n "
"sitio en concreto.\n");
AddDetail(({"v�rtice","V�rtice","vortice","Vortice","monolito"}),
"Parece un simple monolito de color negro con forma piramidal. A pesar de "
"estar partido en dos y completamente resquebrajado, tienes la sensaci�n "
"de que un poder dormido te vigila desde dentro del monolito. Mientras "
"piensas en ello, no puedes reprimir un escalofr�o �de verdad hace tanto "
"fr�o aqu�...?\n");

AddRoomCmd("tocar",SF(vortex));

AddExit("este","./psi_ruins13");
}

