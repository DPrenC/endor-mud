/****************************************************************************
Fichero: camino25.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"

inherit CASTILLO("camino/camino_base");
create(){
    ::create();
    SetIntShort("la explanada frente al castillo");
        SetIntLong("Te encuentras en una pequeña explanada empedrada ante el puente "
    "levadizo y las puertas del castillo de Nandor, situado justo al sur. Aquí "
    "confluyen el sendero trillado del este y el sendero empedrado que asciende por la "
    "vertiente norte de la colina desde el camino del norte de Marhalt.\n");
    AddDetail(({"colina", "vertiente"}), "La vertiente norte de la colina desciende en un "
    "suave declive cubierto de hierba hasta el camino del norte de Marhalt.\n");
    AddDetail("puente", "Un robusto puente levadizo de madera de roble sostenido por "
    "cadenas de hierro que salva el profundo foso que rodea el castillo.\n");
    AddDetail("foso", "Te asomas para observar el foso. Es una profunda "
    "zanja cabada a los pies de los contrafuertes que sostienen las murallas en cuyo "
    "terroso fondo hay algunos charcos negruzcos de barro malholiente procedente de las "
    "aguas fecales y demás desperdicios del castillo. Ésta zona ha sido descuidada, "
    "pues sus bordes aparecen desmoronados, las estacas de hierro que rematan el fondo "
    "están oxidadas e inclinadas, y en la parte baja crecen algunas plantas rastreras.\n");
    AddDetail(({"estacas", "estaca"}), "Son unas barras de hierro de metro y medio de "
    "longitud que se estrechan desde la base para terminar en punta. Habitualmente este "
    "tipo de defensa se coloca en el fondo de fosos y zanjas defensivas para ensartar a "
    "cualquier hombre o caballo que caiga desde arriba, lo que suele resultar en una "
    "muerte agónica y terrible. Éstas estacas en particular están recubiertas por una "
    "gruesa capa de óxido ya antiguo, aparecido por causa de la humedad y al descuido.\n"
    "Algunas se inclinan precariamente, mientras que otras reposan medio enterradas "
    "en el barro.\n");
    SetIntSmell("Percibes el olor de agua estancada procedente del foso.\n");
    AddExit("norte", "./camino26");
    AddExit("este", "./camino24");
    AddExit("sur", CASTILLO("patio/puente"));
}

