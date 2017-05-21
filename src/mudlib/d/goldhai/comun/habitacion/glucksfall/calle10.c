#include "path.h"
inherit GROOM;

create()
{
  ::create();
  SetIntShort("la avenida Djorn");
  SetLongWrap(
    "Te encuentras en el Sur de una peque�a plaza situada justo al "
    "oeste de una de las torres que protegen Glucksfall. Un poco "
    "m�s all� de la torre ves un peque�o puerto con algunos barcos "
    "atracados en �l. Por el contrario puedes adentrarte en la ciudad "
    "si vas hacia el Oeste."
    );
  SetIndoors(0);
  AddExit("oeste","calle9");
  AddExit("norte","calle11");
  AddExit("este","torre5");
  SetLocate("Glucksfall");
}
