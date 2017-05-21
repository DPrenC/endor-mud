#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Estás frente a la Segunda Entrada Sur. Empiezas a formar una "
  	"imagen mental de por qué una fortaleza no debe tener tantos accesos, "
  	"a no ser que desees fervientemente que sea asaltada y tomada con "
  	"apenas un puñado de hombres. Pensando más detenidamente llegas a la "
  	"conclusión que quien la diseñó fué un auténtico génio estratega. "
  	"Quizás sea fácil perder el control de la fortaleza, pero es "
  	"extremadamente fácil volver a recuperarlo. Sea como sea, la entrada "
  	"ahora está cerrada a cal y canto.\n"));
  AddDetail(({"entrada", "portón", "portones"}), "Ves una entrada cerrada. Nada podría abrirla.\n");
  AddExit("norte", ATB_CI("ciudad11"));
  AddExit("oeste", ATB_CI("ciudad04"));
}

