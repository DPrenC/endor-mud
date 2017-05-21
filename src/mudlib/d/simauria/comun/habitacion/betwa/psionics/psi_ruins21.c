/* psi_ruins21.c
   Antiguo Observatorio Astron�mico
   Creaci�n: [n] Nemesis, 19-Abr-2001 18:17:57 CEST
   Notas: Aqu� habr� al menos una piedra de memoria
*/

#include "./path.h"
#include <moving.h>


inherit SIM_ROOM;

private int map, stone;


int buscar(string arg) {
object ob;
 if (arg == "en los pergaminos" || arg == "entre los pergaminos") {
  write("Buscas entre los pergaminos algo interesante...\n");
  if ( (TP->UseSkill("rastrear")>0) && (map == 1) )
  {
   write("... y encuentras un viejo mapa del cielo.\n");
   ob = clone_object(OTRO("starmap"));
   map = 0;
   ob->move(TI,M_SILENT);
  }
  else {
   write("...pero no parece haber nada �til.\n"+map);
   if (random(250)) {
    ob = clone_object(OTRO("polvo"));
    ob->move(TI,M_SILENT);
   }
  }
 }
 else write("�D�nde quieres buscar?\n");
 return 1;
}

int tele(string arg) {
object ob,room;
 room = find_object("/d/simauria/comun/habitacion/betwa/psionics/camino07");
 if (arg == "las estrellas" || arg == "estrellas") {
  if (stone) {
   write("Miras por el telescopio, pero no ves nada.\n");
   write("Sin embargo, al dejar el telescopio, algo cae al suelo.\n");
//   ob = clone_object(OTRO("piedra_XXX"));
//   ob->move(TO,M_SILENT);
   stone = 0;
  }
  else {
   if (!find_object("/d/simauria/comun/habitacion/betwa/psionics/camino07"))
    write("Miras por el telescopio, pero no ves nada.\n");
   else
    write(W("Miras por el telescopio y ves:\n"+room->QueryIntLong()+
	   "["+room->Exits(1,TP)+"]\n"+room->Content())
	 );
  }
  return 1;
 }
 else return 0;
}


reset() {
::reset();
map = 1;
stone = 1;
}


create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("el observatorio astron�mico");
SetIntLong(
"Te encuentras en una enorme sala circular con techo abovedado.\
 Est�s rodeado de viejos instrumentos astron�micos apenas reconocibles. Es\
 muy posible que los psi�nicos utilizaran este lugar para estudiar las\
 estrellas y para sentirse en contacto con el Cosmos. Sin embargo, ahora no\
 es m�s que una estancia llena de polvo y trastos viejos.\n\
La �nica salida son unas escaleras que conducen al piso de abajo.\n");
SetIndoors(1);
SetIntBright(25);

AddDetail(({"escalera"}),
"Una polvorienta escalera de madera da acceso al piso inferior.\n");
AddDetail(({"instrumentos","instrumentos astron�micos","instrumentos astronomicos"}),
"Varios viejos aparatos de medida est�n tirados por el suelo. Probablemente "
"ayudaban a los astr�nomos a escudri�ar el cielo. Sin embargo ahora son poco. "
"m�s que chatarra. Tambi�n hay algunos viejos pergaminos tirados aqu� y all� y "
"un extra�o aparato en el centro de la sala.\n");
AddDetail(({"pergaminos","viejos pergaminos"}),
"Probablemente son viejas cartas astron�micas. A lo mejor puedes encontrar "
"algo interesante entre ellos.\n");
AddDetail(({"aparato","extra�o aparato","extranyo aparato","telescopio"}),
"Parece un telescopio. Tal vez puedas observar las estrellas con �l.\n");
AddDetail(({"aparatos","aparatos de medida"}),
"Parecen aparatos para medir �ngulos... Por otro lado, est�n tan oxidados que "
"ya poco importa.\n");

AddRoomCmd("buscar",SF(buscar));
AddRoomCmd("observar",SF(tele));

AddExit("abajo","./psi_ruins13");

}