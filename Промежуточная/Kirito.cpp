class medium : public Swords
{
    public:
    medium()
    {
        this->rare = "medium";
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
class Light_red : public medium
{
    public:
    Light_red()
    {
        this->rare = "Light_red";
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
        cout << "red. Not read. Red. Blood. Rage......"<< endl;
        cout << "                            "<<endl;
        cout << "----------------------------"<< endl;
        cout << "                            "<<endl;
        cout << "Now choose a Sword: " << endl;
        cout << "Meowmoor - 1"<<endl;
        cout << "Star fall - 2"<<endl;
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



