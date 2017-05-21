/****************************************************************************
Fichero: camino_base.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: Archivo base del camino empedrado del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("un camino empedrado");
    switch(d4()){
        case 1:
            SetIntLong("Te encuentras en un pequeño camino empedrado que se dirije desde "
            "el camino del norte de Marhalt hasta la misma puerta del castillo del "
            "noble de la región.\n Este camino está mejor cuidado que el serpenteante "
            "sendero de la parte este de la colina, pues por aquí existe menos pendiente "
            "y se utiliza mejor para el acceso de carros hacia la fortaleza.\n");
            break;
        case 2:
            SetIntLong("Este es el camino principal para acceder a la fortaleza "
            "que reina sobre la colina. Es la parte más allanada y, por tanto, es "
            "más cómodo para los carros y las carretas, por ello se encuentra empedrado "
            "y su mantenimiento es constante para guardar las apariencias.\n");
            break;
        case 3:
            SetIntLong("Desde la misma puerta del castillo del noble de Nandor sale este "
            "camino empedrado, el cual va a unirse, más hacia el norte con el camino "
            "del norte de Marhalt. Se encuentra en bastante buen estado, pues es "
            "la mejor opción para acceder a la fortaleza, y el noble no quiere "
            "descuidarlo por ser la primera impresión que se lleva el viajante que "
            "llega hasta aquí.\n");
            break;
        case 4:
            SetIntLong("Pisas el empedrado de uno de los accesos a la fortaleza que "
            "reina sobre la colina, y de los dos caminos que llegan hasta sus puertas "
            "este es el más accesible, ya que el otro sólo es un simple sendero "
            "serpenteante e inclinado.\n Por aquí es por donde llegan hasta el castillo "
            "los viajantes en sus carros, ya que esta parte del noroeste de la colina "
            "es la más accesible por tener menos pendiente respecto a la del este.\n");
            break;
    }
    AddDetail(({"suelo", "camino", "empedrado", "suelo empedrado", "camino empedrado"}),
"El suelo de este camino está bien empedrado y bien cuidado, pues el noble así lo "
"desea. Son cantos rodados de mediano tamaño y de roca normal y corriente que se "
"encontraría en cualquier lugar pedregoso.\n");
    AddDetail("colina", "La colina rompe el paisage suave y ondulado como un descarnado "
    "puño de piedra que emerge súbitamente del suelo. Desde aquí puedes ver la "
    "pendiente que hay por el otro lado de la colina, el del este, donde a sus piés se "
    "asienta la villa de Nandor.\n");
    AddDetail(({"fortaleza", "castillo"}),
    "La fortaleza se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificación recia, sombría y angulosa, carente de todo atractivo "
    " artístico pero sin duda bien situado y de construcción sólida.\n");

    AddDetail(({"Nandor", "nandor", "villa", "pueblo", "aldea"}),
    "La villa de Nandor se extiende al este, en el interior de una suave hondonada que "
    "acuna sus sencillas construcciones de piedra y madera.\n Hacia el sudeste, el "
    "verde dosel del bosque de Maralth se recorta contra el cielo, al otro lado de "
    "la depresión del terreno.\n");
    AddDetail(({"cored", "Cored"}),
    "El bosque viejo de Cored parece emanar una negrura sobrenatural en el norte. "
    "Es denso y no es posible apreciar ningún detalle a través de su gama de colores "
    "oscuros. Todo lo que espresa su vegetación es intranquilidad.\n");
AddDetail(({"murallas", "muralla", "muro", "pared", "paredes"}),
    "Las fuertes murallas que protegen el castillo "
    "cercan el patio de armas por tres de sus lados, alzándose en hileras de grandes "
    "bloques de piedra cada una de las cuales se apoya sobre otras dos, haciendo el "
    "muro mas resistente y evitando que se derrumbe por el peso.\n");
    SetIndoors(0);
    SetLocate("el norte de Marhalt");
    if(d6()==1)
        AddItem(PNJCASTILLO("hombre_armas1"), REFRESH_DESTRUCT);
}

