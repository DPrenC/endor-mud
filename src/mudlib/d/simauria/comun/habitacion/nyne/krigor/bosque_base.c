/*
DESCRIPCION  : Habitacion base del bosque
FICHERO      : bosque_base.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#define MIN(x,y) (x>y?y:x)

inherit SIM_ROOM;

//#define MIN(x,y) (x>y?y:x)
//#define MAX(x,y) (x>y?x:y)

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
switch(random(5)){
case 0:
   s+="Te encuentras en algun lugar del inmenso bosque "+QueryNombreBosque()+". A tu alrededor puedes "
      "observar cientos de grandes y frondosos arboles que deben llevar aqui desde "
      "tiempo inmemoriales. ";break;
case 1:
   s+="En esta zona el bosque "+QueryNombreBosque()+" que se extiende a tu alrededor se vuelve algo "
      "mas denso y sombrio debido a la gran cantidad de arboles que hay. Te resulta "
      "un poco inquietante. ";break;
case 2:
   s+="El terreno del bosque presenta en esta zona una cierta pendiente. Piensas que "
      "no estaria de mas tener un poco de precaucion al avanzar para evitar alguna "
      "desagradable caida. ";break;
case 3:
   s+="Observas que en esta zona el bosque se vuelve algo mas claro, debido a que "
      "gran parte de los arboles aun son aun jovenes y con poco tamanyo. Esto hace "
      "que el bosque sea aqui algo mas luminoso que en otras zonas. ";
   AddDetail(({"arboles"}),"Son arboles jovenes con toda una vida por delante.\n");
   break;
case 4:
   s+="Observas que en esta parte del bosque abundan especialmente los robles en "
      "comparacion con otros tipos de arboles. Son unos arboles grandes y frondosos. ";
   AddDetail(({"robles"}),"En esta zona hay bastantes de ellos.\n");
   break;
}

//Descripcion de los detalles de la zona
switch(random(6)){
case 0:
   s+="En esta zona del bosque la tierra que pisas esta mas bien humeda, quiza debido "
      "a alguna lluvia reciente o al paso de algun acuifero subterraneo cerca de aqui.";
   AddDetail(({"suelo"}),"La tierra del suelo que pisas esta humeda.\n");
   prob_seta=MIN(100,prob_seta*4);
   break;
case 1:
   s+="El suelo esta cubierto de una mullida capa de hojarasca que cruje al pisarla.";
   AddDetail(({"hojarasca","hojas"}),
      "La hojarasca es la capa de hojas secas caidas de los arboles que hay en el suelo.\n");
   break;
case 2:
   s+="Unos altos y espesos matorrales te impiden continuar hacia algunas direcciones.";
   AddDetail(({"matorrales"}),
      "Son lo bastante grandes como para impedirte avanzar en algunas direcciones.\n");
   break;
case 3:
   s+="Junto a ti se encuentra un viejo tronco medio podrido de lo que alguna vez debio "
      "ser un gran arbol. Es posible que sirva de refugio para algun pequenyo animal.";
   AddDetail(({"tronco"}),
      "Es solo un viejo tronco.\n");
   break;
case 4:
   s+="En el suelo puedes distinguir las huellas dejadas por algun animal del bosque.";
   AddDetail(({"huellas"}),
      "Parecen las huellas de un conejo.\n");
   break;
case 5:
   s+="Cerca de aqui ves un grupo de rocas.";
   AddDetail(({"rocas"}),"Son solo un grupo de rocas en medio del bosque.\n");
   break;
}
return (s+"\n");
}


InitVars(){
  prob_seta=PROB_SETA;
  return;
}


AnyadirPnjs(){
  if (random(100)<PROB_AVE) AddItem(PNJ("camino/aveboske"),REFRESH_DESTRUCT,1);
  // if (random(100)<PROB_MAMIFERO) AddItem(PNJ("animal/mamboske"),REFRESH_DESTRUCT,1);
  // if (random(100)<PROB_OSO) AddItem(PNJ("animal/oso_base"),REFRESH_DESTRUCT,1);
  //if (random(100)<PROB_BANDIDO) AddItem(PNJ_STD("bandido"),REFRESH_DESTRUCT,1);
  return;
}


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


create()
{
  ::create();
  InitVars();
  if (!QueryNombreBosque()) SetNombreBosque("de nadie");
  SetIntShort("el bosque "+QueryNombreBosque());
  SetIntLong(Desc());

  SetIntNoise("Oyes el canto de los pajaros.\n");
  SetIntSmell("Huele a bosque.\n");
  SetLocate("bosque "+QueryNombreBosque());
  SetIndoors(0);

  AnyadirSetas();
  AnyadirHierbas();
  AnyadirPnjs();
}
