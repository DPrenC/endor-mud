#include "path.h"
inherit KHA_ROOM;
#include "darts.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("El corredor parece estrecharse un poco m�s aqu�. Las paredes est�n llenas de "
        "un l�quido parduzco que parece salir de las grietas. El olor se hace casi "
        "insoportable.\n");
    SetIndoors(1);
    SetIntBright(30);
    AddDetail(({"roturas","rotura","pared","paredes","liquido","grieta",
	       "l�quido","grietas"}),"Ves unos peque�os agujeros en la pared, que casi est� a punto de "
	       "desmoronarse.\n");
    AddDetail(({"cucaracha","cucarachas"}),"Intenta huir cuando remueves los restos de comida.\n");
    AddDetail("suelo","Entre los restos de comida puedes ver incluso cucarachas intentando "
        "huir.\n");
    AddExit("este",CLOACAS+"cloaca7");
    AddExit("sur",CLOACAS+"cloaca5");
    AddItem(MONS+"slug",REFRESH_DESTRUCT,1);
}
