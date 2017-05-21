/**************************************************************************
fichero: taberna.c
Autor: kastwey
Creación: 21/07/2005
Descripción: La taberna para los soldados borrachuzos del centro de
entrenamiento
[t] 20/02(2009 Cambiado NOTIFY_FAIL por K_NOTIFY
**************************************************************************/
#include "./path.h"
#include <keeper.h>

inherit PUB;
inherit KEEPER;


string escuchar()
{
    object *inv;
    int personas;
    inv = all_inventory();
    personas = sizeof(filter(inv,(:living($1) && $1->id("enano_borracho"):)));
    if (!personas)
    {
        return W("La taberna está ahora muy silenciosa, pues no ves a tu "
                 "alrededor a los habituales enanos que suelen armar ruido "
                 "por aquí.\n");
    }
    if (personas == 1)
    // hay solo un enano
    {
        return "Escuchas a un enano cantando a voz en cuello.\n";
    }
    return W("Escuchas el ruido de risas y voces de los enanos que hay "
             "alborotando en el local.\n");
}



public void create()
{
    ::create();
    SetIntShort("la taberna Mi Entrañable Cerveza");
    SetIntLong(W("Te encuentras en una taberna donde a todas horas hay "
                 "movimiento. Enanos frecuentemente se reúnen aquí para "
                 "descargar las tensiones acumuladas en el Centro. El local "
                 "es bastante amplio, y tiene varias mesas con sillas, que "
                 "la mayor parte del día están ocupadas. La taberna es "
                 "famosa por la variedad de cerveza que puedes encontrar.\n"));
        SetIntSmell(W("El olor a cerveza impregna cada centímetro de este local. "
                  "Se nota que es la especialidad de la casa.\n"));
    SetIntNoise(#'escuchar);
    SetIndoors(1);
    SetIntBright(75);
    SetKeeper(PNJ_CIUDAD_ANNUFAM("fignus.c"),REFRESH_DESTRUCT,1);
    AddItem(PNJ_CIUDAD_ANNUFAM("enano_borracho"),REFRESH_DESTRUCT,random(5));
    AddDetail(({"mesas","mesa"}),
              W("Son un grupo de cindo o seis mesas, rodeadas todas ellas por sillas de madera, donde los enanos se sientan a cantar, hablar y emborracharse. El tabernero ha de ir muy a menudo a limpiarlas por el estropicio que éstos provocan.\n"));
    AddDetail(({"sillas","silla"}),W("Son simples sillas de madera que "
                "rodean las mesas de la taberna.\n"));
    AddDetail(({"mostrador","barra"}),W("Es una barra alargada, similar "
                "a la de la mayoría de las tabernas y bares. Al final hay "
                "un menú que puedes leer para saber lo que puedes pedir.\n"));
    AddDrink("cerveza rubia","una jarra de",3,6,5,0,W("Te bebes una jarra de "
             "cerveza rubia. ¡Deliciosa! Notas como te refresca a la vez que "
             "sientes como te achispas por momentos."));
    AddDrink("cerveza negra","una jarra de",5,10,7,0,W("Te bebes una jarra "
             "de cerveza negra. Es de sabor fuerte pero te resulta "
             "muy agradable."));
    AddDrink("cerveza de importación","una jarra de",10,15,9,0,W("Te bebes "
             "una deliciosa jarra de cerveza de importación. Sin duda "
             "una de las mejores cervezas que has probado."));
    AddFood("tarta de cerveza","un trozo de",10,8,0,W("Te comes un "
                "trozo de tarta de cerveza. Hmmm cuanto menos, un sabor "
                "original."));
    AddFood("pollo a la cerveza","un plato de",15,17,0,W("Te comes un plato "
            "de pollo a la cerveza. La verdad es que aquí saben cocinar... "
            "!Estaba buenísimo!"));
    AddFood("atún a la salsa cervecera","un plato de",10,14,0,W("Te comes un "
            "plato de atún a la salsa cervecera... Un plato original, "
            "y a la vez para chuparse los dedos... Lo cierto es que no "
            "te importaría repetir..."));

    AddExit("norte",HAB_UNGRIM_ANNUFAM("ungrim_07"));
}


int _porder(string str)
// sobrecargamos esta función por si no hay tabernero
{
    //if (CantAttend(NOTIFY_FAIL)) return 0;
    if (CantAttend(K_NOTIFY)) return 0;
    return ::_porder(str);
}

