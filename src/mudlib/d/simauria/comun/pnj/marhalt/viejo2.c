        /****************************************************************************
        Fichero: viejo2.c
        Autor: Ratwor
        Fecha: 14/08/2007
        Descripción: Roalf totalmente arreglado.
        ****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit NPC;

create() {
    ::create();
    SetStandard("Roalf", "humano", 11, GENDER_MALE);
    SetShort("Roalf");
    SetLong("Es un anciano de cara flaca, con barba de tres días y cara de paleto. "
    "A pesar de todo, inspira ternura y tiene presencia de gran experiencia "
    "que debe tener de la vida. Quizá le puedas preguntar algo sobre la villa.\n");
    AddId(({"roalf","anciano", "viejo"}));
    AddQuestion(({"nandor", "Nandor", "villa"}),
        "Roalf dice: 'En un principio vivieron aquí elfos, pero después se fueron a "
        "su bosques y nuestros antepasados la ocuparon devolviéndola a la vida.'\n");
    AddQuestion("elfos",
        "Roalf dice: 'Son criaturas de los bosques. Se creen superiores a nosotros "
        "porque dominan la magia, pero si les sacas de ahí son bastante mediocres. "
        "Además son muy orgullosos y, si no fuera por los orcos, les habríamos dado "
        "un escarmiento hace tiempo.'\n");
    AddQuestion("orcos",
        "Roalf dice: 'Las razas de la luz estamos en guerra con ellos desde hace mucho. "
        "De vez en cuando hacen incursiones, pero no te preocupes, eso es por el sur, "
        "aquí estamos a salvo de esas bestias.'\n");
    AddQuestion(({"primo", "primo rombrat", "primo Rombrat", "rombrat", "Rombrat"}),
        "Roalf te dice: ummm mi primo Rombrat sí, hace años que se fué a vivir "
        "al poblado de Enalel, parece que allí se vive bien.\n",1);
    InitChats(2,({
        "Roalf dice: 'Espero que este año no nieve tanto como el pasado.'\n",
        "Roalf dice: mi primo Rombrat me comenta que a menudo suelen merodear ogros "
        "por los campos de manzanos.\n",
        "Roalf dice: 'ùltimamente parece que Nandor tiene mucha afluencia de viajeros.'\n",
        "Roalf dice: 'Dicen que va a haber otra guerra. Ojalá pudiera ir, "
        "pero ya no soy joven...'\n"}));
    InitAChats(10,({
    "Roalf gruñe: '¡Qué juventud! ¡En mis tiempos te ibas a enterar! ¡Gamberro!'\n"}));
    SetCitizenship("nandor");
}
