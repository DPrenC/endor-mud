/****************************************************************************
Fichero: tabernera_gorat.c
Autor: Ratwor
Fecha: 29/07/2006
Descripción: una tabernera para la tasca de Gorat
****************************************************************************/

#include "./path.h"
# <properties.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("Nuldhan", "humano", 8, GENDER_FEMALE);
    SetShort("Nuldhan la tabernera");
    SetLong("Esta es la tabernera de la única tasca de Gorat, algo gordita y fea, pero "
    "teniendo en cuenta su edad es normal. Mientras su marido faena de pescador, ella se "
    "queda en el local atendiendo a los ciudadanos y funcionarios del pueblo.\n");
    AddId(({"tabernera", "gorda", "gordita", "fea", "humana", "mujer", "nuldhan"}));
    SetCitizenship("gorat");
    Set(P_CANT_LURE,1);
    InitChats(1, ({"La tabernera pasa un trapo por encima del mostrador.\n",
        "La tabernera te mira curiosa.\n", "La tabernera canturrea en voz baja.\n",
        "La tabernera suspira.\n", "Un mosquito te pasa cerca de la oreja.\n"}));
    InitAChats(10, ({"La tabernera grita: ¡Socorro, socorro!.\n"}));
    SetSmell("Huele un poco a pescado.\n");
    AddQuestion(({"pesca", "pescar"}), "La tabernera te dice: tenemos un puerto y un "
    "muelle algo pequeño, pero con buena pesca para entretenerse.\n");
    AddQuestion("marido", "La tabernera te dice: ahora mismo está faenando en alta mar.\n");
    AddQuestion("faro", "La tabernera te dice: desde que se rompió se están teniendo "
    "algunos problemillas con los barcos pesqueros.\n");
    AddQuestion(({"gorat", "pueblo"}), "La tabernera te dice: a mi me gusta este pueblo, es pequeñito,"
    " gracioso, bien comunicado por tierra y mar y, tenemos trabajo para todos.\n ");
    AddQuestion(({"tasca", "taberna", "negocio"}), "La tabernera dice: Mi marido y yo "
    "llevamos este local desde que nos casamos hace mucho tiempo, tenemos los clientes "
    "del pueblo, que, junto con los guardias y los funcionarios, hacen de esta tasca "
    "un buen negocio.\n");
    AddQuestion(({"clientes", "comensales", "ciudadanos", "funcionarios"}),
    "La tabernera dice: ya los ves, comen y se divierten.\n");
    AddQuestion(({"guardias", "soldados", "sargentos"}), "La tabernera te dice: quizá hay"
    " demasiados, pero así nos encontramos más seguros con ellos.\n");
    SetShrugMsg("La tabernera dice: ¿cómo?");

}
