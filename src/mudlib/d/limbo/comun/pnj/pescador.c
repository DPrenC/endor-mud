/*
DESCRIPCION  : Pescador del quest "las llaves del templo de Asthar"
FICHERO      : /d/limbo/comun/pnj/pescador.c
MODIFICACION : 24-09-98 [Angor@Siamuria] Creacion.
// 07-Ene-02 [n] Interceptado el Die() pa que no muera y Zomax deje de dar la
//               co�a
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
"siervos de los dioses que vive en esta isla. Gouraan est� pescando con ca�a, "
"pero por lo que observas carece de la habitual habilidad para ella que se da "
"entre los de su raza. En el cubo que hay a su lado solo hay algunos peque�os "
"pescados que emplea como cebo. Gouraan no parece de muy buen humor. Tal vez "
"deberias preguntarle acerca de la pesca.\n");

  SetIds(({"logath","siervo","Gouraan","gouraan","pescador"}));
  SetAds(({"un","siervo","adulto","pescador"}));
  SetAlign(-200);
  SetAC(3);
  SetNoGet("Gouraan te dice: 'No molestes y d�jame pescar'.\n");
  SetAggressive(0);
  SetGoChance(0);


  InitChats(15,({
  //--------------------------------------------------------------------------------
   "Gouraan dice: '�Por la sangre de Sheeba, no hay forma de que piquen!'\n",
   "Gouraan coloca un trozo de cebo en la ca�a y lanza de nuevo el sedal al agua.\n",
   "Gouraan murmura alguna maldici�n entre dientes.\n",
   "Gourran dice: 'Pero �quereis picar?. �Malditos peces! Quien me mandaria a mi... "
   }));

  AddQuestion(({"pesca"}),
  "Hice una est�pida apuesta con el dios Angor y la perdi. Sheeba me har� perder la "
  "vista como castigo, jam�s debi liarme en semejante asunto. Pero lo hecho, hecho "
  "est�. Debo pescar 50 kilos de pescado y ya ves en el cubo lo que tengo. Adem�s, "
  "para colmo de males hace un rato pic� uno grande pero de un tir�n rompi� el "
  "sedal llev�ndose mi ultimo anzuelo bueno...\n");

  AddQuestion(({"anzuelo"}),
  "Solo me quedan un par de anzuelos peque�os y retorcidos ya que el �ltimo bueno "
  "lo perd� hace un rato cuando pico un pez grande pero, Sheeba le devore las "
  "entra�as, el maldito pego un tir�n y rompi� el sedal de la ca�a. Quiz� con "
  "otro anzuelo los peces picarian m�s, no se.\n");

  AddQuestion(({"angor","Angor"}),
  "Angor es un dios que suele trabajar en esta isla. No es un mal tipo aunque "
  "tiene sus peque�as manias. Hoy no lo he visto aun por aqui.\n");

  AddQuestion(({"apuesta"}),
  "La apuesta... no tiene importancia. Me perdi� mi orgullo, pero juro por Sheeba "
  "que no volver� a ocurrir. Si quieres un consejo, nunca apuestes con un dios. "
  "Como perd� la apuesta debo pescar 50 kilos de pescado para el dios Angor. No se "
  "para que demonios los querra a no ser que se divierta viendo como me hierve la "
  "sangre mientras intento pescarlos. Los de mi raza siempre han sido buenos "
  "pescadores pero desgraciadamente a mi no se me da muy bien. Cuesti�n de "
  "paciencia supongo...\n");

  AddQuestion(({"sheeba","Sheeba"}),
  "�No conoces a Sheeba? No tienes perd�n. Sheeba es la diosa Logath del fuego y el "
  "el hielo, del amor y la guerra. Sheeba es la �nica diosa a la que deberias "
  "venerar si fueses algo m�s inteligente.\n");

  AddQuestion(({"cebo"}),
  "�No toques mi cebo! No es que valga mucho y en una situaci�n normal hasta lo "
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
   "Hay un pu�ado de peque�os pescados en el cubo. Gouran emplea trozos de estos "
   "pescados en en anzuelo de la ca�a para que sirvan de cebo y atraer as� a los "
   "peces.\n");
  return 1;
  }

if ((str!="cubo")&&(str!="cubo de pescado")) return 0;
  write(
   "Junto al lugar donde pesca, Gouraan tiene un viejo cubo en el que guarda el "
   "pescado. La pesca no se le da bien a Gouraan y el cubo est� practicamente vacio "
   "salvo por un pu�ado de peque�os pescados que emplea como cebo para su ca�a.\n");
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
   "con la ca�a en la cara. Eso te ha dolido. Gouran te dice: '�Sheeba te seque las "
   "entra�as! Ya que no ayudas, al menos no molestes'.\n");
   tell_room(environment(TP), ({ MSG_SEE,
  NOMBRE+" ataca a Gouraan, pero este presiente su ataque y lo esquiva para a "
  "continuaci�n revolverse y pegarle con la ca�a en la cara. "+NOMBRE+" desiste.\n"}), ({ TP }));
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
          "Gouraan dice: '�Gracias a Sheeba! Es justo lo que necesitaba. Como recompensa por "
          "tu ayuda te dar� un par de pescados'. Gouraan mira en el cubo del pescado, se "
          "encoge de hombros y te dice dice:'Lo siento, pero lo �nico que tengo son un "
          "pu�ado de peque�os pescados que empleo como cebo y que necesito. De todas "
          "formas te dar� uno, no es que sea gran cosa pero quiz�s te sirva de algo'. "
          "Coges el peque�o pescado y piensas si ha merecido la pena la molestia\n");
    tell_room(environment(TP), ({ MSG_SEE, NOMBRE+" da un anzuelo a Gouraan y este tras mirar en el cubo del pescado le "
        "recompensa con un peque�o pescado. "+NOMBRE+" no parece muy convencid"+AO+".\n"}), ({ TP }));
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
 write(W("Gouraan te mira con extra�eza mientras murmura algo as� como: "
         "'Est�n locos estos "+PO->QueryRace()+"s.'"));
}
