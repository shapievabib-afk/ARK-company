#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <filesystem>
#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#include <limits.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#include <limits.h>
#endif

using namespace std;

int global_sharpness = 0;
int global_level = 0;
string global_sword_name = "";

////////////////////// сделано нейронкой

std::string getExecutableDir() {
#ifdef _WIN32
    char path[MAX_PATH];
    GetModuleFileNameA(nullptr, path, MAX_PATH);
    return std::filesystem::path(path).parent_path().string();
#elif defined(__linux__)
    char path[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", path, sizeof(path)-1);
    if (len != -1) {
        path[len] = '\0';
        return std::filesystem::path(path).parent_path().string();
    }
#elif defined(__APPLE__)
    char path[PATH_MAX];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        return std::filesystem::path(path).parent_path().string();
    }
#endif
    // fallback – вернуть текущую рабочую директорию
    return std::filesystem::current_path().string();
}

////////////////////// сделано нейронкой

class Swords
{
public:

int sharpness;
int lvl;
string rare;

    Swords()
    {
        sharpness = 0;
        lvl = 0;
        rare = "none";
    }
        void callSword() {
            cout << "Lets pick a sword" << endl;
            cout << "At first, choose a rare class:" << endl;
            cout << "Low - Z" << endl;
            cout << "Medium - X" << endl;
            cout << "High - C" << endl;
        }
};

class medium : public Swords
{
    public:
    medium()
    {
        this->rare = "medium";}
        void M()
        {
        cout << "Medium? It's somewhere in the middle..."<< endl;
        cout << "                            "<<endl;
        cout << "----------------------------"<< endl;
        cout << "                            "<<endl;
        cout << "Now choose a rare: " << endl;
        cout << "Light red rare - Z"<<endl;
        cout << "pink rare - X"<<endl;
        cout << "light purple rare - C"<<endl;
        cout << "lime rare - V"<<endl;
      }
};

class Low: public Swords
{
public:
    Low()
    {
        this->rare = "Low";
    }
        void lowcall(){
        cout<<"Now choose a rare:"<<endl;
        cout<<"White rare - Z, Blue rare - X, Orange rare - C, Green rare - V"<<endl;
        }

};

class High: public Swords
{
public:
    High()
    {
        this->rare = "high";
    }
    void callHigh(){
        cout<<"Now choose a rare:"<<endl;
        cout<<"Yellow rare - Z, Red rare - X"<<endl;
    }

};

class White: public Low
{
public:
    White()
    {
        this->rare = "White";
    }
    void callWhite()
    {
        cout<<"Great, you choose white rare, rather dumb idea, heh"<<endl;
        cout<<"it`s time to take your sword and rush into a battle"<<endl;
        cout<<"The ebony sword - 1, The silver dagger - 2"<<endl;
        cout<<"a palm tree sword - 3, The cactus sword - 4"<<endl;
        cout<<"The copper dagger - 5, Wooden sword - 6"<<endl;
        cout<<"Dark wood sword - 7"<<endl;
    }
};

class Blue: public Low
{
public:
    Blue()
    {
        this->rare = "Blue";
    }
    void callBlue()
    {
        cout<<"Great, you choose blue rare, you really love tryharding, yeah?"<<endl;
        cout<<"it`s time to take your sword and rush into a battle"<<endl;
        cout<<"Umbrella - 1, Caramel sword - 2"<<endl;
        cout<<"The scourge of light - 3, The Bloody Ripper - 4"<<endl;
        cout<<"The white laser sword - 5, Gladius - 6"<<endl;
    }
};

class Orange: public Low
{
public:
    Orange()
    {
        this->rare = "Orange";
    }
    void callOrange()
    {
        cout<<"Great, you choose orange rare, you really love to show off, yeah?"<<endl;
        cout<<"it`s time to take your sword and rush into a battle"<<endl;
        cout<<"Volcane- 1, Beekeeper - 2"<<endl;
        cout<<" The edge of the night- 3,An elegant cane  - 4"<<endl;
        cout<<"The bone sword- 5,The grass blade - 6"<<endl;
    }
};

class Green: public Low
{
public:
    Green()
    {
        this->rare = "Orange";
    }
    void callGreen()
    {
        cout<<"Great, you choose Green rare, not bad"<<endl;
        cout<<"it`s time to take your sword and rush into a battle"<<endl;
        cout<<"muhophagus - 1, a spiky tentacle- 2"<<endl;
        cout<<"Zhvalo sword - 3, Muramasa - 4"<<endl;
        cout<<"The mouse baseball bat- 5,glove with blades - 6"<<endl;
    }
};

