/****************************************************************************
Fichero: guardia.c
Autor: Ratwor
Fecha: 08/05/2010
Descripci�n: un soldado de la guardia de Berat.
****************************************************************************/



#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>

inherit NPC;
inherit GUARD;


create() {
    "*"::create();

    SetStandard("un guardia","humano",([GC_LUCHADOR:24+d6()]),GENDER_MALE);
    SetShort("un Soldado de la Guardia");
    switch(d3()){
        case 1:
            SetLong("Es un j�ven de baja estatura, constituci�n ligera y pelo casta�o.\n "
            "Su f�sico y rasgos faciales lo identifican como descendiente de los "
            "Verati, pueblo que habit� en el delta del Raxal antes de que los ishtrios "
            "vinieran del Mar y que con la ayuda de �stos edificaron el puerto "
            "de Verat en la parte occidental del delta.\n");
            break;
        case 2:
            SetLong("Es un hombre de estatura baja y constituci�n ligera pero "
            "nervuda.\n Su pelo casta�o est� cuajado de ebras plateadas y ostenta "
            "una media barba entrecana partida por una antigua cicatriz que le "
            "cruza el carrillo izquierdo.\n Su f�sico y rasgos faciales lo identifican "
            "como descendiente los Berati, pueblo que habit� en el delta del Raxal "
            "antes de que los Ishtrios vinieran del mar y que con la ayuda de �stos, "
            "edificaron el puerto de Berat en la parte occidental del delta.\n");
            break;
        case 3:
            SetLong("Es un hombre de estatura media, pelo casta�o oscuro y facciones "
            "angulosas.\n Tiene la piel curtida por el efecto del aire y el clima "
            "marino y la cicatriz de una dentellada de lo que podr�a ser un roorg, "
            "le recore el antebrazo del codo a la mu�eca.\n Con sus rasgos y aspecto "
            "f�sico, no se trata de un Berati, sino de un mestizaje con gentes de "
            "otra procedencia.\n");
            break;
    } 
    SetLong(QueryLong()+"Forma parte de la guardia de Berat, un cuerpo de defensa "
   "formado por los m�s audaces y avezados habitantes oriundos de este puerto, que "
    "patrullan tanto sus calles como el laberinto de canales e islas que forman "
    "el gran delta, a bordo de peque�as embarcaciones, e incluso hostigan a los "
    "piratas que de vez en cuando entran en el gran golfo de Berat.\n"); 
    AddId(({"guardia","soldado","soldado de la guardia", "hombre"}));
    SetCitizenship("berat");
    SetIVision(0);
    SetGoChance(50);
    AddWalkZones(SIMA("berat"));
    AddQuestion(({"ciudad","berat","Berat"}),
    "El guardia dice: 'Berat se asienta sobre la margen occidental del gran delta "
      "del Raxal, y constituye un puerto muy importante entre Ishtria y Nine.\n "
      "Por �l transitan numerosos viajeros y mercanc�as, con destino a la capital "
      "o a las regiones interiores del reino de Simauria.'\n");
    AddQuestion(({"roorg","roorgs"}),
    "El guardia dice:\n 'Los roorgs son unos peces carn�voros que han sido cazados "
      "por las gentes del delta, desde hace cientos de a�os.\n Son unos animales "
      "lentos y pesados, pero sus dentelladas son mortales y pueden destrozar a "
      "un hombre si lo encuentran cara a cara.\n Anta�o los hombres los cazaban "
      "acerc�ndoseles en los canales a bordo de ligeros botes, y los hostigaban con "
      "arpones hiri�ndolos de grabedad, hasta que estaban lo suficientemente d�biles "
      "como para capturarlos y despedazarlos, e incluso algunos usaban sus machetes "
      "para enfrentarse a ellos en el agua, como forma de demostrar su valor.\n Su "
      "piel es muy flexible, resistente e impermeable, y perfecta para elaborar "
      "calzado y ropas.'\n");
    AddQuestion("berati", "El guardia dice:\n 'Los Berati fueron un pueblo de pescadores "
    "que habitaban en el amplio delta del Raxal y en las costas del golfo.\n No "
    "eran guerreros por naturaleza, pero todos aquellos que intentaron conquistarlos, "
    "perecieron en los inextricables laberintos de islas i canales, y por sus "
    "eficientes emboscadas.\n A�n as�, a�os antes de la construcci�n de Berat, "
    "fueron diezmados, y los supervivientes, con la ayuda de los hombres de Ishtria, "
    "construyeron este puerto como principal punto de desembarco entre el puerto "
    "de Nine y la capital.'\n"); 
    InitChats(3,({
      "El guardia examina el filo de su sable en busca de alguna mella.\n",
      "El guardia balancea distra�damente su arp�n.\n",
      "El guardia desliza el dedo sobre el curvo filo de su sable con adem�n amenazador.\n",
      "El guardia lanza unos cuantos arponazos de pr�ctica al aire.\n"}));
    InitAChats(7, ({
      "El guardia lanza una estocada ascendente con la punta curva de su sable "
      "y arremete por el otro lado con el arp�n de punta aserrada.\n",
      "El guardia asesta un tajo lateral con el sable.\n",
      "El guardia voltea el arp�n en el aire golpeando alternativamente con la punta "
      "y con el extremo del mango.\n",
      "El guardia asesta un brutal tajo con su sable.\n",
    "El guardia amaga un tajo con el sable para acabar lanzando un arponazo con la otra mano.\n"}));

    AddItem(ARMA("sable_corto"), REFRESH_REMOVE, SF(wieldme));
    AddItem(ARMA("arpon_dentado"), REFRESH_REMOVE, SF(wieldme));
    AddItem(PROT("berat/peto_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/pantalon_roorg"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROT("berat/botas_roorg"), REFRESH_REMOVE, SF(wearme));
}

