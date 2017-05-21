/** /std/weapon.c V2.1
 *
 * Fichero con toda la funcionalidad de las armas
 *
   orome: 26/08/2014. añadidas multitud de armas para endor-mud y reformadas totalmente las que habían.
 para crear virtualmente armas en el mud:
 clonar weapon.c de /std
 el arma resultante convertirla en la deseada con:
 xcall $m.arma->SetStandard("CsEspadaCorta", 9, 3, "hierro");
 no funcionan defines, así que hay que usar su equivalente buscándolo donde corresponda.
 En los archivos solo heredar de WEAPON y configurar el SetStandard
 SetStandard(WT_ESPADA_CORTA, 9, P_SIZE_LARGE, M_MADERA);
 En este caso sí es obligatorio los defines
 si se quiere propiedades distintas a las de este archivo base entonces modificarlas allí.
 */

#include <classes.h>
#include <combat.h>
#include <config.h>
#include <equipment.h>
#include <living.h>
#include <moving.h>
#include <properties.h>
#include <search.h>

// -----------------------------------------------------------------------------

inherit THING;
inherit "/std/equipment";

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Declaraciones Forward:
public nomask int QueryDamageType();
varargs int QueryWC();

// -----------------------------------------------------------------------------
// Atributos:

private int pWC, pDamType, pWPperQP; // WC, Tipo de Danyo y "dureza"
private string pWeaponType; // Tipo de arma
private nosave int invshort;  // flag para manejar diferentes modificaciones
        // de Short e InvShort

// -----------------------------------------------------------------------------
// Cálculos, Funciones Auxiliares, etc.
// -----------------------------------------------------------------------------

protected int helpcalc(int wc,int size)
{
    int i;
    switch (size)
    {
  case 1:  i=1; break;
  case 2:  i=2; break;
  case 3:  i=3; break;
    case 4:  i=4; break;
  default: i=3;
    }
    return i + ( (wc<1) ? 1 : wc/2);
}

protected int calcvalue(int wc, mixed material) {
 int i;
 switch(material)
  {
  case M_TELA     : i=0; break;
  case M_CUERO    : i=0; break;
  case M_MADERA   : i=30*wc; break;
  case M_HUESO    : i=15*wc; break;
  case M_CRISTAL  : i=10*wc; break;
  case M_PIEDRA   : i=15*wc; break;
  case M_HIERRO   : i=150*wc; break;
  case M_ACERO    : i=175*wc; break;
  case M_COBRE    : i=40*wc; break;
  case M_BRONCE   : i=50*wc; break;
  case M_PLATA    : i=350*wc; break;
  case M_ORO      : i=700*wc; break;
  case M_PLATINO  : i=1000*wc; break;
  case M_DIAMANTE : i=1000*wc; break;
  case M_TITANIO  : i=1500*wc; break;
  case M_ADAMANTIO: i=1700*wc; break;
  case M_MITHRIL  : i=2000*wc; break;
  case M_ALUMINIO : i=2500*wc; break;
  default : i=0; break;
  }
 return i;
}

// Función usada para que nadie se pase con los WC.
protected int calc_wc(mixed type, int wc, mixed mat)
{
 int i;

 if (wc>19) i=19;
 else i=wc;
 switch(type)
 {
    // categoría 1 hasta wc 5
  case WT_CUCHILLO: case WT_DAGA: case WT_LATIGO:
    if (wc >  5) i= 5; break;
  // categoría 2 hasta wc 11
  case WT_ESPADA_CORTA: case WT_PICO: case WT_AZADON: case WT_LANZA    : case WT_JABALINA: case WT_ESGRIMA:
    if (wc > 11) i=11; break;
case WT_MANOPLA: case WT_CADENA: case WT_VARA: case WT_CAYADO: case WT_IMPROVISADA:
    if (wc >  10) i= 10; break;
  //categoría 3 hasta wc 15
  case WT_ESPADA_MEDIANA: case WT_ESPADA_SINDA: case WT_HACHA_KHAZAD: case WT_MARTILLO: case WT_MANGUAL:
    case WT_ESPADA: case WT_HACHA: case WT_ALABARDA : case WT_PICA: case WT_MAZA: case WT_GARROTE: case WT_CIMITARRA:
    if (wc > 15) i=15; break;

 }
 return i;
}

