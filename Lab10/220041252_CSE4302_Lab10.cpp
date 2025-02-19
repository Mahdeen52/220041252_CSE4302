#include <iostream>
#include<string>
#include<vector>
using namespace std;


class CharacterActions{
    public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats() const = 0;
    virtual bool isAlive() const = 0;
    virtual int getAttackPower() const = 0;
    virtual int getSpecialAbilityPower() const = 0;
    virtual string getName() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual int getMana() const = 0;
    virtual void resetMana() = 0;
    virtual ~CharacterActions() = default;
};


class BaseCharacter : public CharacterActions {
    protected: string name;
                int health; 
                int mana;
                int attackpower;
                string SpecialAbility;
                int SpecialAbilitypower;

    public:
    BaseCharacter(const string& n, int hp, int ap, const string& sa, int sap)
        : name(n), health(hp), mana(0), attackpower(ap), SpecialAbility(sa), SpecialAbilitypower(sap) {}

        void attack() override {
            cout<<name<<"Attacks with power"<<attackpower<<endl;
            mana+=50;
        }


        void defend() override {
            cout<<name<<"takes"<<attackpower<<"damage. Health now:"<<health<<endl;
        }


        void useSpecialAbility() override {
           if(mana>=100) {
            cout<<name<<"uses "<<SpecialAbility<<" with power "<<SpecialAbilitypower<<endl;
            mana = 0;
           }

           else cout<<name<<"cannot use mana"<<endl;
        }


        void takeDamage(int damage) {
            health -= damage;
            if (health < 0) health = 0;
        }

    bool isAlive() const override{
        return health > 0;
    }

    void displayStats() const override {
        cout << name << " - Health: " << health << ", Mana: " << mana << endl;
    }

    int getAttackPower() const override {
        return attackpower;
    }

    int getSpecialAbilityPower() const override {
        return SpecialAbilitypower;
    }

    string getName() const override {
        return name;
    }

    int getMana() const override {
        return mana;
    }

    void resetMana() override {
        mana = 0;
    }
};

class Warrior : public BaseCharacter {
public:
    Warrior() : BaseCharacter("Warrior", 100, 25, "Berserk Rage", 35) {}
};

class Mage : public BaseCharacter {
public:
    Mage() : BaseCharacter("Mage", 120, 20, "Arcane Blast", 30) {}
};

class Archer : public BaseCharacter {
public:
    Archer() : BaseCharacter("Archer", 90, 20, "Fire Arrow", 35) {}
};



class BossEnemy {
    protected: int health;
               int attackpower;

    public: BossEnemy() : health(150), attackpower(30) {}

    void attack(CharacterActions& character) {
        cout<<"Boss attacks"<<character.getName()<<"with power"<< attackpower << "!" << endl;
        character.takeDamage(attackpower);
    }

    void defend(CharacterActions& character) {
        cout<<"Boss takes"<<attackpower<<"damage!" << endl;
    }

   void takeDamage(int damage) {
            health -= damage;
            if (health < 0) health = 0;
        }

    bool isDefeated() const {
        return health <= 0;
    }

    int getHealth() const {
        return health;
    }

    void displayHealth() const {
        cout << "Boss Health: " << health << endl;
    }
};



class GameEngine {
public:

bool allPlayersAlive(const vector<CharacterActions*>& players) const {
        for (auto player : players) {
            if (!player->isAlive()) return false;
        }
        return true;
    }

    void playGame(vector<CharacterActions*>& players, BossEnemy& boss) {
        cout << "Game begins! Players vs. Boss" << endl;

        while (!boss.isDefeated() && allPlayersAlive(players)) {
        
            for (auto player : players) {
                if (player->isAlive()) {
                    player->attack();
                    boss.takeDamage(player->getAttackPower());
                    boss.defend(*player);
                    boss.displayHealth();
                    if(!boss.getHealth()) {
                            break;
                    }

                    if (player->getMana() >= 100) {
                        player->useSpecialAbility();
                        boss.takeDamage(player->getSpecialAbilityPower());
                        boss.displayHealth();
                        if(!boss.getHealth()) {
                            break;
                    }
                    }
                }
            }

         
            for (auto player : players) {
                if (boss.isDefeated()) break;
                if (player->isAlive()) {
                    boss.attack(*player);
                    player->displayStats();
                }
            }
        }

       
        if (boss.isDefeated()) {
            cout << "Boss defeated! Players win!" << endl;
        } else {
            cout << "Players defeated! Boss wins!" << endl;
        }
    }
   

};

int main() {

    Warrior warrior;
    Mage mage;
    Archer archer;
    vector<CharacterActions*> players = { &warrior, &mage, &archer };
    BossEnemy boss;


    GameEngine game;
    game.playGame(players, boss);

    return 0;
}

