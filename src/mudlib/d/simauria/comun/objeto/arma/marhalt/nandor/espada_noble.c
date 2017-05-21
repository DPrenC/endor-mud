/****************************************************************************
Fichero: espada_noble.c
Autor: Ratwor
Fecha: 07/12/2007
Descripción: El arma del señor del castillo de Nandor.
        Solo la pueden empuñar amigos de la familia del noble de Nandor: elfos, humanos 
        y medio elfos, pero de más de nivel 45.
         Si la empuñan humanos y el enemigo es de alguna de las razas enemigas de su 
         familia tiene un tercio más de daño.
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
    SetShort("Morlang, la gran espada de Cónor");
    SetLong("Ésta gran espada es la posesión mas apreciada de la línea Dhes-Bláin, y a "
    "sido heredada generación tras generación por sus primogénitos remontándose al mismo "
    "Cónor, unos doscientos años atrás cuando el señorío de Nandor fue levantado contra "
    "las invasiones procedentes de las montañas norteñas. Los señores de Ihstria "
    "se la obsequiaron a Cónor cuando el guerrero les juró lealtad, y pronto la hoja de "
    "Morlang fue bautizada con sangre enemiga en cantidades verdaderamente asombrosas.\n"
    "Es una de las pocas armas que quedan en el mundo forjadas según las avanzadas "
    "técnicas que los antepasados de los habitantes de Ishtria trajeron de allende el mar.\n"
    "La gran empuñadura guarnecida de plata oscurecida por el tiempo, está "
    "confeccionada para que pueda empuñarse cómodamente con una o dos manos.\n"
    "El magnífico pomo dorado aparece tallado en forma de cabeza de león, animal cuyas "
    "garras también adornan los extremos de los amplios gabilanes, pudiendo resultar "
    "útiles para herir tanto como para detener los filos enemigos. Justo en la cruz "
    "del arma, aparece una flor de lis dorada engarzada en un anillo de un metal "
    "desconocido de color rojizo. La hoja es larga y pesada, de filos rectos bien "
    "afilados, punta poco pronunciada y triangular. En conjunto, resulta una poderosa "
    "espada ideal para propinar poderosos mandobles y tajos, aunque sólo un guerrero de "
    "gran destreza y fuerza será capaz de manejarla a dos manos con velocidad	y soltura, "
    "y se dice que sólo los herederos legítimos de Cónor son capaces de manejar a "
    "Morlang con una sola mano.\n Una serie de caracteres extraños recorren la parte "
    "central de la hoja en una intrincada inscripción.\n");
    AddId(({"gran espada", "Morlang", "morlang", "mandoble", "arma"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(9000);
    SetNumberHands(2);
    SetValue(20000);
    SetMagic(1);
    AddSubDetail(({"runas", "inscripción", "caracteres", "caracteres extraños"}),
    "Es una inscripción de  caracteres cincelados a bajo relieve que adorna toda la "
    "parte central de la hoja del mandoble.\n");
    AddSubReadMsg(({"runas", "inscripción", "caracteres", "caracteres extraños"}), 
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
    TC_BLUE+"¡Los filos de Morlang emiten un brillo mortecino cuando hieren a "
    +enemy->QueryName()+"!\n"+TC_NORMAL);
    damage += damage/3;
	  return damage;
}


public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
    if (weapon != TO) return EQ_OK;
    if (!wielder->QueryIsPlayer()) return EQ_OK;
    if (wielder->QueryGuildLevel() < MIN_LEVEL)
        return "Aún no eres lo suficientemente renombrado como para empuñar un arma "
        "tan noble y antigua.\n";
    if (wielder->QueryRace()!="elfo" && wielder->QueryRace()!="humano" && 
      wielder->QueryRace()!="medio-elfo")
    {
    return "Morlang fue forjada por los Señores de los Hombres y te das cuenta de que "
    "no es un arma apta para alguien de tu raza.\n";
  }else{
        write("Aferras con ambas manos la gran empuñadura de Morlang, alzándola  "
        "y comprobando el magnífico equilibrio de la antigua hoja.\n");
        say("Con gesto reverente, "+CAP(TNAME)+" empuña Morlang con ambas manos "
        "alzándola en un marcial saludo.\n");

      return ::ChkEquip(wielder, weapon, flags);
    }
}

public string f_leer_runas(){
    int lectura=TP->UseSkill(HAB_RUNAS, 20);
    if ( !(TP->HasSkill(HAB_RUNAS) && TP->SkillIsEnabled(HAB_RUNAS)) ) 
        return "No tienes capacidad para entender el significado de este tipo de "
        "inscripciones.\n";
    if (lectura <= 0)
        return "No consigues identificar los caracteres, eso es muy difícil para ti.\n";
    else if (lectura <= 10)
        return "Alzas la espada y le das vueltas intentando dilucidar el origen "
        "de la inscripción.\n Finalmente llegas a la conclusión de que se trata "
        "de una escritura muy antigua, probablemente de origen ishtrio.\n";
    else if (lectura <= 20)
        return "Reconoces los caracteres como una antigua escritura de origen "
        "ishtrio, pero apenas consigues identificar unas pocas palabras: Ishtros, "
        "hombres, poder y muerte.\n";
    else if (lectura <= 30)
        return "Reconoces la antigua escritura ishtria y tras no pocos esfuerzos "
        "consigues descifrar que se trata de unos versos que bien podrían hablar "
        "del poder del arma.\n Entiendes algunas palabras sueltas como: Ishtros, "
        "hombres, sangre, manos, aliados, enemigos, poder y muerte.\n";
    else if (lectura <= 40)
        return "Los caracteres son los que utilizaban los antiguos hombres de "
        "Ishtro, casi consigues entender el texto entero, pero más o menos deduces "
        "que habla sobre los eternos aliados de los hombres de Ishtro y la muerte "
        "de sus enemigos con manos valerosas...\n";

    return "Los caracteres son los utilizados por los hombres de Ishtros y "
    "dicen en su antigua lengua:\n"+TC_BLUE+"\t Por los Altos Hombres de Ishtros"
    " fui forjada\n\t y  sólo por ellos y sus eternos aliados seré empuñada.\n"
    "\t Con mi poder la sangre de sus enemigos será derramada.\n\t Enemigos "
    "de los Hombres temed,\n\t pues pronta será vuestra muerte\n\t cuando por "
    "manos valerosas mi hoja sea alzada.\n"+TC_NORMAL;
}
  