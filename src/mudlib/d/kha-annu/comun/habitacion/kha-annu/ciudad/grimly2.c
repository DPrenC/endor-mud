#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"Sigues paseando por la Avenida y te parece escuchar un ligero alboroto hacia el "
"oeste. Grandes farolas negras iluminan la calle y podrias pasarte varias horas "
"observando el atractivo movimiento de las llamas. Al sur se esconde un pequenyo "
"callejon y al norte se encuentra la calle Hunkas.\n");

   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"farolas","grandes farolas"}),
   "Las farolas estan destinadas a iluminar la avenida.\n");
   AddDetail(({"llama","llamas"}),
   "Nunca paran de moverse y parece como si quisieran saltar de la farola.\n");

   AddExit("norte",CIUDAD+"hunkas1");
   AddExit("sur",CIUDAD+"callejon2");
   AddExit("este",CIUDAD+"grimly3");
   AddExit("oeste",CIUDAD+"grimly1");

   SetLocate("Kha-annu");
}

init() {
   ::init();
   add_action("escuchar","escuchar");
}
escuchar(string str) {
  if ((str != "alboroto") && (str != "ligero alboroto") &&
      (str != "un ligero alboroto")) {
     write("Debes poner atencion a lo que quieres escuchar.\n");
     return 1;
  }
   else  {
      if (random(6) < TP->QueryInt()) {
	 write("El ruido parece que viene de la taberna.\n");
	 return 1;
      }
      else  {
	 write("No escuchas nada. Deben haber sido imaginaciones tuyas.\n");
	 return 1;
      }
   }
}
