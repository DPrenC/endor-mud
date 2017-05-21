/****************************************************************************
Fichero: camino01.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    SetIntLong("Te encuentras en el camino del Norte de Marhalt, en el punto de comienzo"
    " de la larga ruta que comunica la peque�a poblaci�n agr�cola de Nandor con el "
    "poblado de Enalel, en el lejano norte, y con las a�n m�s distantes monta�as "
    "septentrionales.\n Su construcci�n se remonta a los tiempos de los primeros hombres "
    "y los grandes se�ores de Ishtria, cuando florec�an las alianzas comerciales "
    "y militares entre humanos y medio elfos, y decenas de caravanas mercantes "
    "recorr�an diariamente la gran distancia que separa ambas localidades.\n En aquellos "
    "tiempos el camino estaba adoquinado con enormes losas gran�ticas de corte exagonal "
    "que ahora aparecen resquebrajadas, desmenuzadas y en la mayor parte del trayecto "
    "han sido sustituidas por un firme de tierra pisada, fangosa y revuelta por el "
    "paso de personas, caballos y carretas.\n En este punto el terreno se ve especialmente "
    "enfangado y pisoteado, debido al cont�nuo tr�nsito de soldados y animales entre "
    "la villa de Nandor, cuya calle principal comienza al este, y el Castillo de "
    "los Dhes-Bl�in, que se alza en lo alto de una escarpada colina, hacia el oeste.\n");

    AddDetail(({"Nandor", "nandor", "villa", "pueblo", "aldea"}),
    "La villa de Nandor se extiende al este, en el interior de una suave hondonada que "
    "acuna sus sencillas construcciones de piedra y madera.\n Hacia el sudeste, el "
    "verde dosel del bosque de Maralth se recorta contra el cielo, al otro lado de "
    "la depresi�n del terreno.\n");
    AddDetail(({"bosque", "bosque de marhalt", "bosque de Marhalt"}),
    "El bosque de Marhalt se extiende al sudeste de la Villa de nandor, al borde de "
    "la suave depresi�n que cobija el pueblo, vibrante de verdor y vida.\n Entre "
    "la extensa variedad de tonos verdes, marrones y rojizos alcanzas a vislumbrar "
    "a intervalos irregulares el reflejo plateado de las aguas del r�o Kandal, que "
    "discurren tranquilas hacia el suroeste.\n");
    AddDetail(({"rio", "r�o", "aguas", "agua", "kandal", "Kandal"}),
    "Desde aqu� alcanzas a vislumbrar entre la variedad de colores del bosque de Marhalt "
    "un reflejo irregular, cuando plateado, cuando dorado o verdoso, que son las "
    "aguas del r�o Kandal, que discurren con suavidad hacia el oeste, hacia tierras m�s "
    "abiertas donde los habitantes de Nandor aprovechan sus aguas, para regar los "
    "campos de cultivo y los maizales que avastecen, tanto a la capital de Ishtria, como "
    "el decreciente comercio con los semielfos de Enalel.\n");
    AddDetail("colina", "La colina rompe el paisage suave y ondulado como un descarnado "
    "pu�o de piedra que emerge s�bitamente del suelo. Desde aqu� puedes ver su "
    "vertiente oriental, un abrupto terrapl�n de varias decenas de metros de altura "
    "por el que serpentea un estrecho camino que asciende trabajosamente entre rocas "
    "y �rboles esmirriados y torcidos que se aferran a la �rida pared pedregosa como "
    "extra�os seres amarillentos a una calavera reseca.\n");

    AddDetail(({"fortaleza", "castillo"}),
    "La fortaleza se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificaci�n recia, sombr�a y angulosa, carente de todo atractivo "
    " art�stico pero sin duda bien situado y de construcci�n s�lida.\n");

    AddExit("oeste", "./camino02");
    AddExit("este", MARH("nandor/calle0"));
}

