/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab4_2.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
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
SetIntLong(W("Est�s en el dormitorio, parece muy confortable, frente a ti hay una "
"cama con  aspecto de ser bastante c�moda..., el suelo esta cubierto por una "
"alfombra ex�tica, en conjunto la habitaci�n es bastante c�lida y acogedora. "
"Puedes ver las escaleras por las que has subido, y una ventana que da al sur. "
"Un armario completa la habitaci�n, tiene sus cajones cerrados.\n"));


SetIndoors(1);
SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
SetIntBright(50);

AddDetail(({"armario","mueble"}),W("Es un armario de corte cl�sico, parece "
"bastante viejo pero esta bien cuidado.\n"));

AddDetail(({"cama"}),W("La cama es bastante grande y lujosa como corresponde a un comerciante"
"tiene unas mantas muy gruesas para poder soportar el fr�o intenso reinante de la zona.\n"));

AddDetail(({"escaleras","escaleras de madera"}),W("Las escaleras que bajan "
"al primer piso son bastante inclinadas, podr�an ser peligrosas para alguien "
"borracho.\n"));

AddDetail(({"ventana"}),W("Por la ventana puedes ver el mar a lo lejos por encima de las "
"casas de Berat.\n"));

AddExit("abajo","/d/simauria/comun/habitacion/simauria/berat/hab4_1");

}
allow_enter(int metodo,mixed extras)
{
  if (TP->QueryAlcohol()>30)
  {
    write(W("Cuando est�s intentando subir por las empinadas escaleras pierdes pie, "
         " a continuaci�n el poco equilibrio que tienes se desvanece por lo que caes "
         "rodando hasta la sala de abajo, afortunadamente no te haces mas que magulladuras.\n"));

    return ME_NO_ENTER;
  }
  write("logras llegar al segundo piso.\n");
  return ::allow_enter(metodo,extras);
}