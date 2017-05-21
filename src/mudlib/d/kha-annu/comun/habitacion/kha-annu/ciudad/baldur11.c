#include "./path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("la calle de Baldur");
    SetIntLong("Llegas hasta casi el final de la calle Baldur de Kha-annu. Hacia el norte ves"
        "un portal abierto que conduce a la posada. Hacia el este está la esquina de esta "
            "calle con la calle Kilok, llamada así por el río que pasa bajo ella.\n");
    SetIntBright(60);
    SetIndoors(1);
    AddDetail( ({"caverna","cueva","excavación","excavacion"}),"Toda la parte este de la "
        "ciudad está excavada a mano en la pared de la montaña.\n");
    AddDetail(({"gremio","gremios"}),"Un poco hacia el oeste se encuentra la entrada al gremio "
        "de clerigos, y por esta misma calle en la misma direccion esta tambien el de guerreros.\n");
    AddDetail(({"lámpara","lampara","lamparas","lámparas","antorcha","antorchas","farola",
        "farolas","luz"}),"Son dos especie de antorchas, pero que no despiden gas ni llama "
        "alguna.\n");
    AddExit("norte",POSADAS+"dazul/posada");
    AddExit("este",CIUDAD+"baldur12");
    AddExit("oeste",CIUDAD+"baldur10");
    SetLocate("ciudad de Kha-Annu");
}
