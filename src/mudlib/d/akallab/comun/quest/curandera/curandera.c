/*
DESCRIPCION  : La curandera del bosque de Talek
FICHERO      : /d/akallab/comun/quest/curandera/curandera.c
MODIFICACION : 13-02-99 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <colours.h>
#include <messages.h>
inherit NPC;
inherit "/lib/money";


int tieneDinero(int n);

create()
{
    ::create();
    SetStandard("Nereba","orco",6,GENERO_FEMENINO);
    SetName("Nereba");
    SetShort("Nereba, la vieja curandera");
    SetLong("Nereba es una vieja curandera orca. Vive en una pequeña cabaña en el claro del "
        "bosque de Talek. Es ya muy mayor, pero aún recuerda los secretos de su oficio, y "
        "prepara pociones con ingredientes del bosque. Dada su avanzada edad, tiene con ella a "
        "una joven ayudante que la asiste y a la que enseña el oficio. Siempre necesita nuevos "
        "ingredientes.\n");
    SetAlign(-100);
    SetIds(({"nereba","Nereba","curandera","vieja","orca"}));
    InitChats(15,({
        "La curandera machaca unas hojas secas en un mortero.\n",
        "La curandera le dice a su ayudante: Casi no quedan algunos ingredientes...\n"
            "Luego te mira y dice: 'Si quieres ayudarme, pregúntame por ingredientes y te "
            "diré como hacerlo.'\n",
        "La curandera busca ingredientes en las estanterías de las paredes.\n",
        "La curandera te dice: Puedo curar tus heridas por un precio razonable. "
            "Pregúntame por curas, y te informaré con más detalle.\n",
        "La vieja curandera remueve pacientemente el contenido de la marmita.\n"}));
    AddQuestion(({"curas","cura"}),"La curandera te dice: Utilizando las pociones que fabrico "
        "y mis conocimientos, puedo curar tus heridas por un precio razonable. Soy capaz de "
        "realizar tres tipos de curas distintas: rápida, es barata, pero solo sanas un poco.\n"
        "normal, precio normal, sanas bastante.\ncompleta (es cara, pero te cura totalmente)\n"
        "Para que te cure utiliza "+TC_BOLD+"cura <tipo>"+TC_NORMAL+" y para que te diga "
        "cuánto te costará en tu estado de salud actual una cura, utiliza "+TC_BOLD+"coste"+
        TC_NORMAL+".\n");
}

init()
{
    ::init();
    add_action("cura_cmd","cura");
    add_action("coste_cmd","coste");
    add_action("preguntar_cmd","preguntar");
    add_action("dar_cmd","dar");
}


//porcentaje de cura segun el tipo
int cura(int tipo)
{
    int i;
    switch(tipo)
    {
        case 0:
            i=20;
        break;
        case 1:
            i=60;
        break;
        case 2:
            i=100;
        break;
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
  return (base+hp*peso);
}


int coste_cmd(){
  int hp, maxhp, dam;
  string msg;
  msg="";
  hp=TP->QueryHP();
  maxhp=TP->QueryMaxHP();
  msg= "\nLa curandera te dice:'Bien, hij"+AO+" veamos que tal estas de salud'. "
       "La curandera te realiza un rapido examen preliminar para hacerse una idea de "
       "tu estado.";
  write(msg+"\n");
  msg="";

  dam=hp*100/maxhp;
  say("La curandera examina el estado de saluda de "+NOMBRE+".\n",TP);

  if (dam==100){
    msg+= "'Tu estas perfectamente de salud. Hij"+AO+", no me hagas perder el tiempo!'\n";
    write(msg);
    return 1;
  }

  if (dam>=75)
  msg+="La curandera dice:'Hij"+AO+", parece que no estas muy mal, tan solo heridas "
       "superficiales y algun que otro feo moraton, pero poco mas. Bah! son solo "
       "aranyazos'.\n";

  if ((dam>=50)&&(dam<75))
  msg+="La curandera dice:'Hij"+AO+", tienes algunas heridas que empiezan a ser "
       "preocupantes. No te moriras, pero deberias preocuparte. Alguien podria "
       "aprovecharse...'\n";

  if ((dam>=25)&&(dam<50))
  msg+="La curandera dice:'Hij"+AO+", no hace falta que te diga yo como estas. "
       "Tus heridas son considerables y tenes algunas hemorragias internas. Yo "
       "de tu me curaria pronto'.\n";

  if (dam<25)
  msg+="La curandera dice:'Hij"+AO+", estas mal, muy mal. Tus heridas son muy "
       "feas y bastante graves. No te queda mucha vida asi no tienes demasido "
       "tiempo para pensartelo...'\n";

  msg+="La curandera te dice:'Ummmh....en tu estado una cura rapida te costara "+
       coste(0)+" monedas de cobre; una normal, unas "+coste(1)+" y una cura "
       "total unas "+coste(2)+". Tu decides'.\n";

  write(msg);
  return 1;
}


int cura_cmd(string tipo){
  int pela,hp,cur;

  if ((!tipo)||((tipo!="rapida")&&(tipo!="normal")&&(tipo!="completa")))
  return notify_fail(
       "La curandera dice:'Que te haga una cura? vale, pero hij"+
        AO+", tendras que especificar de que tipo la quieres. Preguntame "
       "por curas y te lo explicare.\n",NOTIFY_NOT_VALID);

  switch(tipo){
    case "rapida"  : pela=coste(0); cur=cura(0); break;
    case "normal"  : pela=coste(1); cur=cura(1); break;
    case "completa": pela=coste(2); cur=cura(2); break;
    }

  if ((TP->QueryHP())==(TP->QueryMaxHP()))
     return notify_fail(
     "La curandera dice:'Una cura "+tipo+"? Para que, tu estas completamente san"+AO+".\n",NOTIFY_NOT_VALID)&&0;

  write("La curandera dice:'Vamos a ver, o sea que quieres una cura "+tipo+". Pero "
          "antes, lo primero es lo primero, tienes las "+pela+" monedas de cobre que "
          "cuesta?'\n");

  if (tieneDinero(pela)==1){
      hp=((TP->QueryMaxHP())-(TP->QueryHP()))*cur/100;
      TP->SetHP(TP->QueryHP()+hp);
      write("La curandera coge un tarro de una de las estanterias y extrae de el "
              "un espeso unguento que te aplica con cuidado en las heridas. Escuece, "
              "pero notas como el dolor de las heridas te va disminuyendo.\n");
     }
  return 1;
}


int tieneDinero(int n)
{
    if (!TP) return 0;
    if (QuerySomeonesValue (TP) < n)
    {
        write("Cuando vas a pagar te das cuenta de que no llevas suficiente "
                "dinero. La curandera te dice: 'No tienes dinero? Pues lo "
                "siento hij"+AO+", sin dinero no hay cura. Yo me gano la "
                "vida con este trabajo.\n");
        return 0;
    }
    write("Le pagas a la curandera el importe de la cura.\n");
    PayValue (TP, n);
    return 1;
}


int preguntar_cmd(string str) {
 object quien, ob;
 string a;
 quien=TP;
 if (!quien || !str) return 0;
 if ((sscanf(str,"a curandera sobre %s",a)==1)||
     (sscanf(str,"a nereba sobre %s",a)==1)||
     (sscanf(str,"a Nereba sobre %s",a)==1)){

      if ((a!="ingrediente")&&(a!="ingredientes")){
         return notify_fail("La curandera se encoge de hombros.\n",NOTIFY_NOT_VALID)&&0;
         }
      else{
         write("\nLa curandera te dice: 'Apenas me quedan algunos tipos de "
               "ingredientes con los que preparo pociones y unguentos. Estoy "
               "ocupada y no puedo ir a buscarlos en este momento asi que si "
               "tu lo haces por mi te recompensare con un par de pociones "
               "curativas. Creo que es un trato justo. Los ingredientes que "
               "necesito se pueden encontrar por este valle, especialmente "
               "en este bosque.\n");
         ob=present("lista",TP);
         if (!ob || !call_other(ob,"id","lista_componentes_quest")){
            ob=clone_object(QUEST+"curandera/lista");
            ob->move(TP);
            write("Toma una lista de los ingredientes que necesito. Cuando "
                    "consigas alguno de ellos, lo traes y me lo das, y yo lo "
                    "tachare de la lista. Cuando me los hayas traido todos te "
                    "dare tu recompensa.'\n");
            return 1;
            }
         else{
            write("Ya tienes una lista de los ingredientes que necesito. "
                    "Consigue los que faltan en ella y te dare tu recompensa.'\n");
            return 1;
            }
         }
    }
    else return notify_fail("La curandera se encoge de hombros.\n",NOTIFY_NOT_VALID)&&0;
}


int dar_cmd(string str) {
object from, ob, ob2, lista;
int num;
string a, b, Quests;

 from=TP;
 if (!from || !str) return 0;
 if ((sscanf(str,"%s a curandera",a)==1)||
     (sscanf(str,"%s a nereba",a)==1)||
     (sscanf(str,"%s a Nereba",a)==1))
     {
     ob  =  present(a,TP);
     if (!ob) return notify_fail("Tu no tienes "+a+".\n",NOTIFY_NOT_VALID)&&0;
     lista =  present("lista",TP);
     if (!lista || !call_other(lista,"id","lista_componentes_quest"))
        {
        write("La curandera te dice: 'Un regalo? Gracias "+NOMBRE+"!'\n");
        ob->remove();
        return 1;
        }
     else
        {
if (lista->EsObjDeLista(ob,from))
           {
           write("La curandera te dice: 'Bien "+NOMBRE+", has conseguido uno "
                   "de los ingredientes de la lista que te di. Lo marcare en la "
                   "lista para que no se me olvide.'\n");
           if (lista->faltan()==0)
              {
              write("La curandera mira la lista y te dice: Vaya, parece que acabas "
                      "de entregarme el ultimo de los ingredientes que faltaba!. Bien, "
                      "hij"+AO+" lo prometido es deuda. Toma las dos pociones que te "
                      "prometi.'\n");
              write("La curandera te da dos pociones curativas.\n");
              tell_room(TO, ({ MSG_SEE, "La curandera da dos pociones a "+NOMBRE+" como pago por sus servicios.\n"}), ({ TP }));

              ob2=clone_object(POCION("pocion_curativa"));
              ob2->move(TP);
              ob2=clone_object(POCION("pocion_curativa"));
              ob2->move(TP);

              Quests=from->QueryQuests();
              if (!Quests) Quests="hallo";
              if (sscanf(Quests,"%sngredientes_curandera_bosqu%s",a,b)!=2)
                 {
                 write("\nAcabas de resolver el quest de la curandera del bosque de Talek.\n\n");
                 QUESTMASTER->InformSolution("La curandera del bosque de Talek ha "
                       "conseguido nuevos ingredientes gracias a "+NOMBRE);
                 QUESTMASTER->SetPlayerQuest("ingredientes_curandera_bosque",TP);
                 }


              write("La curandera te dice:' Ya no necesitaras mas la lista de los "
                      "ingredientes, asi que me la quedare yo. Gracias por tu ayuda.'\n\n");
              lista->remove();
              }
           else
              {
              write("La curandera mira la lista y te dice: 'Animo, ya solo "
                        "te falta conseguir "+lista->faltan()+" ingrediente"+
                        (lista->faltan()>1?"s":"")+".'\n");
              }
           }
           else write("La curandera te dice: 'Un regalo? Gracias "+NOMBRE+"!'\n");
           ob->remove();
           return 1;
        }
     }
 return 0;
}

