/* Archivo:         casagranjero01.C
   Autor:           Yalin y Lug
   Descripci�n:     casa de los administradores en la granja de la aldea de Sloch
   Fecha:           22/05/2006
*/
#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("la casa de los administradores de la granja de la aldea de Sloch");
    SetIntLong("Te encuentras en una amplia estancia que forma la parte baja "
        "de la casa de los administradores de la granja de la aldea de Sloch. "
        "Aqu� es donde el administrador de turno que lleva la granja hace "
        "las cuentas con cada uno de los aldeanos libres que trabajan para "
        "la abad�a en sus campos.\n A tu alrededor puedes ver algunas sillas "
        "de madera apoyadas contra las paredes, una gran mesa tras la que "
        "se coloca el administrador para despachar con las diferentes "
        "personas que a menudo pasan por aqu�, tambi�n puedes ver una "
        "estanter�a a lo largo de una de las paredes.\n Hay una escalera de "
        "madera que asciende hacia la parte de habitaci�n de la casa y una "
        "trampilla en el suelo que da paso al s�tano.\n");
    SetIntSmell("Huele a viejos pergaminos almacenados y a tinta de calamar.\n");
    SetIntNoise("Puedes escuchar los sonidos apagados de la calle que se cuelan por la puerta entreabierta.\n");
    AddDetail(({"suelo"}), "es un entarimado de madera bastante pulido. Ext� "
        "algo sucio ya que los granjeros y aldeanos que entran aqu� no son "
        "demasiado cuidadosos.\n");
    AddDetail(({"pared", "paredes"}), "las paredes aqu� est�n revestidas de "
        "madera hasta media altura, el resto es piedra pintada de azul.\n");
    AddDetail(({"techo"}), "Es un techo de madera no muy alto sostenido por "
        "fuertes vigas que lo cruzan de lado a lado.\n");
    AddDetail(({"viga", "vigas"}), "Son gruesos troncos pulidos y pintados "
        "que soportan el peso de la planta superior de la casa. De ellas "
        "cuelgan tres l�mparas de aceite.\n");
    AddDetail(({"lamparas","l�mparas","lampara","l�mpara"}), "Son unas "
        "l�mparas de aceite de fino cristal y de bronce que sirven para "
        "iluminar la gran estancia en la que estamos cuando no hay luz "
        "natural.\n");
    AddDetail(({"estanteria", "estanter�a", "estantes"}), "Se trata de unos "
        "estantes fijados a la pared en la que se alinean los libros de la "
        "contabilidad de todo el entramado de la granja.\n");
    AddDetail(({"libros", "libros", "rollo", "rollos"}), "Son los rollos de "
        "pergamino en los que se van anotando las cuestiones particulares de "
        "cada asunto de la granja. Son bastante grandes y permanecen "
        "apilados de pie uno al lado del otro. Para que no se abran, est�n "
        "atados con una cinta de tela.\n");
    AddDetail(({"mesa", "mesa grande"}), "Es una larga mesa de madera "
        "bastante gruesa. Est� muy pulida y tiene una p�tina por el paso de "
        "los a�os. Sobre ella se extienden los rollos de pergamino en los "
        "que se toman las anotaciones.\n");
    AddDetail(({"silla", "sillas"}), "son sillas de madera que se adosan a "
        "la pared donde se sientan a esperar los aldeanos y trabajadores de "
        "la granja cuando el administrador no puede atenderles de inmediato.\n");
    AddItem(PNJ("sherek/aldea/guardian2"),REFRESH_DESTRUCT,1);
    AddExit("oeste", SHERALD("casas/casagranja00"));
    AddExit("este", SHERALD("casas/casagranja03"));
    AddExit("abajo", SHERALD("casas/casagranja02"));
    AddExit("arriba", SHERALD("casas/casagranja04"));
}
