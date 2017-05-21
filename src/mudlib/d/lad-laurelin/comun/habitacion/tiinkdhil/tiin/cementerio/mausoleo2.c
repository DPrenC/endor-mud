
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;


create(){
  ::create();
 SetIntShort("un mausoleo");
SetIntLong(    "Te encuentras en una pequeña estancia en medio de la cual ves una\n"
 "sencilla y bella tumba rodeada parcialmente por unas bonitas flores.\n"
  "Aqui notas una paz que no has percibido en ningún otro rincón del cementerio.\n"
 );

  SetIndoors(1);
  SetIntBright(40);

 SetIntSmell("Respirar aire fresco y aromatizado.\n");

  AddDetail(({"tumba","ataud"}),    "Está hecha de madera de caoba. Tiene una incripción en la tapa.\n"
     );

  AddDetail(({"tapa","piedra"}),
  "En común hay talladas unas palabras: .\n"
    "LLoramos tu pérdida y la pérdida de tu sueño. Que algún día deje de serlo.\n"    );
  AddDetail(({"porqueria","telarañas"}),
  "Restos de hojas, telas de araña y polvo se acumulan por todos lados.\n"    );

 AddExit("este",ALUTIIN("cementerio/camino3"));
 AddItem(ALUPNJ("vampiresa"),REFRESH_DESTRUCT,1);
AddItem(ALUPNJ("guer_esquel"),REFRESH_DESTRUCT,1);
AddItem(ALUPNJ("guer_esquel"),REFRESH_DESTRUCT,1);

 SetLocate("cementerio2");
 }
 