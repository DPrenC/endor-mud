/*
DESCRIPCION  : Habitacion base del bosque de la fortaleza
FICHERO      : bosque.c
MODIFICACION : veintialgo-06-00 [Maler] Creacion
*/

#include "path.h"
#include <properties.h>


inherit SIM_ROOM;

#define MIN(x,y) (x>y?y:x)
#define MAX(x,y) (x>y?x:y)
#define caza ({"ardilla","aguila","canario","conejo","golondrina","lobo","gusano","ave_rnd"})

//probabilidades de que aparezcan obj/pnj (%)
#define PROB_SETA     10
#define PROB_HIERBA   15
#define PROB_AVE      20
#define PROB_MAMIFERO 15
#define PROB_OSO      10
#define PROB_BANDIDO  10

private static int prob_seta;
private static string NombreBosque;

void   SetNombreBosque(string n){NombreBosque=n;return;}
string QueryNombreBosque(){return NombreBosque;}

string Desc()
{
string s;
s="";

//Descripcion general del bosque
switch(random(7)){
case 0:
   s+="Estás en un bosque al norte de Nandor. Los altos y frondosos árboles apenas "
      "te dejan ver por donde caminas. Una increíble paz reina aquí, haciendo de este "
      "bosque un lugar tranquilo para pasar una temporada, quizá sea incluso demasiado tranquilo. ";break;
case 1:
   s+="El bosque aquí clarea un poco, aún así no alcanzas a ver gran cosa, sin embargo la luz te anima "
      "a seguir tu camino. El aire es puro, y la paz reinante te agradan enormemente. ";break;

case 2:
   s+="El terreno del bosque presenta en esta zona una cierta pendiente. Piensas que "
      "no estaría de más tener un poco de precaución al avanzar para evitar alguna "
      "desagradable caída. ";break;
case 3:
   s+="Observas que en esta zona el bosque se vuelve algo más claro, debido a que "
      "gran parte de los árboles aún son jóvenes y con poco tamaño. Esto hace "
      "que el bosque sea aquí algo más luminoso que en otras zonas. ";
   AddDetail(({"arboles"}),"Son árboles jóvenes con toda una vida por delante.\n");
   break;
case 4:
   s+="Observas que en esta parte del bosque abundan especialmente las encinas en "
      "comparación con otros tipos de árboles. Son unos árboles grandes y frondosos. ";
   AddDetail(({"encinas"}),"En esta zona hay muchos.\n");
   break;
case 5:
   s+="El bosque se extiende hasta donde alcanza tu mirada. Visto desde aquí parece "
   "interminable. Visto desde arriba la visión debe ser increíble. ";
   break;
case 6:
   s+="En esta parte del bosque hay una increíble cantidad de árboles. No sólo te dificultan "
   "ver la luz del sol, sino que también te impiden andar con facilidad por aquí. ";
   break;
}

//Descripcion de los detalles de la zona
switch(random(8)){
case 0:
   s+="En esta zona del bosque la tierra que pisas esta mas bien húmeda, quizá debido "
      "a alguna lluvia reciente o al paso de algun acuífero subterráneo cerca de aquí.";
   AddDetail(({"suelo"}),"La tierra del suelo que pisas esta húmeda.\n");
   prob_seta=MIN(100,prob_seta*4);
   break;
case 1:
   s+="El suelo esta cubierto de una mullida capa de hojarasca que cruje al pisarla.";
   AddDetail(({"hojarasca","hojas"}),
      "La hojarasca es la capa de hojas secas caídas de los árboles que hay en el suelo.\n");
   break;
case 2:
   s+="Unos altos y espesos matorrales te impiden continuar en algunas direcciones.";
   AddDetail(({"matorrales"}),
      "Son lo bastante grandes como para impedirte avanzar en algunas direcciones.\n");
   break;
case 3:
   s+="Junto a tí se encuentra un viejo tronco medio podrido de lo que alguna vez debió "
      "ser un gran árbol. Es posible que sirva de refugio para algun pequeño animal.";
   AddDetail(({"tronco"}),
      "Es solo un viejo tronco.\n");
   break;
case 4:
   s+="En el suelo puedes distinguir las huellas dejadas por algun animal del bosque.";
   AddDetail(({"huellas"}),
      "Parecen las huellas de un conejo.\n");
   break;
case 5:
   s+="Cerca de aquí ves un grupo de rocas.";
   AddDetail(({"rocas"}),"Son solo un grupo de rocas en medio del bosque.\n");
   break;
case 6:
   s+="En esta parte del bosque el suelo esta cubierto de maleza, de tal forma "
   "que apenas ves por donde pones los pies. ";
   AddDetail(({"maleza"}),"Cardos, espigas, y tomillo parecen componer la maleza de por aquí.\n");
   AddDetail(({"cardos"}),"Cardos borriqueros, los primeros en nacer y los últimos en morir.\n");
   AddDetail(({"espigas"}),"Son un incordio, no las das quitados de tu ropa.\n");
   AddDetail(({"tomillo"}),"Huele muy bien.\n");
   break;
case 7:
   s+="Todas las zonas de este bosque te parecen similares, esto contribuye a tu actual estado "
   "de desorientación, sin embargo todavía tienes clara la causa por la que estás aquí.";
   break;

}
return (s+"\n");
}


