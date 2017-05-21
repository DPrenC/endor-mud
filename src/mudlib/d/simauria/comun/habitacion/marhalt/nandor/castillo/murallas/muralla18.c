/****************************************************************************
Fichero: muralla18.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En la muralla del castillo.
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
    SetIntLong("Te encuentras sobre el adarbe o parte superior de la muralla oriental "
    "del castillo, de unos dos metros de ancho y coronado por almenas de altura media.\n"
    "�ste lienzo de la fortificaci�n fue constru�do en base a dos fuertes muros de "
    "bloques de piedra encajados lo mas exactamente posible, rellenando el espacio "
    "intermedio con un conjunto de argamasa, grabilla y cantos rodados, siendo todo "
    "ello compactado y recubierto de una �ltima capa de bloques. �ste procedimiento es "
    "ampliamente utilizado en la edificaci�n de murallas por ser mas r�pido, dotar a "
    "los muros de mas elasticidad, adem�s de ofrecer el mismo efecto visual que los "
    "hechos exclusivamente de piedra maciza.\n"
    "Abajo en el patio de armas y constru�dos contra la muralla hay unos cuantos "
    "cobertizos. La muralla contin�a hacia el sur y el norte. Al este, mas all� del "
    "foso la ladera de la colina desciende hacia el camino norte de Marhalt y la aldea "
    "de Nandor.\n");
    AddDetail(({"colina", "ladera"}), "La colina rocosa sobre la que se alza el "
    "castillo desciende hacia el este en una serie de desniveles en los que crecen "
    "algunos parches de hierba y matojos. Sobre este flanco, un estrecho sendero "
    "trillado trepa en zigzag separandose del camino norte de Marhalt.\n");
    AddDetail(({"aldea", "nandor", "Nandor", "pueblo"}), "Al este del castillo y al "
    "pie de la colina, se encuentra la peque�a aldea de Nandor, un conjunto de "
    "humildes moradas que rodean la casa de tributos y el peque�o templo. Al norte se "
    "extienden los campos de cultivo, al sur el r�o Kandal y el bosque de Marhalt, y al "
    "este un viejo cementerio.\n");
    AddDetail("almenas", "Un muro de unos cincuenta cent�metros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posici�n cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que �ste pueda hacer "
    "nada para evitarlo.\n");
    AddDetail(({"cobertizo", "cobertizos"}), "Varios cobertizos constru�dos contra la "
    "parte interior de la muralla usados como caballerizas, perreras y otros servicios "
    "para el castillo.\n");


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
    AddExit("sur", "./muralla19");
    AddExit("norte", "./muralla17");
}


