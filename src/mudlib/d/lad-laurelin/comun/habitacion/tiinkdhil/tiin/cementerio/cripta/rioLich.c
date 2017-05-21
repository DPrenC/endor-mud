#include "path.h"

inherit LAD_ROOM;
create()
{
  ::create();
  SetIntShort("un r�o subterr�neo");
  SetIntLong(
    "La cripta termina al oeste en esta cavidad que el r�o que ves enfrente tuyo ha "
        "escavado.\n"
    "La sala esta iluminada por los reflejos verdes y rojos que surgen del agua. "
    "Tal vez una inspecci�n mas cuidadosa pueda revelarte algo m�s.\n"
    );
  SetIndoors(1);
  SetIntBright(20);
  SetIntSmell(
        "Notas la humedad del r�o, aunque con un ligero olor a sangre y muerte.\n"
    );
  SetIntNoise(
        "Escuchas el murmullo del agua, aunque de cuando en cuando oyes como un gemido "
        "apagado que te hace dudar de tus oidos.\n"
    );
  AddDetail(({"r�o","agua","reflejos"}),
        "Al acercarte al r�o ves porque esta habitacion te da mala espina. Inmersas "
        "en la corriente puedes ver las almas de todos los que han sido sacrificados "
        "aqui. Sus espectros sin cabeza, que brillan con una ligera luz verdosa, son "
        "arrastrados r�o abajo, a lo mas profundo de la tierra. El agua, lejos de ser "
        "limpida y cristalina, como coresponde a las corrientes subterraneas, esta "
        "enturbiada por manchas de sangre.\n"
    );

  AddItem(ALUPNJ("espectro"),REFRESH_DESTRUCT,1);
  AddExit("este",ALUTIIN("cementerio/cripta/mausoleo1"));
}