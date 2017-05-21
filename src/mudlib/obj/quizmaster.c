/**
 * /obj/quizmaster.c
 */

#pragma no_inherit
#pragma no_clone

#include <quiz.h>
#include <properties.h>
#include <input_to.h>
#include <files.h>
#include <money.h>
#include <colours.h>
#include <gremios.h>
#include <moving.h>

private nosave string question; // Ultima pregunta
private nosave mixed answer; // Respuestas de la ultima pregunta
private nosave int timeleft = 0;
private nosave int state = 0;
private nosave int total_questions; // total de preguntas realizadas en una partida
private nosave int total_questions_in_game; // el total de preguntas que se harán en una partida
private nosave int draw; // si se permite o no empate
private nosave int repeat; // si no se repetirán las preguntas en la partida mientras sea posible
private nosave string *questions_ids = ({}); // las preguntas realizadas, para usar con repeat a 0
private nosave object award; // premio
private nosave object starter; // quien está iniciando la partida
private nosave int percentage_xp; // la experiencia de premio
private int money; // el dinero del premio
private nosave int listadas_a, listadas_p; // si se han listado las preguntas de la base de datos
private nosave mapping players = ([:2]); // ([ <RealName>: <points>; <answers>, ])
private nosave mapping attempts = ([:1]); // ([<RealName>:<Attempts>, ])

//----------------------------------------------------------------------------

public varargs int StopGame(int silent); // forward
private void _reset_game(); //forward
private void _start_game5(); // forward

//----------------------------------------------------------------------------

// función para lanzar el mensaje que sea por el canal
private void _gritar(string str)       { CHMASTER->SendEmote(Q_CHANNEL, str); }

// ----------------------------------------------------------------------------
// Propiedades

public mixed QueryCurrentQuestion()
{
    if (!question || !answer) return 0;
    return ({question, answer});
}
public int QueryProposedQuestionsCount()
{
    mixed res;
    DBMASTER->Exec("select count(id) from quiz_questions where active = 0");
    if (!(res = DBMASTER->Fetch())) return 0;
    return to_int(res[0]);
}
public varargs int    QueryQuestionsCount(int include_proposed)
{
    DBMASTER->Exec("select count(id) from quiz_questions" + (!include_proposed ? " where active=1" : ""));
    return to_int(DBMASTER->Fetch()[0]);
}

public int QueryState() { return state; }
public mapping QueryAttempts() { return copy(attempts); }

public object QueryAward() { return award; }

public object QueryStarter() { return starter; }

public mapping QueryPlayers()          { return copy(players); }
public int     ResetPlayers()          { players = ([]); return 1; }

// ----------------------------------------------------------------------------
// Obtención y anuncio de los resultados de la partida

static int _worst_winner(string a, string b)   { return players[a]>players[b]; }
static int _worst_answerer(string a, string b) { return players[a,1]>players[b,1]; }

private mixed _query_game_result(int type)
{
    int num_players = sizeof(players);
    int points, answers;
    string *nombres, *lista, mensaje;
    if (!num_players) return Q_NO_PLAYERS;
    else if (num_players == 1) return Q_ONE_PLAYER;
    nombres = m_indices(players);
    if (type == QUIZ_LOSER)
    {
        points = players[(lista = sort_array(nombres, SF(_worst_winner)))[0]];
        answers = players[lista[0], 1];
        if (points == players[lista[<1]]) return Q_NO_LOSERS;
    }
    else
    {
        points = players[(lista = sort_array(nombres, SF(_worst_winner)))[<1]];
		      answers = players[lista[<1], 1];
        if (!points) return Q_NO_WINNERS;
    }
    return ({filter(nombres, (:players[$1] == $2:), points), points, answers});
}

public mixed *QueryWinners() { return _query_game_result(QUIZ_WINNER); }
public mixed *QueryLosers() { return _query_game_result(QUIZ_LOSER); }

public varargs string ShowAllResults(int i, int finished)
// i es la ordenación, que puede ser QUIZ_WINNERS o QUIZ_LOSSERS.
// finished es 1 si la partida está acabada, 0 de lo contrario
{
    string *names, msg;
    
    if (!sizeof(players)) return 0;

    names = m_indices(players);

    switch (i)
    {
        case QUIZ_ORDER_WINNER:  // Ordenados por mas ganador
            names = sort_array(names, "_worst_winner");
            msg = "Los resultados " + (finished ? "" : "actuales ") + "ordenados por puntuación son:\n";
            break;
        case QUIZ_ORDER_ANSWER_BACK:  // Ordenado por mas 'respondon'
            names = sort_array(names, "_worst_answerer");
            msg = "Los resultados actuales ordenados por número de respuestas dadas:\n";
            break;
        default: // por defecto saco la lista sin ordenar
            msg = "Los resultados actuales son:\n";
    }

    for (i=sizeof(names); i-- ; ) {
        msg += sprintf("[ %9s ] Aciertos: %4s Puntuación: %4s\n",
                names[i],
                to_string(players[names[i],1]),
                to_string(players[names[i]]));
    }
    return msg;
}

