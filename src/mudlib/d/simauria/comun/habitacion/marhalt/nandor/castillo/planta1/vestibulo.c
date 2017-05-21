/****************************************************************************
Fichero: vestibulo.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: El vestíbulo del castillo.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <properties.h>
inherit SIM_ROOM;

create(){
    ::create();
    SetIntBright(40);
    SetIntShort("el vestíbulo");
    SetIntLong("El amplio vestíbulo en el que te hallas se encuentra en la planta baja "
    "de la torre del homenaje. Es una estancia sobria, cuadrada y umbría cuyo suelo "
    "enlosado hace resonar el eco de tus pasos. Ningún tapiz cuelga de sus desnudas "
    "paredes y ninguna estatua se yergue en sus rincones, tan solo dos antiguas "
    "armaduras enhiestas flanquean las puertas de roble siempre abiertas, que hacia el "
    "oeste conducen al salón de la torre de donde procede un calorcillo que invita a "
    "entrar. En esta estancia el señor del castillo suele dar, rodeado de sus guardias, "
    "la bienvenida a invitados de alta alcurnia y en días señalados, los campesinos de "
    "Nandor se amontonan aquí esperando su turno para exponer sus quejas y ruegos a su "
    "amo.\n"
    "Al norte se abre un pasillo ancho, bien enlosado e iluminado, al este está el "
    "portón de la torre que comunica con el patio y hacia el sur un arco conduce a otro "
    "pasillo mas estrecho.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre está hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddDetail("armaduras", "Un par de antiguas y pesadas armaduras colocadas a ambos "
    "lados de la entrada del salón.\n"
    "Se apoyan sobre alabardas de hoja enorme que dificilmente podría sostener un "
    "hombre, decoradas con antiguos grabados. La visera de los yelmos de cimera alta "
    "está bajada y sobre el acero pulido de la coraza portan incrustada una flor de lis "
    "dorada sobre un mandoble cincelado en el metal.\n");
    AddDetail(({"puertas", "puerta"}), "Unas altas puertas de roble pulido sin ninguna "
    "insignia ni adorno, casi siempre abiertas de par en par. Sobre la parte alta del "
    "arco que las alberga, hay tallado un yelmo alado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes está cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"escudo", "escudo de portón", "escudo de porton"}), "Es el escudo de "
    "armas de los Dhes-Bláin grabado en bronce. Representa una flor de lis por "
    "encima de un mandoble.\n");
    AddExit("norte", "./pasillo1");
    AddExit("oeste", "./salon_recepcion");
    AddExit("este", CASTILLO("patio/patio18"));
    AddExit("sur", "./zona_servidumbre1");
    AddDoor("sur", "una puerta de servicio",
    "Es una simple, pero bien cuidada, puerta de madera sin adornos, se utiliza para "
    "acceder a la zona de servidumbre.\n",
    ({"puerta", "puerta simple", "puerta de servidumbre", "puerta de servicio",
        "puerta del sur"}));
        SetLocate("el castillo de Nandor");
    AddDoor("este", "un gran portón",
    "Un gran portón de madera aherrada en forma de arco, sobre cuyos batientes "
    "aparece el escudo de los Dhes-Bláin.\n",
    ({"gran portón","portón", "gran porton", "porton"}), GENDER_MALE,
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_porton"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_porton")]));
}

