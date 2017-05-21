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
    SetShort("una pierna desmembrada salvajemente");
     SetLong(
"Sin lugar a dudas, estuvo en mejor lugar anteriormente. Su propietario no\n"
"la reclamara y seguro que podras quedartela.\n");
   SetIds( ({"pierna"}) );
   AddAdjective( ({"desmembrada","una","sangrienta","partida"}) );
   SetSmell("Puag! ni en suenyos hubieses olido una pierna en este estado.\n");
   SetNoise("Mientras juegas con la pierna, escuchas unos 'cracks' estimulantes.\n");
}

init() {
    ::init();
    add_action("Come","comer");
    add_action("Come","consumir");
}

Come(string str) {
object pota;
  if (str == "pierna" || str == "pierna desmembrada" || str == "pierna sangrienta" ||
       str == "brazo partido") {
   if (TP->QueryRace() == "orco" || TP->QueryRace() == "troll" ||
       TP->QueryRace() == "kainoak" ||
       TP->QueryRace() == "draconiano" || TP->QueryRace() == "demonio") {

       write("Te comes la pierna... y te sientes mejor!\n");
       say(capitalize(getuid(TP))+
                                " se come una pierna. Es repugnante.\n");
          if (TP->QueryHP() == TP->QueryMaxHP()+10 ||
              TP->QueryHP() == TP->QueryMaxHP()+9 ||
             TP->QueryHP() == TP->QueryMaxHP()+8 ||
             TP->QueryHP() == TP->QueryMaxHP()+7 ||
             TP->QueryHP() == TP->QueryMaxHP()+6 ||
             TP->QueryHP() == TP->QueryMaxHP()+5 ||
             TP->QueryHP() == TP->QueryMaxHP()+4 ||
             TP->QueryHP() == TP->QueryMaxHP()+3 ||
             TP->QueryHP() == TP->QueryMaxHP()+2 ||
             TP->QueryHP() == TP->QueryMaxHP()+1 ||
             TP->QueryHP() == TP->QueryMaxHP() ) {return 1;}
          else { TP->SetHP(TP->QueryHP()+10); }
         remove();
         if (TO) destruct(TO);
         return 1;
    }
    if (TP->QueryRace() != "orco" || TP->QueryRace() != "troll" ||
        TP->QueryRace() != "kainoak" ||
        TP->QueryRace() != "draconiano" || TP->QueryRace() != "demonio" ) {
       write(
"Te comes la pierna. Sin lugar a dudas tienes agallas, pero sientes nauseas.\n"
"Buaaaargh! Un liquido amargo, acido y caliente sube por tu garganta...\n"
"Has vomitado.\n");
       say(capitalize(getuid(TP))+
        " empieza a morder una pierna... y vomita delante de tus pies.\n"
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
