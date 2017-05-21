/*          cemen3e.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 12-11-00
            Modificado por :
	    [Nemesis] Modificada la funcion hacer_sentar() para que el banco
                      solo se rompa si eres muy pesado. Si el banco no se
                      rompe, te curara un poco. Si te caes, te haras danyo.
                      Cambios en la descripcion y en los AddDetails.
                      Anyadida la salida a la guarida del ghoul.
		      [n] Ahora el banco cambia de descripción dependiendo
		      de si está roto o no.
	    [Jessy]   Castellanización del fichero y cambio de ermita a templo...
*/
#include <properties.h>
#include <health.h>
#include "./path.h"

inherit SIM_ROOM;
private int intacto;

hacer_sentar(string str)
{ if (!str) write ("¿Dónde te quieres sentar?\n");
  else {
  if (str!="en banco"&&str!="banco") write ("¿Dónde te quieres sentar?\n");
  else
  {
  if (!intacto) write("El banco está roto.\n");
  else
  {
   write("Te sientas en el banco y ....\n");
   if (TP->QueryWeight()>90000) {
    tell_room(MARH("nandor/cementerio/cemen3e"),"CRASSSHHH...!! "+TP->QueryName()+" ha roto el banco.\n");
    TP->heal(-random(TP->QueryCon()));
    intacto=0;
   }
   else{
    write("El banco parece resistir tu peso. Te sientas en él y descansas. Al cabo de "
	  "unos instantes, te sientes más fuerte y te levantas, dispuesto a todo.\n");
    TP->heal(random(TP->QueryCon())+random(TP->QueryStr())+5);
   }
  }
 }
}
 return 1;
}

mirar_banco() {
  string str;
  if (!TP) return 0;
  if (intacto) str =
   "Es un banco de madera. Está bastante deteriorado, y quizá no resista tu "
   "peso si te sientas en él. Por otro lado, con todo el tiempo que debe llevar "
   "aquí, no se irá a romper ahora... ¿O sí?\n";
  else str =
   "Es un banco de madera. Por desgracia, parece que no ha escapado a la "
   "destrucción generalizada que reina en el lugar y yace partido en dos "
   "en el suelo.\n";
  return str;
}

init() {
  ::init();
  intacto = 1;
  add_action("hacer_sentar","sentar");
}
create() {
::create();
SetLocate("Cementerio de Nandor");
SetIntShort("el camino interior del Cementerio de Nandor");
SetIntLong(
	   "Estás en un lugar donde hay un banco para que la gente pueda sentarse y "
	   "descansar mientras visita a sus seres más queridos. Entre las tumbas "
	   "abiertas hay una muy particular. "
	   "Hacia el oeste ves la capilla, al norte ves tumbas y al sur sólo ves "
	   "más lápidas.\n");
SetIndoors(0);
AddDetail("banco",SF(mirar_banco));
AddDetail("capilla", "No está en muy bien estado que digamos.\n");
AddDetail("tumbas",
	  "La mayoría han sido profanadas. Algo raro pasa en este cementerio.\n");
AddDetail(({"tumba","tumba particular"}),
	    "En la tierra fresca de alrededor hay huellas recientes.\n");
AddDetail(({"huellas","huellas recientes"}),
"Son las huellas de unos pies descalzos. Parece como si se internaran "
"en la tumba... Alguien vive ahí abajo, sin duda.\n");
AddExit("sur","cemen2e");
AddExit("norte","cemen4e");
AddExit("oeste","cemen3");
AddExit("abajo","goulslair");
HideExit("abajo",1);
}

reset(){
intacto=1;
::reset();
}