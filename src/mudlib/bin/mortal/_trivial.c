/*
 * /bin/mortal/_trivial
 */


#include <quiz.h>

private int _query_game_info(int type);
private int _propose_question();
private int _query_actual_question();

public int main(string str)
{
    seteuid(getuid());
    switch(str)
    {
    case "pregunta": return _query_actual_question(); break;
    case "info": return _query_game_info(QUIZ_SIMPLIFIED_INFO); break;
        case "info extendida": return _query_game_info(QUIZ_EXTENDED_INFO); break;
        case "proponer": return _propose_question(); break;
        default:
             return notify_fail("Uso: trivial <info>, <info extendida>, <pregunta> o <proponer>. "
                                "Para más información, escribe ayuda trivial.\n");
    }
    return 0;
}


private int _query_game_info(int type)
{
    string msg, msg2;
    if (!TP) return 0;
    if (QUIZMASTER->QueryState() == Q_STATE_NONE)
    {
        return notify_fail("No hay ningun trivial en curso en estos momentos.\n", NOTIFY_NOT_VALID);
    }
    msg = QUIZMASTER->QueryResults() + ".\n";
    if (type == QUIZ_EXTENDED_INFO)
    {
        ;
        if (msg2 = QUIZMASTER->ShowAllResults(QUIZ_ORDER_WINNER)) msg += msg2 + "\n";
    }
    write(msg);
    return 1;
}

private int _propose_question() { return QUIZMASTER->NewQuestionInteractive(QUIZ_PROPOSE); }
private int _query_actual_question()
{
    mixed *current;
    if (QUIZMASTER->QueryState() == Q_STATE_NONE)
    {
        return notify_fail("No hay ningun trivial activo en estos momentos.\n", NOTIFY_NOT_VALID);
    }
    if (QUIZMASTER->QueryState() != Q_STATE_ANSWER)
    {
        return notify_fail("No se ha planteado   ninguna pregunta en este momento.\n", NOTIFY_NOT_VALID);
    }
    if (!(current = QUIZMASTER->QueryCurrentQuestion()))
    {
        return notify_fail("No se pudo obtener la pregunta actual.\n", NOTIFY_NOT_VALID);
    }
    write("Pregunta actual: " + current[QUIZ_QUESTION] + "\n");
    return 1;
}

    