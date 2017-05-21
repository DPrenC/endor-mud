/*=============================================================*
 |           << GOLDHAI.Saliente [t] Theuzifan >>              |
 *=============================================================*
 |            Creacion.................. 23-03-00              |
 |            Ultima Modificacion....... 10-04-00              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <damage.h>


inherit GROOM;

int cmd_bajar(string str)
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
  write("Atas la cuerda al saliente y empiezas a bajar por ella.\n");
  if (!TP->QueryInvis())
    say(TP->QueryName()+" ata una cuerda al saliente y empieza a bajar.\n");
  perc=TP->UseSkill(HAB_TREPAR,-30);

  if (perc<1)
  {
    write("�El viento te zarandea y tu inexperiencia te juega una mala pasada! Caes al vac�o "
    	"y tu vida comienza a desfilar ante tus ojos.\n");
    hp=-perc*2;
    TP->Defend(hp, DT_BLUDGEON);
    TP->move(ACANTILADO("playa"), M_GO, TP->QueryName()+" cae desde el saliente.\n");
  }
  else
    TP->move(ACANTILADO("playa"), M_GO, TP->QueryName()+" baja por una cuerda.\n");

  //TP->Set("_FROM",0);
  return 1;
}


int cmd_saltar(string str)
{
  int perc;
  int hp;

  write("Te asomas al borde del saliente, y la vista es arrolladora. Tendr�s una bonita "
  	"historia que contar, si sobrevives, por supuesto. Sin pensarlo m�s saltas al vac�o.\n");

  perc=TP->UseSkill(HAB_SALTAR, -40);
  if (perc<1)
  {
    write("�Tu salto se convierte en una ca�da incontrolada!\n");
    hp=-perc*2;
  }
  else
    hp=random(30);

  TP->Defend(hp, DT_BLUDGEON);
  TP->move(ACANTILADO("playa"), M_GO, TP->QueryName()+" cae desde el saliente.\n");
  return 1;
}


int cmd_subir(string str)
{
  int perc;
  int hp;
  object prev;

  prev=find_object("/d/goldhai/comun/habitacion/acantilado/acantilado_norte6");

  if (!prev || !present("cuerda", prev))
    return notify_fail("�No puedes subir! Alguien se ha llevado la cuerda con la "
    	"que hab�as bajado. La �nica salida que tienes es bajar atando una cuerda "
    	"al saliente e intentar llegar sano y salvo a la playa.\n");

  perc=TP->UseSkill(HAB_TREPAR,-15);

  if (perc<1)
  {
    write("�El viento te zarandea y tu inexperiencia te juega una mala pasada! Caes al vac�o "
    	"y tu vida comienza a desfilar ante tus ojos.\n");
    hp=perc*3/2;
    TP->Defend(-perc, DT_BLUDGEON);
    if (perc<-50)
      TP->move(ACANTILADO("playa"), M_GO, TP->QueryName()+" cae desde el acantilado.\n");
    else write("Milagrosamente consigues agarrarte al saliente y no caer m�s abajo.\n");
  }
  else
    TP->move(ACANTILADO("acantilado_norte6"), M_GO, TP->QueryName()+" sube por una cuerda.\n");
  //TP->Set("_FROM", 0);
  return 1;
}


create()
{
 ::create();
 SetIndoors(0);
 SetIntShort("un saliente");
 SetIntLong(
"Est�s en un saliente de la pared rocosa del acantilado. En saliente pr�ximo "
"hay un enorme nido de alg�n ave que probablemente tambi�n tenga un tama�o "
"respetable. Piensas que podr�as llegar a �l de un salto, pero el viento que "
"sopla con fuerza y la humedad sobre las rocas hace que sea una maniobra muy "
"arriesgada.Estando m�s o menos a la mitad de la altura del acantilado, una "
"ca�da ser�a seguramente fatal. .\n");

AddDetail(({"acantilado","precipicio"}),
"Es un enorme acantilado que baja de forma casi perpendicular hasta una playa.\n\
Seria practicamente un suicidio saltar desde este lugar.\n");

AddDetail(({"mar","oceano","agua"}),
"Desde este punto de la isla el mar adquiere una belleza especial. Ves como\n\
llegan las olas de forma lenta y rompen a escasos metros de la playa.\n");

AddDetail("nido", "Ves un nido de grandiosas dimensiones. El ave que deb�a habitarlo ser�a "
"desde luego enorme.\n");

 AddExit("arriba",SF(cmd_subir));
 AddExit("saltar", SF(cmd_saltar));
 AddExit("abajo", SF(cmd_bajar));
 AddExit("nido", ACANTILADO("nido"));
 SetLocate("saliente del acantilado del suroeste de Goldhai");
}