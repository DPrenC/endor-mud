#include "path.h"
inherit ATB_B("bosque_sur");

QueryIntLong()
{
  return ::QueryIntLong()+"Ante ti ves el Gremio de Guardabosques.\n";
}
create(){
  ::create();
  SetPathToCity("norte");

  AddDetail("gremio", "Es una construcci�n s�lida en medio de este bosque.\n");
  AddExit("norte", ATB_B("bosque01"));
  AddExit("entrar", "/guilds/guardabosques/gremio");
}
