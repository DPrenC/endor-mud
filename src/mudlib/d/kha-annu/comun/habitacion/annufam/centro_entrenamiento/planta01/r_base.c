/****************************************************************************
Fichero: r_base
Autor: Riberales
		[T] Tagoras
Fecha: 21/02/2006
Descripción: Base de las rooms de entrene de la planta baja del CAGE.
[T] 28/03/2009: Se puede entrenar en el CAGE. Sólo si se tienes las placas de recluta.
****************************************************************************/


#include "path.h"
#include <nightday.h>
#include <properties.h>

inherit BASE_ANNUFAM;

#define BONUS_MASTER	100			// El bonus de entreno que da el maestro.
#define ENTRENOS		30			// Cada entreno hace estos UseSkill
//#define AO				(TP->QueryGender()==GENERO_FEMENINO?"a":"o");

string QueryWeapon();
string olor();
int cmd_coger(string str);
int cmd_entrenar(string str);
int do_train(string skill);
string *tipo_arma;



/*public void allow_enter(mixed from,int method,mixed extra)
{
    if (method == M_SPECIAL)
    {
        return PO->move(HAB_PRIMERA_ANNUFAM("pasillo05"),M_SILENT);
    }
    else if (method == M_GO
*/

create()
{
    ::create();
    AddDetail(({"antorchas","antorcha"}),
                "Es una antorcha que durante las horas de falta de luz sirve "
                "para alumbrar el centro. No tiene ninguna característica en "
               "especial.\n");
    AddDetail(({"enseña","ensenya"}),
                "Se trata de la enseña del dominio de Kha-annu. En su parte "
                "superior hay una corona de oro con cinco diamantes, que "
                "representan las cinco ciudades del dominio enano, y en la "
                "parte inferior un escudo con borde plateado y de fondo verde "
                "sobre el que hay un león rampante que muestra sus fauces "
                "desafiante, y que se encuentra flanqueado por dos hachas "
                "enanas de empuñadura marrón.\n");
    AddDetail("suelo",
              "El suelo de esta sala es más o menos como el del resto del "
              "edificio: de baldosas de piedra verdes y marrones... pero con "
              "alguna salpicadura de sangre, muy probablemente, provocada "
              "por la dureza del entrenamiento.\n");
    AddDetail("techo","Es un techo abovedado y muy austero.\n");

    SetIndoors(1);
    SetIntBright(45);
    SetIntSmell(olor());
    AddRoomCmd("coger", "cmd_coger");
    AddRoomCmd("entrenar", "cmd_entrenar");
}

public void AddParedes()
{
    AddDetail(({"pared","paredes"}),
                "Son paredes de ladrillo sin más decoración que una enseña "
                "del dominio de Kha-annu. En ellas hay estanterías y soportes "
                "con armas y también alguna antorcha para iluminar durante "
                "las horas de falta de luz. En una de las paredes puedes ver "
                "una ventana.\n");

    AddDetail(({"estanteria","estantería","estanterias","estanterías"}),
                "Son estanterías de madera donde observas algunas armas.\n");

    return ;
}

string olor()
{
    if (random(100) < 50)
    {
        return "No te podías imaginar que el olor del sudor enano pudiera llegar a doler.\n";
    }
    return "El olor de la sangre y el sudor te impregna y te aturde.\n";
}

void AddVentanaN()
{
    return AddDetail("ventana",
              "A través de la ventana puedes ver parte de la Arena donde los "
              "enanos de Annufam practican el arte de la guerra.\n");
}

void AddVentanaS()
{
    AddDetail("ventana",
              "A través de la ventana ves parte de la ciudad de Annufam y "
              "algunos enanos paseando.\n");

    return ;
}

string QueryWeapon()
{
	return tipo_arma[0];
}

int cmd_coger(string str)
{
    if (str == "todo")
    {
        write("Las armas de la estantería mejor no las cojas.\n");
        return 0;
    }

    if (!str || member(({"arma", "armas"}) + tipo_arma, str) <0) return 0;

    if (present(tipo_arma[0])) return 0;

    write("Mejor que no cojas esas armas, parece que las tienen muy controladas.\n");
    return 1;
}

