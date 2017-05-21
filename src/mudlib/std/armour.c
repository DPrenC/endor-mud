/*
 * /std/armour.c V2.0
 *
 * Fichero con toda la funcionalidad de las armaduras
 *
 * Creación: Feb'99, a partir de los antiguos /std/armour.c
 *           y /std/armour/combat.c, tomando ideas y código de la versión 4.8
 *           del armour.c de NightFall. [Nemesis@Simauria]
 * Modificado: Ago'99 [n] Pegados aquí los fragmentos necesarios del puzzle.
 *	05-10-99 [t] Añado el material M_ESPECIAL...
 *      28-03-00 [n] No veo la necesidad de un M_ESPECIAL, ahora bien, paso.
 *                   Yo por mi parte, cambio SetAC de private a public y
 *                   guardo en un log los usos de SetAC.
  */

#include <classes.h>
#include <combat.h>
#include <config.h>
#include <equipment.h>
#include <moving.h>
#include <properties.h>
#include <search.h>

inherit THING;
inherit "/std/equipment";

// Declaraciones Forward:
public varargs int QueryAC();
public int GetDefence(int type);

// -----------------------------------------------------------------------------
// Atributos:
private int pArmourType, pAPperQP; // Tipo de armadura y "dureza"
private mapping pDefences; // Defensas respecto a los diferentes DT_...

private nosave int invshort;  // flag para manejar diferentes modificaciones de
				                      // Short e InvShort
// -----------------------------------------------------------------------------
// Calculos, Funciones Auxiliares, etc.
// -----------------------------------------------------------------------------

protected int helpcalc(int ac,int size)
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
    return i + (ac/5);
}

protected int calcvalue(int ac, string material)
{
 int i;
  switch(material)
  {
  case M_TELA     : i=5*ac; break;
  case M_PIEL     : i=5*ac; break;
  case M_CRISTAL  : i=10*ac; break;
  case M_CUERO    : i=15*ac; break;
  case M_HUESO    : i=15*ac; break;
  case M_PIEDRA   : i=15*ac; break;
  case M_MADERA   : i=30*ac; break;
  case M_COBRE    : i=40*ac; break;
  case M_BRONCE   : i=50*ac; break;
  case M_HIERRO   : i=150*ac; break;
  case M_ACERO    : i=175*ac; break;
  case M_ALUMINIO : i=250*ac; break;
  case M_PLATA    : i=350*ac; break;
  case M_ORO      : i=700*ac; break;
  case M_PLATINO  : i=1000*ac; break;
  case M_DIAMANTE : i=1000*ac; break;
  case M_TITANIO  : i=1500*ac; break;
  case M_ADAMANTIO: i=1700*ac; break;
  case M_MITHRIL  : i=2000*ac; break;
  case M_ESPECIAL : i=2500*ac; break;
  default : i=0; break;
  }
 return i;
}

// dureza(material):
// calcula el bonificador por material para la armadura.

protected int dureza(string material) { return M_DUREZA[material];}

protected int calc_apperqp(int ac, string material) {
 int i;
 i = ac + M_DUREZA[material];
 if (i <=0) return 1;
 else return i;
}

protected int calc_ac(mixed type, int ac, string mat)
{
 int i;
 i=ac;
 switch(type)
 {
  case AT_ARMOUR:
  {
   switch(mat)
   {
    case M_TELA  : if (ac >  3) i= 3; break;
    case M_CUERO : if (ac > 15) i=15; break;
    case M_PIEL  : if (ac > 15) i=15; break;
    default : if (ac > 25) i=25; break;
   }

  } break; // Case AT_ARMOUR...

  case AT_HELMET   : if (ac >  5) i= 5; break;
  case AT_GLOVES   : if (ac >  5) i= 5; break;
    case AT_BRAZALES   : if (ac >  5) i= 5; break;
  case AT_BOOTS    : if (ac >  5) i= 5; break;
    case AT_GREBAS   : if (ac >  5) i= 5; break;
  case AT_SHIELD   : if (ac > 10) i=10; break; //escudo
  case AT_TROUSERS : if (ac > 1) i=1; break;
      case AT_MANTO    : if (ac >  1) i= 1; break;
        case AT_CAPUCHA    : if (ac >  1) i= 1; break;
  case AT_RING :
  if (ac>=1)
  {
  i=1;
  "/obj/lib/register"->Register(sprintf("%O",TO), "ANILLOS_MAGICOS");
  } break; // case AT_RING...
  case AT_AMULET :
  if (ac>=1)
  {
  i=1;
  "/obj/lib/register"->Register(sprintf("%O",TO), "AMULETOS_MAGICOS");
  } break; // case AT_AMULET...

 }
return i;

}

