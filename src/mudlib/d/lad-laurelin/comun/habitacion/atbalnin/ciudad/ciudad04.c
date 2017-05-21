#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Te vienen a la mente un mont�n de razones por las que una "
  	"salida, entrada o acceso al frondoso bosque de Atbalnin puede estar "
  	"cerrada. La realidad, como siempre, superar� a la ficci�n, as� que "
  	"asumes que esos desvencijados portones no se volver�n a abrir a no ser "
  	"que alguien extremadamente h�bil (y con tratos preferenciales con "
  	"determinadas deidades) venga y las arregle.\n"));
  AddDetail(({"port�n", "porton", "portones"}), W("Ves unos portones que han "
  	"conocido una �poca mejor y m�s gloriosa. Ni el mism�simo Asthar, "
  	"maestro en generaci�n de bostezos, podr�a abrirlas.\n"));
  AddExit("norte", ATB_CI("ciudad10"));
  AddExit("este", ATB_CI("ciudad05"));
}

