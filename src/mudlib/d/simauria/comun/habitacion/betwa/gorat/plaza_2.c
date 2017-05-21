// 07-06-08 [Angor] Creacion

#include "./path.h"
inherit GORAT("room_base.c");

create () {
::create();
replace_program();
SetIntShort("la plaza principal de Gorat");
SetIntLong(
"Te encuentras al extremo sur de la plaza central de Gorat frente al edificio "
"del Gran Salón donde el consejo de ancianos se reúne. Adosada a la pared "
"oeste de la plaza hay una pileta sobre la que mana una alegre fuente a la "
"sombra de los arboles que crecen colina arriba.\n");

AddDetail(({"edificio","salon","salón","dios"}),
"El Gran Salón de Gorat se alza al suroeste de aquí. Es un edificio "
"rectangular de madera con pórtico y tejado a dos aguas de paja seca y "
"comprimida. En los bordes del tejado hay dos planchas de madera talladas que "
"representan a un dios alado que protege el Salón que hay bajo él: su cabeza "
"está en la cúspide y sus alas son el tejado. El resto de la fachada bajo el "
"pórtico está cubierto de otras planchas talladas con motivos marinos y "
"conchas encastradas. Todas las tallas están pintados de un color ocre "
"brillante con lineas en negro.\n");

 AddDetail(({"arboles","arboles"}),
"La colina sobre la que se asienta Gorat asciende hacia el oeste. En su "
"parte baja junto a la plaza crecen varios altos arboles cuyas copas se "
"mecen al ritmo de la brisa que llega del golfo.\n");

 AddItem(OTRO("berat/fuente"));

 AddExit("suroeste", GORAT("salon_1") );
 AddExit("sur", GORAT("casa1a") );
 AddExit("noreste", GORAT("plaza_3") );
 AddExit("norte", GORAT("plaza_1") );

 SetIntNoise("La fuente mana alegremente.\n");
 SetIntSmell("Alguien debe estar cocinando en una de las casas cercanas.\n");
}
