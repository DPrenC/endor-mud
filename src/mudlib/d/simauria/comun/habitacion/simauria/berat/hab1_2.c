/*
DESCRIPCION  : 2ª planta de la casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab1_2.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
  [Nyh] Como me jode que la peña use TP sin chekear si existe...
	Arreglo un bug provocado cuando TP evaluaba 0.
	Tb mejoro el allow_enter, que no chekeaba el method
	Tambien me jode que no pongan correctamente la declaracion de la
	funcion que estan sobreescribiendo.
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <moving.h>

inherit SIM_ROOM;

create() {

::create();
SetLocate("berat");
SetIntShort("el dormitorio");
SetIntLong(W("Estás en el dormitorio, parece muy confortable, frente a ti hay una "
"cama con  aspecto de ser bastante cómoda... , el suelo esta cubierto por una "
"alfombra exótica, en conjunto la habitación es bastante cálida y acogedora. "
"Puedes ver las escaleras por las que has subido,y una ventana que da al sur. "
"Un armario completa la habitacion. Tiene sus cajones cerrados.\n"));


SetIndoors(1);
SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
SetIntBright(50);

AddDetail(({"armario","mueble"}),W("Es un armario de corte clásico, parece "
"bastante viejo pero está bien cuidado.\n"));

AddDetail(({"cama"}),W("La cama es bastante grande (de matrimonio) "
"tiene unas mantas muy gruesas para poder soportar el frío intenso reinante de la zona.\n"));

AddDetail(({"escaleras","escaleras de madera"}),W("Las escaleras que bajan "
"al primer piso son bastante inclinadas,podrían ser peligrosas para alguien "
"borracho.\n"));

AddDetail(({"ventana"}),W("Por la ventana puedes ver el mar a lo lejos por encima de las "
"casas de berat.\n"));

AddExit("abajo","/d/simauria/comun/habitacion/simauria/berat/hab1_1");

AddItem(QUEST+"cuchillo/thalan",REFRESH_REMOVE,1);
}


public int allow_enter(int method, mixed extra)
{
  int i;
  object prev;
  if (!(prev = PO) || !living(prev) || (method != M_GO && method != M_SILENT))
  {
    return ::allow_enter(method, extra);
  }
  if (prev->QueryAlcohol()>30)
  {
    tell_object(prev, "Cuando estás intentando subir por las empinadas escaleras, "
                      "pierdes pie, y el poco equilibrio que tienes se desvanece, "
                      "con lo que caes rodando hasta la sala de abajo. Afortunadamente "
                      "no te haces mas que magulladuras.\n");
    return ME_NO_ENTER;
  }
  if ((i = ::allow_enter(method, extra)) == ME_OK)
  {
    tell_object(prev, "Subes las escaleras hasta el segundo piso.\n");
  }

  return i;
}
