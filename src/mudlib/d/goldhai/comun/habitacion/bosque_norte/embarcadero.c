/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 07-02-99                |
 |               Ultima Modificacion.. 07-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PORT;

create()
{
 ::create();
 SetIntShort("un embarcadero");
 SetIntLong("\
Una extraña calma hace que este lugar sea algo tétrico. El embarcadero está\n\
todo lleno de unas algas verdes bastante malolientes. La madera carcomida\n\
del suelo y la humedad del ambiente es quizás lo más destacado del lugar.\n\
Puedes salir de aquí si vas hacia el Sur.\n");

 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Hay una extraña calma en este lugar.\n");
 SetIntSmell("Argghh.. huele bastante mal.\n");

 AddDetail(({"embarcadero","lugar","muelle"}),
"Es tan pequeño y viejo que parece imposible que aquí llegue un barco.\n");
 AddDetail(({"algas","algas verdes"}),
"Puaajjj.. desde luego eso es bastante asqueroso.\n");
 AddDetail("tabla","No ves ninguna tabla cerca.\n");
 AddRoomCmd("leer","room_leer");
 AddShip(BOTE_FANTASMA("bote"));

 AddExit("sur",BNORTE("alrededor_crowy15"));

 SetLocate("bosque del norte de Goldhai");
}

room_leer(string str)
{
 if (str=="tabla")
  return write("No ves ninguna tabla aquí.\n"),1;
 return 0;
}