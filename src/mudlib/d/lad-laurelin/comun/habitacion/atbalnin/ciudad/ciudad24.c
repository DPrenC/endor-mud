#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Lejos, hacia el este, ves lo que parece una plaza y donde, "
  	"si la vista no te enga�a, se alza lo que parece una biblioteca. A "
  	"veces se encuentran cosas interesantes entre las paredes de esos "
  	"edificios, aunque eso es s�lo un rumor sin confirmar, ning�n "
  	"aventurero que se precie debe ser cogido in fraganti en uno de esos "
  	"criaderos de polillas.\n"));
  SetIntShort("la zona central de Atbalnin");
  AddDetail("biblioteca", W("Es una biblioteca. Desde aqu� no llegas a verlo, "
  	"pero probablemente contendr� alg�n libro.\n"));
  AddDetail("plaza", "Es una plaza.\n");
  AddExit("sur", ATB_CI("ciudad25"));
  AddExit("oeste", ATB_CI("ciudad23"));
  AddExit("este", ATB_CI("ciudad26"));
}
