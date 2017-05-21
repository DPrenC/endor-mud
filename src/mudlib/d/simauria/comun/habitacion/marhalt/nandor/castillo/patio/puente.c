/****************************************************************************
Fichero: puente.c
Autor: Ratwor
Fecha: 28/12/2007
Descripci�n: El puente elevadizo.
****************************************************************************/

#include "./path.h"
#include <scheduler.h>
inherit SIM_ROOM;

private string DescLarga()
{
    object entrada = find_object(resolve_file("./entrada"));
    int estado;
    string msg;
    if (!entrada)
    // no est� cargada, as� que pillamos el estado de la hora
    {
        estado = member(
        ({ND_NIGHT, ND_PREDAWN}), QueryDayState()) >= 0 ? S_CLOSED : S_OPENED;
    }
    else
    // s� est� cargada, as� que lo pillamos de la entrada dir�ctamente
    {
        estado = entrada->QueryRoomState();
    }
    if (estado == S_CLOSED)
        msg = "El rastrillo de la entrada est� bajado impidiendo la entrada al castillo.\n";
        else msg = "El rastrillo de la entrada est� subido dejando el paso libre para "
        "entrar al castillo.\n";
    return "Te encuentras sobre el puente levadizo que salva el foso que rodea el "
    "castillo. Est� constru�do en robusta madera de roble, y tiene anchura suficiente "
    "para que dos jinetes o un carro puedan atravesarlo c�modamente. Las dos  cadenas  "
    "que permiten alzarlo surgen de orificios situados bajo las almenas y descienden en "
    "diagonal hasta los extremos de la extructura de madera donde est�n ancladas. Al sur "
    "se alzan las fuertes murallas del castillo que protegen la puerta, erizadas de "
    "almenas y con las aberturas de los matacanes defendiendola desde arriba.\n La "
    "entrada del castillo es un ancho arco con puertas de doble batiente, a cada lado "
    "del cual y a gran altura, hay unos soportes  para antorchas de gran tama�o.\n Al "
    "norte hay una peque�a explanada empedrada donde confluyen los senderos que "
    "ascienden del este y el norte hasta la cima de la colina donde se alza el "
    "castillo.\n" + msg;
}

create(){
    ::create();
    SetLocate("el castillo de Nandor");
    SetIntShort("el puente elevadizo");
    SetIntLong(SF(DescLarga));

    AddDetail("cadenas", "Gruesas cadenas de hierro cubiertas de manchas de �xido.\n");
    AddDetail("murallas", "Levantadas con las antiguas artes de Ishtria, las murallas "
    "constru�das con enormes bloques de piedra gris perfectamente encajados entre s�, "
    "se alzan sobre ti defendiendo las puertas con fuertes almenas y matacanes que se "
    "adelantan sobre el puente.\n");
    AddDetail("almenas", "Alzando la mirada ves las almenas advirtiendo que sobre la "
    "puerta son mas altas y fuertes, sobresaliendo ligeramente hacia afuera y "
    "apoy�ndose sobre gradas invertidas que dificultan a cualquier enemigo tomar las "
    "murallas con escalas.\n");
    AddDetail("matacanes", "Una hilera de orificios situada en la parte inferior de las "
    "almenas que se alzan sobre la puerta por los que se dispara a los atacantes y se "
    "les arrojan piedras y aceite hirviendo sin peligro de que los defensores "
    "queden al descubierto.\n");
    AddDetail("soportes", "Dos soportes de hierro que pueden sostener grandes hachones "
    "con el objeto de iluminar bien el puente y la entrada al castillo.\n");
    AddDetail("senderos", "Dos senderos trillados que ascienden zigzagueando a la "
    "peque�a explanada empedrada situada al norte del puente levadizo.\n");
    AddDetail(({"puerta", "puertas", "entrada"}), "Encajada  en el gran arco de la "
    "entrada, la puerta dividida en dos batientes est� fabricada de gruesas vigas de "
    "roble reforzada por  bandas horizontales de hierro claveteado cubiertas de una "
    "respetable capa de �xido. Los goznes de acero corresponden su tama�o al de los "
    "batientes. Amplias abrazaderas colocadas en la parte interna de la puerta son "
    "usadas para encajar trancas que mantienen los batientes cerrados desde dentro, "
    "aunque para ello son necesarios la fuerza de varios hombres.\n");
    AddDetail("foso", "Te asomas a las almenas para observar el foso. Es una profunda "
    "zanja cabada a los pies de los contrafuertes que sostienen las murallas en cuyo "
    "terroso fondo hay algunos charcos negruzcos de barro malholiente procedente de las "
    "aguas fecales y dem�s desperdicios del castillo. �sta zona ha sido descuidada, "
    "pues sus bordes aparecen desmoronados, las estacas de hierro que rematan el fondo "
    "est�n oxidadas e inclinadas, y en la parte baja crecen algunas plantas rastreras.\n");
    AddDetail(({"estacas", "estaca"}), "Son unas barras de hierro de metro y medio de "
    "longitud que se estrechan desde la base para terminar en punta. Habitualmente este "
    "tipo de defensa se coloca en el fondo de fosos y zanjas defensivas para ensartar a "
    "cualquier hombre o caballo que caiga desde arriba, lo que suele resultar en una "
    "muerte ag�nica y terrible. �stas estacas en particular est�n recubiertas por una "
    "gruesa capa de �xido ya antiguo, aparecido por causa de la humedad y al descuido.\n"
    "Algunas se inclinan precariamente, mientras que otras reposan medio enterradas "
    "en el barro.\n");

    SetIndoors(0);
    SetIntSmell("Percibes el olor de agua estancada procedente del foso.\n");
    AddServerNotification("./entrada");
    AddExit("norte", CASTILLO("camino/camino25"));
    AddExit("sur", "./entrada");
}


