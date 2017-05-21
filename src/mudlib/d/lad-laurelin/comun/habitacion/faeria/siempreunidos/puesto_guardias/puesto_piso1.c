/***
Fichero puesto_piso1.c
Autor: kastwey@simauria
Descripción: Dormitorio de los guardias.
Creación: 05/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");


create()
{
    ::create();
    SetIntShort("el dormitorio de los guardias");
    SetIntLong(W("Te encuentras en el dormitorio de los guardias que protegen el pueblo de Siempreunidos.\n"
    "Es una habitación espaciosa, repleta de camastros. Al fondo de la sala puedes ver una mesa y algunas sillas.\n"
    "Sin duda, es aquí donde los guardias suben a descansar o a dormir cuando no les toca estar en el puesto de vigilancia.\n"
    "Hacia el oeste ves lo que parece una sala de reuniones, y al este otra pequeña sala que parece hacer las funciones de comedor y sala de descanso.\n"));
    SetOficina(HAB_PUESTO("puesto_guardias/puesto_guardias"));
    SetIndoors(1);
    SetIntBright(25);
    SetIntSmell("Hmm. No huele precísamente a rosas.\n");
    AddDetail(({"camas", "cama", "camastros", "camastro"}), W("Más que camas estas no son más que colchones de paja o lana tirados en el suelo.\n"
    "No parecen demasiado cómodas, aunque seguro que es mejor que dormir sobre el suelo.\n"));
    AddDetail(({"mesas", "mesa"}), W("Es una mesa rectangular apoyada en una de las paredes de la estancia.\n"
    "Tiene algunas sillas a su alrededor.\n"));
    AddDetail(({"silla", "sillas"}), "Son unas sillas colocadas alrededor de la mesa. Aquí suelen sentarse los guardias a descansar, a jugar a las cartas... en definitiva, a pasar el tiempo cuando no tienen nada mejor que hacer.\n");
    AddItem(PNJ_PUESTO("soldado_piso1"), REFRESH_HOME,(["PedirRefuerzos":0]), 1 + random(3));
    AddItem(PNJ_PUESTO("sargento_piso1"), REFRESH_HOME, (["PedirRefuerzos":0]),1 + random(2));
    AddExit("oeste", HAB_PUESTO("puesto_guardias/puesto_reuniones"));
    AddExit("este", HAB_PUESTO("puesto_guardias/puesto_estar"));
    AddExit("abajo", HAB_PUESTO("puesto_guardias/puesto_guardias"));
}


init()
{
	  ::init();
	  if (QueryExits() && QueryExits()["este"]) load_object(QueryExits()["este"]);
	  if (QueryExits() && QueryExits()["oeste"]) load_object(QueryExits()["oeste"]);
}

public int QueryPiso1() { return 1; }
	