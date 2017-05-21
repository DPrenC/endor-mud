#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

create()
{
  ::create();
  SetIntLong(W("Frente a t� ves una tienda, que por el sonido interior y "
  	"por alguna que otra pista m�s puedes intuir que sirve como compra "
  	"venta de armas. Una de ellas es el cartel donde puedes leer: tienda "
  	"de armas. Hacia el sur vislumbras la silueta de un edificio.\n"));

  SetIntShort("la zona central de Atbalnin");
  AddDetail("tienda", "Es una tienda donde habitualmente se compran y venden armas.\n");
  AddReadMsg("cartel", W("En una caligraf�a no demasiado ortodoxa puedes leer "
  	"Tienda de Armas.\n"));
  AddDetail("cartel", "En un cartel con un dibujo de un yunque y un martillo. Podr�as leerlo.\n");

  AddExit("sur", ATB_CI("ciudad31"));
  AddExit("suroeste", ATB_CI("ciudad30"));
  AddExit("entrar", ATB_TI("tienda05"));

}