public varargs string QueryResults(int finished)
// devuelve el resultado de la partida. Finished determina si ya está acabada o no
{
    mixed winners, losers;
    int points, gender, n_ac;
    string *nombres, nombre, s, s2, msg;
    object ob;

    if (state == Q_STATE_NONE)
    {
        return "No hay ninguna partida en curso";
    }
    winners = QueryWinners();

    if ((int)winners == Q_NO_PLAYERS)
    // no hay jugadores
    {
        return "Ningún jugador ha participado en esta partida" +
               (finished ? "" : " hasta el momento");
    }

    if (winners == Q_ONE_PLAYER)
    // un solo jugador
    {
        points = players[(nombre = m_indices(players)[0])];
        n_ac = players[nombre, 1];

        s = n_ac != 1 ? "s" : "";
        s2 = total_questions != 1 ? "s" : "";
        return "El único jugador participante en la partida" +
               (finished ? "" : " hasta el momento") + " ha sido " +
               CAP(nombre) + ", con " + points + " puntos, y " + n_ac + " pregunta" + s +
               " acertada" + s + ", de un total de " + total_questions + " pregunta" + s2 +
               " efectuada" + s2;
    }

    if (winners == Q_NO_WINNERS)
    // hay jugadores, pero no hay ganadores
    {
        return "Aunque " +
               implode((nombres = sort_array(m_indices(players), (:$1 > $2:)))[..<2], " ") +
               " y " + nombres[<1] + " han participado en la partida, ninguno ha "
               "acertado " + (total_questions > 1 ? "ninguna de las " + total_questions +
                                                    " preguntas efectuadas" :
                                                    "la única pregunta efectuada");
    }

    // ganadores
    points = winners[1];
    n_ac = winners[2];

    s = n_ac != 1 ? "s" : "";
    s2 = total_questions != 1 ? "s" : "";

    if (sizeof(winners[0]) == 1)
    {
        ob = find_object(LOWER(winners[0][0]));
        gender = ob ? ob->QueryGender() : GENDER_MALE;
        msg = (gender == GENDER_MALE ? "¡El ganador " : "¡La ganadora ") +
              (finished ? "de la partida ha sido " : "actual de la partida es ") +
              winners[0][0] + ", con " + points +
              " puntos obtenidos, y " + n_ac + " pregunta" + s + " acertada" + s + ", de un total de " + total_questions +
              " pregunta" + s2 + " efectuada" + s + "!";
    }
    else
    // hay más de un ganador
    {
        msg = "¡Los ganadores " + (finished ? "de esta partida han sido: " : "actual de la partida son: ") +
              implode((nombres = sort_array(winners[0], (:$1 > $2:)))[..<2], " ") +
              " y " + nombres[<1] + ", habiendo obtenido cada uno " + points + " puntos en un total de " + total_questions + " pregunta" + s2 + " efectuada" +
              s2 + "!";
    }

    // perdedores
    losers = QueryLosers();
    if ((int)losers == Q_NO_LOSERS)
    // no hay perdedores
    {
        return msg + "\n¡No hay perdedores en esta partida!";
    }

    points = losers[1];
    n_ac = losers[2];

    if (sizeof(losers[0]) == 1)
    {
        ob = find_object(LOWER(losers[0][0]));
        gender = ob ? ob->QueryGender() : GENDER_MALE;
        msg += "\n" + (gender == GENDER_MALE ? "¡El perdedor " : "¡La perdedora ") +
              (finished ? "de la partida, ha sido " : "actual de la partida, es ") +
              losers[0][0] + ", con " + points +
              " puntos obtenidos, y " + n_ac + " pregunta" + s + " acertada" + s + "!";
    }
    else
    // hay más de un perdedor
    {
        msg += "\n¡Los perdedores " +
              (finished ? "de esta partida han sido: " : "actual de la partida son: ") +
              implode((nombres = sort_array(losers[0], (:$1 > $2:)))[..<2], " ") +
              " y " + nombres[<1] + ", habiendo obtenido cada uno " + points + " puntos!";
    }

    return msg;
}

// ---------------------------------------------------------------------------

public int _continue_playing()
// devuelve 1 si continuamos jugando, 0 y finaliza la partida, si ya se acaba
{
    mixed winners;
    
    if (total_questions_in_game == -1 || total_questions < total_questions_in_game) return 1;
    if (!draw && (winners = QueryWinners()) && pointerp(winners) && sizeof(winners = winners[0]) > 1)
    // hay un empate, y no se permite
    {
        while (remove_call_out("DoQuestion") > -1);
        _gritar("¡Se ha producido un empate entre " + implode(winners[..<2], ", ") + " y " +
                winners[<1] + ". Debido a que en esta partida no puede haber empates, se realizará "
                "una pregunta de desempate para determinar el ganador. ¡El que primero conteste, gana! ¡Preparados?");
        total_questions_in_game++;
        call_out("DoQuestion", 20);
        return 1;
    }
    StopGame();
    return 0;
}


public int _end_time()
{
    if (state != Q_STATE_ANSWER) return 0;
    _gritar("¡Se acabó el tiempo! La pregunta queda sin responder");
    if (!_continue_playing()) return 0;
    _gritar("A ver si la próxima se os da mejor");
    attempts = ([:1]); // borramos los intentos para la pregunta
    call_out("DoQuestion", Q_TIME_NEW_QUESTION);
    return state = Q_STATE_ASK;
}

static int _question() {
    if (state != Q_STATE_ASK || !question) return 0;
    _gritar(question);
    return state = Q_STATE_ANSWER;
}

public void DoQuestion()
{
    mixed res_q, res_a;
    while (remove_call_out("_end_time") != -1);
    if (state != Q_STATE_ASK ||!_continue_playing()) return 0;
    DBMASTER->Exec("select * from quiz_questions where active=1 " +
                   (!repeat && sizeof(questions_ids) ?
                    " and id not in(" + implode(questions_ids, ",") + ") " :
                   "") + "order by rand() limit 1");
    res_q = DBMASTER->Fetch();
    if (!res_q)
    // no hay preguntas sin repetir, por lo que reseteamos las repetidas para que vuelvan a repetirse
    {
        questions_ids = ({});
        DoQuestion();
        return;
    }
    question = res_q[QUIZ_T_QUESTION];
    if (!repeat) questions_ids += ({res_q[QUIZ_T_ID]});
    DBMASTER->Exec("select answer from quiz_answers where questionid=" + to_int(res_q[QUIZ_T_ID]));
    answer = ({});
    while (res_a = DBMASTER->Fetch())
    {
        answer += ({res_a[0]});
    }
    total_questions++;
    _gritar("Atención, pregunta" + (total_questions_in_game > -1 ? " " + total_questions + " de " + total_questions_in_game : ""));
    call_out("_question", 2);
    call_out("_end_time", Q_TIME_MAX_QUESTION);
}

public int StartGame()
{
    if ((state != Q_STATE_NONE && state != Q_STATE_WAITING_START) || !QueryQuestionsCount()) return 0;
    if (state == Q_STATE_WAITING_START)
    {
        if (award)
        {
            write("En esta partida no se pueden producir empates. En caso de haberlos, se realizará "
                  "una pregunta extra para desempatar.\n");
        }
        _start_game5();
        return 1;
    }
    write("Iniciando una partida de trivial.\n");
    state = Q_STATE_STARTING;
    starter = TP;

    input_to("_start_game2", INPUT_PROMPT,
             "Especifica el número de preguntas que deseas que tenga esta partida, pulsa Intro para "
             "indicar 'partida infinita', o c para cancelar el inicio de la partida: ");
    return 1;
}

