/* Archivo        granja03.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripci�n:   Calle de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/granja");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"En este lugar gira hacia el oeste, donde hay "
        "m�s estancias; mientras que asciende al norte hacia los establos, "
        "los campos y la casa de los administradores. Al este puedes ver "
        "el molino y al sur un r�o.\n");
    SetIntNoise("Escuchas a los animales a tu alrededor y el sonido del agua "
        "del r�o entrando en el canal del molino.\n");
    SetIntSmell("Huele a humedad...,  lo habitual estando al lado del r�o.\n");
    AddDetail(({"charco", "charcos"}), "Son peque�os charquitos de aguas que "
        "la fuerza de la corriente salpica al camino.\n");
    AddDetail(({"molino", "este"}), "Se trata de una construcci�n de piedra "
        "bastante grande que contiene la maquinaria del molino de la aldea. "
        "Tiene un canal y un peque�o puente que lo cruza.\nTiene una especie "
        "de aliviadero o compuerta que permite la entrada o salida del agua.\n"
        "El tejado de la edificaci�n va a dos aguas y la cubierta ha sido "
        "construida con lajas de pizarra.\n");
    AddDetail(({"esclusa"}), "Sirve para controlar la fuerza del caudal que "
        "mueve las ruedas del molino.\n");
    AddDetail(({"puente"}), "Cruza el canal y da entrada al molino.\n");
    AddDetail(({"r�o","rio"}),"Es el r�o Kandal que nace en las monta�as del "
        "nordeste. Aqu� todav�a no alcanza el gran tama�o que tendr� en las "
        "llanuras, pero es muy caudaloso y sus aguas tienen una gran fuerza, "
        "�til para mover los molinos y batanes.\n");
    AddExit("norte", SHERALD("granja/granja02"));
    AddExit("sudeste", SHERALD("granja/molino00"));
    AddExit("oeste", SHERALD("granja/granja04"));
}
