/*=============================================================*
 |             << GOLDHAI.playa [w] Woo@simauria >>            |
 *=============================================================*
 |                Creacion............. 29-10-98               |
 |                Ultima Modificacion.. 08-02-99               |
 |                                                             |
 *=============================================================*/

#include "../sys/goldhai.h"
inherit GROOM;

create() {
 ::create();

 SetIntShort("una playa");

 switch(random(4))
 {
  case 0:
 SetIntLong("\
Caminas sobre la arena de una playa. El agua del mar se acerca lentamente\n\
hasta la orilla para m�s tarde retroceder, dejando esa humedad caracter�stica\n\
sobre la arena. En el sur los arboles del bosque te impiden ir hacia all�.\n");
  break;

  case 1:
 SetIntLong("\
Est�s en una zona de la playa del norte de Goldhai. Es un sitio bastante\n\
tranquilo y silencioso ideal para pasar aqu� las tardes, mirando el mar.\n");
   break;

  case 2:
 SetIntLong("\
Paseas por la orilla de la playa con el agua del mar a escasos metros de ti.\n\
Cientos de conchas marinas se esparcen por la arena d�ndole un toque bastante\n\
agradable al lugar. El paisaje contrasta con los enormes �rboles del bosque\n\
que tienes al sur.\n");
  break;

  case 3:
 SetIntLong("\
Te encuentras en la playa del norte de la isla Goldhai. La arena y el agua\n\
son los dos elementos caracter�sticos que conforman la belleza del lugar.\n\
No puedes ir hac�a el sur ya que el bosque te lo impide, as� que no tienes\n\
otro remedio que continuar andando por la playa.\n");
  break;

  default:
 SetIntLong("\
Caminas sobre la arena de una playa. El agua del mar se acerca lentamente\n\
hasta la orilla para m�s tarde retroceder, dejando esa humedad caracter�stica\n\
sobre la arena.\n");
 }

 AddDetail(({"arena","playa","orilla"}),
"Una fina arena cubre todo el suelo de esta playa junto a centenares de\n\
peque�as conchas marinas.\n");
 AddDetail(({"mar","agua","oceano"}),
"No puedes divisar el fin de toda esta inmensidad de agua.\n");
 AddDetail(({"concha","conchas","conchas marinas","concha marina"}),
"Hay muchas de ellas a tu alrededor como si de un mosaico se tratara.\n");
 AddDetail(({"arboles","bosque","bosque norte"}),
"A tus espaldas hay un espeso bosque.\n");

 SetIntSmell("Es el t�pico olor a humedad de las zonas de playa.\n");
 SetIntNoise("Oyes el suave ruido del agua acercandose a la orilla.\n");

 SetIndoors(0); // A descubierto, es una playa ;))
}
