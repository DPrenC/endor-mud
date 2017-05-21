#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Justo en el extremo nordeste de la plaza central de Atbalnin "
  	"se alza la biblioteca central. Lo sabes porque estás frente a ella. "
  	"Aqui se guardan libros escritos por todo tipo de personas, desde "
  	"recetas de cocina hasta aburridos volúmenes que hablan de "
  	"jurisprudencia, pasando por libros de aventuras, censos...\n"));
  SetPreIntShort("frente a");
  SetIntShort("la biblioteca");
  AddDetail("biblioteca", "Es la biblioteca de Atbalnin.\n");

  AddExit("oeste", ATB_CI("ciudad25"));
  AddExit("norte", ATB_CI("ciudad26"));
  AddExit("sur", ATB_CI("ciudad35"));
  AddExit("entrar", ATB_BI("biblio00"));
  AddExit("suroeste",ATB_CI("ciudad34"));
}