class Light_red : public medium
{
    public:
    Light_red()
    {
        this->rare = "Light_red";


    }
    void M1()
    {
        cout << "Light red. It's almost red, but a little lighter"<< endl;
        cout << "                            "<<endl;
        cout << "----------------------------"<< endl;
        cout << "                            "<<endl;
        cout << "Now choose a Sword: " << endl;
        cout << "The adamantine sword - 1"<<endl;
        cout << "White Laser Saber - 2"<<endl;
        cout << "The Destroyer Blade - 3"<<endl;
        cout << "The Cobalt Sword - 4"<<endl;
        cout << "Elucidator and Dark Repulser - 5"<<endl;
        cout << "The Mithril Sword - 6"<<endl;

    }
};

class pink : public medium
{
    public:
    pink()
    {
        this->rare = "pink";


    }
    void M2()
    {
        cout << "Pink is a very cute color"<< endl;
        cout << "                            "<<endl;
        cout << "----------------------------"<< endl;
        cout << "                            "<<endl;
        cout << "Now choose a Sword: " << endl;
        cout << "Lambent Light - 1"<<endl;
        cout << "The Ice Spit - 2"<<endl;
        cout << "Dragon Slayer - 3"<<endl;
        cout << "Excalibur - 4"<<endl;
        cout << "sharp-tongued sword - 5"<<endl;
        cout << "The Sower - 6"<<endl;
    }
};

class light_purple : public medium
{
    public:
    light_purple()
    {
        this->rare = "light_purple";

    }
    void M3()
    {
         cout << "My favorite jacket was light purple. Oh, how nostalgic"<< endl;
        cout << "                            "<<endl;
        cout << "----------------------------"<< endl;
        cout << "                            "<<endl;
        cout << "Now choose a Sword: " << endl;
        cout << "The Scythe of Death - 1"<<endl;
        cout << "The thing - 2"<<endl;
    }
};

class lime_rare : public medium
{
    public:
    lime_rare()
    {
        this->rare = "lime rare";

    }
    void M4()
    {
        this->rare = "lime rare";
        cout << "I don't like citrus fruits, ugh"<< endl;
        cout << "                            "<<endl;
        cout << "----------------------------"<< endl;
        cout << "                            "<<endl;
        cout << "Now choose a Sword: " << endl;
        cout << "The Chlorophytic saber - 1"<<endl;
        cout << "Chlorophytic claymer - 2"<<endl;
        cout << "Khalid's sword - 3"<<endl;
    }
};

class red : public medium
{
    public:
    red()
    {
        this->rare = "red";

    }
    void M5()
    {
       cout << "red. Not read. Red. Blood. Rage......"<< endl;
        cout << "                            "<<endl;
        cout << "----------------------------"<< endl;
        cout << "                            "<<endl;
        cout << "Now choose a Sword: " << endl;
        cout << "Meowmoor - 1"<<endl;
        cout << "Star fall - 2"<<endl;
    }
};

class Yellow: public High
{
public:
    Yellow()
    {
        this->rare = "Yellow";
    }
    void callYellow(){
        cout<<"Great, you choose Yellow rare, you really love to show off, yeah?"<<endl;
        cout<<"it`s time to take your sword and rush into a battle"<<endl;
        cout<<"The Christmas tree sword - 1, The true Excalibur- 2"<<endl;
        cout<<"The Horseman's blade - 3, The key-sword - 4"<<endl;
        cout<<"The maniac's knife- 5,The soaring dragon - 6"<<endl;
    }
};

class Ebony: public White
{
public:
    Ebony()
    {
        sharpness = 1;
        lvl = 1;
        cout<<"Normal ebony sword"<<endl;
    }
};

class Silver_Dag: public White
{
public:
    Silver_Dag()
    {
        sharpness = 2;
        lvl = 1;
        cout<<"Wow, rather sharp"<<endl;
    }
};

class Palm: public White
{
public:
    Palm()
    {
        sharpness = 2;
        lvl = 2;
        cout<<"Smells like a coconout"<<endl;
    }
};

class Cactus: public White
{
public:
    Cactus()
    {
        sharpness = 1;
        lvl = 3;
        cout<<"Ouch!"<<endl;
    }
};

class Copper: public White
{
public:
    Copper()
    {
        sharpness = 3;
        lvl = 2;
        cout<<"Sharp, but... This sword is too soft, can easily brake"<<endl;
    }
};

class Wooden: public White
{
public:
    Wooden()
    {
        sharpness = 3;
        lvl = 3;
        cout<<"like in a childhood"<<endl;
    }
};

