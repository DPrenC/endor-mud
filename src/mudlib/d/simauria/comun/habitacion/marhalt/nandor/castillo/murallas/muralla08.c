/****************************************************************************
Fichero: muralla08.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En la muralla del castillo.
****************************************************************************/

#include "./path.h"
inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
    SetIntShort("la muralla, sobre la puerta del castillo");
    SetIntLong("Te encuentras justo sobre las puertas del castillo, en el centro del "
    "peque�o baluarte que se adelanta sobre el foso. �sta parte es de gran importancia "
    "pues en ella est�n los tornos que alzan el rastrillo de la entrada, y el mecanismo "
    "que maneja el puente levadizo, todo ello  protegido desde el exterior por un "
    "matac�n. Tanto al este como al oeste, una garita volada se alza sobre el adarbe.\n");
    AddDetail(({"matac�n", "matacan"}), "Es una obra de defensa que sobresale de la "
    "muralla por su parte exterior empleada como un lugar seguro desde el cual mirar y "
    "atacar al enemigo. Consiste en una plataforma con orificios, a trav�s de los "
    "cuales, piedras, materiales ardientes y otros tipos de proyectiles pueden ser "
    "lanzados sobre los atacantes que se hallen al pie de la fortificaci�n; en la cual "
    "se apoya un muro avanzado que sirve de protecci�n, rematado por una especie de "
    "tejadillo o solapa de pizarra que se alza aproximadamente un metro hacia el interior.\n");
    AddDetail(({"torno", "tornos"}), "Son unos grandes tornos conectados al rastrillo "
    "que hay justo debajo.\n");
    AddDetail("mecanismo", "Est� formado por un grueso eje de madera apoyado sobre tres "
    "refuerzos met�licos anclados al suelo, rematado en sus extremos por dos rollos "
    "donde se enrroscan las grandes cadenas que sujetan los extremos del puente, y una "
    "serie de barras que sobresalen en forma de aspa en la parte central, usadas por "
    "los hombres encargados del mecanismo para hacer girar todo el conjunto.\n");
    AddDetail(({"cadena", "cadenas"}), "Dos gruesas cadenas de hierro surgen de los "
    "extremos del mecanismo para descender diagonalmente atrav�s de unos orificios "
    "practicados en la muralla hasta anclarse en los extremos mas alejados del puente.\n");
    AddDetail(({"garitas", "garita"}), "Tanto al este como al oeste de aqu�, apoyadas "
    "sobre el muro frontal dotado de saeteras que sustituye a las almenas para ofrecer "
    "mayor protecci�n, y sobre un pont�n trasero de madera, se han levantado unas "
    "rudimentarias garitas voladas o torrecillas almenadas, desde las que los arqueros "
    "obtienen excelentes puestos de tiro para cubrir el puente levadizo, e incluso la "
    "muralla circundante hasta los torreones.\n"
    "Est�n constru�das con piedra de baja calidad y en forma algo descuidada, "
    "contrastando con la perfecci�n del resto de la obra, lo que sugiere que se trata de "
    "un a�adido posterior.\n");
    AddDetail("bosque", "Al norte del camino de Marhalt, se extiende el bosque de "
    "Cored, una oscura masa de a�osos �rboles de aspecto ominoso.\n");
    AddDetail(({"colina", "ladera", "declive"}), "Al norte del castillo la ladera de la "
    "colina desciende en un declive poco pronunciado y cubierto de hierba, por el cual "
    "discurre el sendero trillado que al pie de la elevaci�n se une al camino norte de "
    "Marhalt.\n");

    AddExit("este", "./muralla09");
    AddExit("oeste", "./muralla07");
    AddItem(PNJCASTILLO("arquero"), REFRESH_DESTRUCT, 2);
}
