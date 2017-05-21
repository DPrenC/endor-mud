/****************************************************************************
Fichero: zona_lenyador.c
Autor: Ratwor
Fecha: 28/01/2007
Descripci�n: la room de fuera de la caba�a del le�ador.
****************************************************************************/

#include "./path.h"
inherit MARH("nandor/bosque/bosque_base");

string f_sale_humo(){
    object dentro = find_object(MARH("nandor/bosque/casa_lenyador"));
    if (dentro->QueryChimenea()==1)
        return "Ante ti tienes una caba�a de madera vieja y sin tratar,bastante "
        "desvencijada, con s�lo una puerta y un peque�o ventanuco. Observas tambi�n "
        "una chimenea que no deja de sacar humo, lo que indica que dentro habr� un "
        "fuego encendido.\n Es una casucha no muy grande, en la que habita el le�ador "
        "que tala los �rboles de este bosque.\n";
        return "Ante ti tienes una caba�a de madera vieja y sin tratar,bastante "
        "desvencijada, con s�lo una puerta y un peque�o ventanuco. Observas tambi�n "
        "una chimenea que se supone que dentro de la caba�a habr� un hogar para "
        "mantenerla tibia, aunque ahora debe estar apagada porque no sale humo.\n "
        " Es una casucha no muy grande, en la que habita el le�ador que tala los "
        "�rboles de este bosque.\n";
}

string f_mirar_chimenea(){
    object dentro = find_object(MARH("nandor/bosque/casa_lenyador"));
    if (dentro->QueryChimenea()==1)

        return "La chimenea debe estar encendida ahora mismo, pues sale humo sin "
        "parar.\n";
        return "La chimenea debe estar apagada, de lo contrario saldr�a humo y no ves "
        "que salga nada.\n";
}

create()
{
    ::create();
    SetLocate("bosque de Marhalt");
    SetIntShort("el bosque de Marhalt, junto a la caba�a de un le�ador");
    SetIntLong("Un claro dejado por los �rboles permite observar la maleza y los "
        "arbustos que crecen por todas partes en que los robles y las hayas dejan "
        "sitio. Quiz�s este claro tenga que ver con la cantidad de troncos que pueden "
        "verse por aqu�, troncos de �rboles que han estado en esta zona pero que "
        "ahora han desaparecido por obra del trabajo de un hacha. Aqu� y all� se ven "
        "troncos de forma irregular.\nAcompa�ando a los montones de troncos se "
        "encuentra una ruinosa caba�a t�pica de le�ador, la cual tiene su entrada "
        "hacia el este.\n");
    AddDetail(({"madera", "troncos", "troncos apilados"}), "Distintos montones de "
        "troncos apilados y de diferentes tama�os.\n");
    AddDetail(({"caba�a", "casa", "choza"}),  SF(f_sale_humo));
    AddDetail(({"chimenea", "humo"}), SF(f_mirar_chimenea));
    AddDetail(({"ventana", "ventanuco", "peque�o ventanuco", "ventanuco peque�o"}),
    "Es un peque�o agujero en la parte frontal de la caba�a, por el que apenas entra "
    "luz al interior.\n");
    AddExit("este","./casa_lenyador");
    AddExit("norte", "./bosque042");
    AddExit("noroeste", "./bosque041");
    AddExit("oeste", "./bosque048");
    AddDoor("este", "la puerta de la caba�a",
    "Es una destartalada puerta de madera sin tratar.\n",
    ({"puerta", "puerta de madera", "puerta destartalada", "puerta de la caba�a",
    "puerta del este"}));
    AddItem(PNJ("marhalt/lenyador"),REFRESH_DESTRUCT);
}

init(){
    ::init();
    call_out("pisadas",1);

}

public void pisadas(){
    tell_room(MARH("nandor/bosque/casa_lenyador"), "Se escuchan pisadas fuera de la "
    "caba�a.\n");
}
