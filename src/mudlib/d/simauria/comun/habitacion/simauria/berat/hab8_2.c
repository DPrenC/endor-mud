/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab8_2.c
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
"cama con aspecto de ser bastante c�moda... , el suelo esta cubierto por una "
"alfombra. "
"Puedes ver las escaleras por las que has subido, y una ventana que da al este. "
"Un armario completa la habitaci�n, tiene sus cajones cerrados.\n"));
AddDetail("alfombra","Una alfombra muy vieja.\n");
AddDetail("cajones","Est�n cerrados a cal y canto.\n");
AddDetail("armario","Un armario con cajones.\n");


SetIndoors(1);
SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar todo est� impregnado con un olor a mar.\n");
SetIntBright(50);


AddDetail(({"cama"}),W("La cama es bastante grande par ser de una sola plaza"
"tiene unas mantas muy gruesas para poder soportar el fr�o intenso reinante de la zona.\n"));

AddDetail(({"escaleras","escaleras de madera"}),W("Las escaleras que bajan "
"al primer piso son bastante inclinadas, podr�an ser peligrosas para alguien "
"borracho.\n"));

AddDetail(({"ventana"}),"Por la ventana puedes ver el delta sobre el que esta construido Berat.\n");

AddExit("abajo","/d/simauria/comun/habitacion/simauria/berat/hab8_1");

}
allow_enter(int metodo,mixed extras)
{
  if (TP->QueryAlcohol()>30)
  {
    write(W("Cuando est�s intentando subir por las empinadas escaleras pierdes pie, "
         "a continuaci�n el poco equilibrio que tienes se desvanece por lo que caes "
         "rodando hasta la sala de abajo, afortunadamente no te haces m�s que magulladuras.\n"));
    return ME_NO_ENTER;
  }
  write("logras llegar al segundo piso.\n");
  return ::allow_enter(metodo,extras);
}
