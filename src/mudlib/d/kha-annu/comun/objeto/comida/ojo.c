/*  Es un ojo comestible.
    fichero: ojo.c
    autor:  [I] Izet@Simauria.
    creacion: 11 de Febrero 1998.
    ultimas modificaciones: 1 Jun, 1998 by [Y] Yandros.
*/

#include "./path.h"

inherit THING;
create() {
  ::create();
    SetShort("un ojo");
     SetLong(
"Este ojo debio estar mejor situado en las cavidades oculares de su duenyo.\n"
"Parece como si te observara, pero que ojo separado de su lugar de origen\n"
"no lo parece?\n");
   SetIds( ({"ojo"}) );
   AddAdjective( ({"un"}) );
   SetSmell("Acercas el ojo a tu nariz... en realidad no huele a nada.\n");
   SetNoise("El ojo no parece emitir ruido alguno.\n");
}

init() {
    ::init();
    add_action("Come","comer");
    add_action("Come","consumir");
}

Come(string str) {
object pota;
  if ( str == "ojo" || str == "un ojo" ) {
   if (TP->QueryRace() == "orco" || TP->QueryRace() == "troll" ||
       TP->QueryRace() == "kainoak" ||
       TP->QueryRace() == "draconiano" || TP->QueryRace() == "demonio") {

       write("Te comes el ojo.\n");
       say(capitalize(getuid(TP))+
                                " saca un ojo de su bolsillo y se lo come.\n");
         remove();
         if (TO) destruct(TO);
         return 1;
    }
    if (TP->QueryRace() != "orco" || TP->QueryRace() != "troll" ||
        TP->QueryRace() != "kainoak" ||
        TP->QueryRace() != "draconiano" || TP->QueryRace() != "demonio" ) {
       write(
"Empiezas a masticar el ojo, y el ruido que produce al morderlo te da asco...\n"
"Buaaaargh! Un liquido amargo, acido y caliente sube por tu garganta...\n"
"Has vomitado.\n");
       say(capitalize(getuid(TP))+
        " empieza masticar un ojo y vomita delante de tus pies.\n"
"Es repugnante.\n");

         seteuid(getuid(TO));
         pota = clone_object(COMIDA("pota"));
	 pota->move(environment(TP));
         remove();
         if (TO) destruct(TO);
         }
       return 1;
   }
  else {
      return 0;
  }
}
