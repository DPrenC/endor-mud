#include "./path.h"
inherit GBOSQUE;

create()
{
  ::create();

  AddFlor();
  AddItem("/guilds/conjuradores/pergamino/pergamino_espada_sagrada",REFRESH_REMOVE);

  AddExit("norte","bosque18");
  AddExit("sur","bosque21");
  SetLocate("bosque djorn");
}