class Dark_Wooden: public White
{
public:
    Dark_Wooden()
    {
        sharpness = 4;
        lvl = 3;
        cout<<"Something darker than childhood"<<endl;
    }
};
//Синие мечи

class Umbrella: public Blue
{
public:
    Umbrella()
    {
        sharpness = 3;
        lvl = 3;
        cout<<"In case of heavy rain, push the red button"<<endl;
    }
};

class Caramel: public Blue
{
public:
    Caramel()
    {
        sharpness = 4;
        lvl = 4;
        cout<<"Like a real candy!"<<endl;
    }
};

class Scourge_of_Light: public Blue
{
public:
    Scourge_of_Light()
    {
        sharpness = 3;
        lvl = 5;
        cout<<"Wanna kill someone?"<<endl;
    }
};

class Bloody_ripper: public Blue
{
public:
    Bloody_ripper()
    {
        sharpness = 7;
        lvl = 4;
        cout<<"It smells... like a death"<<endl;
    }
};

class White_Laser: public Blue
{
public:
    White_Laser()
    {
        sharpness = 5;
        lvl = 6;
        cout<<"I am your father! Noooooo"<<endl;
    }
};

class Gladius: public Blue
{
public:
    Gladius()
    {
        sharpness = 7;
        lvl = 7;
        cout<<"No, this Gladius is not from portal2"<<endl;
    }
};
//ОРАНЖЕВЫЕ МЕЧИ

class Volcane: public Orange
{
public:
    Volcane()
    {
        sharpness = 2;
        lvl = 10;
        cout<<"Huff, it`s hot"<<endl;
    }
};

class Beekeeper: public Orange
{
public:
    Beekeeper()
    {
        sharpness = 5;
        lvl = 8;
        cout<<"Bzzzzz, do you like honey?"<<endl;
    }
};

class Edge_of_Night: public Orange
{
public:
    Edge_of_Night()
    {
        sharpness = 8;
        lvl = 8;
        cout<<"I am vengence!"<<endl;
    }
};

class Elegant_cane: public Orange
{
public:
    Elegant_cane()
    {
        sharpness = 7;
        lvl = 11;
        cout<<"Like a gentleman"<<endl;
    }
};

class Bone_sword: public Orange
{
public:
    Bone_sword()
    {
        sharpness = 12;
        lvl = 7;
        cout<<"Some skeleton lost his hand..."<<endl;
    }
};

class Grass_blade: public Orange
{
public:
    Grass_blade()
    {
        sharpness = 10;
        lvl = 9;
        cout<<"You can`t own this sword if you are PhysTech student"<<endl;
    }
};

//ЗЕЛЕНАЯ РЕДКОСТЬ

class Muhophagus: public Green
{
public:
    Muhophagus()
    {
        sharpness = 10;
        lvl = 10;
        cout<<"Muhophagus..."<<endl;
    }
};

class Tentacle: public Green
{
public:
    Tentacle()
    {
        sharpness = 13;
        lvl = 11;
        cout<<"Looks disgusting... Great!"<<endl;
    }
};

class Zhvalo: public Green
{
public:
    Zhvalo()
    {
        sharpness = 14;
        lvl = 12;
        cout<<"Zhvalo is... I dont know"<<endl;
    }
};

class Murosama: public Green
{
public:
    Murosama()
    {
        sharpness = 15;
        lvl = 13;
        cout<<"Honour is everything!"<<endl;
    }
};

class Bat: public Green
{
public:
    Bat()
    {
        sharpness = 10;
        lvl = 16;
        cout<<"Bat with a cute mouse"<<endl;
    }
};

class Gloves: public Green
{
public:
    Gloves()
    {
        sharpness = 19;
        lvl = 18;
        cout<<"Kyau!"<<endl;
    }
};


class ChristmasTreeSword: public Yellow
{
public:
    ChristmasTreeSword()
    {
        sharpness = 80;
        lvl = 79;
        cout << "The Christmas tree sword gleams with holiday lights!" << endl;
    }
};


class TrueExcalibur: public Yellow
{
public:
    TrueExcalibur()
    {
        sharpness = 75;
        lvl = 88;
        cout << "The true Excalibur shines with legendary power!" << endl;
    }
};


class HorsemansBlade: public Yellow
{
public:
    HorsemansBlade()
    {
        sharpness = 90;
        lvl = 90;
        cout << "The Horseman's blade whispers of ancient battles!" << endl;
    }
};


class KeySword: public Yellow
{
public:
    KeySword()
    {
        sharpness = 57;
        lvl = 89;
        cout << "The key-sword unlocks more than just doors!" << endl;
    }
};


