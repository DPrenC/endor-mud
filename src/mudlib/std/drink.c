/* SIMAURIA '/std/drink.c'
   =======================
   [w] Woo
   [a] Angor
   [t] Theuzifan
   [h] Nyh

   29-12-96 [w] Adaptado para el nuevo mud. He dejado la ayuda original.
                Quizas haya que poner genero.
   10-10-98 [a] Anyadido el genero del recipiente con las funciones:
                Set_Vessel_Gender() Query_Vessel_Gender() y modificados
                convenientemente aquellos mensajes que lo necesitan
   02-02-99 [t] Castellanización.
   18-04-03 [t] Solo los viales de vida deben curar.
   21-04-03 [t] Añadidas las funciones QueryXXX y algunas SetXXX para que
   		las bebidas funcionen correctamente al grabar y volver a
   		cargar el inventario.
   05-05-04 [h] Faltaban un par de return 0; en la dinción _drink
*/


/*
 * 1.1: no more cloning!
 * 1.2: several bugs fixed (with the aid of Jhary, Mutabor, Pepel, Pumuckel
 *      and Sique)
 *
 * This piece of code defines a generic bottled drink object. The empty
 * bottle can be refilled in a room which defines the property
 *  "DrinkRefill"
 * which should be a string defining the liquid which can be refilled in
 * that room.
 *
 * An example of a room which allows to refill empty bottles is given in
 *  /d/archwiz/common/health/exroom1.c
 *
 * To set the drink up, you have to call the following functions (most of
 * them are optional) in this order:
 *
 * void Set_Drink_Name(string liquid_desc)
 *  sets name of drink (e.g. "firebreather")
 *
 * string SetFoodMsg1(string msg1)          [optional]
 *  sets the message which the user gets when drinking
 * string SetFoodMsg2(string msg2)          [optional]
 *  sets the message which the room gets when the user consumes the drink
 * int SetFoodAlc(int strength)             [optional]
 *  sets alcoholic strength of the drink
 * int SetFoodHeal(int heal)                [optional]
 *  sets how many HP the user gets instantly when consuming the drink
 * int SetValue(int value)              [optional]
 *  set value of drink (without vessel)
 *
 * string Set_Vessel_Name(string vessel_desc)
 *  sets name of vessel
 * string Set_Vessel_Value(int value)
 *  sets value of empty vessel
 * int Set_Vessel_Weight(int weight)
 *  sets how heavy the vessel is
 * int Set_Vessel_Volume(int vol)
 *  sets the volume (in ml) the vessel contains (or may contain). This
 *  together with the alcohol content directly determines the soak values.
 *
 * Examples:
 *
 * 1. A full bottle of firebreather.
 *
 * The bottle will show up as "a bottle of firebreather". It features a long
 * description. Drink messages are the defaults, that is "You drink a
 * firebreather." and "[name] drinks a firebreather.". The bottle has a volume
 * of 200 ml, but since the firebreather is a strong alcoholic beverage, its
 * soak is only 1. (The same amount of water would have a soak of 14.) The
 * weight of the empty bottle is 500 grams, its worth is 10 coins. The price
 * of the full drink is calculated automatically.
 *
 * inherit "std/drink";
 * void create() {
 *  ::create();
 *  Set_Drink_Name("firebreather");
 *  SetFoodStrength(25);
 *  SetFoodHeal(12);
 *  Set_Vessel_Name("bottle");
 *  Set_Vessel_Volume(200);
 *  Set_Vessel_Weight(500);
 *  Set_Vessel_Value(10);
 *  SetLong("This bottle is filled with fine 25-year-old firebreather.\n");
 * }
 *
 * 2. The same bottle when it is emptied.
 *
 * inherit "std/drink";
 * void create() {
 *  ::create();
 *  Set_Vessel_Name("bottle");
 *  Set_Vessel_Volume(200);
 *  Set_Vessel_Weight(500);
 *  Set_Vessel_Value(10)
 *  fill_vessel(0);
 *  SetLong("This bottle was filled with firebreather once.\n");
 * }
 */

#include <health.h>
#include <properties.h>
#include <sounds.h>

