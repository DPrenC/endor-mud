#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();
  SetPreIntShort("frente a");
  SetIntShort("la puerta Norte de Glucksfall");
  SetLongWrap(
     "Est�s justo delante de las puertas de Glucksfall que se hallan en "
     "el Este. En cualquier otra direcci�n llegar�s a alguna parte del "
     "bosque Djorn.");

  AddExit("norte","bosque20");
  AddExit("oeste","bosque38");
  AddExit("sur","bosque22");
  AddExit("este",GLUCKSFALL("puerta_norte"));
  SetLocate("bosque djorn");
}