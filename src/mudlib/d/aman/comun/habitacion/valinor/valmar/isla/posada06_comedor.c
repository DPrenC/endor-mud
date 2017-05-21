/*****************************************************************************************
 ARCHIVO:       posada06_comedor.c
 AUTOR:         Ztico
 FECHA:         13-04-2005
 DESCRIPCIÓN:   Posada del Unicornio Azul. Comedor principal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <keeper.h>

inherit PUB;
inherit KEEPER;

create()
{
    if(::create()) return 1;

    SetIntShort("el comedor Principal de la Posada");
    SetIntLong("Estás en una amplia sala donde puedes sentarte a comer los manjares que "
        "se cocinan en este lugar. Las mesas se distribuyen a lo largo de las paredes "
        "cubiertas de ventanales con bancos de piedra adosados a ellas sobre los que "
        "ves mullidos almohadones. En el centro del comedor se alza una redonda "
        "plataforma donde con suerte, podrás deleitarte contemplando bellas danzas o "
        "escuchando la música de los más selectos laúdes, arpas y liras de toda "
        "Faeria. Puedes acceder al átrio bajando las escaleras que hay hacia el sur.\n");
    AddDetail(({"mesa", "mesas"}), "Son mesas de madera, alargadas y con cuatro patas "
        "arqueadas.\n");
    AddDetail(({"ventanal", "ventanales"}), "Te asomas a uno de ellos y contemplas el "
        "movimiento de las copas de los robles que rodean la isla.\n");
    AddDetail(({"banco" ,"bancos"}), "Están hechos de granito labrado y perfectamente "
        "pulido.\n");
    AddDetail(({"almohadón", "almohadon", "almohadones"}), "Gracias a estos almohadones "
        "los bancos dan un aspecto mucho más cómodo y confortable.\n");
    AddDetail("plataforma", "Es una tarima alzada enmoquetada, de color rogo "
        "bermellón.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddFood("pato asado", "un plato de", 15, 15, 0, 0);
    AddFood("torta de miel con nueces", "una", 7, 9, 0, 0);
    AddFood("trucha con puerros", "una", 10, 13, 0, 0);
    AddDrink("hidromiel", "una jarra de", 6, 0, 8, 0);
    AddDrink("vino con granadas", "una taza de", 10, 10, 5, 0);
    AddDrink("cerveza negra", "una jarra de", 7, 7, 6, 0);

    AddExit("abajo", HAB_BOSQUE_ISLA("posada03_atrio.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("posada08_salon.c"));

    SetKeeper(PNJ_VALMAR("nerulf.c"));
}