//[a] anyadidas para usarlas en las descripciones
#define EA (Query_Vessel_Gender()==GENDER_FEMALE?"a":"e")
#define OA (Query_Vessel_Gender()==GENDER_FEMALE?"a":"o")
#define _A (Query_Vessel_Gender()==GENDER_FEMALE?"a":"")

/* This should probably move to <health.h> */
#define DRINKLIST "/log/DRINKLIST"
#define DRAUGHT   250       /* how many ml can be drunken with one sip */

// -----------------------------------------------------------------------------

inherit THING;

// -----------------------------------------------------------------------------

/* drink variables */
private int dvolume;    /* actual volume of drink */
private int alc, heal, do_heal;
private string  dname;      /* Name of liquid */

// variables del recipiente (vessel)
private int    vvalue;    // Valor
private int    vweight;   // Peso
private int    vvolume;   // Capacidad
private string vname;     // Nombre del recipiente
private int    vgender;   // Genero gramatical del recipiente ([a] anyadido)

/* other variables */
private string  kind, msg1, msg2, long_desc;

// -----------------------------------------------------------------------------

int QueryMaxFull();
/* function declaration */
void    empty_vessel();
int     fill_vessel(int n);
void    log_drink(string me);

int Set_Vessel_Gender(int i){vgender=i; return i;}
int Query_Vessel_Gender(){return vgender;}

void create() {
    string *myname;

    /* log new stuff */
    if (sizeof(myname = explode(object_name(TO), "#")) == 1)
        log_drink(myname[0]);

    ::create();

    kind = "bebida";
    alc  = heal = do_heal = 0;
    dvolume = 0;

    vname   = "bote";
    Set_Vessel_Gender(GENDER_MALE);
    vvolume = 500;
    vweight = 500;
    vvalue  = 10;
    SetIds(({"bebida","bote"}));
}

/*
 * public functions
 */
void init()
{
    ::init();
    add_action("_drink","beber");
    add_action("_refill","rellenar");
    add_action("_refill","llenar");
}

/*********************************************
 * Built-in properties
 */
string SetFoodKind(string str)  { return kind = str; }
string QueryFoodKind()      { return kind; }
string SetFoodMsg1(string str)  { return msg1 = str; }
string QueryFoodMsg1()      { return msg1; }
string SetFoodMsg2(string str)  { return msg2 = str; }
string QueryFoodMsg2()      { return msg2; }
/* I think this is not optimal --- Organimedes */
string SetLong(string desc) { return long_desc = desc; }


//[a] Modificada para que emplee el genero del recipiente
string QueryLong() {
    if (!dvolume) return("Un"+_A+" "+vname+" vaci"+OA+".\n");
    else if (long_desc && long_desc != "") return(long_desc);
    else return ("Est"+EA+" "+vname+" está llen"+OA+" de "+dname+".\n");
}


int SetFoodAlc(int n)       { return alc = n; }
int QueryFoodAlc()      { return alc; }
int SetFoodHeal(int n) { return heal = n; }
int QueryFoodHeal()     { return do_heal?heal:0; }
int SetIsVial(int to) { return do_heal = to; }
int QueryIsVial() { return do_heal; }

// ------------------------------------------------
// The following properties cannot be set directly
// ------------------------------------------------


//[a] Modificada para que emplee el genero del recipiente
string QueryShort() {
  string str;

  str = "un"+_A+" "+vname+" de "+dname;
  if (!dvolume) {
    str += " (vací"+OA+")";
  }
  else if (QueryMaxFull()) {
    str += " (llen"+OA+")";
  }
  else {
    str += " (empezad"+OA+")";
  }
  return str;
}


int QueryWeight()   { return (vweight + dvolume); }

int QueryValue() {
    int min_value, value;
    int mod;

    mod=0;
    if (do_heal&HP) mod++;
    if (do_heal&SP) mod++;

    value = ::QueryValue();
    min_value = MIN_FOOD_COST(dvolume/14, 0, alc, heal*mod, QueryWeight());
        /* dvolume/14 is approx. equal to soak value of liquid */
    if (value < min_value) value = min_value;
    return (value + vvalue);
}