/* CalcDefend (enemy, damage, damage_type)
 * Defend (enemy, damage, damage_type)
 *
 * Computar la defensa contra un daño específico y devolverla.
 * El propio living la restará del daño.
 * CalcDefend() sólo calcula el valor.
 * Defend() es la función que debe llamarse para la defensa.
 *
 * La defensa devuelta por Defend() será modificada por la
 * calidad de la armadura más un desplazamiento de 5 para que
 * las armaduras con calidad >=95% den protección total.
 * Los bonificadores por bendición/maldición también se
 * calcularán ahí.
 */

int CalcDefend (object enemy, int damage, int type)
{
	 int defence, hands;
	 object wearer;

	 wearer = QueryEquipped();
	 if (!wearer) return 0;

	 defence = QueryAC();
	 if (type != DT_INTR) defence += GetDefence(type);

	 if (pArmourType == AT_SHIELD)
	 {
	   defence += (wearer->QueryDex() + wearer->QueryCon()) / 8;

	   hands = QueryNumberHands();
	   if (hands > 1) defence = defence * (1 + hands) / 2;
	 }

	 return defence;
}

int Defend (object enemy, int damage, int type)
{
  object d_ob;
  int defence, q;

  defence = CalcDefend(enemy, damage, type);

  q = QueryQuality();
  defence = defence * ( (q > 94) ? 100 : q+5 );
        // protección completa para calidad > 94%

  //dtell("nyh",sprintf("defence = %O\tdamage = %O\treturn=%O\n",defence, damage, ( (damage * defence) + 9950) / 10000));
  return ( (damage * defence) + 9950) / 10000;
}


// -----------------------------------------------------------------------------
// Funciones para manipular Atributos (Set-,Query-,Remove-,Add-,Get-,...)
// -----------------------------------------------------------------------------

// pAPperQP
public int QueryAPperQP ()    { return pAPperQP; }
public int SetAPperQP (int i)    { return pAPperQP = i; }

// pDefences
public mapping QueryDefenceMap() { return copy(pDefences || ([])); }
public int GetDefence(int type)  { return (pDefences || ([]))[type]; }
public int AddDefence(int type, int value)
{
	 if (!VALID_DAMAGE_TYPE(type)) return 0;
	 if (!pDefences) pDefences = ([ ]);
	 if (value) pDefences[type] = value;
	 else m_delete(pDefences,type);
	 return value;
}

public mapping SetDefenceMap(mapping m)
{
	 int i, *types;

	 if (!mappingp(m)) m = ([ ]);
	 if (!member(m,DT_INTR)) m[DT_INTR] = GetDefence(DT_INTR);
	 pDefences = ([ ]);
	 types = m_indices(m);
	 for (i=sizeof(types); i--; )
	AddDefence(types[i], m[types[i]]);
	 return QueryDefenceMap();
}

// pAC
// El AC es un atributo más del mapping pDefences, concretamente, la defensa
// contra DT_INTR (daño por defecto). Antes era la posicion 0, pero ahora
// es el valor definido por DT_INTR en el combat.h, permitiendo mayor flexibi-
// lidad y clarificando un poco mas el código. Ahora mismo DT_INTR=0.
// AsignaAC es lo que usa SetStandard para modificar el valor de AC, de ahí que
// sea una función privada. De esta manera, siempre sabré cuándo alguien está
// modificando el AC desde fuera de SetStandard, ya que el código de SetAC va a
// incluye la escritura en un log del archivo donde se usa SetAC.

private int AsignaAC(int ac) { return AddDefence(DT_INTR,ac); }

public int SetAC(int ac)   {

log_file("combat/SetAC",sprintf("%O\n",TO));

return AddDefence(DT_INTR,ac);
}

