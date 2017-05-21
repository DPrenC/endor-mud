/****************************************************************************
Fichero: copa_arbol.c
Autor: Kastwey
Fecha: 01/03/2006
Descripción:
Una de las copas de los árboles del gremio de las kisalas
****************************************************************************/


#include <nightday.h>
#include <moving.h>
#include <skills.h>
#include "path.h"

#define SALTAR ({"al otro árbol", "al otro arbol", "derecha", "este", "al este",\
                 "al arbol", "al árbol", "árbol", "arbol", "al arbol del este",\
                 "al árbol del este", "al arbol de la derecha", "al árbol de \
                 la derecha"})


inherit AM_ARENA("arena_base");

int cmd_saltar (string str)
{
    int hab;
    object pl;
    if (!str ||member(SALTAR, str) < 0)
    {
        return notify_fail("¿Saltar a dónde?\n", NOTIFY_NOT_VALID);
    }

    if ((pl = TP)->QueryTP() < 5)
    {
        return notify_fail("Estás demasiado cansada para saltar ahora.\n",
                           NOTIFY_NOT_VALID);
    }
    if (  pl->QuerySkillLevel(HAB_SALTAR)
        > pl->QueryMaxSkillLevel(HAB_SALTAR) * 25 / 100)
    // Ha superado el 25% del máximo de su habilidad... Así que trepa sin
    // problemas, pero tampoco la usa
    {
        pl->move(AM_ARENA("copa_arbol2"), M_SPECIAL,
                 ({"salta con agilidad y precisión, cayendo limpiamente en la "
                   "plataforma de la otra copa del árbol",
                   "llega saltando desde el árbol de la derecha",
                   "Con un movimiento fluido, saltas hacia el otro árbol... "
                   "Caes límpiamente en la plataforma de la otra copa"}));
        pl->AddTP(-5);
        return 1;
    }
    switch(pl->UseSkill(HAB_SALTAR))
    {
        case -50..-21:
        // casi, pero no
             pl->move(AM_ARENA("arena4"), M_SPECIAL,
                      ({"salta hacia la copa del otro árbol. Parece que va a "
                        "llegar...\n"
                        ".................................................\n"
                        "Pero finalmente, se queda a escasos centímetros de la "
                        "misma. Sin poder evitarlo, resbala por las ramas del "
                        "árbol hasta caer en la red.\n",
                        "cae desde lo alto de un árbol",
                        "Saltas con todas tus fuerzas hacia la copa del otro "
                        "árbol... Parece que vas a conseguir llegar...\n"
                        ".................................................\n"
                        "Pero finalmente te quedas a escasos centímetros de la "
                        "plataforma. Resbalas por el ramaje del árbol hasta "
                        "que tu caída se detiene gracias a la red"}));
             break;
        case -20..100:
        // lo consigue
             pl->move(AM_ARENA("copa_arbol2"), M_SPECIAL,
                      ({"salta hacia la otra copa del árbol... Parece que va a llegar...\n"
                        ".................................................\n"
                        "Y finalmente cae justo en el borde de la plataforma",
                        "llega saltando desde el árbol de al lado",
                        "Saltas con todas tus fuerzas hacia la copa del otro "
                        "árbol... Parece que vas a conseguir llegar...\n"
                        ".................................................\n"
                        "¡Caes justo en el borde de la plataforma! Por los pelos, "
                        "pero lo conseguiste"}));
             break;
        default:
        // no lo consigue, desde menos infinito hasta -50
             pl->move(AM_ARENA("arena4"), M_SPECIAL,
                      ({"salta hacia la otra copa del árbol. Sin embargo, el "
                        "salto es realmente desastroso, y termina cayendo al "
                        "vacío",
                        "cae desde lo alto de un árbol",
                        "Saltas hacia la plataforma del árbol de al lado. Sin "
                        "embargo, no calculas bien, y a una velocidad "
                        "escalofriante, te precipitas al vacío... Menos mal que "
                        "antes de llegar al suelo tienes la red, que amortigua tu "
                        "caída y no te haces ni un rasguño"}));
    }
    pl->AddTP(-5);
    return 1;
}




private string desc_larga()
{
    object server = load_object(QueryServer());
    int estado;
    string msg = "Estás sobre una plataforma en la copa de uno de los árboles "
                 "más altos de la isla del gremio de las kisalas. ";
    if (estado = server->QueryState() == ND_NIGHT || estado == ND_PREDAWN)
    // es de noche, así que no se ve mucho
    {
        return msg + "Posiblemente durante el día podrías ver mucho más, pero "
                     "lo que es ahora, sólo llegas a vislumbrar algo del bosque "
                     "que tienes a tu alrededor: árboles, árboles y más árboles. "
                     "El árbol que tienes a tu derecha está casi a la misma "
                     "altura que este en el que te encuentras... Quizás podrías "
                     "saltar hasta él.\n";
    }
    return msg + "Desde esta posición privilegiada, puedes observar toda la isla "
                 "en la que te encuentras, el lago que la rodea, y más allá, "
                 "los impenetrables bosques de Goldhai. El árbol que tienes a "
                 "tu derecha está casi a la misma altura que este en el que "
                 "te encuentras... Quizás podrías saltar hasta él.\n";
}



private string detalle_horizonte()
{
    object server = load_object(QueryServer());
    int estado;
    if (estado = server->QueryState() == ND_NIGHT || estado == ND_PREDAWN)
    {
        return "Miras hacia el horizonte, pero con la oscuridad de la noche "
               "no ves más allá de pocos metros. El árbol que tienes a tu "
               "izqierda, casi a la misma altura que este en el que te encuentras, "
               "y los otros árboles que pueblan todo este bosque, son las "
               "únicas cosas que consigues divisar.\n";
    }
    return "Miras hacia el horizonte y observas las aguas del lago que rodea a "
    "este islote, así como los bosques tanto de esta isla como la de Goldhai... "
    "La verdad es que poco más se puede ver por aquí.\n";
}


create()
{
    ::create();
    SetIntShort("la copa de un árbol");
    SetIntLong(SF(desc_larga));
    AddDetail("horizonte",SF(detalle_horizonte));
    AddDetail(({"derecha","arbol de la derecha","árbol de la derecha",
                "este", "árbol","arbol"}), "Es un árbol casi tan grande como este "
                "en el que estás. También tiene dispuestas varias cuerdas por "
                "su tronco, lo que permitirá sin duda un ascenso y descenso "
                "relativamente sencillo. Estos dos árboles no están muy lejos "
                "entre sí... quizás podrías "
                "intentar saltar hasta el otro.\n");

    AddRoomCmd("saltar","cmd_saltar");

    AddExit("abajo",(:TP->move(AM_ARENA("arena3"),M_SPECIAL,
                               ({"baja con cuidado del árbol agarrándose de las "
                                 "cuerdas dispuestas por todo el tronco",
                                 "llega descendiendo desde la copa del árbol",
                                 "Te agarras del tronco y de las cuerdas que en "
                                 "él hay dispuestas, y con infinito cuidado "
                                 "comienzas a descender... Al poco, llegas al "
                                 "suelo"})):));

}