/* int CalcDamage(object enemy)
 *
 * Como argumento, le pasamos el enemigo que estamos atacando. Esto permite
 * usar habilidades especiales del arma contra ciertos tipos (razas) de
 * monstruos.
 * Esta función calcula el daño que el arma haría normalmente al enemigo,
 * sin tener en cuenta ningún hit_ob.
 * Si quieres redefinirla, tienes que escribir tu propio CalcDamage() y
 * llamar ::CalcDamage(enemy) para tener una primera idea del daño causado.
 * Llama a QueryDamage(enemy) para obtener el daño causado realmente.
 */
//muevo la formula al combatmaster
public int CalcDamage (object enemy) {
  return QueryEquipped()?(COMBATMASTER->CalcBaseDamage(QueryWC(),QueryEquipped()->QueryStr()*(1+(QueryNumberHands()>1?QueryNumberHands():1))/2)):0;
}


// -----------------------------------------------------------------------------
// Funciones para manipular Atributos (Set-,Query-,Remove-,Add-,Get-,...)
// -----------------------------------------------------------------------------

// pWPperQP
public int QueryWPperQP ()  { return pWPperQP; }
public int SetWPperQP (int i)  { return pWPperQP = i; }

// pWC
// AsignaWC la usa SetStandard (exclusivamente) para poner el WC.
// De esta manera si alguien usa SetWC, yo me entero, porque los usos
// "a saco" de SetWC se guardan en un log.
// NOTA: De momento, se queda private hasta que TODAS las armas
// de Simauria pasen por SetStandard.
// NOTA2: Tío, eres un pelma. Sencillamente se crea un log y se devuelve
// el WC anterior, mas que nada para que NO PETE, y se GRABE EL LOG (la
// función, si es privada, NO se encuentra). Basta con que NO se modifique
// el pWC.

private int AsignaWC (int w)  { return pWC = w; }

public int SetWC (int w)
{
  log_file("combat/SetWC",sprintf("%O\n",TO));
  return pWC = w;
}

varargs int QueryWC ()    { return pWC; }

// pDamType
// QueryDamageType la llama living/combat. Si tenemos un hit_object, le pedimos
// a él el tipo de daño. Si es 0, usamos nuestro propio pDamType.
public int SetDamType (int type)  { return pDamType = type; }
public int QueryDamType ()    { return pDamType; }
public nomask int QueryDamageType() { return QueryDamType(); }

