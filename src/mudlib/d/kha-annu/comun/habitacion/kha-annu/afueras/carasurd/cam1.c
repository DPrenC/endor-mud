/*
DESCRIPCION: Cordillera sur de Kha-annu
ARCHIVO: /d/Kha-annu/comun/habitacion/Kha-annu/afueras/carasurd/cam1.c
CREACION: 14-10-2001 [Alura]
MODIFICACION:
*/

#include "./path.h"
#include <moving.h>
#include <combat.h>
#include <skills.h>

#define TREPAR ({"por pared","por la pared","por roca","por la roca",\
"la roca","la pared","roca","pared","por rocas","por las rocas","rocas"})
inherit KHA_ROOM;

/*
por ahora, esto se quita hasta que no se ponga annufam

// trepar al sendero de inicio de Annufam
int cmd_trepar(string str)
{
    object botas, pl;
    int danyo;
    // daño que se hará si se cae. Si es 0 es que escala bien.
    if (!str || member(TREPAR,str) < 0) return notify_fail(query_verb() + " por dónde?\n",
        NOTIFY_NOT_VALID);
    pl = TP;
    if (!botas = present("botas_escalada",TP))
    // no lleva botas puestas, ni siquiera en el inventario
    {
        write("Comienzas a escalar la lisa pared. Sin embargo, no llevas un "
            "calzado apropiado y caes.\n");
        say(CAP(TNAME) + " comienza a escalar la escarpada pared. Sin "
            "embargo, ves como sus pies resbalan en la lisa roca y cae al "
            "suelo.\n",pl);
        danyo = 5 + random(11);
    }
    else if (botas && member(pl->QueryArmours(),botas) < 0)
    // tiene las botas en el inventario pero no puestas
    {
        write("Cuando comienzas a escalar la pared, te das cuenta de que "
            "llevar las botas de escalada en las manos no te va a servir de "
            "mucho. Irremediablemente, por lo escarpado de la roca y por "
            "el poco agarre que puedes conseguir, terminas cayendo al "
            "suelo.\n");
        say(CAP(TNAME) + " comienza a escalar la pared con grandes "
            "dificultades. Realmente no sabes para qué lleva esas botas de "
            "escalada en las manos en vez de ponérselas... Confirmando lo "
            "desacertado de esa decisión, ves como sus pies pierden asidero "
            "en la roca y se precipita al vacío.\n",pl);
        danyo = 10 + random(6);
        // aquí el daño aumenta, por idiota y no ponerse las botas, XDDD.
    }
    else
    // lleva las botas puestas
    {
        int hab = pl->UseSkill(HAB_TREPAR);
        // dtell("kastwey",sprintf("hab: %d.\n",hab));
        if (hab < -50)
        // desastroso
        {
            write("Comienzas a escalar la pared. Sin embargo, tu "
                "inexperiencia hace que tus pies resbalen y caigas "
                "al duro suelo.\n");
            say(CAP(TNAME) + " comienza a escalar la pared, pero sus pies "
                "resbalan y cae al suelo.\n",pl);
            danyo = 1 + random(5);
            // poco daño, que no le ha dado tiempo ni a subir un poquito ;)
        }
        else if (hab < -20)
        // desastroso, pero ya no tanto
        {
            write("Comienzas a escalar la pared. Sin embargo, y pese al "
                "agarre extra que te proporcionan las botas, te da por "
                "mirar abajo, te pones nervios" + AO + ", las piernas "
                "comienzan a temblarte, y, finalmente, tus pies pierden "
                "contacto con la roca y te precipitas de espaldas al "
                "suelo.\n");
            say(CAP(TNAME) + " comienza a escalar la pared. De pronto, "
                "observas como mira hacia abajo, su semblante palidece, y "
                "finalmente, sus pies parecen no querer colaborar en la "
                "tarea y termina precipitándose de espaldas al suelo.\n",pl);
            danyo = 10 + random(15);
            // esta vez ya ha tenido tiempo de escalar lo suficiente para darse
            // una buena ostia.
        }
        else if (hab < 10)
        // casi, casi, pero no!
        {
            write("Comienzas a escalar la pared. Procurando no mirar abajo, "
                "plantas los pies fírmemente en las rocas. Sin embargo, y "
                "cuando ya estás casi divisando la cima, apoyas mal un pie, "
                "y horrorizad" + AO + ", notas como pierdes asidero en la "
                "roca y te precipitas al vacío...\n\nToda tu vida te pasa por "
                "la mente en cuestión de segundos...\n"
                "..................................\n\n");
            say(CAP(TNAME) + " comienza a escalar la escarpada pared. Cuando "
                "está a punto de coronar la cima, ves como uno de sus pies "
                "pierde asidero en la roca, y sin poder evitarlo, el cuerpo "
                "le sigue en una escalofriante caída.\n",pl);
            danyo = 30 + random(30);
            // este daño es jodido... la pared es alta de verdad, las cosas
            // como son, XDDD.
        }
    }
    if (danyo)
    // hay daño, así que llamamos a Defend para que lo haga
    {
        pl->SetAttribute("intentos_escalar_pared_annufam",
            pl->QueryAttribute("intentos_escalar_pared_annufam") + 1);
        pl->Defend(danyo, DT_BLUDGEON,
            DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
        return 1;
    }
    pl->RemoveAttribute("intentos_escalar_pared_annufam");
    pl->move(HAB_SENDERO_ANNUFAM("sendero1"),M_SPECIAL,
        ({"comienza a escalar la escarpada pared. Aunque en más de "
            "una ocasión parece que se terminará cayendo al vacío, "
            "finalmente consigue llegar a lo alto",
        "llega trepando por la pared",
        "Comienzas a escalar la lisa roca. Las botas que calzas "
            "hacen que te agarres bien a la pared y puedas ascender "
            "poco a poco.\n"}));
    return 1;
}

*/

create()
{
    ::create();
    SetIntShort("las montañas de Kha-annu");
    SetIntLong("Este camino está excavado en las montañas que forman la cordillera sureste de "
        "Kha-annu. Las paredes de la montaña están recubiertas de espesos pinos y hayas "
        "cobrizas por la parte superior, pero en la parte baja la roca está pelada.\n");
    SetIndoors(0);
    SetIntNoise("El viento que azota fuerte tu cara te impide escuchar nada con "
        "claridad.\n");
    SetIntSmell("Tu olfato no capta nada especial en este lugar.\n");
    AddDetail(({"camino","carretera"}),"Es el camino por donde has llegado hasta aquí.\n");
    AddDetail(({"roca","pared"}),"La roca de la parte inferior de la montaña es casi vertical "
        "y muy lisa. Te va a suponer un arduo trabajo si estás pensando escalarla, a no ser "
        "que tengas el equipo adecuado.\n");
    // por ahora, nada de esto
    // AddRoomCmd(({"trepar","escalar"}),"cmd_trepar");
    AddExit("sur",PUERTANOR + "entrada");
    AddExit("norte","cam2");
    SetLocate("Kha-annu");
}