class ManiacsKnife: public Yellow
{
public:
    ManiacsKnife()
    {
        sharpness = 89;
        lvl = 73;
        cout << "The maniac's knife has a sinister gleam!" << endl;
    }
};


class SoaringDragon: public Yellow
{
public:
    SoaringDragon()
    {
        sharpness = 91;
        lvl = 81;
        cout << "The soaring dragon sword feels alive in your hands!" << endl;
    }
};

class adamantine_sword : public Light_red
{
public:
    adamantine_sword()
    {
        sharpness = 40;
        lvl = 31;
    }

};
class White_Laser_Saber : public Light_red
{
public:
    White_Laser_Saber()
    {
        sharpness = 35;
        lvl = 29;
    }

};
class The_Destroyer_Blade : public Light_red
{
public:
    The_Destroyer_Blade()
    {
        sharpness = 45;
        lvl = 30;
    }

};
class The_Cobalt_Sword : public Light_red
{
public:
    The_Cobalt_Sword()
    {
        sharpness = 30;
        lvl = 30;
    }

};
class Elucidator_and_Dark_Repulser : public Light_red
{
public:
    Elucidator_and_Dark_Repulser()
    {
        sharpness = 100;
        lvl = 100;
        cout <<"These are Kirito's legendary pair of swords from Sword Art Online."<<endl;
        cout << "It's almost impossible to lose with these swords"<<endl;
        cout<<"-----------------------"<<endl;
    }

};
class The_Mithril_Sword : public Light_red
{
public:
    The_Mithril_Sword()
    {
        sharpness = 1;
        lvl = 1;
    }

};

class Lambent_Light : public pink
{
public:
    Lambent_Light()
    {
        sharpness = 100;
        lvl = 100;
        cout<<"Asuna's rapier. A powerful weapon. Very powerful."<<endl;
        cout<<"(And Asuna is the best girl in the whole anime)"<<endl;
        cout<<"-----------------------"<<endl;
    }

};
class The_Ice_Spit : public pink
{
public:
    The_Ice_Spit()
    {
        sharpness = 20;
        lvl = 60;
    }

};
class Dragon_Slayer : public pink
{
public:
    Dragon_Slayer()
    {
        sharpness = 100;
        lvl = 100;
        cout<<"Happiness"<<endl;
        cout<<"Happiness"<<endl;
        cout<<"Happiness"<<endl;
        cout<<"When will I be happy???"<<endl;
        cout<<"-----------------------"<<endl;
    }

};

class Excalibur : public pink
{
public:
    Excalibur()
    {
        sharpness = 40;
        lvl = 35;
    }

};
class sharp_tongued_sword : public pink
{
public:
    sharp_tongued_sword()
    {
        sharpness = 59;
        lvl = 40;
    }

};
class The_Sower : public pink
{
public:
    The_Sower()
    {
        sharpness = 59;
        lvl = 41;
    }

};



class The_Scythe_of_Death : public light_purple
{
public:
    The_Scythe_of_Death()
    {
        sharpness = 37;
        lvl = 41;
    }

};
class The_thing : public light_purple
{
public:
    The_thing()
    {
        sharpness = 59;
        lvl = 51;
    }

};


class The_Chlorophytic_saber : public lime_rare
{
public:
    The_Chlorophytic_saber()
    {
        sharpness = 59;
        lvl = 51;
    }

};

class Chlorophytic_claymer : public lime_rare
{
public:
    Chlorophytic_claymer()
    {
        sharpness = 50;
        lvl = 51;
    }

};
class Khalids_sword : public lime_rare
{
public:
    Khalids_sword()
    {
        sharpness = 1;
        lvl = 100;
        cout<<"This is the sword of one of the game's creators"<<endl;
        cout<<"It's not very sharp, but it can surprise you"<<endl;
        cout<<"-----------------------"<<endl;
    }

};



class Meowmoor : public red
{
public:
    Meowmoor()
    {
        sharpness = 70;
        lvl = 68;
    }

};

class Star_fall : public red
{
public:
    Star_fall()
    {
        sharpness = 69;
        lvl = 70;
    }

};


class boss
{
public:
int HP;
 int lvl;
    boss()
    {
        HP = 0;
        lvl = 0;

    }
};

class Holin : public boss
{
public:
    Holin()
    {
        HP=10;
        lvl =1;
        cout<<"What is temperature?"<<endl;
        cout<<"This is a very difficult question."<<endl;
        cout<<"I will not answer it."<<endl;
        cout<<"---------------------"<<endl;
    }
    void win()
    {
        cout << "-Yes, I lost. But you'll lose in the session!"<<endl;

    }
    void lose()
    {
        cout<< "-Mde, you still have a lot to learn."  <<endl;

    }

};

