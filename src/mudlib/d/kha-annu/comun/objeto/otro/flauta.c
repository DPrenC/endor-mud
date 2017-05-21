/* [Woo] Modificado */

#include "./path.h"
#include <properties.h>


inherit THING;

int llamada;
create() {
 ::create();
 SetIds(({"llamador","flauta"}));
 SetAds(({"un","dorada"}));
 SetShort("una flauta dorada");
 SetLong(
"Esta es la flauta para llamar a tu mascota. Reluce como el oro, aunque parece\n"
"que no está hecha de ese metal. Para avisar a tu mascota usa 'llamar mascota'\n"
"y una pantera sin nombre acudira a tu encuentro.\n");

 SetWeight(10);
 SetValue(0);
 Set(P_NODROP,1);
 Set(P_NOSELL,1);
 Set(P_AUTOOBJECT,1);
}

init () {
  ::init();
     llamada=0;
     add_action("llamar","llamar");
     add_action("asustar","asustar");
}

llamar (string str) {
object pantera;
   if (llamada==1) {
     write("Pero si la mascota ya esta aquí, ¿para que vas a llamarla?\n");
     return 1;
   }
   else {
      if ((str!="mascota") && (str!="pantera") && (str!="la mascota") &&
          (str!="la pantera")) {
             write("\n¿A quien o a qué quieres llamar?\n");
             return 1;
      }
      else {
             write(
"De repente y sin saber como una armoniosa melodia sale de tu ser y la\n"
"conduces al exterior a través de tu flauta dorada.\n");
             seteuid(getuid(TO));
             pantera=clone_object("/players/izet/pnj/pantera");
             llamada=1;
             pantera->move(environment(TP));
             write("Tu pantera negra de combate a acudido a tu llamada.\n");
             write("Para hacer que se marche usa 'asustar pantera'.\n");
             say("La pantera de "+TP->QueryName()+" ha llegado.\n");
             return 1;
           }
   }
}
asustar (string str) {

      if ((str != "mascota") && (str != "pantera"))
        {
         write("¿A quien o a qué quieres asustar?\n");
         return 1;
        }
       else {
         write("Empiezas a pegar berridos a tu pantera negra y esta huye.\n");
         return 1;
        }
}
