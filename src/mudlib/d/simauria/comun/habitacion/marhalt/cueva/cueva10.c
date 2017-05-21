/***********************************************************
*    Nombre: cueva10.c			                   *
*    Localizacion: Cueva de los Trolls                     *
*    Realizada por : Cajun, el ejecutor                    *
*    Creado : 20-12-99                                     *
*    Modificado: 07-02-00  -> Incorporar función buscar    *
*                08-02-00  -> Mejora de la función inicio  *
************************************************************/


#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <properties.h>

inherit MARHCUEVA("cueva_base");
#define FLAG "tc10"

string QueryIntLong(){
    if (TP->Query(FLAG)){
        return "El pasillo se abre en una gran sala con el techo muy alto, algunos "
        "salpicones de sangre manchan las sucias paredes. Esparcido por el suelo "
		"se identifica algunas armas viejas y oxidadas amontonadas junto con multitud "
		"de objetos indescriptibles.\n";
    }
    return "El pasillo se abre en una gran sala con el techo muy alto, "
		"algunos salpicones de sangre manchan las sucias paredes. Esparcido por el suelo "
		"se identifica algunas armas viejas y oxidadas amontonadas junto con otros "
		"objetos indescriptibles. A lo mejor si buscas podrías encontrar algo de valor.\n";
}

int buscar(){
    int perc;
    object ob;

    if (!TP->QueryAttribute(FLAG))
    {
        TP->SetAttribute(FLAG, 1);
        perc=(TP->UseSkill(HAB_RASTREAR));

        write("Te acercas hacia el fondo de la sala y hurgas entre los restos de basura.\n");
        say (TP->QueryName()+ " se va al fondo de la habitación y rebusca por el suelo.\n");
        if (perc > 0)
        {
            write("Debajo de un trozo de tela encuentras una gema.\n");
            ob=clone_object(OTRO("gema"));
            ob->move(TO, M_SILENT);
        }
        else
        write("Rebuscas pero no eres capaz de encontrar nada de valor.\n");

    }
    else
    write("Por mas que rebuscas no eres capaz de encontrar nada de valor entre tanta basura.\n");
    return 1;
}

create () {
    ::create();
    AddDetail(({"arma", "objetos", "objetos indescriptibles", "basura"}),
    "sólo es un montón de basura de donde no debe de haber nada razonablemente en "
    "buen estado.\n");
    SetIntShort("una guarida troll");
    seteuid(getuid());
    SetIntSmell("Peferirías no haber abierto las fosas nasales.\n");
    AddRoomCmd("buscar",SF(buscar));
    AddExit("oeste", "./cueva09");
    AddItem(PNJ("marhalt/cueva/troll"),REFRESH_DESTRUCT,d3());
}
