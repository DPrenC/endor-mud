#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();
  SetPreIntShort("frente a");
  SetIntShort("la puerta Sur de Glucksfall");
  SetLongWrap(
    "Te encuentras fuera de la ciudad con las puertas situadas al "
    "Este y el bosque Djorn en el resto de direcciones."
  );

  AddExit("norte","bosque25");
  AddExit("sur","bosque27");
  AddExit("oeste","bosque28");
  AddExit("este",GLUCKSFALL("puerta_sur"));
  SetLocate("bosque djorn");
}