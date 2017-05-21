/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 29-10-98              |
 |            Ultima Modificacion....... 10-04-00              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <damage.h>

inherit GACANTILADO;

int cmd_buscar(string str)
{
  int perc;

  if (str!="arbustos" && str!="arbusto") return 0;
  perc=TP->UseSkill(HAB_RASTREAR);

  if (perc<1)
  {
    if (!TP->QueryInvis())
      say(TP->QueryName()+" rebusca por entre los arbustos pero no parece encontrar "
      	"nada.\n");
    write("Te pones a rebuscar por los arbustos. Seguramente hay algo, pero se "
    	"te pasa por alto.\n");
  }
  else
  {
    write("Empiezas a rebuscar por los arbustos y encuentras una entrada medio tapada por la "
  	"maleza. Te internas en ella y te das cuenta de que es una caverna. Coges una antorcha "
  	"que estaba en la pared, la enciendes y bajas. Después de mucho bajar y bajar, cuando "
  	"empiezas a preguntarte si no llegarás nunca al fondo, ves una luz al fondo. Sales al "
  	"exterior y dejas la antorcha en la pared.\n");
    if (!TP->QueryInvis())
      say(TP->QueryName()+" rebusca por entre los arbustos y desaparce entre ellos.\n");
    TP->move(ACANTILADO("playa"), M_GO, TP->QueryName()+" aparece por la cueva.\n");
  }
  return 1;
}


int cmd_atar(string str)
{
  object ob;
  int perc, hp;

  ob=present("cuerda");
  if (!ob) ob=present("cuerda", TP);
  if (!ob) return notify_fail("No tienes ninguna cuerda para bajar.\n"),0;
  if (member(inherit_list(ob), "/obj/cuerda.c")==-1)
    return notify_fail("La cuerda que tienes no te inspira la suficiente confianza para arriesgar "
    	"el tipo de esta manera.\n"),0;
  ob->move(TO, M_SILENT);
  write("Atas la cuerda a una roca y empiezas a bajar por ella, en un intento de llegar al "+
  	"saliente.\n");
  if (!TP->QueryInvis())
    say(TP->QueryName()+" ata una cuerda a una roca y empieza a bajar.\n");
  perc=TP->UseSkill(HAB_TREPAR,-30);

  if (perc<1)
  {
    write("¡El viento te zarandea y tu inexperiencia te juega una mala pasada! Caes al vacío "
    	"y tu vida comienza a desfilar ante tus ojos.\n");
    hp=-perc*3/2;
    TP->Defend(hp, DT_BLUDGEON);
    if (perc<-50)
      TP->move(ACANTILADO("playa"), M_GO, TP->QueryName()+" cae desde el acantilado.\n");
    else TP->move(ACANTILADO("saliente"), M_GO, TP->QueryName()+" cae desde el acantilado.\n");
  }
  else
    TP->move(ACANTILADO("saliente"), M_GO, TP->QueryName()+" baja por una cuerda.\n");

  return 1;
}
/*
init()
{
  ::init();
  TP->Set("_FROM", TO);
}
*/
create()
{
 ::create();

 AddExit("sur",ACANTILADO("acantilado_norte5"));
 AddExit("norte",ACANTILADO("acantilado_norte7"));
 AddDetail("acantilado", "Te asomas al acantilado y observas la gran altura que te separa "
 	"del fondo. Tu mirada pasea por la pared de roca y en un saliente descubres algo que te "
 	"había pasado desapercibido, un objeto que te recuerda vagamente a un nido.\n");
 AddDetail("nido", "Algo parecido a un nido descansa en un saliente rocoso. Seguramente "
 	"podrías llegar hasta allí abajo atando una cuerda en algun sitio y deslizándote "
 	"por ella.\n");
 AddDetail(({"arbusto", "arbustos"}), "Ves unos frondosos arbustos. Te acercas a ellos y "
 	"notas un ligero vientecillo cálido y olor a moho. Parece haber algo oculto en ellos.\n");
 AddDetail("saliente", "A la mitad de altura del acantilado ves un saliente. Quizás podrías "
 	"llegar a él atando una cuerda a algún sitio y bajando por ella.\n");
 AddRoomCmd(({"atar","bajar"}), "cmd_atar");
 AddRoomCmd("buscar", "cmd_buscar");
 SetLocate("acantilado del noroeste de Goldhai");
}