int cmd_entrenar(string str)
{
	mapping m_skills = ([
		"vara":"pelea con varas",
		"daga":"pelea con daga",
		"lanza":"pelea con lanza",
		"alabarda":"pelea con alabarda",
		"hacha":"pelea con hacha",
		"cadena":"pelea con cadena",
		"latigo":"pelea con latigos",
		"mangual":"lucha con mangual",
		"florete":"esgrima",
		"espada":"lucha con espada",
		"manopla":"pelea con manopla",
		"ninguna":"artes marciales",
		"escudo":"bloqueo con escudo",
		"maza":"pelea con maza"
	]);
	string weapon = QueryWeapon();
	string skill;
	int wields;
	int i;
	object maestro;

	skill = m_entry(m_skills, weapon)[0];
	maestro = present("maestro");
	if (!maestro || !living(maestro))
		return notify_fail("¿Cómo quieres entrenar si no hay ningún maestro en la sala para enseñarte?\n", NOTIFY_NOT_OBJ);
	if (maestro->Fighting())
		return notify_fail("El maestro te dice: 'Ahora estoy un pelín ocupado. Vuelve más tarde'\n", NOTIFY_NOT_VALID);
	if (!present("placas_cage", TP))
		return notify_fail("El maestro te dice: 'Yo sólo entreno a reclutas.'\n", NOTIFY_NOT_OBJ);
	
	if (present("placas_cage", TP)->QueryOwnerName() != TP->QueryRealName())
	{
		say ("El maestro increpa a "+CAP(TNAME)+" y comienza enojarse mucho.\n", TP);
		maestro->Kill(TP);
		return notify_fail("El maestro dice: 'Serás mentiros"+AO+". ¿Intentar engañarme?. Ahora verás...'\n", NOTIFY_NOT_VALID);
	}

	if (!TP->HasSkill(skill))
		return notify_fail("El maestro te dice: ¿Cómo quieres entrenar una habilidad que aún no has aprendido?\n", NOTIFY_NOT_VALID);

	if (("ninguna" == weapon) && (({}) != (TP->QueryWeapons() - ({ 0 }))))
		return notify_fail("El maestro te dice: 'Si quieres entrenar artes marciales primero habrás de desempuñar cualquier arma que lleves.'\n", NOTIFY_NOT_VALID);

	if (("ninguna" != weapon))
	{
		mixed * wielded;
		object w_weapon;

		wields = 0;
		if (("escudo" != weapon))
			wielded = TP->QueryWeapons();
		else
			wielded = TP->QueryArmours();
		if (sizeof(wielded) && sizeof(wielded -= ({ 0 })))
		{
			for (i=0; i<sizeof(wielded); i++)
			{
				w_weapon = wielded[i];
				if (!objectp(w_weapon)) continue;
				if (-1 < member(w_weapon->QueryIds(), weapon)) 
					wields = 1;
			}
		}

		if (!wields)
			return notify_fail("El maestro te dice: 'Si quieres entrenar tendrás que llevar puesto el equipo apropiado.'\n", NOTIFY_NOT_OBJ);
	}

	if (find_call_out("do_train") != -1)
	{
		remove_call_out("do_train");
		write("Pero si ya estabas entrenando!!! Con la distracción tendrás que volver a empezar.\n");
	}
	write ("Comienzas a entrenar '"+skill+"' duro, muy duro.\n");
	call_out("do_train", 2+random(3), skill);
	
	return 1;
}

int do_train(string skill)
{
	int i;
	for (i=0; i<ENTRENOS; i++)
		TP->UseSkill(skill, BONUS_MASTER);
	write ("Paras de entrenar '"+skill+"' para recuperar el aliento.\n");
	return 1;
}

/*
    Ponemos el arma que toca en la room.
*/
public void AddWeapon()
{
    string weapon;

    weapon = QueryWeapon();
    if (weapon)
    {
        if ("ninguna" == weapon)
            return;
        if ("arma" == weapon)
            return;
        if ("escudo" == weapon)
        {
            AddItem(PROT_CENTRO_ANNUFAM("escudo"), REFRESH_REMOVE, 4+random(3));
            return;
        }
        if ("espada" == weapon)
        {
            AddItem(ARMA_CENTRO_ANNUFAM("espada"), REFRESH_REMOVE, 2+random(2));
            AddItem(ARMA_CENTRO_ANNUFAM("sable"), REFRESH_REMOVE, 2+random(2));
            return;
        }
        if ("hacha" == weapon)
        {
            AddItem(ARMA_CENTRO_ANNUFAM("hacha_guerreros"), REFRESH_REMOVE, 4+random(3));
            return;
        }
        AddItem(ARMA_CENTRO_ANNUFAM(weapon), REFRESH_REMOVE, 4+random(3));
    }
}
