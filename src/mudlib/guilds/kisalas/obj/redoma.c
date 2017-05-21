/****************************************************************************
Fichero: /guilds/kisalas/objeto/redoma
Autor: Yalin
Fecha: 28/01/2008 12:52
Descripción: Vasija contenedora para el ungüento
****************************************************************************/

#include "path.h"
#include <properties.h>
inherit THING;

//variables globales
int tiene,poder;
string cal;

void describe()
{
    string imagen, contiene, nivel;
    imagen="Es un pequeño recipiente semiesférico de vidrio, cerrado por un tapón de corcho, "
        "a propósito para guardar ungüentos o pociones espesas.\n";
    if (tiene == 0) contiene="";
    else contiene="Contiene una pasta aceitosa de un color verde esmeralda.\n";
    switch(tiene)
    {
        case 0:
            nivel="Está vacío.\n";
        break;
        case 1:
            nivel="Está casi vacío.\n";
        break;
        case 2:
            nivel="Queda menos de la mitad.\n";
        break;
        case 3:
            nivel="Queda la mitad.\n";
        break;
        case 4:
            nivel="Queda más de la mitad.\n";
        break;
        case 5:
            nivel="Está casi lleno.\n";
        break;
        case 6:
            nivel="Está lleno.\n";
        break;
    }
    switch(poder)
    {
        case 1:
            cal="muy mala";
        break;
        case 2:
            cal="mala";
        break;
        case 3:
            cal="regular";
        break;
        case 4:
            cal="buena";
        break;
        case 5:
            cal="muy buena";
        break;
        case 6:
            cal="excelente";
        break;
    }
    if (tiene==0) SetShort("Un pomo de cristal vacío");
    else SetShort("un pomo de cristal con bálsamo de calidad "+cal);
    SetLong(imagen+contiene+nivel);
    SetWeight(100+(5*tiene));
    SetValue(500+(tiene*poder*5));
    return;
}

//funciones de cantidad
void SetContent(int cont)
{
    tiene = cont;
    describe();
    return;
}
int QueryContent() { return tiene; }

//funciones de poder curativo
void SetPotencia(int pot)
{
    poder = pot;
    describe();
    return;
}
int QueryPotencia() { return poder; }
        
private void empty()
{
    tiene=0;
    poder=0;
    describe();
}
create()
{
    ::create();
    empty();
    AddId(({"pomo","pomo de vidrio","pomo de cristal","recipiente","recipiente de vidrio",
        "recipiente de cristal","balsamo_vial"}));
    Set(P_MATERIAL,M_CRISTAL);
}

init()
{
    ::init();
    add_action("fvaciar","vaciar");
}

int fvaciar(string str)
{
    if (!str) return notify_fail("¿Vaciar qué?\n",NOTIFY_NOT_VALID);
    if (member(TO->QueryIds(),str)!=-1)
    {
        if (tiene==0) return notify_fail("El pomo ya está vacío.\n",NOTIFY_NOT_VALID);
        tell_object(TP,"Destapas el pomo y lo vuelcas. El bálsamo se derrama, extendiéndose "
            "por el suelo hasta desaparecer.\n");
        if (TP->QueryInvis()<1) tell_room(environment(TP),TNAME+" vuelca un pomo de cristal, y "
            "su contenido se derrama, filtrándose por el suelo.\n",({TP}));
        empty();
        return 1;
    }
    return 0;
}

