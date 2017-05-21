/* ENDOR-MUD room de ajustes para fichas nuevas.
Ajusta la sed, el hambre, los puntos de vida, la ciudadanía y mueve al player a su enclave
*/
#include <properties.h>
#include <wizlevels.h>
#include <domain.h>
#include <input_to.h>
#include <stdrooms.h>
#include <moving.h>
#include <colours.h>

inherit ROOM;

public void ajustes();
public void movimiento();
public void vestimenta();
public void gremio(){
// de momento solo humanos y hobits, cuando haya otro gremio ya lo cambiamos.
if (TP->QueryRazabase()=="humano" || TP->QueryRazabase()=="hobbit")
        TP->move("/guilds/aventurero/sede/bree/aventurero.c", M_SILENT);
        call_out("movimiento",2);
    }
public void movimiento(){
        write(ANSI_PURPLE+"\nMoviendo a tu personaje a su destino..."+ANSI_NORMAL+"\n\n");
    "/room/room_inicio"->enclaves();
    }
public void input_hombrecomun(){
    input_to("ciu_hombrecomun", INPUT_PROMPT, "\nLas opciones de enclaves para los hombres son:\n"
    "errante, \nBree, \nCiudad del Lago, \nValle, \nMinas Tirith, \nPelargir, "
    "\nDol Amroth, \nCalembel, \nLossarnach.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_dunadan(){
    input_to("ciu_dunadan", INPUT_PROMPT, "\nLas opciones de enclaves para los Dúnadan son:\n"
    "Minas Tirith, \nPelargir, \nDol Amroth, \nRefugio Dunadan.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_orcocomun(){
    input_to("ciu_orcocomun", INPUT_PROMPT, "\nLas opciones de enclaves para los orcos son:\n"
    "Moria, \nMinas Morgul, \nIsengard, \nGorgoroth.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_trasgos(){
    input_to("ciu_trasgos", INPUT_PROMPT, "\nLas opciones de enclaves para los Trasgos son:\n"
    "Moria, \nCiudad de los Trasgos.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_uruk(){
    input_to("ciu_uruk", INPUT_PROMPT, "\nLas opciones de enclaves para los Uruk son:\n"
    "Minas Morgul, \nIsengard, \nGorgoroth.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_enanos(){ // cintura-ancha barbafuego
    input_to("ciu_enanos", INPUT_PROMPT, "\nLas opciones de enclaves para los Cintura Ancha y los Barbafuego son:\n"
    "Nan Naugrim, \nerrante.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_barbiluengo(){
    input_to("ciu_barbiluengo", INPUT_PROMPT, "\nLas opciones de enclaves para los Barbiluengos son:\n"
    "Nan Naugrim, \nErebor, \nColinas de Hierro, \nerrante.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_noldo(){
    input_to("ciu_noldo", INPUT_PROMPT, "\nLas opciones de enclaves para los Noldor son:\n"
    "Mithlond, \nImladris, \nLothlórien, \nerrante.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_sinda(){
    input_to("ciu_sinda", INPUT_PROMPT, "\nLas opciones de enclaves para los Sinda son:\n"
    "Reino de Thranduil, \nMithlond, \nImladris, \nLothlórien, \nerrante.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_silvano(){
    input_to("ciu_silvano", INPUT_PROMPT, "\nLas opciones de enclaves para los Silvanos son:\n"
    "Reino de Thranduil, \nLothlórien.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_medioelfo(){
    input_to("ciu_medioelfo", INPUT_PROMPT, "\nLas opciones de enclaves para los medio elfo son:\n"
    "Mithlond, \nImladris, \nRefugio Dúnadan, \nerrante.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_wose(){
    input_to("ciu_wose", INPUT_PROMPT, "\nLas opciones de enclaves para los Wose son:\n"
    "Bosque de Drúadan, \nCavernas del Viejo Púkël.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_haradan(){
    input_to("ciu_haradan", INPUT_PROMPT, "\nLas opciones de enclaves para los Haradan son:\n"
    "Estepas de Harad, \nUmbar.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_dunlendino(){
    input_to("ciu_dunlendino", INPUT_PROMPT, "\nLas opciones de enclaves para los Dunlendinos son:\n"
    "Tierras Brunas, \nerrante.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
public void input_rohir(){
    input_to("ciu_rohir", INPUT_PROMPT, "\nLas opciones de enclaves para los Rohir son:\n"
    "Cuernavilla, \nEdoras.\n  ¿Qué ciudadanía quieres para tu personaje?: ");
}
create(){
    ::create();
        SetLocate("algún lugar de Arda");
        SetIntBright(20);
    SetIntShort("Ajustando valores");
    SetIntLong("Por último, aquí te vestimos y te ajustamos algunos valores como tu lugar de procedencia o ciudadanía.\n");
    }

public void init(){
    ::init();
if(!IS_LEARNER(TP)){
ajustes();
    }
}

public void ajustes(){
        TP->SetHP(TP->QueryMaxHP());
    TP->SetFood(TP->QueryMaxFood());
    TP->SetDrink(TP->QueryMaxDrink());

    vestimenta();

    write(ANSI_PURPLE+"\nAjustando la ciudadanía de tu personaje...\n"+ANSI_NORMAL);
    switch(TP->QueryRace()){
        case "hombre-comun": input_hombrecomun();  break;
        case "algo": case "fuerte": case "peloso":
            write("Temporalmente se te ajusta la ciudadanía en Bree.\n");
            TP->SetCitizenship("bree");
            gremio();
             break;
        case "variag":
            write("La única ciudadanía posible para los variag es Meseta de Khänd.\n");
            TP->SetCitizenship("meseta de khand");
            gremio();
             break;
        case "oriental":
            write("La única ciudadanía posible para los Orientales son las Estepas del Este.\n");
            TP->SetCitizenship("estepas del este");
            gremio();
             break;
        case "hombre-del-bosque":
            write("La única ciudadanía posible para los hombres del bosque es Ciudad del Bosque.\n");
            TP->SetCitizenship("ciudad del bosque");
            gremio();
             break;
        case "beornida":
            write("La única ciudadanía posible para los Beórnidas es Carroca.\n");
            TP->SetCitizenship("carroca");
            gremio();
             break;
        case "medio-orco":
            write("La única ciudadanía posible para los medio orcos es Isengard.\n");
            TP->SetCitizenship("isengard");
            gremio();
             break;
            case "lossadan":
                write("La única ciudadanía posible para los Lossadan es la Bahía de Forochel.\n");
            TP->SetCitizenship("bahia de forochel");
            gremio();
             break;
        case "numenoreano-negro": case "corsario":
            write("La única ciudadanía posible para los Numeroneanos Negros y los Corsarios es Umbar.\n");
            TP->SetCitizenship("umbar");
            gremio();
             break;
        case "dunadan": input_dunadan();  break;
        case "orco-comun": input_orcocomun();  break;
        case "trasgos": input_trasgos();  break;
        case "uruk": input_uruk();  break;
        case "barbafuego": case "cintura-ancha": input_enanos();  break;
        case "barbiluengo": input_barbiluengo();  break;
        case "noldo": input_noldo();  break;
        case "sinda": input_sinda();  break;
        case "silvano": input_silvano();  break;
        case "medio-elfo": input_medioelfo();  break;
        case "wose": input_wose();  break;
        case "haradan": input_haradan();  break;
        case "dunlendino": input_dunlendino();  break;
        case "rohir": input_rohir();  break;
        default: //Puñoférreo, piepétreo, barbatiesa, rizosnegros.
        write("Temporalmente se te ajusta la ciudadanía en errante.\n");
            TP->SetCitizenship("errante");
            gremio();
    break;
        }//switch inputs
        }//ajustes

public void vestimenta(){
    object pantalones, tunica, botas, vestido, zapatos, camisa, blusa, falda;
    switch(TP->QueryRazabase()){
        case "elfo":
          if (TP->QueryGender()==GENDER_MALE){
    tunica = clone_object(ROPA("base_tunica"));
    botas  = clone_object(ROPA("base_botas"));
    tunica->move(TP);
TP->Equip(tunica,1);
botas->move(TP);
TP->Equip(botas,1);
}else{
vestido = clone_object(ROPA("vestido"));
    vestido->move(TP);
    TP->Equip(vestido,1);
    zapatos = clone_object(ROPA("zapatos"));
    zapatos->move(TP);
    TP->Equip(zapatos,1);
    }
    break;
    case "hobbit":
          if (TP->QueryGender()==GENDER_MALE){
    camisa = clone_object(ROPA("camisa"));
    pantalones  = clone_object(ROPA("base_pantalones"));
    camisa->move(TP);
TP->Equip(camisa,1);
pantalones->move(TP);
TP->Equip(pantalones,1);
}else{
vestido = clone_object(ROPA("vestido"));
    vestido->move(TP);
    TP->Equip(vestido,1);
        }
    break;
            default:
if (TP->QueryGender()==GENDER_MALE){
    pantalones = clone_object(ROPA("base_pantalones"));
    botas  = clone_object(ROPA("base_botas"));
        camisa = clone_object(ROPA("camisa"));
    pantalones->move(TP);
TP->Equip(pantalones,1);
botas->move(TP);
TP->Equip(botas,1);
camisa->move(TP);
TP->Equip(camisa,1);
}else{
falda  = clone_object(ROPA("falda"));
    falda->move(TP);
    TP->Equip(falda,1);
    blusa  = clone_object(ROPA("blusa"));
    blusa->move(TP);
TP->Equip(blusa,1);
zapatos = clone_object(ROPA("zapatos"));
    zapatos->move(TP);
    TP->Equip(zapatos,1);
    }
    break;
}//switch
}//vestimenta

 public nomask void ciu_hombrecomun(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_hombrecomun();
        return;
    }
if (member(({"errante", "bree", "ciudad del lago", "valle", "minas tirith", "pelargir",
         "dol amroth", "calembel", "lossarnach"}), str) < 0)
{
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_hombrecomun();
        return;
    }
if (member(({"bree", "ciudad del lago", "valle", "minas tirith", "pelargir",
         "dol amroth", "calembel", "lossarnach"}), str) >= 0)
         TP->SetCitizenship(str);
         else TP->SetCitizenship("errante");
    gremio();
}//ciu_hombrecomun
public nomask void ciu_dunadan(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_dunadan();
        return;
    }
if (member(({"minas tirith", "pelargir", "dol amroth", "refugio dunadan"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_dunadan();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_dunadan

public nomask void ciu_orcocomun(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_orcocomun();
        return;
    }
if (member(({"moria", "minas morgul", "isengard", "gorgoroth"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_orcocomun();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_orcocomun

public nomask void ciu_trasgos(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_trasgos();
        return;
    }
if (member(({"moria", "ciudad de los trasgos"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_trasgos();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_trasgos
public nomask void ciu_uruk(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_uruk();
        return;
    }
if (member(({"minas morgul", "isengard", "gorgoroth"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_uruk();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_uruk
public nomask void ciu_enanos(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_enanos();
        return;
    }
if (member(({"nan naugrim", "errante"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_enanos();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_enanos
public nomask void ciu_barbiluengo(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_barbiluengo();
        return;
    }
if (member(({"nan naugrim", "colinas de hierro", "erebor", "errante"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_barbiluengo();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_barbiluengo
public nomask void ciu_noldo(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_noldo();
        return;
    }
if (member(({"mithlond", "imladris", "lothlorien", "errante"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_noldo();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_noldo
public nomask void ciu_sinda(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_sinda();
        return;
    }
if (member(({"reino de thranduil", "mithlond", "imladris", "lothlorien", "errante"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_sinda();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_sinda
public nomask void ciu_silvano(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_silvano();
        return;
    }
if (member(({"lothlorien", "reino de thranduil"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_silvano();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_silvano
public nomask void ciu_medioelfo(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_medioelfo();
        return;
    }
if (member(({"mithlond", "imladris", "refugio dunadan", "errante"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_medioelfo();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_medioelfo
public nomask void ciu_wose(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_wose();
        return;
    }
if (member(({"bosque de druadan", "cavernas del viejo pukel"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_wose();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_wose
public nomask void ciu_haradan(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_haradan();
        return;
    }
if (member(({"umbar", "estepas de harad"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_haradan();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_haradan
public nomask void ciu_dunlendino(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_dunlendino();
        return;
    }
if (member(({"tierras brunas", "errante"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_dunlendino();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_dunlendino
public nomask void ciu_rohir(string str){
if (!str || str == ""){
        write("\nEscribe alguna de las opciones de la lista.\n");
        input_rohir();
        return;
    }
if (member(({"cuernavilla", "edoras"}), str) < 0){
        write(ANSI_RED+"\nElección incorrecta."+ANSI_NORMAL+"\n");
        input_rohir();
        return;
    }else{
        TP->SetCitizenship(str);
        gremio();
    }
}//ciu_rohir