public varargs int QueryAC()  { return GetDefence(DT_INTR); }

// pArmourType

int QueryArmourType() { return pArmourType; }

int SetArmourType(int a)
{
	 if (!VALID_ARMOUR_TYPE(a))
	return 0;

	 if (pArmourType)
		RemoveId( ([AT_CORAZA: "coraza"
		 , AT_CASCO:   "casco"
		 , AT_AMULETO: "amuleto"
		 , AT_ANILLO:  "anillo"
		 , AT_GUANTES: "guantes"
		 , AT_TUNICA:  "tunica"
		 , AT_BOTAS:   "botas"
		 , AT_ESCUDO:  "escudo"
		 , AT_PANTALONES: "pantalones"
		 , AT_MANTO: "manto"
		 , AT_CAPUCHA: "capucha"
         , AT_GREBAS: "grebas"
         , AT_CINTURON: "cinturon"
         , AT_TALABARTE: "talabarte"
         , AT_BROCHE: "broche"
         , AT_BRAZALES: "brazales"
         , AT_PULSERA: "pulsera"
         , AT_TABARDO: "tabardo"
         , AT_TIARA: "tiara"
         , AT_FALDA: "falda"
         , AT_CAMISA: "camisa"
		])[pArmourType]
			);
	 pArmourType=a;
	 AddId( ([ AT_CORAZA:  "coraza"
		 , AT_CASCO:   "casco"
		 , AT_AMULETO: "amuleto"
		 , AT_ANILLO:  "anillo"
		 , AT_GUANTES: "guantes"
		 , AT_TUNICA:  "tunica"
		 , AT_BOTAS:   "botas"
		 , AT_ESCUDO:  "escudo"
		 , AT_PANTALONES: "pantalones"
		 , AT_MANTO: "manto"
		 , AT_CAPUCHA: "capucha"
         , AT_GREBAS: "grebas"
         , AT_CINTURON: "cinturon"
         , AT_TALABARTE: "talabarte"
         , AT_BROCHE: "broche"
         , AT_BRAZALES: "brazales"
         , AT_PULSERA: "pulsera"
         , AT_TABARDO: "tabardo"
         , AT_TIARA: "tiara"
         , AT_FALDA: "falda"
         , AT_CAMISA: "camisa"
		])[pArmourType]
	 );
	 return pArmourType;
}

