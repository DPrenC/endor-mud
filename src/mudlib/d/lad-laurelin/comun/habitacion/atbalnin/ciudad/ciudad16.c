#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Si miras hacia abajo ver�s una bonita cantidad de rampa que "
  	"se enrosca en espiral al arbol que la sujeta. Sorprendentemente la "
  	"caba�a que hay ante t� parece ser una especie de restaurante local. "
  	"Intentas pensar en cu�nta gente se aventurar� a subir por una rampa "
  	"endiabladamente empinada y larga, y que adem�s carece de barandilla, "
  	"para sencillamente llenar el buche.\n"));
  AddDetail("rampa", "Es una rampa en espiral. Larga. Retorcida.\n");
  AddDetail("restaurante", W("Parece ser el t�pico sitio donde pagas y te dan "
  	"algo que llevarte al est�mago, sin ser un gremio de asesinos.\n"));
  AddExit("entrar", ATB_CI("restaurante01"));
  AddExit("oeste", ATB_CI("ciudad02"));
}