public void _start_game2(string str)
{
    int num;
    if (str) str = LOWER(str);
    if (!str || str == "")
    {
        total_questions_in_game = -1;
    }
    else if (str == "c" || str == "cancelar")
    {
    write("\nPartida cancelada.\n");
    StopGame(Q_SILENT);

    return;
    }
    else if (!(num = to_int(str)))
    {
        write("\nDebes especificar un número positivo de preguntas por partida, o bien pulsa intro "
              "para indicar 'partida infinita'.\n");
        input_to("_start_game2", INPUT_PROMPT,
             "Especifica el número de preguntas que deseas que tenga esta partida, pulsa Intro para "
             "indicar 'partida infinita', o c para cancelar el inicio de la partida: ");
        return;
    }
    else     total_questions_in_game = num;
    write("\nBien, la partida " +
          (total_questions_in_game == -1 ?
           "será infinita" : " tendrá " + total_questions_in_game + " preguntas") + ".\n");
    write("\nRepetición de preguntas.\n");
    input_to("_start_game3", INPUT_PROMPT,
             "¿Deseas que las preguntas no se repitan durante la partida, mientras esto sea posible? Pulsa s, n, o c para cancelarla.\n");
}

public void _start_game3(string str)
{
    if (str) str = LOWER(str);
    if (!str || str == "" || member(({"s", "si", "sí", "n", "no", "c", "cancelar"}), str) < 0)
    {
        write("\nDebes pulsar s, n, o c.\n");
        input_to("_start_game3", INPUT_PROMPT,
                 "¿Deseas que las preguntas no se repitan durante la partida, mientras esto sea posible? Pulsa s, n, o c para cancelarla.\n");
        return;
    }
    if (str == "c" || str == "cancelar")
    {
        StopGame(Q_SILENT);
        write("\nPartida cancelada.\n");
        return;
    }
    else if (str == "s" || str == "si" || str == "sí")
    {
        write("\nDe acuerdo. Se enviarán preguntas diferentes hasta que sea posible.\n");
    repeat = 0;
    }
    else
    {
        write("\nDe acuerdo. Podrán repetirse preguntas.\n");
        repeat = 1;
    }
    write("\nPremio para la partida.\n1. Un objeto.\n2. Dinero.\n3. Experiencia.\n4. Ninguno.\nC: Cancelar la partida.");
    input_to("_start_game4", INPUT_PROMPT, "¿Qué premio deseas ofrecer al ganador de la partida? ");
    return;
}


public void _start_game4(string str)
{
    string *validas = ({"1", "2", "3", "4", "objeto", "dinero", "experiencia", "ninguno", "c"});
    if (str) str = LOWER(str);
    if (!str || member(validas, str) < 0)
    {
        write("\nDebes escribir 1 (objeto), 2 (dinero), 3 (experiencia), 4 (ninguno), o c para cancelar la partida.\n");
        input_to("_start_game4", INPUT_PROMPT, "¿Qué premio deseas ofrecer al ganador de la partida? ");
        return;
    }
    switch (str)
    {
        case "c": case "cancelar":
            write("\nPartida cancelada.\n");
            StopGame(Q_SILENT);
            return;
        case "1": case "objeto":
            input_to("_start_game_object", INPUT_PROMPT,
                     "Escribe la ruta del objeto que deseas ofrecer como premio al ganador de "
                     "la partida, o c, para cancelarla: ");
            return;
        case "2": case "dinero":
            write("\nEscribe a continuación la cantidad de dinero ofrecida, en formato: "
                  "tipo cantidad, tipo cantidad... Ejemplo: oro 3, plata 14.\n");
            input_to("_start_game_money", INPUT_PROMPT,
                     "Cantidad de dinero a ofrecer como premio al ganador de la partida: ");
            return;
        case "3": case "experiencia":
            write("\nEscribe, en porcentaje, la experiencia a ofrecer para el ganador. Este será "
                  "el porcentaje de la XP necesaria para que el ganador suba de su nivel actual "
                  "al siguiente.\n");
            input_to("_start_game_experience", INPUT_PROMPT,
                     "Porcentaje de experiencia ofrecida al ganador, pulsa c para cancelar la partida: ");
            return;
        case "4": case "ninguno":
            write("\nDe acuerdo, no se otorgará ningún premio automáticamente a la finalización de "
                  "la partida.\n");
            _start_game5();
            return;
    }
}

public void _start_game_object(string str)
{
    string msg;
    if (str) str = LOWER(str);
    if (!str || str == "")
    {
        write("\nDebes utilizar una de las opciones disponibles.\n");
        input_to("_start_game_object", INPUT_PROMPT,
                     "Escribe la ruta del objeto que deseas ofrecer como premio al ganador de "
                     "la partida, o c, para cancelarla: ");
        return;
    }
    if (str == "c")
    {
        StopGame(Q_SILENT);
        write("\nPartida cancelada.\n");
        return;
    }
    seteuid(getuid(TP));
    if (str[<2..] != ".c") str += ".c";

    if (file_size(str) == FSIZE_NOFILE)
    // no existe, o no se tiene acceso a él
    {
        write("\nEl fichero especificado no existe, o no tienes acceso a él.\n");
        input_to("_start_game_object", INPUT_PROMPT,
                     "Escribe la ruta del objeto que deseas ofrecer como premio al ganador de "
                     "la partida, o c, para cancelarla: ");
        return;
    }
    if ((msg = catch(award = clone_object(str))))
    {
        write("\n¡Error al clonar el objeto!\n" + msg + "\n");
        write("\nPartida cancelada.\n");
        StopGame(Q_SILENT);
        return;
    }
    write("\nDe acuerdo. Se ofrecerá como premio " + (award->QueryShort() || award->QueryName() || "algo") +
          ".\n");
    input_to("_start_game_object2", INPUT_PROMPT,
             "¿Deseas cambiar, o incluir propiedades extra para este objeto? Pulsa s, n, o c para cancelar.\n");
}

public void _start_game_object2(string str)
{
    if (str) str = LOWER(str);
    if (!str || str == "" || member(({"s", "n", "c"}), str) < 0)
    {
        write("\nDebes escribir s, n, o c para cancelar.\n");
        input_to("_start_game_object2", INPUT_PROMPT,
                 "¿Deseas cambiar, o incluir propiedades extra para este objeto? Pulsa s, n, o c para cancelar.\n");
        return;
    }
    if (str == "n")
    {
        _start_game5();
        return;
    }
    else if (str == "c")
    {
        StopGame(Q_SILENT);
        write("\nPartida cancelada.\n");
    }
    write("\nDe acuerdo. El trivial quedará a la espera del comando trivial iniciar para iniciarse "
          "por completo. Para ajustar las propiedades del objeto premio, puedes acceder a él "
          "ejecutando la función del objeto quizmaster 'QueryAward'.\n");
    state = Q_STATE_WAITING_START;
}