// SetStandard()-> Usada para crear armaduras correctas en todos sus valores
varargs int SetStandard (mixed armour_type, int ac, int size, string material)
// armour_type puede ser tambien un array de la forma:
// ({armour_type, ac, size})
{

  int at;

  // Extender el array a sus valores (if armour_type es un array)
  if (pointerp(armour_type))
    return apply(SF(SetStandard),armour_type);

  if (!VALID_ARMOUR_TYPE(armour_type)) return 0;
  at = member(({ AT_ARMOUR, AT_HELMET, AT_RING, AT_GLOVES, AT_CLOAK,
                  AT_BOOTS, AT_SHIELD, AT_TROUSERS, AT_AMULET, AT_MANTO,
                  AT_CAPUCHA, AT_GREBAS, AT_CINTURON, AT_TALABARTE, AT_BROCHE,
                  AT_BRAZALES, AT_PULSERA, AT_TABARDO, AT_TIARA, AT_FALDA, AT_CAMISA}), armour_type
                    );
  if (at < 0)
  {
    log_file("COMPAT", sprintf("%O: %O->SetStandard(string %O,)\n"
            , TO, PO, armour_type));
    at = member(({ "coraza", "casco", "anillo", "guantes", "tunica", "botas",
                    "escudo", "pantalones", "amuleto", "manto",
                    "capucha", "grebas", "cinturon", "talabarte", "broche", "brazales",
                     "pulsera", "tabardo", "tiara", "falda", "camisa" }), armour_type
                    );
  }
  SetShort ( ({ "una coraza"
              , "un casco"
              , "un anillo"
              , "unos guantes"
              , "una túnica"
              , "unas botas"
              , "un escudo"
              , "unos pantalones"
              , "un amuleto"
              ,"un manto"
              , "una capucha"
              , "unas grebas"
              , "un cinturón"
, "un talabarte"
, "un broche"
, "unos brazales"
, "una pulsera"
, "un tabardo"
, "una tiara"
, "una falda"
, "una camisa"
             })[at]
           );

SetLong(
 ({ "Es una coraza formada por placas de cuero superpuestas y moldeadas para adaptarse "
    "al cuerpo y que protege de las caderas a los hombros de su portador. Incluye unas "
    "amplias mangas que van hasta el codo.\n"
              , "Es un sencillo casco fabricado con láminas superpuestas de cuero duro "
              "que cubre la parte superior de la cabeza.\n"
              , "Es una liviana y estrecha banda de metal que se puede ensartar en un dedo.\n"
              , "Son unos simples guantes de cuero blando que protegen las manos.\n"
              , "Es una prenda de tela, larga, amplia y con mangas que se viste en la "
              "parte superior del cuerpo y llega hasta las rodillas.\n"
              , "Son un simple par de botas de cuero blando cuya caña llega hasta la rodilla.\n"
              , "Es un escudo redondo, de tamaño medio, confeccionado con un armazón "
              "de tablillas de madera y con unas correas de cuero en la parte interior "
              "para colgarlo del brazo.\n"
              , "Son unos simples pantalones de tela que cubren las piernas hasta los tobillos.\n"
              , "Se trata de un simple medallón de metal que cuelga de una liviana "
              "cinta de cuero que se ajusta en torno del cuello de quien lo lleva.\n"
              ,"Es un amplio manto fabricado con tela corriente que se ajusta al "
              "cuello o el hombro mediante un broche, cayendo sobre la espalda de "
              "su portador en grandes pliegues. Suele utilizarse para envolverse "
              "en él y soportar las bajas temperaturas o esconder toda clase de objetos debajo.\n"
              , "Es una simple capucha de tela vasta y sin teñir que cubre la cabeza "
              "y puede ajustarse para ocultar el rostro de su portador. Suele ir unida a una capa o manto.\n"
              , "Son unas simples placas de cuero que, superpuestas y sujetas con "
              "tiras del mismo material, protegen los muslos, rodillas y pantorrillas "
              "de su portador.\n"
              , "Es una simple tira de cuero con una hebilla y una serie de agujeros "
              "para ajustarlo a las caderas de su portador. Se usa para colgar todo "
              "tipo de vainas y objetos o para sujetar la ropa.\n"
, "Son un par de tiras de cuero que se entrecruzan en el pecho y espalda y que "
"cuentan con un par de hebillas para ajustarlas al cuerpo de su portador.\n  Un par de "
"lazzadas de cuero cuelgan de la parte posterior para poder llevar un escudo o un "
"arma de gran tama´ño colgada a la espalda.\n"
, "Es un simple broche de metal que sirve para cerrar el manto o capa de quien lo "
"lleva sobre un hombro o el cuello.\n"
, "Son una serie de placas de cuero que, superpuestas y sujetas a los antebrazos por "
"tiras del mismo material  y unas pequeñas hebillas metálicas, protegen el brazo "
"de su portador del codo a la muñeca.\n"
, "Es una simple banda de metal circular en cuyo interior se introduce la muñeca.\n"
, "Es una holgada prenda de cuero que se lleva suelta sobre el tronco. Cuenta con dos "
"amplias y cortas mangas que no cubren casi nada más que los hombros.\n"
, "Es un sencillo aro de bronce sin ninguna clase de adorno que se sostiene rodeando "
"la parte superior del cráneo.\n"
, "una larga falda de tela rústica que tapa hasta los pies.\n"
, "una simple camisa de tela rasa.\n"
             })[at]
           );


  if (!material)
     SetMaterial( ({
                    M_CUERO
                  , M_CUERO
                  , M_COBRE
                  , M_CUERO
                  , M_TELA
                  , M_CUERO
                  , M_CUERO
                  , M_TELA
                  , M_COBRE
                  , M_TELA  //manto
                  , M_TELA  // capucha
              , M_CUERO  // grebas
              , M_CUERO // cinturón
, M_CUERO  // talabarte
, M_COBRE  // broche
, M_CUERO  // brazales
, M_COBRE  // pulsera
, M_CUERO  // tabardo
, M_COBRE  // tiara
, M_TELA // falda
, M_TELA // camisa
                  })

                );
  else SetMaterial(material);
  Set(P_GENDER, ({  GENDER_FEMALE // Coraza
                   ,GENDER_MALE   // Casco
                   ,GENDER_MALE   // Anillo
                   ,GENDER_MALE   // Guantes
                   ,GENDER_FEMALE // Túnica
                   ,GENDER_FEMALE // Botas
                   ,GENDER_MALE   // Escudo
                   ,GENDER_MALE   // Pantalones
		   ,GENDER_MALE   // Amuleto
		   ,GENDER_MALE   // Manto
		   , GENDER_FEMALE  // capucha
              , GENDER_FEMALE    // grebas
              , GENDER_MALE   // cinturón
, GENDER_MALE  // talabarte
, GENDER_MALE  // broche
, GENDER_MALE  // brazales
, GENDER_FEMALE  // pulsera
, GENDER_MALE  // tabardo
, GENDER_FEMALE  // tiara
, GENDER_FEMALE  // falda
, GENDER_FEMALE  // camisa
                  })[at]
               );

  Set(P_NUMBER, ({  0
                   ,0
                   ,0
                   ,1
                   ,0
                   ,1
                   ,0
                   ,1
		   ,0
		   ,0 //manto
		   , 0 //capucha
		   , 1 //grebas
		   , 0 //cinturón
		   , 0  //talabarte
		   , 0 // broche
		   , 1 // brazales
		   , 0 // pulsera
		   , 0 //tabardo
		   , 0 // tiara
		   , 0 //falda
		   , 0 // camisa
                  })[at]
                );
  SetSize(size);
  SetResetQuality(99);
  SetQuality(99);
  if (armour_type == AT_SHIELD)
  //SetNumberHands( (ac>5) ? (ac+4)/5 : 1);
  SetNumberHands(1);
  SetWeight ( ({ 3000 * helpcalc(ac,size) // 5000..40000 (AT_MAIL)
               ,  500 * helpcalc(ac,size) //  250.. 1000 (AT_HELMET)
               ,    30 * helpcalc(ac,size) //    5        (AT_RING)
               ,   100 * helpcalc(ac,size) //   40..  160 (AT_GLOVES)
               ,  350 * helpcalc(ac,size) //  450.. 1800 (AT_CLOAK)
               ,  500 * helpcalc(ac,size) //  500.. 2000 (AT_BOOTS)
               ,  1000 * helpcalc(ac,size) //  750.. 3750 (AT_SHIELD)
	       ,  350 * helpcalc(ac,size) //  350.. 1750 (AT_TROUSERS)
	       ,    60 * helpcalc(ac,size) //    5        (AT_AMULET)
	       ,  450 * helpcalc(ac,size) //  450.. 1800 (AT_MANTO)
	       ,   150 * helpcalc(ac,size) //   100..  400 (AT_CAPUCHA)
	       ,  800 * helpcalc(ac,size) //  500.. 2000 (AT_GREBAS)
	       ,  200 * helpcalc(ac,size) //  200.. 800 (AT_CINTURON)
	       ,  300 * helpcalc(ac,size) //  300.. 1200 (AT_TALABARTE)
	       ,  50 * helpcalc(ac,size) //  50.. 200 (AT_BROCHE)
	       ,  600 * helpcalc(ac,size) //  600.. 2000 (AT_BRAZALES)
	       ,  80 * helpcalc(ac,size) //  80.. 320 (AT_PULSERA)
	       ,  200 * helpcalc(ac,size) //  200.. 800 (AT_TABARDO)
	       ,  100 * helpcalc(ac,size) //  100.. 400 (AT_TIARA)
	       ,  350 * helpcalc(ac,size) //  350.. 1750 (AT_FALDA)
	       ,  350 * helpcalc(ac,size) //  350.. 1750 (AT_CAMISA)
              })[at]
           );
  SetValue ( ({  110 + calcvalue(ac,material) // (AT_MAIL,     maxac 25)
              ,   50 + calcvalue(ac,material) // (AT_HELMET,   maxac  5)
              ,  100 + calcvalue(ac,material) // (AT_RING,     maxac  0)
              ,   50 + calcvalue(ac,material) // (AT_GLOVES,   maxac  5)
              ,   20 + calcvalue(ac,material) // (AT_CLOAK,    maxac  5)
              ,   30 + calcvalue(ac,material) // (AT_BOOTS,    maxac  5)
              ,  100 + calcvalue(ac,material) // (AT_SHIELD,   maxac 10)
	      ,   20 + calcvalue(ac,material) // (AT_TROUSERS, maxac 1)
	      ,   50 + calcvalue(ac,material) // (AT_AMULET,   maxac  0)
	      ,   40 + calcvalue(ac,material) // (AT_MANTO,    maxac  1)
	      ,   20 + calcvalue(ac,material) // (AT_CAPUCHA,   maxac  1)
	      ,   60 + calcvalue(ac,material) // (AT_GREBAS,    maxac  5)
	      ,   20 + calcvalue(ac,material) // (AT_CINTURON,   maxac  0)
	      ,   30 + calcvalue(ac,material) // (AT_TALABARTE,   maxac  0)
	      ,   40 + calcvalue(ac,material) // (AT_BROCHE,   maxac  0)
	      ,   100 + calcvalue(ac,material) // (AT_BRAZALES,   maxac  5)
	      ,   50 + calcvalue(ac,material) // (AT_PULSERA,   maxac  0)
	      ,   70 + calcvalue(ac,material) // (AT_TABARDO,   maxac  2)
	      ,   50 + calcvalue(ac,material) // (AT_TIARA,   maxac  0)
	      ,   30 + calcvalue(ac,material) // (AT_FALDA,   maxac  0)
	      ,   30 + calcvalue(ac,material) // (AT_CAMISA,   maxac  0)
             })[at]
           );
  SetAPperQP(calc_apperqp(ac,material));
  SetArmourType (armour_type);
// De esta manera me evito líos...
  AsignaAC (calc_ac(armour_type, ac, material));
  return 1;
}


