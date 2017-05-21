/*
DESCRIPCION : ermita de berat
FICHERO     : /d/simauria/comun/habitacion/simauria/berat/ermita
MODIFICACION: 4-11-99 [Icaro] Vuelvo a robar para Berat
[Maler] si, y vuelves a robar mal, tie webos
[Maler] introduzco a arandil, tio de quest
[k] Karu añade Detalles de retablo y paredes y funcion para trepar.
May'2002 [Nemesis] La madre que sus parió. Rehace por completo las
                   descripciones para que no incluyan a ningún wiz.
                   Obviamente, ya NO es una ermita.
-------------------------------------------------------------------
NOTAS:
 [n] Se meterá 1 punto de exploración si se miran las armas de los Gigantes
     por su nombre real. Para ello, por supuesto, habrá que "investigar" en
     alguna biblioteca. Y antes de ello, obviamente, habrá que escribir los
     libros correspondientes. Pero todo llegará, lo prometo...
*/
#include "./path.h"
#include <moving.h>
#include <skills.h>
#include <combat.h>
#include <sounds.h>
#define QPROY(x) "/guilds/hechiceros/quest/proyectilelectrico/"+x

inherit SIM_ROOM;
public void snd_caida();
create(){
    ::create();
    SetLocate("berat");
    SetIntShort("el templo de Toolam");
    SetIntLong("Te encuentras en el templo dedicado a Toolam, el dios del Viento. "
    "Sendas hileras de columnas flanquean el pasillo que conduce hasta el altar "
    "del dios, situado bajo una bóveda sostenida por cuatro estatuas a guisa de "
    "columnas. Tras el altar puedes ver una enorme estatua del dios, y tras ésta un gran "
    "retablo que sin duda representa algunas de sus proezas. El templo "
    "se encuentra bien iluminado, gracias a la luz que entra por unas hermosas "
    "vidrieras y también a la multitud de lámparas encendidas en honor del dios.\n");
    SetIntBright(45);

    SetIntNoise("Escuchas el crepitar de las llamas de las innumerables lámparas que "
    "hay en la ermita.\n");
    SetIntSmell("Huele a incienso.\n");

    AddDetail(({"lámparas","lamparas"}),
     "Han sido encendidas en honor del dios. Debe ser una divinidad muy querida.\n");
    AddDetail(({"cristales", "vidrieras"}),
    "Representan algunos pasajes de la vida del dios Toolam.\n");
    AddDetail(({"estatua"}), "Hay varias estatuas: la del dios y otras cuatro.\n");
    AddDetail(({"estatua del dios","estatua enorme","enorme estatua","estatua de Toolam"}),
    "Es la estatua de Toolam, el dios del viento. Es un dios al que las gentes "
    "de Berat tienen en gran estima.\n");
    AddDetail(({"cúpula","bóveda", "cupula", "boveda"}),
    "Parece representar un cielo cuajado de estrellas.\n");
    AddDetail(({"cuatro estatuas", "4 estatuas"}),
    "Son las estatuas de los cuatro hijos de Toolam, los Gigantes de los Vientos: "
    "Gormoth, Tanuk, Guirin y Domin. Tienen los brazos levantados como si sostuvieran "
    "el firmamento con ellos.\n");

    AddDetail(({"Gormoth","gormoth","estatua de Gormoth","estatua de gormoth"}),
    "Una de las columnas que sostienen la bóveda está tallada en la figura "
    "de Gormoth, el Gigante del Viento del Norte. Lleva un casco con cuernos y luce "
    "una larga barba recogida en dos trenzas. De su cinturón cuelga un enorme "
    "martillo de guerra.\n");
    AddDetail(({"martillo","martillo de guerra","martillo de Gormoth","martillo de gormoth"}),
    "Es el arma con la que se suele representar a Gormoth.");

    AddDetail(({"Tanuk","tanuk","estatua de Tanuk","estatua de tanuk"}),
    "Una de las columnas que sostienen la bóveda está tallada en la figura "
    "de Tanuk, el Gigante del Viento del Sur. Sonríe enigmáticamente detrás "
    "de sus espesos bigotes, como si algo le divirtiera. La empuñadura de una "
    "espada asoma de una vaina en su espalda.\n");
    AddDetail(({"espada","espada de Tanuk","espada de tanuk"}),
    "Es el arma con la que se suele representar a Tanuk.");

    AddDetail(({"Guirin","guirin","estatua de Guirin","estatua de guirin"}),
    "Una de las columnas que sostienen la bóveda está tallada en la figura "
    "de Guirin, el Gigante del Viento del Este. Luce un manto con capucha y "
    "te llaman la atención sus orejas puntiagudas, parecidas a las de los elfos "
    "Junto a él hay tallado un arco largo y de su cinto cuelga un carcaj vacío.\n");
    AddDetail(({"arco","arco de Guirin","arco de guirin"}),
    "Es el arma con la que se suele representar a Guirin.");

    AddDetail(({"Domin","domin","estatua de Domin","estatua de domin"}),
    "Una de las columnas que sostienen la bóveda está tallada en la figura "
    "de Domin, el Gigante del Viento del Oeste. Lleva una larga capa que va desde "
    "sus poderosos hombros hasta casi rozar el suelo. Junto a él hay clavada una "
    "inmensa lanza.\n");
    AddDetail(({"lanza","inmensa lanza","lanza de Domin","lanza de domin"}),
    "Es el arma con la que se suele representar a Domin.");

    AddDetail(({"pared","paredes"}),
    "Las paredes están adornadas con hermosos relieves y tapices.\n");
    AddDetail("relieves",
    "Son hermosos relieves que representan al dios en distintos pasajes de su vida.\n");
    AddDetail("tapices",
    "Sin duda son ofrendas de las familias acomodadas de la ciudad al dios, "
    "ya que en muchos de ellos puedes ver divisas y escudos familiares.\n");
    AddDetail(({"tapizes"}),
    "No. No se escribe 'tapizes', sino TAPICES. A ver si hacemos el favor de "
    "aprender a escribir...\n");
    AddDetail("retablo",
    "Hay un retablo en una de las paredes, tan grande que casi "
    "llega hasta el techo, pero puedes ver que hay un hueco arriba.\n");
    AddDetail("hueco","Hay un hueco encima del retablo. Está muy alto.\n");

    AddRoomCmd("rezar","cmd_rezar");
    AddRoomCmd("trepar","ftrepar");
    AddItem(QPROY("arandil"),REFRESH_DESTRUCT);
    AddExit("oeste","cprin7");
    AddExit("norte","calle3");
    AddDoor("oeste", "la puerta principal",
    "Es una puerta de mediano tamaño, de madera maciza y lisa, da a la calle principal "
    "de Berat.\n", ({"puerta", "puerta del oeste", "puerta pricipal"}));
    AddDoor("norte", "la puerta trasera",
    "Es una puerta normal que da a un callejón.\n",
    ({"puerta", "puerta trasera", "puerta del norte"}));
}

