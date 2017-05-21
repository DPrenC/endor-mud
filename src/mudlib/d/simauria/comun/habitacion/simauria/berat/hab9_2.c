/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab9_2.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
-------------------------------------------------------------------------------
*/
#include <moving.h>
#include "path.h"

inherit SIM_ROOM;

create() {

::create();
SetLocate("berat");
SetIntShort("el segundo piso");
SetIntLong(W("Este es el segundo piso de la casa. Desde aquí puedes ver que la habitación "
"está bastante ordenada llena de trastos extraños, montones de papeles y "
"bastantes cosas más desperdigadas por la habitación.\n"));

AddDetail("cosas","Un montón de cosas.\n");
AddDetail("trastos","Alguien muy raro vive aquí, nunca habías visto nada parecido.\n");
AddDetail("papeles","Un montón de papeles sin ninguna utilidad.\n");

SetIndoors(1);
SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
SetIntBright(50);

AddDetail(({"escaleras","escaleras de madera"}),W("Las escaleras que bajan "
"al primer piso son bastante inclinadas, podrian ser peligrosas para alguien "
"borracho.\n"));


AddExit("abajo","./hab9_1");

}
allow_enter(int metodo,mixed extras)
{
  if (TP->QueryAlcohol()>30)
  {
    write(W("Cuando estás intentando subir por las empinadas escaleras pierdes pie, "
         "a continuación el poco equilibrio que tienes se desvanece por lo que caes "
         "rodando hasta la sala de abajo, afortunadamente no te haces más que magulladuras.\n"));

    return ME_NO_ENTER;
  }
  write("logras llegar al segundo piso.\n");
  return ::allow_enter(metodo,extras);
}
