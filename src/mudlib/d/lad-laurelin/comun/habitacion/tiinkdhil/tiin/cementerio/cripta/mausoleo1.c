#include "path.h"
inherit LAD_ROOM;
create()
{
  ::create();
  SetIntShort("la tumba de DheSarf");
  SetIntLong(
    "En esta sala se encuentra la tumba de DheSarf, el gran nigromante que construyó "
        "esta cripta para acoger su reposo eterno.\n"
    "En en centro de la sala ves un sarcófago muy ornado, presumiblemente el sepulcro "
        "de DheSarf.\n"
    );
  SetIndoors(1);
  SetIntBright(0);
  SetIntSmell(
    "Hueles a cerrado.\n"
    );
  SetIntNoise(
    "Notas el sepulcral silencio de la muerte.\n"
    );
  AddDetail(({"sepulcro","tumba","sepulcro de DheSarf","sarcofago"}),
        "Es un nicho escavado en la misma roca, que ha sido trabajada para cubrirla "
        "de adornos. En un principio debio estar policromada, pero el efecto de la "
        "humedad de los siglos ha hecho que caiga toda la pintura. La tapa ha sido "
        "quitada, y llace al lado del nicho, lo que te permite observar el interior, "
        "que esta completamente vacio.\n"
    );

  AddExit("oeste",ALUTIIN("cementerio/cripta/rioLich"));
  AddExit("sur",ALUTIIN("cementerio/cripta/laboratLich"));
  AddExit("este", ALUTIIN("cementerio/camino2"));
 //AddDoor("este", "puertas", "Son las puertas de salida de la cripta");
  AddItem(ALUPNJ("lich"),REFRESH_DESTRUCT,1);
}
