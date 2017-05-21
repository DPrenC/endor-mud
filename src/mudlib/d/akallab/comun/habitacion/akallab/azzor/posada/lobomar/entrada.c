/*
DESCRIPCION : posada del Lobo de mar
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/entrada.c
MODIFICACION:
06-12-05 [Riberales] Creacion
16-09-07 [Angor] Movido a posada/lobomar/ . Cambiadas las descripciones.
*/

#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <nightday.h>
inherit ROOM;

public int QueryEntrada() { return 1; }

public create()
{
    ::create();

    SetIntShort("la entrada a la posada Lobo de Mar");
    SetIntLong(
	"Esta es la entrada a la posada Lobo de Mar en Azzor, una peque�a "
        "estancia de techo bajo y paredes de madera. Un viejo farol "
        "de hierro cuelga del techo iluminando el lugar. Junto a la pared, "
        "una recia escalera lleva al piso superior. Dos arcos de madera, al "
        "norte y al este conducen otras estancias de la posada.\n");
        
   AddDetail(({"farol"}),
        "El farol es una caja con caras de vidrio y aristas met�licas. La vela "
        "que arde en su interior esta as� protegida de los golpes de viento que "
        "entran del exterior del edificio.\n");
    AddDetail(({"escalera","escaleras"}),
        "Son unas recias escaleras de madera ancladas en la pared que "
        "ascienden a la planta superior de la posada, donde se "
        "encuentran las habitaciones para los hu�spedes.\n");
    SetIntBright(45);
    AddExit("oeste",AZ_POSADA("lobomar/sala_descanso"));
    AddExit("norte",AZ_POSADA("lobomar/taberna"));
    AddExit("este",AZ_PUERTO("portico01"));
    AddExit("arriba",AZ_POSADA("lobomar/descansillo"));
    AddDoor("norte","la puerta de la taberna",
        "La puerta no es muy gruesa. Est� hecha de madera pulida. En su parte superior tiene "
            "un panel de cristal. Supones que al ser interior, no precisa ser muy resistente.\n",
        ({"puerta","puerta norte","puerta de taberna","puerta de la taberna"}),GENDER_FEMALE,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:({ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON}),
        P_DOOR_CANT_OPEN_MSG:({({"Molly se fu� a dormir de madrugada, "
            "y no volver� hasta el mediod�a, a servir..., comida.\n","Tratas de abrir la "
            "puerta en la oscuridad, pero no consigues encontrar la manija.\n"}),({"@nombre@ "
            "pensaba meterse un lingotazo, pero la taberna est� cerrada...\n","Oyes a alguien "
            "removerse, jurando en la oscuridad.\n"}),
            "Parece que alguien trata de abrir la puerta.\n"})]));
    SetLocate("ciudad de Azzor");
}
