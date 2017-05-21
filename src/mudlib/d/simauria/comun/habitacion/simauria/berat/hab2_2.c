/*
DESCRIPCION  : Dentro de una casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab2_2.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include "./moving.h"

inherit SIM_ROOM;

create() {

::create();
SetLocate("berat");
SetIntShort("el despacho");
SetIntLong(W("Estás en el despacho-dormitorio de la casa,esta habitación es más "
"austera que la de abajo. Tiene un escritorio lleno de papeles "
"y, separada por un biombo, una cama con un pequeño armario a su lado,por lo que "
"has podido ver esto es el despacho de algún comerciante y carece de las comodidades "
"que, segun tu opinión, debería tener un dormitorio. Al oeste se abre una ventana "
"detrás tuyo estan las escaleras por donde has subido aquí.\n"));

SetIndoors(1);
SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
SetIntBright(50);

AddDetail(({"armario","mueble"}),W("Es un pequeño armario de corte clásico, parece "
"bastante viejo pero está bien cuidado.\n"));

AddDetail(("cama"),W("La cama es bastante pequeña, parece bastante incómoda, "
"tiene unas mantas muy gruesas para poder soportar el frío intenso reinante de la zona.\n"));

AddDetail(({"escaleras","escaleras de madera"}),W("Las escaleras que bajan "
"al primer piso son bastante inclinadas, podrían ser peligrosas para alguien "
"borracho.\n"));

AddDetail(({"escritorio"}),W("El escritorio es de madera y parece bastante usado, está "
"recubierto de papeles. Quizá si los mirases encontraras algo de utilidad.\n"));

AddDetail(({"papeles","papel"}),W("Después de mirar los papeles no ves nada de interés "
"casi todos son recibos, facturas y comprobantes de diversas operaciones mercantiles.\n"));

AddDetail(({"ventana"}),W("Por la ventana ves el delta sobre el que esta construido el "
"pueblo de Berat, al fondo puedes ver unos campos de cultivo de los que se alimenta el pueblo.\n"));

AddExit("abajo","/d/simauria/comun/habitacion/simauria/berat/hab2_1");
AddRoomCmd("coger","cmd_coger");
}

int cmd_coger(string str)
     {if (!str || str!="papeles")
         return notify_fail("¿que quieres coger?\n"),0;

       write("¿no pensaras robarle los papeles al comerciante verdad?.\n");
       return 1;
     }

allow_enter(int metodo,mixed extras)
{
  if (TP->QueryAlcohol()>30)
  {
    write(W("Cuando estás intentando subir por las empinadas escaleras pierdes pie, "
         "a continuación el poco equilibrio que tienes se desvanece por lo que caes "
         "rodando hasta la sala de abajo,afortunadamente no te haces mas que magulladuras.\n"));
    return ME_NO_ENTER;
  }
  write("logras llegar al segundo piso.\n");
  return ::allow_enter(metodo,extras);
}
    