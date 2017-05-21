/* PNJ conserje del ayuntamiento de Nandor
 * [c] cheto
 *
 * 10-10-2001 Creacion
 *
 * [n] Castellanizado. (Oct'02)
 */

#include <properties.h>
inherit NPC;
create() {
    ::create();
    SetStandard("un funcionario", "humano", 9+d3(), GENDER_MALE);
    SetShort("un funcionario");
    SetLong("El funcionario es un humano de complexión normal, pero con cara de "
    "aburrido y amargado.\n");
    AddId(({"hombre", "funcionario"}));
    SetCitizenship("gorat");
    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    InitChats(4,({"El funcionario silba una canción.\n",
    "El hombre te pregunta: quieres algo?\n"}));

    AddQuestion(({"información","informacion"}),
    "El hombre dice: 'Aquí puedes pedir el impreso necesario para el JK23-H.'\n");
    AddQuestion(({"JK23-H","impreso","ayuda"}),
    "El funcionario dice cansinamente: 'Para pedir el impreso necesario para\n"
    "el certificado JK23-H escribe: 'pedir impreso'.\n");
}
