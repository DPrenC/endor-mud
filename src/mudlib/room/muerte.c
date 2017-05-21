/* Death  (Mateese, 28-Aug-92)
   slighlty updated, Pepel, 8-Jan-95

   muerte.c
   Tradussio por [I] Izet@Simauria.
 Creacion: 12 Enero, 1997.
 Ultima modificacion: 12 Enero, 1997.
*/

#include <properties.h>   /* para las propiedades 'sesuales' de la muerte */

inherit "/std/npc";

/*-------------------------------------------------------------------------*/

create () {

  ::create();
  SetName ("Muerte");
  AddId ("guadanya");
  AddId ("tunica");

  SetShort ("La Muerte");
  SetRace ("inmortal");
  Set(P_DEFENCES, ({ 50 }) );
  Set(P_HANDS,({ ({ "mano derecha", 0, 25 }), ({"mano izquierda", 0, 25 }) }));
}

/*-------------------------------------------------------------------------*/

init() {
  ::init();
  add_action("Coger", "coger");
  add_action("Coger", "robar");
}

/*-------------------------------------------------------------------------*/

/* hack alert */
static private string lastid;
id(s) { if (::id(s)) { lastid = s; return 1; } }

Long (str) {

  if (lastid == "muerte")
    return
"Es la Muerte. Va vestida con una tunica negra y en su mano derecha empunya una\n\
guadanya. Bajo su capa puedes acertar a ver las cuencas de los ojos de este\n\
misterioso ser y, al hacerlo, sientes un frio intenso que penetra en lo mas\n\
profundo de tu alma.\n";

  if (lastid == "guadanya")
    return
"Es una guadanya extremadamente afilada, tanto que hasta el viento intenta\n"
"apartarse de su hoja para no ser cortado en dos por la gran hoja curva.\n"
"La luz a su alrededor hace extranyas formas al chocar contra el filo de\n"
"esta guadanya.\n";

  if (lastid == "tunica")
    return
"Es una tunica negra con muchos bolsillos, sin embargo piensas que pueda no\n"
"quedarte bien. Parece que ha sido hecha para alguien muy delgado. REALMENTE\n"
"delgado...\n";

  return 0;
}

/*-------------------------------------------------------------------------*/

Coger(str) {

  if (str == "guadanya" || str == "tunica") {
    int extra;
    extra = random(90) + 10;
    write (
"Agarras firmemente la " + str + " e intentas tirar de ella hacia ti.\n\n"
"ESTUPIDO MORTAL. TE HAS GANADO " + extra + " ANYOS EXTRA EN EL PURGATORIO!\n"
"La Muerte hace una horrorosa mueca y te arrastra de los dedos con su mano\n"
"huesuda.\n"
          );
    TP->SetExplored();
    return 1;
  }
}
