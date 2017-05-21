#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Te encuentras hacia el oeste de la ciudad, en la calle de Baldur. En esta "
"calle, hacia el este, se encuentran los gremios de Kha-annu. Es una calle "
"solo transitada por los aventureros osados que buscan algo de accion en "
"sus vidas. La calle esta iluminada por unas grandes farolas negras que "
"emiten una ligera llama alimentada con gas.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"gremio","gremios"}),
	     "Los gremios estan hacia el este de donde te encuentras.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, su mision es "
"la iluminacion de toda la ciudad\n");
   AddExit("oeste",CIUDAD+"rurik_a");
   AddExit("este",CIUDAD+"baldur2");
}