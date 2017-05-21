/*
   Theuzifan, 20-07-99
   Habitaci�n est�ndar de BOSQUE.
   Esta habitaci�n, aparte de crear el entorno, a�ade animales (limitando que
   no pasen a la ciudad).
   Se utiliza el skill 'rastrear' para buscar la ciudad y algo de caza, con
   el comando 'rastrear'.
   Nyh introduce lo del ultimo rastreo y tal pa que la gente no suba a saco la
   habilidad
*/


#include "path.h"
#include <wizlevels.h>
#include <nightday.h>
#include <properties.h>

#define P_ULTIMO_RASTREO	"UltimoRastreo"
#define TIEMPO_ENTRE_RASTREO	3
#define caza ({"ardilla", "conejo", "jabali", "ciervo", "topo"})
#define animales ({"ardilla", "ciervo", "conejo", "jabali", "lobo", "oso", "topo", "zorro"})


inherit LAD_ROOM_EX;
static string ToCity;
static int noanim;

int SetNoAnimals(int i)
{
  return noanim=i;
}
/*
  Estas funciones indican el camino m�s corto a la ciudad m�s cercana.
  en ToCity se guarda la direcci�n a seguir en cada habitaci�n (p.e. en
  bosque00 se guarda 'oeste', y en la habitaci�n a la que se llega usando
  ToCity (oeste en este caso), se guardar�a la direcci�n para ir a la
  ciudad, as� en cada habitaci�n sabes hacia donde ir para llegar a la
  ciudad, si eres un buen rastreador.
*/

string SetPathToCity(string path)
{
  return ToCity=path;
}


string QueryPathToCity()
{
  return ToCity;
}



/* cmd_ciudad:
  B�squeda de la ciudad m�s cercana, usando el skill 'rastrear' en los
  jugadores y la variable ToCity, que indica la direcci�n a seguir en
  cada habitaci�n para ir a la ciudad.
  Si el % del skill es <1, fallas. Si no, aciertas... estaba pensando en
  que te pudiera enga�ar, pero ya veremos...
*/
int cmd_ciudad(string str)
{
  mixed *idx;
  int perc;

  if (!QueryExits() || QueryExits()==([]))
    return notify_fail("Desde aqu� no puedes ir a ning�n sitio.\n");
#if 0
  //los wizs no necesitan de los skills, pero para testearlo quito ello:
  if (IS_LEARNER(TI))
  {
    write("Al parecer la ciudad est� hacia el "+QueryPathToCity()+".\n");
    return 1;
  }
#endif
  write("Rastreas el terreno en busca de los rastros de una ciudad...\n");
  if (!TP->Query(P_INVIS))
    say(capitalize(TP->QueryName())+" se pone a rastrear los alrededores.\n");

  perc=TP->UseSkill("rastrear");
#if 0
  //te tima miserablemente d�ndote una direcci�n err�nea
  if (perc<-20)
  {
    idx=m_indices(QueryExits());
    write("Al parecer la ciudad est� hacia el "+idx[random(sizeof(idx))]+".\n");
    return 1;
  }
#endif
  TP->SetCombatDelay(1);
  if (perc<1) return notify_fail("No encuentras ning�n rastro.\n");

  write("Al parecer la ciudad est� hacia el "+QueryPathToCity()+".\n");
  TP->Set(P_ULTIMO_RASTREO,time());
  return 1;
}