// pWeaponType (En weapon/combat.c)
string QueryWeaponType()  { return pWeaponType; }
string SetWeaponType(string w)
{
    if (!VALID_WEAPON_TYPE(w))
  return pWeaponType;

    if (pWeaponType)
  RemoveId(pWeaponType[2..]);
    pWeaponType = w;
    switch(pWeaponType){
        case "CsLatigo": AddId(({"látigo", "latigo"})); break;
        case "CsManopla": AddId(({"guantelete", "manopla", "puño"})); SetAds(({"de", "hierro"})); break;
        case "CsEspadaCorta": AddId("espada"); SetAds(({"corta"})); break;
        case "CsCimitarra": AddId(({"espada", "cimitarra"})); break;
        case "CsCayado": AddId(({"baston", "bastón"})); break;
        case "CsJabalina": AddId(({"jabalina", "lanza"})); break;
        case "CsPica": AddId(({"pica", "lanza"})); break;
        case "CsCimitarraPesada": AddId(({"cimitarra", "espada"})); SetAds(({"pesada"})); break;
        case "CsMazaPesada": AddId("maza"); SetAds(({"pesada"})); break;
        case "CsMartilloPesado": AddId("martillo"); SetAds(({"pesado"})); break;
        case "CsHachaPesada": AddId("hacha"); SetAds(({"pesada"})); break;
        case "CsHachaKhazad": AddId("hacha"); SetAds(({"khazad"})); break;
        case "CsMangualPesado": AddId("mangual"); SetAds(({"pesado"})); break;
        case "CsEspadaSinda": AddId("espada"); SetAds(({"sinda"})); break;
            case "CsAzadon": AddId(({"azadon", "azadón"})); break;
            //case "CsImprovisada": AddId("rama"); SetAds(({"improvisada"})); break;
            case "CsEspadaMediana": AddId(({"espada", "montante"})); SetAds(({"bastarda", "mediana", "larga"})); break;
             default:
        AddId(pWeaponType[2..]);
    } // identificadores y adjetivos.

    // tipo de daño asignado
    SetDamType( ([ WT_ESPADA:    DT_SLASH
     , WT_HACHA:     DT_SLASH
     , WT_LATIGO:    TD_LACERACION   //DT_SLASH
     , WT_CUCHILLO:  DT_SLASH
        , WT_DAGA:  DT_PIERCE
     , WT_ESGRIMA:   DT_PIERCE
     , WT_LANZA:     DT_PIERCE
     , WT_ALABARDA:  DT_PIERCE
     , WT_MAZA:      DT_BLUDGEON
     , WT_MANGUAL:   DT_BLUDGEON
     , WT_MANOPLA:   DT_BLUDGEON
     , WT_VARA:      DT_BLUDGEON
     , WT_GARROTE:      DT_BLUDGEON
     , WT_ESPADA_CORTA :   DT_SLASH
     , WT_CIMITARRA :      DT_SLASH
     , WT_MANDOBLE:        DT_SLASH
     , WT_CADENA:    TD_LACERACION   //DT_BLUDGEON
     , WT_CAYADO:    DT_BLUDGEON
     , WT_JABALINA:  DT_PIERCE
     , WT_PICA:      DT_PIERCE
     , WT_CIMITARRA_PESADA: DT_SLASH
     , WT_MAZA_PESADA: DT_BLUDGEON
     , WT_MARTILLO:  DT_BLUDGEON
     , WT_MARTILLO_PESADO: DT_BLUDGEON
     , WT_HACHA_PESADA: DT_SLASH
     , WT_HACHA_KHAZAD: DT_SLASH
     , WT_MANGUAL_PESADO: DT_BLUDGEON
     , WT_ESPADA_SINDA: DT_SLASH
     , WT_PICO:      DT_PIERCE
     , WT_AZADON:    DT_SLASH
        , WT_ESPADA_MEDIANA:    DT_SLASH
            , WT_IMPROVISADA: DT_BLUDGEON
         ])[pWeaponType] );
    return pWeaponType;
}

public varargs int QueryValue()
{
//    if (flag) return (::QueryValue());
    return modifyValue(::QueryValue());
}

/*
 * int QueryDamage(object enemy)
 *
 * Esta función devuelve el daño que hace el arma.
 * Como argumento, le pasamos el enemigo que estamos atacando. Esto
 * permite habilidades especiales del arma contra ciertos tipos (razas)
 * de monstruos. QueryDamage() debería devolver el daño real que el arma
 * quiere hacer (ya aleatorizado y con todos los bonificadores, incluyendo
 * modificadores de calidad).
 *
 * El daño devuelto por QueryDamage() será modificado por la
 * calidad del arma más un desplazamiento de 5 para permitir
 * a las armas de calidad >= 95% hacer daño completo.
 */

int QueryDamage(object enemy) {
  object h_ob;
  int damage, q;

  damage = CalcDamage(enemy) ;

  q = QueryQuality();
  damage = damage * ( q>94 ? 100 : q+5 );
  // Daño completo para calidad >= 95%

  return damage / 100;
}

