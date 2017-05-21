/****************************************************************************
Fichero: sendero_base.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: Archivo base del sendero serpenteante de la parte este de la colina que asciende al castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("el sendero de la colina");
    switch(d4()){
        case 1:
            SetIntLong("Te encuentras en el serpenteante sendero que asciende desde la "
            "villa de Nandor hasta las inmediaciones del castillo de los Dhes-Bl�in, "
            "todo a tu alrededor son rocas sueltas, malas hierbas y peque�os �rboles "
            "en �ngulos inc�modos.\n En lo alto de la colina destaca la impresionante "
            "fortaleza, vigilante en todo momento del terreno que alberga.\n");
            break;
        case 2:
            SetIntLong("Te encuentras en medio de un sinuoso sendero que asciende la "
            "colina m�s importante del norte de Marhalt, por su parte este,pues all� "
            "es donde se encuentra la fortaleza de uno de los nobles m�s importantes de "
            "Simauria, de la casa de los Dhes-Bl�in.\n El terreno que pisas es "
            "inc�modo, salvaje y notablemente propenso a ca�das accidentales. Por lo "
            "cual se suele utilizar m�s bien poco, ya que para llegar hasta el castillo "
            "es m�s frecuente usar el otro camino empedrado, situado en la parte "
            "noroeste de la colina, y el cual presenta algo menos de inclinaci�n "
            "comparado con este sendero.\n");
            break;
        case 3:
            SetIntLong("Te encuentras en la parte este de la colina donde reina "
            "el expl�ndido castillo del noble de Nandor. Es un sendero horriblemente feo, "
            "inc�modo y cansino.\n En lo alto vigila, la enorme mole de piedra,  "
            "incesante tus movimientos y los de cualquiera que se atrevan a pasearse "
            "inconscientemente por aqu�.\n");
            break;
        case 4:
            SetIntLong("Est�s en la parte este de la colina m�s importante del norte de "
            "Marhalt, donde reina la impresionante fortaleza del noble de la regi�n.\n "
            "En tu parte este se encuentra la villa de Nandor, hacia el norte, junto a "
            "la falda de la colina, un espeso bosque ocupa todo lo que alcanza la "
            "vista desde aqu�, mientras que al sur lo �nico que se ve son unas temibles "
            "monta�as con el r�o Kandal a sus pies.\n");
            break;
    }
    AddDetail(({"suelo", "sendero"}), "Pisas un inc�modo sendero que asciende "
    "trabaj�samente la colina, serpenteando entre rid�culos arbolitos torcidos y "
    "multitud de rocas sueltas.\n");
    AddDetail("colina", "La colina rompe el paisage suave y ondulado como un descarnado "
    "pu�o de piedra que emerge s�bitamente del suelo. Desde aqu� puedes ver su "
    "vertiente oriental, un abrupto terrapl�n de varias decenas de metros de altura "
    "por el que serpentea un estrecho camino que asciende trabajosamente entre rocas "
    "y �rboles esmirriados y torcidos que se aferran a la �rida pared pedregosa como "
    "extra�os seres amarillentos a una calavera reseca.\n");

    AddDetail(({"fortaleza", "castillo"}),
    "La fortaleza se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificaci�n recia, sombr�a y angulosa, carente de todo atractivo "
    " art�stico pero sin duda bien situado y de construcci�n s�lida.\n Desde este punto "
    "de la colina se puede apreciar con mucho detalle su torre�n del nordeste y su "
    "peque�a, pero alta, torre del sudeste.\n");
    AddDetail(({"torre�n del nordeste", "torre�n de C�nor", "torre�n de c�nor", "c�nor",
        "torreon del nordeste", "torreon de C�nor", "torreon de c�nor", "c�nor"}),
    "El torre�n de C�nor recibe �ste nombre en honor al famoso h�roe que inici� la "
    "l�nea Desh'Blain.\n"
    "Est� constru�do en forma cil�ndrica para evitar los puntos d�biles ofrecidos en las "
    "torres con esquinas que al ser derrumbadas ocasionan la ruina de toda la "
    "fortificaci�n, y con el objetivo de dotar a la estructura de mas resistencia al "
    "estar repartido por igual el peso sobre la obra exterior. Se apoya sobre "
    "robustos contrafuertes, una especie de cortos muros laterales de no mas de un "
    "metro de anchura que se van estrechando hacia arriba. Unas angostas aspilleras "
    "oradadas a lo largo de los muros proporcionan puntos de vigilancia y disparo a los "
    "defensores. La parte superior est� protegida por almenas algo sobresalientes, "
    "apoyadas sobre una serie de gradas invertidas, de forma que la parte superior del "
    "torre�n es mas amplia que el cuerpo propiamente dicho.\n");
    AddDetail(({"torre delgada", "torre de la dama", "dama", "torre del sudeste",
        "torre peque�a"}), "La torre de la Dama, algo mas "
    "alta que los torreones y la torre del homenaje, se iergue en la uni�n de las "
    "partes sur y este de las murallas, justo al borde del acantilado cortado a pico "
    "sobre los verdes pastos de Nandor a orillas del r�o.\n"
    "Es una edificaci�n cuadrada y espigada, sirviendo mas como torre de vigilancia que "
    "como parte defensiva. Su construcci�n es algo tosca, no comparable a la de los "
    "grandes torreones y la muralla norte.\n");

    AddDetail(({"Nandor", "nandor", "villa", "pueblo", "aldea"}),
    "La villa de Nandor se extiende al este, en el interior de una suave hondonada que "
    "acuna sus sencillas construcciones de piedra y madera.\n Hacia el sudeste, el "
    "verde dosel del bosque de Maralth se recorta contra el cielo, al otro lado de "
    "la depresi�n del terreno.\n");
    AddDetail(({"cored", "Cored"}),
    "El bosque viejo de Cored parece emanar una negrura sobrenatural en el norte. "
    "Es denso y no es posible apreciar ning�n detalle a trav�s de su gama de colores "
    "oscuros. Todo lo que espresa su vegetaci�n es intranquilidad.\n");
AddDetail(({"murallas", "muralla", "muro", "pared", "paredes"}),
    "Las fuertes murallas que protegen el castillo "
    "cercan el patio de armas por tres de sus lados, alz�ndose en hileras de grandes "
    "bloques de piedra cada una de las cuales se apoya sobre otras dos, haciendo el "
    "muro mas resistente y evitando que se derrumbe por el peso.\n");
    SetIndoors(0);
    SetLocate("el norte de Marhalt");
    if(d10()==1)
        AddItem(PNJCASTILLO("hombre_armas1"), REFRESH_DESTRUCT);
}

