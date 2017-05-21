/****************************************************************************
Fichero: yalin/workroom
Autor: Yalin
Fecha: 22/04/2008 13:35:05inherit RO
Descripción: El salón de la casa (workroom) de Yalin.
****************************************************************************/
#include "path.h"
#include <properties.h>
#include <magia.h>
#include <door.h>
inherit ROOM;

/* la siguiente función responderá a la acción coger del jugador dependiendo de lo que intente coger */
public int decor(string str)
{
    if ((str == "divan") || (str == "diván"))
    {
        write("No eres bastante fuerte para mover eso.\n");
        say((CAP(TNAME) + " intenta llevarse los muebles. ¡Vaya ocurrencia!\n"),TP);
        return 1;
    }
    if ((str == "tapiz") || (str == "lienzo") || (str == "dibujo") || (str == "dibujos"))
    {
        write("Si se te ocurre tocar el tapiz, Yalin seguramente te convertirá en rana.\n");
        return 1;
    }
    if ((str == "lampara") || (str == "lámpara") || (str == "globo") || (str == "globos"))
    {
        write("La lámpara está muy alta, no llegas a ella.\n");
        return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetIntShort("el salón de la casa de Yalin");
    SetIntLong("El salón principal impresiona por su riqueza. Tal vez algo recargado, "
        "pero como buena reina, aunque sea de las hadas, a Yalin le gusta disfrutar de la "
        "vida decadente.\nUna fina mesa de caoba ocupa el centro de la habitación, "
        "rodeada por 4 sillas a juego, sobre la que pende una magnífica lámpara de bronce.\nEn "
        "una de las paredes hay un confortable diván, donde Yalin y Sunca se reclina a escuchar "
        "la música que flota en el ambiente. La pared frente al diván está adornada con un "
        "magnífico tapiz de seda bordado en oro.\n");
    SetIntBright(50);
    SetIntSmell("Notas el delicado aroma de la opulencia, mezcla de maderas nobles, "
        "sedas y perfumes exóticos.\n");
    SetIntNoise("Una dulce música de violín y flauta llena el ambiente, sin que sepas de "
        "dónde procede.\n");
    AddDetail(({"lampara","lámpara"}),"Una gran estrella de 12 brazos, labrada a martillo por "
        "un gigante, que termina en 12 globos de vidrio.\n");
    AddDetail(({"globo","globos"}), "12 globos de vidrio de gran tamaño, soplados por el "
        "propio Kheron de atbalnin.\n");
    AddDetail(({"tapiz","seda"}), "Es un gran lienzo de seda tejido por los elfos, con dibujos "
        "bordados en oro fino por los enanos.\n");
    AddDetail(({"dibujo","dibujos"}), "No representan nada que tu reconozcas. Tal vez sean "
        "runas o símbolos mágicos, o tal vez sean dibujos mágicos que cambian caprichosamente.\n");
    AddDetail(({"dragon","dragón","dragones"}), "Los dragones que sostienen la mesa y las "
        "sillas son como todos los dragones. Grandes serpientes con alas. Se apollan en el "
        "suelo y están mirando hacia afuera.\n");
    AddDetail(({"divan","diván"}), "Una especie de cama estrecha con respaldo y reposabrazos a "
        "los lados, que sirve tanto para sentarse como para estar tumbado. Está tapizado con "
        "el mismo terciopelo que las sillas.\n");
    AddDetail(({"terciopelo"}), "Es una tela gruesa, belluda y... cara.\n");
    Set(P_TPORT,TPORT_NO);
    AddRoomCmd("coger", "decor");
    AddItem("obj/ninyo",REFRESH_DESTRUCT,1);
    AddItem("obj/mesa");
    AddItem("obj/sillas");
    AddExit("torre", TORRE("piso2/center"));
    AddExit("norte",TORRE("rooms/yalin/pasillo"));
    AddExit("sur",TORRE("rooms/yalin/terraza"));
    AddExit("este", TORRE("rooms/yalin/dormit"));
    AddExit("oeste", TORRE("rooms/yalin/portal"));
    AddDoor("torre","la puerta de la torre",
        "Es una puerta de roble, barnizada en un tono oscuro.\nEs austera y fría, sin adornos ni "
            "grabados. Casi da la impresión de ser una celda, o un velatorio.\n",
        ({"puerta","puerta yalin","puerta torre","puerta de torre","puerta de la torre"}),GENDER_FEMALE,"yalin_key",
        ([P_MATERIAL:M_MADERA,P_DOOR_CANT_OPEN_MSG:({
            "Ésa es la habitación de Yalin, no puedes entrar ahí sin permiso. Si no tienes la "
                "llave, será porque no debes entrar.\n",
            "@nombre@ trata de entrar en la habitación de Yalin, pero la "
            "la puerta está cerrada con llave. Por algo será.\n",
            "Oyes a alguien intentando abrir una puerta.\n"}),P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
}
    