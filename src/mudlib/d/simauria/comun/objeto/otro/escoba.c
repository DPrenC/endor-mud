/***
Fichero: escoba.c
Autor: kastwey@simauria
Descripción: Una escoba para limpiar las habiaciones
Creación: 03/01/2005.
Reescribo totalmente la escoba anterior, evito call_outs y tonterías
y la pongo que lo quite todo de una vez.
Ahora es algo así como mágica...
***/

#include <moving.h>

inherit THING;

int eliminar(object cosa);
string *cosas;
string *mensajes = ({});
mapping objetos = ([]);

create()
{
    ::create();
    SetShort("una escoba");
    SetLong("Es una escoba.\n"
            "Sirve para barrer los objetos no vivos y que se puedan coger, "
            "que no pertenezcan por defecto a la habitación en la que te "
            "encuentres. "
            "Para barrer, escribe barrer.\n");
    AddId("escoba");
    SetValue(100);
    SetWeight(300);
}

init()
{
	::init();
	add_action("cmd_barrer","barrer");
}

int cmd_barrer()
{
	object *inventario, *contenido;
	int i, j;
	object pl;
	string descripcion, *indices;
	if (!(pl = TP)) return 0;
	if (!present(TO,TP)) return 0;
	inventario = all_inventory(environment(pl));
	inventario = filter(inventario,SF(eliminar));
	for (i=sizeof(inventario);i--;)
	{
	  	contenido = deep_inventory(inventario[i]);
	  	for (j=sizeof(contenido);j--;)
	  	{
            descripcion = contenido[j]->QueryShort() || contenido[j]->QueryName() || "algo";
	  	    contenido[j]->remove();
	  	    if (contenido[j]) destruct(contenido[j]);
	  	    if (!contenido[j]) objetos[descripcion]++;
 	    }
    	descripcion = inventario[i]->QueryShort() || inventario[i]->QueryName() || "algo";
    	inventario[i]->remove();
	  	if (inventario[i]) destruct(inventario[i]);
	  	if (!inventario[i]) objetos[descripcion]++;
	}
	if (sizeof((indices = m_indices(objetos))))
	{
  	  	for (i=sizeof(indices);i--;)
  	  	{
  	  		if (objetos[indices[i]] > 1) mensajes+=({indices[i] + " [" + objetos[indices[i]] + "]"});
  	  		else mensajes+=({indices[i]});
  	  	}
  	  	write("Sueltas la escoba.\n");
  	  	say(CAP(NNAME(pl)) + " suelta la escoba.\n",pl);
  	  	tell_room(ENV(pl),"Al instante, se pone a girar sobre sí misma, mientras se ilumina intensamente.\n"
	                      "Notas cómo un extraño viento comienza a surgir de ella, "
	                      "arremolinando a su alrededor todos los objetos que hay "
	                      "tirados.\nLa escoba se eleva del suelo, mientras el "
	                      "viento se hace más intenso, absorbiendo todos los objetos.\n" +
	                      implode(mensajes[0..<2],", ")+(sizeof(mensajes[0..<2])?" y ":"")+mensajes[<1] + " " + (sizeof(mensajes) > 1?"han":"ha") + " sido destruido" + (sizeof(mensajes) > 1?"s":"") + ".\n");
	    objetos = ([]);
	    mensajes = ({});
	}
	else
	{
	write("Sueltas la escoba, pero no hace nada, así que la vuelves a coger.\n");
    say(CAP(NNAME(pl)) + " suelta la escoba, y al darse cuenta de que no hace "
        "nada, la vuelve a coger.\n",TP);
	}
    return 1;
}

int eliminar(object cosa)
{
    if (   !cosa->QueryClassIds() || living(cosa) || cosa->QueryNoTake()
        || cosa->QueryNoDrop() || cosa->QueryCreator() == object_name(ENV(TP)))
    {
        return 0;
    }
    return 1;
}
