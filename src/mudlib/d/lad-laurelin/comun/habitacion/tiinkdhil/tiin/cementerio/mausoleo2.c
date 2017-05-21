
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;


create(){
  ::create();
 SetIntShort("un mausoleo");
SetIntLong(    "Te encuentras en una peque�a estancia en medio de la cual ves una\n"
 "sencilla y bella tumba rodeada parcialmente por unas bonitas flores.\n"
  "Aqui notas una paz que no has percibido en ning�n otro rinc�n del cementerio.\n"
 );

  SetIndoors(1);
  SetIntBright(40);

 SetIntSmell("Respirar aire fresco y aromatizado.\n");

  AddDetail(({"tumba","ataud"}),    "Est� hecha de madera de caoba. Tiene una incripci�n en la tapa.\n"
     );

  AddDetail(({"tapa","piedra"}),
  "En com�n hay talladas unas palabras: .\n"
    "LLoramos tu p�rdida y la p�rdida de tu sue�o. Que alg�n d�a deje de serlo.\n"    );
  AddDetail(({"porqueria","telara�as"}),
  "Restos de hojas, telas de ara�a y polvo se acumulan por todos lados.\n"    );

 AddExit("este",ALUTIIN("cementerio/camino3"));
 AddItem(ALUPNJ("vampiresa"),REFRESH_DESTRUCT,1);
AddItem(ALUPNJ("guer_esquel"),REFRESH_DESTRUCT,1);
AddItem(ALUPNJ("guer_esquel"),REFRESH_DESTRUCT,1);

 SetLocate("cementerio2");
 }
 