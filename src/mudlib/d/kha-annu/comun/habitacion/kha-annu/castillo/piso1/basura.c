/* Coded by Yandros to AURORA MUD.
   Modificado por [i] Izet@Simauria, para implemental a Nightfall(tm).
   Ultima modificacion: 9 Oct, 1997.
 */
#include "path.h"
#include <moving.h>
inherit KHA_ROOM;

create() {
::create();

SetIntShort("el basurero");

SetIntLong(
"Montanyas y montanyas de basura han sido acumuladas en este lugar durante "
"mucho tiempo. Por tu nariz entra un hedor a podredumbre que te dice que lo "
"mejor que puedes hacer es salir de este lugar o moriras de contener la "
"respiracion. Te preguntas como es que has entrado en esta habitacion.\n");

SetIntBright(70);

AddExit("este", PISO1+"bajada");
AddDetail("basura",
"Las montanyas de basura cubren el suelo y las paredes de esta pequenya "
"estancia y su olor te da nauseas.\n");
}

init()  {
   ::init();

   add_action("olor","oler");
}

olor ()  {
object pota;
   if (TP->QueryHP() < 50)  {
      write(
"Buaaargh! Las nauseas han invadido tus sentidos y sin querer has vomitado "
"mientras corrias hacia la salida.\n "
"Con los ojos cerrados y lagrimosos sales del basurero.\n\n");
      say("La tez de "+TP->QueryName()+
" se ha puesto muy blanca y ha vomitado mientras iba hacia la\n\salida.\n");
      TP->move(PISO1+"bajada",M_GO);
      pota = clone_object(COMIDA("pota"));
      pota->move(environment(TP));
   return 1;
   }
   else  {
      write(
"Buaaargh! Las nauseas han invadido tus sentidos y sin querer has vomitado "
"mientras corrias hacia la salida. Con los ojos cerrados y lagrimosos sales "
"del basurero.\n\n");
      say("La tez de "+TP->QueryName()+
" se ha puesto muy blanca y ha vomitado mientras iba hacia la\n\salida.\n");
      TP->move(PISO1+"bajada",M_GO);
      TP->SetHP((TP->QueryHP())-
		          (random(6)+random(6)+random(6)+random(6)));
      write("\nTe sientes mucho mas debil.\n");
      pota = clone_object(COMIDA("pota"));
      pota->move(environment(TP));
      return 1;
   }
}
