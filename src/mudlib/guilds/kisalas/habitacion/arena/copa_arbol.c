/****************************************************************************
Fichero: copa_arbol.c
Autor: Kastwey
Fecha: 01/03/2006
Descripci�n:
Una de las copas de los �rboles del gremio de las kisalas
****************************************************************************/


#include <nightday.h>
#include <moving.h>
#include <skills.h>
#include "path.h"

#define SALTAR ({"al otro �rbol", "al otro arbol", "derecha", "este", "al este",\
                 "al arbol", "al �rbol", "�rbol", "arbol", "al arbol del este",\
                 "al �rbol del este", "al arbol de la derecha", "al �rbol de \
                 la derecha"})


inherit AM_ARENA("arena_base");

int cmd_saltar (string str)
{
    int hab;
    object pl;
    if (!str ||member(SALTAR, str) < 0)
    {
        return notify_fail("�Saltar a d�nde?\n", NOTIFY_NOT_VALID);
    }

    if ((pl = TP)->QueryTP() < 5)
    {
        return notify_fail("Est�s demasiado cansada para saltar ahora.\n",
                           NOTIFY_NOT_VALID);
    }
    if (  pl->QuerySkillLevel(HAB_SALTAR)
        > pl->QueryMaxSkillLevel(HAB_SALTAR) * 25 / 100)
    // Ha superado el 25% del m�ximo de su habilidad... As� que trepa sin
    // problemas, pero tampoco la usa
    {
        pl->move(AM_ARENA("copa_arbol2"), M_SPECIAL,
                 ({"salta con agilidad y precisi�n, cayendo limpiamente en la "
                   "plataforma de la otra copa del �rbol",
                   "llega saltando desde el �rbol de la derecha",
                   "Con un movimiento fluido, saltas hacia el otro �rbol... "
                   "Caes l�mpiamente en la plataforma de la otra copa"}));
        pl->AddTP(-5);
        return 1;
    }
    switch(pl->UseSkill(HAB_SALTAR))
    {
        case -50..-21:
        // casi, pero no
             pl->move(AM_ARENA("arena4"), M_SPECIAL,
                      ({"salta hacia la copa del otro �rbol. Parece que va a "
                        "llegar...\n"
                        ".................................................\n"
                        "Pero finalmente, se queda a escasos cent�metros de la "
                        "misma. Sin poder evitarlo, resbala por las ramas del "
                        "�rbol hasta caer en la red.\n",
                        "cae desde lo alto de un �rbol",
                        "Saltas con todas tus fuerzas hacia la copa del otro "
                        "�rbol... Parece que vas a conseguir llegar...\n"
                        ".................................................\n"
                        "Pero finalmente te quedas a escasos cent�metros de la "
                        "plataforma. Resbalas por el ramaje del �rbol hasta "
                        "que tu ca�da se detiene gracias a la red"}));
             break;
        case -20..100:
        // lo consigue
             pl->move(AM_ARENA("copa_arbol2"), M_SPECIAL,
                      ({"salta hacia la otra copa del �rbol... Parece que va a llegar...\n"
                        ".................................................\n"
                        "Y finalmente cae justo en el borde de la plataforma",
                        "llega saltando desde el �rbol de al lado",
                        "Saltas con todas tus fuerzas hacia la copa del otro "
                        "�rbol... Parece que vas a conseguir llegar...\n"
                        ".................................................\n"
                        "�Caes justo en el borde de la plataforma! Por los pelos, "
                        "pero lo conseguiste"}));
             break;
        default:
        // no lo consigue, desde menos infinito hasta -50
             pl->move(AM_ARENA("arena4"), M_SPECIAL,
                      ({"salta hacia la otra copa del �rbol. Sin embargo, el "
                        "salto es realmente desastroso, y termina cayendo al "
                        "vac�o",
                        "cae desde lo alto de un �rbol",
                        "Saltas hacia la plataforma del �rbol de al lado. Sin "
                        "embargo, no calculas bien, y a una velocidad "
                        "escalofriante, te precipitas al vac�o... Menos mal que "
                        "antes de llegar al suelo tienes la red, que amortigua tu "
                        "ca�da y no te haces ni un rasgu�o"}));
    }
    pl->AddTP(-5);
    return 1;
}




private string desc_larga()
{
    object server = load_object(QueryServer());
    int estado;
    string msg = "Est�s sobre una plataforma en la copa de uno de los �rboles "
                 "m�s altos de la isla del gremio de las kisalas. ";
    if (estado = server->QueryState() == ND_NIGHT || estado == ND_PREDAWN)
    // es de noche, as� que no se ve mucho
    {
        return msg + "Posiblemente durante el d�a podr�as ver mucho m�s, pero "
                     "lo que es ahora, s�lo llegas a vislumbrar algo del bosque "
                     "que tienes a tu alrededor: �rboles, �rboles y m�s �rboles. "
                     "El �rbol que tienes a tu derecha est� casi a la misma "
                     "altura que este en el que te encuentras... Quiz�s podr�as "
                     "saltar hasta �l.\n";
    }
    return msg + "Desde esta posici�n privilegiada, puedes observar toda la isla "
                 "en la que te encuentras, el lago que la rodea, y m�s all�, "
                 "los impenetrables bosques de Goldhai. El �rbol que tienes a "
                 "tu derecha est� casi a la misma altura que este en el que "
                 "te encuentras... Quiz�s podr�as saltar hasta �l.\n";
}



private string detalle_horizonte()
{
    object server = load_object(QueryServer());
    int estado;
    if (estado = server->QueryState() == ND_NIGHT || estado == ND_PREDAWN)
    {
        return "Miras hacia el horizonte, pero con la oscuridad de la noche "
               "no ves m�s all� de pocos metros. El �rbol que tienes a tu "
               "izqierda, casi a la misma altura que este en el que te encuentras, "
               "y los otros �rboles que pueblan todo este bosque, son las "
               "�nicas cosas que consigues divisar.\n";
    }
    return "Miras hacia el horizonte y observas las aguas del lago que rodea a "
    "este islote, as� como los bosques tanto de esta isla como la de Goldhai... "
    "La verdad es que poco m�s se puede ver por aqu�.\n";
}


create()
{
    ::create();
    SetIntShort("la copa de un �rbol");
    SetIntLong(SF(desc_larga));
    AddDetail("horizonte",SF(detalle_horizonte));
    AddDetail(({"derecha","arbol de la derecha","�rbol de la derecha",
                "este", "�rbol","arbol"}), "Es un �rbol casi tan grande como este "
                "en el que est�s. Tambi�n tiene dispuestas varias cuerdas por "
                "su tronco, lo que permitir� sin duda un ascenso y descenso "
                "relativamente sencillo. Estos dos �rboles no est�n muy lejos "
                "entre s�... quiz�s podr�as "
                "intentar saltar hasta el otro.\n");

    AddRoomCmd("saltar","cmd_saltar");

    AddExit("abajo",(:TP->move(AM_ARENA("arena3"),M_SPECIAL,
                               ({"baja con cuidado del �rbol agarr�ndose de las "
                                 "cuerdas dispuestas por todo el tronco",
                                 "llega descendiendo desde la copa del �rbol",
                                 "Te agarras del tronco y de las cuerdas que en "
                                 "�l hay dispuestas, y con infinito cuidado "
                                 "comienzas a descender... Al poco, llegas al "
                                 "suelo"})):));

}