// QueryValue->Imagino que llamará al QueryValue de std/equipment.c
public varargs int QueryValue()
{
//	 if (flag) return (::QueryValue());
	 return modifyValue(::QueryValue());
}

// Descripciones...
public string Long(string what)     { return modifyLong(::Long(what)); }
// No hay descripción larga al examinar diferente... ¿quizá debería?
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
// No existe modifyAds()
//public string *QueryAds() { return modifyAds(::QueryAds()); }

public varargs int move (mixed dest, int method, mixed extra) {
  int rc;
  rc = thing::move(dest, method, extra);
  if (rc == ME_OK)
	 notify_move(dest, method, extra);
  return rc;
}

public int remove()
{
  notify_move(0, M_DESTRUCT);
  return thing::remove();
}

// -----------------------------------------------------------------------------
// Otras funciones de utilidad...
// -----------------------------------------------------------------------------

// DegradeArmour()
public void DegradeArmour ( mapping soaked, mapping damage, object weapon
                          , int success, int target)

// Degrada la calidad de la armadura

{
  int s, apq;

  s = soaked["TOTAL"];
  apq = QueryAPperQP();
   if ((apq>0) && ((s>=apq)||!random(200)))
   AddQuality(-((s/apq)||1));
}

// register_armour: Opcional. Si esta el logger, vale, si no, a la calle.
// No está ¡Mierda! Con lo que mola...

/*public void register_armour()
{
  catch(call_other("/d/archwiz/common/defence/obj/logger",
	 "register_armour",TO));
}
*/

// -----------------------------------------------------------------------------
// Funciones principales (create, init,...)
// -----------------------------------------------------------------------------
void create ()
{
  "*"::create();
  SetUsage(EQM_WEAR); // Nueva!
  AddClassId(C_ARMOUR);
  SetStandard(AT_CASCO, 1, P_SIZE_GENERIC); // Poner casco de cuero
  seteuid(getuid(TO)); // to be able to load the formula object.
// No puedo... aún
//  call_out("register_armour",1);  // register , but allow configuration after being cloned
}

void init()
{
  "*"::init();
}
