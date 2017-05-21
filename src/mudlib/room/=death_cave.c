inherit "/std/room";


#include <rooms.h>;
#include <properties.h>;
#include <moving.h>;
int i;
object quien, hab;

Genero(string ao) {
if (TP->QueryGender() == 1 ) return "o";
if (TP->QueryGender() == 0 ) return "a";
if (  (TP->QueryGender()) != 1 && (TP->QueryGender()) != 0) return "o";
}


Articulo(string str) {
if ( (TP->QueryGender()) == 1 ) return "un";
if ( (TP->QueryGender()) == 0 ) return "una";
if ( (TP->QueryGender()) != 1 &&
     (TP->QueryGender()) != 0) return "un";
}

Raza(string raza) {
if ( (TP->QueryRace()) == "demonio") {
   if ( (TP->QueryGender()) == 1) return "demonio";
   if ( (TP->QueryGender()) == 0) return "demonio";
   if ( (TP->QueryGender() == 1) && (TP->QueryGender() == 0)) return "demonio";
}
if ( (TP->QueryRace()) == "draconiano") {
   if ( (TP->QueryGender()) == 1) return "draconiano";
   if ( (TP->QueryGender()) == 0) return "draconiana";
   if ( (TP->QueryGender() == 1) &&
         (TP->QueryGender() == 0)) return "draconiano";
}
if ( (TP->QueryRace()) == "duende") {
   if ( (TP->QueryGender()) == 1) return "duende";
   if ( (TP->QueryGender()) == 0) return "duende";
   if ( (TP->QueryGender() == 1) && (TP->QueryGender() == 0)) return "duende";
}
if ( (TP->QueryRace()) == "elfo") {
   if ( (TP->QueryGender()) == 1) return "elfo";
   if ( (TP->QueryGender()) == 0) return "elfa";
   if ( (TP->QueryGender() == 1) && (TP->QueryGender() == 0)) return "elfo";
}
if ( (TP->QueryRace()) == "elfo-oscuro") {
   if ( (TP->QueryGender()) == 1) return "elfo-oscuro";
   if ( (TP->QueryGender()) == 0) return "elfa-oscura";
   if ( (TP->QueryGender() == 1)
      && (TP->QueryGender() == 0)) return "elfo-oscuro";
}
if ( (TP->QueryRace()) == "enano") {
   if ( (TP->QueryGender()) == 1)
     return "enano";
   if ( (TP->QueryGender()) == 0)
     return "enana";
   if ( (TP->QueryGender() == 1) && (TP->QueryGender() == 0))
     return "enano";
}
if ( (TP->QueryRace()) == "gigante") {
   if ( (TP->QueryGender()) == 1) return "gigante";
   if ( (TP->QueryGender()) == 0) return "gigante";
   if ( (TP->QueryGender()) == 1
      && (TP->QueryGender()) == 0) return "gigante";
}
if ( (TP->QueryRace()) == "gnomo") {
   if ( (TP->QueryGender()) == 1) return "gnomo";
   if ( (TP->QueryGender()) == 0) return "gnoma";
   if ( (TP->QueryGender()) == 1 && (TP->QueryGender()) == 0) return "gnomo";
}
if ( (TP->QueryRace()) == "humano") {
   if ( (TP->QueryGender()) == 1) return "humano";
   if ( (TP->QueryGender()) == 0) return "humana";
   if ( (TP->QueryGender()) == 1
      && (TP->QueryGender()) == 0) return "humano";
}
if ( (TP->QueryRace()) == "kainoak") {
   if ( (TP->QueryGender()) == 1) return "kainoak";
   if ( (TP->QueryGender()) == 0) return "kainoak";
   if ( (TP->QueryGender()) == 1
      && (TP->QueryGender()) == 0) return "kainoak";
}
if ( (TP->QueryRace()) == "kender") {
   if ( (TP->QueryGender()) == 1) return "kender";
   if ( (TP->QueryGender()) == 0) return "kender";
   if ( (TP->QueryGender()) == 1 && (TP->QueryGender()) == 0) return "kender";
}
if ( (TP->QueryRace()) == "logath") {
   if ( (TP->QueryGender()) == 1) return "logath";
   if ( (TP->QueryGender()) == 0) return "logath";
   if ( (TP->QueryGender()) == 1
      && (TP->QueryGender()) == 0) return "logath";
}
if ( (TP->QueryRace()) == "medio-elfo") {
   if ( (TP->QueryGender()) == 1) return "medio-elfo";
   if ( (TP->QueryGender()) == 0) return "medio-elfa";
   if ( (TP->QueryGender()) == 1
      && (TP->QueryGender()) == 0) return "medio-elfo";
}
if ( (TP->QueryRace()) == "orco") {
   if ( (TP->QueryGender()) == 1) return "orco";
   if ( (TP->QueryGender()) == 0) return "orco";
   if ( (TP->QueryGender()) == 1 && (TP->QueryGender()) == 0) return "orco";
}
if ( (TP->QueryRace()) == "troll") {
   if ( (TP->QueryGender()) == 1) return "troll";
   if ( (TP->QueryGender()) == 0) return "troll";
   if ( (TP->QueryGender()) == 1 && (TP->QueryGender()) == 0) return "troll";
}

if (TP->QueryRace() == "") return (TP->QueryRace());
}

