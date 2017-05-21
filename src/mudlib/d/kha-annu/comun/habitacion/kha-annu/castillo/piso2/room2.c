/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
   [F]  Fran@simauria   9-9-2000 cambio detalles a espanyol
   [n]  Nemesis@simauria
        [27-11-2000] Añadido el comando al add_action de "tirar"
                    porque si no, petaba. Otra cosa, como comentario...
                    Ya que lo pasas a español, pon acentos y eñes,...
                    y traduce TODO el texto, ok? Las funciones incluídas.
                    Gracias.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 27 Nov, 2000.
 *   15-05-2008 Melones! 12 años y aun tenia partes en ingles! traducido al fin. Angor
 */

#include "path.h"
#include <properties.h>
#include <door.h>


inherit KHA_ROOM;

int cuadro;
int picture;
int tester;

create() {
  ::create();
 picture = 0;
  tester =  0;
  SetIntShort("una habitación de invitados en el castillo");
  SetIntLong(
"Estas en la habitacion de un noble. La estancia carece de mobiliario, algo "
"extranyo en este castillo. Solo ves una mesilla de noche algo desvencijada.\n"
"Tambien hay un cuadro en la pared norte.\n"
  );
  SetIntBright(70);

    AddExit("este",PISO2+"piso2_2");
    AddDoor("este","la puerta del pasillo",
        "Un rectángulo de madera, aunque..., con un primoroso acabado.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}), GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));

AddDetail(({"lampara techo","lamparas de techo","lamparas","lampara",}),
"Las lamparas del techo estan hechas de diamantes.Hay un brillo "
"increible en toda la estancia.\n");
AddDetail("suelo","Puedes ver el reflejo de las lamparas en el suelo.\n");
AddDetail(({"paredes","pared",}),"Las paredes estan hechas de puro granito, con "
"una decoracion de filigranas de oro.\n");
AddDetail("cuadro","Es un cuadro de un orco feo. Adorable...\n");
}

init()  {
   ::init();
   add_action("tirar","tirar");
   add_action("empujar","push");
   add_action("examinar","exa");
   add_action("examinar","m");
   add_action("examinar","mi");
   add_action("examinar","mir");
   add_action("examinar","mira");
   add_action("examinar","mirar");
}

tirar(string str)  {
    if (str != "cuadro")   {
    notify_fail("¿Tirar de QUE?\n");
      return 0;
   }
   else  {
    if (cuadro == 0)  {
        write("Tiras del cuadro con cuidado y escuchas un click."
   "Encuentras un agujero detras del cuadro.\n");
say(TP->query_cap_name()+" empuja algo en la pared norte.\n");
    cuadro = 1;
        return 1;
      }
      if (picture == 1)  {
       write("El cuadro ha sido movido ya. No hace falta moverlo mas.\n");
        return 1;
      }
   }
}

empujar (string str) {
   if (str != "cuadro")  {
     notify_fail("Empujar QUE?");
      return 0;
   }
   else  {
      if (picture == 1) {
	 write("Empujas el cuadro y no pasa nada.\n");
	 say(TP->query_cap_name()+" empuja el cuadro.\n");
     cuadro = 0;
	 return 1;
      }
      if (picture == 0)  {
	 write("¿Por qué empujarlo, acaso quieres romperlo?\n");
	 return 1;
      }
   }
}

examinar(string str)  {
   if ((picture == 0) && (str !="cuadro")) {
      notify_fail("Examinar QUE?\n");
      return 0;
   }
   else  {
      if ((picture == 0) && ((tester == 0) || (tester == 1)))  {
	 write("Examinas el cuadro cuidadosamente y te das cuenta que está "
	 "fijado a la pared por medio de unas pequeñas bisagras... Quizá "+
	 "podrías empujar o tirar de él.\n");
         say(TP->query_cap_name()+" examina el cuado del muro norte.\n");
         return 1;
      }
   }

   if ((picture == 1) && (str !="agujero")) {
      notify_fail("Examinar QUE?\n");
      return 0;
   }
   else  {
      if ((picture == 1) && (tester == 0)) {
	 write("Miras en el agujero y encuentras un montón de monedas.\n");
	 //TP->clone_object(OTRO("orchand"));
	 TP->adjust_money(random(50)+50,"gold");
         say(TP->query_cap_name()+" coge algo de un agujero en el muro.\n");
	 tester = 1;
	 return 1;
     }
     if ((picture == 1) && (tester == 1)) {
         write("El agujero solo contiene polvo.\n");
         return 1;
     }
   }
}