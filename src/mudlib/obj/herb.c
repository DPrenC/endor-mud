/* SIMAURIA '/obj/herb.c'
   ======================

   Pensar en fusionarlo con la comida normal.

   Clases de las hierbas implementados (definidos en herb.h):

   HERB_CLASS_NORMAL   : No hace nada
   HERB_CLASS_HEALING  : Da puntos de golpe (HP)
   HERB_CLASS_MAGIC    : Da puntos de magia (SP)
   HERB_CLASS_POISONOUS: Quita puntos de vida (HP)
   HERB_CLASS_NARCOTIC : Droga (el player no puede hacer nada por un tiempo)
   HERB_QUENCH   : Comida (quita parte del hambre)
   HERB_CLASS_TOXIC    : Emborracha
   HERB_CLASS_UNKNOWN  : Ni idea de q hace XD

   SetClass es para especificar el efecto que causa
   SetType es para especificar el tipo de 'hierba', es un string descriptivo
           y se le pueden poner cosas como "baya", "seta", "fruto", "hierba"...
*/

#include <properties.h>
#include <commands.h>
#include <herbs.h>

//------------------------------------------------------------------------------

inherit THING;

//------------------------------------------------------------------------------

private string pClass, pType;
public int pPower;

//------------------------------------------------------------------------------

public int QueryIsHerb() { return 1; }

//------------------------------------------------------------------------------

public string QueryType() { return pType; }
public string SetType(string str)
{
  if (pType) RemoveId(pType);
  pType = str;
  AddId(pType);
  return QueryType();
}

public string QueryClass() { return pClass; }
public string SetClass(string str)
{
  if (member(HERB_ALL, str) < 0) str = HERB_CLASS_UNKNOWN;
  if (pClass) RemoveId(pClass);
  pClass = str;
  AddId(pClass);
  return QueryClass();
}

public string QueryPowerString()
{
    switch (pPower)
    {
                case 0..20:    return "muy suave";
        case 21..70:   return "suave";
        case 71..110:  return "moderado";
        case 111..140: return "intenso";
        case 141..170: return "potente";
        case 171..200: return "excesivo";
        default:       return "de una intensidad no reconocible";
    }
    return "demasiado fuerte";
}

public int QueryPowerNumber()
{
    if (!pPower || !intp(pPower)) return pPower = 0;
    return pPower;
}

public int QueryPower() {
  return QueryPowerNumber();
}

public int SetPower(int i)
{
    if(!i || !intp(i)) return pPower = 0;
    if(i <   0) i = 0;
    if(i > 200) i = 200;
    pPower = i;
    return QueryPower();
}

//------------------------------------------------------------------------------

// Sobreescrita
public int QueryValue()
{
  int min_value, weight;

  weight = QueryWeight();

  switch (pClass)
  {
    case HERB_CLASS_HEALING:
    case HERB_CLASS_MAGIC:
      min_value = pPower * pPower / 7 - weight / 100;
      break;
    default:
      min_value = pPower * 2 - weight /100;
  }

  if (::QueryValue() < min_value) SetValue(min_value);

  return ::QueryValue();
}

//------------------------------------------------------------------------------

public int f_efectos()
{
    write("La cabeza te da vueltas. Estás demasiado agotad" + TP->QueryGenderEndString()
          + " como para hacer nada ahora.\n");
    say(CAP(TNAME) + " trata de hacer algo, pero narcotizad" + TP->QueryGenderEndString()
        + " como está, falla.\n", TP);
    return 1;
}

public int f_poison()
{
    write("¡Ohhhh! ¡Argh! ¡Te arde la garganta! Tu estómago comienza a hervir.\n");
    say("¡Argh!. " + CAP(TNAME) + " se retuerce de dolor.\n", TP);
    TP->Defend(pPower);
    return remove();
}

public int f_heal()
{
    int life_heal;

    write("El sabor es bastante agradable. Notas cómo tu cuerpo se recupera.\n");
    life_heal = pPower/3;
    if(life_heal > 25) life_heal = 25;
    TP->HealHP(life_heal);
    return remove();
}

public int f_narcot()
{
    write("Notas cómo se te embota la cabeza y se te nubla la vista ...\n");
    say(CAP(TNAME) + " se tambalea. Parece narcotizad" + TP->QueryGenderEndString()
        + ".\n", TP);
    add_action("f_efectos", "", AA_NOSPACE);
    call_out("f_awake", pPower);
    return 1;
}

public int f_satiate()
{
    write("Te sientes menos hambrient" + TP->QueryGenderEndString() + ".\n");
    TP->AddFood(pPower);
    return remove();
}

public int f_magic()
{
    int mana_heal;
    write("¡Sientes cómo unos extraños poderes fluyen a traves de tu cuerpo!\n");
    mana_heal = pPower / 3;
    if(mana_heal > 25)
    {
        mana_heal = 25;
    }
    TP->HealSP(mana_heal);
    return remove();
}

public int f_intox()
{
    write("¡Te sientes muy feliz y todo comienza a dar vueltas!\n");
    TP->AddAlcohol(pPower);
    return remove();
}

public int f_awake()
{
    write("Poco a poco vuelves en ti, aunque te queda un buen dolor de cabeza.\n");
    say(CAP(TNAME) + " parece ya recuperad" + TP->QueryGenderEndString() + ".\n", TP);
    TP->SetTP(0);
    return remove();
}

public int cmd_comer(string str)
{
  object herb;

  if (!str) return 0;

  herb = present(str, TP);

  if (!herb) notify_fail("No tienes "+str+".\n");

  if (herb != TO) return 0; // Si no soy yo paso

  say(CAP(TNAME) + " se come " + QueryShort() + ".\n", TP);
  write("Te comes "+QueryShort() + ".\n");

  switch(QueryClass())
    {
        case HERB_CLASS_POISONOUS: f_poison();  break;
        case HERB_CLASS_HEALING  : f_heal();    break;
        case HERB_CLASS_MAGIC    : f_magic();   break;
        case HERB_CLASS_TOXIC    : f_intox();   break;
        case HERB_CLASS_NARCOTIC : f_narcot();  break;
        case HERB_CLASS_FOOD     : f_satiate(); break;
        default: write("No tiene mal sabor, pero tampoco te llena el estómago.\n"); remove();
    }

    if (TO) destruct (TO);

    return 1;
}

//------------------------------------------------------------------------------

init()
{
    ::init();
    add_action("cmd_comer", "comer");
}

//------------------------------------------------------------------------------

create()
{
    ::create();
    SetShort("una hierba");
    SetLong("Parece una hierba normal.\n");
    AddId(HERB_ID);

    SetWeight(25);
    SetSize(P_SIZE_SMALL);

    SetClass(HERB_CLASS_NORMAL);
    SetType(HERB_TYPE_HERB);

    pPower = 20;
}

//------------------------------------------------------------------------------
