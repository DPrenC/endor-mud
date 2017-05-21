/****************************************************************************
Fichero: camino03.c
Autor: Ratwor
Fecha: 27/12/2007
Descripci�n: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    SetIntLong("Te encuentras en el camino del Norte de Marhalt, en alg�n punto de la "
    "larga ruta que comunica la peque�a poblaci�n agr�cola de Nandor con el poblado "
    "de Enalel, en el lejano norte, y con las a�n m�s distantes monta�as "
    "septentrionales.\n Su construcci�n se remonta a los tiempos de los primeros hombres "
    "y los grandes se�ores de Ishtria, cuando florec�an las alianzas comerciales y "
    "militares entre humanos y semi elfos y decenas de caravanas mercantes recorr�an "
    "diariamente la gran distancia que separa ambas regiones.\n En aquellos tiempos el "
    "camino estaba adoquinado con enormes losas gran�ticas de corte exagonal que ahora "
    "aparecen resquebrajadas, desmenuzadas y en la mayor parte del trayecto han sido "
    "sustituidas por un firme de tierra pisada, fangosa y revuelta por el paso de "
    "personas, caballos y carretas.\n En este punto el terreno se ve especialmente "
    "enfangado y pisoteado, debido al cont�nuo tr�nsito de soldados y animales entre "
    "la villa de Nandor, hacia el este, y el Castillo de los Dhes-Bl�in, que se alza "
    "en lo alto de una escarpada colina hacia el oeste.\n Hacia el sur y el suroeste se "
    "extienden una serie de peque�as granjas y extensos maizales, principal ocupaci�n "
    "de los habitantes de nandor e importante fuente de avastecimiento tanto para la "
    "ciudad de Ishtria en el sur, como para los habitantes de Nandor, la guarnici�n "
    "del castillo de los Dhes-Bl�in y el decreciente comercio con los semielfos de "
    "Enalel.\n");
    AddDetail(({"rio", "r�o", "kandal", "Kandal"}),
    "El r�o Kandal discurre suavemente en el sur. Los habitantes de Nandor han realizado "
    "una serie de peque�as presas, diques y desv�os para surtir de regad�o los campos de "
    "maizales que sustentan la econom�a de su se�or.\n");
    AddDetail(({"maizales", "cultivos", "granjas", "campos"}), "Hacia el sur y el "
    "suroeste, y hasta las mismas orillas del r�o Kandal, m�s hacia el sur, se extienden"
    ", ondulantes y brillantes en sus mil tonos de amarillo y verde, una serie de "
    "peque�as granjas y extensosmaizales que constituyen la principal ocupaci�n de "
    "los habitantes denandor, as� como la m�s importante forma de avastecimiento "
    "tanto parala ciudad de Ishtria en el sur, como para los habitantes de Nandor, "
    "laguarnici�n del castillo de los Dhes-Bl�in y el decreciente comercio con los "
    "semielfos de Enalel.\n");
    AddDetail("colina", "La colina rompe el paisage suave y ondulado como un descarnado "
    "pu�o de piedra que emerge s�bitamente del suelo. Desde aqu� puedes ver su "
    "vertiente oriental, un abrupto terrapl�n de varias decenas de metros de altura "
    "por el que serpentea un estrecho camino que asciende trabajosamente entre rocas "
    "y �rboles esmirriados y torcidos que se aferran a la �rida pared pedregosa como "
    "extra�os seres amarillentos a una calavera reseca.\n");

    AddDetail("castillo", "Se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificaci�n recia, sombr�a y angulosa, carente de todo atractivo "
    " art�stico pero sin duda bien situado y de construcci�n s�lida.\n");

    AddDetail(({"bosque", "bosque de marhalt", "bosque de Marhalt"}),
    "El bosque de Marhalt se extiende al sudeste de la Villa de nandor, al borde de "
    "la suave depresi�n que cobija el pueblo, vibrante de verdor y vida.\n Entre "
    "la extensa variedad de tonos verdes, marrones y rojizos alcanzas a vislumbrar "
    "a intervalos irregulares el reflejo plateado de las aguas del r�o.\n");
    AddDetail(({"Nandor", "nandor", "villa", "pueblo", "aldea"}),
    "La villa de Nandor se extiende al este, en el interior de una suave hondonada que "
    "acuna sus sencillas construcciones de piedra y madera.\n Hacia el sudeste, el "
    "verde dosel del bosque de Maralth se recorta contra el cielo, al otro lado de "
    "la depresi�n del terreno.\n");

    AddExit("oeste", "./camino04");
    AddExit("sudeste", "./camino02");
}

