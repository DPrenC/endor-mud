/*
DESCRIPCION : fonda base
FICHERO     : /d/akallab/std/fonda.c
MODIFICACION: 17-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <moving.h>
#include <money.h>

#include <rooms.h>
#include <properties.h>
#include <colours.h>

inherit ROOM;
inherit "/lib/money";

// Variables internas
string fonda;      //nombre de la fonda
string duenyo;     //nombre del duenyo de la fonda
string lugar;      //nombre del lugar donde esta la fonda
string ultimo;     //nombre del ultimo cliente
mapping comidas;   //lista de comidas disponibles
mapping bebidas;   //lista de bebidas disponibles
int    haybebidas; //hay algo de beber
int    ncomidas;   //numero de comidas

// Declaracion de funciones
void    HazDescr();
int    AddComida(string nombre, int precio, int poder, int nmax);
int    AddBebida(string nombre, int precio, int sed, int alcohol, int hp);
string VerMenu();
int    curar(int n);
int    consumir(string s);
int    TieneDinero(int n);
int    NoHayComidaMsg(string s);
int    SiHayComidaMsg(string s);
int    TraerComidaMsg(string s);
int    TraerBebidaMsg(string s);
int    DigerirComida(int poder);
int    BeberBebida(int precio, int sed, int alcohol, int hp, string que);
int    reponer();

// Definicion de minifinciones
string QueryNombreFonda(){return fonda;}
string QueryNombreDuenyo(){return duenyo;}
string QueryLugar(){return lugar;}
int    SetNombreFonda(string s){fonda=s; HazDescr(); return 1;}
int    SetNombreDuenyo(string s){duenyo=s; HazDescr(); return 1;}
int    SetLugar(string s){lugar=s; HazDescr(); return 1;}
int    VerMenuCmd(){write(VerMenu());return 1;}

//Formulas para el efecto de las comidas
#define COMIDA_FOOD(x)    (x*3)
#define COMIDA_HP(x)      (x*2)


create(){
 ::create();
 fonda="";
 duenyo="un orco";
 lugar="";
 haybebidas=0;
 ncomidas=0;

 HazDescr();

 AddDetail(({"cocina","puerta"}),
 "En un extremo de la fonda hay una puerta que conduce a la cocina. Es "
   "alli donde se preparan las comidas que se sirven en la fonda. La puerta "
   "es de doble hoja con unos resortes que hacen que se cierre sola: cuando "+
   duenyo+" viene cargado con comida desde la cocina solo debe empujarla "
   "para pasar.\n");

 AddDetail(({"mesas"}),
 "La fonda esta llena de ellas. Donde sino iban a comer los clientes?\n");

 AddDetail(({"chimenea"}),
 "Al fondo de la habitacion hay una gran chimenea en la que siempre hay "
   "un agradable fuego que mantiene la fonda a una confortable temperatura.\n");

AddDetail(({"escalera"}),
"La escalera permite subir al piso de arriba donde viven los duenyos.\n");

AddDetail(({"menu"}),SF(VerMenu));

AddRoomCmd ("menu", SF(VerMenuCmd));
AddRoomCmd ("pedir", SF(consumir));

SetIntNoise("Oyes a la gente comiendo.\n");
SetIntSmell("Hmmmm! el olor que llega de la cocina te hace la boca agua.\n");
SetIndoors(1);
SetIntBright(50);

AddItem(PNJ("z_ciudad/bardo"),REFRESH_DESTRUCT,1);

//Ejemplos:
//AddComida("un javali asado", 200, 12, random(2)+1);
//AddBebida("un vaso de vino",5,5,4,3);
}


//Definicion de funciones

void HazDescr()
{
string l;
l="Te encuentras en "+(fonda==""?"una fonda":"la fonda "+fonda)+", un "
  "pequenyo pero acogedor local"+(lugar!=""?" de "+lugar:"")+". El local es "
  "regentado por "+duenyo+", un orco atento aunque mas bien seco que atiende "
  "a la clientela. Su esposa es la encargada de preparar las comidas que "
  "puedes ver en el "+TC_BOLD+"menu"+TC_NORMAL+" que se sirven aqui: "
  "sabrosas y con precios moderados. El local esta lleno de mesas y tiene "
  "una gran chimenea al fondo. Una puerta comunica con la cocina y una "
  "escalera con el piso de arriba.\n";
SetIntShort((fonda==""?"En una fonda":"En la fonda "+fonda));
SetIntLong(l);
}


int AddComida(string nombre, int precio, int poder, int nmax)
{
if (!comidas) comidas=([nombre: nmax; precio; poder; nmax]);
else comidas+=([nombre: nmax; precio; poder; nmax]);
ncomidas+=nmax;
return 1;
}

int AddBebida(string nombre, int precio, int sed, int alcohol, int hp)
{
if (!bebidas) bebidas=([nombre: precio; sed; alcohol; hp]);
else bebidas+=([nombre: precio; sed; alcohol; hp]);
haybebidas=1;
return 1;
}


string VerMenu()
{
int i,j;
string s;
string *keys;
j=0;
i=0;
if ((haybebidas==0)&&(ncomidas==0)) return (MAY(duenyo)+", el posadero, "
   "te dice: Lo siento, pero en este momento no nos queda nada. Vuelve mas "
   "tarde cuando se hayan cocinado nuevos platos.\n");
s=duenyo+" te dice: 'Esto es lo que servimos en esta fonda:\n";
if (sizeof(comidas)>0)
   {
   keys = m_indices(comidas);
   s+="COMIDAS\n";
   for (i=0; i<sizeof(keys); i++){
       s+=i+1+": "+capitalize(keys[i])+" ("+comidas[keys[i],1]+")\n";
       }
   }
j=i;
if (sizeof(bebidas)>0)
   {
   keys = m_indices(bebidas);
   s+="\nBEBIDAS\n";
   for (i=0; i<sizeof(keys); i++){
       s+=i+j+1+": "+capitalize(keys[i])+" ("+bebidas[keys[i],1]+")\n";
       }
   }
s+="\nUsa "+TC_BOLD+"pedir <numero>"+TC_NORMAL+" para consumir ahora lo que quieras.\nBuen provecho'.\n";
return s;
}


int TieneDinero(int n)
{
if (!TP) return 0;
if (QuerySomeonesValue (TP) < n)
   {
   write("Cuando vas a pagar te das cuenta de que no llevas suficiente dinero.\n"
         "El posadero te dice:'Vaya... parece que no tienes suficiente dinero.\n"
         "Lo siento pero se ha de pagar lo que se consume'.\n");
   return 0;
   }
write("Le pagas a "+duenyo+" el importe de lo que has pedido.\n");
PayValue (TP, n);
return 1;
}


int curar(int n)
{
int hp, maxhp;
hp = TP->QueryHP();
maxhp =  TP->QueryMaxHP();
if (hp < maxhp)
   {
   if (hp + n > maxhp) n = maxhp - hp;
   TP->SetHP(hp + n);
   }
return 1;
}


int NoHayComidaMsg(string s)
{
string str;
say(capitalize(duenyo)+" grita a la cocina: Nos queda "+s+"?\n");
say("Desde la cocina se oye: No, ya no queda!\n");
str="El posadero te dice:' Los siento no nos queda "+s+".";
if (ncomidas!=0) str+=" Si te interesa aun nos quedan otras comidas.'\n";
else             str+=" Vuelve mas tarde cuando se hayan cocinado nuevos platos.'\n";
write(str);
return 1;
}


int SiHayComidaMsg(string s)
{
say("El posadero grita a la cocina: Nos queda "+s+"?\n");
say("Desde la cocina se oye: Si, aun tenemos!\n");
write("El posadero grita a la cocina: Nos queda "+s+"?\n"
      "Desde la cocina se oye: Si, aun tenemos!\n"
      "El posadero dice:'Perfecto! Ahora mismo te lo traigo.\n");
return 1;
}


int TraerComidaMsg(string s)
{
say(capitalize(duenyo)+" desaparece tras la puerta de la cocina. Al momento "
    "vuelve cargado con varias fuentes y jarras a la mesa donde esta "+NOMBRE+
    ".\n",TP);
write("El posadero te dice: 'Ahora te traigo "+s+"'.\n");
write(capitalize(duenyo)+" desaparece tras la puerta de la cocina. Al momento "
    "vuelve cargado con varias fuentes y jarras y te dice: 'Aqui tienes lo que "
    "me has pedido'.\n");
return 1;
}


int TraerBebidaMsg(string s)
{
say("El posadero desaparece tras la puerta de la cocina. Al momento "
    "vuelve cargado con una generosa jarra a la mesa donde esta "+NOMBRE+
    ".\n",TP);
write("El posadero te dice: 'Ahora te traigo "+s+".\n");
write("El posadero desaparece tras la puerta de la cocina. Al momento "
      "vuelve cargado con la bebida que le habias pedido.\n");
return 1;
}


int DigerirComida(int poder)
{
if (!TP) return 0;
if (! TP->AddFood (COMIDA_FOOD(poder)))
   {
   TP->SetFood(TP->QueryMaxFood());
   write("Cuando te traen la comida te das cuenta de que no "
           "estas tan hambrient"+AO+" como creias, por lo que "
           "dejas parte en el plato.\n");
   }
else write("Te comes la comida que habias pedido.\n");
if (NOMBRE==ultimo) write("El posadero dice:' Me alegro de que repita en mi establecimiento.");
ultimo = NOMBRE;
curar(COMIDA_HP(poder));
write("\n");
return 1;
}


int BeberBebida(int precio, int sed, int alcohol, int hp, string que)
{
int beber;
if (!TieneDinero(precio)) return 1;
TraerBebidaMsg(que);
say (NOMBRE+" se bebe "+que+".\n");
write("Te bebes "+que+".\n");
if (!TP->AddDrink(sed))
   {
   TP->SetDrink(TP->QueryMaxDrink());
   write("No estas tan sedient"+AO+" como para acabarte la bebida.\n");
   }
if (! TP->AddAlcohol(alcohol))
   {
   write("El posadero te dice: 'Amig"+AO+", estas bastante borrach"+AO+
           ". Yo de tu no beberia mas.\n");
   }
curar(hp);
return 1;
}

int reponer()
{
int i;
string *keys;
if (sizeof(comidas)>0)
   {
   keys = m_indices(comidas);
   for (i=0; i<sizeof(keys); i++){
       comidas[keys[i],0]=comidas[keys[i],3];
       ncomidas+=comidas[keys[i],3];
       }
   }
return 1;
}

int consumir(string s)
{
int cont, encontrado, i;
string *keys;
cont=1;
encontrado=0;
if (!s)
   {
   write("El posadero te dice: 'Tendras que decirme que es lo que quieres'.\n");
   return 1;
   }
if ((ncomidas==0)&&(haybebidas==0))
   {
   write(duenyo+", el posadero, te dice:'Lo siento, pero en este momento "
         "no nos queda nada. Vuelve mas tarde cuando se hayan cocinado "
         "nuevos platos.\n");
   return 1;
   }

if (sizeof(comidas)>0)
   {
   keys = m_indices(comidas);
   for (i=0; i<sizeof(keys); i++){
       if (((string)cont==s)||("<"+(string)cont+">"==s))
          {
          encontrado=1;
          if (comidas[keys[i],0]==0) NoHayComidaMsg(keys[i]);
          else
             {
             SiHayComidaMsg(keys[i]);
             if (TieneDinero(comidas[keys[i],1]))
                {
                TraerComidaMsg(keys[i]);
                DigerirComida(comidas[keys[i],2]);
                comidas[keys[i],0]--;
                ncomidas--;
                if (ncomidas==0) call_out("reponer",180);
                }
             }
          }
       cont++;
       }
   }

if ((sizeof(bebidas)>0)&&(encontrado==0))
   {
   keys = m_indices(bebidas);
   for (i=0; i<sizeof(keys); i++){
       if (((string)cont==s)||("<"+(string)cont+">"==s))
          {
          encontrado=1;
          //({  ({nombre}),({precio,sed,alcohol,hp})  })
          BeberBebida(bebidas[keys[i],0],bebidas[keys[i],1],bebidas[keys[i],2],bebidas[keys[i],3],keys[i]);
          }
       cont++;
       }
   }

  if (encontrado==0) write("El posadero dice: 'No tenemos ese numero en el menu, elige otra cosa'.\n");
  return 1;
}
