/****************************************************************************
Fichero: sendero_base.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: Archivo base del sendero serpenteante de la parte este de la colina que asciende al castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("el sendero de la colina");
    switch(d4()){
        case 1:
            SetIntLong("Te encuentras en el serpenteante sendero que asciende desde la "
            "villa de Nandor hasta las inmediaciones del castillo de los Dhes-Bláin, "
            "todo a tu alrededor son rocas sueltas, malas hierbas y pequeños árboles "
            "en ángulos incómodos.\n En lo alto de la colina destaca la impresionante "
            "fortaleza, vigilante en todo momento del terreno que alberga.\n");
            break;
        case 2:
            SetIntLong("Te encuentras en medio de un sinuoso sendero que asciende la "
            "colina más importante del norte de Marhalt, por su parte este,pues allí "
            "es donde se encuentra la fortaleza de uno de los nobles más importantes de "
            "Simauria, de la casa de los Dhes-Bláin.\n El terreno que pisas es "
            "incómodo, salvaje y notablemente propenso a caídas accidentales. Por lo "
            "cual se suele utilizar más bien poco, ya que para llegar hasta el castillo "
            "es más frecuente usar el otro camino empedrado, situado en la parte "
            "noroeste de la colina, y el cual presenta algo menos de inclinación "
            "comparado con este sendero.\n");
            break;
        case 3:
            SetIntLong("Te encuentras en la parte este de la colina donde reina "
            "el expléndido castillo del noble de Nandor. Es un sendero horriblemente feo, "
            "incómodo y cansino.\n En lo alto vigila, la enorme mole de piedra,  "
            "incesante tus movimientos y los de cualquiera que se atrevan a pasearse "
            "inconscientemente por aquí.\n");
            break;
        case 4:
            SetIntLong("Estás en la parte este de la colina más importante del norte de "
            "Marhalt, donde reina la impresionante fortaleza del noble de la región.\n "
            "En tu parte este se encuentra la villa de Nandor, hacia el norte, junto a "
            "la falda de la colina, un espeso bosque ocupa todo lo que alcanza la "
            "vista desde aquí, mientras que al sur lo único que se ve son unas temibles "
            "montañas con el río Kandal a sus pies.\n");
            break;
    }
    AddDetail(({"suelo", "sendero"}), "Pisas un incómodo sendero que asciende "
    "trabajósamente la colina, serpenteando entre ridículos arbolitos torcidos y "
    "multitud de rocas sueltas.\n");
    AddDetail("colina", "La colina rompe el paisage suave y ondulado como un descarnado "
    "puño de piedra que emerge súbitamente del suelo. Desde aquí puedes ver su "
    "vertiente oriental, un abrupto terraplén de varias decenas de metros de altura "
    "por el que serpentea un estrecho camino que asciende trabajosamente entre rocas "
    "y árboles esmirriados y torcidos que se aferran a la árida pared pedregosa como "
    "extraños seres amarillentos a una calavera reseca.\n");

    AddDetail(({"fortaleza", "castillo"}),
    "La fortaleza se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificación recia, sombría y angulosa, carente de todo atractivo "
    " artístico pero sin duda bien situado y de construcción sólida.\n Desde este punto "
    "de la colina se puede apreciar con mucho detalle su torreón del nordeste y su "
    "pequeña, pero alta, torre del sudeste.\n");
    AddDetail(({"torreón del nordeste", "torreón de Cónor", "torreón de cónor", "cónor",
        "torreon del nordeste", "torreon de Cónor", "torreon de cónor", "cónor"}),
    "El torreón de Cónor recibe éste nombre en honor al famoso héroe que inició la "
    "línea Desh'Blain.\n"
    "Está construído en forma cilíndrica para evitar los puntos débiles ofrecidos en las "
    "torres con esquinas que al ser derrumbadas ocasionan la ruina de toda la "
    "fortificación, y con el objetivo de dotar a la estructura de mas resistencia al "
    "estar repartido por igual el peso sobre la obra exterior. Se apoya sobre "
    "robustos contrafuertes, una especie de cortos muros laterales de no mas de un "
    "metro de anchura que se van estrechando hacia arriba. Unas angostas aspilleras "
    "oradadas a lo largo de los muros proporcionan puntos de vigilancia y disparo a los "
    "defensores. La parte superior está protegida por almenas algo sobresalientes, "
    "apoyadas sobre una serie de gradas invertidas, de forma que la parte superior del "
    "torreón es mas amplia que el cuerpo propiamente dicho.\n");
    AddDetail(({"torre delgada", "torre de la dama", "dama", "torre del sudeste",
        "torre pequeña"}), "La torre de la Dama, algo mas "
    "alta que los torreones y la torre del homenaje, se iergue en la unión de las "
    "partes sur y este de las murallas, justo al borde del acantilado cortado a pico "
    "sobre los verdes pastos de Nandor a orillas del río.\n"
    "Es una edificación cuadrada y espigada, sirviendo mas como torre de vigilancia que "
    "como parte defensiva. Su construcción es algo tosca, no comparable a la de los "
    "grandes torreones y la muralla norte.\n");

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
    if(d10()==1)
        AddItem(PNJCASTILLO("hombre_armas1"), REFRESH_DESTRUCT);
}

