/*  Es una pota comestible.
    fichero: pota.c
    autor:  [I] Izet@Simauria.
    creacion: 11 de Febrero 1998.
    ultimas modificaciones: 1 Jun, 1998 by [Y] Yandros.
*/

#include "./path.h"

inherit THING;
create() {
  ::create();
    SetShort("un brazo desmembrado salvajemente");
     SetLong(
"Sin lugar a dudas, estuvo en mejor lugar anteriormente. Su propietario no\n"
"vendra a reclamarlo, asi que tal vez puedas quedartelo.\n");
   SetIds( ({"brazo"}) );
   AddAdjective( ({"desmembrado","un","sangriento","partido"}) );
    SetSmell("Puag! ni en suenyos hubieses intentado oler un brazo en este estado.\n");
    SetNoise("Mientras juegas con el brazo, puedes escuchar algun crack estimulante.\n");
}

init() {
    ::init();
    add_action("Come","comer");
    add_action("Come","consumir");
}

Come(string str) {
object pota;
  if ( str == "brazo" || str == "brazo desmembrado" || str == "brazo sangriento" ||
       str == "brazo partido") {
   if (TP->QueryRace() == "orco" || TP->QueryRace() == "troll" ||
       TP->QueryRace() == "kainoak" ||
       TP->QueryRace() == "draconiano" || TP->QueryRace() == "demonio") {

       write("Te comes el brazo... y te sientes mejor.\n");
       say(capitalize(getuid(TP))+
                                " se come un brazo. Es repugnante.\n");
         if (TP->QueryHP() == TP->QueryMaxHP()+5 ||
             TP->QueryHP() == TP->QueryMaxHP()+4 ||
             TP->QueryHP() == TP->QueryMaxHP()+3 ||
             TP->QueryHP() == TP->QueryMaxHP()+2 ||
             TP->QueryHP() == TP->QueryMaxHP()+1 ||
             TP->QueryHP() == TP->QueryMaxHP() ) {return 1;}
          else { TP->SetHP(TP->QueryHP()+5); }
         remove();
         if (TO) destruct(TO);
         return 1;
    }
    if (TP->QueryRace() != "orco" || TP->QueryRace() != "troll" ||
        TP->QueryRace() != "kainoak" ||
        TP->QueryRace() != "draconiano" || TP->QueryRace() != "demonio" ) {
       write(
"Te has comido el brazo. Sin lugar a dudas tienes agallas, pero sientes nauseas.\n"
"Buaaaargh! Un liquido amargo, acido y caliente sube por tu garganta...\n"
"Has vomitado.\n");
       say(capitalize(getuid(TP))+
        " se come un brazo descuartizado y vomita justo delante de tus pies.\n"
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
