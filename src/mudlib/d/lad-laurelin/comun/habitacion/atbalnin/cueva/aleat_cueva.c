#include "path.h"
inherit LAD_ROOM;

create(){
  string desc;

  ::create();
  switch (random(4)) {
    case 0: desc="Estás en una cueva oscura y tenebrosa. Las paredes parecen "
    	"haber sido talladas por el agua. Seguramente esto fué un río "
    	"subterráneo.\n";
    	break;
    case 1: desc="Estás en una cueva bastante grande. Mide más o menos tres "
    	"metros de altura y otros tres de anchura.\n";
    	break;
    case 2: desc="Oyes inquietantes sonidos de animales reptando por la "
    	"cueva. Desde luego no está deshabitada.\n";
    	break;
    default: desc="Ves algún que otro charco. Seguramente formado por las "
    	"gotas que caen del techo y de sus estalacmitas. Seguramente habrá "
    	"algún afluente acuífero en algún lugar inmediatamente superior a "
    	"éste.\n";
  }

  SetIntLong(W(desc));
  SetIntShort("una cueva tenebrosa");
  SetIntNoise("Escuchas un apagado e incesante sonido de goteo.\n");
  SetIntSmell("Huele a moho y a humedad.\n");

  if (!random(2))
    AddItem(PNJ("atbalnin/bosque/lobo"), REFRESH_REMOVE, 1+random(2));

  SetLocate("la cueva de Atbalnin");
  SetIndoors(1);
  SetIntBright(5);
}