class Hitcliff : public boss
{
public:
    Hitcliff()
    {
        HP=300;
        lvl =96;
        cout<<"- Let's solve everything with a duel!"<<endl;
        cout<<"If you win, the game will end."<<endl;

        cout<<"---------------------"<<endl;
    }
    void win()
    {
        cout << "Oh, I forgot to mention. Kirito-kun, Asuna-kun... congratulations on completing the game."<<endl;
        cout << " "<<endl;
        cout <<"We looked up at Hitcliff. He looked down at us with a calm face"<<endl;
        cout <<"------------------------------------"<<endl;
        cout << " "<<endl;
        cout <<"-Well, I have to go."<<endl;
    }
    void lose()
    {
        cout<< "Hitcliff watched my movement with pity,"  <<endl;
        cout<< "which was neither a technique nor even an attack."  <<endl;
        cout<< "He easily deflected and knocked my sword away with his shield,"  <<endl;
        cout<< "and the blade in his right hand pierced my chest."  <<endl;
        cout<< "--------------------------------"  <<endl;
        cout << " "<<endl;
        cout<< "System message: You're dead"  <<endl;
    }

};



class Lepus : public boss
{
public:
    Lepus()
    {
        HP=80;
        lvl =30;
        cout<<"Aggressive animal sounds!"<<endl;

    }
    void win()
    {
        cout << "Sounds of sadness"<<endl;

    }
    void lose()
    {
        cout<< "Sounds of joy"  <<endl;

    }

};

string getResourcePath(const std::string& filename) {
    std::filesystem::path exePath = std::filesystem::current_path(); // или можно получить путь к exe
    return (exePath / "resources" / filename).string();
}

