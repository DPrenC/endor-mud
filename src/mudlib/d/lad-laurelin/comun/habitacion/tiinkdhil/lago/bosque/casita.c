
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;
create(){
  ::create();
  SetIndoors(1);
  SetIntBright(40);
  SetLocate("bosqueDehim");
  SetIntSmell("Mucho polvo se cuela en tus orificios nasales y estornudas vívamente.\n");
  SetIntNoise("La casa cruje, pero a parte de eso no oyes nada mas.\n");
  SetIntShort("una casa en ruinas");
  SetIntLong("Estás en una casa en ruinas. La madera que la forma está bastante sucia y po"
		"drida y los ventanales están tan tapados que apenas dejan pasar algo de luz."
		" Hay sillas rotas y restos de objetos a tu alrededor y tus pies se posan en "
		"una alfombra deshilachada.\n");

  AddExit("norte",ALULAGO("bosque/tienda")); 	//la de la tienda
  AddExit("oeste",ALULAGO("bosque/bosque10")); 	//entrada principal, puede ser una puerta
}