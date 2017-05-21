/* Fichero: mandos.c
Autor: Aulë
Fecha: 01/08/2014
Descripción: vala de los muertos, resucita a los jugadores
*/

#include "./path.h"
#include <colours.h>
#include <properties.h>
#include <messages.h>
inherit NPC;
#define NOMBRE  (capitalize(TP->QueryRealName()))

public int nolucho()
{
    object agresor=TP || PO;
    tell_room(environment(),agresor->QueryName()+" se enfrenta a Mandos pero este "
    "parece hacerse más alto y terrible. Con una sola mirada le hace retroceder, "
    "acobardad"+agresor->QueryGenderEndString()+".\n",({agresor}));
    return notify_fail("Te adelantas con intención de atacar a Mandos, pero éste parece "
    "hacerse más alto y terrible. Te mira, y el poder que emana te hace desistir, "
    "aterrorizad"+agresor->QueryGenderEndString()+".\n",
    NOTIFY_NOT_VALID);
}

public int esquivo()
{
    tell_room(environment(),"Mandos hace un gesto con su mano izquierda, evitando "
    "que "+NOMBRE+" le lanzase lo que tenía intennción.\n",({TP}));
    write("Mandos desvía tu lanzamiento con un gesto de sumano izquierda.\n");
    return 1;
}

create()
{
    ::create();
    SetStandard("Mandos","ainu",200,GENERO_MASCULINO);
    SetChkFightFunction(SF(nolucho));
    SetChkMagicFunction(SF(nolucho));
    SetShort("Mandos,el Juez de los Valar");
    SetLong(
    "Tienes ante ti a Mandos, señor de las Estancias de Espera, Juez de los Valar, cuya "
    "palabra equivale a una sentencia y cuyo corazón no se ablanda ante nada.\n"
    "Es un alto Vala que como todos los de su raza, emana poder, nobleza y majestad de "
    "forma palpable. Sus hermosas facciones tienen la belleza y la estocidad de la "
    "piedra. Sus ojos, impávidos, profundos y sabios han visto el devenir de todas las edades "
    "de Arda y atesoran un conocimiento sobre lo que ha de venir mayor que cualquier "
    "habitante del mundo.\n"
    "Viste de forma muy poco ostentosa, con una larga túnica gris y una capa  del mismo "
    "color, con la capucha echada hacia atrás. Sus cabellos son plateados y le caen "
    "sueltos sobre la espalda.\n");
    SetIds(({"ainu","juez","mandos","Mandos","námo"}));
    SetAds(({"vala","juez","ainu", "noble", "poderoso", "sabio"}));
    SetNoGet("Nadie podría ser tan osado como para intentar coger al mismísimo Mandos "
    "en brazos.\n");
    Set(P_CANT_STEAL,1);
    Set(P_CANT_LURE,1);
    InitChats(6,({
    	"Mandos dice: A muy pocos de entre los mortales se les ha permitido retornar a la "
    	"vida tras haber comparecido ante mí.\n",
    	"Mandos dice: si deseas volver al mundo de los vivos y caminar de nuevo bajo los "
    	"cielos de Varda,solo tienes que escribir 'retornar', y yo juzgaré si te mereces"
    	" tal privilegio.\n"}));

    SetShrugMsg("Mandos dice: No estoy aquí para contestar a preguntas, Hijo de "
    "Ilúvatar.\n");
    AddItem(OBJ_PROT("capa_mandos"), REFRESH_REMOVE, SF(wearme));
    AddItem(OBJ_PROT("tunica_mandos"), REFRESH_REMOVE, SF(wearme));
}

init()
{
    ::init();
    add_action("esquivo","lanzar");

}
