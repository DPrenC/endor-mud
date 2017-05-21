/****************************************************************************
Fichero: arena3.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas, con �rbol para trepar
****************************************************************************/

#include "path.h"
#include <skills.h>
#include <moving.h>



#define TREPAR ({"�rbol", "arbol", "por el �rbol", "por el arbol", "por �rbol",\
                 "por arbol", "al �rbol", "al arbol"})

inherit SUELO_ARENA;

public int cmd_trepar(string str)
{
    int hab;
    object pl;
    if (!str || member(TREPAR, str) < 0)
    {
        return notify_fail("�" + CAP(query_verb()) + " por d�nde?\n",
                           NOTIFY_NOT_VALID);
    }
    if ((pl = TP)->QueryTP() < 5)
    {
        return notify_fail("Est�s demasiado cansada para escalar ahora.\n",
                           NOTIFY_NOT_VALID);
    }

    if (  pl->QuerySkillLevel(HAB_TREPAR)
        > pl->QueryMaxSkillLevel(HAB_TREPAR) * 25 / 100)
        // Ha superado el 25% del m�ximo de su habilidad... As� que trepa sin
    // problemas, pero tampoco la usa
    {
        pl->move(AM_ARENA("copa_arbol"), M_SPECIAL,
                 ({"trepa sin dificultad hasta la copa del �rbol",
                   "llega trepando desde abajo",
                   "�gilmente y sin dificultad, te aferras al tronco. Sin "
                   "usar ni tan siquiera las cuerdas, trepas hasta la copa del "
                   "�rbol"}));
        pl->AddTP(-5);
        return 1;
    }
    // a�n no ha superado el 25% as� que usamos la habilidad
    // Como este �rbol es f�cil, trepa con -20 de UseSkill
    switch(pl->UseSkill(HAB_TREPAR))
    {
        case -50..-21:         // casi casi, pero no ;)
             write("Te aferras con todas tus fuerzas a las cuerdas y al tronco e "
                   "intentas impulsarte hacia arriba. Poco a poco vas ganando "
                   "terreno al interminable �rbol... Sin embargo, cuando te quedan "
                   "escasos metros para llegar a la copa, un mal paso hace que "
                   "la cuerda se te resbale, pierdas asidero en el "
                   "tronco, y con ayuda de la gravedad, te precipitas al suelo... "
                   "Aunque est�s a punto de caer sobre la red, la gran altura a "
                   "la que te encontrabas hace que finalmente caigas a las fr�as "
                   "y malolientes aguas del lago... R�pidamente sales del agua.\n");
             say(CAP(TNAME) + " se aferra con fuerza a las cuerdas y al tronco e "
                 "intenta ascender... Poco a poco va ganando terreno al enorme "
                 "�rbol, pero finalmente, cuando ya s�lo le quedan unos metros "
                 "para llegar a la copa, ves como se tambalea, pierde pie y cae "
                 "al vac�o... Por un momento parece que va a caer sobre la red, "
                 "pero acaba cayendo de espaldas a las malolientes aguas del lago. "
                 "R�pidamente, sale del agua.\n");

             break;
        case -20..100:
             TP->move(AM_ARENA("copa_arbol"), M_SPECIAL,
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
                 "intenta ascender por el �rbol. Sin embargo, su inexperiencia "
                 "hace que la cuerda se le escurra y caiga de espaldas sobre la "
                 "red.\n");
    }
    pl->AddTP(-5);
    return 1;
}


create()
{
    ::create();

    SetIntLong("Al norte puedes ver una de las paredes del edificio del "
               "gremio, mientras que al este, oeste y nordeste contin�a el bosque. "
               "Al sur, divisas las aguas del lago Zinn, y m�s all�, la isla "
               "de Goldhai.\n"
               "Casi al borde mismo del agua, observas que uno de los �rboles, "
               "el m�s alto de los alrededores, tiene unas cuerdas atadas "
               "por las que te ser�a relativamente f�cil trepar.\n");

    AnadeDetalleEdificio("norte");

    AddDetail(({"arbol","�rbol","arbol alto","�rbol alto","�rbol grande",
                "arbol grande"}), "Se trata de un �rbol enorme, con un "
                "grueso tronco. Las rugosidades del mismo y las cuerdas que ves "
                "atadas a su alrededor, hacen de �l un lugar ideal por donde "
                "trepar. Bajo �l, y extendi�ndose hacia el este hasta otro �rbol "
                "casi id�ntico a este, puedes ver una red, seguramente para impedir "
                "que las Kisalas sufran alg�n desagradable accidente al escalar.\n");

    AddDetail(({"cuerda","cuerdas"}), "Son unas gruesas cuerdas atadas alrededor del "
                                      "tronco del gran �rbol. Facilitan un posible "
                                      "ascenso o descenso por �l.\n");

    AddDetail("red", "Se trata de una red formada por gruesas cuerdas entrelazadas, "
              "creando as� una malla que parece bastante resistente. La red se "
              "extiende hacia el este, junto a otro �rbol de proporciones "
              "similares al que ves ante ti.\n");


    AddRoomCmd(({"trepar","escalar"}),"cmd_trepar");

    AddExit("oeste","arena2");
    AddExit("este","arena4");
    AddExit("nordeste","arena1");

}


