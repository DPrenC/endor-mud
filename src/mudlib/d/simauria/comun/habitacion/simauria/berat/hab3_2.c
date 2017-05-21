/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab3_2.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
--------------------------------------------------------------------------------
*/
#include <moving.h>
#include "path.h"

inherit SIM_ROOM;

create() {

::create();
SetLocate("berat");
SetIntShort("el segundo piso");
SetIntLong(W("Estás en el segundo piso de la casa parece que aquí sus moradores duermen"
"puesto que hay una cama de matrimonio y una cuna de bebe. Junto a la cuna hay un "
"armario bastante grande, y junto a la cama de matrimonio una mesita de noche de madera "
"por lo demás la habitación es normal no tiene más que una ventana orientada al este "
"desde la que puedes ver el delta sobre el que se asienta el pueblo. "
"Detrás tuyo estan las escaleras por donde has subido aquí\n"));


SetIndoors(1);
SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
SetIntBright(50);

AddDetail(({"mesita"}),W("Es una pequeño mesita, parece "
"bastante vieja pero está bien cuidada.\n"));

AddDetail(({"cama"}),W("La cama es de matrimonio y como tal es grande y bastante "
"cómoda por lo que parece.\n"));

AddDetail(({"armario"}),W("El armario está abierto y en su interior puedes ver "
"una cantidad enorme de pañales y utensilios de limpieza de bebes.\n"));

AddDetail(({"escaleras","escaleras de madera"}),W("Las escaleras que bajan "
"al primer piso son bastante inclinadas, podrían ser peligrosas para alguien "
"borracho.\n"));


AddExit("abajo","./hab3_1");

}
allow_enter(int metodo,mixed extras)
{
  if (TP->QueryAlcohol()>30)
  {
    write(W("Cuando estás intentando subir por las empinadas escaleras pierdes pie, "
         " a continuación el poco equilibrio que tienes se desvanece por lo que caes "
         "rodando hasta la sala de abajo, afortunadamente no te haces mas que magulladuras.\n"));
    return ME_NO_ENTER;
  }
  write("logras llegar al segundo piso.\n");
  return ::allow_enter(metodo,extras);
}

