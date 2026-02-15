#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <conio.h> // для _getch()
using namespace std;

// Цвета для консоли (для Windows)
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// ===================== БАЗОВЫЙ КЛАСС МЕЧА =====================
class Swords {
protected:
    int sharpness;
    int lvl;
    string rare;

public:
    Swords() : sharpness(0), lvl(0) {}
    virtual ~Swords() {}

    int getSharpness() { return sharpness; }
    int getLevel() { return lvl; }
    string getRare() { return rare; }

    virtual void describe() {
        cout << "⚔️ Обычный меч" << endl;
    }

    // Виртуальные функции для легендарных способностей
    virtual void specialAbility1() {
        cout << "Обычная атака" << endl;
    }

    virtual void specialAbility2() {
        cout << "Нет второй способности" << endl;
    }

    virtual void specialAbility3() {
        cout << "Нет третьей способности" << endl;
    }
};

// ===================== ПРОМЕЖУТОЧНЫЕ КЛАССЫ =====================
class medium : public Swords {
public:
    medium() {
        this->rare = "medium";
    }
};

class Light_red : public medium {
public:
    Light_red() {
        this->rare = "Light_red";
    }
};

class pink : public medium {
public:
    pink() {
        this->rare = "pink";
    }
};

class light_purple : public medium {
public:
    light_purple() {
        this->rare = "light_purple";
    }
};

class lime_rare : public medium {
public:
    lime_rare() {
        this->rare = "lime rare";
    }
};

