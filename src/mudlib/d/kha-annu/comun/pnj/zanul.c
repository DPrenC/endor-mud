/* [Woo] Modificado */

#include "path.h"
#include <properties.h>

inherit KBASE;

create() {
      ::create();

   SetStandard("Zanul","enano",3,GENDER_MALE);
   SetShort("Zanul, el tendero");
  SetLong(
"Zanul es el duenyo de la tienda de armas en la calle Rurik. Es un enano "
"bastante curtido, con una espesa barba marron trenzada. Sus cejas estan bien "
"pobladas, y su nariz tiene un gracioso tono encarnado... habra estado en el "
"Dragon Azul hace escasos minutos. Su rostro muestra un sonrisa desde que "
"has puesto los pies en su tienda.\n");
  SetIds( ({"enano","zanul","Zanul","tendero"}) );
  SetAds( ({"el","un"}) );
}
