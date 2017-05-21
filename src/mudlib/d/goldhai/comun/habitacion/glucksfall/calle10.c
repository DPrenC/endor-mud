#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la avenida Djorn");
  SetLongWrap(
    "Te encuentras en el Sur de una pequeña plaza situada justo al "
    "oeste de una de las torres que protegen Glucksfall. Un poco "
    "más allá de la torre ves un pequeño puerto con algunos barcos "
    "atracados en él. Por el contrario puedes adentrarte en la ciudad "
    "si vas hacia el Oeste."
    );
  SetIndoors(0);
  AddExit("oeste","calle9");
  AddExit("norte","calle11");
  AddExit("este","torre5");
  SetLocate("Glucksfall");
}