// ===================== LIGHT RED МЕЧИ =====================
class adamantine_sword : public Light_red {
public:
    adamantine_sword() {
        sharpness = 40;
        lvl = 31;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << CYAN << "Адамантиновый меч" << RESET << endl;
        cout << "Прочный и надежный, как адамантит" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class White_Laser_Saber : public Light_red {
public:
    White_Laser_Saber() {
        sharpness = 35;
        lvl = 29;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << WHITE << "Белый лазерный меч" << RESET << endl;
        cout << "Режет врагов на расстоянии!" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class The_Destroyer_Blade : public Light_red {
public:
    The_Destroyer_Blade() {
        sharpness = 45;
        lvl = 30;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << RED << "Клинок Разрушителя" << RESET << endl;
        cout << "Не оставляет шансов врагам" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class The_Cobalt_Sword : public Light_red {
public:
    The_Cobalt_Sword() {
        sharpness = 30;
        lvl = 30;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << BLUE << "Кобальтовый меч" << RESET << endl;
        cout << "Холодный, как синий металл" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class Elucidator_and_Dark_Repulser : public Light_red {
private:
    bool dualBladeMode = false;

public:
    Elucidator_and_Dark_Repulser() {
        sharpness = 100;
        lvl = 100;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << MAGENTA << "⚔️⚔️ ELUCIDATOR И DARK REPULSER ⚔️⚔️" << RESET << endl;
        cout << YELLOW << "These are Kirito's legendary pair of swords from Sword Art Online." << endl;
        cout << "It's almost impossible to lose with these swords" << endl;
        cout << GREEN << "-----------------------" << RESET << endl;
        cout << "Доступные способности:" << endl;
        cout << "1. Starburst Stream (Звездопад) - 16 быстрых ударов" << endl;
        cout << "2. Dual Blade Mode - Удвоенный урон на 3 хода" << endl;
        cout << "3. Eclipse (Затмение) - Финальный удар" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }

    void specialAbility1() override {
        cout << MAGENTA << "⚡ STARBURST STREAM! 16 быстрых ударов! ⚡" << RESET << endl;
        cout << "Урон увеличен в 3 раза!" << endl;
    }

    void specialAbility2() override {
        dualBladeMode = !dualBladeMode;
        if(dualBladeMode) {
            cout << MAGENTA << "⚔️ DUAL BLADE MODE АКТИВИРОВАН! Урон удвоен на 3 хода! ⚔️" << RESET << endl;
        } else {
            cout << "Режим двух мечей деактивирован" << endl;
        }
    }

    void specialAbility3() override {
        cout << MAGENTA << "🌑 ECLIPSE! ФИНАЛЬНЫЙ УДАР! 🌑" << RESET << endl;
        cout << "Огромный урон по всем врагам!" << endl;
    }
};

class The_Mithril_Sword : public Light_red {
public:
    The_Mithril_Sword() {
        sharpness = 1;
        lvl = 1;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << "Мифриловый меч" << endl;
        cout << "Легкий, но пока слишком слабый..." << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

// ===================== PINK МЕЧИ =====================
class Lambent_Light : public pink {
private:
    int flashCounter = 0;

public:
    Lambent_Light() {
        sharpness = 100;
        lvl = 100;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << MAGENTA << "✨ LAMBENT LIGHT ✨" << RESET << endl;
        cout << YELLOW << "Asuna's rapier. A powerful weapon. Very powerful." << endl;
        cout << MAGENTA << "(And Asuna is the best girl in the whole anime)" << RESET << endl;
        cout << GREEN << "-----------------------" << RESET << endl;
        cout << "Доступные способности:" << endl;
        cout << "1. Fluent Light (Быстрый свет) - Серия из 8 ударов" << endl;
        cout << "2. Mother's Rosario - Финальная техника Асуны" << endl;
        cout << "3. Flash Burst - Ускорение атаки" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }

    void specialAbility1() override {
        cout << MAGENTA << "🌸 FLUENT LIGHT! 8 быстрых ударов рапирой! 🌸" << RESET << endl;
        cout << "Урон увеличен в 2.5 раза!" << endl;
    }

    void specialAbility2() override {
        cout << MAGENTA << "💫 MOTHER'S ROSARIO! 11-ти ударная комбинация! 💫" << RESET << endl;
        cout << "Максимальный урон по врагу!" << endl;
    }

    void specialAbility3() override {
        flashCounter++;
        cout << MAGENTA << "⚡ FLASH BURST! Скорость атаки увеличена! (Зарядов: " << flashCounter << ") ⚡" << RESET << endl;
    }
};

class The_Ice_Spit : public pink {
public:
    The_Ice_Spit() {
        sharpness = 20;
        lvl = 60;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << "Ледяной клинок" << endl;
        cout << "Морозное дыхание смерти" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class Dragon_Slayer : public pink {
private:
    int rageMode = 0;

public:
    Dragon_Slayer() {
        sharpness = 100;
        lvl = 100;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << RED << "🐉 DRAGON SLAYER 🐉" << RESET << endl;
        cout << YELLOW << "Happiness" << endl;
        cout << "Happiness" << endl;
        cout << "Happiness" << endl;
        cout << BLUE << "When will I be happy???" << RESET << endl;
        cout << GREEN << "-----------------------" << RESET << endl;
        cout << "Доступные способности:" << endl;
        cout << "1. Удар дракона - Мощная атака" << endl;
        cout << "2. Режим ярости - Увеличение урона от полученного урона" << endl;
        cout << "3. Berserker Rage - Полная ярость" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }

    void specialAbility1() override {
        cout << RED << "🐉 УДАР ДРАКОНА! Огромный меч обрушивается на врага! 🐉" << RESET << endl;
        cout << "Урон увеличен в 3 раза!" << endl;
    }

    void specialAbility2() override {
        rageMode++;
        cout << RED << "🔥 РЕЖИМ ЯРОСТИ " << rageMode << "! Чем больше урона получаешь, тем сильнее бьешь! 🔥" << RESET << endl;
    }

    void specialAbility3() override {
        cout << RED << "⚡ BERSERKER RAGE! АТАКА БЕРСЕРКА! ⚡" << RESET << endl;
        cout << "Игнорирует всю защиту врага!" << endl;
    }
};

class Excalibur : public pink {
public:
    Excalibur() {
        sharpness = 40;
        lvl = 35;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << YELLOW << "ЭКСКАЛИБУР" << RESET << endl;
        cout << "Меч короля Артура" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class sharp_tongued_sword : public pink {
public:
    sharp_tongued_sword() {
        sharpness = 59;
        lvl = 40;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << "Острослов" << endl;
        cout << "Режет не только плоть, но и душу" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class The_Sower : public pink {
public:
    The_Sower() {
        sharpness = 59;
        lvl = 41;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << "Сеятель" << endl;
        cout << "Сеет хаос среди врагов" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

// ===================== LIGHT PURPLE МЕЧИ =====================
class The_Scythe_of_Death : public light_purple {
public:
    The_Scythe_of_Death() {
        sharpness = 37;
        lvl = 41;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << MAGENTA << "Коса Смерти" << RESET << endl;
        cout << "Когда видишь этот меч,死神 улыбается тебе" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class The_thing : public light_purple {
public:
    The_thing() {
        sharpness = 59;
        lvl = 51;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << "Вещь" << endl;
        cout << "Что это? Как это работает? Никто не знает..." << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

// ===================== LIME RARE МЕЧИ =====================
class The_Chlorophytic_saber : public lime_rare {
public:
    The_Chlorophytic_saber() {
        sharpness = 59;
        lvl = 51;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << GREEN << "Хлорофитовая сабля" << RESET << endl;
        cout << "Пахнет лесом и свежестью" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class Chlorophytic_claymer : public lime_rare {
public:
    Chlorophytic_claymer() {
        sharpness = 50;
        lvl = 51;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << GREEN << "Хлорофитовый клаймер" << RESET << endl;
        cout << "Тяжелый и зеленый" << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

class Khalids_sword : public lime_rare {
public:
    Khalids_sword() {
        sharpness = 1;
        lvl = 1;
    }

    void describe() override {
        cout << "═══════════════════════════════════════" << endl;
        cout << "Меч Халида" << endl;
        cout << "У каждого героя есть свой первый меч..." << endl;
        cout << "═══════════════════════════════════════" << endl;
    }
};

// ===================== ИГРОВАЯ СИСТЕМА =====================
class Game {
private:
    vector<Swords*> inventory;
    Swords* currentSword;
    int playerHP;
    int maxPlayerHP;
    int playerLevel;
    int wins;
    int defenseMode; // 0 - нет защиты, 1 - защита
    int specialCooldown[3]; // Кулдауны способностей

public:
    Game() : currentSword(nullptr), playerHP(100), maxPlayerHP(100), playerLevel(1), wins(0), defenseMode(0) {
        for(int i = 0; i < 3; i++) specialCooldown[i] = 0;

        cout << "\n" << CYAN << "╔══════════════════════════════════════╗" << RESET << endl;
        cout << CYAN << "║" << RESET << "     🗡️  ДОБРО ПОЖАЛОВАТЬ В МИР МЕЧЕЙ  🗡️     " << CYAN << "║" << RESET << endl;
        cout << CYAN << "╚══════════════════════════════════════╝" << RESET << "\n" << endl;
    }

    ~Game() {
        for(auto sword : inventory) {
            delete sword;
        }
    }

    void start() {
        // Даем первый меч
        cout << "🔰 Ваш первый меч: Меч Халида\n" << endl;
        Khalids_sword* firstSword = new Khalids_sword();
        inventory.push_back(firstSword);
        currentSword = firstSword;

        bool playing = true;
        while(playing) {
            // Обновляем кулдауны
            for(int i = 0; i < 3; i++) {
                if(specialCooldown[i] > 0) specialCooldown[i]--;
            }

            showMenu();

            char choice = _getch();
            cout << choice << endl;

            switch(choice) {
                case '1':
                    getNewSword();
                    break;
                case '2':
                    showInventory();
                    break;
                case '3':
                    changeSword();
                    break;
                case '4':
                    fight();
                    break;
                case '5':
                    playerStats();
                    break;
                case '6':
                    rest();
                    break;
                case '7':
                    cout << "\n👋 До встречи! Пусть мечи всегда будут остры!\n" << endl;
                    playing = false;
                    break;
                default:
                    cout << RED << "❌ Неверный выбор!" << RESET << endl;
            }

            if(playing) {
                cout << "\nНажмите любую клавишу для продолжения...";
                _getch();
                system("cls");
            }
        }
    }

    void showMenu() {
        cout << "\n" << YELLOW << "═══════════════════════════════════════" << RESET << endl;
        cout << "           🏠 ГЛАВНОЕ МЕНЮ" << endl;
        cout << YELLOW << "═══════════════════════════════════════" << RESET << endl;
        cout << "1. 🗡️  Получить новый меч" << endl;
        cout << "2. 📦 Инвентарь" << endl;
        cout << "3. 🔄 Сменить меч" << endl;
        cout << "4. ⚔️  Сразиться" << endl;
        cout << "5. 📊 Статистика" << endl;
        cout << "6. ❤️  Отдохнуть (восстановить HP)" << endl;
        cout << "7. 🚪 Выйти" << endl;
        cout << YELLOW << "═══════════════════════════════════════" << RESET << endl;
        cout << "❤️ Ваше HP: " << playerHP << "/" << maxPlayerHP << endl;
        cout << "Выберите действие: ";
    }

    void getNewSword() {
        cout << "\n" << CYAN << "medium : public Swords" << RESET << endl;
        cout << "Medium? It's somewhere in the middle..." << endl;
        cout << "                            " << endl;
        cout << GREEN << "----------------------------" << RESET << endl;
        cout << "                            " << endl;
        cout << "Now choose a rare: " << endl;
        cout << "Light red rare - Z" << endl;
        cout << "pink rare - X" << endl;
        cout << "light purple rare - C" << endl;
        cout << "lime rare - V" << endl;
        cout << "Ваш выбор: ";

        char rare_choice = _getch();
        cout << rare_choice << endl;
        rare_choice = toupper(rare_choice);

        Swords* newSword = nullptr;

        switch(rare_choice) {
            case 'Z': { // Light red
                cout << "\n" << CYAN << "Light_red : public medium" << RESET << endl;
                cout << "Light red. It's almost red, but a little lighter" << endl;
                cout << "                            " << endl;
                cout << GREEN << "----------------------------" << RESET << endl;
                cout << "                            " << endl;
                cout << "Now choose a Sword: " << endl;
                cout << "The adamantine sword - 1" << endl;
                cout << "White Laser Saber - 2" << endl;
                cout << "The Destroyer Blade - 3" << endl;
                cout << "The Cobalt Sword - 4" << endl;
                cout << "Elucidator and Dark Repulser - 5" << endl;
                cout << "The Mithril Sword - 6" << endl;
                cout << "Ваш выбор: ";

                char sword_choice = _getch();
                cout << sword_choice << endl;

                switch(sword_choice) {
                    case '1': newSword = new adamantine_sword(); break;
                    case '2': newSword = new White_Laser_Saber(); break;
                    case '3': newSword = new The_Destroyer_Blade(); break;
                    case '4': newSword = new The_Cobalt_Sword(); break;
                    case '5': newSword = new Elucidator_and_Dark_Repulser(); break;
                    case '6': newSword = new The_Mithril_Sword(); break;
                    default: cout << RED << "Неверный выбор!" << RESET << endl;
                }
                break;
            }

            case 'X': { // Pink
                cout << "\n" << MAGENTA << "pink : public medium" << RESET << endl;
                cout << "Pink is a very cute color" << endl;
                cout << "                            " << endl;
                cout << GREEN << "----------------------------" << RESET << endl;
                cout << "                            " << endl;
                cout << "Now choose a Sword: " << endl;
                cout << "Lambent Light - 1" << endl;
                cout << "The Ice Spit - 2" << endl;
                cout << "Dragon Slayer - 3" << endl;
                cout << "Excalibur - 4" << endl;
                cout << "sharp-tongued sword - 5" << endl;
                cout << "The Sower - 6" << endl;
                cout << "Ваш выбор: ";

                char sword_choice = _getch();
                cout << sword_choice << endl;

                switch(sword_choice) {
                    case '1': newSword = new Lambent_Light(); break;
                    case '2': newSword = new The_Ice_Spit(); break;
                    case '3': newSword = new Dragon_Slayer(); break;
                    case '4': newSword = new Excalibur(); break;
                    case '5': newSword = new sharp_tongued_sword(); break;
                    case '6': newSword = new The_Sower(); break;
                    default: cout << RED << "Неверный выбор!" << RESET << endl;
                }
                break;
            }

            case 'C': { // Light purple
                cout << "\n" << MAGENTA << "light_purple : public medium" << RESET << endl;
                cout << "My favorite jacket was light purple. Oh, how nostalgic" << endl;
                cout << "                            " << endl;
                cout << GREEN << "----------------------------" << RESET << endl;
                cout << "                            " << endl;
                cout << "Now choose a Sword: " << endl;
                cout << "The Scythe of Death - 1" << endl;
                cout << "The thing - 2" << endl;
                cout << "Ваш выбор: ";

                char sword_choice = _getch();
                cout << sword_choice << endl;

                switch(sword_choice) {
                    case '1': newSword = new The_Scythe_of_Death(); break;
                    case '2': newSword = new The_thing(); break;
                    default: cout << RED << "Неверный выбор!" << RESET << endl;
                }
                break;
            }

            case 'V': { // Lime rare
                cout << "\n" << GREEN << "lime_rare : public medium" << RESET << endl;
                cout << "I don't like citrus fruits, ugh" << endl;
                cout << "                            " << endl;
                cout << GREEN << "----------------------------" << RESET << endl;
                cout << "                            " << endl;
                cout << "Now choose a Sword: " << endl;
                cout << "The Chlorophytic saber - 1" << endl;
                cout << "Chlorophytic claymer - 2" << endl;
                cout << "Khalid's sword - 3" << endl;
                cout << "Ваш выбор: ";

                char sword_choice = _getch();
                cout << sword_choice << endl;

                switch(sword_choice) {
                    case '1': newSword = new The_Chlorophytic_saber(); break;
                    case '2': newSword = new Chlorophytic_claymer(); break;
                    case '3': newSword = new Khalids_sword(); break;
                    default: cout << RED << "Неверный выбор!" << RESET << endl;
                }
                break;
            }

            default:
                cout << RED << "❌ Неверный выбор редкости!" << RESET << endl;
                return;
        }

        if(newSword) {
            inventory.push_back(newSword);
            cout << "\n" << GREEN << "✅ Вы получили новый меч!" << RESET << endl;
            newSword->describe();
        }
    }

    void showInventory() {
        if(inventory.empty()) {
            cout << "\n📦 Инвентарь пуст!" << endl;
            return;
        }

        cout << "\n" << CYAN << "═══════════════════════════════════════" << RESET << endl;
        cout << "           📦 ИНВЕНТАРЬ" << endl;
        cout << CYAN << "═══════════════════════════════════════" << RESET << endl;

        for(size_t i = 0; i < inventory.size(); i++) {
            cout << i+1 << ". ";
            if(inventory[i] == currentSword) {
                cout << GREEN << "▶ [ЭКИП.] " << RESET;
            }

            // Определяем тип меча
            if(dynamic_cast<Elucidator_and_Dark_Repulser*>(inventory[i])) {
                cout << MAGENTA << "⚔️⚔️ Elucidator и Dark Repulser" << RESET;
            }
            else if(dynamic_cast<Lambent_Light*>(inventory[i])) {
                cout << MAGENTA << "✨ Lambent Light" << RESET;
            }
            else if(dynamic_cast<Dragon_Slayer*>(inventory[i])) {
                cout << RED << "🐉 Dragon Slayer" << RESET;
            }
            else if(dynamic_cast<adamantine_sword*>(inventory[i])) {
                cout << CYAN << "Адамантиновый меч" << RESET;
            }
            else if(dynamic_cast<White_Laser_Saber*>(inventory[i])) {
                cout << WHITE << "Белый лазерный меч" << RESET;
            }
            else if(dynamic_cast<The_Destroyer_Blade*>(inventory[i])) {
                cout << RED << "Клинок Разрушителя" << RESET;
            }
            else if(dynamic_cast<The_Cobalt_Sword*>(inventory[i])) {
                cout << BLUE << "Кобальтовый меч" << RESET;
            }
            else if(dynamic_cast<The_Mithril_Sword*>(inventory[i])) {
                cout << "Мифриловый меч" << RESET;
            }
            else if(dynamic_cast<The_Ice_Spit*>(inventory[i])) {
                cout << "Ледяной клинок" << RESET;
            }
            else if(dynamic_cast<Excalibur*>(inventory[i])) {
                cout << YELLOW << "Экскалибур" << RESET;
            }
            else if(dynamic_cast<sharp_tongued_sword*>(inventory[i])) {
                cout << "Острослов" << RESET;
            }
            else if(dynamic_cast<The_Sower*>(inventory[i])) {
                cout << "Сеятель" << RESET;
            }
            else if(dynamic_cast<The_Scythe_of_Death*>(inventory[i])) {
                cout << MAGENTA << "Коса Смерти" << RESET;
            }
            else if(dynamic_cast<The_thing*>(inventory[i])) {
                cout << "Вещь" << RESET;
            }
            else if(dynamic_cast<The_Chlorophytic_saber*>(inventory[i])) {
                cout << GREEN << "Хлорофитовая сабля" << RESET;
            }
            else if(dynamic_cast<Chlorophytic_claymer*>(inventory[i])) {
                cout << GREEN << "Хлорофитовый клаймер" << RESET;
            }
            else if(dynamic_cast<Khalids_sword*>(inventory[i])) {
                cout << "Меч Халида" << RESET;
            }
            else {
                cout << "Меч #" << i+1;
            }

            cout << " (⚔️" << inventory[i]->getSharpness() << " | 📈" << inventory[i]->getLevel() << ")";
            cout << " [" << inventory[i]->getRare() << "]";
            cout << endl;
        }
        cout << CYAN << "═══════════════════════════════════════" << RESET << endl;
    }

    void changeSword() {
        if(inventory.empty()) {
            cout << "\n❌ У вас нет мечей!" << endl;
            return;
        }

        showInventory();
        cout << "Выберите номер меча для экипировки: ";

        int choice;
        cin >> choice;

        if(choice > 0 && choice <= inventory.size()) {
            currentSword = inventory[choice-1];
            cout << GREEN << "✅ Теперь экипирован: " << RESET;
            currentSword->describe();
        } else {
            cout << RED << "❌ Неверный номер!" << RESET << endl;
        }
    }

    void rest() {
        playerHP = maxPlayerHP;
        cout << GREEN << "❤️ Вы отдохнули и полностью восстановили HP!" << RESET << endl;
    }

    void fight() {
        if(!currentSword) {
            cout << "\n❌ Сначала экипируйте меч!" << endl;
            return;
        }

        // Создаем врага с балансом по уровню
        int enemyLevel = max(1, playerLevel + (rand() % 3 - 1));
        int enemyHP = 30 + (enemyLevel * 15); // Уменьшил HP врагов
        int enemyDamage = 5 + (enemyLevel * 3); // Уменьшил урон врагов

        string enemyName;
        switch(rand() % 6) {
            case 0: enemyName = "Гоблин-разбойник"; break;
            case 1: enemyName = "Орк-воин"; break;
            case 2: enemyName = "Тролль-берсерк"; break;
            case 3: enemyName = "Темный рыцарь"; break;
            case 4: enemyName = "Молодой дракон"; break;
            case 5: enemyName = "Бандит"; break;
        }

        cout << "\n" << RED << "⚔️  НАЧАЛО БИТВЫ! ⚔️" << RESET << endl;
        cout << "Ваш противник: " << enemyName << " (Уровень " << enemyLevel << ")" << endl;
        cout << "❤️ HP врага: " << enemyHP << endl;
        cout << "⚔️ Сила врага: " << enemyDamage << endl;
        cout << "\nНажмите любую клавишу для начала битвы...";
        _getch();

        int playerFightHP = playerHP;
        int enemyFightHP = enemyHP;
        defenseMode = 0;

        while(playerFightHP > 0 && enemyFightHP > 0) {
            system("cls");
            cout << "\n" << YELLOW << "═══════════════════════════════════════" << RESET << endl;
            cout << "❤️ Ваше HP: " << playerFightHP << "/" << playerHP << endl;
            cout << "👾 HP врага: " << enemyFightHP << "/" << enemyHP << endl;
            if(defenseMode > 0) {
                cout << GREEN << "🛡️ Защита активна! Получаете на 50% меньше урона" << RESET << endl;
            }
            cout << YELLOW << "═══════════════════════════════════════" << RESET << endl;

            cout << "\n⚔️ Ваш ход!" << endl;
            cout << "1. Обычная атака" << endl;
            cout << "2. Защита (уменьшает входящий урон на 50%)" << endl;

            // Показываем специальные способности для легендарных мечей
            if(dynamic_cast<Elucidator_and_Dark_Repulser*>(currentSword) ||
               dynamic_cast<Lambent_Light*>(currentSword) ||
               dynamic_cast<Dragon_Slayer*>(currentSword)) {
                cout << "3. Способность 1 (Кулдаун: " << specialCooldown[0] << ")" << endl;
                cout << "4. Способность 2 (Кулдаун: " << specialCooldown[1] << ")" << endl;
                cout << "5. Способность 3 (Кулдаун: " << specialCooldown[2] << ")" << endl;
            }

            char fightChoice = _getch();
            int damage = 0;
            bool specialUsed = false;

            switch(fightChoice) {
                case '1': // Обычная атака
                    damage = currentSword->getSharpness() / 2 + (rand() % 15);
                    cout << "💥 Обычная атака! ";
                    break;

                case '2': // Защита
                    defenseMode = 2; // Защита действует 2 хода
                    cout << "🛡️ Вы встали в защитную стойку!" << endl;
                    break;

                case '3': // Способность 1
                    if(specialCooldown[0] <= 0) {
                        specialCooldown[0] = 3;
                        currentSword->specialAbility1();
                        if(dynamic_cast<Elucidator_and_Dark_Repulser*>(currentSword)) {
                            damage = currentSword->getSharpness() * 3;
                        } else if(dynamic_cast<Lambent_Light*>(currentSword)) {
                            damage = currentSword->getSharpness() * 2.5;
                        } else if(dynamic_cast<Dragon_Slayer*>(currentSword)) {
                            damage = currentSword->getSharpness() * 3;
                        }
                        specialUsed = true;
                    } else {
                        cout << "❌ Способность перезаряжается! " << specialCooldown[0] << " ходов" << endl;
                    }
                    break;

                case '4': // Способность 2
                    if(specialCooldown[1] <= 0) {
                        specialCooldown[1] = 4;
                        currentSword->specialAbility2();
                        if(dynamic_cast<Elucidator_and_Dark_Repulser*>(currentSword)) {
                            damage = currentSword->getSharpness() * 2;
                        } else if(dynamic_cast<Lambent_Light*>(currentSword)) {
                            damage = currentSword->getSharpness() * 4;
                        } else if(dynamic_cast<Dragon_Slayer*>(currentSword)) {
                            damage = currentSword->getSharpness() * 2;
                        }
                        specialUsed = true;
                    } else {
                        cout << "❌ Способность перезаряжается! " << specialCooldown[1] << " ходов" << endl;
                    }
                    break;

                case '5': // Способность 3
                    if(specialCooldown[2] <= 0) {
                        specialCooldown[2] = 5;
                        currentSword->specialAbility3();
                        if(dynamic_cast<Elucidator_and_Dark_Repulser*>(currentSword)) {
                            damage = currentSword->getSharpness() * 5;
                        } else if(dynamic_cast<Lambent_Light*>(currentSword)) {
                            damage = currentSword->getSharpness() * 3;
                        } else if(dynamic_cast<Dragon_Slayer*>(currentSword)) {
                            damage = currentSword->getSharpness() * 4;
                        }
                        specialUsed = true;
                    } else {
                        cout << "❌ Способность перезаряжается! " << specialCooldown[2] << " ходов" << endl;
                    }
                    break;
            }

            // Применяем урон, если не защита
            if(fightChoice != '2' && (damage > 0 || specialUsed)) {
                if(!specialUsed) cout << "Урон: " << damage << endl;
                enemyFightHP -= damage;
            }

            // Проверка победы
            if(enemyFightHP <= 0) {
                cout << "\n" << GREEN << "🎉 ПОБЕДА! Вы победили " << enemyName << "!" << RESET << endl;
                wins++;

                if(wins % 2 == 0) { // Каждые 2 победы
                    playerLevel++;
                    maxPlayerHP += 15;
                    playerHP = maxPlayerHP;
                    cout << "📈 УРОВЕНЬ ПОВЫШЕН! Теперь вы " << playerLevel << " уровня!" << endl;
                }

                // Шанс получить меч с врага (40%)
                if(rand() % 100 < 40) {
                    cout << "🎁 Враг выронил меч!" << endl;

                    // Случайный меч (упрощенно)
                    int randomSword = rand() % 3;
                    Swords* loot = nullptr;
                    switch(randomSword) {
                        case 0: loot = new The_Mithril_Sword(); break;
                        case 1: loot = new Khalids_sword(); break;
                        case 2: loot = new The_Ice_Spit(); break;
                    }
                    if(loot) {
                        inventory.push_back(loot);
                        cout << "✅ Получен новый меч!" << endl;
                    }
                }

                break;
            }

            // Ход врага
            if(enemyFightHP > 0) {
                cout << "\n👾 Ход врага!" << endl;
                int enemyAttack = enemyDamage + (rand() % 10 - 5);

                // Защита уменьшает урон
                if(defenseMode > 0) {
                    enemyAttack = enemyAttack / 2;
                    cout << "🛡️ Защита уменьшила урон!" << endl;
                    defenseMode--;
                }

                if(enemyAttack < 2) enemyAttack = 2;
                playerFightHP -= enemyAttack;
                cout << "💢 " << enemyName << " нанес " << enemyAttack << " урона!" << endl;
            }

            if(playerFightHP <= 0) {
                cout << "\n" << RED << "💀 ВЫ ПРОИГРАЛИ! 💀" << RESET << endl;
                cout << "Но не отчаивайтесь! Вы восстановили половину HP!" << endl;
                playerHP = maxPlayerHP / 2;
                if(playerHP < 20) playerHP = 20;
                return;
            }

            cout << "\nНажмите любую клавишу для следующего хода...";
            _getch();
        }

        playerHP = playerFightHP;
        if(playerHP > maxPlayerHP) playerHP = maxPlayerHP;
    }

    void playerStats() {
        cout << "\n" << CYAN << "═══════════════════════════════════════" << RESET << endl;
        cout << "           📊 СТАТИСТИКА" << endl;
        cout << CYAN << "═══════════════════════════════════════" << RESET << endl;
        cout << "❤️ HP: " << playerHP << "/" << maxPlayerHP << endl;
        cout << "📈 Уровень: " << playerLevel << endl;
        cout << "🏆 Побед: " << wins << endl;
        cout << "🗡️ Мечей в коллекции: " << inventory.size() << endl;

        if(currentSword) {
            cout << "\n⚔️ Текущий меч:" << endl;
            currentSword->describe();
        }
        cout << CYAN << "═══════════════════════════════════════" << RESET << endl;
    }
};

// ===================== MAIN =====================
int main() {
    system("chcp 65001 > nul");
    system("cls");

    srand(time(0));

    Game game;
    game.start();

    return 0;
}
