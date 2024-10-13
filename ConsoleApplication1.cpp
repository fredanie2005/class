#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Entity.h"
int main() {
    // StaticObject staticObj(5.0f, 10.0f); // x = 5.0 et y = 10.0

    // Exercice 2
    Entity2 entity2({ 10.0f, 20.0f });
    entity2.afficher();
    entity2.setPosition(30.0f, 40.0f);
    entity2.afficher();

    // Exercice 3
    AMovable entity3({ 10.0f, 20.0f });
    entity3.move(5.0f, 5.0f);
    entity3.afficher();

    // Exercice 4
    Alive entity4(8.0f);
    entity4.showHp();
    entity4.damage(3.0f);
    entity4.showHp();
    entity4.heal(1.50f);
    entity4.showHp();
    entity4.resetHp();
    entity4.showHp();

    // Exercice 7
    BreakableObject obj(10, 20, 100);
    obj.recevoirDegats(50);  
    obj.recevoirDegats(60);


    // Exercice 10
    StaticObject staticObj(10.0f, 20.0f);
    BreakableObject breakableObj(15.0f, 25.0f, 100.0f);
    breakableObj.recevoirDegats(30.0f);
    breakableObj.showHp(); 
    breakableObj.recevoirDegats(80.0f); 
    Mob mob(5.0f, 10.0f, 50.0f, { 1.0f, 0.0f }); 
    mob.move(2.0f, 3.0f);
    mob.recevoirDegats(20.0f); 
    mob.showHp();
    mob.recevoirDegats(40.0f);
    Player player(0.0f, 0.0f, 100.0f, { 0.0f, 1.0f });
    player.move(1.0f, 2.0f);
    player.recevoirDegats(10.0f);
    player.showHp(); 
    player.attack(&mob); 
    mob.showHp();

    // Exercice 12


    return 0;
}