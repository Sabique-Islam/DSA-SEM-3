#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./structures.h"

int main()
{
    srand(time(NULL));

    Player player = {"", 100, 50, 50, 1};
    Inventory inv = {0, 0, 0};

    printf("Welcome to Survival Island!\n");
    printf("Enter your name: ");
    scanf("%s", player.name);

    while (player.health > 0)
    {
        printStatus(player, inv);

        Event e = getRandomEvent();
        printf("\nEvent: %s\n", e.description);
        applyEvent(&player, e);

        performAction(&player, &inv);

        player.hunger -= 5;
        player.thirst -= 5;

        if (player.hunger <= 0 || player.thirst <= 0)
        {
            player.health -= 10;
            printf("You are starving or dehydrated!\n");
        }

        player.day++;
        printf("\n--- End of Day %d ---\n", player.day);
        getchar();
    }

    printf("\nYou died on day %d. RIP %s.\n", player.day, player.name);
    return 0;
}