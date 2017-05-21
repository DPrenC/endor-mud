/*  Es una pota comestible.
    fichero: pota.c
    autor:  [I] Izet@Simauria.
    creacion: 11 de Febrero 1998.
    ultimas modificaciones:     11 Feb, 1998.
*/

#include "./path.h"


inherit THING;
create() {
   ::create();
     SetShort("un vomito asqueroso y repugnante");
     SetLong(
"Es un vomito. Su textura es espesa y ves unos tropezones amarillos y\n"
"sanguinolentos flotando en su superficie. Parece comestible, aunque no\n"
"recomendable a no ser que te veas en una situacion extrema de inanicion.\n");
   SetIds( ({"vomito"}) );
   AddAdjective( ({"asqueroso","repugnante","un","sanguinolento","amarillo"}) );
    SetSmell("Arg! Notas un olor acido y espeso que viene del vomito.\n");
    SetNoise("El vomito no produce ningun ruido, aunque en su momento hubo de producirlo.\n");
}

init() {
    ::init();
    add_action("Come","comer");
    add_action("Come","consumir");
    add_action("Bebe","beber");
}

Come(string str) {
object pota;
  if ( str == "vomito" || str == "pota" || str == "vomito asqueroso" ||
       str == "vomito repugnante" || str == "vomito asqueroso y repugnante") {
   if (TP->QueryRace() == "orco" || TP->QueryRace() == "troll" ||
       TP->QueryRace() == "kainoak" ||
       TP->QueryRace() == "draconiano" || TP->QueryRace() == "demonio") {

       write("Te comes el vomito. Te sientes mejor.\n");
       say(capitalize(getuid(TP))+
                                " se come un vomito. Es repugnante.\n");
         if (TP->QueryHP() == TP->QueryMaxHP() ) {return 1;}
         else { TP->SetHP( (TP->QueryHP()) + 1); }
         remove();
         if (TO) destruct(TO);
         return 1;
    }
    if (TP->QueryRace() != "orco" || TP->QueryRace() != "troll" ||
        TP->QueryRace() != "kainoak" ||
        TP->QueryRace() != "draconiano" || TP->QueryRace() != "demonio" ) {
       write(
"Te has comido el vomito y sientes nauseas...\n"
"Buaaaargh! Un liquido amargo, acido y caliente sube por tu garganta...\n"
"Has vomitado.\n");
       say(capitalize(getuid(TP))+
        " se come algo amarillento y vomita justo delante de tus pies.\n"
"Es repugnante.\n");

         TO->move(environment(TP));
         }
       return 1;
   }
  else {
      return 0;
  }
}

Bebe(string str) {
   if (!str && str != "vomito" && str != "pota" && str != "vomito asqueroso" &&
       str != "vomito repugnante" && str != "vomito asqueroso y repugnante") {
       return 0;
   }
   if (str == "vomito" || str == "pota" || str == "vomito asqueroso" ||
       str == "vomito repugnante" || str == "vomito asqueroso y repugnante") {
   write("No puedes beberte el vomito. Habria que masticar los tropezones.\n");
   return 1;
   }
}

