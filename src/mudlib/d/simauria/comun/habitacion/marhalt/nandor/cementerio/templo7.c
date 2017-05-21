/*
 templo7.c : Cementerio de Nandor
 Creado por : Blackrider
 Fecha : 1-11-97
 Ultima modificacion :
  23-09-98 [Nemesis] Algo hice, pero no recuerdo qu�...
  18-09-02 [Nemesis] 4 a�os m�s tarde, se adapta a lo del templo y eso.
                     Esto supone cambios en descriciones y tal.
		     Ya de paso, castellanizado...
  05-12-02 [Nemesis] Que hab�a metido la pata en la salida "abajo", que
                     hab�a puesto "ermit6" en lugar de "templo6". Sorry :)

*/
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

hacer_salir() {
   int hp;
   write("Te pones en el borde del campanario y ......\n");
   tell_room(HABITACION+"marhalt/nandor/cementerio/cemen4", "Ahhhhhhhhhhh..."
   "......\n....CATACROCcccccKKKKKK!!!\n"+TP->QueryName()+" se ha tirado desde"
   " lo alto del campanario.\n");
   TP->move(HABITACION+"marhalt/nandor/cementerio/cemen4");
   write("Te has ca�do desde arriba del todo... Te duele todo el cuerpo.\n");
   hp=TP->QueryHP();
   TP->SetHP(hp-(25-random(TP->QueryCon())));
   TP->SetExplored();
   return(1);
  }
init() {
  ::init();
  add_action("hacer_salir","salir");
}

create() {
 ::create();
 SetLocate("Cementerio de Nandor");
 SetIntShort("el campanario del Templo de Sharanna");
 SetIntLong(
"Est�s en lo alto del campanario. Hay una gran campana en el centro de esta "
"habitaci�n y una cuerda que cuelga de ella hacia un hueco enmedio del suelo. "
"Una cornisa rodea todo el campanario. Desde aqu� dominas todo el cementerio "
"y el bosque que lo rodea, al oeste puedes ver un pueblo. "
"Las escaleras son el �nico modo de volver en la ermita. En todas las otras "
"direcciones sales a la cornisa exterior.\n");
 SetIndoors(1);
 SetIntBright(20);
 AddDetail("cornisa","No parece muy firme, no te atrevas a salir fuera.\n");
 AddDetail("pueblo", "Una agrupaci�n de viviendas.\n");
 AddDetail("cementerio",
"Desde aqu� tiene un aspecto muy t�trico, con todas esas fosas abiertas... "
"Tambi�n ves... �una sombra movi�ndose entre las tumbas!");
 AddDetail(({"sombra"}),
"Quiz� deber�as bajar a investigar.\n");
 AddDetail(({"bosque","bosques"}),
"Son los bosques que rodean la villa de Nandor. Sin duda tienen un aspecto m�s "
"acogedor que el cementerio en el que est�s...\n");
 AddExit("norte",SF(hacer_salir));
 AddExit("sur",SF(hacer_salir));
 AddExit("este",SF(hacer_salir));
 AddExit("oeste",SF(hacer_salir));
 AddExit("abajo","templo6");
}
