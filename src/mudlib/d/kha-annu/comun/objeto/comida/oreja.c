/*  Una oreja comestible.
    fichero: oreja.c
    autor:  [I] Izet@Simauria.
    creacion: 11 de Febrero 1998.
    ultimas modificaciones: 1 Jun, 1998 by [Y] Yandros.
*/

#include "./path.h"

inherit THING;
create() {
  ::create();
     SetShort("una oreja solitaria");
     SetLong(
"Es una oreja cortada de su lugar de origen.\n");
   SetIds( ({"oreja"}) );
   AddAdjective( ({"cortada","una","solitaria"}) );
    SetSmell("Huele a cerumen.\n");
    SetNoise("Vas a escuchar a una oreja? o ella te escuchara a ti?\n");
}

init() {
    ::init();
    add_action("Come","comer");
    add_action("Come","consumir");
}

Come(string str) {
object pota;
  if ( str == "oreja" || str == "oreja solitaria" ||
       str == "una oreja" || str == "una oreja solitaria") {
   if (TP->QueryRace() == "orco" || TP->QueryRace() == "troll" ||
       TP->QueryRace() == "kainoak" ||
       TP->QueryRace() == "draconiano" || TP->QueryRace() == "demonio") {

       write("Te comes la oreja.\n");
       say(capitalize(getuid(TP))+
                                " se come una oreja.\n");
         remove();
         if (TO) destruct(TO);
         return 1;
    }
    if (TP->QueryRace() != "orco" || TP->QueryRace() != "troll" ||
        TP->QueryRace() != "kainoak" ||
        TP->QueryRace() != "draconiano" || TP->QueryRace() != "demonio" ) {
       write(
"Empiezas a darle mordiscos a la oreja y sientes nauseas.\n"
"Buaaaargh! Un liquido amargo, acido y caliente sube por tu garganta...\n"
"Has vomitado.\n");
       say(capitalize(getuid(TP))+
        " se come una oreja y vomita.\n"
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
