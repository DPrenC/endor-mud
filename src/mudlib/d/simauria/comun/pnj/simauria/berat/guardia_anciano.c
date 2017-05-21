/****************************************************************************
Fichero: guardia_anciano.c
Autor: Dharkus
Fecha: 03/05/2010
Descripci�n: Un oficial amciano de la guardia de Berat
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
inherit GUARD;

create()
{
    "*"::create();
    
    SetStandard("el viejo oficial","humano",([GC_LUCHADOR:18]),GENDER_MALE);
    SetShort("Un viejo oficial de la guardia");
    SetLong("Es un anciano oficial de la guardia de Berat, encargado de atender "
    "en el mostrador del cuartel.\n Su piel est� muy arrugada y su aspecto es p�lido "
    "y fr�gil.\n Su cuerpo est� lleno de grandes cicatrices, debido a las "
    "muchas luchas en las que sin duda hizo frente en su juventud.\n A causa de esos "
    "lances, �nicamente posee una de sus manos.\n");
    AddId(({"guardia", "oficial"}));
    SetAds(({"anciano","viejo"}));
    SetCitizenship("berat");
    SetIVision(0);
    InitChats(3,({"El anciano suspira hondo.\n",
      "El viejo oficial murmura: Cuando yo era joven no hab�a quien me chuleara y "
      "ahora, tengo que aguantar de todo.\n",
      "El viejo mira con pena su mu��n.\n"}));
          AddQuestion(({"ciudad","berat","Berat"}),
    "El viejo oficial dice: 'Berat se asienta sobre la margen occidental del gran delta "
      "del Raxal, y constituye un puerto muy importante entre Ishtria y Nine.\n "
      "Por �l transitan numerosos viajeros y mercanc�as, con destino a la capital "
      "o a las regiones interiores del reino de Simauria.'\n");
    AddQuestion(({"roorg","roorgs"}),
    "El viejo oficial dice:\n 'Los roorgs son unos peces carn�voros que han sido cazados "
      "por las gentes del delta, desde hace cientos de a�os.\n Son unos animales "
      "lentos y pesados, pero sus dentelladas son mortales y pueden destrozar a "
      "un hombre si lo encuentran cara a cara.\n Anta�o los hombres los cazaban "
      "acerc�ndoseles en los canales a bordo de ligeros botes, y los hostigaban con "
      "arpones hiri�ndolos de grabedad, hasta que estaban lo suficientemente d�biles "
      "como para capturarlos y despedazarlos, e incluso algunos usaban sus machetes "
      "para enfrentarse a ellos en el agua, como forma de demostrar su valor.\n Su "
      "piel es muy flexible, resistente e impermeable, y perfecta para elaborar "
      "calzado y ropas.'\n");
    AddQuestion("berati", "El viejo oficial dice:\n 'Los Berati fueron un pueblo de "
    "pescadores que habitaban en el amplio delta del Raxal y en las costas del golfo.\n No "
    "eran guerreros por naturaleza, pero todos aquellos que intentaron conquistarlos, "
    "perecieron en los inextricables laberintos de islas i canales, y por sus "
    "eficientes emboscadas.\n A�n as�, a�os antes de la construcci�n de Berat, "
    "fueron diezmados, y los supervivientes, con la ayuda de los hombres de Ishtria, "
    "construyeron este puerto como principal punto de desembarco entre el puerto "
    "de Nine y la capital.'\n"); 
    AddItem(PROT("berat/peto_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/pantalon_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/botas_roorg"), REFRESH_REMOVE, SF(wearme));

}
