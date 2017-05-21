/* Iglesia de Nandor modificada para Kha-annu.
   Agradecimientos al que la hizo.
   Izet@Simauria.
*/
#include "path.h"

inherit KHA_ROOM;

pray() {
  if (!TP) return 0;

  if (TP->QueryGhost()) {
    write("Una poderosa fuerza absorbe tu espiritu y reapareces en forma solida.\n");
    TP->SetGhost(0);
    say(TP->QueryName()+" reaparece en forma solida.\n");
  }
  else {
    if (TP->QueryAlign()< 0) {
      write("Te arrodillas y elevas una plegaria a los dioses locales.\n");
      say(TP->QueryName()
        +" se arrodilla y lanza una piadosa plegaria a los dioses locales.\n");
    }
    else {
      TP->SetHP(TP->QueryMaxHP());
      write ("Te arrodillas y elevas una plegaria a los dioses locales.\n");
      say(TP->QueryName()
        +" eleva una plegaria a los dioses, que le recompensan por su bondad.\n");
      write("Los dioses locales te recompensan por tu bondad.\n");
    }

  }
  return 1;
}
create () {
  object portal;
  ::create();
  SetIntShort("la iglesia de Kha-Annu");
  SetIntLong(
"Esta es la iglesia de estas cavernas llamadas Kha-annu. La luz entra tenue por "
"las vidrieras, reflejando los colores de los cristales. El suelo esta "
"hecho de piedras pulidas a conciencia, y sobre algunas ves unos extranyos "
"signos medio borrados por el tiempo. El altar es un enorme monolito de color "
"negro con extranyas inscripciones. Si has muerto quiza puedas rezar ahi a los "
"dioses locales para conseguir un nuevo cuerpo.\n");
  SetIndoors(1);
  SetLocate("Kha-annu");
  SetIntBright(40);
  AddDetail(({"altar"}),
  "Es una gran roca basaltica sin apenas pulimentar. En los laterales tiene "
  "unos extranyos signos grabados que son apenas legibles, pero que podrian "
  "ser nombres de antiguos dioses hoy olvidados o plegarias. Eso no lo sabras "
  "nunca.\n");
  AddDetail(({"ventanas", "vidrieras"}),
  "Las ventanas estan cubiertas con vidrieras de vivos colores que representan "
  "escenas de una mitologia perdida ya. A pesar de la increible suciedad que "
  "las cubre, las escenas conservan todo su vigor, y por momentos te parece que "
  "los personajes representados cobran vida y se mueven ante tus ojos.\n");
  AddDetail(({"letras", "signos"}),
  "No merece la pena que intentes descifrarlos. Probablemente fueron escritos "
  "en una lengua ya perdida. Sin embargo, casi podrias jurar que esas losas "
  "marcadas son tumbas. Quiza las tumbas de algun sacerdote o noble importante.\n");

  AddRoomCmd("rezar",SF(pray));
  AddExit("norte",CIUDAD+"grimly8");
  AddExit("sur",CIUDAD+"baldur8");

 portal=clone_object("/obj/monolito");
 portal->SetRaza("enano");
 portal->move(TO);

 }