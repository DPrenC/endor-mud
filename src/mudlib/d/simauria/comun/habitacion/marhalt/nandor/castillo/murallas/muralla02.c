/****************************************************************************
Fichero: muralla02.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En la muralla del castillo.
****************************************************************************/

#include "./path.h"
#include <properties.h>
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
    "los muros de mas elasticidad, adem�s de ofrecer el mismo efecto visual que los "
    "hechos exclusivamente de piedra maciza. �sta parte de la muralla est� bien cuidada "
    "pues aunque un ataque desde el oeste no ser�a probable debido a lo accidentado del "
    "terreno, un peque�o grupo de audaces escaladores podr�a ascender hasta aqu� y "
    "penetrar en la torre del homenaje situada algo mas al sur.\n"
    "Instalada tras las almenas hay una peque�a catapulta. Al norte la muralla dobla "
    "hacia el este en un recodo protegido por el torre�n de la inmolaci�n, mientras "
    "que al sur acaba en un arco de piedra que da entrada a la torre del homenaje. Abajo "
    "contemplas el patio de armas y asom�ndote a las almenas puedes ver el foso y el "
    "declive de la colina.\n");
    AddDetail("almenas", "Un muro de medio metro de grosor que llega a la altura del pecho de un "
    "hombre rematado a intervalos regulares por cortos fustes cuadrados entre los "
    "cuales los defensores se asoman para disparar o derribar a los asaltantes. A cada "
    "pocos metros en la parte baja hay saeteras, estrechas aberturas mas anchas en la "
    "parte interior que en la esterior, utilizadas para disparar desde una posici�n "
    "cubierta o deslizar armas penetrantes como lanzas para ensartar a  cualquiera que "
    "trepe por escalas de asalto sin que pueda hacer nada para evitarlo.\n");
    AddDetail(({"terreno", "colina", "declive", "pendiente"}), "La colina pedregosa "
    "sobre la que se alza el castillo cae hacia el oeste en una pendiente bastante "
    "pronunciada y accidentada, de la que sobresalen aqu� y all� rocas medio sueltas y "
    "aglomeraciones de monte bajo.\n");
    AddItem(THING, REFRESH_REMOVE,
    ([P_SHORT: "una peque�a catapulta",
    P_LONG: "ES una peque�a catapulta "
    "de poco alcance encajada contra las almenas y bastante descuidada. Est� formada "
    "por un bastidor horizontal de madera rectangular apoyado en el suelo sobre el que "
    "se sujeta una pieza similar en posici�n vertical, cuya utilidad es la de frenar el "
    "brazo propulsor, un madero ligero pero fuerte rematado en una especie de cuchara "
    "met�lica algo oxidada donde se cargan los proyectiles, que mediante la fuerza de "
    "torsi�n aportada por unas gruesas cuerdas retorcidas, sale disparado lanzando su "
    "carga en una trayectoria ascendente.\n",
    P_WEIGHT: 1000000, P_GENDER: GENDER_FEMALE,
    P_IDS: ({"peque�a catapulta", "pequena catapulta", "catapulta"})]));
    AddItem(THING, REFRESH_REMOVE,
    ([P_SHORT: "un bloque de piedra",
        P_LONG: "Es un peque�o bloque de piedra que debi� de sobrar de alguna de las "
            "murallas y ahora se utiliza como proyectil para las catapultas.\n",
        P_WEIGHT: 9000, P_IDS: ({"piedra", "bloque de piedra", "bloque"})]), d8());
    AddExit("norte", "./muralla03");
    AddExit("sur", "./muralla01");
}


