/****************************************************************************
Fichero: muralla01.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
    SetIntLong("Te encuentras sobre el adarbe o parte superior de la muralla occidental "
    "del castillo de unos dos metros de ancho y coronado por almenas de altura media.\n"
    "�ste lienzo de la fortificaci�n, al dar sobre una parte de la colina que cae en un "
    "declive dificilmente escalable, fue constru�do en base a dos fuertes muros de "
    "bloques de piedra encajados lo mas exactamente posible, rellenando el espacio "
    "intermedio con un conjunto de argamasa, grabilla y cantos rodados, siendo todo ello "
    "compactado y recubierto de una �ltima capa de bloques. �ste procedimiento es "
    "ampliamente utilizado en la edificaci�n de murallas por ser mas r�pido, dotar a "
    "los muros de m�s elasticidad, adem�s de ofrecer el mismo efecto visual que los "
    "hechos exclusivamente de piedra maciza. �sta parte de la muralla est� bien cuidada "
    "pues aunque un ataque desde el oeste no ser�a probable debido a lo accidentado del "
    "terreno, un peque�o grupo de audaces escaladores podr�a ascender hasta aqu� y "
    "penetrar en la torre del homenaje situada justo al sur.\n Hacia el este puedes ver "
    "el patio de armas con la herrer�a del castillo bajo tus pi�s, al sur la "
    "torre del homenaje, al norte contin�a la muralla hacia el torre�n de la inmolaci�n "
    "y al oeste el foso a la sombra de la muralla y el declive de la colina.\n");

    AddDetail(({"terreno", "colina", "declive", "pendiente"}), "La colina pedregosa "
    "sobre la que se alza el castillo cae hacia el oeste en una pendiente bastante "
    "pronunciada y accidentada, de la que sobresalen aqu� y all� rocas medio sueltas y "
    "aglomeraciones de monte bajo.\n");

    AddDetail(({"herrer�a","herreria", "forja"}), "Es un bajo cobertizo levantado en el "
    "�ngulo que forma la muralla y el muro de la torre del homenaje, con un tejado de "
    "pizarra ligeramente inclinado y una corta y rechoncha chimenea que da salida a los "
    "vapores del interior.\n");
    AddDetail("almenas", "Un muro de medio metro de grosor que llega a la altura del pecho de un "
    "hombre rematado a intervalos regulares por cortos fustes cuadrados entre los "
    "cuales los defensores se asoman para disparar o derribar a los asaltantes. A cada "
    "pocos metros en la parte baja hay saeteras, estrechas aberturas mas anchas en la "
    "parte interior que en la esterior, utilizadas para disparar desde una posici�n "
    "cubierta o deslizar armas penetrantes como lanzas para ensartar a  cualquiera que "
    "trepe por escalas de asalto sin que pueda hacer nada para evitarlo.\n");
    AddExit("norte", "./muralla02");
    AddExit("sur", CASTILLO("planta2/pasillo0"));
}

