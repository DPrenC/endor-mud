/* psi_ruins13.c
   Antigua Biblioteca
   Creaci�n: [n] Nemesis, 19-Abr-2001 01:54:00 CEST
   Notas: El sitio m�s obvio para guardar una piedra de memoria.
*/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <skills.h>
inherit SIM_ROOM;
#define AO (TP->QueryGenderEndString())
#define TRAMPA 30

public void notify_leave(mixed to, int method, mixed extra)
{
    ::notify_leave(to, method, extra);
    if (!TP) return;
    if (find_call_out("_rastrear") != -1)
    {
        write("Dejas de revolver papeles.\n");
        while (remove_call_out("_rastrear") != -1);
        TP->remove_attribute("rastreando");
    }
}

int cmd_buscar(string str)
{
    if (str!="rollo" && str!="rollos" && str!="entre rollos" && str!="entre los rollos") return 0;
        if (find_call_out("_rastrear") != -1)
    {
        if ((TP->SetAttribute("rastreando", TP->QueryAttribute("rastreando") + 1)) >= TRAMPA)
        {
            CHANNELMASTER->SendEmote("mud","Simauria ruega a "+CAP(TNAME)+" que quite el "
                "pisapapeles del intro y sea un poquito honest"+AO+"");
            TP->RemoveAttribute("rastreando");
            write_file(LOGS "trampas_rastreando",ctime(time()) + ", " + CAP(TNREAL)+" ha "
                "intentado hacer trampas rastreando en la biblioteca de los psi�nicos.\n");
        }
        write("A�n est�s rastreando. Espera a terminar para empezar de nuevo.\n");
        return 1;
    }
    write("comienzas a remover los restos de los rollos...\n");
    say(CAP(TNAME) + " comienza a revolver entre los restos de pergamino...\n",TP);
    call_out("_rastrear",2 + random(5));
    return 1;
}

string m_rollo()
{
    if (TP->QueryAttribute("encontrado_calmar")) return"Al coger uno de los rollos, se "
        "desintegra en tus manos. No esperes sacar nada de ellos.\n";
    return "Est�n muy deteriorados, y parecen quebradizos. Te paras a pensar si tal vez, "
        "buscando entre ellos, podr�as encontrar alguno medianamente �til...\n";
}
    
int _rastrear()
{
    TP->RemoveAttribute("rastreando");
    if (!TP->QueryAttribute("encontrado_calmar"))
    {
        int rastrea=TP->UseSkill(HAB_RASTREAR);
        if (rastrea>=25)
        {
            object perga=clone_object("/guilds/kisalas/pergamino/pergamino_calmar");
            TP->SetAttribute("encontrado_calmar",time());
            write("�Vaya! Entre las virutas de papel, encuentras un viejo pergamino.\n");
            if (!perga->move(TP))
            {
                perga->move(environment());
                write("Sin que puedas evitarlo, el pergamino se te cae de las manos.\n");
                say("A "+capitalize(TP->QueryName())+" se le cae un pergamino antiguo.\n",TP);
                return 1;
            }
            return 1;
        }
        write("Remueves algunos rollos que se te deshacen en las manos.\nNo encuentras nada.\n");
        return 1;
    }
    return notify_fail("Intentas revolver entre los viejos rollos, pero se te deshacen en las manos.\n");
}
                
create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("la antigua biblioteca");
SetIntLong(
"Te encuentras en una enorme sala cuadrada cuyas paredes est�n cubiertas de\
 estantes, donde probablemente estuvieron depositados libros y pergaminos que\
 conten�an la antigua sabidur�a del Gremio. Hoy, sin embargo, s�lo contienen\
 algunos viejos rollos y polvo, mucho polvo. Las mesas y asientos que usaron\
 los miembros del gremio para consultar el saber antiguo est�n tirados en el\
 suelo y son casi irreconocibles. Sin embargo, no todo se ha perdido. Unos\
 cristales refulgentes situados en las paredes dan luz a la estancia,\
 recordando en cierto modo el poder y la majestad que pose�a el Gremio.\
 Te resulta triste pensar que tanta sabidur�a y poder se hayan perdido para\
 siempre. Una escalera en el centro de la habitaci�n conduce al piso superior.\n\
Hay una puerta corredera abierta que conduce al exterior en la pared norte y\
 en la pared oeste hay una puerta met�lica con un letrero sobre ella.\n");
SetIntSmell("Huele como a papel rancio.\n");
SetIndoors(1);
SetIntBright(25);

AddDetail(({"escalera"}),
"Una carcomida escalera de madera da acceso al piso superior.\n");
AddDetail(({"estantes"}),
"Cubren las paredes de la sala, sin embargo s�lo contienen polvo y algunos "
"viejos rollos de pergamino.\n");
AddDetail(({"cartel","letrero"}),
"Hay unos signos que parecen flotar sobre �l.\n");
AddDetail(({"signos"}),
"Es dudoso que puedas descifrarlos, pero te llama la atenci�n que brillen con "
"una tenue luz azul.\n");
AddDetail(({"puerta"}),
"�Qu� puerta, la met�lica o la corredera?\n");
AddDetail(({"puerta corredera"}),
"Est� abierta, y es dudoso que puedas cerrarla. Conduce fuera de la sala, "
"al pasillo.\n");
AddDetail(({"puerta met�lica","puerta metalica"}),
"Abollada y desencajada, pero todav�a parece nueva. Refleja la luz de la "
"sala con un tenue reflejo irisado. La sala a la que da acceso est� vivamente "
"iluminada.\n");
    AddDetail(({"polvo"}),"Lo cubre todo. �Quiz� tienes ganas de ponerte a limpiar?\n");
    AddDetail(({"mesas"}),"Est�n casi todas volcadas en el suelo y destrozadas. Fueron de "
        "madera noble, pero ahora est�n completamente carcomidas.\n");
    AddDetail(({"asientos","sillas"}),"No crees que aguantasen tu peso... De hecho, te "
        "sorprende que sean capaces de aguantar el suyo propio.\n");
    AddDetail(({"pergaminos","rollos"}),SF(m_rollo));
    AddDetail(({"cristales","l�mparas","cristales refulgentes"}),"Sirven, a modo de l�mparas, "
        "para iluminar la estancia. Te preguntas c�mo es posible que a�n funcionen.\n");
    AddReadMsg(({"signos","signos brillantes"}),"Como te tem�as, no puedes descifrarlos, pero "
        "es curioso que conserven esa extra�a luz azul a pesar de haberse deteriorado con el "
        "tiempo.\n");
    AddExit("norte","./psi_ruins11");
    AddExit("oeste","./psi_ruins14");
    AddExit("arriba","./psi_ruins21");
    AddRoomCmd("remover","cmd_buscar");
    AddRoomCmd("revolver","cmd_buscar");
    AddRoomCmd("buscar","cmd_buscar");
}

