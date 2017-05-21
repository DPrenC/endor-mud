/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "path.h"
#include <moving.h>

inherit KHA_ROOM;

int puerta;

int ir_sur();

#define ALIN TP->QueryAlign()
#define CNOMBRE capitalize(TNAME)

create() {
  ::create();
  puerta = 0;
  SetIntShort("el segundo piso del castillo en Kha-annu");
  SetIntLong(
"Te encuentras en un corredor frente a dos grandes puertas negras "
"fabricadas en hierro en la segunda planta del castillo. Tras estas puertas "
"debe de encontrarse el salon del trono de Belthain, senyor de estas "
"cavernas llenas de riquezas, y de todo el dominio delimitado por las "
"montanyas de Kha-annu.\n");

  SetIndoors(1);

  SetIntBright(70);

  AddExit("norte",PISO2+"piso2_5");
  AddExit("puertas",SF(ir_sur));
  HideExit("puertas");

  AddDetail(({"lampara","lamparas","lampara de diamantes",
              "lamparas de diamantes",}),
"Las lamparas del techo estan hechas con diamantes engarzados entre si. De "
"ellas fluyen luces de todos los colores en toda la estancia.\n");
  AddDetail("suelo","Ves tu propio reflejo en el suelo junto con el juego de "
"            luces que crean las lamparas del techo.\n");
  AddDetail(({"paredes","pared",}),
"Son paredes de pura roca tallada, cubiertas de finas lineas de oro.\n");
  AddDetail(({"corredor","trono","salon del trono","salon"}),
"No puedes ver el salon del trono, pero estas casi seguro de que se "
"encuentra tras las puertas.\n");
  AddItem(MONS+"guardia",REFRESH_DESTRUCT,2);

}

init() {
   remove_call_out("puerta_abierta");
   remove_call_out("puerta_cerrada");
  ::init();
  add_action("llamar","llamar");
  add_action("mira_puerta","m");
  add_action("mira_puerta","mi");
  add_action("mira_puerta","mir");
  add_action("mira_puerta","mira");
  add_action("mira_puerta","mirar");
  add_action("mira_puerta","exa");
  add_action("mira_puerta","examinar");
}

llamar(string knocker) {
  if (!knocker || (knocker != "puerta" && knocker != "puertas" &&
      knocker != "a puerta" && knocker != "a puertas" &&
      knocker != "en puerta" && knocker != "en puertas" &&
      knocker != "a la puerta" && knocker != "a las puertas" &&
      knocker != "en la puerta" && knocker != "en las puertas" &&
      knocker != "la puerta" && knocker != "las puertas")) {
    write("Llamar a donde?\n");
    return 1;
  }
  if((find_call_out("puerta_abierta") < 0) && (puerta==0)){
    call_out("puerta_abierta",5);
    write("\nLlamas a las grandes puertas.\n");
    say(CNOMBRE+ " llama a las grandes puertas.\n");
    write("Toc! Toc! Toc!\n");
  }
  else if (puerta==0) write("Unos pasos suenan tras las puertas.\n");
  else write("Las puertas ya estan abiertas, para que llamar?\n");
  return 1;
}

mira_puerta(string knocker)  {
  if (!knocker || (knocker != "puerta" && knocker != "puertas" &&
      knocker != "a puerta" && knocker != "a puertas" &&
      knocker != "en puerta" && knocker != "en puertas" &&
      knocker != "a la puerta" && knocker != "a las puertas" &&
      knocker != "en la puerta" && knocker != "en las puertas" &&
      knocker != "la puerta" && knocker != "las puertas")) {
   return 0;
  }
   else  {

   if (puerta == 0)  {
      write("Las puertas estan cerradas. Deberias llamar si quieres "
            " cruzarlas.\n");
      say(CNOMBRE+ " mira las grandes puertas.\n");
      return 1;
    }
    if (puerta == 1)   {
      write("Las puertas estan abiertas. Podrias pasar si quisieras.\n");
      say(CNOMBRE+ " mira las grandes puertas.\n");
      return 1;
    }

  }
}

puerta_abierta() {
  tell_room(TO,
"Unos pasos suenan tras las puertas y de repente se abren y un enano muy "
"feo asoma la cabeza y te examina de pies a cabeza.\n");

  tell_room(TO,
"El feo enano dice: Esta bien, puedes pasar... pero se breve y cuidadoso, "
"                   el rey Belthain no esta de muy buen humor.\n");
  puerta = 1;

  call_out("puerta_cerrada",50);
}
puerta_cerrada() {
  tell_room(TO,"El feo enano murmura algo y desaparece.\n"
                          "Las puertas estan cerradas de nuevo.\n");
  puerta = 0;
}

apresado ()  {
int tirada;
   tirada = random(TP->QueryDex());
   if (tirada >= 10 || tirada == 0) {
      write(
"Diestramente logras despistar a todos los soldados en los pasillos del "
"castillo y logras salir sin problema alguno.\n");
      TP->move(PISO1+"garden",M_GO);
      return 1;
   }
   else {
      write(
"Echas a correr intentando huir de los diez soldados que han acudido a la "
"llamada, pero estos logran alcanzarte y te apresan.\n");
      write(
"Los soldados te conducen hasta una celda en las mazmorras del castillo.\n");
      tell_room(DUNGEONS+"celda2","Diez soldados traen a un "+TP->QueryRace()+
		                " y lo lanzan contra el suelo.\n");
      TP->move(DUNGEONS+"celda2",M_GO);
      tell_room(DUNGEONS+"celda2",
                          "Los soldados cierran de un portazo.\n");
      puerta = 0;
      return 1;
   }
}

int ir_sur()  {

  if (puerta == 0)  {
    write(
"\nAl intentar ir al salon del trono golpeas contra las puertas que se "
"encontraban cerradas.\n");
    say(
CNOMBRE+" intenta entrar al salon del trono y se golpea contra las puertas.\n");
    return 1;
  }

  if (puerta == 1)  {
     if (ALIN <= -100)   {
       tell_room(TO,
"De repente aparece un enano de detras de las puertas y grita:\n"
"'OH NO! Un ser de los abismos infernales! Eh, tu! Tu presencia aqui no es "
"bienvenida! SOLDADOS APRESAD A ESE SER INFERNAL!!!'\n");
       call_out("apresado",5);
       say(CNOMBRE+" comienza a correr huyendo de unos diez soldados.\n");
       return 1;
     }
     else  {
       write(
"Cruzas las grandes puertas del trono hacia el sur y entras en el salon del "
"trono\n");
       say(CNOMBRE+" cruza las grandes puertas hacia el sur.\n");
       TP->move(PISO2+"hall",M_GO);
       return 1;
     }
   }
}