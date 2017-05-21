/*  Son unas entranyas comestibles.
    fichero: entranyas.c
    autor:  [I] Izet@Simauria.
    creacion: 11 de Febrero 1998.
    ultimas modificaciones: 1 Jun, 1998 by [Y] Yandros.
*/

#include "./path.h"

inherit THING;
create() {
  ::create();
    SetShort("unos intestinos sanguinolentos");
     SetLong(
"Te preguntas como es que has cogido esto. Son molestos y se resbalan entre\n"
"tus manos.\n");
   SetIds( ({"intestinos"}) );
   AddAdjective( ({"sanguinolentos","unos"}) );
   SetSmell("Tienen un curioso olor a comida en estado de putrefaccion.\n");
   SetNoise("Empiezas a jugar con los intestinos entre tus manos, produciendo un suave\n"
            "gorgoteo.\n");
}

init() {
    ::init();
    add_action("Come","comer");
    add_action("Come","consumir");
}

Come(string str) {
object pota;
  if ( str == "intestinos" || str == "unos intestinos" ||
       str == "intestinos sanguinolentos" || str == "unos intestinos sanguinolentos") {
   if (TP->QueryRace() == "orco" || TP->QueryRace() == "troll" ||
       TP->QueryRace() == "kainoak" ||
       TP->QueryRace() == "draconiano" || TP->QueryRace() == "demonio") {

       write("Introduces los babosos intestinos en tu boca y los masticas.\n"
             "Te sientes algo mejor.\n");
       say(capitalize(getuid(TP))+
              " saca unos intestinos babosos y sanguinolentos y empieza a\n"
              "comerselos. Es asqueroso oir el sonido el masticarlos.\n");
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
"Introduces una parte de los intestinos en tu boca. El olor de la sangre te\n"
"produce nauseas y te preguntas por que estas haciendo esto.\n"
"Buaaaargh! Un liquido amargo, acido y caliente sube por tu garganta...\n"
"Has vomitado.\n");
       say(capitalize(getuid(TP))+
      " introduce un trozo de intestino baboso y sangriento en su boca...\n"
        "... y vomita.\n"
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
