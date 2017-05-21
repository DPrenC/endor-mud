/**
 * /obj/virtualmaster.c
 */

#include <config.h>

//--- compile_object control --------------------------------------------------------
// ejemplos de filename:
// "/weapon/longsword"
// "/armour/full plate"
public object compile_object(string filename) {
    string name, type;
    object ob;

    name = explode(explode(filename,"/")[<1],".")[0];
    type = explode(explode(filename,"/")[<2],".")[0];

    dtell("nyh",sprintf("VIRTUALMASTER: compile_object(%O)\n"
                        "               type = %O\n"
                        "               name = %O\n"
                        , filename, type, name )
         );
/*
    switch(type)
    {
        case "weapon":  ob = WEAPONMASTER->compile_object(name);
                        break;
        case "armour":  ob = ARMOURMASTER->compile_object(name);
                        break;
    }
*/
    dtell("nyh",sprintf("               ob   = %O\n" , ob ) );

    return ob;
}