public void _start_game_money(string str)
{
    string *separado, *separado2, moneda;
    mapping metalico = ([]);
    int valor;
    
    if (str) str = LOWER(str);
    if (!str || str == "")
    {
        write("\nDebes especificar el dinero del premio a ofrecer al / los ganadores de la partida.\n"
            "Recuerda el formato: tipo cantidad, tipo cantidad... Ejemplo: oro 3, plata 4.\n");
        input_to("_start_game_money", INPUT_PROMPT,
                 "Cantidad de dinero a ofrecer como premio al ganador de la partida: ");
        return;
    }
    else if (str == "c")
    {
        StopGame(Q_SILENT);
        write("\nPartida cancelada.\n");
        return;
    }
    separado = explode(str, ", ");
    foreach(string unacantidad:separado)
    {
        separado2 = explode(unacantidad, " ");
        if (sizeof(separado2) < 2)
        {
            write("\nError en la cadena para establecer el dinero. No se reconoce: " + unacantidad + ".\n"
                  "Vuelve a escribirla.\n");
            input_to("_start_game_money", INPUT_PROMPT,
                     "Cantidad de dinero a ofrecer como premio al ganador de la partida: ");
            return;
        }
        moneda = separado2[0];
        if (!MONEY_DEMON->QueryCoinValue(moneda))
        {
            write("\n¡Error! No se reconoce el tipo de moneda " + moneda + ". Asegúrate de escribir "
                  "la cantidad del premio en el formato correcto: cantidad moneda, cantidad moneda... "
                  "Ejemplo: oro 4, plata 7.\n");
            input_to("_start_game_money", INPUT_PROMPT,
                     "Cantidad de dinero a ofrecer como premio al ganador de la partida: ");
            return;
        }
        if (!(valor = to_int(separado2[1])))
        {
            write("\n" + CAP(separado2[1] + " no es un valor válido.\n"));
            input_to("_start_game_money", INPUT_PROMPT,
                     "Cantidad de dinero a ofrecer como premio al ganador de la partida: ");
            return;
        }
        m_add(metalico, moneda, valor);
    }
    if ((money = MONEY_LIB->Mapping2Value(metalico)) < 100)
    {
        write("\n¡Vamos, hombre, no seas tacaño! Solo se admiten cantidades superiores a una "
              "moneda de oro.\n");
        input_to("_start_game_money", INPUT_PROMPT,
                 "Cantidad de dinero a ofrecer como premio al ganador de la partida: ");
        return;
    }
    write("\nDe acuerdo. El dinero del premio es: " + MONEY_LIB->Value2String(money) + ".\n");
    input_to("_start_game_money2", INPUT_PROMPT,
             "¿Deseas que puedan producirse empates en la partida? Pulsa s, n, o c para cancelarla.\n");
}

public void _start_game_money2(string str)
{
    if (str) str = LOWER(str);
    if (!str || member(({"s", "si", "sí", "n", "no", "c", "cancelar"}), str) < 0)
    {
        write("\nDebes pulsar s, n, o c.\n");
        input_to("_start_game_money2", INPUT_PROMPT,
                 "¿Deseas que puedan producirse empates en la partida? Pulsa s, n, o c para cancelarla.\n");
        return;
    }
    if (str == "c" || str == "cancelar")
    {
        StopGame(Q_SILENT);
        write("\nPartida cancelada.\n");
        return;
    }
    else if (str == "s" || str == "si" || str == "sí")
    {
        draw = 1;
        write("\nDe acuerdo, si hay más de un ganador, se repartirá el dinero del premio de forma "
              "igualitaria.\n");
        _start_game5();
        return;
    }
    write("\nDe acuerdo. Si se produce un empate en la partida, se realizará una pregunta extra "
          "para desempatar.\n");
    _start_game5();
}





public void _start_game_experience(string str)
{
    int valor;
    if (str) str = LOWER(str);
    if (!str)
    {
        write("\nDebes escribir un valor numérico para usarlo como porcentaje.\n");
        input_to("_start_game_experience", INPUT_PROMPT,
                 "Porcentaje de experiencia ofrecida al ganador, pulsa c para cancelar la partida: ");
        return;
    }
    if (str == "c" ||str == "cancelar")
    {
        StopGame(Q_SILENT);
        write("\nPartida cancelada.\n");
        return;
    }
    if (!(valor = to_int(str)))
    {
        write("\n" + str + " no es un valor válido.\n");
        input_to("_start_game_experience", INPUT_PROMPT,
                 "Porcentaje de experiencia ofrecida al ganador, pulsa c para cancelar la partida: ");
        return;
    }
    write("\nDe acuerdo. Se otorgará al ganador de la partida, el " + valor + "% de la experiencia "
          "necesaria para avanzar de nivel.\n");
    percentage_xp = valor;
    _start_game5();
}


private void _start_game5()
{
    string msg;
    state = Q_STATE_ASK;
    CHMASTER->AddChannelHook(TO, Q_CHANNEL);
    msg = TC_BLUE + "¡Atención! ¡Se va a iniciar una nueva partida de Trivial!\n" + TC_NORMAL +
           (total_questions_in_game == - 1 ? "La partida no tiene un límite máximo de preguntas "
            "establecidas, sino que será un wizard el encargado de detenerla" :
            "La partida constará de " + total_questions_in_game + " preguntas") + ".\n";
    if (award)
    {
        msg += "Al ganador de la partida, se le otorgará un premio, consistente en " +
               (award->QueryShort() || award->QueryName() || "algo") +
               ". En caso de empate, se realizará una pregunta de desempate para determinar el "
               "ganador.";
    }
    else if (money)
    {
        msg += "El premio de esta partida consiste en la suma de " + MONEY_LIB->Value2String(money) + ".\n";
        if (draw)
        {
            msg += "En caso de empate entre varios jugadores, dicha suma será repartida entre los "
                   "ganadores.";
        }
        else
        {
            msg += "En caso de empate, se realizará una pregunta extra de desempate para "
                   "determinar el ganador de la partida.";
        }
    }
    else if (percentage_xp)
    {
        msg += "Al ganador de la partida, se le otorgará el " + percentage_xp + "% de la "
               "experiencia necesaria para subir al siguiente nivel.";
    }
    _gritar(msg);
    call_out("DoQuestion", 10);
}

