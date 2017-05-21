/* ENDOR-MUD'/obj/otros/hoguera.c'
   copiado del archivo de las l�mparas.
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
  AddId (({"hoguera"}));
  SetShort("una hoguera");
  SetWeights (2000, 4000);          /* Base weighs 200 gr, one unit 40 gr */
  Set(P_GENDER, GENDER_FEMALE);
SetNoGet(1);
  SetValues (500, 50);              /* Base is worth 1, one unit 1 */
  SetFuelAmount (30+random(10));  /* 15..20 units a 5 minutes */
  SetRechargeable(1);
  SetBrightness (REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetLampMsg ( ({
 "La hoguera ya esta encendida.\n"
,"La hoguera no esta encendida.\n"
,"La hoguera est� totalmente consumida. No puede volver a encenderse si no le a�ades le�a.\n"
,"Utilizas @@Lighter@@ para prender fuego a la hoguera. Tras  producir unas peque�as chispas consigues encenderla.\n"
,"@@Pl_Name@@ utiliza @@Lighter@@ para encender la hoguera, lo cual consigue eficazmente.\n"
,"Esparces las brasas y le�a estinguiendo el fuego de la hoguera.\n"
,"@@Pl_Name@@ esparce las brasas de la hoguera estinguiendo el fuego por completo.\n"
,"El fuego de la hoguera llega a su fin consumi�ndose.\n"
,"El fuego de la hoguera llega a su fin consumi�ndose.\n" //,"La l�mpara de @@Pl_Name@@ parpadea y se apaga.\n",
,"No tienes nada con qu� prender fuego a la hoguera.\n",
"Intentas encender la hoguera con @@Lighter@@ pero fallas vergonzosamente.\n",
"@@Pl_Name@@ intenta encender la hoguera usando @@Lighter@@, pero no es capaz de hacerlo.\n"

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
      rc = " consumida ";
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
  if (QueryBurning()) return "Una hoguera con un buen fuego encendido.\n";
  else return "Una hoguera apagada.\n";
}

string Long(string what) {
  string rc;
  int fuel, maxfuel;

  fuel = QueryFuel();
  maxfuel = QueryFuelMax();
  rc = ::Long();
  if (!TP || !TP->QueryCmdData(SUBID))
  {
  if (fuel == maxfuel) rc += "Contiene abundancia de le�a.\n";
  else if (fuel * 4 > maxfuel * 3) rc += "Contiene bastante le�a.\n";
  else if (fuel * 2 > maxfuel) rc += "Hay le�a suficiente para alimentar el fuego un buen rato.\n";
  else if (fuel * 4 > maxfuel) rc += "Apenas tiene un poco de le�a.\n";
  else if (fuel) rc += "Su fuego ser� breve, necesita m�s le�a.\n";
  else rc += "Con la escasa le�a que tiene no es suficiente para encenderla.\n";
  }
  return rc;
}

int SetFuel (int v) {
  int rc, old;
  old = QueryFuel();
  rc = ::SetFuel(v);
  if (rc <= 0 && old > 0) AddId(({"vacia","vac�a","hoguera vac�a","hoguera vacia"}));
  else if (rc > 0 && old < 0) RemoveId(({"vacia","vac�a","hoguera vac�a","hoguera vacia"}));
  return rc;
}

string QuerySmell() {
  int fuel, maxfuel;

  fuel = QueryFuel();
  maxfuel = QueryFuelMax();
  if (QueryBurning()) return "Hueles a le�a quem�ndose.\n";
  if (fuel == maxfuel) return "Hueles a le�a prendi�ndose.\n";
  if (!fuel) return "Huele a le�a hcamuscada.\n";
  return "Hueles al t�pico olor de hoguera.\n";
}

string QueryNoise() {
  if (QueryBurning()) return "Escuchas el d�bil crepitar del fuego.\n";
  return "No escuchas nada.\n";
}

BurnUp() {
  string msg, msge;
  object env, pl;

  if (::BurnUp()) {
    switch(random(6)) {
      case 0: msg  = "El fuego de la hoguera hace formas siniestras.\n";
              msge = "El fuego de la hoguera hace formas siniestras.\n"; //"La l�mpara de "+Pl_Name()+" parpadea.\n";
              break;
      case 1: msg = "Unos mosquitos son absorbidos por las llamas de la hoguera.\n";
              msge = "Unos mosquitos son absorbidos por las llamas de la hoguera.\n"; //"Muere un insecto atraido por la llama de la l�mpara de "+Pl_Name()+".\n";
              break;
      case 2: msg = "Las llamas reviven espont�neamente ascendiendo unos palmos, pero enseguida vuelve a su estado normal.\n";
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