// SetStandard()-> Usada para crear armas correctas en todos sus valores
varargs int SetStandard (mixed weapon_type, int wc, int size, mixed material)
// weapon_type tambien puede ser un array de la forma:
// ({weapon_type, wc, size})
{
  int wt;

  // extender el array a sus valores (SI weapon_type es un array)
  if (pointerp(weapon_type))
    return apply(SF(SetStandard),weapon_type);

  if (!VALID_WEAPON_TYPE(weapon_type)) return 0;
    // ARMAS, TIPOS VÁLIDOS
  wt = member(({ WT_ESPADA, WT_HACHA, WT_MAZA, WT_LANZA, WT_CUCHILLO,
                  WT_VARA, WT_LATIGO, WT_ALABARDA, WT_CADENA,
                  WT_MANOPLA, WT_ESGRIMA, WT_MANGUAL, WT_DAGA, WT_GARROTE,
                  WT_ESPADA_CORTA, WT_CIMITARRA, WT_MANDOBLE,WT_CAYADO, WT_JABALINA,
                  WT_PICA, WT_CIMITARRA_PESADA, WT_MAZA_PESADA, WT_MARTILLO,
                  WT_MARTILLO_PESADO, WT_HACHA_PESADA, WT_HACHA_KHAZAD,WT_MANGUAL_PESADO,
                  WT_ESPADA_SINDA, WT_PICO, WT_AZADON, WT_ESPADA_MEDIANA, WT_IMPROVISADA }), weapon_type
             );
  SetShort ( ({ "una espada"
              , "un hacha"
              , "una maza"
              , "una lanza"
              , "un cuchillo"
              , "una vara"
              , "un látigo"
              , "una alabarda"
              , "una cadena"
              , "un puño de combate"
              , "un florete"
              , "un mangual"
              , "una daga"
              , "un garrote"
              , "una espada corta"
              , "una cimitarra"
              , "un mandoble"
              , "un cayado"
              , "una jabalina"
              , "una pica"
              , "una enorme cimitarra"
              , "una maza pesada"
, "un martillo de guerra"
, "un martillo pesado"
, "un hacha pesada"
, "un hacha Khazad"
, "un mangual pesado"
, "una estilizada espada sinda"
, "un pico"
, "un azadón de guerra"
, "una espada de mano y media" // espada bastarda
, "una gruesa rama de árbol" // arma improvisada
             })[wt]
           );
  // descripción del arma
  SetLong  ( ({ "Es una espada muy simple, con una hoja de unos noventa centímetros de longitud y doble filo.\n"
              , "Es un hacha de una sola mano con recio mango de madera y una gran hoja de cortante filo.\n"
              , "Es un arma constituída por un mango corto y una cabeza esférica de hierro.\n" //maza simple
              , "Es una lanza de unos dos metros de largo y punta de hierro.\n"
              , "Es un arma de hoja corta, ancha y de un solo filo. Tiene un simple mango de madera.\n" //cuchillo
              , "Una simple vara.\n"
              , "Es un látigo hecho de cuero trenzado y con una pequeña esfera metálica en la punta para darle peso.\n"
              , "Una simple alabarda.\n"
              , "Es una simple cadena de un metro de largo y gruesos eslabones de hierro.\n"
              , "Es un pesado guantelete con gruesos conos metálicos sobresaliendo de la parte superior de los dedos y el dorso, elaborado para asestar tremendos golpes con él.\n" //manopla
              , "Un simple florete.\n"
              , "Es un mango del que cuelga una cadena de hierro a la que va unida una maciza esféra metálica.\n" //mangual
              , "Es un arma de hoja corta, ahusada y de doble filo. La sencilla empuñadura de madera posee sendos gabilanes de hierro.\n" //daga
              , "Es un grueso trozo de madera más ancho por la parte superior, ideal para aporrear cuanto se desee.\n" //garrote
              , "Se trata de una espada de hoja corta, doble filo y aguzada punta, ideal para estocar de cerca. La empuñadura tiene unos sencillos gabilanes de hierro.\n" //espada corta
              , "Es una espada de hoja curva y un solo filo. La empuñadura está envuelta en tiras de cuero.\n" // cimitarra simple
              , "Es una espada a dos manos de hoja pesada y doble filo.\n" // mandoble
             , "Es una vara tallada ideal para apoyarse mientras se camina.\n" // cayado
             , "Es una corta lanza de un metro de largo y punta pesada.\n" // jabalina
             , "Es una enorme lanza de unos cuatro metros de largo y pesada punta de hierro.\n" // pica
             , "Es una pesada cimitarra de enorme hoja curva y un solo filo.\n" // cimitarra pesada
             , "Es una enorme maza a dos manos constituida por un largo mango metálico al que va unido una pesada cabeza esférica de hierro.\n" // maza a dos manos
             , "Es un martillo a una mano con un mango de madera y una cabeza cilíndrica de hierro.\n" // martillo
             , "Es un gran martillo de guerra a dos manos de largo mango metálico y cabeza cilíndrica de hierro.\n" // martillo pesado
             , "Es una gran hacha con mango metálico cubierto de cuero y una enorme y pesada hoja  de filo semicircular.\n" // hacha pesada
             , "Es una típica hacha enana con mango metálico de longitud media que permite aferrarlo a una o dos manos. El arma posee dos grandes y afiladas hojas.\n" // hacha Khazad
             , "Es un gran mangual compuesto de un pesado mango metálico de un metro de largo con una cadena rematada por una gruesa bola de hierro.\n" // mangual pesado
             , "Es una esbelta espada de hoja ligeramente curbada y mango así mismo recurvado pero exenta de guarda.\n" // espada sinda
             , "Se trata de un pico grande constituido por un mango y una larga barra de hierro curva con ambos extremos puntiagudos.\n" // pico
             , "Es un pesado azadón de grueso mango y con una hoja de hierro triangular perpendicular al mango.\n" // azadón
             , "Es una espada bastarda cuya empuñadura permite empuñarla a una o dos manos. La hoja es algo más larga de lo habitual.\n" // espada mediana
             , "Una gruesa rama que algún día perteneció a un árbol.\n" // arma improvisada
             })[wt]
           );
  SetSize(size);
  SetResetQuality(99);
  SetQuality(99);
 // pre-SetMaterial() para forzarlo a ello-olle en caso de que no den material
 // material del arma
if (!material)
 SetMaterial( ({ M_HIERRO  // espada
             , M_HIERRO
       , M_HIERRO
       , M_HIERRO
       , M_HIERRO
       , M_MADERA // vara
       , M_CUERO // látigo
       , M_HIERRO
       , M_HIERRO
       , M_HIERRO // guantelete
       , M_HIERRO
       , M_HIERRO
       , M_HIERRO
       , M_MADERA // garrote
       , M_HIERRO // ESPADA CORTA
       , M_HIERRO // CIMITARRA
       , M_HIERRO // MANDOBLE
       , M_MADERA  // cayado
       , M_HIERRO   // jabalina
       , M_HIERRO  // pica
       , M_HIERRO  // cimitarra pesada
       , M_HIERRO  // maza pesada
       , M_HIERRO  // martillo
       , M_HIERRO  // martillo pesado
       , M_HIERRO  // hacha pesada
       , M_ACERO  // hacha Khazad
       , M_HIERRO   // mangual pesado
       , M_ACERO  // espada sinda
       , M_HIERRO  // pico
       , M_HIERRO   // azadón
       , M_HIERRO // espada mediana
       , M_MADERA  // arma improvisada
      })[wt]
     );

 else SetMaterial(material);
  // peso del arma
  SetWeight ( ({ 350 * helpcalc(wc,size) //WT_ESPADA (MaxWC = 15)
               , 350 * helpcalc(wc,size) // WT_HACHA  (MaxWC = 15)
               , 350 * helpcalc(wc,size) // WT_MAZA   (MaxWC = 15)
               ,  250 * helpcalc(wc,size) //  WT_LANZA  (MaxWC = 11)
               ,  150 * helpcalc(wc,size) //  WT_CUCHILLO (MaxWC = 5)
               ,  250 * helpcalc(wc,size) //  WT_VARA   (MaxWC = 11)
               ,  150 * helpcalc(wc,size) //  WT_LATIGO (MaxWC = 5)
               , 350 * helpcalc(wc,size) // WT_ALABARDA (MaxWC = 15)
               ,  250 * helpcalc(wc,size) //  WT_CADENA  (MaxWC = 11)
               ,  250 * helpcalc(wc,size) //  WT_MANOPLA (MaxWC = 11)
               , 250 * helpcalc(wc,size) // WT_ESGRIMA (MaxWC = 11)
               , 350 * helpcalc(wc,size) // WT_MANGUAL (MaxWC = 15)
               ,  150 * helpcalc(wc,size) //  WT_DAGA (MaxWC = 5)
               ,  350 * helpcalc(wc,size) //  WT_GARROTE   (MaxWC = 15)
               , 250 * helpcalc(wc,size) // WT_ESPADA_CORTA (MaxWC = 11)
               , 350 * helpcalc(wc,size) // WT_CIMITARRA (MaxWC = 15)
               , 450 * helpcalc(wc,size) // WT_MANDOBLE (MaxWC = 19)
               , 250 * helpcalc(wc,size) // WT_CAYADO (MaxWC =11)
               , 250 * helpcalc(wc,size) // WT_JABALINA (MaxWC = 11)
               , 350 * helpcalc(wc,size) // WT_PICA (MaxWC = 15)
               , 450 * helpcalc(wc,size) // WT_CIMITARRA_PESADA (MaxWC = 19)
               , 450 * helpcalc(wc,size) // WT_MAZA_PESADA (MaxWC = 19)
               , 350 * helpcalc(wc,size) // WT_MARTILLO (MaxWC = 15)
               , 450 * helpcalc(wc,size) // WT_MARTILLO_PESADO (MaxWC = 19)
               , 450 * helpcalc(wc,size) // WT_HACHA_PESADA (MaxWC = 19)
               , 350 * helpcalc(wc,size) // WT_HACHA_KHAZAD (MaxWC = 15)
               , 450 * helpcalc(wc,size) // WT_MANGUAL_PESADO (MaxWC = 19)
               , 350 * helpcalc(wc,size) // WT_ESPADA_SINDA (MaxWC = 15)
               , 250 * helpcalc(wc,size) // WT_PICO (MaxWC = 11)
               , 250 * helpcalc(wc,size) // WT_AZADON (MaxWC = 11)
               , 350 * helpcalc(wc,size) // WT_ESPADA_MEDIANA (MaxWC = 15)
               , 250 * helpcalc(wc,size) // WT_IMPROVISADA (MaxWC = 11)
              })[wt]
           );
           // género del arma
  Set(P_GENDER, ({ GENDER_FEMALE, // ESPADA
                   GENDER_FEMALE, // MAZA
                   GENDER_FEMALE, // HACHA
                   GENDER_FEMALE, // LANZA
                   GENDER_MALE,   // CUCHILLO
                   GENDER_FEMALE, // VARA
                   GENDER_MALE,   // LATIGO
                   GENDER_FEMALE, // ALABARDA
                   GENDER_FEMALE, // CADENA
                   GENDER_FEMALE, // MANOPLA
                   GENDER_MALE,   // ESGRIMA
                   GENDER_MALE,    // MANGUAL
                   GENDER_FEMALE, // DAGA
                   GENDER_MALE,    // GARROTE
                   GENDER_FEMALE, // espada corta
                   GENDER_FEMALE, // cimitarra
                                      GENDER_MALE,    // mandoble
                                      GENDER_MALE,  // cayado
                                      GENDER_FEMALE,  //jabalina
                                      GENDER_FEMALE,  // pica
                                      GENDER_FEMALE,   // cimitarra pesada
                                      GENDER_FEMALE,  // maza pesada
                                      GENDER_MALE,  // martillo
                                      GENDER_MALE,   // martillo pesado
                                      GENDER_FEMALE,  // hacha pesada
                                      GENDER_FEMALE,  // hacha Khazad
                                      GENDER_MALE,   // mangual pesado
                                      GENDER_FEMALE,  // espada sinda
                                      GENDER_MALE,  // pico
                                      GENDER_MALE,    // azadón
                                      GENDER_FEMALE,  // espada mediana
                                      GENDER_FEMALE   // arma improvisada
                   })[wt]
             );




// SetValue():
// El primer sumando es el valor intrínseco de ese arma: lo que tú sabes que te
// van a cobrar por el hecho de hacerla.
// El segundo sumando es lo que te va a cargar por el WC y el material.
// precio valor del arma
  SetValue ( ({ 500 + calcvalue(wc,material) // WT_ESPADA
              , 700 + calcvalue(wc,material) // WT_HACHA
              , 500 + calcvalue(wc,material) // WT_MAZA
              , 500 + calcvalue(wc,material) // WT_LANZA
              ,  50 + calcvalue(wc,material) // WT_CUCHILLO
              , 300 + calcvalue(wc,material) // WT_VARA
              , 200 + calcvalue(wc,material) // WT_LATIGO
              , 600 + calcvalue(wc,material) // WT_ALABARDA
              , 500 + calcvalue(wc,material) // WT_CADENA
              , 300 + calcvalue(wc,material) // WT_MANOPLA
              , 300 + calcvalue(wc,material) // WT_ESGRIMA
              , 700 + calcvalue(wc,material) // WT_MANGUAL
              ,  50 + calcvalue(wc,material) // WT_DAGA
              , 300 + calcvalue(wc,material) // WT_GARROTE
              , 400 + calcvalue(wc,material) // WT_ESPADA_CORTA
              , 600 + calcvalue(wc,material) // WT_CIMITARRA
              , 700 + calcvalue(wc,material) // WT_MANDOBLE
              , 700 + calcvalue(wc,material) // WT_CAYADO
              , 700 + calcvalue(wc,material) // WT_JABALINA
              , 700 + calcvalue(wc,material) // WT_PICA
              , 700 + calcvalue(wc,material) // WT_CIMITARRA_PESADA
              , 700 + calcvalue(wc,material) // WT_MAZA_PESADA
              , 700 + calcvalue(wc,material) // WT_MARTILLO
              , 700 + calcvalue(wc,material) // WT_MARTILLO_PESADO
              , 700 + calcvalue(wc,material) // WT_HACHA_PESADA
              , 700 + calcvalue(wc,material) // WT_HACHA_KHAZAD
              , 700 + calcvalue(wc,material) // WT_MANGUAL_PESADO
              , 700 + calcvalue(wc,material) // WT_ESPADA_SINDA
              , 700 + calcvalue(wc,material) // WT_PICO
              , 700 + calcvalue(wc,material) // WT_AZADON
              , 700 + calcvalue(wc,material) // WT_ESPADA_MEDIANA
              , 0 + calcvalue(wc,material) // WT_IMPROVISADA
             })[wt]
           );
  SetWeaponType (weapon_type); // Nota: Hace SetDamType por su cuenta...
  // dureza del arma
// SetWPperQP():
// El primer valor es el valor 'estándar', y lo otro es un bonificador.
  size = ({     2*wc + M_DUREZA[material]  // (WT_ESPADA)
    , 2*wc + M_DUREZA[material]  // (WT_HACHA)
    , 2*wc + M_DUREZA[material]  // (WT_MAZA)
    , 2*wc + M_DUREZA[material]  // (WT_LANZA)
    , 2*wc + M_DUREZA[material]  // (WT_CUCHILLO)
    , 2*wc + M_DUREZA[material]  // (WT_VARA)
    , 2*wc + M_DUREZA[material]  // (WT_LATIGO)
    , 2*wc + M_DUREZA[material]  // (WT_ALABARDA)
    , 2*wc + M_DUREZA[material]  // (WT_CADENA)
    , 2*wc + M_DUREZA[material]  // (WT_MANOPLA)
    , 2*wc + M_DUREZA[material]  // (WT_ESGRIMA)
    , 2*wc + M_DUREZA[material]  // (WT_MANGUAL)
    , 2*wc + M_DUREZA[material]  // (WT_DAGA)
    , 2*wc + M_DUREZA[material]  // (WT_GARROTE)
    , 2*wc + M_DUREZA[material]  // (WT_ESPADA_CORTA)
    , 2*wc + M_DUREZA[material]  // (WT_CIMITARRA)
    , 3*wc + M_DUREZA[material]  // (WT_MANDOBLE)
    , 2*wc + M_DUREZA[material]  // (WT_CAYADO)
    , 2*wc + M_DUREZA[material]  // (WT_JABALINA)
    , 2*wc + M_DUREZA[material]  // (WT_PICA)
    , 3*wc + M_DUREZA[material]  // (WT_CIMITARRA_PESADA)
    , 3*wc + M_DUREZA[material]  // (WT_MAZA_PESADA)
    , 2*wc + M_DUREZA[material]  // (WT_MARTILLO)
    , 3*wc + M_DUREZA[material]  // (WT_MARTILLO_PESADO)
    , 3*wc + M_DUREZA[material]  // (WT_HACHA_PESADA)
    , 3*wc + M_DUREZA[material]  // (WT_HACHA_KHAZAD)
    , 3*wc + M_DUREZA[material]  // (WT_MANGUAL_PESADO)
    , 3*wc + M_DUREZA[material]  // (WT_ESPADA_SINDA)
    , 2*wc + M_DUREZA[material]  // (WT_PICO)
    , 2*wc + M_DUREZA[material]  // (WT_AZADON)
    , 2*wc + M_DUREZA[material]  // (WT_ESPADA_MEDIANA)
    , 2*wc + M_DUREZA[material]  // (WT_IMPROVISADA)
         })[wt];
  if (size<1) size=1; //xq M_DUREZA puede devolver negativo...
  SetWPperQP ( size );
// En lugar de SetWC para evitar líos...
  AsignaWC (calc_wc(weapon_type,wc,material));
  SetNumberHands (wc <= 15 ? 1 : 2);
  SetNumberHands( (    (wc > 15)
          || (member(({WT_VARA,WT_ALABARDA, WT_MANDOBLE, WT_PICA, WT_MAZA_PESADA,
            WT_HACHA_PESADA, WT_CIMITARRA_PESADA, WT_HACHA_KHAZAD, WT_MARTILLO_PESADO,
            WT_PICO, WT_MANGUAL_PESADO, WT_AZADON}),weapon_type) != -1) )? 2:1);
  return 1;
}

