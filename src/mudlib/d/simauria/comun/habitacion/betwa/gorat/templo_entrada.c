// 03-03-03 [z] Cambio hermita por ermita
// 03-06-08 [Angor] Rehecha

#include "./path.h"
inherit GORAT("room_base.c");

create () {
  ::create();
  replace_program();
  SetIntShort("la ermita de la Diosa Valevissa");
  SetIntLong(
"Estás en la puerta del templo de la diosa humana del mar, Valevissa. Este "
"es un lugar de culto donde los pescadores y marineros rezan a su diosa para "
"pedirle que la travesía sea favorable y puedan llegar de nuevo a puerto. Es "
"un pequeño templo prácticamente vacío excepto por el altar que queda al "
"norte y en el que hay una imagen de la diosa.\n");

AddDetail( ({"imagen","diosa","Valevissa","valevissa"}),
"Hay una imagen de la diosa en el altar al fondo del templo. Deberías "
"acércate más si quieres verla con detalle.\n");
   
AddExit("sur", GORAT("calle_faro_1") );
AddExit("norte", GORAT("templo_altar") );
   
/*AddDoor("sur", "la puerta de salida",
"Es una puerta de madera corroída por el salitre del mar, da salida a la playa.\n",
({"puerta", "puerta de salida", "puerta del sur", "puerta de madera"}));*/

switch(d2()){
    case 1:
         AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT); break;
    case 2:
         AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT); break;
    }

SetIndoors(1);
SetIntBright(30);
}