init(){
    ::init();
    call_out("andar_templo", 1);
}

public void andar_templo(){
    tell_room(SIMA("berat/retablo"), CAP(TNAME)+" se encuentra cerca del retablo.\n");
}

int cmd_rezar(string str)
{
    if (!str || (str = LOWER(str)) != "a toolam")
		return notify_fail("¿A quien quieres rezar? solo hay un dios que te escucha.\n");
	say(CAP(TNAME)+ " le reza a Toolam.\n");
	if(TP->QueryRace()=="humano"){
	    TP->SetSmell("Desprende un suave y fresco aroma.\n");
	    write("Notas una suave brisa que procede de la estatua del dios. Te sientes "
    	"mucho más refrescad" + TP->QueryGenderEndString() + ".\n");
	    if(TP->QueryAlign()<0){
	        TP->SetAlign(TP->QueryAlign()+(TP->QueryInt()*2));
	        return 1;
	    }
	    else if(TP->QueryAlign()>=200 && TP->QueryHP()<TP->QueryMaxHP()){
	        TP->AddHP(random(TP->QueryInt()+TP->QueryCon()));
	        return 1;
	    }
	    return 1;
	}
	return  notify_fail("Rezas un rato, pero no ocurre nada.\n",NOTIFY_NOT_VALID);
}

int ftrepar(string str){

    if(TP->QueryTP()<0)
        return notify_fail("Necesitas descansar.\n", NOTIFY_NOT_VALID);
	if (str=="retablo")
	{
		if (TP->UseSkill(HAB_TREPAR)<5)
		{
			write("Empiezas a trepar por el retablo... pero de repente "
			"pierdes el equilibrio y caes al duro suelo.\n");
			say(CAP(TNAME)+" comienza a trepar por el retablo, "
			"pero pierde el equilibrio y cae al duro suelo.\n",TP);
			tell_room(SIMA("berat/retablo"), CAP(TNAME)+" intenta trepar el retablo para "
			"llegar hasta aquí, pero vuelve a caer duramente al suelo.\n");
			tell_room(SIMA("berat/hueco"), CAP(TNAME)+" intenta trepar el retablo, pero "
			"cae al suelo del templo a mitad de camino.\n");
			TP->Defend(15,TD_APLASTAMIENTO,DEFEND_NOMSG);
            snd_caida();
			TP->AddTP(-d2());
			return 1;
		}
		else
		{
			TP->move(SIMA("berat/retablo"),M_SPECIAL,({
				"trepa hasta lo más alto del retablo sin problemas",
        "llega trepando desde abajo",
      	"Consigues trepar hasta lo alto del retablo.."
			}));
			TP->AddTP(-d2());
			tell_room(SIMA("berat/hueco"), CAP(TNAME)+
			" consigue trepar hasta lo alto del retablo, desde el templo, sin problemas.\n");
			return 1;
		}
	}
	else
	{
		notify_fail("¿Trepar <qué>?\n");
		return 0;
	}
return 0;
}

public void snd_caida(){
    object retablo = find_object(SIMA("berat/retablo"));
    object hueco = find_object(SIMA("berat/hueco"));
    play_sound(TO, SND_SUCESOS("caida_fuerte"));
    play_sound(({retablo, hueco}), SND_SUCESOS("caida_fuerte"), 0, 60);
}
