/*
DESCRIPCION  : 	Kara, la curandera
FICHERO      : 	/d/akallab/comun/pnj/curandera.c
MODIFICACION : 	16-09-98 [Chaos@Simauria]Creacion
	        Es provisional mas adelante tendra mas cosas
	        23-02-00 [Nemesis@Smauria] Multiplicado el coste por 10
--------------------------------------------------------------------------------
*/

#include <living.h>
#include <combat.h>
#include <money.h>
#include <gremios.h>
#include <config.h> //por NOTIFY_NOT_CMD
inherit NPC;
inherit "/lib/money";

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

int tieneDinero(int n);

create() {
  ::create();
 SetStandard("Kara","orco",([GC_CLERIGO:12]),GENDER_FEMALE);
  SetShort("Kara, la curandera");
  SetLong(
    "Kara es una vieja orco hermitaña. Hace mucho tiempo que se dedica a la medicina y que vive en "
    "en este bosque alejada de toda civilizacion. Como orco que es, siempre le ha preocupado mas que su medicina "
    "cure al enfermo y no tanto el sabor de un medicamento o la cicatriz que queda "
    "tras una curacion. Todos sus remedios los obtiene de las plantas que crecen en este bosque, y "
    "si hay algun ingrediente que no puede encontrar envia a alguien para que se lo consiga.\n");
  SetWeight(65000);
  SetGoChance(0);

  SetAlign(-100);
  SetMaxHP(600);
  SetHP(600);
  SetIds(({"kara","Kara","curandera","orco"}));

  InitChats(8,({
// --------------------------------------------------------------------------------
  "Kara coge un tarro de una de las extanterias y saca de el un poco de un polvo "
  "rojizo que anyade al medicamento que esta preparando sobre el fuego.\n",
  "Kara se murmura para si:Donde puse las hojas de abedul? Ah si, ya me acuerdo.\n",
  "Kara te mira y te dice:Seguro que te estaras preguntando como soy capaz de "
  "encontrar algo entre tantos frascos. Hij"+AO+", son los anyos de experiancia...'\n",
  "Kara te dice:Acaso no te encuentras bien? En la nota de la pared tienes bien "
  "claro como trabajo. Si no te gusta, ya sabes donde esta la puerta'.\n",
  "Kara rebusca en unos cajones en busca de alguna receta.\n",
  "Kara remueve pacientemente el medicamento que esta fabricando.\n"    }) );
}

init() {
  ::init();
  add_action("cura_cmd","cura");
  add_action("coste_cmd","coste");
}


//porcentaje de cura segun el tipo
int cura(int tipo){
  int i;
  switch(tipo){
    case 0: i=20; break;
    case 1: i=60; break;
    case 2: i=100; break;
  }
  return i;
}


/* FORMULA: coste=base+hp*peso
   donde    base: precio base de cualquier servicio
            hp  : puntos de vida a recuperar
            peso: ponderacion segun el tipo de cura

                       base   peso
   cura rapida ( 20%)  50     25
   cura normal ( 60%)  50     18
   cura total  (100%)  50     12
*/
int coste(int tipo){
  int peso,base,hp,cur;
  base=50;
  hp=(TP->QueryHP())*100/TP->QueryMaxHP();
  switch(tipo){
    case 0: peso=25; cur=cura(0); break;
    case 1: peso=18; cur=cura(1); break;
    case 2: peso=12; cur=cura(2); break;
  }
  hp=((TP->QueryMaxHP())-(TP->QueryHP()))*cur/100;
  return (base+hp*peso)*10;
}


int coste_cmd(){
  int hp, maxhp, dam;
  string msg;
  msg="";
  hp=TP->QueryHP();
  maxhp=TP->QueryMaxHP();

  msg= "Kara dice:'Bien, hij"+AO+" veamos que tal estas de salud'.\n" //
       "Kara te realiza un rapido examen preliminar para hacerse una idea de tu estado.\n";
  dam=hp*100/maxhp;

  say("Kara examina el estado de saluda de "+NOMBRE+".\n",TP);

  if (dam==100){
    msg+= "'Tu estas perfectamente de salud. Hij"+AO+", no me hagas perder el tiempo!'\n";
    write(msg);
    return 1;
  }

  if (dam>=75)
  msg+="Kara dice:'Hij"+AO+", parece que no estas muy mal, tan solo heridas superficiales "
       "algun que otro feo moraton, pero poco mas. Bah! son solo aranyazos'.\n";

  if ((dam>=50)&&(dam<75))
  msg+="Kara dice:'Hij"+AO+", tienes algunas heridas que empiezan a ser preocupantes. "
       "No te moriras, pero deberias preocuparte. Alguien podria aprovecharse...'\n";

  if ((dam>=25)&&(dam<50))
  msg+="Kara dice:'Hij"+AO+", no hace falta que te diga yo como estas. Tus heridas son "
       "considerables y tenes algunas hemorragias internas. Yo de tu me curaria pronto'.\n";

  if (dam<25)
  msg+="Kara dice:'Hij"+AO+", estas mal, muy mal. Tus heridas son muy feas y bastante "
       "graves. No te queda mucha vida asi no tienes demasido tiempo para pensartelo...'\n";

  msg+="Kara te dice:'Ummmh....en tu estado una cura rapida te costara "+coste(0)+" monedas "
       "de cobre; una normal, unas "+coste(1)+" y una cura total unas "+coste(2)+". Tu decides'.\n";

  write(msg);
  return 1;
}


int cura_cmd(string tipo){
  int pela,hp,cur;

  if ((!tipo)||((tipo!="rapida")&&(tipo!="normal")&&(tipo!="completa")))
  return notify_fail(
     "Kara dice:'Que te haga una cura? vale, pero hij"+AO+", tendras que especificar de "
     "que tipo la quieres. Hazte un favor y mira la nota de la pared.\n",NOTIFY_NOT_VALID)&&0;

  switch(tipo){
    case "rapida"  : pela=coste(0); cur=cura(0); break;
    case "normal"  : pela=coste(1); cur=cura(1); break;
    case "completa": pela=coste(2); cur=cura(2); break;
    }

  if ((TP->QueryHP())==(TP->QueryMaxHP()))
     return notify_fail(
     "Kara dice:'Una cura "+tipo+"? Para que, tu estas completamente san"+AO+".\n",NOTIFY_NOT_VALID)&&0;

  write("Kara dice:'Vamos a ver, o sea que quieres una cura "+tipo+". Pero antes, lo "
        "primero es lo primero, tienes las "+pela+" monedas de cobre que cuesta?\n");

  if (tieneDinero(pela)==1){
      hp=((TP->QueryMaxHP())-(TP->QueryHP()))*cur/100;
      TP->SetHP(TP->QueryHP()+hp);
      write("Kara coge un tarro de una de las estanterias y extrae de el un espeso unguento "
            "que te aplica con cuidado en las heridas. Escuece, pero notas como el dolor de "
            "las heridas te va disminuyendo.\n");
     }

  return 1;
}


int tieneDinero(int n)
{
    if (!TP) return 0;
    if (QuerySomeonesValue (TP) < n)
    {
        write("Cuando vas a pagar te das cuenta de que no llevas suficiente dinero. "
              "Kara te dice:'No tienes dinero? Pues lo siento hij"+AO+", sin dinero no hay "
              "cura. Yo me gano la vida con este trabajo.\n");
        return 0;
    }
    write("Le pagas a Kara el importe de la cura.\n");
    PayValue (TP, n);
    return 1;
}
