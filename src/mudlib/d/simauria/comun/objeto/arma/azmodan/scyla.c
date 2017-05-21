/*****************************************************/
//
//	"scyla"
//
//	La m�tica espada scyla!
//
//	est� maldita, por lo tanto tiene WC 2 y no se
//	puede desempu�ar. Si se le quita la maldici�n
//	tiene WC 12.
//
//	Hace un 50% m�s de da�o a los orcos[13-02-02]
//	le cambio la descripci�n a algo mejor.
//	restricci�n: S�lo se puede llevar una
//
//	14-12-01: Kodex -> Creaci�n
//	13-02-02: Kodex -> Modificaci�n
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
    ", ha perdido casi todo su filo y est� marcada con extra�os "
    "s�mbolos de color rojo intenso. Tiene unas piedras negras en "
    "la hoja y est� bastante sucia. Hay algo de esa espada que "
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
		tell_object(wielder, "La espada est� maldita!.\n");
		tell_room(environment(wielder),capitalize(wielder->QueryRealName()) + " mira su espada con una expresi�n de p�nico.\n",({wielder}));
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
	SetLong("Se trata de una magn�fica espada de hoja larga, cuyo acero tiene un "
	"ligero tono rojizo muy peculiar.\n La empu�adura, parece hecha de bronce muy "
	"trabajado, con un magn�fico rub� que forma el pomo. Entremezcl�ndose con los "
	"bajorrelieves de la empu�adura y los retorcidos gabilanes curvados hacia la "
	"hoja hay grabadas  unas sinuosas inscripciones de min�sculos caracteres.\n "
	"Surgiendo del centro de la cruz de la espada y extendi�ndose por la parte media "
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
	", ha perdido casi todo su filo y est� marcada con extra�os "
	"s�mbolos de color rojo intenso. Tiene unas piedras negras en "
	"la hoja y est� bastante sucia. Hay algo de esa espada que "
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
           		write("Ning�n mortal podr�a soportar cargar con dos espadas como esta.\n");
           		return ME_NO_ENTER;
           	}
	return ::move(dest,method,stuff);
	}
//50% de da�o adicional a los orcos
int CalcDamage(object enemy)
{
	int damage;
	damage = ::CalcDamage(enemy);
	if (enemy && (enemy->QueryRace()=="orco") && !(QueryMaldita()))
	tell_room(environment(enemy),
                       TC_RED+"�"+TC_BOLD+"�"+TC_YELLOW+"�"+TC_NORMAL+TC_YELLOW+
                       "scyla desprende llamas abrasando a "+(enemy->QueryName())+
                       TC_BOLD+"!"+TC_RED+"!"+TC_NORMAL+TC_RED+"!\n"+TC_NORMAL);
	damage += damage/2;
	return damage;
}