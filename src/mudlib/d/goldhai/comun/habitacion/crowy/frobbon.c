/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 02-07-00                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <moving.h>


inherit GROOM;

int quest_hecho;

create()
{
 ::create();
 seteuid(getuid(TO));
 quest_hecho=0;
 SetIntShort("un callejón");
 SetIntLong(
"Has entrado en uno de los tantos callejones de Crowy, pero éste tiene algo\n\
especial.. Los huesos te empiezan a temblar y no sabes aún por qué. Un frio\n\
intenso recorre este callejón.\n");

 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Silencio.. eso es lo unico que se escucha aquí.\n");
 SetIntSmell("No puedes relacionar el olor con nada ya que es bastante extraño.\n");

 AddDetail(({"callejon","calle","habitacion"}),
"Oscuro, silencioso, frio.. así es este callejon.\n");

 AddExit("sur",CROWY("calle15"));

 AddItem(PNJ("crowy/mendigo"),REFRESH_DESTRUCT);

 SetLocate("crowy");
}

int _invocar(string str)
{
 if (quest_hecho) return 0;
 else quest_hecho=1; // Momentaneamente.. hasta que se compruebe.

 if (str=="frobbon" || str=="Frobbon" || str=="a frobbon" || str=="a Frobbon" ||
     str=="al fantasma" || str="al fantasma de frobbon" || str="al fantasma de Frobbon")
 {
  call_out("comprobar",2);
  return 1;
 }
 return 0;
}

int comprobar()
{
 object frobbon,anillo;

 if (QUESTMASTER->QueryQuestSolved("frobbon",TP)) {
   quest_hecho=0;
  tell_room(CROWY("frobbon"),"\
El fantasma de Frobbon aparece de la nada.\n\
Frobbon mira a su alrededor y al no ver a nadie con su anillo desaparece.\n");
  return 0; }

 if ((anillo=present("anillo de frobbon",TP)) &&
     (present(TP,TO))) {

  if(!frobbon=clone_object(PNJ("crowy/frobbon"))) {
   quest_hecho=0;return 0; } // Ha habido algun fallo al clonear a Frobbon.

  frobbon->move(CROWY("frobbon"),M_SILENT);
  tell_room(CROWY("frobbon"),"Frobbon le coge el anillo a "+CAP(TP->QueryName())+".\n",({TP}));
  tell_object(TP,"Frobbon te coge el anillo y lo mira.\n");
  tell_object(TP,"El fantasma te da las gracias por haberle ayudado a recuperar su anillo.\n");
  anillo->remove(); // Ya no hace falta.. asi que lo eliminamos.
  QUESTMASTER->SetPlayerQuest("frobbon",TP);
  QUESTMASTER->InformSolution(CAP(TP->QueryName())+" le ha devuelto el anillo a Frobbon.\n");
 write_file (LOGS "FROBBON_QUEST",ctime(time())+" "+getuid(TP)+" ["+
 TP->QueryLevel()+"]   Le devolvió el anillo a Frobbon.\n");
  return 1;
 }
 else
 {
  tell_room(CROWY("frobbon"),"\
El fantasma de Frobbon aparece de la nada.\n\
Frobbon mira a su alrededor y al no ver a nadie con su anillo desaparece.\n");
  return 0;
 }
 quest_hecho=0;
 return 0;
}

init(){
::init();
 add_action("_invocar","invocar");
}

reset(){
quest_hecho=0;
::reset();
}
