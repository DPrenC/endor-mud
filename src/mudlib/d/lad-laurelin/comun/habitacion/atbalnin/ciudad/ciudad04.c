#include "path.h"
inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Te vienen a la mente un montón de razones por las que una "
  	"salida, entrada o acceso al frondoso bosque de Atbalnin puede estar "
  	"cerrada. La realidad, como siempre, superará a la ficción, así que "
  	"asumes que esos desvencijados portones no se volverán a abrir a no ser "
  	"que alguien extremadamente hábil (y con tratos preferenciales con "
  	"determinadas deidades) venga y las arregle.\n"));
  AddDetail(({"portón", "porton", "portones"}), W("Ves unos portones que han "
  	"conocido una época mejor y más gloriosa. Ni el mismísimo Asthar, "
  	"maestro en generación de bostezos, podría abrirlas.\n"));
  AddExit("norte", ATB_CI("ciudad10"));
  AddExit("este", ATB_CI("ciudad05"));
}

