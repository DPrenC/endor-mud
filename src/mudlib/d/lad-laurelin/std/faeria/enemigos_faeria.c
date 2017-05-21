/***
Fichero: enemigos_faeria.c
Autor: kastwey@simauria
Descripción: El server de enemigos que llevan a sus espaldas.
Creación: 09/12/2004
20/12/2004
Añadido el inform_death, para quitar de enemigo al que muera por un soldado o algo.
26/12/2004 añado un par de funciones: AddEnemies y AddNOnGratas
Pretenden añadir varios enemigos de una vez, para cuando lo ponga un guardia.
***/

#include "path.h"

#define SAVE_HERE DOMAINLOGPATH "lad-laurelin/enemigos_faeria"

public int AddEnemy(object enemigo);
public int RemoveEnemy(object enemigo);
public mapping QueryEnemies();
public mapping AddEnemies(mapping enemigos);
public int AddNonGrata(mixed enemigo);
public int RemoveNonGrata(mixed enemigo);
public mapping QueryNonGratas();
public mapping AddNonGratas(mapping nongratas);

mapping pEnemies = ([]);
mapping pNonGratas = ([]);

public int AddEnemy(object enemigo)
{
    if (!enemigo) return 0;
    pEnemies[enemigo->QueryRealName()]++;
    enemigo->SetAttribute("enemigo_faeria", 1);
    save_object(SAVE_HERE);
    return 1;
}
public int RemoveEnemy(object enemigo)
{
    if (!enemigo) return 0;
    if (pEnemies[enemigo->QueryRealName()])
    {
        pEnemies = m_delete(pEnemies, enemigo->QueryRealName());
        enemigo->RemoveAttribute("enemigo_faeria");
        save_object(SAVE_HERE);
        return 1;
    }
    else
    {
        return 0;
    }
}

public mapping QueryEnemies() { return pEnemies; }


public int AddNonGrata(mixed enemigo)
{
    if (!enemigo) return 0;
    if (objectp(enemigo))
    // es un objeto
    {
    	  if (pEnemies[enemigo->QueryRealName()]) return 0;
    	  pNonGratas[enemigo->QueryRealName()]++;
        enemigo->SetAttribute("non_grata_faeria", 1);
    }
    else if (stringp(enemigo))
    // es un nombre
    {
    	  object en_obj;
    	  if (pEnemies[enemigo]) return 0;
    	  pNonGratas[enemigo]++;
    	  if (en_obj = find_object("enemigo")) en_obj->SetAttribute("non_grata_faeria",1);
    }
    else return 0;
    save_object(SAVE_HERE);
    return 1;
}

public int RemoveNonGrata(mixed enemigo)
{
    if (!enemigo) return 0;
    if (objectp(enemigo))
    {
    	  // se le pasó objeto como parámetro
      	if (pNonGratas[enemigo->QueryRealName()])
        {
            pNonGratas = m_delete(pNonGratas, enemigo->QueryRealName());
            enemigo->RemoveAttribute("non_grata_faeria");
            save_object(SAVE_HERE);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (stringp(enemigo))
    // se le ha pasado el string con el nombre
    {
    	  if (pNonGratas[enemigo])
    	  {
    	  	  pNonGratas = m_delete(pNonGratas,enemigo);
    	  	  if (find_object(enemigo)) find_object(enemigo)->RemoveAttribute("non_grata_faeria");
    	      return 1;
    	  }
    	  else
    	  {
    	  	  return 0;
    	  }
    }
}

public mapping QueryNonGratas() { return pNonGratas; }

create()
{
    seteuid(getuid());
    restore_object(LOGS "enemigos_faeria");
}

void inform_death()
{
    if (!PO || !PO->QueryKiller()) return;
    if (PO->QueryKiller()->QueryIsGuardiaFaeria() || PO->QueryKiller()->QueryIsElementalFaeria())
    // el que ha matado al player es un guardia de faeria
    {
    	  if (QueryEnemies()[PO->QueryRealName()])
{
	      	  RemoveEnemy(PO);
	      	  filter(all_inventory(environment(PO->QueryKiller())),
                (: if (call_other($1, "QueryIsGuardia"))
                {
                	  $1->BorraInformadores();
                	  $1->ResetInform();
                }
                else 0;
                	:));
        }
    }
}

public mapping AddEnemies(mapping enemigos)
{
	  string *personas;
	  int i;
	  personas = m_indices(enemigos);
	  for (i=sizeof(personas);i--;)
	  {
	  	  if (pNonGratas[personas[i]]) RemoveNonGrata(personas[i]);
	  	  pEnemies[personas[i]] += enemigos[personas[i]];
	  	  if (find_object(personas[i])) find_object(personas[i])->SetAttribute("enemigo_faeria",1);
	  }
	  save_object(SAVE_HERE);
    return pEnemies;
}


public mapping AddNonGratas(mapping nongratas)
{
	  string *personas;
	  int i;
	  personas = m_indices(nongratas);
	  for (i=sizeof(personas);i--;)
	  {
	  	  if (!pEnemies[personas[i]]) pNonGratas[personas[i]] += nongratas[personas[i]];
	  	  if (find_object(personas[i])) find_object(personas[i])->SetAttribute("non_grata_faeria",1);
	  }
	  save_object(SAVE_HERE);
    return pNonGratas;
}
