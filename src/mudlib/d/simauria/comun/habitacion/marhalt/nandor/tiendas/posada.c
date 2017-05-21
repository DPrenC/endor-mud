/*    Archivo POSADA.C
      Descripcion : posada de la Aldea Nandor
      Realizada por : Saavik coordinada por Blackrider
      Creada : 5-6-97
      6-6-97 [woo] Adaptado al pub estandar...
      Ultima modificacion : 03/11/2006
[buh] hecho todo el sangrado, añadidos details, añadida la salida a la calle Narwhald y
      cambiada la descripción más acorde a los cambios.
*/

#include <properties.h>
#include "./path.h"

inherit PUB;
create() {
    ::create();
    SetIntShort("la posada de Nandor");
    SetLocate("Aldea de Nandor");
    SetIntLong("Un agradable ambiente domina la estancia con gente charlando y comiendo.\n"
        " Ciertamente desde fuera no parece tan grande como ahora que la estás viendo "
        "desde el interior, quizá por eso es que tiene dos salidas, la del sur hacia la "
        "calle principal y la del nordeste hacia la calle Narwhald.\n Una escalera, junto"
        " a la barra, que se encuentra en la zona este del lugar, sube a una segunda "
        "planta.\n También ves al norte lo que parece un comedor privado. Y en una "
        "de las paredes, sobre un gran tonel, está clavado el menú.\n");
    SetIntBright(45);
    SetIntNoise("El sonido de risas y voces es muy fuerte.\n");
    SetIntSmell("Un olor a comida sale de la cocina.\n");
    AddDetail(({"tonel", "barril"}), "Lo menos le caben ahí 500 litros, posiblemente "
        "contenga vino.\n");
    AddDetail(({"escalera","escaleras"}), "Sube a las habitaciones.\n");
    AddDetail(({"barra", "mostrador"}), "Detrás del mostrador se mueve el tabernero, "
        "también hay una pequeña cocina ahí.\n");
    AddDetail(({"gente", "personas"}), "Comen, beben y charlan animadamente, no parece "
        "que sean todos de Nandor.\n");
    AddDetail(({"salida","salidas"}), "La del sur va a la calle principal, mientras que "
        "la del nordeste sale a la calle Narwhald.\n");
    AddExit("nordeste",MARH("nandor/calle15"));
    AddExit("norte","./come1");
    AddExit("arriba","./pasi0");
    AddExit("sur",MARH("nandor/calle0"));
    AddDoor("sur", "la puerta principal",
    "Es la puerta principal de la posada que da a la calle principal de Nandor.\n",
    ({"puerta", "puerta principal", "puerta principal de la posada", "puerta del sur"}));
    AddDoor("nordeste", "la puerta trasera",
    "Es la puerta trasera de la posada que va a dar a la calle Narwhald.\n",
    ({"puerta", "puerta trasera", "puerta del nordeste"}));
    AddItem(PNJ("marhalt/kender"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("marhalt/bardo"),REFRESH_DESTRUCT,1);
    SetKeeper(PNJ("marhalt/tabernero_nandor"));
    AddFood("cordero al horno","un plato de",10,13,0);
    AddFood("estofado de ternera","un plato de",9,12,0);
    AddFood("pollo con patatas","un plato de",10,15,0);
    AddFood("sopa de verduras","un plato de",7,8,0);
    AddFood("patatas asadas","unas",7,9,0);
    AddFood("albóndigas en salsa","unas",9,12,0);
    AddFood("chuletas de cerdo","unas",12,13,0);
    AddDrink("cerveza","una jarra de",5,6,10,0);
    AddDrink("vino","un vaso de",3,4,8,0);
}
