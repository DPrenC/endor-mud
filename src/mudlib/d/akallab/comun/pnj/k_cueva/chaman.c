/*
DESCRIPCION  : Koll, el chaman-curandero
FICHERO      : /d/akallab/comun/pnj/k_cueva/chaman.c
MODIFICACION : 24-11-99 [Angor@Simauria]Creacion
               23-02-00 [Nemesis@Simauria] Multiplicado el coste por 10
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
 SetStandard("Koll","troll",([GC_CLERIGO:12]),GENDER_MALE );
  SetShort("Koll, el chaman y curandero");
  SetLong(
    "Koll es un viejo y escualido troll. A traves de su arrugada piel se adivinan "
	  "sus viejos y gastados huesos. Es el chaman de la tribu y su funcion es la de "
	  "velar por la roca sagrada que protege a la tribu de los malos espiritus. Es "
	  "ademas uno de los principales consejeros del jefe de la tribu. Dicen que los "
	  "espiritus de la roca le ensenyaron lo secretos que le han llevado a ser "
	  "tambien un conocido curandero.\n");
  SetWeight(80000);
  SetGoChance(0);
  SetAlign(-100);
  SetIds(({"koll","Koll","curandero","chaman","troll"}));

  InitChats(8,({
    "Koll coge unas hierbas de uno de los cuencos y las echa al caldero\n",
    "El contenido del caldero hierve lentamente.\n\n",
    "El chaman prueba el sabor del contenido del caldero y hace un gesto "
    "de asentimiento.\n\n",
    "Koll se murmura para si:Donde puse las hojas de abedul? Ah si, ya me acuerdo.\n\n",
    "El chaman te dice: Acaso no te encuentras bien? Mira el amuleto de la "
    "puerta y los espiritus te guiaran.\n\n",
    "Koll rebusca entre los cuencos en busca de algun ingresdiente.\n\n",
    "El chaman remueve pacientemente el medicamento que esta fabricando.\n\n"
   }) );
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

  msg= "Koll dice: Bien, hij"+AO+" veamos que tal estas de salud.\n" //
       "Koll te realiza un rapido examen preliminar para hacerse una idea de tu estado.\n";
  dam=hp*100/maxhp;

  say("Koll examina el estado de salud de "+NOMBRE+".\n",TP);

  if (dam==100){
    msg+= "'Tu estas perfectamente de salud. Hij"+AO+", no me hagas perder el tiempo!\n";
    write(msg);
    return 1;
  }

  if (dam>=75)
  msg+="Koll dice: Hij"+AO+", parece que no estas muy mal, tan solo heridas superficiales "
       "algun que otro feo moraton, pero poco mas. Bah! son solo aranyazos.\n";

  if ((dam>=50)&&(dam<75))
  msg+="Koll dice: Hij"+AO+", tienes algunas heridas que empiezan a ser preocupantes. "
       "No te moriras, pero deberias preocuparte. Alguien podria aprovecharse...\n";

  if ((dam>=25)&&(dam<50))
  msg+="Koll dice: Hij"+AO+", no hace falta que te diga yo como estas. Tus heridas son "
       "considerables y tienes algunas hemorragias internas. Yo de tu me curaria pronto.\n";

  if (dam<25)
  msg+="Koll dice: Hij"+AO+", estas mal, muy mal. Tus heridas son muy feas y bastante "
       "graves. No te queda mucha vida asi no tienes demasido tiempo para pensartelo...\n";

  msg+="Koll te dice: Ummmh....en tu estado una cura rapida te costara "+coste(0)+" monedas "
       "de cobre; una normal, unas "+coste(1)+" y una cura total unas "+coste(2)+". Tu decides.\n";

  write(msg);
  return 1;
}


int cura_cmd(string tipo){
  int pela,hp,cur;

  if ((!tipo)||((tipo!="rapida")&&(tipo!="normal")&&(tipo!="completa")))
  return notify_fail(
     "Koll dice: Que te haga una cura? vale, pero hij"+AO+", tendras que especificar de "
     "que tipo la quieres. Hazte un favor y mira el amuleto de la pared.\n",NOTIFY_NOT_VALID)&&0;

  switch(tipo){
    case "rapida"  : pela=coste(0); cur=cura(0); break;
    case "normal"  : pela=coste(1); cur=cura(1); break;
    case "completa": pela=coste(2); cur=cura(2); break;
    }

  if ((TP->QueryHP())==(TP->QueryMaxHP()))
     return notify_fail(
     "Koll dice: Una cura "+tipo+"? Para que, tu estas completamente san"+AO+".\n",NOTIFY_NOT_VALID)&&0;

  write("Koll dice: Vamos a ver, o sea que quieres una cura "+tipo+". Pero antes, lo "
        "primero es lo primero, tienes las "+pela+" monedas de cobre que cuesta?\n");

  if (tieneDinero(pela)==1){
      hp=((TP->QueryMaxHP())-(TP->QueryHP()))*cur/100;
      TP->SetHP(TP->QueryHP()+hp);
      write("Koll coge un cuenco de entre los que hay junto a la pared y "
	          "extrae de el un espeso unguento que te aplica con cuidado en "
			  "las heridas. Escuece, pero notas como el dolor de las heridas "
			  "te va disminuyendo.\n");
     }

  return 1;
}


int tieneDinero(int n)
{
    if (!TP) return 0;
    if (QuerySomeonesValue (TP) < n)
    {
        write("Cuando vas a pagar te das cuenta de que no llevas suficiente dinero. "
              "Koll te dice: No tienes dinero? Pues lo siento hij"+AO+", sin dinero no hay "
              "cura. Yo me gano la vida con este trabajo.\n");
        return 0;
    }
    write("Le pagas a Koll el importe de la cura.\n");
    PayValue (TP, n);
    return 1;
}

