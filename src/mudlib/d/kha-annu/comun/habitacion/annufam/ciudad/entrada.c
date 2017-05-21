/****************************************************************************
Fichero: entrada.c
Autor: Kastwey
Creación: 24/07/2005
Descripción: Entrada de la ciudad de Annufam
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <combat.h>
#include <skills.h>

#define AVENIDA_PORTON (HAB_AVENIDA_ANNUFAM("avenida_01.c"))
#define FOSO           ({"al foso","a foso","foso"})
#define LANZAR ({"cuerda al porton","cuerda a porton","cuerda al portón",\
"cuerda a portón","la cuerda al porton","la cuerda al portón","la cuerda a \
porton","la cuerda a portón","cuerda a la muralla","cuerda a muralla",\
"la cuerda a la muralla","la cuerda a muralla","la cuerda a las almenas",\
"la cuerda a la almena","cuerda a las almenas","cuerda a la almena",\
"cuerda a murallas","cuerda a las murallas","la cuerda a murallas",\
"la cuerda a las murallas"})

#define DESENGANCHAR  ({"cuerda","cuerda de muralla","cuerda de la muralla",\
"la cuerda","la cuerda de muralla","la cuerda de la muralla",\
"cuerdas","cuerdas de muralla","cuerdas de la muralla","las cuerdas",\
"las cuerdas de muralla","las cuerdas de la muralla","cuerda de murallas",\
"cuerda de las murallas","la cuerda de las murallas","las cuerdas de murallas",\
"las cuerdas de las murallas"})

#define TREPAR ({"cuerda","por cuerda","por la cuerda","a muralla",\
"a la muralla","por muralla","por la muralla","muralla"})

inherit BASE_CIUDAD_ANNUFAM;


object pMurallas, pAvenidaPorton;

public object QueryMurallas()
{
    if (!pMurallas) pMurallas = load_object(HAB_MURALLAS_ANNUFAM("murallas_33"));
    return pMurallas;
}

int entrar_ciudad();


object CuerdaEnganchada(object pl)
// devuelve 0 si no tiene ninguna cuerda enganchada a la muralla, y el objeto
// cuerda en cuestión, si sí hay
{
    object *cuerda;
    cuerda = filter(all_inventory(pl),(:   $1->id("cuerda_engarfiada")
                                        && $2->EstaEnMuralla($1):),QueryMurallas());
    return sizeof(cuerda) ? cuerda[0]: 0;
}

public void notify_leave(mixed to, int method, mixed extra)
{
    object cuerda;
    object pl = PO ||TP;
    ::notify_leave(to,method,extra);
    if (!living(pl)) return;
    if (   to != HAB_FOSO_ANNUFAM("foso_01")
        && to != HAB_MURALLAS_ANNUFAM("murallas_33")
        && cuerda = CuerdaEnganchada(pl))
    {
        QueryMurallas()->SoltarCuerda(cuerda);
        tell_object(pl,"Sueltas la cuerda que mantenías enganchada a lo "
                       "alto de la muralla.\n");
        tell_room(TO,CAP(pl->QueryName()) + " suelta la cuerda que mantenía "
                     "enganchada a lo alto de la muralla.\n",({pl}));
    }
    TP->RemoveAttribute("saltar_foso_annufam");
}



int QueryPortonAbierto()
{
    return (int)(pAvenidaPorton ? pAvenidaPorton :
                 load_object(AVENIDA_PORTON))->QueryPortonAbierto();
}


void caer(string room, string player)
{
    TP->move(HAB_FOSO_ANNUFAM("foso_01"),M_SPECIAL,
             ({"se agarra a la cuerda, y sin pensárselo dos veces, salta al "
               "vacío, quedando colgad" + AO + " por encima del foso. "
               "Cuando consigue acercarse a una de las paredes del mismo, "
               "apoya los pies en ella y comienza a trepar ayudándose con la "
               "cuerda. " + room,
               "cae de espaldas desde algún punto por encima de tu cabeza",
               "Sujetas fuertemente la cuerda y te lanzas al foso. Te "
               "balanceas sobre el abismo hasta llegar a la otra pared, y una "
               "vez allí, apoyas los pies en la muralla y te impulsas hacia arriba con "
               "ayuda de la cuerda. " + player}));
}

int cmd_trepar(string str)
{
    int hab, danyo, num_cuerdas;
    object cuerda;


    if (!str ||member(TREPAR,str) < 0)
    {
        return notify_fail("¿" + CAP(query_verb()) + " por dónde?\n",
                           NOTIFY_NOT_VALID);
    }
    if (QueryPortonAbierto())
    // para qué trepar
    {
        return notify_fail("¿Para qué trepar por las murallas si está el "
                           "portón abierto?",NOTIFY_NOT_VALID);
    }

    if (!num_cuerdas = QueryMurallas()->QueryNumCuerdasEnMuralla())
    {
        return notify_fail("Miras la muralla, luego el foso que se abre ante "
                           "ti, te rascas la cabeza, y piensas que quizás "
                           "con algo a lo que agarrarse podrías trepar por "
                           "ahí.\n",NOTIFY_NOT_VALID);
    }

    if (!cuerda = CuerdaEnganchada(TP))
    // el player no tiene ninguna cuerda sujeta y enganchada a las murallas
    {
        string s = num_cuerdas > 1 ?"s":"";
        return notify_fail("El foso que te separa de la muralla, te hace "
                           "imposible coger la" + s + " cuerda" + s +
                           " enganchada" + s + " en la misma.\n",
                           NOTIFY_NOT_VALID);
    }
    hab = TP->UseSkill(HAB_TREPAR);
    // si lleva puesta botas de escalada, se añade una bonificación al uso
    // de la habilidad
    if (sizeof(filter(TP->QueryArmours() ||({}),(:$1->id("botas_escalada"):))))
    {
        hab += 50;
    }

    // dependiendo de lo habilidoso que sea trepando, lo conseguirá
    // o no lo conseguirá...
    if (hab < -50)
    // desastroso desastroso.... tanto, que se cae al foso ;)
    {
        caer("Sin embargo, la cuerda se le resbala, y sus pies pierden "
             "contacto con la pared. Irremisiblemente, se precipita de "
             "espaldas al foso",
             "Sin embargo, la cuerda se te resbala y tus pies pierden "
             "contacto con la pared. Irremisiblemente, caes de espaldas "
             "al foso...\n"
             "................................................................\n"
             "Toda tu vida te pasa por la mente en unos segundos..");
        danyo = 20 + random(11);
    }
    else if (hab < -20)
    // desastroso, pero ya un poco menos... Desgraciadamente,
    // antes de caer llega más arriba de la muralla, por lo que el
    // porrazo es más grande, XDD.
    {
        caer("Con esfuerzo, va ascendiendo léntamente. Desgraciadamente, la "
             "cuerda se le resbala, y aunque por unos momentos parece que "
             "conseguirá volver a agarrarla, la fuerza de la gravedad le "
             "juega una mala pasada, y cae al vacío",
             "Asciendes léntamente y con cuidado...\n"
             "Sin saber como, la cuerda se te resbala. Intentas volver a "
             "agarrarla, pero la gravedad no parece estar de tu parte, y sin "
             "poder evitarlo, caes al vacío...\n"
             ".................................................................\n"
             "Toda tu vida te pasa por la mente en cuestión de segundos..");
        danyo = 30 + random(21);
    }
    else if (hab < 0)
    // ¡casi! ¡caasi! pero no!
    // el daño es mayor... ya está casi arriba!
    {
        caer("Poco a poco asciende impulsándose con pies y manos. Cuando "
             "ya casi está en el borde superior, las piernas se le doblan y "
             "queda colgando de los brazos. Aunque intenta volver a conseguir "
             "el punto de apoyo, finalmente comienza a escurrirse por "
             "la cuerda, y tras unos segundos de lento descenso, termina "
             "por soltarla, y cae al vacío",
             "Te impulsas hacia arriba con pies y manos, y poco a poco "
             "vas ganando terreno. Cuando ya vislumbras el borde superior "
             "del muro, te flaquean las piernas y pierdes el contacto "
             "con la pared. Colgando de los brazos, intentas sostenerte de "
             "la cuerda, pero tras unos angustiosos segundos, comienzas a "
             "caer...\n"
             "............................................................................\n"
             "Toda tu vida te pasa por la mente en segundos..");
        danyo = 40 + random(21);
    }
    else
    // lo consigue!
    {
        TP->move(HAB_MURALLAS_ANNUFAM("murallas_33"),M_SPECIAL,
                 ({"se agarra fuertemente a la cuerda y salta al foso. "
                   "Colgad" + AO + " sobre el abismo, se balancea hasta "
                   "llegar a la pared de la muralla. Apoyando los pies en "
                   "la muralla, comienza a impulsarse hacia "
                   "arriba con ayuda de la cuerda. Poco a poco va ascendiendo, "
                   "hasta que l" + AO + " ves llegar a la parte superior",
                   "asoma la cabeza por el borde de la muralla, y ayudándose "
                   "con los brazos, se iza por completo",
                   "Sujetas fuertemente la cuerda y saltas al foso. Colgad" +
                   AO + " sobre el vacío te balanceas hasta llegar a la pared "
                   "de la muralla. Apoyas los pies en la misma y comienzas a "
                   "impulsarte hacia arriba con ayuda de la cuerda. Poco a "
                   "poco vas ganando terreno, hasta que por fin vislumbras la "
                   "cima del enorme muro. Apoyándote en él y con tus últimas "
                   "fuerzas, consigues izarte a la parte superior mientras la "
                   "cuerda se te resbala y queda colgando en la muralla"}));
        QueryMurallas()->SoltarCuerda(cuerda);
    }
    if (danyo)
    // se le infringe el daño especificado en danyo
    TP->Defend(danyo, DT_BLUDGEON,
               DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
    QueryMurallas()->SoltarCuerda(cuerda);
    return 1;
}



int cmd_desenganchar(string str)
{
    if (!QueryMurallas()->QueryNumCuerdasEnMuralla()) return 0;
    if (!str || member(DESENGANCHAR,str) < 0)
    {
        return notify_fail("¿Desenganchar qué de dónde?\n",NOTIFY_NOT_VALID);
    }
    return notify_fail("De la muralla te separa un bonito foso... Después de "
                       "todo, piensas que no es tan buena idea hacer eso.\n",
                       NOTIFY_NOT_VALID);
}


int cmd_lanzar(string str)
// lanzar la cuerda a las almenas
{
    object cuerda;
    int hab;

    if (!str || member(LANZAR,str) < 0)
    {
        return notify_fail("¿Lanzar qué dónde?\n",NOTIFY_NOT_VALID);
    }
    if (QueryMurallas()->QueryNumCuerdasEnMuralla() > 10)
    {
        return notify_fail("Miras las diez cuerdas que permanecen enganchadas "
                           "a las murallas y te das cuenta que no hay más "
                           "sitio para lanzar ni una más.\n",NOTIFY_NOT_VALID);
    }


    if (!(cuerda = present("cuerda_engarfiada",TP)))
    // no tiene cuerda
    {
        if (!present("cuerda",TP))
        {
            return notify_fail("No tienes ninguna cuerda para lanzar a las "
                               "murallas.\n",NOTIFY_NOT_VALID);
        }
        else
        // la cuerda no es la apropiada
        {
            return notify_fail("No crees que esta sea la cuerda "
                               "apropiada para intentar la escalada.\n",
                               NOTIFY_NOT_VALID);
        }
    }
    if (QueryMurallas()->EstaEnMuralla(cuerda))
    // esta cuerda ya está enganchada en las murallas
    {
        return notify_fail("La cuerda ya está enganchada a las murallas.\n",
                           NOTIFY_NOT_VALID);
    }
    else if (CuerdaEnganchada(TP))
    {
        return notify_fail("Ya tienes una cuerda sujeta y enganchada a la "
                           "muralla. ¿Para qué lanzar otra?\n",NOTIFY_NOT_VALID);
    }

    hab = TP->UseSkill(HAB_LANZAR);
    // dependiendo de la habilidad en lanzar la cuerda, ocurrirá una cosa u
    // otra
    if (hab < -50)
    // desastroso, por decirlo en modo suave :P
    {
        write("Lanzas la cuerda con todas tus fuerzas. Sin embargo, de alguna "
              "forma te las apañas para que la cuerda describa un extraño "
              "arco y ni siquiera toque la muralla.\n");
        say(CAP(TNAME) + " lanza una cuerda hacia las murallas. Sin embargo, "
            " esta describe un extraño arco y ni siquiera roza la "
            "pared.\n");
        return 1;
    }
    else if (hab < -20)
    // menos desastroso pero aún no
    {
        write("Lanzas con todas tus fuerzas la cuerda hacia lo alto de "
              "la muralla. Sin embargo, el garfio rebota en ella y vuelve a "
              "caer al suelo.\n");
        say(CAP(TNAME) + " lanza una cuerda hacia la muralla, pero el garfio "
            "rebota en ella y vuelve a caer al suelo.\n");
        return 1;
    }
    else if (hab < 0)
    // caasi! casi!
    {
        write("Lanzas con todas tus fuerzas la cuerda hacia lo alto "
              "de la muralla. El garfio casi se engancha en una de las almenas, "
              "pero finalmente, se suelta y vuelve a caer al suelo.\n");
        say(CAP(TNAME) + " lanza una cuerda hacia lo alto de la muralla. "
            "Observas como el garfio casi se engancha en una de las "
            "almenas, pero, finalmente, se suelta y cae al suelo.\n");
        return 1;
    }
    // bien! lo consigue!
    write("Lanzas la cuerda con todas tus fuerzas hacia lo alto de la "
          "muralla. Observas esperanzad" + AO + " como el garfio se dirige "
          "certeramente hacia una de las almenas, y ... ¡consigues "
          "engancharlo!\n");
    say(CAP(TNAME) + " lanza una cuerda hacia lo alto de la muralla. Con "
        "sorprendente precisión, el garfio se engancha en una de las "
        "almenas.\n");
    QueryMurallas()->EngancharCuerdaEnMuralla(cuerda);
    return 1;
}






int cmd_saltar(string str)
{
    object cuerda;

    if(!str || member(FOSO,str) < 0)
    {
        return notify_fail("¿Saltar a dónde?\n",NOTIFY_NOT_VALID);
    }
    if (QueryPortonAbierto())
    {
        return notify_fail("Como no pretendas atravesar el portón, no creo "
                           "que haya otra forma de llegar al foso sin "
                           "antes cerrarlo.\n",NOTIFY_NOT_VALID);
    }
    if (!TP->QueryAttribute("saltar_foso_annufam"))
    {
        write("Supongo que no has querido poner eso, ¿no? Vuelve a escribir "
              "lo mismo, si realmente deseas hacerlo.\n");
        TP->SetAttribute("saltar_foso_annufam",1);
        return 1;
    }
    if (cuerda = CuerdaEnganchada(TP))
    // tiene que soltar la cuerda
    {
        write("Para darle más emoción al asunto, sueltas la cuerda que "
              "tienes enganchada a la muralla.\n");
        QueryMurallas()->SoltarCuerda(cuerda);
        }

    TP->move(HAB_FOSO_ANNUFAM("foso_01"),M_SPECIAL,
             ({"se dirige al borde del foso, y sin pensárselo dos veces, "
              "salta al vacío",
              "cae desde lo alto del foso",
              "Sin pensártelo más, te diriges al borde del foso y saltas al "
              "vacío"}));

    TP->Defend(TP->QueryWeight() / 1000,DT_BLUDGEON,
               DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
    return 1;
}

string mirar_muralla()
{
    int num = QueryMurallas()->QueryNumCuerdasEnMuralla();
    string msg = "Es una muralla de piedra, de aproximadamente diez metros de "
                 "altura. Preservan a la ciudad de cualquier intento de "
                 "intrusión.\n";
    if (num == 1)
    {
        return msg + "También puedes ver una gruesa cuerda "
               "que asciende hasta engancharse en una de las almenas... " +
               (CuerdaEnganchada(TP) ?
                "Yo de ti haría lo que sea que piensas hacer sujetando el otro "
                "extremo de esa cuerda, si no quieres que llegue alguien y te "
                "haga preguntas incómodas.\n":
                "Parece ser que alguien tiene ganas de entrar a la "
                "ciudad escalándola.\n");
    }
    if (!num) return msg;
    return msg + "También puedes ver varias cuerdas acabadas en grandes "
           "garfios, que se encuentran enganchados en una de las almenas.\n";
}

string m_cuerdas()
{
    int num = QueryMurallas()->QueryNumCuerdasEnMuralla();
    if (!num) return 0;
    if (num > 1)
    {
        string palabra = QueryMurallas()->num2letra(num);
        return "Son " + palabra + " cuerdas que se encuentran enganchadas en "
               "una almena de la muralla.\n";
    }
    return "Es una cuerda con un garfio en uno de sus extremos, el cual "
           "puedes ver enganchado en una almena en la muralla. " +
           (CuerdaEnganchada(TP) ?
            "Ya que sujetas el otro extremo, podrías intentar escalar por "
            "ella.\n":
            "El otro extremo cuelga suelto por la pared del foso.\n");
}


public void create()
{
    ::create();

    pMurallas = load_object(HAB_MURALLAS_ANNUFAM("murallas_33"));
    pAvenidaPorton = load_object(HAB_AVENIDA_ANNUFAM("avenida_01"));

    SetPreIntShort("a");
    SetIntShort("las puertas de Annufam");
    SetIntLong(W("Has llegado a las puertas de la ciudad enana de Annufam. "
                 "Según cuentan, el rey Belthain la construyó para instruir "
                 "a los enanos en el arte de la lucha, tras los frecuentes "
                 "intentos de invasión por parte de los orcos. "
                 "Está rodeada de una gran muralla y de un profundo foso. "
                 "También puedes ver un portón que regula la entrada a "
                 "la ciudad.\n"));

    AddDetail("foso",
              (:(!QueryPortonAbierto() ? W("Observas una zanja de unos tres "
                                           "metros de ancho y unos cuantos "
                                           "de profundidad. Te parece ver "
                                           "agua en el fondo, pero tampoco "
                                           "podrías asegurarlo, y de todos "
                                           "modos, no crees que sea una buena "
                                           "idea comprobarlo.\n"):
                                           W("Supones que bajo el portón habrá "
                                             "un foso, pero con él abierto "
                                             "te es imposible verlo.\n")):));

    AddDetail(({"cuerda","cuerda de la muralla","cuerda de muralla","cuerdas",
                "cuerdas de la muralla","cuerdas de muralla"}),
               SF(m_cuerdas));



    AddDetail(({"muralla","murallas","muro"}),SF(mirar_muralla));

    AddDetail(({"porton","portón","puerta","puente","puente levadizo"}),
              (:W("Es una gran puerta de hierro sujeta por cuatro gruesas "
                  "cadenas que permiten subirla o bajarla con relativa "
                  "facilidad.\n"
                  "Actualmente el portón está " +
                  (QueryPortonAbierto() ? " abierto, sirviendo así de puente para "
                                    "atravesar el foso que separa la entrada "
                                    "de la ciudad en sí.\n" :
                                    "cerrado, impidiendo así la entrada a la ciudad.\n")):));

    AddRoomCmd("saltar","cmd_saltar");
    AddRoomCmd("lanzar","cmd_lanzar");
    AddRoomCmd(({"trepar","escalar"}),"cmd_trepar");
    AddRoomCmd("desenganchar","cmd_desenganchar");


    AddExit("sur",HAB_SENDERO_ANNUFAM("explanada"));
    AddExit("norte",SF(entrar_ciudad));
}



int entrar_ciudad()
{
    if (!TP) return 0;
    if (QueryPortonAbierto())
    {
        TP->move(HAB_AVENIDA_ANNUFAM("avenida_01"),M_GO,"norte");
        return 1;
    }
    write("El portón está cerrado, no puedes pasar.\n");
    return 1;
}


public void init()
{
    ::init();
    // cargamos si no lo está la avenida_01 para que no haya problemas con
    // el portón
    load_object(HAB_AVENIDA_ANNUFAM("avenida_01"));
}
