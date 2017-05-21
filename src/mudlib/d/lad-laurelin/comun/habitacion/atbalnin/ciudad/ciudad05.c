#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Est�s frente a la Segunda Entrada Sur. Empiezas a formar una "
  	"imagen mental de por qu� una fortaleza no debe tener tantos accesos, "
  	"a no ser que desees fervientemente que sea asaltada y tomada con "
  	"apenas un pu�ado de hombres. Pensando m�s detenidamente llegas a la "
  	"conclusi�n que quien la dise�� fu� un aut�ntico g�nio estratega. "
  	"Quiz�s sea f�cil perder el control de la fortaleza, pero es "
  	"extremadamente f�cil volver a recuperarlo. Sea como sea, la entrada "
  	"ahora est� cerrada a cal y canto.\n"));
  AddDetail(({"entrada", "port�n", "portones"}), "Ves una entrada cerrada. Nada podr�a abrirla.\n");
  AddExit("norte", ATB_CI("ciudad11"));
  AddExit("oeste", ATB_CI("ciudad04"));
}

