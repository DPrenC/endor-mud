
/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-02-99                |
 |               Ultima Modificacion.. 02-07-00                |
 |                                                             |
 | 03-03-99 [w] Ahora comprueba si tienes un anillo y en ese   |
 |              caso no te da un segundo.                      |
 | 02-07-00 [w] Si no puede dartelo, se va sin dartelo. Ademas |
 |              ahora informa a TP que ha hecho el quest.      |
 *=============================================================*/

#include "./path.h"
#include <properties.h>

#define ASESINOS DOM_STD "asesinos"
#include <moving.h>

inherit NPC;
object salvador;

create()
{
  ::create();
 SetStandard("Lonny","elfo-oscuro",4,GENERO_MASCULINO);
 SetIds(({"lonny","Lonny","estafador","elfo oscuro"}));
 SetShort("Lonny el estafador");
 SetLong("Lonny es un elfo oscuro bastante vulgar. Va vestido con ropas "
         "viejas y muy sucias y tiene un aspecto horrible. Su cara está "
         "llena de moratones como si alguien se hubiera divertido con él "

         "un buen rato.\n");
 SetAlign(-100);
 SetWhimpy(30); // Un poquito cobarde el pobre.
 AddItem(OTRO("anillo_frobbon"));
}

void lonny_se_va()
{
 object anillo;

 say("Lonny sonrie y se marcha del dormitorio\n");
 if (anillo=present("anillo de frobbon",TO))
   anillo->remove();
 destruct(TO);
}

int dar_anillo()
{
object anillo;

if (QUESTMASTER->QueryQuestSolved("frobbon", salvador) ||
    present("anillo de frobbon",TP) || !TP->QueryIsPlayer())
{
 say("Lonny dice: Gracias "+CAP(salvador->QueryName())+
" por matar a Kurts. Ahora ya podré volver \
a mi casa. Prometo que nunca volveré a estafar a nadie más..\n");
 call_out("lonny_se_va",5);
 return 1;
}

if (anillo=present("anillo de frobbon",TO))
{
 say("Lonny dice: Gracias "+CAP(salvador->QueryName())+
" por matar a Kurts. Ahora ya podré volver \
a mi casa. Prometo que nunca volveré a estafar a nadie más.. y para que veas \
que no miento ten este anillo que gané una vez a un tal Turgo, el pobre era \
bastante torpe y nunca vió que le hacia trampas.\n");
 if (anillo->move(salvador,M_SILENT)!=ME_OK)
 {
     tell_object(salvador,"Lonny con las prisas se va sin darte el anillo.\n");
     anillo->remove();
 } else
 {
  tell_object(salvador,"Lonny te da un anillo\n");
 }
 call_out("lonny_se_va",10);
}

 return 1;
}


init() {
::init();
 salvador=TP;
 call_out("dar_anillo",4);
}


private status existe_jugador(string jugador) {
 return find_savefile(jugador)||find_object(lower_case(jugador));
}

public varargs void Die(mixed silent) {
 object ASESINO;

 ASESINO=PO;
 if(!ASESINO->QueryIsPlayer())  {return ::Die(silent);}
 if(!existe_jugador(ASESINO->QueryRealName())) {return ::Die(silent);}
 ASESINOS->SetAsesino(ASESINO->QueryRealName(),3,1,0,1);
 ::Die(silent);
}
