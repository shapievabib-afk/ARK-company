#include <iostream>
#include <string>

using namespace std;

class Swords
{
public:
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

protected:
    int sharpness;
    int lvl;
    string rare;
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

int main()
{
    char type = 'q';
    char rare_type = 'q';
    cout<<"Welcome to Terraria Boss fighting, at first you need a weapon."<<endl;

    Swords sword;

    cin>>type;

    if (type == 'Z')
        {
            Low low;

            cin>>rare_type;

            if(rare_type == 'Z')
            {

            }
            if(rare_type == 'X')
            {
                
            }
            if(rare_type == 'C')
            {
                
            }
            if(rare_type == 'V')
            {
                
            }

        }
    
    if (type == 'X')
        {
            medium mid;
        }
    
    if (type == 'C')
        {
             High high;
        }

    

    
}