int main()
{

    bool playAgain = true;

    sf::Music music;
std::string exeDir = getExecutableDir();
std::filesystem::path musicPath = std::filesystem::path(exeDir) / "resources" / "Jacal.ogg";

if (!music.openFromFile(musicPath.string())) {
    // Если не нашли в resources/, пробуем просто имя файла (на случай, если кто-то положил ogg рядом с exe)
    if (!music.openFromFile("Jacal.ogg")) {
        std::cout << "Can't find music!" << std::endl;
    } else {
        music.setLoop(true);
        music.setVolume(50);
        music.play();
        std::cout << "🎵 Music plays! (from current dir) 🎵" << std::endl;
    }
} else {
    music.setLoop(true);
    music.setVolume(50);
    music.play();
    std::cout << "🎵 Music plays from resources folder! 🎵" << std::endl;
}
    
    while(playAgain){
    char type = 'q';
    char rare_type = 'q';
    int sword_choice;
    
    cout << "Welcome to Terraria Boss fighting, at first you need a weapon." << endl;
    Swords sword;
    sword.callSword();
    
    cin >> type;

    if (type != 'Z' && type != 'X' && type != 'C') {
            cout << "Wrong, try again." << endl;
            continue;
        }
    
    if (type == 'Z')  // Low
    {
        Low low;
        low.lowcall();
        cin >> rare_type;

        if (rare_type != 'Z' && rare_type != 'X' && rare_type != 'C' && rare_type != 'V') {
            cout << "Wrong, try again." << endl;
            continue;
        }
        
        if (rare_type == 'Z')  // White
        {
            White white;
            white.callWhite();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2 && sword_choice != 3 && sword_choice != 4 && sword_choice != 5 && sword_choice != 6 && sword_choice != 7) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    Ebony e; 
                    global_sharpness = e.sharpness;  // Обратите внимание: sharpness protected?
                    global_level = e.lvl;
                    global_sword_name = "Ebony sword";
                    break; 
                }
                case 2: { 
                    Silver_Dag s; 
                    global_sharpness = s.sharpness;
                    global_level = s.lvl;
                    global_sword_name = "Silver dagger";
                    break; 
                }
                case 3: { 
                    Palm p; 
                    global_sharpness = p.sharpness;
                    global_level = p.lvl;
                    global_sword_name = "Palm tree sword";
                    break; 
                }
                case 4: { 
                    Cactus c; 
                    global_sharpness = c.sharpness;
                    global_level = c.lvl;
                    global_sword_name = "Cactus sword";
                    break; 
                }
                case 5: { 
                    Copper c; 
                    global_sharpness = c.sharpness;
                    global_level = c.lvl;
                    global_sword_name = "Copper dagger";
                    break; 
                }
                case 6: { 
                    Wooden w; 
                    global_sharpness = w.sharpness;
                    global_level = w.lvl;
                    global_sword_name = "Wooden sword";
                    break; 
                }
                case 7: { 
                    Dark_Wooden d; 
                    global_sharpness = d.sharpness;
                    global_level = d.lvl;
                    global_sword_name = "Dark wooden sword";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
        else if (rare_type == 'X')  // Blue
        {
            Blue blue;
            blue.callBlue();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2 && sword_choice != 3 && sword_choice != 4 && sword_choice != 5 && sword_choice != 6) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    Umbrella u; 
                    global_sharpness = u.sharpness;
                    global_level = u.lvl;
                    global_sword_name = "Umbrella";
                    break; 
                }
                case 2: { 
                    Caramel c; 
                    global_sharpness = c.sharpness;
                    global_level = c.lvl;
                    global_sword_name = "Caramel sword";
                    break; 
                }
                case 3: { 
                    Scourge_of_Light s; 
                    global_sharpness = s.sharpness;
                    global_level = s.lvl;
                    global_sword_name = "Scourge of Light";
                    break; 
                }
                case 4: { 
                    Bloody_ripper b; 
                    global_sharpness = b.sharpness;
                    global_level = b.lvl;
                    global_sword_name = "Bloody Ripper";
                    break; 
                }
                case 5: { 
                    White_Laser w; 
                    global_sharpness = w.sharpness;
                    global_level = w.lvl;
                    global_sword_name = "White Laser sword";
                    break; 
                }
                case 6: { 
                    Gladius g; 
                    global_sharpness = g.sharpness;
                    global_level = g.lvl;
                    global_sword_name = "Gladius";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
        else if (rare_type == 'C')  // Orange
        {
            Orange orange;
            orange.callOrange();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2 && sword_choice != 3 && sword_choice != 4 && sword_choice != 5 && sword_choice != 6) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    Volcane v; 
                    global_sharpness = v.sharpness;
                    global_level = v.lvl;
                    global_sword_name = "Volcane";
                    break; 
                }
                case 2: { 
                    Beekeeper b; 
                    global_sharpness = b.sharpness;
                    global_level = b.lvl;
                    global_sword_name = "Beekeeper";
                    break; 
                }
                case 3: { 
                    Edge_of_Night e; 
                    global_sharpness = e.sharpness;
                    global_level = e.lvl;
                    global_sword_name = "Edge of Night";
                    break; 
                }
                case 4: { 
                    Elegant_cane e; 
                    global_sharpness = e.sharpness;
                    global_level = e.lvl;
                    global_sword_name = "Elegant cane";
                    break; 
                }
                case 5: { 
                    Bone_sword b; 
                    global_sharpness = b.sharpness;
                    global_level = b.lvl;
                    global_sword_name = "Bone sword";
                    break; 
                }
                case 6: { 
                    Grass_blade g; 
                    global_sharpness = g.sharpness;
                    global_level = g.lvl;
                    global_sword_name = "Grass blade";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
        else if (rare_type == 'V')  // Green
        {
            Green green;
            green.callGreen();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2 && sword_choice != 3 && sword_choice != 4 && sword_choice != 5 && sword_choice != 6) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    Muhophagus m; 
                    global_sharpness = m.sharpness;
                    global_level = m.lvl;
                    global_sword_name = "Muhophagus";
                    break; 
                }
                case 2: { 
                    Tentacle t; 
                    global_sharpness = t.sharpness;
                    global_level = t.lvl;
                    global_sword_name = "Spiky tentacle";
                    break; 
                }
                case 3: { 
                    Zhvalo z; 
                    global_sharpness = z.sharpness;
                    global_level = z.lvl;
                    global_sword_name = "Zhvalo sword";
                    break; 
                }
                case 4: { 
                    Murosama m; 
                    global_sharpness = m.sharpness;
                    global_level = m.lvl;
                    global_sword_name = "Muramasa";
                    break; 
                }
                case 5: { 
                    Bat b; 
                    global_sharpness = b.sharpness;
                    global_level = b.lvl;
                    global_sword_name = "Mouse baseball bat";
                    break; 
                }
                case 6: { 
                    Gloves g; 
                    global_sharpness = g.sharpness;
                    global_level = g.lvl;
                    global_sword_name = "Glove with blades";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
    }
    else if (type == 'X')  // Medium
    {
        medium mid;
        mid.M();
        cin >> rare_type;

        
        
        if (rare_type == 'Z')  // Light red
        {
            Light_red lr;
            lr.M1();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2 && sword_choice != 3 && sword_choice != 4 && sword_choice != 5 && sword_choice != 6) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    adamantine_sword a; 
                    global_sharpness = a.sharpness;
                    global_level = a.lvl;
                    global_sword_name = "Adamantine sword";
                    break; 
                }
                case 2: { 
                    White_Laser_Saber w; 
                    global_sharpness = w.sharpness;
                    global_level = w.lvl;
                    global_sword_name = "White Laser Saber";
                    break; 
                }
                case 3: { 
                    The_Destroyer_Blade d; 
                    global_sharpness = d.sharpness;
                    global_level = d.lvl;
                    global_sword_name = "The Destroyer Blade";
                    break; 
                }
                case 4: { 
                    The_Cobalt_Sword c; 
                    global_sharpness = c.sharpness;
                    global_level = c.lvl;
                    global_sword_name = "The Cobalt Sword";
                    break; 
                }
                case 5: { 
                    Elucidator_and_Dark_Repulser e; 
                    global_sharpness = e.sharpness;
                    global_level = e.lvl;
                    global_sword_name = "Elucidator and Dark Repulser";
                    break; 
                }
                case 6: { 
                    The_Mithril_Sword m; 
                    global_sharpness = m.sharpness;
                    global_level = m.lvl;
                    global_sword_name = "The Mithril Sword";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
        else if (rare_type == 'X')  // Pink
        {
            pink p;
            p.M2();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2 && sword_choice != 3 && sword_choice != 4 && sword_choice != 5 && sword_choice != 6 ) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    Lambent_Light l; 
                    global_sharpness = l.sharpness;
                    global_level = l.lvl;
                    global_sword_name = "Lambent Light";
                    break; 
                }
                case 2: { 
                    The_Ice_Spit i; 
                    global_sharpness = i.sharpness;
                    global_level = i.lvl;
                    global_sword_name = "The Ice Spit";
                    break; 
                }
                case 3: { 
                    Dragon_Slayer d; 
                    global_sharpness = d.sharpness;
                    global_level = d.lvl;
                    global_sword_name = "Dragon Slayer";
                    break; 
                }
                case 4: { 
                    Excalibur e; 
                    global_sharpness = e.sharpness;
                    global_level = e.lvl;
                    global_sword_name = "Excalibur";
                    break; 
                }
                case 5: { 
                    sharp_tongued_sword s; 
                    global_sharpness = s.sharpness;
                    global_level = s.lvl;
                    global_sword_name = "Sharp-tongued sword";
                    break; 
                }
                case 6: { 
                    The_Sower t; 
                    global_sharpness = t.sharpness;
                    global_level = t.lvl;
                    global_sword_name = "The Sower";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
        else if (rare_type == 'C')  // Light purple
        {
            light_purple lp;
            lp.M3();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    The_Scythe_of_Death s; 
                    global_sharpness = s.sharpness;
                    global_level = s.lvl;
                    global_sword_name = "The Scythe of Death";
                    break; 
                }
                case 2: { 
                    The_thing t; 
                    global_sharpness = t.sharpness;
                    global_level = t.lvl;
                    global_sword_name = "The thing";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
        else if (rare_type == 'V')  // Lime
        {
            lime_rare lime;
            lime.M4();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2 && sword_choice != 3) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    The_Chlorophytic_saber c; 
                    global_sharpness = c.sharpness;
                    global_level = c.lvl;
                    global_sword_name = "The Chlorophytic saber";
                    break; 
                }
                case 2: { 
                    Chlorophytic_claymer c; 
                    global_sharpness = c.sharpness;
                    global_level = c.lvl;
                    global_sword_name = "Chlorophytic claymer";
                    break; 
                }
                case 3: { 
                    Khalids_sword k; 
                    global_sharpness = k.sharpness;
                    global_level = k.lvl;
                    global_sword_name = "Khalid's sword";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
    }
    else if (type == 'C')  // High
    {
        High high;
        high.callHigh();
        cin >> rare_type;
        
        if (rare_type == 'Z')  // Yellow
        {
            Yellow yellow;
            yellow.callYellow();
            cin >> sword_choice;

            if (sword_choice != 1 && sword_choice != 2 && sword_choice != 3 && sword_choice != 4 && sword_choice != 5 && sword_choice != 6) {
            cout << "Wrong, try again." << endl;
            continue;
        }
            
            switch(sword_choice) {
                case 1: { 
                    ChristmasTreeSword c; 
                    global_sharpness = c.sharpness;
                    global_level = c.lvl;
                    global_sword_name = "Christmas tree sword";
                    break; 
                }
                case 2: { 
                    TrueExcalibur t; 
                    global_sharpness = t.sharpness;
                    global_level = t.lvl;
                    global_sword_name = "True Excalibur";
                    break; 
                }
                case 3: { 
                    HorsemansBlade h; 
                    global_sharpness = h.sharpness;
                    global_level = h.lvl;
                    global_sword_name = "Horseman's blade";
                    break; 
                }
                case 4: { 
                    KeySword k; 
                    global_sharpness = k.sharpness;
                    global_level = k.lvl;
                    global_sword_name = "Key-sword";
                    break; 
                }
                case 5: { 
                    ManiacsKnife m; 
                    global_sharpness = m.sharpness;
                    global_level = m.lvl;
                    global_sword_name = "Maniac's knife";
                    break; 
                }
                case 6: { 
                    SoaringDragon s; 
                    global_sharpness = s.sharpness;
                    global_level = s.lvl;
                    global_sword_name = "Soaring dragon";
                    break; 
                }
                default: cout << "Invalid choice!" << endl;
            }
        }
    }
    
    // Вывод информации о выбранном мече
    if (global_sharpness > 0) {
        cout << "\n=== SWORD SELECTED ===" << endl;
        cout << "Name: " << global_sword_name << endl;
        cout << "Sharpness: " << global_sharpness << endl;
        cout << "Level: " << global_level << endl;
        cout << "==================\n" << endl;
    }
    
    cout<<"It`s time to fight a boss, choose your enemy!"<<endl;
    cout<<"Holin - A, Hitkliff -B, Lepus - C"<<endl;

    char boss_type = 'q';

    cin>>boss_type;

    if (boss_type == 'A')
    {
        Holin h;
        if (h.lvl < global_level)
        {
        cout<<"The fight begins now!"<<endl;
        cout<<"Beat him with three shots"<<endl;
        cout<<"Your Summary damage is "<<3 * global_sharpness<<endl;
        cout<<"Boss HP:"<<h.HP<<endl;

        if (h.HP <= 3 * global_sharpness)
        {
            cout<<"You win!"<<endl;
            cout<<"Boss:"<<endl;
            h.win();

            cout<<"Thanks for playing!"<<endl;

            return 0;
        }
        else
        {
            cout<<"You lost!"<<endl;
            cout<<"Boss:"<<endl;
            h.lose();

            cout<<"Thanks for playing!"<<endl;

            return 0;
        }
        }
        else{
        cout<<"Sorry, your level is"<<global_level<<", it`s less than boss level"<<h.lvl<<". Try fight him next time"<<endl;
        continue;
        }
    }

    if (boss_type == 'B')
    {
        Hitcliff s;
        if (s.lvl < global_level)
        {
        cout<<"The fight begins now!"<<endl;
        cout<<"Beat him with three shots"<<endl;
        cout<<"Your Summary damage is "<<3 * global_sharpness<<endl;
        cout<<"Boss HP:"<<s.HP<<endl;

        if (s.HP <= 3 * global_sharpness)
        {
            cout<<"You win!"<<endl;
            cout<<"Boss:"<<endl;
            s.win();

            cout<<"Thanks for playing!"<<endl;

            return 0;
        }
        else
        {
            cout<<"You lost!"<<endl;
            cout<<"Boss:"<<endl;
            s.lose();

            cout<<"Thanks for playing!"<<endl;

            return 0;
        }
        }
        else{
        cout<<"Sorry, your level is"<<global_level<<", it`s less than boss level"<<s.lvl<<". Try fight him next time"<<endl;
        continue;
        }
    }

    if (boss_type == 'C')
    {
        Lepus L;
        if (L.lvl < global_level)
        {
        cout<<"The fight begins now!"<<endl;
        cout<<"Beat him with three shots"<<endl;
        cout<<"Your Summary damage is "<<3 * global_sharpness<<endl;
        cout<<"Boss HP:"<<L.HP<<endl;

        if (L.HP <= 3 * global_sharpness)
        {
            cout<<"You win!"<<endl;
            cout<<"Boss:"<<endl;
            L.win();

            cout<<"Thanks for playing!"<<endl;

            return 0;
        }
        else
        {
            cout<<"You lost!"<<endl;
            cout<<"Boss:"<<endl;
            L.lose();

            cout<<"Thanks for playing!"<<endl;

            return 0;
        }
        }
        else{
        cout<<"Sorry, your level is"<<global_level<<", it`s less than boss level"<<L.lvl<<". Try fight him next time"<<endl;
        continue;
        }
    }
}
}
