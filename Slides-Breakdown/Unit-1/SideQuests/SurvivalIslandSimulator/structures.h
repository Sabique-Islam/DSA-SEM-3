#ifndef STRUCT_H
#define STRUCT_H

typedef struct
{
    char name[20];
    int health;
    int hunger;
    int thirst;
    int day;
} Player;

typedef struct
{
    int wood;
    int fish;
    int water;
    int stone;
} Inventory;

typedef struct
{
    char description[100];
    int healthChange;
    int hungerChange;
    int thirstChange;
} Event;

void printStatus(Player p, Inventory inv);
void applyEvent(Player *p, Event e);
Event getRandomEvent();
void performAction(Player *p, Inventory *inv);

#endif