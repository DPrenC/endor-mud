/* SIMAURIA '/obj/torch.c'
   ==========================
   [a] Angor@simauria
   [w] Woo@simauria
   [n] Nemesis@Simauria
   [h] Nyh@simauria

   24-01-97 [a] Traduccion.
   03-02-98 [w] Correccion de algunos typos y bugs.
   30-10-98 [n] Hace que sea un arma.
   31-10-98 [n] Realiza los siguientes cambios:
                - Una antorcha no se puede encender salvo que la empunyes.
		- Una antorcha se apaga automaticamente al ser desempunyada por
		  cualquier metodo, incluyendo suicidio del personaje.
		- Anyadido un add_action para "desempunyar" porque no se me ocu-
		  rre otra forma de desempunyarla. Si alguien lo sabe hacer de
		  otra manera, que lo diga...
	        - Cambiado el WC a 1 y toqueteada la formula que lo calcula.
	        - Puesta P_SIZE_GENERIC, claro.
   06/11/98 [g] Cambia el typo del short de la antorcha cuando esta gastada,
   		ya que ponia " restos una antorcha", con espacio y todo.
   		Cambiado para que diga "Los restos de una antorcha".
   11-12-98 [t] Le pone genero...
   21-09-99 [w] Le pone acentos y e�es.
   27-01-99 [w] Ale, solucionado lo de que pillara el /std/weapon/combat
   07-06-03 [h] Lo convierto en una linterna
*/

#include <config.h>
#include <lamp.h>
#include <properties.h>
#include <nightday.h>
#include <combat.h>

inherit "/std/lamp";

#define THIS TO

#define SUBID  (to_string(TO)+":subid")

private static int started;

public int QueryStarted()    { return started;}
public int SetStarted(int i) { return started = i;}

/*----------------------------------------------------------------------------
** Initialize us
*/

create(){
  lamp::create();
  AddId (({"antorcha","lampara", "l�mpara"}));
  SetShort("una l�mpara de aceite");
  SetWeights (200, 40);          /* Base weighs 200 gr, one unit 40 gr */
  Set(P_GENDER, GENDER_FEMALE);

  SetValues (50, 5);              /* Base is worth 1, one unit 1 */
  SetFuelAmount (15+random(6));  /* 15..20 units a 5 minutes */
  SetRechargeable(1);
  SetBrightness (REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetLampMsg ( ({
 "La l�mpara ya esta encendida.\n"
,"La l�mpara no esta encendida.\n"
,"La l�mpara esta totalmente vac�a. No puede volver a encenderse a menos que la rellenes.\n"
,"Acercas @@Lighter@@ a la mecha de la l�mpara. Con unos golpecitos, consigues "
"hacer saltar unas chispas que la encienden rapidamente.\n"
,"@@Pl_Name@@ acerca @@Lighter@@ a la mecha de la l�mpara. Tras golpearlo repetidamente, consigue "
"hacer saltar una chispa, que prende en la mecha, encendi�ndola.\n"
,"Soplas sobre la l�mpara, apag�ndola.\n"
,"@@Pl_Name@@ apaga su l�mpara.\n"
,"Tu l�mpara parpadea y se apaga.\n"
,"La l�mpara de @@Pl_Name@@ parpadea y se apaga.\n",
"No tienes nada con lo que encender la l�mpara.\n",
"Acercas @@Lighter@@ a la mecha de la l�mpara, pero por m�s que intentas producir "
"una chispa para encenderla, no lo consigues.\n",
"@@Pl_Name@@ acerca @@Lighter@@ a la mecha de su l�mpara, pero por m�s que intenta producir "
"una chispa para encenderla, no lo consigue.\n"

           }));
}

void init () {
  lamp::init();
}

int move(mixed dest, int method, mixed xtra) {
  if (QueryBurning()) SetBurning(0);
  return lamp::move(dest, method, xtra);
}

mixed QueryNoBuy() { return QueryBurning(); }

/*----------------------------------------------------------------------------
** Description, Smell, Noise
*/

string QueryShort() {
  string rc, sh;

  rc = "";
  if (!QueryStarted()) {
    SetStarted(1);
    if (QueryFuel()) {
      rc = " gastada ";
    }
  }
  return ::QueryShort()+rc;
}

string Short() {
  string sh;

  sh = ::Short();
  if (QueryBurning()) sh = strip_article(sh)+" encendida";
  return sh;
}

string QueryLong() {
  if (QueryBurning()) return "Una l�mpara encendida.\n";
  else return "Una l�mpara apagada.\n";
}

string Long(string what) {
  string rc;
  int fuel, maxfuel;

  fuel = QueryFuel();
  maxfuel = QueryFuelMax();
  rc = ::Long();
  if (!TP || !TP->QueryCmdData(SUBID))
  {
  if (fuel == maxfuel) rc += "Est� practicamente nueva.\n";
  else if (fuel * 4 > maxfuel * 3) rc += "Apenas est� gastada.\n";
  else if (fuel * 2 > maxfuel) rc += "Aproximadamente queda la mitad.\n";
  else if (fuel * 4 > maxfuel) rc += "S�lo queda un poco de aceite.\n";
  else if (fuel) rc += "Se acabar� en cualquier momento.\n";
  else rc += "Esta completamente vacia.\n";
  }
  return rc;
}

int SetFuel (int v) {
  int rc, old;
  old = QueryFuel();
  rc = ::SetFuel(v);
  if (rc <= 0 && old > 0) AddId(({"vacia","l�mpara vac�a","l�mpara vacia","lampara vac�a","lampara vacia"}));
  else if (rc > 0 && old < 0) RemoveId(({"vacia","l�mpara vac�a","l�mpara vacia","lampara vac�a","lampara vacia"}));
  return rc;
}

string QuerySmell() {
  int fuel, maxfuel;

  fuel = QueryFuel();
  maxfuel = QueryFuelMax();
  if (QueryBurning()) return "Hueles a aceite quemado.\n";
  if (fuel == maxfuel) return "Hueles aceite.\n";
  if (!fuel) return "Huele a aceite requemado.\n";
  return "Hueles a aceite medio quemado.\n";
}

string QueryNoise() {
  if (QueryBurning()) return "Escuchas el d�bil crepitar del fuego.\n";
  return "No escuchas nada.\n";
}

BurnUp() {
  string msg, msge;
  object env, pl;

  if (::BurnUp()) {
    switch(random(8)) {
      case 0: msg  = "Tu l�mpara parpadea.\n";
              msge = "La l�mpara de "+Pl_Name()+" parpadea.\n";
              break;
      case 1: msg = "Muere un insecto atraido por la llama de tu l�mpara.\n";
              msge = "Muere un insecto atraido por la llama de la l�mpara de "+Pl_Name()+".\n";
              break;
      case 2: msg = "Una rafaga de viento empuja la llama en tu direcci�n y casi quema tu piel.\n";
              msge = msg;
              break;
      default: return;
    }
    pl = 0;
    if ((env=environment(THIS)) && interactive(env)) {
      pl = env;
      tell_object (pl, msg);
      env = environment(pl);
    }
    if (env) tell_room (env, msge, ({ pl }));
  }
}

