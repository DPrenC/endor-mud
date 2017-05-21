/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   [l] Lonerwolf
 *   Creacion: 16 Oct, 1997
 *   Fran@Simauria modificandorrrr
 *   [l]23/10/00 le comente la variable tester que no se esta usando
 *      y daba problemas
 *   Ultima modificacion: 23 Oct, 2000.
 */

#include "path.h"
#include <properties.h>
#include <door.h>

inherit KHA_ROOM;

/* object book;
int tester;
*/

create() {
  ::create();
  // tester = 0;
  SetIntShort("una habitación de invitados");
  SetIntLong("Estas en la habitacion de una dama. El ambiente es oscuro"
           "ya que todos los muebles estan pintados de negro. Hay "
           "una mesa y una alfombra con simbolos extranyos grabados. "
           "Tambien hay una cama y un sillon todos negros... un escalofrio "
           "recorre tu espalda al pensar quien puede dormir aqui."
           "Hay un poco de luz de unas lamparas extranyas en el techo.\n");
  SetIntBright(50);

    AddExit("este",PISO2+"piso2_8");
    AddDoor("este","la puerta del pasillo","Es una puerta de madera, adornada con paneles de cristal.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}), GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));
  AddDetail( ({"lampara","lamparas"}),
   "Ves lamparas con piedras negras que cuelgan del techo y que despiden una luz "
   "que es casi oscura... tetrica...\n");

    AddDetail("suelo","Puedes ver el la alfombra negra... muy tetrica...\n");

  AddDetail("mesa","Esta mesa esta grabada con simbolos extranyos y hay"
           "pequenyos cortes en la madera...de que seran???\n");
  AddDetail("cama","Una cama con sabanas negras y con un par de  "
           "cojines.\n");
  AddDetail("sillon","Un sillon negro, parece confortabe, pero mejor no sentarse.");
  AddDetail(({"alfombra","alfombra negra"}),"La alfombra negra esta decorada con "
           "simbolos extranyos.\n");
}
/*
init()  {
   ::init();
   add_action("coger","coger");
   add_action("mirar","m");
   add_action("mirar","mi");
   add_action("mirar","mir");
   add_action("mirar","mira");
   add_action("mirar","mirar");
   add_action("mirar","exa");
}

int coger (string str)  {
   if ((str != "0 from 0") && (str != "all from all") && (str != "book from 0")
       && (str != "book from table") && (str != "0 from table")
       && (str != "book from all") && (str != "all from table")
       && (str != "all from 0") && (str != "0 from all")) {
          return 0;
       }
   else {      if (tester == 0) {
         write("You get a book from the night table.\n");
         say(TP->query_cap_name()+" gets a book from the night "
             "table.\n");
         book=clone_object(OBJS+"wbook");
         book->move(TP);
         tester = 1;
         return 1;
      }
      if (tester == 1) {
         write("There isn't anything on the night table.\n");
         return 1;
      }
   }
}
int mirar(string str) {

   if ((str != "table") && (str != "night table")) {
      return 0;
   }
   else {
      if (tester == 0) {
         write("There is a book over the night table.\n");
         say(TP->query_cap_name()+" looks at the night table.\n");
         return 1;
      }
      if (tester == 1) {
         write("This a a black night table. You don't see nothing special.\n");
         say(TP->query_cap_name()+" looks at the night table.\n");
         return 1;
      }
   }

   }*/