/* QueryFoodSoak() returns the soak value of one draught */
int QueryFoodSoak() {
  int soak;

  if (do_heal) {
  	return 0;
  }
  if (dvolume < DRAUGHT)
    soak = dvolume/14;
  else
    soak = DRAUGHT/14;
  /* Was: soak = dvolume/14; bugfixed by Pumuckel & Mutabor, 9th oct. 93 */
  /* adjust: 1000 ml for about 7200 heartbeats */
  if (alc > 0) soak = soak / alc;   /* empirical adjustment */
  if (!soak) soak = 1;
  return soak;
}

/* no stuffing with this kind of drink */
int QueryFoodStuff()    { return 0; }

/* Jhary requested these functions: */
int QueryFull()     { return dvolume; }
int SetFull(int to) {
	dvolume = to;
	if (dvolume > vvolume) {
		dvolume = vvolume;
	}
	return dvolume;
}

int QueryMaxFull()  { return (dvolume == vvolume); }

/****************************************************
 * new functions; with "_" to avoid built-in properties
 */
string Set_Drink_Name(string str)   {
    AddId(str); return dname = str;
}
string Set_Vessel_Name(string str)  {
    AddId(str); return vname = str;
}
int Set_Vessel_Value(int n) { return vvalue = n; }
int Set_Vessel_Weight(int n)    { return vweight = n; }
int Set_Vessel_Volume(int n) {
    if (n < 0) n = 0;
    vvolume = n;
    dvolume = n;        /* fill vessel automagically */
    return n;
}

int Query_Vessel_Volume() { return vvolume; }
int Query_Vessel_Weight() { return vweight; }
int Query_Vessel_Value() { return vvalue; }
string Query_Vessel_Name() { return vname; }
string Query_Drink_Name() { return dname; }


/**********************************Action*********************************/

/* drink something */
int _drink(string str) {
    int    p_soak, p_intox, value;
    int    factor, alc_factor, old_weight;
    string p_name;
    object vessel;

    if (!str || present(str,TP) != TO) {
      return notify_fail("No tienes "+(str||"esa bebida")+"\n", NOTIFY_NOT_OBJ);
    }
    if (environment() != TP) {
      return notify_fail("Tendrías que cogerlo primero.\n", NOTIFY_NOT_VALID);
    }
    //[a] anyadido genero
    if (dvolume <= 0) {
      return notify_fail((Query_Vessel_Gender()==GENDER_FEMALE?"La ":"El ")+vname+" está vací"+OA+"!\n");
    }
    /* to avoid things like "drink bottle" */
    //[a] anyadido genero
    if (str == vname) {
      return notify_fail("Deberías intentar beberte el contenido "+(Query_Vessel_Gender()==GENDER_FEMALE?"de la ":"del ")+vname+".\n");
    }
    p_intox = (int)TP->Query(P_ALCOHOL);
    p_soak  = (int)TP->Query(P_DRINK);
    p_name  = (string)TP->QueryName();
    if (dvolume - DRAUGHT <= 0) factor = 1000;
    else factor = DRAUGHT * 1000 / dvolume;  /* avoid rounding errors */
    alc_factor = alc * factor / 1000;

    if ((p_soak + QueryFoodSoak() <= (int)TP->Query(P_MAX_DRINK)) &&
        (p_intox + alc_factor <= (int)TP->Query(P_MAX_ALCOHOL))) {

      play_sound(environment(TP), SND_SUCESOS("beber"));
      if (msg1 && msg1 != "") write(msg1+"\n");
      else write("Bebes un poco de "+dname+".\n");

      if (msg2 && msg2 != "") say(p_name + " " + process_string(msg2)+"\n");
      else say(p_name + " bebe un poco de " + dname + ".\n");

      /* remember weight before drinking: */
      old_weight = QueryWeight();

      TP->AddDrink(QueryFoodSoak());
      TP->AddAlcohol(alc_factor);
      if (do_heal&HP) {
    	TP->HealHP(heal*factor/1000);
      }
      if (do_heal&SP) {
    	TP->HealSP(heal*factor/1000);
      }

      value = QueryValue();
      SetValue(value - value*factor/1000);
      alc     = alc   - alc  *factor/1000;
      heal    = heal  - heal *factor/1000;
      dvolume = dvolume - DRAUGHT;
      if (dvolume <= 0) empty_vessel();

      /* update weight information for environment: */
      environment()->AddIntWeight(QueryWeight()-old_weight);
    }

    else if (p_intox + alc_factor > (int)TP->Query(P_MAX_ALCOHOL)) {
      return notify_fail("¡Estás tan borracho que no puedes encontrarte la boca!\n", NOTIFY_NOT_VALID);
    }
    else if (p_soak + QueryFoodSoak() > (int)TP->Query(P_MAX_DRINK)) {
      return notify_fail("Ya estás suficientemente llen"+(TP->QueryGender()==GENDER_FEMALE?"a":"o")+".\n", NOTIFY_NOT_VALID);
    }
    /* //[Nyh] antes estaba asin, lo cambio xq quiero
    else if (p_intox + alc_factor > (int)TP->Query(P_MAX_ALCOHOL)) {
      write("¡Estás tan borracho que no puedes encontrarte la boca!\n");
      say("¡"+p_name + " está tan borracho que no puede beber nada mas!\n");
    }
    else if (p_soak + QueryFoodSoak() > (int)TP->Query(P_MAX_DRINK)) {
      write("Lo más seguro es que no puedas beberte esto.\n"
            "Ya estás suficientemente llen"+(TP->QueryGender()==GENDER_FEMALE?"a":"o")+".\n");
      say(p_name + " no puede beberse "+dname+".\n");
    }
    */
    return 1;
}

