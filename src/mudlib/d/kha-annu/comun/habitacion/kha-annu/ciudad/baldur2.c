#include "./path.h"

inherit KHA_ROOM;
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Estas en la calle Baldur, al oeste de la ciudad. Las calles de la zona oeste "
"son pasillos cavados en la montanya por la mano de los enanos. Hacia el este "
"puedes ver algo de luz solar que proviene de la salida de la caverna. En "
"esta calle se encuentran los gremios de guerreros y clerigos, en los que los "
"aventureros entrenan su fuerza bruta y su sabiduria.\n");
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"gremio","gremios"}),
	     "Los gremios estan hacia el este de donde te encuentras.\n");
   AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, su mision es "
"la iluminacion de toda la ciudad\n");
   AddExit("norte",CIUDAD+"callejon2");
   AddExit("oeste",CIUDAD+"baldur1");
   AddExit("este",CIUDAD+"baldur3");
}