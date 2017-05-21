#include "path.h"
inherit ROOM;
create()
{
  ::create();
  SetIntShort("el cementerio");
  SetIntLong(
    "Te encuentras en una pequeña estancia en medio de la cual ves lo que queda\n"
    "de una tumba rodeada por telarañas, mugre y porqueria que se ha acumulado con\n"
    "el tiempo.Lo que en otro tiempo fue un gran mausoleo de alguna familia adinerada,\n"
    "ahora es morada de cualquier tipo de engendros que puedan pulular por esta zona.\n"
    );
  SetIndoors(1);
  SetIntBright(30);
  SetIntSmell(
    "El olor a cerrado y a humedad flota en el ambiente.\n"
    );
  SetIntNoise(
    "Ruidos como de arañazos se escuchan a lo lejos.\n"
    );
  AddDetail(({"tumba"}),
    "Una tumba de piedra guarda lo que en su dia fueron los restos de alguien vivo. El aspecto es el de un ataud hecho de piedra que permanece intacto en el centro de la estancia.\n"
    );
  AddDetail(({"niebla"}),
    "Una niebla fina se filtra dentro de esta estancia haciendo de ella un triste y lobrego final para la gente que tiene en esta su ultima morada.\n"
    );
  AddExit("oeste","camino12.c");
  SetLocate("cementerio2");
}
