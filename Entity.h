#pragma once
#include <iostream>
#include <vector>
#include <memory>

// Exercice 1 : Classe Entity
class Entity {
public:
    float x;
    float y;

    float getxPos();
    float getyPos();
    void setxPos(float nx);
    void setyPos(float ny);
};

// Exercice 2 : Classe Entity2
class Entity2 {
private:
    std::vector<float> Vector2;

public:
    Entity2(std::vector<float> Vector2 = { 0.0f, 0.0f });
    virtual void afficher() const;
    virtual void setPosition(float x, float y);
    virtual std::vector<float> getPosition() const;
};

// Exercice 3 : Classe AMovable
class AMovable {
private:
    std::vector<float> Vector2;
    float v;

public:
    AMovable(std::vector<float> Vector2 = { 0.0f, 0.0f });
    virtual void setPosition(float x, float y);
    virtual void setSpeed(float nv);
    virtual void move(float x, float y);
    virtual void afficher() const;
};

// Exercice 4 : Classe Alive
class Alive {
private:
    float max_hp;
    float hp;

public:
    Alive(float max_hp = 0);
    virtual void resetHp();
    virtual void heal(float value);
    virtual void damage(float value);
    virtual void showHp() const;
    float getHp() const;
    float getMaxHp() const;
    virtual void recevoirDegats(float valeur);
};

// Exercice 5 : Interface IAttacker
class IAttacker {
public:
    virtual ~IAttacker();
    virtual void attack(class Alive* alive) = 0; // Méthode pure
};

// Exercice 6 : Classe StaticObject
class StaticObject : public Entity {
public:
    StaticObject(float xPos, float yPos);
};

// Exercice 7 : Classe BreakableObject
class BreakableObject : public Entity, public Alive {
public:
    BreakableObject(float xPos, float yPos, float maxLife);
    void recevoirDegats(float valeur) override;
};

// Exercice 8 : Classe Mob
class Mob : public Entity, public Alive, public AMovable {
public:
    Mob(float xPos, float yPos, float maxLife, std::vector<float> direction);
    void recevoirDegats(float valeur) override;
    void move(float x, float y) override;
};

// Exercice 9 : Classe Player
class Player : public Entity, public Alive, public AMovable, public IAttacker {
public:
    Player(float xPos, float yPos, float maxLife, std::vector<float> direction);
    void recevoirDegats(float valeur) override;
    void move(float x, float y) override;
    void attack(Alive* alive) override;
};

// Exercice 11 Classe World
class World {
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void Init();
    void Step();
};
