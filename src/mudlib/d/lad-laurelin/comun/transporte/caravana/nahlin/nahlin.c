/* SIMAURIA 'Caravana de Nahlin' */

#include "path.h"
#define PSIM "/d/simauria/comun/habitacion/marhalt/nandor/calle0"
#define PATBAL ATBALNIN + "bosque/bosque17"


inherit CARAVAN;
public create()
{
 ::create();
 seteuid(getuid());
 SetIds(({"caravana","nahlin", "Nahlin","caravana Nahlin","caravana nahlin"}));
 SetShort("la caravana Nahlin");
 SetLong(W("Es una larga caravana de elfos montados a caballo, que viaja del "+
 	"bosque de Atbalnin a Nandor.\n"));

 SetEnterMsgs(
   ({"se monta en un caballo y se une a la caravana de Nahlin",
     "se monta en un caballo y se une a la caravana de Nahlin",
     "Te montas en un caballo y te unes a la caravana de Nahlin"}));

 SetLeaveMsgs(
   ({"se baja de un caballo y abandona la caravana",
     "se baja de un caballo y abandona la caravana",
     "Te bajas de un caballo y abandonas la caravana"}));

 SetCaravanaEnterMsgs(({"El lider de la caravana grita: Hemos llegado a @@Parada@@!\n",
	   "La caravana Nahlin llega de @@FromParada@@.\n"}));

 SetCaravanaLeaveMsgs(({"Nos vamos a @@Parada@@!\n",
	   "La caravana Nahlin sale hacia @@Parada@@.\n"}));
 SetParadas(([0:PSIM;"Nandor",1:PATBAL;"Atbalnin"]));

 AddMoveScene(PATBAL, PSIM, "Estás saliendo del bosque de Atbalnin.\n", 10);
 AddMoveScene(PATBAL, PSIM, "Empiezas a subir por las montañas.\n", 15);
 AddMoveScene(PATBAL, PSIM, "Estás en la zona mas alta de las montañas.\n", 15);
 AddMoveScene(PATBAL, PSIM, "Dejas atrás el dominio elfo de Lad-Laurelin.\n", 15);
 AddMoveScene(PATBAL, PSIM, "Atraviesas el bosque de Simauria.\n", 15);
 AddMoveScene(PATBAL, PSIM, "Cruzas un recio puente de piedra.\n", 10);
 AddMoveScene(PATBAL, PSIM, "Continúas por un camino junto a las montañas.\n", 10);
 AddMoveScene(PATBAL, PSIM, "Estás entrando en Nandor.\n", 10);

 AddMoveScene(PSIM, PATBAL, "Estás saliendo de Nandor.\n", 10);
 AddMoveScene(PSIM, PATBAL, "La caravana continúa por un camino junto a las montañas.\n", 15);
 AddMoveScene(PSIM, PATBAL, "La caravana cruza un recio puente de piedra.\n", 15);
 AddMoveScene(PSIM, PATBAL, "Estás cruzando el bosque de Simauria.\n", 10);
 AddMoveScene(PSIM, PATBAL, "La caravana sube por las montañas.\n", 15);
 AddMoveScene(PSIM, PATBAL, "La caravana deja atrás el dominio humano.\n", 15);
 AddMoveScene(PSIM, PATBAL, "La caravana baja de las montañas.\n", 10);
 AddMoveScene(PSIM, PATBAL, "Entras en el bosque de Atbalnin.\n", 15);

 SetCaravanaCost(300);

// Al contrario que los barcos las caravanas solo tienen una habitacion.
 AddDeck(NAHLIN("interior_nahlin"));

 SetMsgCost("No tienes suficiente dinero para unirte a la caravana.\n");
}
