/*
DESCRIPCION  : Red cazacangrejos para el quest de "las llaves del templo de Asthar"
FICHERO      : /d/limbo/comun/obj/otro/cazacangrejos.c
MODIFICACION : 22-09-98 [Angor@Simauria] Creacion.
		28-07-00 [t] Adaptada para salvar el estado de 'cebada'.
--------------------------------------------------------------------------------
*/

#include <config.h> //[a] anayadido por NOTIFY_NOT_CMD
#include <messages.h>

inherit THING;
#include <properties.h>
#define NOMBRE  (capitalize(TP->QueryName()))

static int cebada;

create() {
  ::create();

  SetIds(({"red","cazacangrejos","red cazacangrejos"}));
  AddAdjective(({"una"}));

  SetWeight(250);
  SetValue(4);
  Set(P_NOSELL,1);
  cebada=0;
}

init() {
  ::init();
  add_action("cebar_cmd","cebar");
  add_action("usar_cmd","usar");
}

int cebar_cmd(){
  object who;
  object ob;

  if (cebada==0){
      who=TP;
      ob  =  present("pescado",TP);
      if (!ob || !call_other(ob,"id","pescado_quest")) {
            write("Lo que tienes en tu inventorio no sirve para cebar la red cazacangrejos.\n");
            return 1;
            };
      write("Colocas el pequenyo pescado en el fondo de la red. Ahora esta cebada y lista\n"
            "atrapar cangrejos.\n");
      tell_room(environment(TP), ({ MSG_SEE, NOMBRE+" ceba una red cazacangrejos con un pequenyo pescado.\n"}), ({ TP }));
      ob->remove();
      cebada=1;
      }
  else write("La red ya esta cebada. No necesitas hacerlo de nuevo.\n");
  return 1;
}

int usar_cmd(string str){
    string tmp,que,donde;
    if (!str) return 0;
    if (sscanf(str,"%s con %s",que,donde)<2) return 0;
    if ((que=="cebo")||(que=="pescado")||(donde=="cebo")||(donde=="pescado")){
       if ((donde=="cebo")||(donde=="pescado")){tmp=donde; donde=que; que=tmp;}
       if (donde!="red") return notify_fail("Usar cebo con que?\n",NOTIFY_NOT_VALID)&&0;
       return cebar_cmd();
       return 1;
       }
    return 0;
}


int QueryCebada(){return cebada;}
int SetCebada(int c){return cebada=c;}
string QueryShort() {
  if (!QueryCebada())
    return "una red cazacangrejos";
  else
    return "una red cazacangrejos cebada";
}
string QueryLong() {
  if (!QueryCebada())
    return
   	"Es una red para cazar cangrejos. Tiene forma de bolsa con una apertura en forma "
    "de embudo que apunta hacia adentro. El mecanismo es muy sencillo: se ceba la red "
	"con algo de pescado fresco y el cangrejo que entra atraido por el, queda "
   	"entonces atrapado en su interior.\n";
  return
      	"Es una red para cazar cangrejos. Tiene forma de bolsa con una apertura en forma "
      	"de embudo que apunta hacia adentro. El mecanismo es muy sencillo: se ceba la red "
      	"con algo de pescado fresco y el cangrejo que entra atraido por el, queda "
      	"entonces atrapado en su interior. La red esta ahora cebada con pescado.\n";
}
int descebar(){
 cebada=0;
 return 1;
}
