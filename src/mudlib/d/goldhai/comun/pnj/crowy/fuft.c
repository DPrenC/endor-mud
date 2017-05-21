/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 27-12-97                |
 |               Ultima Modificacion.. 07-03-99                |
 |                                                             |
 |  27-12-97 [w] Idea basada en el parrot.c de Dreconia@NF     |
 |  26-02-99 [w] Ahora da 1 punto de exploración acariciarlo.  |
 *=============================================================*/

#include "path.h"
inherit NPC;

#include <properties.h>
#include <moving.h>

#define LOG_FILE LOGS "LORO"

create() {
 seteuid(getuid());
 ::create();
SetName("fuft");
 SetShort("fuft el loro");
 SetLong("\
Fuft es un loro de color verde muy querido en Crowy. No se sabe quien lo trajo\n\
o como vino pero ahora recorre toda la ciudad escuchando las conversaciones,\n\
memorizandolas y repitiendolas. Se dice que Fuft ha oido grandes secretos\n\
sobre tesoros, asesinatos y pasadizos.\n");
 SetIds(({"loro","loro verde","fuft"}));
 SetLevel(12);
 SetGoChance(50);
 SetHands( ({ ({"ala izquierda",0,10}), ({"ala derecha",0,10}),
           ({"pico",0,12}) }) );
 SetAlign(250);
 SetMsgIn("viene volando");
 SetMsgOut("vuela");
 InitChats(10,({
     "Fuft dice: Ruaakkk ruaaakk me llamo Fuft!!\n",
     "Fuft dice: Ruaakkk.. feos, feos.\n",
     "Fuft dice: Ruuakkk vete con tu suegra, vete con tu suegra!!\n",
     "Fuft aletea y se rasca con el pico.\n",
     "Fuft dice: Ruuaakk.. Fuft quiere mimos, Fuft quiere mimos!\n",
     "Fuft dice: Ruuaakkk.. quiero caricias, quiero caricias!\n"}));
}

init(){ ::init();
 add_action("_acariciar","acariciar");
 add_action("_acariciar","mimar");
}

_acariciar(str)
{
 if (!str)
   return notify_fail("Fuft te dice: Ruaakk.. acariciame a mi.. ruaakkk!!\n"),0;
 if(str!="fuft" && str!="loro" && str!="fuft el loro")
   return notify_fail("Fuft te dice: Ruaakk.. acariciame a mi.. ruaakkk!!\n"),0;
 say(CAP(TNAME)+" acaricia a Fuft.\n",TP);
 say("Fuft se arrima a "+CAP(TNAME)+" y le susurra algo.\n",TP);
 write("Acaricias a Fuft.\n");
 write("Fuft te dice: Ruakkk.. ruaakk... gracias... ruaakkk..\n");
 TP->SetExplored();
 return 1;
}

catch_tell(string str)
{
  string str1,str2;
  object ob;
  if ((TP) && (LOWER(TNREAL)!="fuft") &&

(ISPLAYER(TP)) &&
     ((sscanf(str,"%s: %s",str1,str2))==2))
  {
    write_file(LOG_FILE,str[1..]); // Guarda lo que se dice..
    call_out("repetir",random(4)+2,str2); // Lo repite con retardo
  }
}

repetir(string str)
{
  say("Fuft repite: "+str);
}

DoDamage() // Si le atacan intenta huir
{
  if (ENV(TO))
  {
    tell_room(ENV(TO),
     "Fuft intenta huir ya que no se siente querido en este lugar.\n");
  }
  Whimpy();
  return;
}

move(dest,method,stuff) // No puede salir de crowy
{
 if(method==M_GO && dest->QueryLocate()!="crowy")
  return ME_NO_ENTER;
 return ::move(dest,method,stuff);
}
