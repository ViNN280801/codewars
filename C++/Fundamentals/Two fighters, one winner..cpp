// Task: Create a function that returns the name of the winner in a fight between two fighters.
// Each fighter takes turns attacking the other and whoever kills the other first is victorious.
// Death is defined as having health <= 0.
// Each fighter will be a Fighter object/instance.
// See the Fighter class below in your chosen language.
// Both health and damagePerAttack (damage_per_attack for python)
// will be integers larger than 0. You can mutate the Fighter objects.
// Your function also receives a third argument, a string, with the name of the fighter that attacks first.

#include <iostream>
#include <string>

class Fighter
{
private:
    std::string name;
    int health;
    int damagePerAttack;

public:
    explicit Fighter(std::string name, int health, int damagePerAttack)
    {
        this->name = name;
        this->health = health;
        this->damagePerAttack = damagePerAttack;
    }

    virtual ~Fighter(){};

    std::string getName() { return name; }
    int getHealth() { return health; }
    int getDamagePerAttack() { return damagePerAttack; }

    void setHealth(int value) { health = value; }
};

void printAttack(Fighter *defender, Fighter *attacker)
{
    std::cout << defender->getName() << ": " << defender->getHealth() << " HP\t"
              << attacker->getName() << " has " << attacker->getHealth() << " HP\n";
    std::cout << attacker->getName() << " attacks " << defender->getName() << "; "
              << defender->getName() << " now has "
              << defender->getHealth() - attacker->getDamagePerAttack() << std::endl;
}

std::string doAttack(Fighter *defender, Fighter *attacker)
{
    for (;;)
    {
        defender->setHealth(defender->getHealth() - attacker->getDamagePerAttack());
        // printAttack(defender, attacker);
        if (defender->getHealth() <= 0)
            return attacker->getName();
        attacker->setHealth(attacker->getHealth() - defender->getDamagePerAttack());
        // printAttack(attacker, defender);
        if (attacker->getHealth() <= 0)
            return defender->getName();
    }
    return "Error: doAttack()\n";
}

std::string declareWinner(Fighter *fighter1, Fighter *fighter2, std::string firstAttacker)
{
    if (firstAttacker == fighter1->getName())
        return doAttack(fighter2, fighter1);
    else if (firstAttacker == fighter2->getName())
        return doAttack(fighter1, fighter2);
    else
        return "Error! There is no fighter with name " + firstAttacker + '\n';
}

std::string declareWinner_clever(Fighter *fighter1, Fighter *fighter2, std::string firstAttacker)
{
    int countOfHitsOfFirst{(fighter1->getHealth() - 1) / fighter2->getDamagePerAttack()},
        countOfHitsOfSecond{(fighter2->getHealth() - 1) / fighter1->getDamagePerAttack()};
    return (countOfHitsOfFirst > countOfHitsOfSecond)   ? fighter1->getName()
           : (countOfHitsOfFirst < countOfHitsOfSecond) ? fighter2->getName()
                                                        : firstAttacker;
}

int main()
{
    return EXIT_SUCCESS;
}
