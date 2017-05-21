/*****************************************************************************************
 ARCHIVO:       robledal06.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Sendero a través del robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un sendero cerca de la posada");
    SetIntLong("Los altos muros de 'El Unicornio Azul' se alzan desafiando la dureza de "
        "la niebla. A tu alrededor todo es una confusa mezcla de colores verdes y "
        "pálidos. Puedes seguir el sendero hacia el este y sur o llegar hacia un grupo "
        "de rocas situado al sudeste. Los árboles y las paredes de la posada te impiden "
        "avanzar en cualquier otra dirección.\n");
    AddDetail("niebla", "Sume a toda la isla como en una nube gigante.\n");
    AddDetail("suelo", "Las pocas piedras que quedan en su sitio son "
        "de granito y parecen resbaladizas.\n");
    AddDetail(({"senderillo", "sendero"}), "A tus pies, no ves más que un pequeño "
        "senderillo que alguna vez estuvo adoquinado.\n");
    AddDetail(({"losas", "piedras"}), "Son de granito y empiezan a tomar un color "
        "verdoso.\n");
    AddDetail(({"rocas", "grupo de rocas"}), "Parecen de color negro y están bastante "
        "elevadas.\n");
    AddDetail(({"arboles", "árboles"}), "En algunas zonas se aprietan fuertemente unos "
        "contra otros, cerrándote el paso.\n");
    AddDetail(("paredes", "muros"), "Son los muros de la posada, son de piedra y muy "
        "altos.");

    SetIntSmell("Un olor dulzón y penetrante, fruto de la descomposición de la materia "
        "vegetal, y del olor desprendido por los árboles y plantas.\n");
    SetIntNoise("Escuchas ligeros crujidos de ramas.\n");

    AddExit("este", HAB_BOSQUE_ISLA("robledal07.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal02.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal03.c"));
}
