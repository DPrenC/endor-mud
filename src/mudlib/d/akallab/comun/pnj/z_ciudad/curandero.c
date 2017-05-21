/*
DESCRIPCION  : Koubba, el curandero
FICHERO      : /d/akallab/comun/pnj/curandero.c
MODIFICACION : 16-09-98 [Angor@Simauria]Creacion
    23-02-00 [Nemesis@Simauria] Multiplicado el coste por 10. A ver
    si así le mola menos a la peña.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
#include <living.h>
#include <combat.h>
#include <money.h>
inherit NPC;
inherit "/lib/money";

#define AO      (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define NOMBRE  (capitalize(TP->QueryName()))

int tieneDinero(int n);

void recoger_(object papel, object pl)
{
    if ((!pl) || (member(papel->QueryIds(),"papel_gadline") <0)) return;
// nos aseguramos de que lo ha obtenido legalmente
    if (!pl->QueryAttribute("p_gadline") || papel->QueryOwner() != pl->QueryRealName())
    {
        write("Koubba mira el papel frunciendo el ceño y te dice: Hij"+AO+", esto no hay quien "
            "lo entienda, ¿quieres burlarte de mí? Estoy muy ocupado, así que no molestes.\n"
            "Acto seguido, arroja el papel al fuego.\n");
        say("Éste lo mira, y "
            "frunciendo el ceño le dice: Hij"+AO+", esto no hay quien lo entienda, ¿quieres "
            "burlarte de mí? Estoy muy ocupado, así que no molestes.\nActo seguido, arroja el "
            "papel al fuego.\n",pl);
        papel->remove();
        if (papel) destruct(papel);
        return;
    }
    say("Koubba mira el papel, sonríe levemente y dice: Vaya, le debo algunos favores a esa "
        "pobre chica. Veamos...\nSeguidamente, pone en un recipiente algunos ingredientes que "
        "va sacando de los cajones,y lo coloca al fuego. Al cabo de un rato, retira el "
        "cacharro del fuego, filtra el líquido que recoge en un pequeño vial, añade una última "
        "pizca de un polvo oscuro que se disuelve inmediatamente, y vuelve a colocar el vial "
        "sobre la llama. Al cabo de un momento, el líquido se torna de un intenso color morado, "
        "y Koubba, sirviéndose de unas diminutas tenazas, aprieta el borde semifundido de la "
        "ampolla diciendo: Debe permanecer cerrado hasta el momento de consumirse, el aire lo "
        "estropea.\n");
    write("Luego se dirige a ti y te entrega el vial añadiendo: Aquí lo tienes. Dale recuerdos "
        "a Gadline de mi parte.\n");
    say("Luego se dirige a "+capitalize(pl->QueryName())+" y le entrega el vial añadiendo: "
        "Aquí lo tienes. Dale recuerdos a Gadline de mi parte.\n",pl);
    object vial=clone_object(OTRO("pocion_g"));
    vial->SetOwner(pl->QueryRealName());
    if (!vial->move(pl)) vial->move(environment());
    papel->remove();
    if (papel) destruct(papel);
    return;
}
                
create()
{
    ::create();
   SetStandard("Koubba","orco",6,GENERO_MASCULINO);
    SetName("Koubba");
    SetShort("Koubba, el curandero");
    SetLong("Koubba es un viejo orco. Su cuerpo muestra las cicatrices de su pasado ya lejano "
        "como guerrero. Hace ya mucho tiempo que se dedica a la medicina y que vive en esta "
        "ciudad. Su talento es reconocido y entre sus pacientes se encuentra el mismo "
        "governador. Como orco que es, siempre le ha preocupado más que su medicina cure al "
        "enfermo y no tanto el sabor de un medicamento o la cicatriz que queda tras una "
        "intervención. Su medicina funciona y eso a él le basta.\n");
    SetWeight(65000);
    SetAlign(-100);
    SetIds(({"koubba","Koubba","curandero","orco"}));
    InitChats(8,({
        "Koubba coge un tarro de una de las estanterías y saca de él un poco de un polvo "
            "rojizo que añade al medicamento que está preparando sobre el fuego.\n",
        "Koubba murmura para sí: ¿Dónde puse las hojas de abedul? Ah sí, ya me acuerdo.\n",
        "Koubba te mira y te dice: Seguro que te estarás preguntando cómo soy capaz de "
            "encontrar algo entre tantos frascos. Hij"+AO+", son los años de experiencia...\n",
        "Kouba te dice: ¿Acaso no te encuentras bien? En la nota de la pared tienes bien claro "
            "cómo trabajo. Si no te gusta, ya sabes dónde está la puerta.\n",
        "Koubba rebusca en unos cajones en busca de alguna receta.\n",
        "Koubba remueve pacientemente el medicamento que está fabricando. "
    }));
}

init() {
  ::init();
  add_action("cura_cmd","cura");
  add_action("coste_cmd","coste");
}

//porcentaje de cura segun el tipo
int cura(int tipo)
{
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
int coste(int tipo)
{
    int peso,base,hp,cur;
    base=50;
    hp=(TP->QueryHP())*100/TP->QueryMaxHP();
    switch(tipo)
    {
        case 0:
            peso=25;
            cur=cura(0);
        break;
        case 1:
            peso=18;
            cur=cura(1);
        break;
        case 2:
            peso=12;
            cur=cura(2);
        break;
    }
    hp=((TP->QueryMaxHP())-(TP->QueryHP()))*cur/100;
    return (base+hp*peso)*10;
}

coste_cmd(){
  int hp, maxhp, dam;
  string msg;
  msg="";
  hp=TP->QueryHP();
  maxhp=TP->QueryMaxHP();

  msg= "Koubba dice: Bien, hij"+AO+", veamos que tal estás de salud.\n"
       "Kouba te realiza un rápido examen preliminar para hacerse una idea de tu estado.\n";
  dam=hp*100/maxhp;

  say("Koubba examina el estado de salud de "+NOMBRE+".\n",TP);

  if (dam==100){
    msg+= "Koubba dice: Tú estás perfectamente de salud. ¡Hij"+AO+", no me hagas perder el tiempo!\n";
    write(msg);
    return 1;
  }

  if (dam>=75)
  msg+="Koubba dice: Hij"+AO+", parece que no estas muy mal, tan sólo heridas superficiales "
       "algún que otro feo moratón, pero poco más. ¡Bah! son sólo arañazos.\n";

  if ((dam>=50)&&(dam<75))
  msg+="Koubba dice: Hij"+AO+", tienes algunas heridas que empiezan a ser preocupantes. "
       "No te morirás, pero deberías preocuparte. Alguien podría aprovecharse...\n";

  if ((dam>=25)&&(dam<50))
  msg+="Koubba dice: Hij"+AO+", no hace falta que te diga yo como estás. Tus heridas son "
       "considerables y tienes algunas hemorragias internas. Yo de ti me curaría pronto.\n";

  if (dam<25)
  msg+="Koubba dice: Hij"+AO+", estás mal, muy mal. Tus heridas son muy feas y bastante "
       "graves. No te queda mucha vida, así que no tienes demasiado tiempo para pensártelo...\n";

  msg+="Hmmm....en tu estado una cura rápida te costará "+coste(0)+" monedas "
       "de cobre; una normal, unas "+coste(1)+" y una cura total unas "+coste(2)+". Tú decides.\n";

  write(msg);
  return 1;
}

int cura_cmd(string tipo)
{
  int pela,hp,cur;

  if ((!tipo)||((tipo!="rapida")&&(tipo!="normal")&&(tipo!="completa")))
  return notify_fail(
     "Koubba dice: ¿Que te haga una cura? vale, pero hij"+AO+", tendrás que especificar de "
     "qué tipo la quieres. Hazte un favor y mira la nota de la pared.\n",NOTIFY_NOT_VALID)&&0;

  switch(tipo)
  {
    case "rapida"  : pela=coste(0); cur=cura(0); break;
    case "normal"  : pela=coste(1); cur=cura(1); break;
    case "completa": pela=coste(2); cur=cura(2); break;
    }

  if ((TP->QueryHP())==(TP->QueryMaxHP()))
     return notify_fail(
     "Koubba dice: ¿Una cura "+tipo+"? ¿Para qué? tu estas completamente san"+AO+".\n",NOTIFY_NOT_VALID)&&0;

  write("Koubba dice: Vamos a ver, o sea que quieres una cura "+tipo+". Pero antes, lo "
        "primero es lo primero, ¿tienes las "+pela+" monedas de cobre que cuesta?\n");

  if (tieneDinero(pela)==1){
      hp=((TP->QueryMaxHP())-(TP->QueryHP()))*cur/100;
      TP->SetHP(TP->QueryHP()+hp);
      write("Koubba coge un tarro de una de las estanterías y extrae de él un espeso ungüento "
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
              "Koubba te dice: ¿No tienes dinero? Pues lo siento hij"+AO+", sin dinero no hay "
              "cura. Yo me gano la vida con este trabajo.\n");
        return 0;
    }
    write("Le pagas a Koubba el importe de la cura.\n");
    PayValue (TP, n);
    return 1;
}

public int QueryKoubba() { return 1; }

void notify_enter(mixed from,int method,mixed extra)
{
	if (method == M_GIVE) call_out("recoger_",1,PO,from);
}

