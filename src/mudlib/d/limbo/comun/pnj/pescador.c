/*
DESCRIPCION  : Pescador del quest "las llaves del templo de Asthar"
FICHERO      : /d/limbo/comun/pnj/pescador.c
MODIFICACION : 24-09-98 [Angor@Siamuria] Creacion.
// 07-Ene-02 [n] Interceptado el Die() pa que no muera y Zomax deje de dar la
//               coña
--------------------------------------------------------------------------------
*/

#include "./path.h"     //por PNJ(x)
#include <messages.h>
#include <moving.h>

inherit NPC;

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

create() {
  ::create();
  SetStandard("Gouraan","logath",10,GENDER_MALE);
  SetShort("Gouraan el logath");
  SetLong(
"Gouraan es un logath adulto cuya vestimenta muestra que se trata de uno de los "
"siervos de los dioses que vive en esta isla. Gouraan está pescando con caña, "
"pero por lo que observas carece de la habitual habilidad para ella que se da "
"entre los de su raza. En el cubo que hay a su lado solo hay algunos pequeños "
"pescados que emplea como cebo. Gouraan no parece de muy buen humor. Tal vez "
"deberias preguntarle acerca de la pesca.\n");

  SetIds(({"logath","siervo","Gouraan","gouraan","pescador"}));
  SetAds(({"un","siervo","adulto","pescador"}));
  SetAlign(-200);
  SetAC(3);
  SetNoGet("Gouraan te dice: 'No molestes y déjame pescar'.\n");
  SetAggressive(0);
  SetGoChance(0);


  InitChats(15,({
  //--------------------------------------------------------------------------------
   "Gouraan dice: '¡Por la sangre de Sheeba, no hay forma de que piquen!'\n",
   "Gouraan coloca un trozo de cebo en la caña y lanza de nuevo el sedal al agua.\n",
   "Gouraan murmura alguna maldición entre dientes.\n",
   "Gourran dice: 'Pero ¿quereis picar?. ¡Malditos peces! Quien me mandaria a mi... "
   }));

  AddQuestion(({"pesca"}),
  "Hice una estúpida apuesta con el dios Angor y la perdi. Sheeba me hará perder la "
  "vista como castigo, jamás debi liarme en semejante asunto. Pero lo hecho, hecho "
  "está. Debo pescar 50 kilos de pescado y ya ves en el cubo lo que tengo. Además, "
  "para colmo de males hace un rato picó uno grande pero de un tirón rompió el "
  "sedal llevándose mi ultimo anzuelo bueno...\n");

  AddQuestion(({"anzuelo"}),
  "Solo me quedan un par de anzuelos pequeños y retorcidos ya que el último bueno "
  "lo perdí hace un rato cuando pico un pez grande pero, Sheeba le devore las "
  "entrañas, el maldito pego un tirón y rompió el sedal de la caña. Quizá con "
  "otro anzuelo los peces picarian más, no se.\n");

  AddQuestion(({"angor","Angor"}),
  "Angor es un dios que suele trabajar en esta isla. No es un mal tipo aunque "
  "tiene sus pequeñas manias. Hoy no lo he visto aun por aqui.\n");

  AddQuestion(({"apuesta"}),
  "La apuesta... no tiene importancia. Me perdió mi orgullo, pero juro por Sheeba "
  "que no volverá a ocurrir. Si quieres un consejo, nunca apuestes con un dios. "
  "Como perdí la apuesta debo pescar 50 kilos de pescado para el dios Angor. No se "
  "para que demonios los querra a no ser que se divierta viendo como me hierve la "
  "sangre mientras intento pescarlos. Los de mi raza siempre han sido buenos "
  "pescadores pero desgraciadamente a mi no se me da muy bien. Cuestión de "
  "paciencia supongo...\n");

  AddQuestion(({"sheeba","Sheeba"}),
  "¿No conoces a Sheeba? No tienes perdón. Sheeba es la diosa Logath del fuego y el "
  "el hielo, del amor y la guerra. Sheeba es la única diosa a la que deberias "
  "venerar si fueses algo más inteligente.\n");

  AddQuestion(({"cebo"}),
  "¡No toques mi cebo! No es que valga mucho y en una situación normal hasta lo "
  "tiraria, pero ahora lo necesito para poder pescar los 50 kilos de pescado.\n");

  AddQuestion(({"playa","playa de levante","playa de Levante"}),
  "La playa de Levente queda al nordeste de esta isla como todo el mundo sabe.\n");

  AddQuestion(({"llaves","llaves del templo"}),
  "No se, supongo que las debe tener Asthar. No es algo que me incumba.\n");
Set(P_CANT_FIGHT,1);
Set(P_CANT_STEAL,1);

}

