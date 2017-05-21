/*
   Theuzifan, 20-07-99
   Habitación estándar de BOSQUE.
   Esta habitación, aparte de crear el entorno, añade animales (limitando que
   no pasen a la ciudad).
   Se utiliza el skill 'rastrear' para buscar la ciudad y algo de caza, con
   el comando 'rastrear'.
               [l] Lonerwolf
   Modificada un poco por chantiel y lonerwolf
	 [l]  18/06/10 Se simplifica y mejora la habitacion con la nuevas bondades del mud
*/


#include "./path.h"
#include <properties.h>

inherit LAD_ROOM;

static string ToCity;
static string ToGigants;
static string ToTrolls;

/*
  Estas funciones indican el camino más corto a la ciudad más cercana.
  en ToCity se guarda la dirección a seguir en cada habitación (p.e. en
  bosque00 se guarda 'oeste', y en la habitación a la que se llega usando
  ToCity (oeste en este caso), se guardaría la dirección para ir a la
  ciudad, así en cada habitación sabes hacia donde ir para llegar a la
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

/*[l] queremos rastrear trolls y gigantes */
string SetPathToGigants(string path)
{
  return ToGigants=path;
}

string QueryPathToGigants()
{
  return ToGigants;
}

string SetPathToTrolls(string path)
{
  return ToTrolls=path;
}
string QueryPathToTrolls()
{
  return ToTrolls;
}

/* cmd_ciudad:
  Búsqueda de la ciudad más cercana, usando el skill 'rastrear' en los
  jugadores y la variable ToCity, que indica la dirección a seguir en
  cada habitación para ir a la ciudad.
  Si el % del skill es <1, fallas. Si no, aciertas... estaba pensando en
  que te pudiera engañar, pero ya veremos...
*/
int cmd_ciudad(string str)
{
  mixed *idx;
  int perc;

  if (!QueryExits() || QueryExits()==([]))
    return notify_fail("Desde aquí no puedes ir a ningún sitio.\n");
#if 0
  //los wizs no necesitan de los skills, pero para testearlo quito ello:
  if (IS_LEARNER(TI))
  {
    write("Al parecer la ciudad está hacia el "+QueryPathToCity()+".\n");
    return 1;
  }
#endif
  write("Rastreas el terreno en busca de los rastros de una ciudad...\n");
  if (!TP->QueryInvis())
    say(capitalize(TP->QueryName())+" se pone a rastrear los alrededores.\n");

  perc=TP->UseSkill("rastrear");
#if 0
  //te tima miserablemente dándote una dirección errónea
  if (perc<-20)
  {
    idx=m_indices(QueryExits());
    write("Al parecer la ciudad está hacia el "+idx[random(sizeof(idx))]+".\n");
    return 1;
  }
#endif
  if (perc<1) return notify_fail("No encuentras ningún rastro.\n");

  write("Al parecer la ciudad está hacia el "+QueryPathToCity()+".\n");
  return 1;
}

/* cmd_gigante:
  Búsqueda de la guaria de gigantes mas cercana , usando el skill 'rastrear'
  en los  jugadores y la variable ToGigants, que indica la dirección
  a seguir en cada habitación para ir a la guarida.
  Si el % del skill es <1, fallas. Si no, aciertas... estaba pensando en
  que te pudiera engañar, pero ya veremos...
*/
int cmd_gigante(string str)
{
  mixed *idx;
  int perc;

  if (!QueryExits() || QueryExits()==([]))
    return notify_fail("Desde aquí no puedes ir a ningún sitio.\n");
#if 0
  //los wizs no necesitan de los skills, pero para testearlo quito ello:
  if (IS_LEARNER(TI))
  {
    write("Al parecer la ciudad está hacia el "+QueryPathToGigants()+".\n");
    return 1;
  }
#endif
  write("Rastreas el terreno en busca de los rastros de algun gigante...\n");
  if (!TP->QueryInvis())
    say(capitalize(TP->QueryName())+" se pone a rastrear los alrededores.\n");

  perc=TP->UseSkill("rastrear");
#if 0
  //te tima miserablemente dándote una dirección errónea
  if (perc<-20)
  {
    idx=m_indices(QueryExits());
    write("Al parecer la ciudad está hacia el "+idx[random(sizeof(idx))]+".\n");
    return 1;
  }
#endif
  if (perc<1) return notify_fail("No encuentras ningún rastro.\n");

  write("Al parecer la guarida de gigantes está hacia el "+QueryPathToGigants()+".\n");
  return 1;
}

