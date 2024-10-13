#include "Entity.h"
// Exercice 1 : Classe Entity
float Entity::getxPos() {
    return x;
}

float Entity::getyPos() {
    return y;
}

void Entity::setxPos(float nx) {
    x = nx;
}

void Entity::setyPos(float ny) {
    y = ny;
}

// Exercice 2 : Classe Entity2
Entity2::Entity2(std::vector<float> Vector2) : Vector2(Vector2) {}

void Entity2::afficher() const {
    std::cout << "Position: (" << Vector2[0] << ", " << Vector2[1] << ")" << std::endl;
}

void Entity2::setPosition(float x, float y) {
    Vector2[0] = x;
    Vector2[1] = y;
}

std::vector<float> Entity2::getPosition() const {
    return Vector2;
}

// Exercice 3 : Classe AMovable
AMovable::AMovable(std::vector<float> Vector2) : Vector2(Vector2), v(0) {}

void AMovable::setPosition(float x, float y) {
    Vector2[0] = x;
    Vector2[1] = y;
}

void AMovable::setSpeed(float nv) {
    v = nv;
}

void AMovable::move(float x, float y) {
    Vector2[0] += x;
    Vector2[1] += y;
}

void AMovable::afficher() const {
    std::cout << "Position: (" << Vector2[0] << ", " << Vector2[1] << ")" << std::endl;
}

// Exercice 4 : Classe Alive
Alive::Alive(float max_hp) : max_hp(max_hp), hp(max_hp) {}

void Alive::resetHp() {
    hp = max_hp;
}

void Alive::heal(float value) {
    hp += value;
    if (hp > max_hp) hp = max_hp;
}

void Alive::damage(float value) {
    hp -= value;
    if (hp < 0) hp = 0;
}

void Alive::showHp() const {
    std::cout << "HP: " << hp << "/" << max_hp << std::endl;
}

float Alive::getHp() const {
    return hp;
}

float Alive::getMaxHp() const {
    return max_hp;
}

void Alive::recevoirDegats(float valeur) {
    damage(valeur);
}

// Exercice 5 : Interface IAttacker
IAttacker::~IAttacker() {}

// Exercice 6 : Classe StaticObject
StaticObject::StaticObject(float xPos, float yPos) {
    setxPos(xPos);
    setyPos(yPos);
    std::cout << "Static Object just created at x = " << x << " and y = " << y << std::endl;
}

// Exercice 7 : Classe BreakableObject
BreakableObject::BreakableObject(float xPos, float yPos, float maxLife) : Alive(maxLife) {
    setxPos(xPos);
    setyPos(yPos);
    resetHp();

    std::cout << "Breakable Object just created at x = " << getxPos()
        << " and y = " << getyPos()
        << " with " << getMaxHp() << " life" << std::endl;
}

void BreakableObject::recevoirDegats(float valeur) {
    Alive::recevoirDegats(valeur);
    if (getHp() <= 0) {
        std::cout << "Breakable Object just broke" << std::endl;
    }
}

// Exercice 8 : Classe Mob
Mob::Mob(float xPos, float yPos, float maxLife, std::vector<float> direction) : Alive(maxLife), AMovable(direction) {
    setxPos(xPos);
    setyPos(yPos);
    resetHp();

    std::cout << "Mob just created at x = " << getxPos() << " and y = " << getyPos()
        << " with " << getMaxHp() << " life " << "with direction x = " << direction[0] << " and y = " << direction[1] << std::endl;
}

void Mob::recevoirDegats(float valeur) {
    Alive::recevoirDegats(valeur);
    if (getHp() <= 0) {
        std::cout << "Mob just died" << std::endl;
    }
}

void Mob::move(float x, float y) {
    setxPos(getxPos() + x);
    setyPos(getyPos() + y);
    std::cout << "Mob move to x = " << getxPos() << " and y = " << getyPos() << std::endl;
    AMovable::move(x, y);
}


// Exercice 9 : Classe Player
Player::Player(float xPos, float yPos, float maxLife, std::vector<float> direction) : Alive(maxLife), AMovable(direction) {
    setxPos(xPos);
    setyPos(yPos);
    resetHp();

    std::cout << "Player just created at x = " << getxPos() << " and y = " << getyPos() << " with " << getMaxHp() << " life " << "with direction x = " << direction[0] << " and y = " << direction[1] << std::endl;
}

void Player::recevoirDegats(float valeur) {
    Alive::recevoirDegats(valeur);
    if (getHp() <= 0) {
        std::cout << "Player just died" << std::endl;
    }
}

void Player::move(float x, float y) {
    setxPos(getxPos() + x);
    setyPos(getyPos() + y);
    std::cout << "Player move to x = " << getxPos() << " and y = " << getyPos() << std::endl;
    AMovable::move(x, y);
}

void Player::attack(Alive* alive) {
    alive->recevoirDegats(10);
    std::cout << "Player just attacked." << std::endl;
}

// Exercice 11 Classe World
void World::Init() {
    entities.push_back(std::make_unique<StaticObject>(0, 1));
    entities.push_back(std::make_unique<BreakableObject>(2, 3, 1));
    entities.push_back(std::make_unique<Mob>(4, 5, 20, std::vector<float>{0.1f, 0.2f}));
    entities.push_back(std::make_unique<Player>(6, 7, 10, std::vector<float>{0.3f, 0.4f}));
}

void World::Step() {

}
