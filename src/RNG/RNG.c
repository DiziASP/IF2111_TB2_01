#include "RNG.h"

int RNG()
{
    int score = 100;
    printf("          _____                    _____                    _____          \n");
    printf("         /\\    \\                  /\\    \\                  /\\    \\         \n");
    printf("        /::\\    \\                /::\\____\\                /::\\    \\        \n");
    printf("       /::::\\    \\              /::::|   |               /::::\\    \\       \n");
    printf("      /::::::\\    \\            /:::::|   |              /::::::\\    \\      \n");
    printf("     /:::/\\:::\\    \\          /::::::|   |             /:::/\\:::\\    \\     \n");
    printf("    /:::/__\\:::\\    \\        /:::/|::|   |            /:::/  \\:::\\    \\    \n");
    printf("   /::::\\   \\:::\\    \\      /:::/ |::|   |           /:::/    \\:::\\    \\   \n");
    printf("  /::::::\\   \\:::\\    \\    /:::/  |::|   | _____    /:::/    / \\:::\\    \\  \n");
    printf(" /:::/\\:::\\   \\:::\\____\\  /:::/   |::|   |/\\    \\  /:::/    /   \\:::\\ ___\\ \n");
    printf("/:::/  \\:::\\   \\:::|    |/:: /    |::|   /::\\____\\/:::/____/  ___\\:::|    |\n");
    printf("\\::/   |::::\\  /:::|____|\\::/    /|::|  /:::/    /\\:::\\    \\ /\\  /:::|____|\n");
    printf(" \\/____|:::::\\/:::/    /  \\/____/ |::| /:::/    /  \\:::\\    /::\\ \\::/    / \n");
    printf("       |:::::::::/    /           |::|/:::/    /    \\:::\\   \\:::\\ \\/____/  \n");
    printf("       |::|\\::::/    /            |::::::/    /      \\:::\\   \\:::\\____\\    \n");
    printf("       |::| \\::/____/             |:::::/    /        \\:::\\  /:::/    /    \n");
    printf("       |::|  ~|                   |::::/    /          \\:::\\/:::/    /     \n");
    printf("       |::|   |                   /:::/    /            \\::::::/    /      \n");
    printf("       \\::|   |                  /:::/    /              \\::::/    /       \n");
    printf("        \\:|   |                  \\::/    /                \\::/____/        \n");
    printf("         \\|___|                   \\/____/                                  \n");

    srand(time(NULL));
    int x = rand() % 100;
    int tebak;
    printf("Tebakan:");
    STARTWORD();
    tebak = KataToInt(currentKata);
    while (tebak > 100 && tebak < 0)
    {
        printf("Tebakan:");
        STARTWORD();
        tebak = KataToInt(currentKata);
    }
    while (tebak != x)
    {
        if (tebak > x)
        {
            printf("Lebih kecil\n");
        }
        else
        {
            printf("Lebih besar\n");
        }
        score -= 4;
        printf("Tebakan: ");
        scanf("%d", &tebak);
    }
    printf("Ya, X adalah %d.\n", x);
    return score;
}