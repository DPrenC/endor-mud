/****************************************************************************
Fichero: muralla17.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
    SetIntLong("Te encuentras sobre el adarbe o parte superior de la muralla oriental "
    "del castillo, de unos dos metros de ancho y coronado por almenas de altura media.\n"
    "Éste lienzo de la fortificación fue construído en base a dos fuertes muros de "
    "bloques de piedra encajados lo mas exactamente posible, rellenando el espacio "
    "intermedio con un conjunto de argamasa, grabilla y cantos rodados, siendo todo "
    "ello compactado y recubierto de una última capa de bloques. Éste procedimiento es "
    "ampliamente utilizado en la edificación de murallas por ser mas rápido, dotar a "
    "los muros de mas elasticidad, además de ofrecer el mismo efecto visual que los "
    "hechos exclusivamente de piedra maciza.\n"
    "Abajo en el patio de armas y construídos contra la muralla hay unos cuantos "
    "cobertizos. La muralla continúa hacia el sur y el norte. Al este, mas allá del "
    "foso la ladera de la colina desciende hacia el camino norte de Marhalt y la aldea "
    "de Nandor.\n");
    AddDetail(({"colina", "ladera"}), "La colina rocosa sobre la que se alza el "
    "castillo desciende hacia el este en una serie de desniveles en los que crecen "
    "algunos parches de hierba y matojos. Sobre este flanco, un estrecho sendero "
    "trillado trepa en zigzag separandose del camino norte de Marhalt.\n");
    AddDetail(({"aldea", "nandor", "Nandor", "pueblo"}), "Al este del castillo y al "
    "pie de la colina, se encuentra la pequeña aldea de Nandor, un conjunto de "
    "humildes moradas que rodean la casa de tributos y el pequeño templo. Al norte se "
    "extienden los campos de cultivo, al sur el río Kandal y el bosque de Marhalt, y al "
    "este un viejo cementerio.\n");
    AddDetail("almenas", "Un muro de unos cincuenta centímetros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posición cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que éste pueda hacer "
    "nada para evitarlo.\n");
    AddDetail(({"cobertizo", "cobertizos"}), "Varios cobertizos construídos contra la "
    "parte interior de la muralla usados como caballerizas, perreras y otros servicios "
    "para el castillo.\n");
    AddExit("sur", "./muralla18");
    AddExit("norte", "./muralla16");
}


