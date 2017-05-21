/****************************************************************************
Fichero: entrada.c
Autor: Kastwey
Creaci�n: 24/07/2005
Descripci�n: Entrada de la ciudad de Annufam
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <combat.h>
#include <skills.h>

#define AVENIDA_PORTON (HAB_AVENIDA_ANNUFAM("avenida_01.c"))
#define FOSO           ({"al foso","a foso","foso"})
#define LANZAR ({"cuerda al porton","cuerda a porton","cuerda al port�n",\
"cuerda a port�n","la cuerda al porton","la cuerda al port�n","la cuerda a \
porton","la cuerda a port�n","cuerda a la muralla","cuerda a muralla",\
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
// cuerda en cuesti�n, si s� hay
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
        tell_object(pl,"Sueltas la cuerda que manten�as enganchada a lo "
                       "alto de la muralla.\n");
        tell_room(TO,CAP(pl->QueryName()) + " suelta la cuerda que manten�a "
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
             ({"se agarra a la cuerda, y sin pens�rselo dos veces, salta al "
               "vac�o, quedando colgad" + AO + " por encima del foso. "
               "Cuando consigue acercarse a una de las paredes del mismo, "
               "apoya los pies en ella y comienza a trepar ayud�ndose con la "
               "cuerda. " + room,
               "cae de espaldas desde alg�n punto por encima de tu cabeza",
               "Sujetas fuertemente la cuerda y te lanzas al foso. Te "
               "balanceas sobre el abismo hasta llegar a la otra pared, y una "
               "vez all�, apoyas los pies en la muralla y te impulsas hacia arriba con "
               "ayuda de la cuerda. " + player}));
}

int cmd_trepar(string str)
{
    int hab, danyo, num_cuerdas;
    object cuerda;


    if (!str ||member(TREPAR,str) < 0)
    {
        return notify_fail("�" + CAP(query_verb()) + " por d�nde?\n",
                           NOTIFY_NOT_VALID);
    }
    if (QueryPortonAbierto())
    // para qu� trepar
    {
        return notify_fail("�Para qu� trepar por las murallas si est� el "
                           "port�n abierto?",NOTIFY_NOT_VALID);
    }

    if (!num_cuerdas = QueryMurallas()->QueryNumCuerdasEnMuralla())
    {
        return notify_fail("Miras la muralla, luego el foso que se abre ante "
                           "ti, te rascas la cabeza, y piensas que quiz�s "
                           "con algo a lo que agarrarse podr�as trepar por "
                           "ah�.\n",NOTIFY_NOT_VALID);
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
    // si lleva puesta botas de escalada, se a�ade una bonificaci�n al uso
    // de la habilidad
    if (sizeof(filter(TP->QueryArmours() ||({}),(:$1->id("botas_escalada"):))))
    {
        hab += 50;
    }

    // dependiendo de lo habilidoso que sea trepando, lo conseguir�
    // o no lo conseguir�...
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
    // antes de caer llega m�s arriba de la muralla, por lo que el
    // porrazo es m�s grande, XDD.
    {
        caer("Con esfuerzo, va ascendiendo l�ntamente. Desgraciadamente, la "
             "cuerda se le resbala, y aunque por unos momentos parece que "
             "conseguir� volver a agarrarla, la fuerza de la gravedad le "
             "juega una mala pasada, y cae al vac�o",
             "Asciendes l�ntamente y con cuidado...\n"
             "Sin saber como, la cuerda se te resbala. Intentas volver a "
             "agarrarla, pero la gravedad no parece estar de tu parte, y sin "
             "poder evitarlo, caes al vac�o...\n"
             ".................................................................\n"
             "Toda tu vida te pasa por la mente en cuesti�n de segundos..");
        danyo = 30 + random(21);
    }
    else if (hab < 0)
    // �casi! �caasi! pero no!
    // el da�o es mayor... ya est� casi arriba!
    {
        caer("Poco a poco asciende impuls�ndose con pies y manos. Cuando "
             "ya casi est� en el borde superior, las piernas se le doblan y "
             "queda colgando de los brazos. Aunque intenta volver a conseguir "
             "el punto de apoyo, finalmente comienza a escurrirse por "
             "la cuerda, y tras unos segundos de lento descenso, termina "
             "por soltarla, y cae al vac�o",
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
                   "asoma la cabeza por el borde de la muralla, y ayud�ndose "
                   "con los brazos, se iza por completo",
                   "Sujetas fuertemente la cuerda y saltas al foso. Colgad" +
                   AO + " sobre el vac�o te balanceas hasta llegar a la pared "
                   "de la muralla. Apoyas los pies en la misma y comienzas a "
                   "impulsarte hacia arriba con ayuda de la cuerda. Poco a "
                   "poco vas ganando terreno, hasta que por fin vislumbras la "
                   "cima del enorme muro. Apoy�ndote en �l y con tus �ltimas "
                   "fuerzas, consigues izarte a la parte superior mientras la "
                   "cuerda se te resbala y queda colgando en la muralla"}));
        QueryMurallas()->SoltarCuerda(cuerda);
    }
    if (danyo)
    // se le infringe el da�o especificado en danyo
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
        return notify_fail("�Desenganchar qu� de d�nde?\n",NOTIFY_NOT_VALID);
    }
    return notify_fail("De la muralla te separa un bonito foso... Despu�s de "
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
        return notify_fail("�Lanzar qu� d�nde?\n",NOTIFY_NOT_VALID);
    }
    if (QueryMurallas()->QueryNumCuerdasEnMuralla() > 10)
    {
        return notify_fail("Miras las diez cuerdas que permanecen enganchadas "
                           "a las murallas y te das cuenta que no hay m�s "
                           "sitio para lanzar ni una m�s.\n",NOTIFY_NOT_VALID);
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
    // esta cuerda ya est� enganchada en las murallas
    {
        return notify_fail("La cuerda ya est� enganchada a las murallas.\n",
                           NOTIFY_NOT_VALID);
    }
    else if (CuerdaEnganchada(TP))
    {
        return notify_fail("Ya tienes una cuerda sujeta y enganchada a la "
                           "muralla. �Para qu� lanzar otra?\n",NOTIFY_NOT_VALID);
    }

    hab = TP->UseSkill(HAB_LANZAR);
    // dependiendo de la habilidad en lanzar la cuerda, ocurrir� una cosa u
    // otra
    if (hab < -50)
    // desastroso, por decirlo en modo suave :P
    {
        write("Lanzas la cuerda con todas tus fuerzas. Sin embargo, de alguna "
              "forma te las apa�as para que la cuerda describa un extra�o "
              "arco y ni siquiera toque la muralla.\n");
        say(CAP(TNAME) + " lanza una cuerda hacia las murallas. Sin embargo, "
            " esta describe un extra�o arco y ni siquiera roza la "
            "pared.\n");
        return 1;
    }
    else if (hab < -20)
    // menos desastroso pero a�n no
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
          "certeramente hacia una de las almenas, y ... �consigues "
          "engancharlo!\n");
    say(CAP(TNAME) + " lanza una cuerda hacia lo alto de la muralla. Con "
        "sorprendente precisi�n, el garfio se engancha en una de las "
        "almenas.\n");
    QueryMurallas()->EngancharCuerdaEnMuralla(cuerda);
    return 1;
}






int cmd_saltar(string str)
{
    object cuerda;

    if(!str || member(FOSO,str) < 0)
    {
        return notify_fail("�Saltar a d�nde?\n",NOTIFY_NOT_VALID);
    }
    if (QueryPortonAbierto())
    {
        return notify_fail("Como no pretendas atravesar el port�n, no creo "
                           "que haya otra forma de llegar al foso sin "
                           "antes cerrarlo.\n",NOTIFY_NOT_VALID);
    }
    if (!TP->QueryAttribute("saltar_foso_annufam"))
    {
        write("Supongo que no has querido poner eso, �no? Vuelve a escribir "
              "lo mismo, si realmente deseas hacerlo.\n");
        TP->SetAttribute("saltar_foso_annufam",1);
        return 1;
    }
    if (cuerda = CuerdaEnganchada(TP))
    // tiene que soltar la cuerda
    {
        write("Para darle m�s emoci�n al asunto, sueltas la cuerda que "
              "tienes enganchada a la muralla.\n");
        QueryMurallas()->SoltarCuerda(cuerda);
        }

    TP->move(HAB_FOSO_ANNUFAM("foso_01"),M_SPECIAL,
             ({"se dirige al borde del foso, y sin pens�rselo dos veces, "
              "salta al vac�o",
              "cae desde lo alto del foso",
              "Sin pens�rtelo m�s, te diriges al borde del foso y saltas al "
              "vac�o"}));

    TP->Defend(TP->QueryWeight() / 1000,DT_BLUDGEON,
               DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
    return 1;
}

string mirar_muralla()
{
    int num = QueryMurallas()->QueryNumCuerdasEnMuralla();
    string msg = "Es una muralla de piedra, de aproximadamente diez metros de "
                 "altura. Preservan a la ciudad de cualquier intento de "
                 "intrusi�n.\n";
    if (num == 1)
    {
        return msg + "Tambi�n puedes ver una gruesa cuerda "
               "que asciende hasta engancharse en una de las almenas... " +
               (CuerdaEnganchada(TP) ?
                "Yo de ti har�a lo que sea que piensas hacer sujetando el otro "
                "extremo de esa cuerda, si no quieres que llegue alguien y te "
                "haga preguntas inc�modas.\n":
                "Parece ser que alguien tiene ganas de entrar a la "
                "ciudad escal�ndola.\n");
    }
    if (!num) return msg;
    return msg + "Tambi�n puedes ver varias cuerdas acabadas en grandes "
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
            "Ya que sujetas el otro extremo, podr�as intentar escalar por "
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
                 "Seg�n cuentan, el rey Belthain la construy� para instruir "
                 "a los enanos en el arte de la lucha, tras los frecuentes "
                 "intentos de invasi�n por parte de los orcos. "
                 "Est� rodeada de una gran muralla y de un profundo foso. "
                 "Tambi�n puedes ver un port�n que regula la entrada a "
                 "la ciudad.\n"));

    AddDetail("foso",
              (:(!QueryPortonAbierto() ? W("Observas una zanja de unos tres "
                                           "metros de ancho y unos cuantos "
                                           "de profundidad. Te parece ver "
                                           "agua en el fondo, pero tampoco "
                                           "podr�as asegurarlo, y de todos "
                                           "modos, no crees que sea una buena "
                                           "idea comprobarlo.\n"):
                                           W("Supones que bajo el port�n habr� "
                                             "un foso, pero con �l abierto "
                                             "te es imposible verlo.\n")):));

    AddDetail(({"cuerda","cuerda de la muralla","cuerda de muralla","cuerdas",
                "cuerdas de la muralla","cuerdas de muralla"}),
               SF(m_cuerdas));



    AddDetail(({"muralla","murallas","muro"}),SF(mirar_muralla));

    AddDetail(({"porton","port�n","puerta","puente","puente levadizo"}),
              (:W("Es una gran puerta de hierro sujeta por cuatro gruesas "
                  "cadenas que permiten subirla o bajarla con relativa "
                  "facilidad.\n"
                  "Actualmente el port�n est� " +
                  (QueryPortonAbierto() ? " abierto, sirviendo as� de puente para "
                                    "atravesar el foso que separa la entrada "
                                    "de la ciudad en s�.\n" :
                                    "cerrado, impidiendo as� la entrada a la ciudad.\n")):));

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
    write("El port�n est� cerrado, no puedes pasar.\n");
    return 1;
}


public void init()
{
    ::init();
    // cargamos si no lo est� la avenida_01 para que no haya problemas con
    // el port�n
    load_object(HAB_AVENIDA_ANNUFAM("avenida_01"));
}
