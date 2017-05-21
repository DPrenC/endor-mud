/*=============================================================*
 |          << GOLDHAI.glucksfall [w] Woo@simauria >>          |
 *=============================================================*
 |             Creacion.................. 24-02-00             |
 |             Ultima Modificacion....... 24-02-00             |
 |                                                             |
 *=============================================================*/

#include "../sys/goldhai.h"
inherit GROOM;

create() {
 ::create();

   SetIntShort("un pasillo interior de la muralla");
 switch(random(3))
 {
  case 0:
   SetLongWrap(
     "Estás caminando por el pasillo interior que recorre toda la muralla de "
     "la ciudad. Está iluminado por unas antorchas por lo que pasas con cierto "
     "cuidado para no quemarte. "
     "Solo tienes dos opciones, o continuar hacia adelante o volver "
     "por donde has venido.");
  break;
  case 1:
   SetLongWrap(
     "Esto es bastante claustrofóbico, apenas si puedes moverte y la luz es "
     "muy ténue. Este es el pasillo interior que recorre toda la muralla bordeando "
     "Glucksfall.");
  break;
  case 2:
   SetLongWrap(
     "Continuas andando por el pasillo interior de la muralla. La luz entra por una "
     "ventana pequeña aunque es tan pequeña que han recurrido a unas antorchas para "
     "iluminar el pasillo.");
  break;
  default:
   SetLongWrap(
     "Estás caminando por el pasillo interior que recorre toda la muralla de "
     "la ciudad. Solo tienes dos opciones, o continuar hacia adelante o volver "
     "por donde has venido.");
 }

 AddDetail(({"ventana","ventanuco","luz"}),
"Ves pequeña ventana por la que entra la luz pero está demasiado alta para\n\
que puedas ver el exterior.\n");
 AddDetail(({"antorcha","antorchas"}),
"Cada cierto tiempo cuelga de la pared una antorcha que siempre está encendida\n\
para que ilumine el pasillo tanto de día como de noche.\n");

 switch(random(10))
 {
  case 0:
   AddItem(PNJ("glucksfall/gigante"),REFRESH_DESTRUCT);
  break;
  case 2:
   AddItem(PNJ("glucksfall/elfo-oscuro"),REFRESH_DESTRUCT);
  break;
  case 4:
   AddItem(PNJ("glucksfall/kainoak"),REFRESH_DESTRUCT);
  break;
  case 6:
   AddItem(PNJ("glucksfall/troll"),REFRESH_DESTRUCT);
  break;
  case 8:
   AddItem(PNJ("glucksfall/orco"),REFRESH_DESTRUCT);
  break;
  default:
 }

 SetIndoors(1);
 SetIntBright(30);
 SetLocate("Glucksfall");

}
