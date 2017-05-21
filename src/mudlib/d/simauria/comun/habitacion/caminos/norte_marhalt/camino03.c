/****************************************************************************
Fichero: camino03.c
Autor: Ratwor
Fecha: 27/12/2007
Descripción: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    SetIntLong("Te encuentras en el camino del Norte de Marhalt, en algún punto de la "
    "larga ruta que comunica la pequeña población agrícola de Nandor con el poblado "
    "de Enalel, en el lejano norte, y con las aún más distantes montañas "
    "septentrionales.\n Su construcción se remonta a los tiempos de los primeros hombres "
    "y los grandes señores de Ishtria, cuando florecían las alianzas comerciales y "
    "militares entre humanos y semi elfos y decenas de caravanas mercantes recorrían "
    "diariamente la gran distancia que separa ambas regiones.\n En aquellos tiempos el "
    "camino estaba adoquinado con enormes losas graníticas de corte exagonal que ahora "
    "aparecen resquebrajadas, desmenuzadas y en la mayor parte del trayecto han sido "
    "sustituidas por un firme de tierra pisada, fangosa y revuelta por el paso de "
    "personas, caballos y carretas.\n En este punto el terreno se ve especialmente "
    "enfangado y pisoteado, debido al contínuo tránsito de soldados y animales entre "
    "la villa de Nandor, hacia el este, y el Castillo de los Dhes-Bláin, que se alza "
    "en lo alto de una escarpada colina hacia el oeste.\n Hacia el sur y el suroeste se "
    "extienden una serie de pequeñas granjas y extensos maizales, principal ocupación "
    "de los habitantes de nandor e importante fuente de avastecimiento tanto para la "
    "ciudad de Ishtria en el sur, como para los habitantes de Nandor, la guarnición "
    "del castillo de los Dhes-Bláin y el decreciente comercio con los semielfos de "
    "Enalel.\n");
    AddDetail(({"rio", "río", "kandal", "Kandal"}),
    "El río Kandal discurre suavemente en el sur. Los habitantes de Nandor han realizado "
    "una serie de pequeñas presas, diques y desvíos para surtir de regadío los campos de "
    "maizales que sustentan la economía de su señor.\n");
    AddDetail(({"maizales", "cultivos", "granjas", "campos"}), "Hacia el sur y el "
    "suroeste, y hasta las mismas orillas del río Kandal, más hacia el sur, se extienden"
    ", ondulantes y brillantes en sus mil tonos de amarillo y verde, una serie de "
    "pequeñas granjas y extensosmaizales que constituyen la principal ocupación de "
    "los habitantes denandor, así como la más importante forma de avastecimiento "
    "tanto parala ciudad de Ishtria en el sur, como para los habitantes de Nandor, "
    "laguarnición del castillo de los Dhes-Bláin y el decreciente comercio con los "
    "semielfos de Enalel.\n");
    AddDetail("colina", "La colina rompe el paisage suave y ondulado como un descarnado "
    "puño de piedra que emerge súbitamente del suelo. Desde aquí puedes ver su "
    "vertiente oriental, un abrupto terraplén de varias decenas de metros de altura "
    "por el que serpentea un estrecho camino que asciende trabajosamente entre rocas "
    "y árboles esmirriados y torcidos que se aferran a la árida pared pedregosa como "
    "extraños seres amarillentos a una calavera reseca.\n");

    AddDetail("castillo", "Se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificación recia, sombría y angulosa, carente de todo atractivo "
    " artístico pero sin duda bien situado y de construcción sólida.\n");

    AddDetail(({"bosque", "bosque de marhalt", "bosque de Marhalt"}),
    "El bosque de Marhalt se extiende al sudeste de la Villa de nandor, al borde de "
    "la suave depresión que cobija el pueblo, vibrante de verdor y vida.\n Entre "
    "la extensa variedad de tonos verdes, marrones y rojizos alcanzas a vislumbrar "
    "a intervalos irregulares el reflejo plateado de las aguas del río.\n");
    AddDetail(({"Nandor", "nandor", "villa", "pueblo", "aldea"}),
    "La villa de Nandor se extiende al este, en el interior de una suave hondonada que "
    "acuna sus sencillas construcciones de piedra y madera.\n Hacia el sudeste, el "
    "verde dosel del bosque de Maralth se recorta contra el cielo, al otro lado de "
    "la depresión del terreno.\n");

    AddExit("oeste", "./camino04");
    AddExit("sudeste", "./camino02");
}

