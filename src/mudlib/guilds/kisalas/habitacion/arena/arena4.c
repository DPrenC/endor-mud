/****************************************************************************
Fichero: arena4.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"
#include <skills.h>
#include <moving.h>



#define TREPAR ({"árbol", "arbol", "por el árbol", "por el arbol", "por árbol",\
                 "por arbol", "al árbol", "al arbol"})

inherit SUELO_ARENA;

public int cmd_trepar(string str)
{
    int hab;
    object pl;
    if (!str || member(TREPAR, str) < 0)
    {
        return notify_fail("¿" + CAP(query_verb()) + " por dónde?\n",
                           NOTIFY_NOT_VALID);
    }
    if ((pl = TP)->QueryTP() < 5)
    {
        return notify_fail("Estás demasiado cansada para trepar ahora.\n",
                           NOTIFY_NOT_VALID);
    }
    if (  pl->QuerySkillLevel(HAB_TREPAR)
        > pl->QueryMaxSkillLevel(HAB_TREPAR) * 25 / 100)
    // Ha superado el 25% del máximo de su habilidad... Así que trepa sin
    // problemas, pero tampoco la usa
    {
        pl->move(AM_ARENA("copa_arbol2"), M_SPECIAL,
                 ({"trepa sin dificultad hasta la copa del árbol",
                   "llega trepando desde abajo",
                   "Ágilmente y sin dificultad, te aferras al tronco. Sin "
                   "usar ni tan siquiera las cuerdas, trepas hasta la copa del "
                   "árbol"}));
        pl->AddTP(-5);
        return 1;
    }
    // aún no ha superado el 25% así que usamos la habilidad
    // Como este árbol es fácil, trepa con -20 de UseSkill
    switch(pl->UseSkill(HAB_TREPAR))
    {
        case -50..-21:         // casi casi, pero no ;)
             write("Te aferras con todas tus fuerzas a las cuerdas y al tronco e "
                   "intentas impulsarte hacia arriba. Poco a poco vas ganando "
                   "terreno al interminable árbol... Sin embargo, cuando te quedan "
                   "escasos metros para llegar a la copa, un mal paso hace que "
                   "la cuerda se te resbale, pierdas asidero en el "
                   "tronco, y con ayuda de la gravedad, te precipitas al suelo... "
                   "Aunque estás a punto de caer sobre la red, la gran altura a "
                   "la que te encontrabas hace que finalmente caigas a las frías "
                   "y malolientes aguas del lago... Rápidamente sales del agua.\n");
             say(CAP(TNAME) + " se aferra con fuerza a las cuerdas y al tronco e "
                 "intenta ascender... Poco a poco va ganando terreno al enorme "
                 "árbol, pero finalmente, cuando ya sólo le quedan unos metros "
                 "para llegar a la copa, ves como se tambalea, pierde pie y cae "
                 "al vacío... Por un momento parece que va a caer sobre la red, "
                 "pero acaba cayendo de espaldas a las malolientes aguas del lago. "
                 "Rápidamente, sale del agua.\n");

             break;
        case -20..100:
             TP->move(AM_ARENA("copa_arbol2"), M_SPECIAL,
                      ({"se agarra con fuerza a las cuerdas y al tronco y "
                        "se impulsa hacia arriba. Poco a poco va ganando terreno, "
                        "hasta que, finalmente, consigue llegar a la copa",
                        "llega trepando desde el bosque",
                        "Te agarras con fuerza a la cuerda y al tronco, y "
                        "comienzas a impulsarte hacia arriba... Poco a poco "
                        "vas ganando terreno, hasta que, por fin, consigues "
                        "llegar a la copa.\n"}));
        default:
        // desastroso, realmente desastroso
             write("Te aferras con todas tus fuerzas a las cuerdas y al tronco, "
                   "e intentas impulsarte hacia arriba. Sin embargo, la cuerda "
                   "se te resbala, y finalmente caes de espaldas sobre la red.\n");
             say(CAP(TNAME) + " se aferra con fuerza a las cuerdas y al tronco e "
                 "intenta ascender por el árbol. Sin embargo, su inexperiencia "
                 "hace que la cuerda se le escurra y caiga de espaldas sobre la "
                 "red.\n");
    }
    pl->AddTP(-5);
    return 1;
}




create()
{
    ::create();

    SetIntLong("Desde esta parte, se forma una pequeña elevación que te permite "
               "observar mejor la isla de Goldhai en el horizonte. Al sur, la tierra "
               "acaba abruptamente, dando paso, tras una caída de algunos metros, a "
               "las tranquilas y nada recomendables aguas del lago. Aferrándose "
               "al borde mismo del precipicio, puedes ver un gran árbol, cuyo tronco "
               "aparece rodeado por gruesas cuerdas, que facilitarían un posible "
               "ascenso hasta la plataforma que ves en su parte superior.\n");

    AddDetail(({"arbol","árbol","arbol alto","árbol alto","árbol grande",
                "arbol grande"}), "Se trata de un árbol enorme, con un "
                "grueso tronco. Las rugosidades del mismo y las cuerdas que ves "
                "atadas a su alrededor, hacen de él un lugar ideal por donde "
                "trepar. Bajo él, y extendiéndose hacia el oeste hasta otro árbol "
                "casi idéntico a este, puedes ver una red, seguramente para impedir "
                "que las Kisalas sufran algún desagradable accidente al escalar.\n");

    AddDetail(({"cuerda","cuerdas"}), "Son unas gruesas cuerdas atadas alrededor del "
                                      "tronco del gran árbol. Facilitan un posible "
                                      "ascenso o descenso por él.\n");

    AddDetail("red", "Se trata de una red formada por gruesas cuerdas entrelazadas, "
              "creando así una malla que parece bastante resistente. La red se "
              "extiende hacia el oeste, junto a otro árbol de proporciones "
              "similares al que ves ante ti.\n");

    AddRoomCmd(({"trepar","escalar"}),"cmd_trepar");
    AddExit("oeste","arena3");
    AddExit("este","arena7");
    AddExit("norte","arena1");
    AddExit("nordeste","arena9");
    AddExit("sudeste","arena5");


}


