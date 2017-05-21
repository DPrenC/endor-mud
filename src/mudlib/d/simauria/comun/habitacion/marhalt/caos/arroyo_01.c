/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitaci�n base, corrijo mogoll�n de typos y m�s
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
    "Una estatua est� a tu lado, otra al norte, una m�s al noreste, otras "
    "tres al este, y finalmente la estatua de la charca.\n");
  AddDetail(({"estatua"}),
    "La estatua est� en bastante buen estado. Cuando te fijas en su rostro "
    "notas una expresion de terror m�s all� de lo imaginable. Te percatas "
    "que todas las estatuas est�n como huyendo de algo que viniese de la "
    "zona sur, menos una en el centro de la charca en postura desafiante "
    "mirando a dicha pared.\n");
  AddDetail(({"estatua de la charca","estatua charca","estatua desafiante"}),
    "La estatua esta intacta, cosa que contrasta con la otra estatua que est�"
    " a tu lado, que aunque entera tiene bastantes ara�azos. La estatua est� "
    "finamente trabajada en cobre y esta embutida en una aut�ntica armadura "
    "de hierro (aunque de momento ser� mejor no profanarla).\n"
    "Te resulta muy curioso que es la �nica estatua intacta, y que adem�s "
    "est� en postura desafiante mirando a la pared sur, de la que huyen el "
    "resto.\n");
  AddDetail(({"charca"}),
    "Parece simple agua, pero hay algo que te intranquiliza, pero est�s casi "
    "seguro de que debe haber un pasaje submarino.\n");
  AddExit("norte",CAOSHAB"arroyo_00");
  AddExit("sur",CAOSHAB"arroyo_02");
  AddExit("este",CAOSHAB"arroyo_03");
  AddExit("sudeste",CAOSHAB"arroyo_estatuas");
  AddExit("nordeste",CAOSHAB"arroyo_04");
}
