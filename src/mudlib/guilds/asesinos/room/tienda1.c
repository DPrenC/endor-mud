/*
DESCRIPCION : tienda del gremio de asesinos
FICHERO     : /guilds/asesinos/room/tienda.c
MODIFICACION: 21-06-00 [Maler] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <rooms.h>
#include <moving.h>
inherit SHOP;

#define NOMBRE          (TP->QueryName())
#define NOMBRE_M        (capitalize NOMBRE)
#define SUF             (TP->QueryGenderEndString())
#define SUF2            (TP->QueryGender()==2?"a":"e")

create()
 {
  ::create();
  SetIntShort("una tienda");
  SetIntLong(
 W("Te encuentras en una tienda, propiedad del "
 "famoso Eolion. Las paredes son de marmol negro, y reflejan la "
 "poca luz que ilumina esta estancia. Todo est� incre�blemente ordenado "
 "y pulcro, como si cada cosa estuviese en un sitio especialmente creado "
 "para ella. La variedad de dagas y cuchillos es asombrosa. Ves tambi�n "
 "algunas katanas y armas de esgrima. Una bonita colecci�n de armaduras "
 "de piel de diversos colores cuelga de las paredes.\n"));

 AddDetail(({"tienda","local"}),QueryIntLong());

 AddDetail(({"daga","dagas"}),
 W("Hay una incre�ble variedad de dagas, algunas de ellas dise�adas para funciones "
 "muy determinadas.\n"));
 AddDetail(({"cuchillo","cuchillos"}),
 W("Una incre�ble variedad de cuchillos, los hay de todos los tama�os y formas, cada uno "
 "espec�ficamente dise�ado para una situaci�n determinada.\n"));

 AddDetail(({"armadura","armaduras","armaduras de piel"}),
 W("Hmm, seguro que ser�an de gran utilidad.\n"));

 AddDetail(({"armas de esgrima","esgrima","katana","katanas"}),
 W("Apoyadas contra las paredes y el mostrador, ves varias katanas de color negro, "
 "y otras algo m�s largas de filo plateado. Parece que son bastante caras.\n"));
 SetIntNoise(W("El silencio de este lugar es casi asfixiante.\n"));
 SetIntSmell(W("No hueles a nada en especial en este lugar.\n"));
 SetIndoors(1);
 SetIntBright(50);

 AddExit("nordeste",GASESINOS+"gremio");

 CanAppraise(0); //No se valoran objetos
 CanIdentify(0); //No se identifican objetos

 SetShopkeeper("../pnj/eolion");

//articulos a la venta
 AddArticle(OBJETO("kukri"),REFRESH_REMOVE,10);
 AddArticle(OBJETO("black_katana"), REFRESH_REMOVE,5);
 AddArticle(OBJETO("long_katana"), REFRESH_REMOVE,5);
  AddArticle(OBJETO("daga_lanzar"),REFRESH_REMOVE,5);
  AddArticle(OBJETO("traje_cuero"), REFRESH_REMOVE,5);
 AddArticle(OBJETO("mortero"),REFRESH_REMOVE,10);
 AddArticle(OBJETO("poison_vial"),REFRESH_REMOVE,10);
 AddArticle(HERBS("hierba_venenosa"),REFRESH_REMOVE,10);
}