init() {
  ::init();
  add_action("matar_cmd","matar");
  add_action("dar_cmd", "dar");
  add_action("coger_cmd", "coger");
  add_action("mirar_cmd", "mirar");
  add_action("mirar_cmd", "m");
}

int coger_cmd(string str){
if ((str!="cebo")&&(str!="cubo")) return 0;
  write("El "+str+" es de Gouraan, y con el mal humor que tiene hoy mejor no molestarle.\n");
  return 1;
}

int mirar_cmd(string str){
if (str=="cebo"){
  write(
   "Hay un puñado de pequeños pescados en el cubo. Gouran emplea trozos de estos "
   "pescados en en anzuelo de la caña para que sirvan de cebo y atraer así a los "
   "peces.\n");
  return 1;
  }

if ((str!="cubo")&&(str!="cubo de pescado")) return 0;
  write(
   "Junto al lugar donde pesca, Gouraan tiene un viejo cubo en el que guarda el "
   "pescado. La pesca no se le da bien a Gouraan y el cubo está practicamente vacio "
   "salvo por un puñado de pequeños pescados que emplea como cebo para su caña.\n");
   tell_room(environment(TP), ({ MSG_SEE, NOMBRE+" mira el cubo de pescado de Gouraan.\n"}), ({ TP }));
return 1;
}

// KoRSaRio: otro bugss :) pusieras matar lo que kisieras siempre
//intentaba matarlo a el... faltaba el str y la comprobacion...
//[Nyh] pa que en todos sea igual pongo yo mi linea
int matar_cmd(string str){
  object who;
  int hp;
  who=TP;
 //if(str!="gouraan") return 0;
   if (present(str, environment(who)) != TO) return 0;
  who->StopHunting(TO);
  write(
   "Gouraan tiene como un sexto sentido ademas de una gran agilidad. Cuando vas a "
   "golpearle, se aparta en el ultimo momento. A continuacion se revuelve y te pega "
   "con la caña en la cara. Eso te ha dolido. Gouran te dice: '¡Sheeba te seque las "
   "entrañas! Ya que no ayudas, al menos no molestes'.\n");
   tell_room(environment(TP), ({ MSG_SEE,
  NOMBRE+" ataca a Gouraan, pero este presiente su ataque y lo esquiva para a "
  "continuación revolverse y pegarle con la caña en la cara. "+NOMBRE+" desiste.\n"}), ({ TP }));
  return 1;
}

int dar_cmd(string str) {
 object from, key;
 int mov;
 string a;
 from=TP;
 if (!from || !str) return 0;
 if ((sscanf(str,"%s a pescador",a)==1)||
     (sscanf(str,"%s a logath",a)==1)||
     (sscanf(str,"%s a gouraan",a)==1)||
     (sscanf(str,"%s a Gouraan",a)==1)) {
    object ob;
    ob  =  present(a,TP);
    if (!ob || !call_other(ob,"id","anzuelo")) return 0;
    write("Le das el anzuelo a Gouraan. "
          "Gouraan dice: '¡Gracias a Sheeba! Es justo lo que necesitaba. Como recompensa por "
          "tu ayuda te daré un par de pescados'. Gouraan mira en el cubo del pescado, se "
          "encoge de hombros y te dice dice:'Lo siento, pero lo único que tengo son un "
          "puñado de pequeños pescados que empleo como cebo y que necesito. De todas "
          "formas te daré uno, no es que sea gran cosa pero quizás te sirva de algo'. "
          "Coges el pequeño pescado y piensas si ha merecido la pena la molestia\n");
    tell_room(environment(TP), ({ MSG_SEE, NOMBRE+" da un anzuelo a Gouraan y este tras mirar en el cubo del pescado le "
        "recompensa con un pequeño pescado. "+NOMBRE+" no parece muy convencid"+AO+".\n"}), ({ TP }));
    ob->remove();
    ob=clone_object(OTRO("pescado"));
    if (mov = ob->move(TP) != ME_OK)
    {
        write("Sin poder evitarlo, el pescado se te cae al suelo.\n");
        say("A " + CAP(TNAME) + " se le cae el pescado al suelo.\n", TP);

        ob->move(environment(TP), M_NOCHECK);
    }
    return 1;
   }
   return 0;
}

public void Die() {
 write(W("Gouraan te mira con extrañeza mientras murmura algo así como: "
         "'Están locos estos "+PO->QueryRace()+"s.'"));
}
