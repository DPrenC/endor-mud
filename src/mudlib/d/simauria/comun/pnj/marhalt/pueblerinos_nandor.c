/****************************************************************************
Fichero: pueblerinos_nandor.c
Autor: Ratwor
Fecha: 05/11/2006
Descripción: un pueblerino de ambos sexos para Nandor.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create()
{
    ::create();
    SetSmell("Huele a pueblo.\n");

    switch(d2())
    {
        case 1:
            AddId(({"pueblerino","aldeano"}));
            SetStandard("un aldeano", "humano", ([GC_NINGUNO:10+d6()]), GENDER_MALE);
            SetShort("un aldeano");
            switch(d8())
            {
                case 1:
                    SetLong("Se trata de un aldeano de Nandor que se encuentra paseando "
                    "por la villa.\n Como otros tantos habitantes de la aldea, este "
                    "también trabaja las tierras, pero en este momento debe estar "
                    "descansando.\n");
                    AddId("hombre");
                    break;
                case 2:
                    SetShort("un joven aldeano");
                    SetName("un joven aldeano");
                    SetLong("Es un joven pueblerino de Nandor, guapo, alto y alegre. "
                    "Debería de estar trabajando, pero quizá esté buscando a alguien.\n");
                    AddId("joven");
                    SetStr(QueryStr()+3);
                    break;
                case 3:
                    SetShort("un viejo aldeano");
                    SetName("un viejo aldeano");
                    SetLong("Un viejo pueblerino de la villa de Nandor, ya no tiene el "
                    "cuerpo para trabajar y la verdad es que se nota que lo ha hecho "
                    "duro durante su larga vida.\n");
                    AddId(({"viejo", "anciano", "hombre"}));
                    SetStr(QueryStr()-2);
                    SetCon(QueryCon()-3);
                    SetDex(QueryDex()-3);
                    break;
                case 4:
                    SetShort("un joven aldeano");
                    SetName("un joven aldeano");
                    SetLong("Es un joven alto y musculoso, vestido con pulcritud y de "
                    "piel morena. Por su actitud parece andar sin apuro, seguramente está"
                    " paseando y tomando un poco de aire fresco.\n");
                    AddId("joven");
                    SetStr(QueryStr()+4);
                    break;
                case 5:
                    SetStandard("un niño", "humano", ([GC_TORPE:3 + d3()]), GENDER_MALE);
                    SetShort("un niño");
                    SetLong("Es un niño que mira a todos lados con unos ojitos vivaces "
                    "que parecen verlo y  abarcarlo todo.\n  Tiene la cara y las manos "
                    "sucias del polvo del camino, y más  que caminar, cuando se mueve "
                    "parece avanzar a saltitos.\n");
                    AddId(({"niño", "ninyo", "peque", "pequeño", "pequenyo"}));
                    SetWeight(26000);
                    SetSize(P_SIZE_SMALL);

                    break;
                case 6:
                    SetLong("Es un hombre de mediana edad y cuerpo todavía atlético. "
                    " Adopta una pose firme y tiene la expresión ansiosa de quien "
                    "está por llegar tarde a una cita.\n");
                    AddId("hombre");
                    break;
                case 7:
                    SetLong("Es un hombre ya mayor, aunque conserva en los cabellos "
                    "el color rubio de su juventud. Se mueve con agilidad considerando "
                    "sus años. Va fumando una pipa larga y extraña.\n");
                    AddSubDetail(({"pipa", "pipa extraña"}),"Es una pipa de madera, larga"
                    " y extraña, de la que sale constantemente una columna de humo.\n");
                    AddId("hombre");
                    SetSmell("Huele a tabaco.\n");
                    break;
                case 8:
                    SetShort("un adolescente");
                    SetName("un adolescente");
                    SetLong("Es un adolescente en la flor de la vida en cuyo rostro "
                    "despreocupado puede observarse la determinación que acompaña a sus "
                    "pocos años.\n Tiene el paso alegre, avanzando como si quisiera "
                    "comerse el mundo.\n");
                    AddId(({"adolescente", "joven"}));
                    SetDex(QueryDex()+3);
                    break;
            }
            break;
        case 2:
            AddId(({"humana", "pueblerina","aldeana"}));
            SetStandard("una aldeana", "humano", ([GC_NINGUNO:10+d4()]), GENDER_FEMALE);
            SetShort("una aldeana");
            switch(d8())
            {
                case 1:
                    SetShort("una joven aldeana");
                    SetName("una joven aldeana");
                    SetLong("Se trata de una doncella juvenil que pasea por la villa "
                    "sonriente.\n A veces le oyes canturrear algo en voz baja.\n");
                    AddId(({"joven", "doncella"}));
                    SetSmell("Huele a dulce");
                    break;
                case 2:
                    SetLong("Es una mujer de mediana edad, quizá algo seria, pero no se"
                    " le ve enfadada y parece que goza de buena salud, pues a pesar "
                    "de su edad tiene un buen físico.\n");
                    AddId("mujer");
                    break;
                case 3:
                    SetShort("una vieja aldeana");
                    SetName("una vieja aldeana");
                    SetLong("Es una anciana de la aldea de Nandor que se encuentra "
                    "paseando por los alrededores, quizá esté haciendo algunas compras.\n");
                    AddId(({"vieja", "anciana", "mujer", "señora"}));
                    SetStr(QueryStr()-3);
                    SetCon(QueryCon()-2);
                    SetDex(QueryDex()-3);
                    break;
                case 4:
                    SetLong("Es una mujer madura, con cabellos que ya empiezan a ponerse "
                    "blancos y con un rostro muy dulce. Sus facciones son armoniosas y "
                    "cuando se mueve lo hace lentamente aunque con decisión.\n");
                    AddId(({"mujer", "madura"}));
                    break;
                case 5:
                    SetStandard("una niña", "humano", ([GC_TORPE: 3 + d2()]), GENDER_FEMALE);
                      SetShort("una niña");
                    SetLong("Es una niña pequeña, pelirroja y con cara de pícara. En "
                    "sus grandes ojos azules chispean la curiosidad y el desenfado.\n");
                    AddId(({"niña", "pequeña", "ninya", "pequenya", "pelirroja", "peque"}));
                    SetWeight(26000);
                    SetSize(P_SIZE_SMALL);
                    break;
                case 6:
                    SetShort("una vieja aldeana");
                    SetName("una vieja aldeana");
                    SetLong("Es una anciana de cabello blanco peinados en un rodete y "
                    "mirada perdida. Cuando camina lo hace lentamente, como si el cuerpo le"
                    " pesara.\n");
                    AddId(({"vieja", "anciana", "mujer"}));
                    SetStr(QueryStr()-3);
                    SetCon(QueryCon()-2);
                    SetDex(QueryDex()-3);
                    break;
                case 7:
                    SetShort("una joven aldeana");
                    SetName("una joven aldeana");
                    SetLong("Es una joven de cabellos largos y ojos azabache. Tiene una "
                    "expresión soñadora en el rostro, y parece estar abstraída en sus "
                    "propios pensamientos.\n");
                    AddId("joven");
                    break;
                case 8:
                    SetShort("una joven aldeana");
                    SetName("una joven aldeana");
                    SetLong("Es una joven de pocos años y de ojos vivaces, que miran todo "
                    "con expresión desafiante.\n  Viste ropas llamativas y camina "
                    "contoneándose como para provocar las miradas masculinas.\n");
                    AddId(({"joven", "adolescente", "chica"}));
                    SetSmell("Una suave fragancia a flores sale de su cuerpo.\n");

                    break;
            }
            break;
    }
    SetAlign(75*d3());
    SetWhimpy(15+d20());

    InitAChats(5,({QueryShort()+" grita fuertemente.\n",
        QueryShort()+" intenta escapar.\n", QueryShort()+" grita: ¡déjame en paz!\n"}));

    AddQuestion(({"nandor","nandor","aldea","villa"}), QueryShort()+" te dice: te "
    "encuentras en la villa de Nandor, muy conocida por sus cultivos, su vino, el "
    "gremio de guerreros y el castillo del noble.\n",1);
    AddQuestion(({"noble","castillo"}), QueryShort()+" te dice: el castillo, el noble y "
        "toda su gente la encontrarás al noroeste de la villa.\n",1);
    SetCitizenship("nandor");
    SetGoChance(50);
    AddWalkZones(MARH("nandor"));
if(TO->QuerySize()!=P_SIZE_SMALL){
        if(d2()==1)
            AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":random(3),"plata":d10()])]));
        AddItem(PROT("marhalt/nandor/prenda_superior"),REFRESH_REMOVE,SF(wearme));
        AddItem(PROT("marhalt/nandor/prenda_inferior"),REFRESH_REMOVE,SF(wearme));
    }else{
        AddItem(PROT("marhalt/nandor/prenda_superior_p"),REFRESH_REMOVE,SF(wearme));
    AddItem(PROT("marhalt/nandor/prenda_inferior_p"),REFRESH_REMOVE,SF(wearme));
    }

            InitChats(3, ({QueryShort()+" te mira con curiosidad.\n",
            QueryShort()+" suspira impaciente mientras mira el entorno.\n",
            QueryShort()+" mira a su alrededor.\n"}));
    if (TO->id("chica"))
        InitChats(3, ({QueryShort()+" pestañea mientras te mira.\n",
        QueryShort()+" mira al cielo y hace una mueca.\n",
        QueryShort()+" te mira desafiante.\n",
        QueryShort()+" se toca el pelo coqueta.\n",
        QueryShort()+" te dice: parece que llevas algo de suciedad encima, ¿no?\n"}));          

    if(TO->id("peque"))
        InitChats(3, ({QueryShort()+" sonríe.\n",
        QueryShort()+" se rasca la cabeza.\n",
        QueryShort()+" canturrea algo por lo bajo.\n",
        QueryShort()+" mira al suelo como buscando algo.\n",
        QueryShort()+" te mira con curiosidad.\n",
        QueryShort()+ " se agacha y se vuelve a levantar.\n",
        QueryShort()+" te mira y se ríe a carcajadas.\n"}));          

    if (TO->id("doncella"))
        InitChats(3, ({QueryShort()+" se sonroja al mirarte.\n",
        QueryShort()+" se toca el pelo tímida.\n",
        QueryShort()+" te sonríe y mira hacia otro lado.\n",
      QueryShort()+" se alisa la ropa con las manos.\n"}));

}