/* cmd_troll:
  Búsqueda de la guarida de trolls mas cercana, usando el skill 'rastrear'
  en los jugadores y la variable ToTrolls, que indica la dirección a seguir en
  cada habitación para ir a la guarida.
  Si el % del skill es <1, fallas. Si no, aciertas... estaba pensando en
  que te pudiera engañar, pero ya veremos...
*/
int cmd_troll(string str)
{
  mixed *idx;
  int perc;

  if (!QueryExits() || QueryExits()==([]))
    return notify_fail("Desde aquí no puedes ir a ningún sitio.\n");
#if 0
  //los wizs no necesitan de los skills, pero para testearlo quito ello:
  if (IS_LEARNER(TI))
  {
    write("Al parecer la ciudad está hacia el "+QueryPathToTrolls()+".\n");
    return 1;
  }
#endif
  write("Rastreas el terreno en busca de los rastros de algún troll...\n");
  if (!TP->QueryInvis())
    say(capitalize(TP->QueryName())+" se pone a rastrear los alrededores.\n");

  perc=TP->UseSkill("rastrear");
#if 0
  //te tima miserablemente dándote una dirección errónea
  if (perc<-20)
  {
    idx=m_indices(QueryExits());
    write("Al parecer la ciudad está hacia el "+idx[random(sizeof(idx))]+".\n");
    return 1;
  }
#endif
  if (perc<1) return notify_fail("No encuentras ningún rastro.\n");

  write("Al parecer la ciudad está hacia el "+QueryPathToTrolls()+".\n");
  return 1;
}



/* cmd_cazar:
   Búsqueda y rastreo de animales de caza... te indica una dirección hacia la
   que hay algún animal. Si fallas, no te dice nada... si aciertas y hay
   algún bichejo cerca, te dice donde está. Si no hay animal cerca y el %
   del skill es <30, te engaña, y si es >=30, te crea uno para ti solito.
*/
int cmd_cazar(string str)
{
  int perc, n, i, j, anim;
  object room, ob;
  mixed *ie, *ve,*mi_ie, *mi_ve, f;
  object *cont;

  cont=all_inventory(TO);
  for (i=0; i<sizeof(cont); i++)
    if (cont[i]->Query(P_IS_NPC))
      return  notify_fail(capitalize(cont[i]->QueryShort())+" te "+
      		"impide seguir algún rastro.\n");
      	
  write("Te pones a rastrear el suelo en busca de huellas...\n");
  if (!TP->QueryInvis())
    say(capitalize(TP->QueryName())+" se pone a rastrear el suelo.\n");

  perc=TP->UseSkill("rastrear");
  if (perc<1) return notify_fail("No encuentras ningún rastro.\n");

  if (perc>0)
  {
    ie=m_indices(QueryExits());
    ve=m_values(QueryExits());
    mi_ie=ie;
    mi_ve=ve;
    for (i=0; i<sizeof(ve); i++)
    {
      if ((room=clone_object(ve[i]))->QueryLocate()!=QueryLocate())
      {
        ie-=({ie[i]});
        ve-=({ve[i]});
        mi_ie-=({mi_ie[i]});
        mi_ve-=({mi_ve[i]});
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
    if (perc<30)
    {
      if (sizeof(ie))
      {
        n=random(sizeof(ie));
        write("Ves unas huellas que se dirigen hacia "+ie[n]+".\n");
      }
      else return notify_fail("No encuentras ningún rastro.\n");
    }
    else if (perc>=30)
    {
      f=get_dir(TBPNJ+"*");
      if (sizeof(f))
      {
        ob=clone_object("/"+TBPNJ+f[random(sizeof(f))]);
        ob->move(TO);
        ob->SetGoChance(25);
        write("Encuentras "+ob->QueryShort()+"...\n");
      }
    }
  }

  return 1;
}


/* cmd_rastrear:
   Rastreo de bichos y de la ciudad.
*/
int cmd_rastrear(string str)
{
  switch(str)
  {
    case "ciudad": return cmd_ciudad(str);
    case "caza": return cmd_cazar(str);
    case "trolls": return cmd_troll(str);
    case "gigantes": return cmd_gigante(str);
    default: write("\nPuedes rastrear:\n");
    	     write("   caza: para buscar animales que estén cerca.\n");
	     write("   ciudad: para buscar la ciudad más cercana.\n");
	     write("   trolls: para buscar guarida de los trolls.\n");
	     write("   gigantes: para buscar guaridas de gigantes.\n");
	     write(W("Así, con 'rastrear caza' te diría la dirección más "
	     	"cercana donde hay animales.\n"));
  }
  return 1;
}

/*
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
*/
create(){
  mixed s;
  string *f;

  ::create();
  SetPathToCity("oeste");
  SetPathToTrolls("oeste");
  SetPathToGigants("oeste");
  SetIntLong(W("Estas en un bosque bastante frondoso, donde la "
	"vegetacion casi cierra el camino.\n"));
  SetIntShort("un bosque frondoso");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("el bosque de Tiinkdhil");
  SetIndoors(0);
/*
  if (NIGHTDAY->QueryState()!=ND_NIGHT)
  {
    if(random(6)==0)
    {
      f=get_dir(TBPNJ+"/*");
      if (sizeof(f))
        AddItem(TBPNJ+f[random(sizeof(f))], REFRESH_DESTRUCT);
    }
  }
*/
  AddRoomCmd("rastrear", SF(cmd_rastrear));
  //AddRoomCmd(({"mirar", "mi", "m"}), SF(cmd_mirar));
  //AddRoomCmd("clima", SF(cmd_clima));
  //SetServer(CHRONOS);
}

