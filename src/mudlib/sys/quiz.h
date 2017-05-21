/**
 * /sys/quiz.h
*/

#ifndef _QUIZ_
#define _QUIZ_
#define Q_CHANNEL              "trivial"
// funciones que pueden actuar en silencio o no
#define Q_SILENT               1
// Tiempo desde que se acierta una pregunta hasta que se realiza otra
#define Q_TIME_NEW_QUESTION    30   // medio minuto.
// Tiempo maximo para responder una pregunta antes de cambiar
#define Q_TIME_MAX_QUESTION    300  // 5 minutos
// intentos de contestación por pregunta
#define Q_ATTEMPTS             3

// flags y resultados devueltos
#define QUIZ_QUESTION          0
#define QUIZ_ANSWER            1
#define QUIZ_LOSER             0 // perdedor
#define QUIZ_WINNER            1 // ganador
#define QUIZ_ORDER_WINNER 1 // ordenado por ganador
#define QUIZ_ORDER_ANSWER_BACK 2 // ordenados por el más respondón
#define QUIZ_PROPOSE           1 // proponer una pregunta
#define QUIZ_NEW               0 // añadir una nueva pregunta
#define QUIZ_SIMPLIFIED_INFO   0 // información simplificada de los resultados de la partida
#define QUIZ_EXTENDED_INFO     1 // mostrar información extendida sobre los resultados de la partida


// índices del array devuelto por db_fetch de la tabla de quiz_questions
#define QUIZ_T_ID                  0
#define QUIZ_T_QUESTION            1
// resultados devueltos por algunas funciones
#define Q_NO_PLAYERS           -1 // no hay jugadores en la partida
#define Q_ONE_PLAYER           -2 // un solo jugador participante
#define Q_NO_WINNERS           -3 // no hay ganadores
#define Q_NO_LOSERS            -4 // no hay perdedores
#define Q_QUESTION_ALREADY     -1 // una pregunta ya estaba en la base de datos


// estado del trivial
#define Q_STATE_NONE           0    // No iniciado
#define Q_STATE_STARTING       1 // se está iniciando
#define Q_STATE_WAITING_START        2 // esperando para ser iniciado
#define Q_STATE_ASK            3    // Esperando realizar pregunta
#define Q_STATE_ANSWER         4    // Esperando respuesta


#endif

