
#include "./path.h"

inherit SIM_ROOM;
hacer_coger(string cad1){
object ob;
string donde;
string str;
if (!cad1) {
write("uso coger <que>\n");
return 1;}
if (cad1=="arena"){
ob=clone_object("/d/simauria/comun/objeto/otro/arena");
ob->move(TP);
write("Coges un puñado de arena de playa.\n");
}else{
write("No puedes coger eso.\n");
}//cad1
return 1;
}
create () {
  ::create();
SetLocate("Islote de Gorat");
SetIntShort("la playa del islote de Gorat");
SetIntLong(
"Estás en el este de la playa del islote de Gorat, al fondo ves el "
"continente de Simauria, y las playas de Gorat, con su majestuoso faro "
"iluminando toda la bahía. "
"Al norte, noroeste y noreste sigue el islote y en las demás direcciones "
"tienes agua.\n");
AddDetail("arena","Es arena de playa más blanca de lo normal.\n");
//aqui clonar arena
SetIndoors(0);
AddExit("oeste","estatua");
AddExit("noroeste","playan");
AddExit("sudoeste","playas");
}
init(){
add_action("hacer_coger","coger");
::init();}
