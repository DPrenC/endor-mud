/****************************************************************************
Fichero: guardia_anciano.c
Autor: Dharkus
Fecha: 03/05/2010
Descripción: Un oficial amciano de la guardia de Berat
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
    "en el mostrador del cuartel.\n Su piel está muy arrugada y su aspecto es pálido "
    "y frágil.\n Su cuerpo está lleno de grandes cicatrices, debido a las "
    "muchas luchas en las que sin duda hizo frente en su juventud.\n A causa de esos "
    "lances, únicamente posee una de sus manos.\n");
    AddId(({"guardia", "oficial"}));
    SetAds(({"anciano","viejo"}));
    SetCitizenship("berat");
    SetIVision(0);
    InitChats(3,({"El anciano suspira hondo.\n",
      "El viejo oficial murmura: Cuando yo era joven no había quien me chuleara y "
      "ahora, tengo que aguantar de todo.\n",
      "El viejo mira con pena su muñón.\n"}));
          AddQuestion(({"ciudad","berat","Berat"}),
    "El viejo oficial dice: 'Berat se asienta sobre la margen occidental del gran delta "
      "del Raxal, y constituye un puerto muy importante entre Ishtria y Nine.\n "
      "Por él transitan numerosos viajeros y mercancías, con destino a la capital "
      "o a las regiones interiores del reino de Simauria.'\n");
    AddQuestion(({"roorg","roorgs"}),
    "El viejo oficial dice:\n 'Los roorgs son unos peces carnívoros que han sido cazados "
      "por las gentes del delta, desde hace cientos de años.\n Son unos animales "
      "lentos y pesados, pero sus dentelladas son mortales y pueden destrozar a "
      "un hombre si lo encuentran cara a cara.\n Antaño los hombres los cazaban "
      "acercándoseles en los canales a bordo de ligeros botes, y los hostigaban con "
      "arpones hiriéndolos de grabedad, hasta que estaban lo suficientemente débiles "
      "como para capturarlos y despedazarlos, e incluso algunos usaban sus machetes "
      "para enfrentarse a ellos en el agua, como forma de demostrar su valor.\n Su "
      "piel es muy flexible, resistente e impermeable, y perfecta para elaborar "
      "calzado y ropas.'\n");
    AddQuestion("berati", "El viejo oficial dice:\n 'Los Berati fueron un pueblo de "
    "pescadores que habitaban en el amplio delta del Raxal y en las costas del golfo.\n No "
    "eran guerreros por naturaleza, pero todos aquellos que intentaron conquistarlos, "
    "perecieron en los inextricables laberintos de islas i canales, y por sus "
    "eficientes emboscadas.\n Aún así, años antes de la construcción de Berat, "
    "fueron diezmados, y los supervivientes, con la ayuda de los hombres de Ishtria, "
    "construyeron este puerto como principal punto de desembarco entre el puerto "
    "de Nine y la capital.'\n"); 
    AddItem(PROT("berat/peto_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/pantalon_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/botas_roorg"), REFRESH_REMOVE, SF(wearme));

}
