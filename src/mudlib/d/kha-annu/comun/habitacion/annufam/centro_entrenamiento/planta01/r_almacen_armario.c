/****************************************************************************
Fichero: r_almacen.c
Autor: Riberales
Fecha: 21/02/2006
Descripción: almacén del centro.
[t] 2009/03/04: Añadido un armario, pero mejor hacerlo objeto como en /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/habitacion01.c
****************************************************************************/



#include "path.h"
#include <moving.h>

inherit HAB_PRIMERA_ANNUFAM("r_base");

static int armario_abierto = 0;
static int armario_hacha = 1;
static int armario_mangual = 1;

int cmd_abrir_cerrar(string str);
int cmd_coger(string str);
int cmd_mirar(string str);
void coger_hacha(int only_this);
void coger_mangual(int only_this);

create()
{
    ::create();

    tipo_arma = ({"arma","armas"});

    SetIntShort("el almacén de armas");
    SetIntLong("Has entrado en lo que tiene toda la pinta de ser un almacén "
               "de armas. Aquí es donde los reclutas guardan su equipamiento "
               "después de su jornada de entrenamiento. De hecho ves alguna "
               "que otra arma colgada y también grandes armarios apoyados en "
               "las paredes.\n");

    AddDetail(({"armario","armarios"}),
                "Son unos armarios en los que sospechas que se guardan las "
                "mejores armas del Centro. Parece que están fabricados con "
                "madera de muy buena calidad, así es que no será fácil "
                "abrirlos a las bravas.\n");

    AddDetail(({"pared","paredes"}),
                "Ves colgadas varias de las armas que utilizan los enanos "
                "para entrenarse en el Centro, y también algunos armarios que "
                "parecen destinados a guardar parte del equipo de los "
                "guerreros.\n");


    AddDetail(({"arma","armas","armadura","armaduras"}),
                "Son las armas y armaduras que se utilizan para entrenar. "
                "Algunas están en buen estado, y otras están aquí para "
                "ser reparadas en la herrería de Annufam.\n");

    AddVentanaN();

    AddRoomCmd("abrir", "cmd_abrir_cerrar");
    AddRoomCmd("cerrar", "cmd_abrir_cerrar");
	AddRoomCmd("mirar", "cmd_mirar");
	AddRoomCmd("m", "cmd_mirar");

    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo02"));
}

reset()
{
	::reset();
	armario_abierto=0;
	armario_hacha=1;
	armario_mangual=1;
}

/*
Ampliado con info de:
/d/kha-annu/comun/habitacion/annufam/ciudad/posada/pasillo_piso1.c
/d/limbo/comun/habitacion/limbo/limbo/barca00.c
*/
int cmd_abrir_cerrar(string str)
{
    object guardian;
	string contenido, verb = query_verb();
	int accion = (verb == "abrir");

    if (!str || str != "armario") return 0;

    if ((guardian = present("tripanain")) && living(guardian))
    {
        write("Tripanain te grita: ¡Pero bueno! ¿Qué pretendes hacer " + (accion?"abriendo":"cerrando") + " "
              "ese armario?\n");
        say("Tripanain le grita a "+ CAP(TNAME)+ ".\n");
        guardian->Kill(TP);
        return 1;
    }

	if (armario_abierto && accion)
		return notify_fail("El armario ya está abierto.\n", NOTIFY_NOT_VALID);
	if (!armario_abierto && !accion)
		return notify_fail("El armario ya está cerrado.\n", NOTIFY_NOT_VALID);
    if (!present("llave_almacen_annufam",TP) && accion)
    // no tiene la llave, y la acción es abrir
    {
        return notify_fail("Intentas abrir el armario, pero sin la llave te va a ser imposible.\n", NOTIFY_NOT_VALID);
    }
    else if (!accion)
    // cerrar
    {
        write("Cierras el armario.\n");
        say(CAP(TNAME) + " cierra el armario.\n");
		armario_abierto = 0;
        return 1;
    }
	// Llegado a este pusnto sólo se puede abrir
	if (armario_hacha || armario_mangual)
	{
		contenido = "En el interior del armario hay un ";
		if (armario_hacha)
		{
			contenido += "hacha de las que los enanos utilizan para entrenarse";
			if (armario_mangual)
				contenido += " y un mangual";
		}
		else
			contenido += "mangual";
		contenido += ".\n";
	}
	write ("Abres el armario con la llave que le has quitado a Tripanain.\n" + contenido);
	say (CAP(TNAME) + " introduce una llave en la cerradura del armario y lo abre.\n" + contenido, TP);
	armario_abierto = 1;

    return 1;
}

int cmd_mirar(string str)
{
	string contenido;

	if (!str) return 0;
	if ((LOWER(str) != "dentro del armario") && (LOWER(str) != "dentro de armario") && (LOWER(str) != "interior del armario") && (LOWER(str) != "interior del armario") && (LOWER(str) != "todo del armario") && (LOWER(str) != "todo de armario"))
		return 0;
	if (!armario_abierto)
	{
		write ("El armario está cerrado.\n");
		return 1;
	}
	if (armario_hacha || armario_mangual)
	{
		contenido = "En el interior del armario hay un ";
		if (armario_hacha)
		{
			contenido += "hacha de las que los enanos utilizan para entrenarse";
			if (armario_mangual)
				contenido += " y un mangual";
		}
		else
			contenido += "mangual";
		contenido += ".\n";
	}
	else
		contenido = "El armario está vacío.\n";
	write (contenido);
	return 1;
}

void coger_hacha(int only_this)
{
	object obj;

	if (!armario_hacha)
	{
		if (only_this)
			write ("Sopla!!! Parece que alguien ya la ha cogido.\n");
		return;
	}
	obj = clone_object(ARMA_CENTRO_ANNUFAM("hacha_guerreros"));
	if (obj->move(TP, M_SILENT) != ME_OK)
	{
		write("Vaya, parece que vas muy cargad"+AO+" y no puedes coger el hacha.\n");
		return;
	}
	write ("Coges el hacha del armario.\n");
	say (CAP(TNAME)+" coge el hacha del armario.\n");
	armario_hacha=0;
}

void coger_mangual(int only_this)
{
	object obj;

	if (!armario_mangual)
	{
		if (only_this)
			write ("Sopla!!! Parece que alguien ya lo ha cogido.\n");
		return;
	}
	obj = clone_object(ARMA_CENTRO_ANNUFAM("mangual"));
	if (obj->move(TP, M_SILENT) != ME_OK)
	{
		write("Vaya, parece que vas muy cargad"+AO+" y no puedes coger el mangual.\n");
		return;
	}
	write ("Coges el mangual del armario.\n");
	say (CAP(TNAME)+" coge el mangual del armario.\n");
	armario_mangual=0;
}

int cmd_coger(string str)
{
	string cosa;

	if (!str) return 0;
	if ((sscanf(LOWER(str),"%s del armario", cosa)==1) || (sscanf(LOWER(str),"%s de armario", cosa)==1))
	{
		if (!armario_abierto)
		{
			write ("El armario está cerrado.\n");
			return 1;
		}
		if (("hacha"!=cosa) && ("mangual"!=cosa) && ("todo"!=cosa))
		{
			write("En el armario no hay nada parecido a "+cosa+".\n");
			return 1;
		}
		if ("hacha" == cosa)
		{
			coger_hacha(1);
			return 1;
		}
		if ("mangual" == cosa)
		{
			coger_mangual(1);
			return 1;
		}
		if ("todo" == cosa)
		{
			coger_hacha(0);
			coger_mangual(0);
			return 1;
		}
	}
	else
		return 0;
}
