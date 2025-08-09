#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./structures.h"

void printStatus(Player p, Inventory inv)
{
    printf("\nDay: %d | %s\n", p.day, p.name);
    printf("Health: %d | Hunger: %d | Thirst: %d\n",
           p.health, p.hunger, p.thirst);
    printf("Inventory → Wood: %d | Fish: %d | Water: %d\n",
           inv.wood, inv.fish, inv.water);
}

void applyEvent(Player *p, Event e)
{
    p->health += e.healthChange;
    p->hunger += e.hungerChange;
    p->thirst += e.thirstChange;

    if (p->health > 100)
        p->health = 100;
    if (p->hunger > 100)
        p->hunger = 100;
    if (p->thirst > 100)
        p->thirst = 100;
}

Event getRandomEvent()
{
    Event events[] = {
        {"You found a coconut tree! +10 thirst", 0, 0, 10},
        {"A wild boar attacked you! -20 health", -20, 0, 0},
        {"It rained! +5 thirst", 0, 0, 5},
        {"You found wild berries! +10 hunger", 0, 10, 0},
        {"You slipped and hurt yourself! -10 health", -10, 0, 0}};
    return events[rand() % 5];
}

void performAction(Player *p, Inventory *inv)
{
    int choice;
    printf("\nChoose your action:\n");
    printf("1. Hunt for fish (+food)\n");
    printf("2. Collect water\n");
    printf("3. Gather wood\n");
    printf("4. Rest (+health)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("🎣 You caught a fish!\n");
        inv->fish++;
        p->hunger += 15;
        break;
    case 2:
        printf("You collected fresh water!\n");
        inv->water++;
        p->thirst += 15;
        break;
    case 3:
        printf("You gathered wood!\n");
        inv->wood++;
        break;
    case 4:
        printf("You rested and regained health.\n");
        p->health += 10;
        break;
    default:
        printf("Invalid choice. You wasted the day.\n");
    }
}