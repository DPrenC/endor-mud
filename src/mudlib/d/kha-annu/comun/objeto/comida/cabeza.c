/*  Es una cabeza comestible.
    fichero: cabeza.c
    autor:  [I] Izet@Simauria.
    creacion: 11 de Febrero 1998.
    ultimas modificaciones: 1 Jun, 1998 by [Y] Yandros.
*/

#include "./path.h"

inherit THING;
create() {
  ::create();
    SetShort("una cabeza separada de su cuerpo");
     SetLong(
"La cabeza aun esta caliente, y la sangre chorrea por su cuello degollado\n"
"llenandolo todo de sangre.\n");
   SetIds( ({"cabeza"}) );
   AddAdjective( ({"separada","una","sangrienta","cortada"}) );
   SetSmell("La cabeza despide ese olor tan peculiar que tiene la sangre.\n");
   SetNoise("Mientras juegas con la cabeza puedes escuchar algun 'crack' estimulante.\n");
}

init() {
    ::init();
    add_action("Come","comer");
    add_action("Come","consumir");
}

Come(string str) {
object pota;
  if ( str == "cabeza" || str == "cabeza sangrienta" || str == "cabeza cortada" ||
       str == "cabeza separada") {
   if (TP->QueryRace() == "orco" || TP->QueryRace() == "troll" ||
       TP->QueryRace() == "kainoak" ||
       TP->QueryRace() == "draconiano" || TP->QueryRace() == "demonio") {

       write("Te intentas comer la cabeza, pero es muy dura y no te parece buena idea.\n");
       say(capitalize(getuid(TP))+
       " empieza a morder una cabeza, produciendo unos sonidos estimulantes...\n"
       "... pero desiste de comersela viendo su dureza.\n");
         remove();
         if (TO) destruct(TO);
         return 1;
    }
    if (TP->QueryRace() != "orco" || TP->QueryRace() != "troll" ||
        TP->QueryRace() != "kainoak" ||
	TP->QueryRace() != "draconiano" || TP->QueryRace() != "demonio" ) {
       write(
"Empiezas a pegarle mordiscos a la cabeza produciendo un sonido desgarrador.\n"
"Al empezar a masticar una oreja sientes unas terribles nauseas...\n"
"Buaaaargh! Un liquido amargo, acido y caliente sube por tu garganta...\n"
"Has vomitado.\n");
       say(capitalize(getuid(TP))+
        " empieza a dar mordiscos a una cabeza, y al masticar una oreja\n"
        "vomita justo delante de ti.\n"
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
