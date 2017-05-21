/***
Fichero: puesto_reuniones.c
Autor: kastwey@simauria
Descripción: Sala de reuniones de los guardias de Faeria.
Creación: 06/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");

int cmd_abrir(string str);
int cmd_coger(string str);

create()
{
    ::create();
    SetIntShort("la sala de reuniones");
    SetIntLong(W("Te encuentras en lo que parece una sala de reuniones.\n"
    "La sala está repleta de sillas, y una gran mesa preside el centro de la estancia.\n"
    "Las paredes están forrada de mapas, y en una de ellas, puedes ver una vitrina con gran cantidad de armas en su interior.\n"));
    SetOficina(HAB_PUESTO("puesto_guardias/puesto_piso1"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"mesa"}), "Es una gran mesa que preside el centro de la estancia.\n");
    AddDetail(({"silla", "sillas"}), W("Son unas sillas repartidas por toda la sala.\n"
    "Por la cantidad que hay parece que cuando se hacen reuniones aquí, no hay cuatro gatos precísamente.\n"));
    AddDetail(({"mapas", "mapa", "pared"}), "Todas las paredes están forradas con mapas de lad_laurelin: el bosque que rodea atbalnin, la ciudad, la zona de los ents... Son unos mapas muy detallados.\n");
    AddDetail(({"vitrina"}), "Una gran vitrina se encuentra apoyada en la pared sur. En su interior puedes ver infinidad de armas: arcos, carcajs, espadas, armaduras...\n");
    AddRoomCmd("abrir", "cmd_abrir");
    AddRoomCmd("coger", "cmd_coger");
    AddItem(PNJ_PUESTO("conjurador"), REFRESH_HOME, (["Aggressive":1]), 1);
    AddItem(PNJ_PUESTO("sargento"), REFRESH_HOME, (["Aggressive":1]), 1+random(1));
    AddExit("este", HAB_PUESTO("puesto_guardias/puesto_piso1"));
}

int cmd_abrir(string str)
{
    if (!str && str != "vitrina" && str != "mueble" && str != "armero" && str != "armario") return 0;
    write ("Te acercas a la vitrina e intentas abrirla, pero parece cerrada con llave.\n");
    say(W(capitalize(TP->QueryName()) + " se acerca a la vitrina con intención de abrirla, pero tras varios intentos desiste en su empeño.\n"), TP);
    return 1;
}

int cmd_coger(string str)
{
    if (!str || (str != "mapas" && str != "mapas de pared" && str != "mapa")) return 0;
    write ("Coger los mapas? Mejor los dejas donde están, que iba a resultar un poco sospechoso verte salir de aquí con todos esos mapas encima.\n");
    return 1;
}