public void _give_award(string *ganadores, mixed premio)
{
    object *oganadores, unganador, envganador, *ohabitaciones, dinero;
    mapping habitaciones;
    int i, nganadores, nganadores_habitacion, j;
    string msg, desc_premio;

    if (ganadores && sizeof(ganadores)) ganadores = map(ganadores, SF(lower_case));
    if (intp(premio))
    {
        string gremio;
        if (!(unganador = find_object(ganadores[0]))) return;
        if (!(gremio = unganador->QueryGuild()) || gremio == GC_NINGUNO)
        {
            log_file("QUIZ_INFO", sprintf("%-76=s", ctime() + ". Se ha intentado otorgar a " + CAP(ganadores[0]) +
                     premio + "% de la XP para que avance al siguiente nivel, pero no tiene "
                     "gremio.\n"));
            tell_object(unganador, "Se te ha otorgado el " + premio + "% de la XP necesaria para que "
                        "subas a tu próximo nivel. Sin embargo, actualmente no estás "
                        "en ningún gremio, por lo que no podemos darte el premio.\n"
                        "Por favor, contacta con un wizard una vez te establezcas en algún "
                        "gremio.\n¡Gracias!\n");
            return;
        }
        tell_object(unganador, "Se te ha otorgado el " + premio + "% de la XP necesaria para que "
                    "subas al siguiente nivel.\n¡Enhorabuena!\n");
        premio = (level2xp(unganador->QueryGuildLevel() + 1) - level2xp(unganador->QueryGuildLevel())) / 100 * premio;
        unganador->SetGuildXP(unganador->QueryGuildXP() + premio);
        return;
    }
    
    if (objectp(premio)) desc_premio = (premio->QueryShort() || premio->QueryName() || "albo");
    else if (mappingp(premio)) desc_premio = MONEY_LIB->Value2String(MONEY_LIB->Mapping2Value(premio));
    
    msg = "Escuchas un extraño ruido. Al mirar a tu alrededor, observas que a tu lado "
          "ha aparecido un diminuto duende, vestido con un uniforme fucsia. En una "
          "tarjeta que lleva colgada en el cuello, puedes leer:\n" +
          "------------------------------------------------------------------------"
          "| " + TC_PURPLE + "SOY ZIRIL, EL DUENDE MENSAJERO" + TC_NORMAL + "                                     |"
          "| " + TC_PURPLE + "M T A (MENSAJERÍA DE TRIVIAL A DOMICILIO)" + TC_NORMAL + "                            |"
          "------------------------------------------------------------------------"
          "\n\nEl duende mira hacia todos lados, con cara de no saber muy bien donde está. "
          "De repente, su expresión se aclara y sonríe de oreja a oreja "
          "mientras exclama:\n"
          "¡Ah, sí! Ehm... ";
        
    if (!ganadores || !(nganadores = sizeof(ganadores))) return;
    habitaciones = ([]);
    for (i = nganadores; i--;)
    {
        if (!(unganador = find_object(ganadores[i]))) continue;
        if (!(envganador = ENV(unganador)))
        {
            unganador->move("/std/void");
            envganador = ENV(unganador);
        }
        if (!member(habitaciones, envganador)) m_add(habitaciones, envganador, ({unganador}));
        else habitaciones[envganador] += ({unganador});
    }

    ohabitaciones = m_indices(habitaciones);
    for (i=sizeof(ohabitaciones);i--;)
    {
        oganadores = habitaciones[ohabitaciones[i]];
        if ((nganadores_habitacion = sizeof(oganadores)) == 1)
        {
            msg += "Busco a " + NREAL(oganadores[0]) + ".\n";
        }
        else
        {
            string *sganadores = map(oganadores, (:NREAL($1):));
            msg += "Busco a " + implode(sganadores[..<2], ", ") +
                   (sizeof(sganadores[..<2]) ? " y " : "") + sganadores[<1] + ".\n";
        }
        tell_room(ohabitaciones[i], msg);
        if (nganadores_habitacion == 1)
        {
            tell_object(oganadores[0], "El duende te mira y sonríe.\n" 
                        "-¡Ah, eres tú! ¡Bien, bien!\n");
            tell_room(ohabitaciones[i], "El duende mira a " + NNAME(oganadores[i]) + " mientras dice:\n"
                "-¡Ah, eres tú, no?\n", oganadores);
            tell_room(ohabitaciones[i], "Ciril abre una pequeña mochila que lleva a su espalda y "
                      "saca de ella un pequeño envoltorio.\n"
                      "-¡Ajá! ¡Aquí está! Tengo para ti " + desc_premio + "!\n"
                      "¡Vaya, vaya, qué suerte tienen algunos!\n");
            if (mappingp(premio))
            {
                if ((dinero = MONEY_LIB->QueryMoneyObject(oganadores[0]))) dinero->AdjustMoney(premio);
                else
                {
                    dinero = clone_object(MONEY);
                    dinero->SetMoney(premio);
                }
                premio = dinero;
            }
            tell_object(oganadores[0], "Ciril te da " + desc_premio + ".\n");
            tell_room(ohabitaciones[i],
                      "Ciril le da " + desc_premio + " a " +
                      CAP(NNAME(oganadores[i])) + ".\n", ({oganadores[0]}));
            if (!present(premio, oganadores[0]) && premio->move(oganadores[0], M_SILENT) != ME_OK)
            {
                tell_object(oganadores[0], CAP(desc_premio) + " se te cae al suelo.\n");
                tell_room(ohabitaciones[i], CAP(desc_premio) + " se le cae al suelo.\n", oganadores);
                premio->move(ohabitaciones[i]);
            }
        }
        else
        {
            tell_room(ohabitaciones[i], "Ciril os mira aaténtamente y dice:\n", all_inventory(ohabitaciones[i]) - oganadores);
            tell_room(ohabitaciones[i], "-¡Ah, sois vosotros! ¡Bien, bien!\n"
                      "Ciril abre una pequeña mochila que lleva a su espalda y "
                      "saca de ella un pequeño envoltorio.\n"
                      "-¡Ajá! ¡Aquí está! Tengo para vosotros " + desc_premio + "!\n"
                      "¡Vaya, vaya, qué suerte tienen algunos!\n");
            for (j=nganadores_habitacion; j--;)
            {
                if ((dinero = MONEY_LIB->QueryMoneyObject(oganadores[j]))) dinero->AdjustMoney(premio);
                else
                {
                    dinero = clone_object(MONEY);
                    dinero->SetMoney(premio);
                }
                premio = dinero;
                tell_object(oganadores[j], "Ciril te da " + desc_premio + ".\n");
                tell_room(ohabitaciones[i], "Ciril le da " + desc_premio +
                          " a " + CAP(NNAME(oganadores[j])) + ".\n", ({oganadores[j]}));
                if (!present(premio, oganadores[j]) && premio->move(oganadores[j]) != ME_OK)
                {
                    tell_object(oganadores[j], CAP(desc_premio) + " se te cae al suelo.\n");
                    tell_room(ohabitaciones[i], CAP(desc_premio) + " se le cae al suelo.\n", ({oganadores[j]}));
                    premio->move(ohabitaciones[i]);
                }
            }
        }
        tell_room(ohabitaciones[i], "Ciril vuelve a cerrar la mochila, hace una graciosa "
                  "reverencia, y desaparece de repente.\n");
    }
}

