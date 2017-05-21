
/*
 FECHA: 30/4/99
 AUTOR: Parsifal
 DESCRIPCION: Primera prueba del nidito de Limbo :)
*/


#include <rooms.h>
#include <stdrooms.h>
#include <properties.h>
inherit ROOM;


create () {
  ::create();
  Set(P_INT_SHORT, "sauna del nidito de Mirill y Parsifal");
  Set(P_INT_LONG,
    W("Estás en la sauna de Parsifal y Mirill. Es un cubículo pequeñajo, construido "
    "totalmente en madera, algo claustrofóbico. Es una sauna como otra cualquiera. "
    "Si la pusieran en marcha mientras tú estás dentro con toda esa ropa, no te "
    "haría ninguna gracia... "
    "\n"));

  AddDetail(
         ({"cazo"}),
         "Hay un cazo para refrescarse un poco durante la sauna. No le ves ninguna "
         "otra utilidad. "
         "\n");

  AddDetail(
         ({"cubo"}),
         "Es un cubo lleno de agua. Mejor dejarlo donde está. "
	 "\n");

  AddDetail(
         ({"toalla","toallas"}),
         "Son unas mullidas toallas de felpa, para envolverse en ellas durante la "
         "sauna... aunque Mirill y Parsifal no suelen utilizarlas... "
         "\n");

  SetIntBright(40);
  SetIndoors(1);

  AddExit("banyo","nido4");
}
