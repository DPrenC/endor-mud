
#include "./path.h"
#include <sounds.h>

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("la calle principal de Gorat");
    SetIntLong("Estás en la calle principal de Gorat.\n Hacia el norte se sale del "
    "pueblo encontrándose con la parada de la diligencia y uno de los caminos de Simauria."
    " Al oeste te encontrarías con el puerto, mientras que hacia el este la calle te "
    "adentra más en el pueblo.\n");
    SetIndoors(0);
        AddDetail(({"caño","canyo"}),"Es un simple tubo metálico que sale de la "
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
