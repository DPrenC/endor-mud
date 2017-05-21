/***
Fichero: calle1.c
Autor: kastwey@simauria
Descripci�n: Principio de la calle principal de siempreunidos.
Creaci�n: 02/12/2004
17/12/2004
Le a�ado el sendero que conecta con el bosque de atbalnin.
22/12/2004 Le pongo el cartel para avisar que la recompensa por la cabeza
de un player, es para los pnj del pueblo, y no para otros players... que
me veo a m�s de uno practicando el PK ;)
23/12/2004 A�ado una fuentecilla pa que la pe�a pueda beber, y pongo que salgan los enemigos en el cartel.
***/

#include "path.h"
#include <sounds.h>
inherit STD_FAERIA("hab_siempreunidos");

string ver_taberna();
string leer_cartel();
int cmd_coger(string str);

create()
{
    ::create();
    SetIntShort("la calle principal de Siempreunidos");
    SetIntLong(W("Te encuentras en la parte m�s sure�a de la calle principal del peque�o pueblo de Siempreunidos.\n"
    "La calle contin�a en direcci�n norte, mientras que al sur, un peque�o sendero se adentra en el bosque de Atbalnin. Al este, puedes ver lo que parece una posada, y al oeste una taberna.\n"
    "En medio de la calle, puedes ver un pedestal con la estatua de un elfo de cuya boca brota un gran chorro de agua que parece muy refrescante.\n"
    "Tambi�n puedes ver un cartel colgado de un poste.\n"));
    SetOutdoors(1);
    SetOficina(HAB_PUESTO("calles/calle_02"));
    AddDetail(({"taberna"}), SF(ver_taberna));
    AddDetail(({"construcci�n", "construcciones", "posada"}), W("Al fijarte mejor, observas que tanto la posada como la taberna parecen hechas de madera sin pulir.\n"
    "M�s bien parecen �rboles gigantescos que han sido adaptados de alguna forma (m�gica seguramente) para servir como vivienda a los elfos habitantes de este poblado.\n"));
    AddDetail(({"cartel","letrero"}),"Es un cartel clavado en un poste. Quiz�s podr�as leerlo.\n");
    AddDetail(({"poste","palo"}),"Es un poste situado en uno de los laterales de la calle. Sobre �l hay clavado un gran cartel.\n");
    AddDetail(({"pedestal","pie","pi�","soporte"}),"Es un pedestal sobre el "
        "que est� situada la figura de un elfo.\n");
    AddReadMsg(({"cartel","letrero"}),SF(leer_cartel));
    AddRoomCmd("coger","cmd_coger");
    AddExit("este", HAB_PUESTO("posada/posada"));
    AddExit("oeste", HAB_PUESTO("taberna/taberna"));
    AddExit("norte", HAB_PUESTO("calles/calle_02"));
    AddExit("sur",HAB_PUESTO("calles/sendero2"));
    AddItem(PNJ_PUESTO("encubierto"),REFRESH_DESTRUCT,(["GoChance":50]),1);
    AddItem(PNJ_PUESTO("soldado"), REFRESH_HOME, 1);
    AddItem(PNJ_PUESTO("sargento"), REFRESH_HOME, 1);
    AddItem(OBJ_OTRO_FAERIA("fuente"));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}


string ver_taberna()
{
    if (CHRONOS->QueryHour() >=3 && CHRONOS->QueryHour()<10)
    {
        return(W("Al fijarte mejor, observas que tanto la posada como la taberna parecen hechas de madera sin pulir.\n"
        "M�s bien parecen �rboles gigantescos que han sido adaptados de alguna forma (m�gica seguramente) para servir como vivienda a los elfos habitantes de este poblado.\n"
        "Puedes ver un cartel colgado en la puerta en el que dice:\n"
        "Cerrado! Nuestro horario de apertura es de 10 de la ma�ana a 3 de la madrugada.\n"));
    }
    else
    {
        return(W("Al fijarte mejor, observas que tanto la posada como la taberna parecen hechas de madera sin pulir.\n"
        "M�s bien parecen �rboles gigantescos que han sido adaptados de alguna forma (m�gica seguramente) para servir como vivienda a los elfos habitantes de este poblado.\n"));
    }
}


string leer_cartel()
{
	  return W("Bienvenid" + AO + " al pueblo de Siempreunidos.\n"
    "A continuaci�n, te informamos de las leyes vigentes en nuestro pueblo:\n"
    "Aqu�, el asesinato o intento de agresi�n contra uno de nuestros habitantes, ser� severamente castigado por nuestros guardias.\n"
    "Si alguien asesina a uno de nuestros habitantes se ofrecer� una recompensa por su captura, que ir� aumentando seg�n los asesinatos que ese individuo lleve a sus espaldas.\n"
    "Atenci�n! La recompensa se otorgar� �nicamente a las autoridades pertinentes en el poblado. Si usted ve a una persona buscada por la guardia, informe en la oficina local.\n\n\n"
    "Nota importante!: Las siguientes razas, no ser�n bienvenidas en nuestro pueblo, por razones evidentes:\n" +
    implode(RAZASENEMIGAS[0..<2],", ")+(sizeof(RAZASENEMIGAS[0..<2])?" y ":"")+RAZASENEMIGAS[<1] + ".\n"
    "Firmado: Shadezzar.\n");
}

int cmd_coger(string str)
{
 	  if (!str || (str != "fuente" && str != "estatua")) return 0;
 	  if (present("guardia_faeria",TO) && living(present("guardia_faeria",TO)))
 	  {
 	  	  write(W("Te agarras fuertemente a la estatua e intentas levantarla.\n" + capitalize(present("guardia_faeria",TO)->QueryName()) + " te mira con sorna y comienza a reirse entre dientes.\n"
 	  	  "Con la sensaci�n de haber hecho el idiota, te alejas de la fuente e intentas pegarte a una de las paredes a ver si la tierra te traga o algo.\n"));
 	  	  say(W(capitalize(TP->QueryName()) + " se agarra a la estatua e intenta levantarla.\n" + capitalize(present("guardia_faeria",TO)->QueryName()) + " l" + AO + " mira con sorna y comienza a reirse entre dientes.\n"),TP);
 	  	  return 1;
 	  }
 	  else
 	  {
 	  	  write("Te agarras fuertemente a la estatua e intentas levantarla, pero te es imposible.\n");
 	  	  say(W(capitalize(TP->QueryName()) + " se agarra fuertemente a la estatua e intenta levantarla. Tras un rato intent�ndolo, lo deja por imposible.\n"),TP);
 	  }
 	  return 1;
}
