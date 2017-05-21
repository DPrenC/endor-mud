/****************************************************************************
Fichero: posada.c
Autor: Ratwor
Fecha: 27/08/2006
Descripción: una posada reformada para krigor.
****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit PUB ;

create()
{
    ::create();
    SetIntShort("la posada los 3 puñales");
    SetIntLong("Algunos juegos de mesas y sillas rellenan la extraña estancia convertida "
        "en esta posada llamada los 3 puñales, por algún motivo desconocido...\n"
        " Ciertamente no es muy grande, pero teniendo en cuenta lo aislado del "
        "pueblo de Krigor respecto al resto del mundo, no le hace falta una posada mayor "
        ".\n Unas estrechas escaleras suben al piso superior, donde se supone que"
        " se encuentran las habitaciones.\n  Junto al mostrador, ves el menú "
        "de las comidas y bebidas  que sirven en este local.\n");
    SetLocate("Krigor");
    SetIntSmell("EL contraste de la madera con el olor de las comidas invade el lugar.\n");
    SetIntNoise("Un extraño sonido sordo da un ambiente incómodo a la estancia.\n");
    SetIntBright(30);
    SetKeeper(PNJKRIG("posadero_krigor"));
    AddExit("arriba",KRIGOR("posada/pasillo"));
    AddExit("oeste",KRIGOR("plaza"));
    AddExit("este",KRIGOR("posada/comedor"));
    AddDoor("oeste", "la puerta de la calle",
    "Es la puerta para salir a la plaza de Krigor.\n",
    ({"puerta", "puerta de la calle", "puerta del oeste"}));
    AddDrink("agua", "un vaso de", 3, 0, 12, 0,
        "El tabernero te sirve el vaso de agua y te lo bebes de un trago sin respirar.\n");
    AddDrink("vino tinto", "un vaso de", 5, 9, 4, 0,
"El tabernero llena un vaso de un pequeño barril con vino tinto y te lo sirve... parece "
        "que sabe bien y te calienta por dentro.\n");
    AddDrink("cerveza","una jarra de",5,6, 9,0, "Está fresquita y sienta muy bien.\n");
    AddDrink("ron","un vaso de",5,12,6,0,
        "Te bebes el ron sin respirar, ¡Qué fuerte está este ron!.\n");
    AddFood("cordero asado", "un plato de", 6,10, 0,
        "El posadero te trae un plato de cordero asado que alimenta.\n");
    AddFood("guisado de ternera", "un plato de", 7, 9, 0,
        "El posadero te sirve el guisado, que al comertelo te sientes como nuevo.\n");
    AddFood("rabo de toro", "una cazuela de", 8, 11,0,
        "EL posadero te trae una cazuela de rabo de toro humeante que te llena de vida "
        "al comértelo.\n");
}