/* refill vessel */
int _refill(string str) {
    object room, vessel;
    string s, empty_vessel, liquid;

    if (!str || sscanf(str,"%s con %s",empty_vessel,liquid) != 2) {
    notify_fail("Rellenar <recipiente> con <liquido>.\n");
    return 0;
    }
    if (present(empty_vessel,TP) != TO) {
    notify_fail("No dispones de "+empty_vessel+" para llenar.\n");
    return 0;
    }
    if (dvolume > 0 && (lower_case(dname) != lower_case(liquid))) {
    notify_fail("¡No puedes mezclar dos líquidos diferentes!\n");
    return 0;
    }

    room = environment(TP);
    if (lower_case((string)room->Query(P_REFILL)||"") != lower_case(liquid)
     && !present(lower_case(liquid), room)
       )
    {
    write("No hay "+liquid+" aquí.\n");
    return 1;
    }
    write("Llenas "+QueryShort()+" con "+liquid+".\n");
    say(TP->QueryName()+ " llena "+QueryShort()+" con "+liquid+".\n");

    fill_vessel(vvolume);       /* fill vessel completely */
    Set_Drink_Name(liquid);
    return 1;
}

/******* Internal procedures *********/

/*
 * make current vessel empty and give it the current values
 * of: vessel's name, weight, value and volume.
 * The user may overload a long description.
 */
void empty_vessel() {
    SetFoodMsg1("");
    SetFoodMsg2("");
    SetFoodAlc(0);
    SetFoodHeal(0);
    SetValue(0);
    fill_vessel(0);

    /* do the naming */
    SetIds(({"bebida","recipiente","vaso",vname}));   /* delete old ids */
    SetLong("");                /* delete old long desc */
    AddAdjective("vacio");
}

/*
 * fill current vessel with a defined volume (ml)
 */
int fill_vessel(int volume) {
    SetAds(({ }));
    if (volume > vvolume)
    dvolume = vvolume;
    else if (volume > 0)
    dvolume = volume;
   else
    dvolume = 0;
    return dvolume;
}

/*
 * log drink into drinklist
 */
void log_drink(string me) {
    string list, foo1, foo2;

    if (file_size(DRINKLIST) > 0) {
    list = read_file(DRINKLIST);
    if (!sscanf(list,"%s"+me+"%s",foo1,foo2))
        write_file(DRINKLIST,me+"\n");
    }
    else
    write_file(DRINKLIST,me+"\n");
}