public int StopGame(int silent)
{
    if (state == Q_STATE_NONE) return 2; // 2 = already stoped
    CHMASTER->RemoveChannelHook(TO, Q_CHANNEL);
    if (!silent)
    {
        string msg, msg2, award_desc;
        mixed winners = QueryWinners();
        object win;
        int div;
        mixed premio;

        // informamos del resultado de la partida
        msg = QueryResults(1) + ".\n\n" + ((msg2 = ShowAllResults(QUIZ_ORDER_WINNER, 1)) ? msg2 : "") + "\n\n";
        if (pointerp(winners)) winners = winners[0];
        else if (winners == Q_ONE_PLAYER) winners = m_indices(players);
        else
        {
            _gritar(msg + "¡Partida finalizada!");
            _reset_game();
            return 1;
        }
        if (award)
        // había premio
        {
            premio = award;
            msg += (msg2 = CAP(winners[0]) + " ha conseguido el premio de esta partida, consistente en " +
                   (award->QueryShort() || award->QueryName() || "algo") + "!\n");
            log_file("QUIZ_INFO", ctime() + ". " + msg2);
        }
        else if (percentage_xp)
        {
            msg += (msg2 = CAP(winners[0]) + " ha conseguido el premio de esta partida, otorgándosele el " +
                   percentage_xp + "% de la XP necesaria para subir al siguiente nivel!\n");
            log_file("QUIZ_INFO", ctime() + ": " + msg2);
            premio = percentage_xp;
        }
        else if (money)
        // dinero, puede haber empate
        {
            int swinners;
            if ((swinners = sizeof(winners)) > 1)
            // hay más de un ganador
            {
                div = money / swinners;
                if (!div) div = 1;
                msg += (msg2 = "Debido a que en esta partida ha habido más de un ganador, el dinero "
                       "total del premio se repartirá entre ellos. Por tanto, " +
                       implode(winners[..<2], ", ") + " y " + winners[<1] + ", recibirán cada "
                       "cual la suma de " + MONEY_LIB->Value2String(div) + "!\n");
                premio = MONEY_LIB->Value2Mapping(div);
            }
            else
            // solo hay un ganador
            {
                msg += (msg2 = CAP(winners[0]) + " ha conseguido el premio de esta partida, "
                       "consistente en " + MONEY_LIB->Value2String(money) + ".\n");
                premio = MONEY_LIB->Value2Mapping(money);
            }
            log_file("QUIZ_INFO", ctime() + ": " + msg2);
        }
        msg += "¡Partida finalizada!";
        _gritar(msg);
        _give_award(winners, premio);

    }
_reset_game();
return 1;
}

private void _reset_game()
{
    question = 0;
    answer = 0;
    timeleft = 0;
    players = ([:2]);
    total_questions = 0;
    total_questions_in_game = 0;
    state = Q_STATE_NONE;
    attempts = ([:1]);
    if (award && !ENV(award)) award->remove();
    else award = 0;
    money = 0;
    draw = 0;
    percentage_xp = 0;
    repeat = 0;
    questions_ids = ({});
    while (remove_call_out("DoQuestion") > -1);
}

static void _winner(object ob, int points)
{
    _gritar("¡Correcto!");
    _gritar(sprintf("¡Acierta %s por '%s'", (string) ob->QueryName(), pointerp(answer)?(string)answer[0]:answer) + " y consigue por ello " + points + " puntos!");
    attempts = ([:1]); // borramos los intentos para esta pregunta;
    _continue_playing();
}

public void NotifyChannel(string from, string ch, string str, int emote) 
{
    object ob;
    int points;

    if (state != Q_STATE_ANSWER) return 0;
    if (emote) return;
    ob = find_object(lower_case(from));
    if (!ob || !living(ob)) return;

    attempts[from]++; // sumamos un intento a esta pregunta

    str = lower_case(str); // Para facilitar las comparaciones

    if (   (stringp(answer)  && str == lower_case(answer))
        || (pointerp(answer) && member(map(answer, SF(lower_case)), str) >= 0 ) )
    { // ganador!
        state = Q_STATE_ASK;
        players[from, 1]++; // sumamos una pregunta acertada
        switch(attempts[from])
        {
            case 1: points = 10; break;
            case 2: points = 8; break;
            case 3: points = 5; break;
        }
        players[from]+=points;
        call_out("_winner", 0, ob, points);
        call_out("DoQuestion", Q_TIME_NEW_QUESTION);
    }
}
// Creación, modificación o borrado de preguntas

private int _check_new_question(string n_question, mixed n_answer)
{
    if (!n_question || !n_answer || (!pointerp(n_answer) && !stringp(n_answer))) return 0;
    if (pointerp(n_answer) && sizeof(n_answer) > sizeof(filter(n_answer, (:stringp($1):))))
    // si algún elemento del array de respuestas no es string, no se añade nada
    {
        return 0;
    }
    return 1;
}

public int AddQuestion(string n_question, string *n_answers, int type)
{
    mixed res;
    int id;
    DBMASTER->Exec("select count(id) from quiz_questions where question='" + n_question + "'");
    res = DBMASTER->Fetch();
    if (to_int(res[0])) return -1; // ya existía
    DBMASTER->Exec("insert into quiz_questions values(default, '" + n_question + "', " + (type == QUIZ_PROPOSE ? "0" : "1") + ")");
    if (!(id = DBMASTER->InsertId())) return 0; // error
    
    // Insertamos todas las respuestas a esta pregunta
    foreach(string ans:n_answers)
    {
        DBMASTER->Exec("insert into quiz_answers values(default, '" + ans + "', " + id + ")");
    }
    return 1;
}

