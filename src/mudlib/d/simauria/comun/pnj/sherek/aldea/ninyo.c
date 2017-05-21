/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/aldea/ninyo.c
Autor: Lug y Yalin
Fecha: 16/08/2006
Descripción: Niño jugando en la pradera
****************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;
#define SEX (gen==2?"a":"o")

//variables
string nom, rnom, cp, pelo, pelo2, co, ojos, imagen, cdd;
int gen, edad;

private int NoLucho();
//genera los datos aleatorios básicos
void configura()
{
    edad = 7+d6();
    switch(d2())
    {
        case 1:
            nom = "una niña";
            gen = GENERO_FEMENINO;
            rnom = "la niña";
            AddId(({"niña","ninya"}));
        break;
        case 2:
            nom = "un niño";
            gen = GENERO_MASCULINO;
            rnom = "el niño";
            AddId(({"niño","ninyo"}));
        break;
    }
    switch(d4())
    {
        case 1:
            cp = "rubio";
        break;
        case 2:
            cp = "negro";
        break;
        case 3:
            cp = "castaño";
        break;
        case 4:
            cp = "rojo";
        break;
    }
    switch(d3())
    {
        case 1:
            pelo = "corto";
        break;
        case 2:
            pelo = "largo";
        break;
        case 3:
            pelo ="fino";
        break;
    }
    switch(d3())
    {
        case 1:
            pelo2 = "rizado";
        break;
        case 2:
            pelo2 = "liso";
        break;
        case 3:
            pelo2 = "suave";
        break;
    }
    switch(d4())
    {
        case 1:
            co = "azules";
        break;
        case 2:
            co = "verdes";
        break;
        case 3:
            co = "negros";
        break;
        case 4:
            co = "marrones";
        break;
    }
    switch(d3())
    {
        case 1:
            ojos = "atentos";
        break;
        case 2:
            ojos = "profundos";
        break;
        case 3:
            ojos = "melancólicos";
        break;
    }
    return;
}
                                
// monta la descripción
string describe()
{
    imagen = "Es "+nom+" de unos "+edad+" años, de pelo "+cp+", "+pelo+" y "+pelo2+
    ", y unos "+ojos+" ojos "+co+".\n";
    switch(gen)
    {
        case 1:
            imagen += "De su cara sonriente, aún no han desaparecido la mirada pícara y la "
                "traviesa expresión propias de su edad, aunque sus manos muestran ya las señales "
                "de su colaboración en el trabajo de la granja y los campos.\n";
        break;
        case 2:
            imagen += "Su dulce carita aún no ha perdido la radiante sonrisa y la mirada "
                "curiosa de las niñas que aún sólo piensan en juegos y hadas, si bien sus manos "
                "tienen ya las marcas del trabajo doméstico, para el que sin duda se la "
                "prepara y condiciona.\n";
        break;
    }
    switch(d3())
    {
        case 1:
            imagen +=     "Aunque está bastante suci"+SEX+" de jugar con la tierra y la "
                "hierba, puede adivinarse que es bastante guap"+SEX+".\n";
        break;
        case 2:
            imagen += "Parece algo acalorad"+SEX+" y descompuest"+SEX+" en su atuendo, dando "
                "la impresión de haber estado practicando algún juego agitado.\n";
        break;
        case 3:
            imagen += "Sus reposados movimientos y la serenidad de su rostro indican sin duda "
                "que da un ocioso paseo meditando en sus cosas.\n";
        break;
    }
    switch(d2())
    {
        case 1:
            imagen += "Parece disfrutar felizmente de un tiempo de merecido descanso.\n";
        break;
        case 2:
            imagen+="Parece estar alerta, y mira frecuentemente hacia el pueblo, lo que te hace "
                "pensar que en realidad no tiene permiso para estar aquí";
            if (edad <= 9) imagen+=", y su actitud de continuo sobresalto muestra bien a las "
                "claras que es la primera vez que hace novillos.\n";
            else imagen+=", aunque no parece importarle demasiado.\n";
        break;
    }
    return imagen;
}
          