create() {
 ::create();
 SetIntShort("En una cueva humeda");
 SetIntLong(
 "Estas en una cueva humeda, donde vive el espiritu de la reencarnacion.\n");
 SetIndoors(1);
 SetIntBright(0);
}

init() {
  ::init();
  call_out("Muerte",5);
}

Muerte() {
  int muerto;
  write(
"Te encuentras en una cueva humeda. Ves un espiritu ante ti.\n");
  muerto = TP->QueryAttribute("muerto");
  switch (muerto) {
     case 0: write(
"El espiritu de la cueva dice: Oh, parece ser que te has encontrado con la\n"
"muerte. Podria echarte una mano, pero nunca habia hecho esto antes.\n"
"Quieres que intente reencarnarte? De acuerdo! Pero no te quejes si algo va\n"
"mal...\n"
"  --- puf!! ---\n"
"El espiritu enciende una extranya vela y de repente te ves envuelto en una\n"
"extranya nube naranja. Tosiendo y estornudando, logras salir de entre el\n"
"espeso humo ...\n"); break;
     case 1: write(
"El espiritu de la cueva dice: Tsk,tsk - lo has hecho de nuevo! - Recuerda,\n"
"tu eres solo "+Articulo()+" "+Raza()+" y no tienes tantas vidas como un gato\n"
"(o al menos, eso creo...)!\n"
"Ya has vuelto una vez de la muerte - quieres intentar la segunda?\n"
"Como quieras! Espera un segundo mientras preparo la vela ...\n"
" --- fuf! ---\n"
"Una inmensa nube naranja llena el aire. Al desaparecer, te encuentras de\n"
"nuevo contigo mismo ...\n"); break;
     case 2: write(
"El espiritu de la cueva dice: Vaya, de nuevo por aqui! No se cuantas\n"
"veces podre hacer esto. Quieres que intente reencarnarte de nuevo?\n"
"Vale, mmmm, donde habre puesto ahora mi nube naranja? ...'\n"
"  > puf! <\n"
"El espiritu enciende una vela.\n"
"Todo desparece en una densa nube de humo naranja ...\n"); break;
    default: write(
"The cave-sprite says: Vaya, creo que la has armado! No me quedan mas nubes\n"
"naranjas!\n"
"No esperaras que haga una reencarnacion decente sin nubes, no? Si ... bien,\n"
"esa es la clase de ignorancia porcina que espero de vosotros los mortales.\n"
"Si fuerais listos os reencarnariais vosotros mismos, y yo no soy tan loco\n"
"como para terminar en el infierno por ustedes, ya no hare esto jamas!\n"
"ME LARGO DE AQUI!!!!\n"
"El espiritu de la cueva, enfadado, tira una vela y desaparece. Durante\n"
"un momento te quedas sin saber que hacer. Entonces coges la vale y la\n"
"enciendes por ti mism"+Genero()+".\n"
"No suena ningun >puf!< ni ningun >fuf!< y la nube de humo naranja no aparece,\n"
"te encuentras en un lugar que te suena familiar ...\n");
   }
   TP->SetAttribute("muerto", muerto+1);
   TP->SetHP(5);
   call_out("back",5);
   return 1;
}

back() {
  quien->move(hab, M_GO);
}

died(pl) {
  tell_object(pl,"Has muerto!\n");
  hab=environment(pl);
  quien=pl;
  pl->reduce_hit_point(200,0);
  pl->move(TO, M_TELEPORT);
}
