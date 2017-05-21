
#include "./path.h"
#include <sounds.h>

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("la calle principal de Gorat");
    SetIntLong("Est�s en la calle principal de Gorat.\n Hacia el norte se sale del "
    "pueblo encontr�ndose con la parada de la diligencia y uno de los caminos de Simauria."
    " Al oeste te encontrar�as con el puerto, mientras que hacia el este la calle te "
    "adentra m�s en el pueblo.\n");
    SetIndoors(0);
        AddDetail(({"ca�o","canyo"}),"Es un simple tubo met�lico que sale de la "
        "piedra.\n");
        AddDetail(({"pila"}),"Es un agujero cuadrado pavimentado, donde se "
        "recoge el agua que cae de la fuente.\n");
    AddExit("este","./callep3");
    AddExit("oeste","./callep1");
    AddExit("norte","./callec1");
    AddItem(OTRO("betua/fuente"));
    AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT, d2());
    AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT, d2());
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}
