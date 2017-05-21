/* Archivo        granja03.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   Calle de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/granja");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"En este lugar gira hacia el oeste, donde hay "
        "más estancias; mientras que asciende al norte hacia los establos, "
        "los campos y la casa de los administradores. Al este puedes ver "
        "el molino y al sur un río.\n");
    SetIntNoise("Escuchas a los animales a tu alrededor y el sonido del agua "
        "del río entrando en el canal del molino.\n");
    SetIntSmell("Huele a humedad...,  lo habitual estando al lado del río.\n");
    AddDetail(({"charco", "charcos"}), "Son pequeños charquitos de aguas que "
        "la fuerza de la corriente salpica al camino.\n");
    AddDetail(({"molino", "este"}), "Se trata de una construcción de piedra "
        "bastante grande que contiene la maquinaria del molino de la aldea. "
        "Tiene un canal y un pequeño puente que lo cruza.\nTiene una especie "
        "de aliviadero o compuerta que permite la entrada o salida del agua.\n"
        "El tejado de la edificación va a dos aguas y la cubierta ha sido "
        "construida con lajas de pizarra.\n");
    AddDetail(({"esclusa"}), "Sirve para controlar la fuerza del caudal que "
        "mueve las ruedas del molino.\n");
    AddDetail(({"puente"}), "Cruza el canal y da entrada al molino.\n");
    AddDetail(({"río","rio"}),"Es el río Kandal que nace en las montañas del "
        "nordeste. Aquí todavía no alcanza el gran tamaño que tendrá en las "
        "llanuras, pero es muy caudaloso y sus aguas tienen una gran fuerza, "
        "útil para mover los molinos y batanes.\n");
    AddExit("norte", SHERALD("granja/granja02"));
    AddExit("sudeste", SHERALD("granja/molino00"));
    AddExit("oeste", SHERALD("granja/granja04"));
}
