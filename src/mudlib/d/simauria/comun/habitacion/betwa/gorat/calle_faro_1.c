// 04-06-08 [Angor] Creacion

#include "./path.h"
inherit GORAT("room_base.c");

create () {
    ::create();
    replace_program();
    SetIntShort("el sendero al faro de Gorat");
    SetIntLong(
"Las �ltimas rampas de este sendero al faro que quedan al oeste para llegar "
"a la cima de esta colina son bastante m�s empinadas que el resto del sendero "
"que desciende hasta Gorat. Un peque�o templo de piedras grises y tejado de "
"pizarra se halla construido al norte de aqu�. La hierba crece alta en torno "
"a �l y baila al son del viento de llega del golfo.\n");

AddDetail(({"templo","puerta","tejado","pizarra"}),
"El templo es una peque�a construcci�n rectangular de bloques de piedra grises y "
"tejado de planchas irregulares de pizarra azulada. Parece s�lido y no tiene "
"ventanas. Enmarcando su puerta se hallan un par de troncos tallados con motivos "
"marinos.\n");

AddDetail(({"troncos","conchas","ocre"}),
"Tienen motivos marinos tallados en ellos. Est�n pintados de un color ocre "
"brillante con lineas en negro y llevan conchas encastradas. Supones que lo "
"que representan tiene relaci�n con el culto del templo.\n");

    AddExit("noreste", GORAT("calle_faro_2") );
    AddExit("norte", GORAT("templo_entrada") );
    AddExit("oeste", GORAT("mirador") );
}