public int AddProposedQuestion(string str)
{
    int valor;
    mixed res;

    if (!str || str == "")
    {
        return notify_fail("Sintaxis: trivial añadir propuesta <identificador de la pregunta a añadir>.\n"
                           "Para ver los identificadores de las preguntas propuestas, escribe "
                           "listar propuestas.\n", NOTIFY_NOT_VALID);
    }
    else if (!(valor = to_int(str)))
    {
        return notify_fail("Debes escribir el número identificativo de la pregunta a añadir.\n", NOTIFY_NOT_VALID);
    }
    if (!QueryProposedQuestionsCount())
    {
        return notify_fail("No hay preguntas propuestas actualmente en la base de datos.\n",
                           NOTIFY_NOT_VALID);
    }
    if (!listadas_p)
    {
        return notify_fail("Antes de añadir una pregunta propuesta, debes listar las existentes.\n",
                           NOTIFY_NOT_VALID);
    }
    DBMASTER->Exec("Select * from quiz_questions where id=" + valor + " and active=0");
    if (!(res = DBMASTER->Fetch()))
    {
        return notify_fail("Ese identificador no existe. Asegúrate de haberlo escrito correctamente.\n",
                           NOTIFY_NOT_VALID);
    }
    input_to("_add_proposed_question2", INPUT_PROMPT,
             "¿Seguro que deseas añadir la siguiente pregunta?\n" + res[QUIZ_T_QUESTION] + "\n" 
             "Pulsa s, o n. ", res[QUIZ_T_QUESTION], valor);
    return 1;
}

public void _add_proposed_question2(string str, string the_question, int valor)
{
    if (str) str = LOWER(str);
    if (!str || str == "" || member(({"s", "sí", "si", "n", "no"}), str) < 0)
    {
        write("Debes pulsar s o n.\n");
        input_to("_add_proposed_question2", INPUT_PROMPT,
             "¿Seguro que deseas añadir la siguiente pregunta?\n" + the_question + "\n" 
             "Pulsa s, o n. ");
        return;
    }
    if (str == "n")
    {
        write("Cancelando la adición de esta pregunta.\n");
        return;
    }
    DBMASTER->Exec("update quiz_questions set active=1 where id=" + valor);
    if (!DBMASTER->AffectedRows())
    {
        write("Error al agregar la pregunta propuesta a la lista de preguntas para el trivial.\n");
        return;
    }
    write("Pregunta propuesta añadida.\n");
    listadas_p = 0;

}



public int RemoveQuestion(mixed d_question)
{
    if (!d_question && !stringp(d_question) && !intp(d_question)) return 0;
    if (stringp(d_question))
    {
        DBMASTER->Exec("delete from quiz_answers where QuestionID = (select id from quiz_questions where question='" + d_question + "')");
        DBMASTER->Exec("delete from quiz_questions where question='" + d_question + "'");
    }
    else
    {
        DBMASTER->Exec("delete from quiz_answers where QuestionID=" + d_question);
        DBMASTER->Exec("delete from quiz_questions where id=" + d_question);
    }
    return DBMASTER->AffectedRows() > 0;
}


// funciones para ser llamadas desde los binarios

public int ListQuestions(string str)
{
    string mensaje;
    int numero, num_questions, type, i;
    mixed res;

    if (str && !(numero = to_int(str)) && str != "propuestas")
    {
        return notify_fail("Sintaxis: listar, listar propuestas, listar <numero_pregunta<, o "
                           "listar propuestas <numero_pregunta.\n",
                           NOTIFY_NOT_VALID);
    }

    if (!(num_questions = QueryQuestionsCount()))
    {
        return notify_fail("Actualmente no hay preguntas en el trivial.\n", NOTIFY_NOT_VALID);
    }
    if (!str || str == "propuestas")
    // listamos
    {
        if (!str) type = 0;
        else type = 1;
        if ((!type && !QueryQuestionsCount()) || (type && !QueryProposedQuestionsCount()))
        {
            return notify_fail("No hay preguntas " + (type ? "propuestas " : "") + "en la base de datos.\n",
                               NOTIFY_NOT_VALID);
}

        mensaje = "Lista de preguntas " + (!type ? "existentes en la base de datos" : "propuestas") + ":\nID        | pregunta\n";
        DBMASTER->Exec("select id, question from quiz_questions where active=" + !type);
        while(res = DBMASTER->Fetch())
        {
            mensaje += sprintf("%-10s | %s", res[0], res[1]) + "\n";
        }
        STR->smore(mensaje);
        if (!type) listadas_a = 1;
        else listadas_p = 1;
        return 1;
    }
    if (numero < 0)
    {
        return notify_fail("Debes indicar un número positivo que corresponda con el identificador de una de las preguntas.\n",
                           NOTIFY_NOT_VALID);
    }
    DBMASTER->Exec("select question, active from quiz_questions where id=" + numero);
    if (!(res = DBMASTER->Fetch()))
    {
        return notify_fail("Esa pregunta no existe.\n", NOTIFY_NOT_VALID);
    }
    write("Pregunta " + (res[1] == "0" ? "propuesta" : "") + ": " + res[0] + ".\n");
    // obtenemos las respuestas
    DBMASTER->Exec("select answer from quiz_answers where questionid=" + numero);
    mensaje = "";
    while (res = DBMASTER->Fetch())
    {
        mensaje += (i ? (i+ 1) + ". " : "") + res[0] + ".\n";
        i++;
    }
    if (i > 1) write("Respuestas:\n1. " + mensaje + "\n\n");
    else write("Respuesta: " + mensaje + "\n\n");
    return 1;
}

public int RemoveQuestionInteractive(string str)
{
    int num;
    string pregunta;
    mixed res;
    if (!str || !num = (int)str)
    {
        return notify_fail("Debes introducir el identificador de la pregunta a borrar.\n",
                           NOTIFY_NOT_VALID);
    }
    if (!QueryQuestionsCount())
    {
        return notify_fail("Actualmente no hay preguntas en el trivial.\n",
                           NOTIFY_NOT_VALID);
    }
    if (num < 0)
    {
        return notify_fail("Debes introducir un número positivo, correspondiente a uno de los "
                           "identificadores de una pregunta del trivial.\n", NOTIFY_NOT_VALID);
    }
    DBMASTER->Exec("select question from quiz_questions where id=" + num);
    if (!(res = DBMASTER->Fetch()))
    {
        return notify_fail("Ese identificador no existe.\n", NOTIFY_NOT_VALID);
    }
    pregunta = res[0];
    input_to("_confirm_remove_question", INPUT_PROMPT,
             "¿Estás seguro de que deseas borrar la siguiente pregunta: " + pregunta + "\n"
             "Escribe s, o n.\n", num);
    return 1;
}

