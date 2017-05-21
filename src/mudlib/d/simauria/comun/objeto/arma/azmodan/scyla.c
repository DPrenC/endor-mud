/*****************************************************/
//
//	"scyla"
//
//	La mítica espada scyla!
//
//	está maldita, por lo tanto tiene WC 2 y no se
//	puede desempuñar. Si se le quita la maldición
//	tiene WC 12.
//
//	Hace un 50% más de daño a los orcos[13-02-02]
//	le cambio la descripción a algo mejor.
//	restricción: Sólo se puede llevar una
//
//	14-12-01: Kodex -> Creación
//	13-02-02: Kodex -> Modificación
//
/******************************************************/
inherit WEAPON;

#include <combat.h>
#include <properties.h>
#include <moving.h>
#include <colours.h>
#include "../path.h"

int maldita = 1;

public SetMaldita(int maldicion);
public QueryMaldita();


create()
{
::create();

SetStandard(WT_ESPADA,12,P_SIZE_MEDIUM,M_MITHRIL);

SetShort("la espada 'scyla'");
    SetLong("Es una espada con una hoja larga muy deteriorada"
    ", ha perdido casi todo su filo y está marcada con extraños "
    "símbolos de color rojo intenso. Tiene unas piedras negras en "
    "la hoja y está bastante sucia. Hay algo de esa espada que "
    " atrae con intensidad.\n");
    SetIds(({"arma","espada","scyla"}));
    SetMagic(1);
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(1);
    if (maldita == 1) SetWC(2);
}


public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
  if (maldita)
  {
    tell_object(wielder,"Tienes un mal presentimiento...\n");
  }
  return ::ChkEquip(wielder, weapon, flags);
}

public varargs mixed ChkUnequip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
	if (maldita)
	{
		tell_object(wielder, "La espada está maldita!.\n");
		tell_room(environment(wielder),capitalize(wielder->QueryRealName()) + " mira su espada con una expresión de pánico.\n",({wielder}));
		return EQ_FORBID;
	}
	return ::ChkUnequip(wielder, weapon, flags);
}

QueryMaldita()
{
	return(maldita);
}

SetMaldita(int maldicion)
{
	if (!maldicion)
	{
	tell_room(environment(TP),
	"La espada 'scyla' se ilumina de repente.\n");
	SetLong("Se trata de una magnífica espada de hoja larga, cuyo acero tiene un "
	"ligero tono rojizo muy peculiar.\n La empuñadura, parece hecha de bronce muy "
	"trabajado, con un magnífico rubí que forma el pomo. Entremezclándose con los "
	"bajorrelieves de la empuñadura y los retorcidos gabilanes curvados hacia la "
	"hoja hay grabadas  unas sinuosas inscripciones de minúsculos caracteres.\n "
	"Surgiendo del centro de la cruz de la espada y extendiéndose por la parte media "
	"de la hoja hasta tres tercios de la misma, hay cincelado un elaborado haz de "
	"llamas, que parece arder intermitentemente con un fuego interior, ascendiendo por "
	"la hoja para disgregarse en los filos y la punta de la espada.\n");
	SetWC(12);
	}
	else
	{
	tell_room(environment(TP),
	"La espada 'scyla' pierde su brillo y se deteriora.\n");
	SetLong("Es una espada con una hoja larga muy deteriorada"
	", ha perdido casi todo su filo y está marcada con extraños "
	"símbolos de color rojo intenso. Tiene unas piedras negras en "
	"la hoja y está bastante sucia. Hay algo de esa espada que "
	" atrae con intensidad.\n");
	SetWC(12);
	}
	maldita = maldicion;
	return maldita;
}

move(dest,method,stuff)
	{
		//solo se puede llevar una
		if (present("scyla",dest))
           	{
           		write("Ningún mortal podría soportar cargar con dos espadas como esta.\n");
           		return ME_NO_ENTER;
           	}
	return ::move(dest,method,stuff);
	}
//50% de daño adicional a los orcos
int CalcDamage(object enemy)
{
	int damage;
	damage = ::CalcDamage(enemy);
	if (enemy && (enemy->QueryRace()=="orco") && !(QueryMaldita()))
	tell_room(environment(enemy),
                       TC_RED+"¡"+TC_BOLD+"¡"+TC_YELLOW+"¡"+TC_NORMAL+TC_YELLOW+
                       "scyla desprende llamas abrasando a "+(enemy->QueryName())+
                       TC_BOLD+"!"+TC_RED+"!"+TC_NORMAL+TC_RED+"!\n"+TC_NORMAL);
	damage += damage/2;
	return damage;
}