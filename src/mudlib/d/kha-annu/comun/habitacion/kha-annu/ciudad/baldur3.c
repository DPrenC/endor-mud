#include "./path.h"
inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Caminas a traves del amplio corredor que es la calle Baldur. Esta es la "
"calle donde se encuentran los gremios de la ciudad. Senyalando hacia el "
"norte ves una inmensa estatua con una enorme espada en su cinturon y "
"cabalgando una hermosa yegua. Unas grandes farolas negras de metal "
"iluminan el pasillo que conforma la calle Baldur.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"gremio","gremios"}),
	     "Los gremios estan hacia el este de donde te encuentras.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, su mision es "
"la iluminacion de toda la ciudad\n");
   AddExit("este",CIUDAD+"baldur4");
   AddExit("oeste",CIUDAD+"baldur2");
   AddItem(OTRO("estatua"),REFRESH_DESTRUCT,1);
   SetLocate("Kha-annu");
}