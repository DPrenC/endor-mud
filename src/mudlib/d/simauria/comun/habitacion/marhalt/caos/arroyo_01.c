/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitación base, corrijo mogollón de typos y más
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("el centro de la estancia del arroyo");
  SetIntLong("Te encuentras en la parte central de una gran estancia "
    "rectangular.\n"
    "Delante tuya, a tus pies, ves una especie de charca. "
    "Puedes distinguir siete estatuas de color verde jaspeado, una de ellas "
    "a tu lado y otra dentro de la charca.\n");
  SetIntNoise("Escuchas en suave rumor del paso del agua en la charca del "
    "sur.\n");
  AddDetail(({"estatuas"}),
    "Una estatua está a tu lado, otra al norte, una más al noreste, otras "
    "tres al este, y finalmente la estatua de la charca.\n");
  AddDetail(({"estatua"}),
    "La estatua está en bastante buen estado. Cuando te fijas en su rostro "
    "notas una expresion de terror más allá de lo imaginable. Te percatas "
    "que todas las estatuas están como huyendo de algo que viniese de la "
    "zona sur, menos una en el centro de la charca en postura desafiante "
    "mirando a dicha pared.\n");
  AddDetail(({"estatua de la charca","estatua charca","estatua desafiante"}),
    "La estatua esta intacta, cosa que contrasta con la otra estatua que está"
    " a tu lado, que aunque entera tiene bastantes arañazos. La estatua está "
    "finamente trabajada en cobre y esta embutida en una auténtica armadura "
    "de hierro (aunque de momento será mejor no profanarla).\n"
    "Te resulta muy curioso que es la única estatua intacta, y que además "
    "está en postura desafiante mirando a la pared sur, de la que huyen el "
    "resto.\n");
  AddDetail(({"charca"}),
    "Parece simple agua, pero hay algo que te intranquiliza, pero estás casi "
    "seguro de que debe haber un pasaje submarino.\n");
  AddExit("norte",CAOSHAB"arroyo_00");
  AddExit("sur",CAOSHAB"arroyo_02");
  AddExit("este",CAOSHAB"arroyo_03");
  AddExit("sudeste",CAOSHAB"arroyo_estatuas");
  AddExit("nordeste",CAOSHAB"arroyo_04");
}
