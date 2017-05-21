inherit ROOM;
#include "path.h"


create() {
::create();
SetLocate("gremio de hechiceros");
SetIntBright(50);
SetIntShort("unas escaleras");
SetIntLong(W("Estas en las escaleras que comunican los distintos pisos"
" de la torre del gremio estan realizadas en marmol exquisitamente tallado"
" si miras hacia arriba puedes verte reflejado en el pulido techo."
" Ves un cartel dorado colgado en la pared.\n"));
SetIndoors(1);
AddDetail(({"cartel"}),W("Es un pequeño cartel dorado, podrias leerlo, asi podiras saber lo que pone.\n"));
AddReadMsg(({"cartel"}),W(
"El cartel pone:\n"
"La habitacion de descanso se encuentra al oeste, al sur la tienda del gremio de los hechiceros"
" y al suroeste la gran biblioteca del gremio.\n"
));
AddExit("suroeste","./bibliote");
AddExit("oeste","./descan");
AddExit("sur","./tienda");
//AddExit("arriba","./esca2");
AddExit("abajo","./esca0");
}