string dialogo()
{
    string ret;
    switch(d3())
    {
        case 1:
            ret = capitalize(rnom)+" te mira y dice: ¿Tienes familia aquí, o has "
                "venido a trabajar?\n";
        break;
        case 2:
            if (gen == GENDER_MALE) ret = capitalize(rnom)+" se hurga la nariz con el dedo.\n";
            else ret = capitalize(rnom)+" se arregla el pelo con coquetería.\n";
            break;
        case 3:
            ret = capitalize(rnom)+" te dice: ¿Vienes de "+cdd+"? Me gustaría visitar "+cdd+
                " algún día. Mi familia vino de allí.\n";
        break;
    }
    return ret;
}

create()
{
    ::create();
    configura();
    SetStandard(nom,"humano",10,gen);
    AddId(({"to_delete"}));
    SetChkFightFunction(SF(NoLucho));
    SetChkMagicFunction(SF(NoLucho));
    SetShort(nom);
    SetLong(describe());
    SetHP(QueryMaxHP());
    SetAlign(2000);
    SetNoGet(capitalize(rnom)+" dice: Soy muy pequeñ"+SEX+" aún. Si intentas hacerme cosas, "
        "llamaré a un guardia.\n");
    SetCitizenship("sherek");
    SetGoChance(50);
    AddWalkZones(SHERALD("pradera"));
    string *villa=({"nandor","Berat","Koek","Gorat","enalel","Krigor"});
    cdd = villa[random(6)];
    switch(d3())
    {
        case 1:
            InitChats(5,({capitalize(rnom)+" mueve la cabeza, y con voz misteriosa te dice: "
                "¿Sabes? El otro día vi a Marath entrar en el cementerio, pero él no tiene "
                "familia allí, ¡qué raro...!",
            SF(dialogo)}));
        break;
        case 2:
            InitChats(5,({        capitalize(rnom)+" frunce el ceño y dice: Marath también es "
                "forastero, pero sepasa el día en la taberna. Mi padre dice que no se sabe "
                "de qué vive.\n",
            SF(dialogo)}));
        break;
        case 3:
            InitChats(5,({capitalize(rnom)+" te dice en un susurro: Me da miedo Marath. Ayer "
                "le vi entrar en el cementerio y le seguí de lejos, pero cuando entré, no "
                "estaba... ¿Sabes?, creo que es un fantasma...\n",
            SF(dialogo)}));
        break;
    }
}

NoLucho(object agresor)
{
    if (agresor->QueryGuildLevel() <= 30) return notify_fail(capitalize(rnom)+" te mira con "
        "carita de pena, y con lágrimas en los ojos te dice: ¡No me pegues, "
        "por favor, no me pegueees!\nSientes como tu corazón se encoge, y "
        "decides dejarle y pedirle perdón.\n",NOTIFY_NOT_VALID);
    object obj, env;
    env = environment(TO);
    obj = present("guardian",env);
    if (!obj || !living(obj))
    {
        obj=clone_object(PNJ("sherek/aldea/guardian"));
        obj->move(env);
        say(capitalize(rnom)+" grita: ¡Señor guardia! ¡señor guardia!\nAl momento un "
            "guardia llega corriendo a ver qué ocurre, lo que aprovecha "+
            nom+" para salir disparad"+SEX+".\n");
    }
    else
    {
        write(capitalize(rnom)+" sale corriendo, y te deja que te apañes con el guardián.\n");
        say("El niño sale corriendo, dejando que "+capitalize(agresor->QueryName())+" se las "
            "componga con el guardián.\n",agresor);
    }
    obj->Kill(agresor || PO);
    notify_fail("El guardia te grita: ¿Es que no tienes vergüenza? ¡Atacar a un niño! ¡Yo te "
        "enseñaré, cobarde! E inmediatamente carga contra ti.\n");
    return remove(),0;
}
