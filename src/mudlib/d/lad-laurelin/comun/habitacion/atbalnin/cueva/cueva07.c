#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("La pared que va hacia el sudeste tiene unas curiosas "
	"grabaciones runicas. Quizas sea tan solo el nombre del lago, o quizas "
	"no lo sea. Sea como fuere, el lago esta hacia el este de aqui y sigue "
	"en todas direcciones.\n"));
  SetIntShort("el lago de la cueva de Atbalnin");
  AddDetail("suelo", "Es frio, liso y humedo.\n");
  AddDetail(({"paredes", "pared"}), W("La pared sudeste tiene unas "
	"runas grabadas en la piedra.\n"));
  AddDetail("lago", "Es un inmenso y oscuro lago.\n");
  if (TP->QueryRace()=="elfo" || TP->QueryRace()=="medio-elfo" ||
	TP->QueryRace()=="elfo-oscuro")
    AddDetail(({"inscripcion", "runas"}), "Consigues leer lo que podria ser el "
	"nombre del lago, <Selegond Taur>.\n");
  else
    AddDetail(({"inscripcion", "runas"}), "Estan en un lenguaje que, aunque "
	"familiar, no consigues descifrar.\n");
  AddExit("norte", ATB_C("cueva05"));
  AddExit("nordeste", ATB_C("cueva08"));
  AddExit("este", ATB_C("cueva11"));
  AddExit("sudeste", ATB_C("cueva12"));
  AddExit("noroeste", ATB_C("cueva04"));
}
