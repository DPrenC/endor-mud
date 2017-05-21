/* Archivo:         lavadero.c
   Autor:           Yalin y Lug
   Descripci�n:     lavadero de ropa de la aldea de Sloch
   Fecha:           29/05/2006
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("un lavadero de ropa en la aldea  de Sloch");
    SetIntLong("Est�s dentro de una estructura cuadrangular bastante grande con un techo de "
    "ladrillos cocidos al sol sujeto por cuatro gruesos pilares. Hay dos grandes pilas de piedra "
    "utilizadas por los habitantes de la aldea para labar ropas y enseres.\nSolamente puedes "
    "salir hacia el nordeste, las dem�s  salidas est�n bloqueadas por el r�o dado que este lugar se "
    "interna ligeramente dentro del cauce.\n");
    SetIntSmell("Hay un exttra�o olor, debe ser el tipo de jab�n que se utiliza aqu�.\n");
    SetIntNoise("Se escucha el fragor producido por la corriente del r�o al pasar bajo el lavadero.\n");
    AddDetail(({"suelo"}), "Se trata de unas grandes placas de piedra que se "
        "apoyan en pibotes de madera hundidos en el lecho del r�o. Bajo "
        "ellas pasan las aguas del kandal.\n");
    AddDetail(({"techo"}), "est� construido con ladrillos ligeros que se "
        "apoya sobre unas vigas que descargan su peso sobre cuatro columnas "
        "en las esquinas del cobertizo.\n");
    AddDetail(({"ladrillo", "ladrillos"}), "Son ladrillos de adobe y "
        "conforman el techo de este lugar.\n");
    AddDetail(({"columna","columnas","pilar", "pilares"}), "Est�n "
        "construidos con sillares de piedra caliza y soportan el peso de la "
        "techumbre. Est�n ya bastante desgastados por no ser esta una piedra "
        "adecuada a un lugar con tanta humedad.\n");
    AddDetail(({"viga", "vigas"}), "Son grandes vigas de madera que "
        "descargan el peso de los ladrillos del techo sobre los pilares que "
        "soportan todo el entramado.\n");
    AddDetail(({"pared", "paredes"}), "No hay paredes, los paneles est�n "
        "vac�os dejando pasar la luminosidad del d�a.\n");
    AddDetail(({"pila", "pilas", "lavadero"}), "Son dos dep�sitos "
        "rectangulares con unas peque�as compuertas para meter y sacar el "
        "agua con el objeto de poder lavar. En los extremos hay unas maderas "
        "estriadas para poder restregar las prendas.\n");
    AddDetail(({"compuerta", "compuertas"}), "cada una de las pilas tiene "
        "dos, una alta que al ser abierta toma agua desde el cauce del r�o, "
        "y otra baja que se encarga de vaciarla.\n");
    AddDetail(({"madera", "maderas", "maderas estriadas"}), "son unas tablas "
        "con estr�as que est�n en los extremos de las pilas y colocadas "
        "obl�cuamente para restregar las prendas sobre ellas al ser lavadas.\n");
    AddDetail(({"rio", "r�o", "cauce", "oeste", "norte", "sur"}), "Es el r�o "
        "Kandal, que viene del este, y hace aqu� un giro abrazando la aldea "
        "por el sur. El lugar en el que est�s se interna en el cauce "
        "haciendo que parte de la corriente discurra bajo tus pies.\n");
    AddExit("nordeste", SHERALD("calles/caminorio05"));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,2);
}

