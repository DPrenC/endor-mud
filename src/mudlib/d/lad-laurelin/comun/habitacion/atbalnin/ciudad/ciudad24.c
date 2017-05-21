#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Lejos, hacia el este, ves lo que parece una plaza y donde, "
  	"si la vista no te engaña, se alza lo que parece una biblioteca. A "
  	"veces se encuentran cosas interesantes entre las paredes de esos "
  	"edificios, aunque eso es sólo un rumor sin confirmar, ningún "
  	"aventurero que se precie debe ser cogido in fraganti en uno de esos "
  	"criaderos de polillas.\n"));
  SetIntShort("la zona central de Atbalnin");
  AddDetail("biblioteca", W("Es una biblioteca. Desde aquí no llegas a verlo, "
  	"pero probablemente contendrá algún libro.\n"));
  AddDetail("plaza", "Es una plaza.\n");
  AddExit("sur", ATB_CI("ciudad25"));
  AddExit("oeste", ATB_CI("ciudad23"));
  AddExit("este", ATB_CI("ciudad26"));
}
