/******************************************/
// Comando para configurar completamente a un Ainur
/******************************************/
#include "/secure/config.h"
#include "/secure/wizlevels.h"
#include <stdrooms.h>
#define STATSAINUR 50
int main() {
    seteuid(getuid());
    string antetitulo;
    object cinturon_orome, manto_orome, botas_orome, tunica_orome, valaroma, lanza_orome;
        object cota_profundidades, tunica_ulmo;
    object guanteletes_tulkas;
    object martillo_aule;
    write("Ajustando la configuración de los Ainur a tu personaje "+CAP(TP->QueryRealName())+"...\n\n");
    TP->command_me("quitarse todo");
    RACEMASTER->InitRace(TP->QueryRealName(),"ainu");
    write("Tu personaje es ahora de la raza "+TP->QueryRace()+".\n");
    TP->SetShort(TP->QueryRealName());
    TP->SetEchoMode(1);
    TP->SetSounds(1);
    TP->SetSoundEnvironment(1);
    TP->SetBrief(1);
write("Activado Sonidos y descripciones cortas.\n");
    TP->SetCitizenship("valmar");
    write("Tu ciudadanía es: "+TP->QueryCitizenship()+".\n");
    /*
    if(IS_MAIA(TP)) CAP(TP->SetPresay("Maia"));
    if (IS_HERALDO(TP)) CAP(TP->SetPresay("Heraldo"));
    if (IS_VALA(TP)) CAP(TP->SetPresay("Vala"));
    if (IS_ARATAR(TP)) CAP(TP->SetPresay("Aratar"));
*/

    switch(TP->QueryRealName()){
        case "orome":
            TP->SetRazabase("humano");
            TP->SetTitle("El Señor de los Bosques");
            TP->SetLong("Oromë es un vala alto y señorial, en cuyo noble rostro reside aún la antigua luz de Valinor, y en cuyos ojos de mirada franca y tranquila reside la sabiduría de miles de centurias. Grande es el poder que se intuye en él, pues es el gran cazador de los Valar, quien más ha combatido a las criaturas de Morgoth en eras pasadas y uno de los Valar más amados por Elfos y Hombres.\n");
            TP->SetHome("/d/aman/comun/habitacion/valinor/valmar/ciudad/hab_orome");
                TP->SetGender(1);
if(present("valaroma",TP)) valaroma=present("valaroma",TP);
    else {
        valaroma=clone_object("/d/aman/comun/objeto/otro/valaroma");
        valaroma->move(TP);
    }
    if(present("botas_orome",TP)) botas_orome=present("botas_orome",TP);
    else {
        botas_orome=clone_object("/d/aman/comun/objeto/proteccion/botas_orome");
        botas_orome->move(TP);
    }
    if(present("tunica_orome",TP)) tunica_orome=present("tunica_orome",TP);
    else {
        tunica_orome=clone_object("/d/aman/comun/objeto/proteccion/tunica_orome");
        tunica_orome->move(TP);
    }
    if(present("cinturon_orome",TP)) cinturon_orome=present("cinturon_orome",TP);
    else {
        cinturon_orome=clone_object("/d/aman/comun/objeto/proteccion/cinturon_orome");
        cinturon_orome->move(TP);
    }
    if(present("manto_orome",TP)) manto_orome=present("manto_orome",TP);
    else {
        manto_orome=clone_object("/d/aman/comun/objeto/proteccion/manto_orome");
        manto_orome->move(TP);
    }
    if(present("lanza_orome",TP)) lanza_orome=present("lanza_orome",TP);
    else {
        lanza_orome=clone_object("/d/aman/comun/objeto/arma/valinor/lanza_orome");
        lanza_orome->move(TP);
    }
    TP->Equip(valaroma,1);
    TP->Equip(botas_orome,1);
    TP->Equip(tunica_orome,1);
    TP->Equip(manto_orome,1);
    TP->Equip(cinturon_orome,1);
    TP->Equip(lanza_orome,1);
            break;
        case "aule":
            TP->SetRazabase("enano");
            TP->SetTitle("El Vala herrero, padre de los enanos");
            TP->SetLong("Te encuentras ante Aulë, el poderoso vala herrero. Ha elegido una vestidura mortal algo distinta a la de sus hermanos, pues aunque alto y de aspecto noble, más allá de lo que cualquier mortal podría ser, su aspecto es más fornido y rotundo, algo que le ayuda en sus grandes trabajos de forja. Siempre ocupado en nuevas obras, Aulë fue el creador de la raza de los Enanos, quienes le rinden adoración incondicional.\n");
            TP->SetHome("/d/aman/comun/habitacion/valinor/valmar/ciudad/hab_aule");
                TP->SetGender(1);
            if(present("martillo_aule",TP)) martillo_aule=present("martillo_aule",TP);
    else {
        martillo_aule=clone_object("/d/aman/comun/objeto/arma/valinor/martillo_aule");
        martillo_aule->move(TP);
    }
    TP->Equip(martillo_aule,1);
            break;
        case "ulmo":
            TP->SetRazabase("humano");
            TP->SetTitle("El Señor de las Aguas");
            TP->SetLong("Te encuentras ante el poderoso Vala Ulmo, señor de todas las aguas corrientes y dueño de todos los mares. Es una presencia impresionante, una figura alta y poderosa como una gran ola a punto de romper. En sus ojos de mirada profunda como las cavernas abisales reside una gran sabiduría sobre lo pasado, lo presente y lo futuro. Es un Vala solitario, que prefiere la soledad a la compañía de los demás miembros de su estirpe y que siempre ha protegido y defendido a elfos y hombres en sus largas guerras con los Poderes Oscuros.\n");
        TP->SetHome("/d/aman/comun/habitacion/valinor/valmar/ciudad/hab_ulmo");
            TP->SetGender(1);
        if(present("tunica_ulmo",TP)) tunica_ulmo=present("tunica_ulmo",TP);
    else {
        tunica_ulmo=clone_object("/d/aman/comun/objeto/proteccion/tunica_ulmo");
        tunica_ulmo->move(TP);
    }
    if(present("cota_ulmo",TP)) cota_profundidades=present("cota_ulmo",TP);
    else {
        cota_profundidades=clone_object("/d/aman/comun/objeto/proteccion/cota_profundidades");
        cota_profundidades->move(TP);
    }
TP->Equip(tunica_ulmo,1);
TP->Equip(cota_profundidades,1);
            break;
        case "tulkas":
            TP->SetRazabase("enano");
            TP->SetTitle("El campeón de los Maiar");
            TP->SetLong("Te encuentras ante Tulkas, el poderoso campeón de Valinor, quien descendió a Arda entre risas en los tiempos antiguos para enfrentarse a Melkor. Es más alto que la mayoría de los Valar, y posee una constitución física impresionante. En su noble rostro no percibes la misma sabiduría que en el resto de los Valar, pero en sus ojos reside una lealtad y nobleza incuestionables.\n");
TP->SetHome("/d/aman/comun/habitacion/valinor/valmar/ciudad/hab_tulkas");
    TP->SetGender(1);
if(present("guanteletes_tulkas",TP)) guanteletes_tulkas=present("guanteletes_tulkas",TP);
    else {
        guanteletes_tulkas=clone_object("/d/aman/comun/objeto/proteccion/guanteletes_tulkas");
        guanteletes_tulkas->move(TP);
    }
TP->Equip(guanteletes_tulkas,1);
            break;
            case "melkor":
            TP->SetRazabase("humano");
            TP->SetTitle("Morgoth, Señor de Angband");
            TP->SetHome(INICIO);
                TP->SetGender(1);
                SetBando(2);
            break;
        default:
            TP->SetRazabase("humano");
            TP->SetTitle("Servidor de Eru");
            TP->SetHome(INICIO);
                TP->SetGender(1);
            break;
        }

write("Tu Raza Base es: "+TP->QueryRazabase()+".\n");
write("Se te entrega y equipa las vestimentas y equipo que se te ha asignado según tu personaje.\n");
TP->SetStr(STATSAINUR);
TP->SetCon(STATSAINUR);
TP->SetDex(STATSAINUR);
TP->SetInt(STATSAINUR);
TP->SetWis(STATSAINUR);
TP->SetCha(STATSAINUR);
write("Todos tus stats se han ajustado a "+STATSAINUR+".\n");

write("Se traslada a tu personaje a la room inicial que se te ha asignado.\n");
TP->command_me("casa");

    write("Si todo ha salido bien, ya tienes tu personaje\n "+TP->QueryPresay()+" "+
    CAP(TP->QueryRealName())+" "+TP->QueryTitle()+"\n con sus características bien ajustadas.\n");
   return 1;
}
