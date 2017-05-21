/***********************************************************/
//  Camino que une Rhoemas con las grutas de Azmodan
//  camino.c
//  Kodex [28-02-02]
//

#include <properties.h>

#include "./path.h"
inherit SIM_ROOM;


public int QueryCaminoAzmodan() { return 1; }

create() {
    ::create();
    SetIndoors(0);
    SetIntShort("el camino Rhoemas-Azmodan");
switch (random(3))    {
    case 0: SetIntLong(W("Estás en el camino que une el valle de Rhoemas con "
    "la tierra de Azmodan, frontera entre territorios humanos y orcos, que antaño"
    " pertenecía a estas criaturas de la oscuridad.\n"));
        break;
    case 1: SetIntLong(W("Este camino lleva a los valientes exploradores del valle de"
    " Rhoemas a las grutas de Azmodan donde se esconden los orcos. Muchas leyendas hablan"
    " de estas tierras y nada bueno cuentan de ellas.\n"));
        break;
    case 2: SetIntLong(W("El camino ha sido escenario de batallas y persecuciones "
    "y en ningún momento lo ves como un lugar seguro, deberías acelerar la marcha "
    "para llegar cuanto antes a tu destino.\n"));
        break;
    default:break;
    }
SetIntNoise("Oyes el canto de los pájaros.\n");
    if(d3()==1)
        AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,d3());

Adornar();

}

public void Adornar()
{
    object adorno;
    switch (random(20))
        {
        case 0: //una piedra
            AddItem(OBJETO_AZMODAN("piedra_camino"), REFRESH_REMOVE);
            break;
        case 1: //un esqueleto humano
            adorno = clone_object("/std/thing");
            adorno->SetShort("un esqueleto humano");
            adorno->SetLong(W("Probablemente una de las víctimas de los orcos que habitan "
            "Azmodan, o quizá un antiguo soldado humano que combatió contra los orcos de "
            "Azmodan tiempo atrás.\n"));
            adorno->SetIds(({"esqueleto","esqueleto humano"}));
            adorno->SetWeight(50000);
            AddItem(adorno,REFRESH_REMOVE,1);
            break;
        case 2: //un esqueleto orco
            adorno = clone_object("/std/thing");
            adorno->SetShort("un esqueleto orco");
            adorno->SetLong(W("Los clanes orcos de Azmodan siempre luchando, es posible "
            "que este orco sea víctima de sus disputas internas... o quizá este esqueleto "
            "se remonta a la guerra contra los humanos.\n"));
            adorno->SetIds(({"esqueleto","esqueleto orco"}));
            adorno->SetWeight(50000);
            AddItem(adorno,REFRESH_REMOVE,1);
            break;
        default:break;
        }
}
