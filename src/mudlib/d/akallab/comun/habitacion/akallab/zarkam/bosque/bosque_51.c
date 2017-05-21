/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("un camino entre las montañas");
  SetIntLong(
  "Estas en la ladera de una de las montanyas de la cordillera de Kova. Esta "
  "cordillera es por general una region bastante inaccesible, pero al alzar la "
  "vista descubres que por encima de unas rocas, las cuales no presentan ninguna "
  "dificultad a la hora de escalarlas, discurre un angosto camino entre las "
  "montanyas. "
  "El extenso bosque que se extiende al sur de aqui, te hace imposible avanzar "
  "en esa direccion.\n");
  AddDetail(({"bosque","arboles","arbol"}),
  "Justo al sur se extiende un espeso bosque, sus arboles y densa vegetacion te "
  "impiden acceder a su interior desde esta zona.\n");
  AddDetail(({"montanya","montanyas","cordillera","Kova"}),
  "La cordillera de Kova se alza majestuosa y desafiante frente a tus ojos. Puedes "
  "ver un angosto camino que avanza entre las montanyas pero que solo es accesible "
  "subiendo por unas pequenyas rocas.\n");
  AddDetail(({"rocas","piedras"}),
  "Unas cuantas rocas son lo unico que separan este lugar del camino que circula "
  "entre las montanyas.\n");
  AddDetail(({"camino"}),
  "Por encima de unas rocas ves un camino que permite el acceso a la cordillera "
  "de Kova. Parece ser muy empinado.\n");
  AddExit("oeste",Z_BOSQUE("bosque_50"));
  AddExit("nordeste",Z_BOSQUE("bosque_59"));
  AddExit("arriba",Z_BOSQUE("montain_e"));
  AddItem(PNJ("animal/urraca"),REFRESH_DESTRUCT);
  SetIndoors(0);
  SetIntSmell("El aire proviniente de las montanyas es algo frio.\n");
  SetIntNoise("Escuchar un fuerte ruido de viento que llega desde la cordillera.\n");
  SetLocate("bosque de Zarkam");
}