/* cmd_cazar:
   B�squeda y rastreo de animales de caza... te indica una direcci�n hacia la
   que hay alg�n animal. Si fallas, no te dice nada... si aciertas y hay
   alg�n bichejo cerca, te dice donde est�. Si no hay animal cerca y el %
   del skill es <30, te enga�a, y si es >=30, te crea uno para ti solito.
*/
int cmd_cazar(string str)
{
  int perc, n, i, j, anim;
  object room, ob;
  mixed *ie, *ve;
  object *cont;

  cont=all_inventory(TO);
  for (i=0; i<sizeof(cont); i++)
    if (cont[i]->Query(P_IS_NPC))
      return notify_fail(capitalize(cont[i]->QueryShort())+" te "+
      		"impide seguir alg�n rastro.\n");

  write("Te pones a rastrear el suelo en busca de huellas...\n");
  if (!TP->Query(P_INVIS))
    say(capitalize(TP->QueryName())+" se pone a rastrear el suelo.\n");

  perc=TP->UseSkill("rastrear");
  TP->SetCombatDelay(1);
  if (perc<1) return notify_fail("No encuentras ning�n rastro.\n");

  if (perc>0)
  {
    ie=m_indices(QueryExits());
    ve=m_values(QueryExits());
    for (i=0; i<sizeof(ve)-1; i++)
    {
      if ((room=load_object(ve[i]))->QueryLocate()!=QueryLocate())
      {
        ie-=({ie[i]});
        ve-=({ve[i]});
      }
      cont=all_inventory(room);
      anim=0;
      for (j=0; j<sizeof(cont); j++)
        if (cont[j]->Query(P_IS_NPC)) anim++;
      if (!anim)
      {
        ie-=({ie[i]});
        ve-=({ve[i]});
      }
    }
    if (perc<70)
    {
      if (sizeof(ie))
      {
        n=random(sizeof(ie));
        write("Ves unas huellas que se dirigen hacia "+ie[n]+".\n");
      }
      else return notify_fail("No encuentras ning�n rastro.\n");
    }
    else if (perc>=70)
    {
      ob=clone_object(PNJ("atbalnin/bosque/"+caza[random(sizeof(caza))]));
      ob->move(TO);
      ob->SetGoChance(25);
      write("Encuentras "+ob->QueryShort()+"...\n");
    }
  }
  TP->Set(P_ULTIMO_RASTREO,time());
  return 1;
}


/* cmd_rastrear:
   Rastreo de bichos y de la ciudad.
*/
int cmd_rastrear(string str) {
int res;
  if (!str) {
    return notify_fail("Puedes rastrear:\n"
   	"   caza: para buscar animales que est�n cerca.\n"
   	"   ciudad: para buscar la ciudad m�s cercana.\n\n"
   	"As�, con 'rastrear caza' te dir�a la direcci�n m�s cercana donde hay animales.\n");
  }
  if (!(TP->Query(P_ULTIMO_RASTREO)
      && (time()-TP->Query(P_ULTIMO_RASTREO))<TIEMPO_ENTRE_RASTREO)) {
    switch(str) {
      case "ciudad": res=cmd_ciudad(str); break;
      case "caza":   res=cmd_cazar(str);  break;
    }
    return res;
  }
  else {
    return notify_fail("Necesitas descansar un poco antes de volver a rastrear.\n");
  }
}

int cmd_clima()
{
  write(CHRONOS->QueryWeatherMsg());
  return 1;
}

int cmd_mirar(string que)
{
  if (que=="suelo")
  {
    write(CHRONOS->QueryGroundDesc());
    return 1;
  }
  if (que=="clima" || que=="tiempo")
    return cmd_clima();
  return 0;
}

QueryIntLong()
{
  if (random(8)==3)
    return W(::QueryIntLong()+"Te fijas un poco y ves montones de huellas de animales. "+
    	"Seguramente rastreando un poco podr�as encontrar algo de caza.\n");
  else return ::QueryIntLong();
}
create(){
  mixed s;

  ::create();
  seteuid(getuid());
  SetPathToCity("oeste");
  SetIntLong(W("Estas en un bosque bastante frondoso, donde la "
	"vegetacion casi cierra el camino.\n"));
  SetIntShort("un bosque frondoso");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("el bosque de Atbalnin");
  SetIndoors(0);

  if (NIGHTDAY->QueryState()!=ND_NIGHT && !noanim)
  {
    if(random(6)==0)
      AddItem(PNJ("atbalnin/bosque/"+animales[random(sizeof(animales))]), REFRESH_REMOVE);
  }

  AddRoomCmd("rastrear", SF(cmd_rastrear));
  AddRoomCmd(({"mirar", "mi", "m"}), SF(cmd_mirar));
  AddRoomCmd("clima", SF(cmd_clima));
  SetServer(NIGHTDAY);
}

