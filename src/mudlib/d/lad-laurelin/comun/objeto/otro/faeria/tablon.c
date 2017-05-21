/***
Fichero: tablon.c
Autor: kastwey@simauria
Descripción: El cartel donde aparecen los enemigos de Faeria, y los muertos
que llevan a sus espaldas.
Creación: 01/12/2004
10/12/2004
Quito muchas cosas... pa que contarlas todas
Nyh... pa que no digas que es obsceno ;)
26/12/2004 Uso sprintf para evitarme to la morralla de los espacios
***/

#include "path.h"
#define RECOMPENSA 20

inherit THING;
int cmd_leer(string str);

create()
{
    ::create();
    seteuid(getuid());
    SetShort("un tablón");
    SetLong(W("Es un tablón en el que aparecen las personas más buscadas del poblado.\n"
        "Quizás podrías leerlo.\n"));
    SetIds(({"tablón", "tablon"}));
    SetNoGet(1);
    SetNoDrop(1);
    SetNoTake(1);
}

init()
{
    ::init();
    add_action("cmd_leer", "leer");
    if (!TP) return;
    if (!TP->QueryAttribute("enemigo_faeria") && TABLON_ENEMIGOS->QueryEnemies()[TP->QueryRealName()]) TABLON_ENEMIGOS->RemoveEnemy(TP);
    if (!TP->QueryAttribute("non_grata_faeria") && TABLON_ENEMIGOS->QueryNonGratas()[TP->QueryRealName()]) TABLON_ENEMIGOS->RemoveNonGrata(TP->QueryRealName());
}

int cmd_leer(string str)
{
    string mensaje = "";
    int i;
    string *indices;
    if (member(QueryIds(), str) < 0)
    // no ha puesto leer cartel, letrero, ETC...
        return 0;
    indices = m_indices(TABLON_ENEMIGOS->QueryEnemies() || ({}));
    if (sizeof(indices))
    {
        mensaje = "Las personas más buscadas de Faeria.\n"
            "Nombre     |     personas asesinadas         |         recompensa\n";
        for (i=0;i<sizeof(indices);i++)
        {
            mensaje += sprintf("%-17s%-38d%s\n",indices[i],TABLON_ENEMIGOS->QueryEnemies()[indices[i]],TABLON_ENEMIGOS->QueryEnemies()[indices[i]]*RECOMPENSA + " mithriles");
        }
    }
    indices = m_indices(TABLON_ENEMIGOS->QueryNonGratas());
    if (sizeof(indices))
    {
        mensaje +="\n\nPersonas non gratas en Siempreunidos.\n"
        "La siguiente lista de personas no son bienvenidas en nuestro pueblo, por haber intentado asesinar a alguno de nuestros ciudadanos, o bien por haber provocado alteraciones en el orden público.\n\n";
        mensaje += implode(indices[0..<2],", ")+(sizeof(indices[0..<2])?" y ":"")+indices[<1];
        mensaje+=".\n";
    }


    if (mensaje == "") return write("El tablón está vacío.\n"), 1;
    else STR->smore(mensaje, TP->QueryPageSize());
    return 1;
}