// Descripciones...

public string Long(string what)     { return modifyLong(::Long(what)); }
// No existe modifyExaLong
//public string ExaLong(string what) { return modifyExaLong(::ExaLong(what)); }

public string InvShort (string what)
{
    string rc;
    invshort = 1;
    rc = ::InvShort(what);
    invshort = 0;
    return modifyInvShort(rc);
}
public string Short (string what)
{
    if (invshort) return ::Short(what);
    return modifyShort(::Short(what));
}
// Adjetivos
// Tampoco existe modifyAds
//public string *QueryAds() { return modifyAds(::QueryAds()); }

// -----------------------------------------------------------------------------
// Otras funciones de utilidad...
// -----------------------------------------------------------------------------

// DegradeWeapon
public void DegradeWeapon ( mapping soaked, mapping damage, int success
                          , int target)
{
  int s, wpq;

  s = soaked["TOTAL"];
  wpq = QueryWPperQP();
  if ( (wpq>0) && ((s >= wpq) || !random(200)) )
        AddQuality( -((s/wpq) || 1) );
}

public varargs int move (mixed dest, int method, mixed extra) {
  int rc;
  rc = thing::move(dest, method, extra);
  if (rc == ME_OK)
    notify_move(dest, method, extra);
  return rc;
}

public int remove() {
  notify_move(0, M_DESTRUCT);
  return thing::remove();
}


// register_weapon: Opcional. Si esta el logger, vale, si no, a la calle.
// Aunque seria bonito tenerla. Así que la buscaré...
/*
public void register_weapon()
{
   catch(call_other("/d/archwiz/common/defence/obj/logger",
  "register_weapon",TO));
}
*/

// -----------------------------------------------------------------------------
// Funciones principales (create, init,...)
// -----------------------------------------------------------------------------

create()
{
    "*"::create();
    SetUsage(EQM_WIELD); // Nueva!
    AddClassId(C_WEAPON);
    SetStandard(WT_IMPROVISADA,5,P_SIZE_GENERIC);
    seteuid(getuid(TO)); // Para poder cargar el objeto de fórmula.
// Esto sería muy útil, definitivamente...
//    call_out("register_weapon",1);
}

init()
{
    "*"::init();  /* does the add_action for 'show' */
}
