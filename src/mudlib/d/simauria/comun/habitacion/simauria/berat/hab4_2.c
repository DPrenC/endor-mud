/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab4_2.c
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
SetIntShort("el dormitorio");
SetIntLong(W("Estás en el dormitorio, parece muy confortable, frente a ti hay una "
"cama con  aspecto de ser bastante cómoda..., el suelo esta cubierto por una "
"alfombra exótica, en conjunto la habitación es bastante cálida y acogedora. "
"Puedes ver las escaleras por las que has subido, y una ventana que da al sur. "
"Un armario completa la habitación, tiene sus cajones cerrados.\n"));


SetIndoors(1);
SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
SetIntBright(50);

AddDetail(({"armario","mueble"}),W("Es un armario de corte clásico, parece "
"bastante viejo pero esta bien cuidado.\n"));

AddDetail(({"cama"}),W("La cama es bastante grande y lujosa como corresponde a un comerciante"
"tiene unas mantas muy gruesas para poder soportar el frío intenso reinante de la zona.\n"));

AddDetail(({"escaleras","escaleras de madera"}),W("Las escaleras que bajan "
"al primer piso son bastante inclinadas, podrían ser peligrosas para alguien "
"borracho.\n"));

AddDetail(({"ventana"}),W("Por la ventana puedes ver el mar a lo lejos por encima de las "
"casas de Berat.\n"));

AddExit("abajo","/d/simauria/comun/habitacion/simauria/berat/hab4_1");

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