InitVars(){
  prob_seta=PROB_SETA;
  return;
}

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
      		"impide seguir algún rastro.\n");

  write("Te pones a rastrear el suelo en busca de huellas...\n");
  if (!TP->Query(P_INVIS))
    say(capitalize(TP->QueryName())+" se pone a rastrear el suelo.\n");

  perc=TP->UseSkill("rastrear");
  TP->SetCombatDelay(1);
  if (perc<1) return notify_fail("No encuentras ningún rastro.\n");

  if (perc>0)
  {
    ie=m_indices(QueryExits());
    ve=m_values(QueryExits());
	for (i=0; i<sizeof(ve); i++)
    {
	room=clone_object(ve[i]);
if(room->QueryLocate()!=QueryLocate())
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
      else return notify_fail("No encuentras ningún rastro.\n");
    }
    else if (perc>=70)
    {
ob=clone_object("/d/simauria/comun/pnj/marhalt/fortaleza/bosque/"+caza[random(sizeof(caza))]);
      ob->move(TO);
      ob->SetGoChance(25);
      write("Encuentras "+ob->QueryShort()+"...\n");
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
    case "caza": return cmd_cazar(str);
    default: write("\nPuedes rastrear:\n");
    	     write("   caza: para buscar animales que estén cerca.\n\n");
	        write(W("Así, con 'rastrear caza' te diría la dirección más "
	     	"cercana donde hay animales.\n"));
  }
  return 1;
}



AnyadirPnjs(){
switch(random(100))
   {
   case 0..4:AddItem(PNJFB("aguila"),REFRESH_DESTRUCT,1);break;
   case 5..9:AddItem(PNJFB("ardilla"),REFRESH_DESTRUCT,1);break;
   case 10..14:AddItem(PNJFB("canario"),REFRESH_DESTRUCT,1);break;
   case 15..29:AddItem(PNJFB("ave_rnd"),REFRESH_DESTRUCT,1);break;
   case 30..34:AddItem(PNJFB("conejo"),REFRESH_DESTRUCT,1);break;
   case 35..39:AddItem(PNJFB("golondrina"),REFRESH_DESTRUCT,1);break;
   case 40..44:AddItem(PNJFB("gusano"),REFRESH_DESTRUCT,1);break;
   case 45..49:AddItem(PNJFB("lobo"),REFRESH_DESTRUCT,1);break;
   default:break;
   }
}

/*
AnyadirHierbas(){
int nhierba,i;
string tipo;
  nhierba=(random(100)<PROB_HIERBA?random(2)+1:0);
  if (nhierba==0) return;
  for(i=0;i<nhierba;i++){
     switch(random(100)){
        case  0..25:  tipo="hierba";break;
        case 26..35:  tipo="hierba_narcotica";break;
        case 36..50:  tipo="hierba_curativa";break;
        case 51..65:  tipo="hierba_magica";break;
        case 66..90:  tipo="hierba_saciante";break;
        case 91..100: tipo="hierba_venenosa";break;
        }
     AddItem(HERBS(tipo),REFRESH_DESTRUCT,1);
     }
  return;
}


AnyadirSetas(){
int nseta,i;
string tipo;
  nseta=(random(100)<prob_seta?random(2)+1:0);
  if (nseta==0) return;
  for(i=0;i<nseta;i++){
     switch(random(100)){
        case  0..25:  tipo="seta";break;
        case 26..35:  tipo="seta_narcotica";break;
        case 36..50:  tipo="seta_curativa";break;
        case 51..65:  tipo="seta_magica";break;
        case 66..90:  tipo="seta_saciante";break;
        case 91..100: tipo="seta_venenosa";break;
        }
     AddItem(HERBS(tipo),REFRESH_DESTRUCT,1);
     }
  return;
}
*/

create()
{
  ::create();
  InitVars();
  SetNombreBosque("de Cored");
  SetIntShort("el bosque "+QueryNombreBosque());
  SetIntLong(W(Desc()));

  SetIntNoise("Oyes el canto de los pájaros.\n");
  SetIntSmell("Huele a bosque.\n");
  SetIndoors(0);
  //AnyadirSetas();
  //AnyadirHierbas();
  AddDetail(({"bosque","bosque de la fortaleza"}),
     W("Es un bosque de mediano tamaño que se extiende en la parte norte "
       "de Nandor. Es un bosque no muy denso habitado principalmente por "
  	   "bandidos e indeseables de este tipo. Si no fuera por la chusma que "
  	   "lo habita, sería un lugar muy agradable.\n"));
  SetLocate("bosque de la fortaleza");
  AddRoomCmd("rastrear", SF(cmd_rastrear));

}
