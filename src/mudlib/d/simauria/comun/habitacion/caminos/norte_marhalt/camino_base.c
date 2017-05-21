/****************************************************************************
Fichero: camino_base.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: Archivo base del camino del norte de Marhalt que se dirije hacia el pomar
y bordea la colina del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("el camino del norte de Marhalt");

    switch(d3()){
        case 1:
            SetIntLong("Te encuentras en el camino del Norte de Marhalt, en alg�n punto "
            "de la larga ruta que comunica la peque�a poblaci�n agr�cola de Nandor con "
            "el poblado de Enalel, en el lejano norte, y con las a�n m�s distantes "
            "monta�as septentrionales.\n Su construcci�n se remonta a los tiempos de "
            "los primeros hombres y los grandes se�ores de Ishtria, cuando florec�an "
            "las alianzas comerciales y militares entre humanos y semi elfos, y "
            "decenas de caravanas mercantes recorr�an diariamente la gran distancia "
            "que separa ambas regiones.\n En aquellos tiempos el camino estaba "
            "adoquinado con enormes losas gran�ticas de corte exagonal que ahora "
            "aparecen resquebrajadas, desmenuzadas y en la mayor parte del trayecto "
            "han sido sustituidas por un firme de tierra pisada, fangosa y revuelta "
            "por el paso de personas, caballos y carretas.\n");
            break;
        case 2:
            SetIntLong("Te encuentras en el camino del Norte de Marhalt, en alg�n punto "
            "de la larga ruta que comunica la peque�a poblaci�n agr�cola de Nandor con "
            "el poblado de Enalel, en el lejano norte, y con las a�n m�s distantes "
            "monta�as septentrionales. En la actualidad pocos son los que osan transitar "
            "por estos lugares, y los que se atreven se hacen acompa�ar por grandes "
            "destacamentos de soldados, aunque esto tampoco es una garant�a de "
            "seguridad.\n Los ogros abandonan sus guaridas en las monta�as y caen como "
            "fieras sobre los viajeros. Los orcos y los goblins saquean y asesinan como "
            "buitres hambrientos y los feroces bandidos de Cored atacan indistintamente "
            "a soldados y comerciantes. Todo esto a provocado que los nobles humanos se "
            "guarezcan tras sus muros para proteger sus tesoros y sus cosechas, "
            "mientras los semielfos de Enalel protegen con el corage que da la "
            "desesperaci�n sus manzanos y sus ogares. Solo los muy ambiciosos o los muy "
            "desesperados se preocupan ahora del comercio.\n");
            break;
        case 3:
            SetIntLong("Est�s en el largo camino del norte de Marhalt, el cual une "
            "la importante aldea de Nandor con el norte del dominio de Simauria.\n"
            "El camino serpentea junto a la falda de una colina, en cuya cima, un "
            "castillo parece cernirse sobre los viajeros. Notas clavarse en ti la "
            "mirada atenta de los vig�as apostados en las torres y la muralla, lo que "
            "te inpulsa a apurar el paso.\n Hacia el sureste, medio ocultos por la "
            "colina, distingues los tejados de la aldea de nandor, enmarcados por las "
            "verdes copas de los �rboles del bosque de Marhalt, que se recortan contra "
            "el cielo.\n En toda la parte norte, el sombr�o bosque de Cored se "
            "fusiona con la arboleda de Marhalt, que se estiende hacia el nordeste hasta "
            "donde alcanza la vista.\n");
            break;
    }

    switch(d4()){
        case 1:
            SetIntLong(QueryIntLong()+ "En este punto el antiguo pavimento de losas "
            "exagonales aparece casi intacto, aunque briznas de hierba crecen en las "
            "junturas y algunas losas aparecen resquebrajadas y partidas.\n");
            break;
        case 2:
            SetIntLong(QueryIntLong()+ "Caminas pisando cascotes resquebrajados que sin "
            "duda alguna vez formaron parte de un pavimento explendoroso.\n");
            break;
        case 3:
            SetIntLong(QueryIntLong()+ "Este es uno de los pocos puntos del camino en "
            "los que el antiguo pavimento aparece intacto, losas gran�ticas exagonales "
            "sobre las que podr�a caber una diligencia, unidas con tal precisi�n que "
            "apenas se distinguen las junturas. Sin duda esto es obra de maestros "
            "canteros enanos.\n");
            break;
        case 4:
            SetIntLong(QueryIntLong()+ "En este punto el terreno se ve especialmente "
            "enfangado y pisoteado. Los restos de armas en el suelo y el color rojo "
            "intenso del fango demuestran que aqu� hubo una pelea encarnizada, y no "
            "hace demasiado.\n");
            break;
    }
    AddDetail("colina", "La colina rompe el paisage suave y ondulado como un descarnado "
    "pu�o de piedra que emerge s�bitamente del suelo. Desde aqu� puedes ver su "
    "vertiente oriental, un abrupto terrapl�n de varias decenas de metros de altura "
    "por el que serpentea un estrecho camino que asciende trabajosamente entre rocas "
    "y �rboles esmirriados y torcidos que se aferran a la �rida pared pedregosa como "
    "extra�os seres amarillentos a una calavera reseca.\n");

    AddDetail("castillo", "Se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificaci�n recia, sombr�a y angulosa, carente de todo atractivo "
    " art�stico pero sin duda bien situado y de construcci�n s�lida.\n");

    AddDetail(({"Nandor", "nandor", "villa", "pueblo", "aldea"}),
    "La villa de Nandor se extiende al este, en el interior de una suave hondonada que "
    "acuna sus sencillas construcciones de piedra y madera.\n Hacia el sudeste, el "
    "verde dosel del bosque de Maralth se recorta contra el cielo, al otro lado de "
    "la depresi�n del terreno.\n");


    SetIndoors(0);
    SetLocate("el norte de Marhalt");
    if(d20()==1)
        AddItem(PNJ("camino/viajero"),REFRESH_DESTRUCT);
}

