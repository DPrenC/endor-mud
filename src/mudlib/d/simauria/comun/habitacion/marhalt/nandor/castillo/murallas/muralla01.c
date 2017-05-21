/****************************************************************************
Fichero: muralla01.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
    SetIntLong("Te encuentras sobre el adarbe o parte superior de la muralla occidental "
    "del castillo de unos dos metros de ancho y coronado por almenas de altura media.\n"
    "Éste lienzo de la fortificación, al dar sobre una parte de la colina que cae en un "
    "declive dificilmente escalable, fue construído en base a dos fuertes muros de "
    "bloques de piedra encajados lo mas exactamente posible, rellenando el espacio "
    "intermedio con un conjunto de argamasa, grabilla y cantos rodados, siendo todo ello "
    "compactado y recubierto de una última capa de bloques. Éste procedimiento es "
    "ampliamente utilizado en la edificación de murallas por ser mas rápido, dotar a "
    "los muros de más elasticidad, además de ofrecer el mismo efecto visual que los "
    "hechos exclusivamente de piedra maciza. Ésta parte de la muralla está bien cuidada "
    "pues aunque un ataque desde el oeste no sería probable debido a lo accidentado del "
    "terreno, un pequeño grupo de audaces escaladores podría ascender hasta aquí y "
    "penetrar en la torre del homenaje situada justo al sur.\n Hacia el este puedes ver "
    "el patio de armas con la herrería del castillo bajo tus piés, al sur la "
    "torre del homenaje, al norte continúa la muralla hacia el torreón de la inmolación "
    "y al oeste el foso a la sombra de la muralla y el declive de la colina.\n");

    AddDetail(({"terreno", "colina", "declive", "pendiente"}), "La colina pedregosa "
    "sobre la que se alza el castillo cae hacia el oeste en una pendiente bastante "
    "pronunciada y accidentada, de la que sobresalen aquí y allá rocas medio sueltas y "
    "aglomeraciones de monte bajo.\n");

    AddDetail(({"herrería","herreria", "forja"}), "Es un bajo cobertizo levantado en el "
    "ángulo que forma la muralla y el muro de la torre del homenaje, con un tejado de "
    "pizarra ligeramente inclinado y una corta y rechoncha chimenea que da salida a los "
    "vapores del interior.\n");
    AddDetail("almenas", "Un muro de medio metro de grosor que llega a la altura del pecho de un "
    "hombre rematado a intervalos regulares por cortos fustes cuadrados entre los "
    "cuales los defensores se asoman para disparar o derribar a los asaltantes. A cada "
    "pocos metros en la parte baja hay saeteras, estrechas aberturas mas anchas en la "
    "parte interior que en la esterior, utilizadas para disparar desde una posición "
    "cubierta o deslizar armas penetrantes como lanzas para ensartar a  cualquiera que "
    "trepe por escalas de asalto sin que pueda hacer nada para evitarlo.\n");
    AddExit("norte", "./muralla02");
    AddExit("sur", CASTILLO("planta2/pasillo0"));
}

