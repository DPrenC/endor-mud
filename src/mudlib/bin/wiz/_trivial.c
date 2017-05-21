/**
 * /bin/wiz/_trivial
 */

#include <quiz.h>

private int _start_quiz();
private int _stop_quiz();
private varargs int _add_question(string str);
private int _remove_question(string str);
private int _list_questions(string str);
private int _query_game_info(int type);

public int main(string str)
{
    seteuid(getuid());
    switch(str)
    {
        case "iniciar": return _start_quiz(); break;
        case "detener": return _stop_quiz(); break;
        case "añadir": return _add_question(); break;
        default:
             if (str && str[..5] == "añadir")
             {
                 if (str[7..15] == "propuesta") return _add_question(str[17..]);
             }
             if (str && str[..5] == "listar")
             {
                 return _list_questions((str[7..] != "" ? str[7..] : 0));
             }
             if (str && str[..5] == "borrar")
             {
                 return _remove_question((str[7..] != "" ? str[7..] : 0));
             }
             return notify_fail("Sintáxis: trivial iniciar, detener, añadir, "
                                "añadir propuesta, borrar, listar, info, o info extendida.\n", NOTIFY_ILL_ARG);
    }
    return 0;
}

private int _start_quiz()
{
    int state;
    if ((state = QUIZMASTER->QueryState()) == Q_STATE_STARTING)
    {
        return notify_fail("Ya se está iniciando una partida en estos momentos.\n", NOTIFY_NOT_VALID);
    }
    else if (state == Q_STATE_WAITING_START)
    // está preparado para iniciarse
    {
        object starter = QUIZMASTER->QueryStarter();
        if (!starter ||starter == TP)
        {
            if (!QUIZMASTER->StartGame())
            {
                return notify_fail("Ipmosible iniciar la partida.\n", NOTIFY_NOT_VALID);
            }
            return 1;
        }
        return notify_fail("El trivial debe ser iniciado por " + NREAL(starter) +
                           ", que fue quien la estaba configurando.\n", NOTIFY_NOT_VALID);
    }
    else if (state != Q_STATE_NONE)
    // ya está funcionando
    {
        return notify_fail("El trivial ya está en funcionamiento.\n", NOTIFY_NOT_VALID);
    }
    if (!QUIZMASTER->StartGame())
    {
        return notify_fail("Imposible iniciar el servidor Trivial.\n", NOTIFY_NOT_VALID);
    }
    return 1;
}

private int _stop_quiz()
{
    int state;
    object starter;

    if ((state = QUIZMASTER->QueryState()) == Q_STATE_NONE)
    {
        return notify_fail("El trivial no está actualmente activo.\n", NOTIFY_NOT_VALID);
    }
    else if (state == Q_STATE_WAITING_START)
    {
        if ((starter = QUIZMASTER->QueryStarter()) && starter != TP)
        {
            return notify_fail("La partida está siendo iniciada por " + NREAL(starter) + ".\nNo puedes "
                               "detenerla.\n", NOTIFY_NOT_VALID);
        }
        QUIZMASTER->StopGame(Q_SILENT);
    }
    else if (QUIZMASTER->QueryState() == Q_STATE_STARTING)
    {
        if ((starter = QUIZMASTER->QueryStarter()))
        {
            if (starter == TP)
            {
                return notify_fail("Para cancelar esta partida, utiliza la opción cancelar del "
                                   "menú de opciones de inicio.\n", NOTIFY_NOT_VALID);
            }
        }
        return notify_fail("Actualmente se está iniciando una partida. Espera unos instantes.\n", NOTIFY_NOT_VALID);
    }
    if (!QUIZMASTER->StopGame())
    {
        return notify_fail("No se puede finalizar la partida.\n", NOTIFY_NOT_VALID);
    }
    write("La partida ha finalizado.\n");
    return 1;
}

private int _list_questions(string str) { return QUIZMASTER->ListQuestions(str); }
private varargs int _add_question(string str) { return (!str ? QUIZMASTER->NewQuestionInteractive(QUIZ_NEW) : QUIZMASTER->AddProposedQuestion(str)); }
private int _remove_question(string str) { return QUIZMASTER->RemoveQuestionInteractive(str); }


