/****************************************************************************
Fichero: espada_noble.c
Autor: Ratwor
Fecha: 07/12/2007
Descripci�n: El arma del se�or del castillo de Nandor.
        Solo la pueden empu�ar amigos de la familia del noble de Nandor: elfos, humanos 
        y medio elfos, pero de m�s de nivel 45.
         Si la empu�an humanos y el enemigo es de alguna de las razas enemigas de su 
         familia tiene un tercio m�s de da�o.
****************************************************************************/

#include <properties.h>
#include <combat.h>
#include <colours.h>
#include <skills.h>
#define MIN_LEVEL 50
inherit WEAPON;
public string f_leer_runas();
create()
{
    ::create();
    SetStandard(WT_ESPADA, 14, P_SIZE_LARGE, M_ACERO);
    SetShort("Morlang, la gran espada de C�nor");
    SetLong("�sta gran espada es la posesi�n mas apreciada de la l�nea Dhes-Bl�in, y a "
    "sido heredada generaci�n tras generaci�n por sus primog�nitos remont�ndose al mismo "
    "C�nor, unos doscientos a�os atr�s cuando el se�or�o de Nandor fue levantado contra "
    "las invasiones procedentes de las monta�as norte�as. Los se�ores de Ihstria "
    "se la obsequiaron a C�nor cuando el guerrero les jur� lealtad, y pronto la hoja de "
    "Morlang fue bautizada con sangre enemiga en cantidades verdaderamente asombrosas.\n"
    "Es una de las pocas armas que quedan en el mundo forjadas seg�n las avanzadas "
    "t�cnicas que los antepasados de los habitantes de Ishtria trajeron de allende el mar.\n"
    "La gran empu�adura guarnecida de plata oscurecida por el tiempo, est� "
    "confeccionada para que pueda empu�arse c�modamente con una o dos manos.\n"
    "El magn�fico pomo dorado aparece tallado en forma de cabeza de le�n, animal cuyas "
    "garras tambi�n adornan los extremos de los amplios gabilanes, pudiendo resultar "
    "�tiles para herir tanto como para detener los filos enemigos. Justo en la cruz "
    "del arma, aparece una flor de lis dorada engarzada en un anillo de un metal "
    "desconocido de color rojizo. La hoja es larga y pesada, de filos rectos bien "
    "afilados, punta poco pronunciada y triangular. En conjunto, resulta una poderosa "
    "espada ideal para propinar poderosos mandobles y tajos, aunque s�lo un guerrero de "
    "gran destreza y fuerza ser� capaz de manejarla a dos manos con velocidad	y soltura, "
    "y se dice que s�lo los herederos leg�timos de C�nor son capaces de manejar a "
    "Morlang con una sola mano.\n Una serie de caracteres extra�os recorren la parte "
    "central de la hoja en una intrincada inscripci�n.\n");
    AddId(({"gran espada", "Morlang", "morlang", "mandoble", "arma"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(9000);
    SetNumberHands(2);
    SetValue(20000);
    SetMagic(1);
    AddSubDetail(({"runas", "inscripci�n", "caracteres", "caracteres extra�os"}),
    "Es una inscripci�n de  caracteres cincelados a bajo relieve que adorna toda la "
    "parte central de la hoja del mandoble.\n");
    AddSubReadMsg(({"runas", "inscripci�n", "caracteres", "caracteres extra�os"}), 
    SF(f_leer_runas));
}

int CalcDamage(object enemy)
{
	  int damage;
	  damage = ::CalcDamage(enemy);
	  if (enemy && TP->QueryRace()=="humano" && TP->QueryStr()>= 45 && 
	    (enemy->QueryRace()=="kainoak" || enemy->QueryRace()=="demonio" || 
	    enemy->QueryRace()=="troll"))
	  tell_room(environment(enemy),
    TC_BLUE+"�Los filos de Morlang emiten un brillo mortecino cuando hieren a "
    +enemy->QueryName()+"!\n"+TC_NORMAL);
    damage += damage/3;
	  return damage;
}


public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
    if (weapon != TO) return EQ_OK;
    if (!wielder->QueryIsPlayer()) return EQ_OK;
    if (wielder->QueryGuildLevel() < MIN_LEVEL)
        return "A�n no eres lo suficientemente renombrado como para empu�ar un arma "
        "tan noble y antigua.\n";
    if (wielder->QueryRace()!="elfo" && wielder->QueryRace()!="humano" && 
      wielder->QueryRace()!="medio-elfo")
    {
    return "Morlang fue forjada por los Se�ores de los Hombres y te das cuenta de que "
    "no es un arma apta para alguien de tu raza.\n";
  }else{
        write("Aferras con ambas manos la gran empu�adura de Morlang, alz�ndola  "
        "y comprobando el magn�fico equilibrio de la antigua hoja.\n");
        say("Con gesto reverente, "+CAP(TNAME)+" empu�a Morlang con ambas manos "
        "alz�ndola en un marcial saludo.\n");

      return ::ChkEquip(wielder, weapon, flags);
    }
}

public string f_leer_runas(){
    int lectura=TP->UseSkill(HAB_RUNAS, 20);
    if ( !(TP->HasSkill(HAB_RUNAS) && TP->SkillIsEnabled(HAB_RUNAS)) ) 
        return "No tienes capacidad para entender el significado de este tipo de "
        "inscripciones.\n";
    if (lectura <= 0)
        return "No consigues identificar los caracteres, eso es muy dif�cil para ti.\n";
    else if (lectura <= 10)
        return "Alzas la espada y le das vueltas intentando dilucidar el origen "
        "de la inscripci�n.\n Finalmente llegas a la conclusi�n de que se trata "
        "de una escritura muy antigua, probablemente de origen ishtrio.\n";
    else if (lectura <= 20)
        return "Reconoces los caracteres como una antigua escritura de origen "
        "ishtrio, pero apenas consigues identificar unas pocas palabras: Ishtros, "
        "hombres, poder y muerte.\n";
    else if (lectura <= 30)
        return "Reconoces la antigua escritura ishtria y tras no pocos esfuerzos "
        "consigues descifrar que se trata de unos versos que bien podr�an hablar "
        "del poder del arma.\n Entiendes algunas palabras sueltas como: Ishtros, "
        "hombres, sangre, manos, aliados, enemigos, poder y muerte.\n";
    else if (lectura <= 40)
        return "Los caracteres son los que utilizaban los antiguos hombres de "
        "Ishtro, casi consigues entender el texto entero, pero m�s o menos deduces "
        "que habla sobre los eternos aliados de los hombres de Ishtro y la muerte "
        "de sus enemigos con manos valerosas...\n";

    return "Los caracteres son los utilizados por los hombres de Ishtros y "
    "dicen en su antigua lengua:\n"+TC_BLUE+"\t Por los Altos Hombres de Ishtros"
    " fui forjada\n\t y  s�lo por ellos y sus eternos aliados ser� empu�ada.\n"
    "\t Con mi poder la sangre de sus enemigos ser� derramada.\n\t Enemigos "
    "de los Hombres temed,\n\t pues pronta ser� vuestra muerte\n\t cuando por "
    "manos valerosas mi hoja sea alzada.\n"+TC_NORMAL;
}
  