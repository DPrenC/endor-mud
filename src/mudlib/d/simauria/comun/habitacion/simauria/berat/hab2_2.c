/*
DESCRIPCION  : Dentro de una casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab2_2.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
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
SetIntLong(W("Est�s en el despacho-dormitorio de la casa,esta habitaci�n es m�s "
"austera que la de abajo. Tiene un escritorio lleno de papeles "
"y, separada por un biombo, una cama con un peque�o armario a su lado,por lo que "
"has podido ver esto es el despacho de alg�n comerciante y carece de las comodidades "
"que, segun tu opini�n, deber�a tener un dormitorio. Al oeste se abre una ventana "
"detr�s tuyo estan las escaleras por donde has subido aqu�.\n"));

SetIndoors(1);
SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
SetIntBright(50);

AddDetail(({"armario","mueble"}),W("Es un peque�o armario de corte cl�sico, parece "
"bastante viejo pero est� bien cuidado.\n"));

AddDetail(("cama"),W("La cama es bastante peque�a, parece bastante inc�moda, "
"tiene unas mantas muy gruesas para poder soportar el fr�o intenso reinante de la zona.\n"));

AddDetail(({"escaleras","escaleras de madera"}),W("Las escaleras que bajan "
"al primer piso son bastante inclinadas, podr�an ser peligrosas para alguien "
"borracho.\n"));

AddDetail(({"escritorio"}),W("El escritorio es de madera y parece bastante usado, est� "
"recubierto de papeles. Quiz� si los mirases encontraras algo de utilidad.\n"));

AddDetail(({"papeles","papel"}),W("Despu�s de mirar los papeles no ves nada de inter�s "
"casi todos son recibos, facturas y comprobantes de diversas operaciones mercantiles.\n"));

AddDetail(({"ventana"}),W("Por la ventana ves el delta sobre el que esta construido el "
"pueblo de Berat, al fondo puedes ver unos campos de cultivo de los que se alimenta el pueblo.\n"));

AddExit("abajo","/d/simauria/comun/habitacion/simauria/berat/hab2_1");
AddRoomCmd("coger","cmd_coger");
}

int cmd_coger(string str)
     {if (!str || str!="papeles")
         return notify_fail("�que quieres coger?\n"),0;

       write("�no pensaras robarle los papeles al comerciante verdad?.\n");
       return 1;
     }

allow_enter(int metodo,mixed extras)
{
  if (TP->QueryAlcohol()>30)
  {
    write(W("Cuando est�s intentando subir por las empinadas escaleras pierdes pie, "
         "a continuaci�n el poco equilibrio que tienes se desvanece por lo que caes "
         "rodando hasta la sala de abajo,afortunadamente no te haces mas que magulladuras.\n"));
    return ME_NO_ENTER;
  }
  write("logras llegar al segundo piso.\n");
  return ::allow_enter(metodo,extras);
}
    