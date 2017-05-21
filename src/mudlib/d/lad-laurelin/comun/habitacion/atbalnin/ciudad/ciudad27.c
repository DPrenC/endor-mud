#include "path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("El vil metal, ésa es la principal razón de ser de todos "
  	"y cada uno de los aventureros. Bueno, y el riesgo, un amante en "
  	"cada ciudad, pero eso entra en el contrato. ¿Dónde puede haber "
  	"más dinero que en el regazo de un dragón? Exacto, en un banco. "
  	"Estas frente a una sucursal del Banco de Simauria. El edificio "
  	"tampoco es que desentone con el resto de estructuras, pero parece "
  	"ligeramente más sólido que los demás. Probablemente debido a la "
  	"naturaleza de lo guardado en su interior. Cerca de sus puertas "
  	"puedes ver un cartel.\n"));
  SetIntShort("la zona central de Atbalnin");
  AddDetail("banco", W("Ves una sucursal del Banco de Simauria. Aquí podrás "
  	"realizar todo tipo de transacciones monetarias.\n"));

  AddDetail("cartel", "Es un cartel que podrías leer.\n");
  AddReadMsg("cartel", "Lees el cartel: 'Abierto durante el día'.\n");

  AddExit("sur", ATB_CI("ciudad26"));
  AddExit("entrar", ATB_TI("banco"));
  AddExit("este", ATB_CI("ciudad30"));
    AddDoor("entrar", "la puerta del banco", "Es la puerta para entrar en el banco.\n",
    ({"puerta", "puerta del banco"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
  }
    