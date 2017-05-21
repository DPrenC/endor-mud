/****************************************************************************
Fichero: camino_base.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: Archivo base del camino del norte de Marhalt que se dirije hacia el pomar
y bordea la colina del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("el camino del norte de Marhalt");

    switch(d3()){
        case 1:
            SetIntLong("Te encuentras en el camino del Norte de Marhalt, en algún punto "
            "de la larga ruta que comunica la pequeña población agrícola de Nandor con "
            "el poblado de Enalel, en el lejano norte, y con las aún más distantes "
            "montañas septentrionales.\n Su construcción se remonta a los tiempos de "
            "los primeros hombres y los grandes señores de Ishtria, cuando florecían "
            "las alianzas comerciales y militares entre humanos y semi elfos, y "
            "decenas de caravanas mercantes recorrían diariamente la gran distancia "
            "que separa ambas regiones.\n En aquellos tiempos el camino estaba "
            "adoquinado con enormes losas graníticas de corte exagonal que ahora "
            "aparecen resquebrajadas, desmenuzadas y en la mayor parte del trayecto "
            "han sido sustituidas por un firme de tierra pisada, fangosa y revuelta "
            "por el paso de personas, caballos y carretas.\n");
            break;
        case 2:
            SetIntLong("Te encuentras en el camino del Norte de Marhalt, en algún punto "
            "de la larga ruta que comunica la pequeña población agrícola de Nandor con "
            "el poblado de Enalel, en el lejano norte, y con las aún más distantes "
            "montañas septentrionales. En la actualidad pocos son los que osan transitar "
            "por estos lugares, y los que se atreven se hacen acompañar por grandes "
            "destacamentos de soldados, aunque esto tampoco es una garantía de "
            "seguridad.\n Los ogros abandonan sus guaridas en las montañas y caen como "
            "fieras sobre los viajeros. Los orcos y los goblins saquean y asesinan como "
            "buitres hambrientos y los feroces bandidos de Cored atacan indistintamente "
            "a soldados y comerciantes. Todo esto a provocado que los nobles humanos se "
            "guarezcan tras sus muros para proteger sus tesoros y sus cosechas, "
            "mientras los semielfos de Enalel protegen con el corage que da la "
            "desesperación sus manzanos y sus ogares. Solo los muy ambiciosos o los muy "
            "desesperados se preocupan ahora del comercio.\n");
            break;
        case 3:
            SetIntLong("Estás en el largo camino del norte de Marhalt, el cual une "
            "la importante aldea de Nandor con el norte del dominio de Simauria.\n"
            "El camino serpentea junto a la falda de una colina, en cuya cima, un "
            "castillo parece cernirse sobre los viajeros. Notas clavarse en ti la "
            "mirada atenta de los vigías apostados en las torres y la muralla, lo que "
            "te inpulsa a apurar el paso.\n Hacia el sureste, medio ocultos por la "
            "colina, distingues los tejados de la aldea de nandor, enmarcados por las "
            "verdes copas de los árboles del bosque de Marhalt, que se recortan contra "
            "el cielo.\n En toda la parte norte, el sombrío bosque de Cored se "
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
            "los que el antiguo pavimento aparece intacto, losas graníticas exagonales "
            "sobre las que podría caber una diligencia, unidas con tal precisión que "
            "apenas se distinguen las junturas. Sin duda esto es obra de maestros "
            "canteros enanos.\n");
            break;
        case 4:
            SetIntLong(QueryIntLong()+ "En este punto el terreno se ve especialmente "
            "enfangado y pisoteado. Los restos de armas en el suelo y el color rojo "
            "intenso del fango demuestran que aquí hubo una pelea encarnizada, y no "
            "hace demasiado.\n");
            break;
    }
    AddDetail("colina", "La colina rompe el paisage suave y ondulado como un descarnado "
    "puño de piedra que emerge súbitamente del suelo. Desde aquí puedes ver su "
    "vertiente oriental, un abrupto terraplén de varias decenas de metros de altura "
    "por el que serpentea un estrecho camino que asciende trabajosamente entre rocas "
    "y árboles esmirriados y torcidos que se aferran a la árida pared pedregosa como "
    "extraños seres amarillentos a una calavera reseca.\n");

    AddDetail("castillo", "Se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificación recia, sombría y angulosa, carente de todo atractivo "
    " artístico pero sin duda bien situado y de construcción sólida.\n");

    AddDetail(({"Nandor", "nandor", "villa", "pueblo", "aldea"}),
    "La villa de Nandor se extiende al este, en el interior de una suave hondonada que "
    "acuna sus sencillas construcciones de piedra y madera.\n Hacia el sudeste, el "
    "verde dosel del bosque de Maralth se recorta contra el cielo, al otro lado de "
    "la depresión del terreno.\n");


    SetIndoors(0);
    SetLocate("el norte de Marhalt");
    if(d20()==1)
        AddItem(PNJ("camino/viajero"),REFRESH_DESTRUCT);
}

