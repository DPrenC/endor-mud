/*
Fichero: traspuertao.c
Autor: aulë
Fecha: 12/03/2013
Descripción: Tras la puerta oeste de Bree.
Al anochecer se cierra y hay que llamar, el guardia te deja pasar según raza o
alineamiento.
*/
#include "./path.h"
inherit HABITACION+"bree/base_aldea";
create()
{
    ::create();
    	SetIntShort("ante la caseta de guardia");
    	SetIntLong(
    	"Estás en un camino que arranca de la puerta situada justo al oeste y por la que "
    	"puedes abandonar la aldea de Bree. A tu alrededor se ierguen, algo dispersas, "
    	"humildes pero funcionales y confortables, las casas de los hombres de Bree.\n"
    	"Justo al norte se levanta una pequeña caseta o cabañña de piedra donde el "
    	"guardián encargado de la vigilancia de la puerta se guarece de los elementos, "
    	"pudiendo observar el camino por la ventana dispuesta a tal efecto.\n"
    	"Hacia el oeste el camino asciende una leve pendiente internándose entre las "
    	"casas de la aldea hasta llegar a un alto edificio de dos alas.\n");
    	AddDetail(({"caseta", "cabaña"}),
    	"Es una baja cabaña de piedra toscamente tallada y encajada con gruesa argamasa.\n"
    	"El techo de tejas es a dos aguas y cuenta con una pequeña ventanita y una "
    	"sólida puerta baja.\n");
    AddExit("oeste", HABITACION+"caminos/antepuertao");
     AddExit("este", "./viao1");
     AddExit("norte", "./casetao");
     AddDoor("norte", "la puerta de la caseta de guardia",
     "Es una robusta puerta de madera formada por anchos tablones.\n"
     "Tiene un ventanuco en la parte superior.\n",
     ({"puerta", "norte", "n", "caseta", "puerta de la caseta", "puerta n"}));
     AddDoor("oeste", "una robusta puerta de trancas",
     "Es una robusta puerta de unos dos metros de altura constituida por gruesas "
     "trancas de madera reforzadas con herrajes y con la punta aguzada.\n"
     "Varios pesados cerrojos y pestillos la aseguran y posee un par de ventanucos "
     "a la altura de un Hobbit y de un Hombre respectivamente para examinar el "
     "exterior e identificar a quien llame tras la puesta de sol.\n",
     ({"trancas", "puerta", "o", "oeste", "puerta o"}));
     
     
    }