public void _confirm_remove_question(string res, int num)
{
    int val;
    res = LOWER(res);
    if (res != "s" && res != "n")
    {
        write("Debes escribir s, o n.\n");
        RemoveQuestionInteractive((string)num);
        return;
    }
    if (res == "n")
    {
        write("Operación de borrado cancelada. Saliendo.\n");
        state = Q_STATE_NONE;
        return;
    }
    if (!val = RemoveQuestion(num))
    {
        write("Error al borrar la pregunta de la base de datos.\n");
        return;
    }
    write("Pregunta borrada satisfactoriamente.\n");
    listadas_a = 0;
}


public varargs int NewQuestionInteractive(int type)
{
    input_to("_new_question", INPUT_PROMPT, "Escribe la pregunta a " +
             (type == QUIZ_PROPOSE ? "proponer" : "añadir") + ".\n", type);
    return 1;
}

public void _new_question(string n_question, int type)
{
    if (n_question == "")
    {
        write("Operación cancelada. Saliendo.\n");
        return;
    }
    write("La pregunta introducida es: " + n_question + "\n");
    input_to("_new_question2", INPUT_PROMPT,
             "¿Es correcto? Escribe s, o n.\n", n_question, type);
}

public void _new_question2(string res, string n_question, int type)
{
    res = LOWER(res);
    if (res != "s" && res != "n")
    {
        write("Debes escribir s o n.\n");
        return _new_question(n_question, type);
    }
    if (res == "n")
    {
        NewQuestionInteractive(type);
        return;
    }
    input_to("_new_question3", INPUT_PROMPT, "Escribe la primera respuesta. Esta será la "
             "respuesta que aparecerá por el canal del trivial como la respuesta "
             "correcta si un jugador acierta introduciendo cualquiera de las respuestas "
             "especificadas para esta pregunta.\n", n_question, 0, type);
}

public void _new_question3(string n_answer, string n_question, string *n_answers, int type)
{
    if (n_answer == "")
    {
        write("No has introducido la respuesta.\n");
        if (!n_answers)
        {
            input_to("_new_question3", INPUT_PROMPT, "Escribe la primera respuesta. Esta será la "
                     "respuesta que aparecerá por el canal del trivial como la respuesta "
                     "correcta si un jugador acierta introduciendo cualquiera de las respuestas "
                     "especificadas para esta pregunta.\n", n_question, 0, type);
            return;
        }
        input_to("_new_question3", INPUT_PROMPT,
                 "Escribe la respuesta " + (1 + sizeof(n_answers)) + ".\n", n_question, n_answers, type);
    }

    // confirmamos si la respuesta ha sido correctamente introducida
    input_to("_new_question4", INPUT_PROMPT,
             "La respuesta introducida es: " + n_answer + ".\n¿Es correcto? Pulsa s, o n.\n",
             n_question, n_answers, n_answer, type);
}

public void _new_question4(string res, string n_question, string *n_answers,
                                   string n_answer, int type)
{
    res = LOWER(res);
    if (res != "s" && res != "n")
    {
        write("Debes escribir s o n.\n");
        input_to("_new_question4", INPUT_PROMPT,
                 "La respuesta introducida es: " + n_answer + ".\n¿Es correcto? Pulsa s, o n.\n",
                 n_question, n_answers, n_answer, type);
        return;
    }
    if (res == "n")
    {
        if (!n_answers)
        {
            input_to("_new_question3", INPUT_PROMPT, "Escribe la primera respuesta. Esta será la "
                     "respuesta que aparecerá por el canal del trivial como la respuesta "
                     "correcta si un jugador acierta introduciendo cualquiera de las respuestas "
                     "especificadas para esta pregunta.\n", n_question, 0, type);
            return;
        }
        input_to("_new_question3", INPUT_PROMPT,
                 "Escribe la respuesta " + (1 + sizeof(n_answers)) + ".\n", n_question, n_answers, type);
        return;
    }
    if (!n_answers) n_answers = ({});
    n_answers += ({n_answer});
    write("Respuesta " + sizeof(n_answers) + " añadida.\n");
    input_to("_new_question5", INPUT_PROMPT,
             "¿Deseas añadir alguna otra respuesta? Pulsa s, o n.\n", n_question, n_answers, type);
}

public void _new_question5(string res, string n_question, string *n_answers, int type)
{
    string s, pregunta;
    int i;

    res = LOWER(res);
    if (res != "s" && res != "n")
    {
        write("Debes pulsar s o n.\n");
        input_to("_new_question4", INPUT_PROMPT,
                 "¿Deseas añadir alguna otra respuesta? Pulsa s, o n.\n", n_question, n_answers, type);
    }
    if (res == "s")
    {
        input_to("_new_question3", INPUT_PROMPT,
                 "Escribe la respuesta " + (1 + sizeof(n_answers)) + ".\n", n_question, n_answers, type);
        return;
    }
    s = sizeof(n_answers) > 1 ? "s" : "";
    pregunta = n_question + "\n\nRespuesta" + s + ":\n";
    foreach(string ans:n_answers)
    {
        i++;
        pregunta += i + ". " + ans + ".\n";
    }
    input_to("_new_question6", INPUT_PROMPT,
             "La pregunta con su" + s + " respuesta" + s + " es la siguiente:\n" + pregunta +
             "\n" + (type == QUIZ_PROPOSE ? "¿Deseas proponerla? " : "¿Deseas añadirla a la base de "
             "datos? ") + "Escribe s, o n.\n", n_question, n_answers, type);
}

public void _new_question6(string res, string n_question, string *n_answers, int type)
{
    int val;
    res = LOWER(res);
    if (res != "s" && res != "n")
    {
        write("Debes escribir s, o n.\n");
        return _new_question5("n", n_question, n_answers, type);
    }

    if (res == "n")
    {
        write("Operación cancelada. Saliendo.\n");
        return;
    }
    if (type == QUIZ_PROPOSE)
    {
        if (!AddQuestion(n_question, n_answers, QUIZ_PROPOSE))
        {
            write("Error al proponer la pregunta. Contacta con un wizard.\n");
            return;
        }
        write("Tu pregunta ha sido añadida a las preguntas propuestas. Gracias "
              "por tu colaboración.\n");
        return;
    }
    val = AddQuestion(n_question, n_answers, QUIZ_NEW);
    if (val == Q_QUESTION_ALREADY)
    {
        write("Esta pregunta ya fue añadida con anterioridad.\n");
        return;
    }
    if (!val)
    {
        write("Error al añadir la pregunta.\n");
        return;
    }
    write("Pregunta añadida satisfactoriamente.\n");
}

public int remove()
{
    if (award) award->remove();
    return destruct(TO), 1;
}


