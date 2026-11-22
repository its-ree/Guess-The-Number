#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

/* ── ANSI Colors ── */
#define RST   "\033[0m"
#define BOLD  "\033[1m"
#define DIM   "\033[2m"
#define BLINK "\033[5m"

#define BLK   "\033[30m"
#define RED   "\033[31m"
#define GRN   "\033[32m"
#define YEL   "\033[33m"
#define BLU   "\033[34m"
#define MAG   "\033[35m"
#define CYN   "\033[36m"
#define WHT   "\033[37m"

#define BRED  "\033[91m"
#define BGRN  "\033[92m"
#define BYEL  "\033[93m"
#define BCYN  "\033[96m"
#define BWHT  "\033[97m"

/* ── Enable ANSI on Windows ── */
void enableAnsi(void) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD m = 0;
    GetConsoleMode(h, &m);
    SetConsoleMode(h, m | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void cls(void) { system("cls"); }

void msleep(int ms) { Sleep(ms); }

void hideCursor(void) { printf("\033[?25l"); }
void showCursor(void) { printf("\033[?25h"); }

/* ── Typing effect ── */
void typeText(const char *text, int delayMs, const char *color) {
    printf("%s", color);
    for (int i = 0; text[i]; i++) {
        putchar(text[i]);
        fflush(stdout);
        msleep(delayMs);
    }
    printf(RST);
}

/* ── Glitch line: random hex garbage ── */
void glitchLine(int len) {
    const char hex[] = "0123456789ABCDEF";
    printf(DIM GRN);
    for (int i = 0; i < len; i++) {
        putchar(hex[rand() % 16]);
    }
    printf(RST "\n");
}

/* ── Fake loading bar ── */
void loadingBar(const char *label, int width, int durationMs, const char *color) {
    int stepMs = durationMs / width;
    printf("  %s%s [", color, label);
    for (int i = 0; i < width; i++) {
        putchar('#');
        fflush(stdout);
        msleep(stepMs);
    }
    printf("] DONE" RST "\n");
}

/* ── Matrix rain splash ── */
void matrixSplash(int lines) {
    const char chars[] = "01@#$%&*!?<>{}[]|/\\~^";
    for (int row = 0; row < lines; row++) {
        printf("  ");
        for (int col = 0; col < 60; col++) {
            int r = rand() % 10;
            if (r < 3)       printf(BGRN "%c", chars[rand() % (int)strlen(chars)]);
            else if (r < 5)  printf(DIM GRN "%c", chars[rand() % (int)strlen(chars)]);
            else             printf(DIM BLK " ");
        }
        printf(RST "\n");
        msleep(30);
    }
}

/* ── Scramble-reveal text effect ── */
void scrambleReveal(const char *text, const char *color) {
    int len = (int)strlen(text);
    char buf[256];
    const char glyphs[] = "@#$%&!?*<>{}";

    for (int pass = 0; pass < 6; pass++) {
        printf("\r  %s", color);
        for (int i = 0; i < len; i++) {
            if (pass >= 5 || (rand() % 6) < pass) {
                buf[i] = text[i];
            } else {
                buf[i] = glyphs[rand() % (int)strlen(glyphs)];
            }
        }
        buf[len] = '\0';
        printf("%s", buf);
        fflush(stdout);
        msleep(80);
    }
    printf("\r  %s%s" RST "\n", color, text);
}

/* ── Sound effects ── */
void sndWrong(void) {
    Beep(150, 80);
    Beep(100, 100);
}

void sndWin(void) {
    Beep(400, 100);
    Beep(500, 100);
    Beep(600, 100);
    Beep(800, 300);
}

void sndStartup(void) {
    Beep(300, 60);
    Beep(400, 60);
    Beep(500, 60);
    Beep(600, 80);
}

/* ── Flush stdin ── */
void flushIn(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ── Boot Sequence ── */
void bootSequence(void) {
    cls();
    hideCursor();

    matrixSplash(6);
    msleep(200);

    printf("\n");
    typeText("  [SYS] Initializing kernel...", 20, DIM GRN);
    msleep(300);
    printf(BGRN " OK\n" RST);

    typeText("  [SYS] Loading cipher module...", 20, DIM GRN);
    msleep(200);
    printf(BGRN " OK\n" RST);

    typeText("  [SYS] Establishing secure channel...", 20, DIM GRN);
    msleep(400);
    printf(BGRN " OK\n" RST);

    printf("\n");
    loadingBar("DECRYPTING", 30, 800, BGRN);
    loadingBar("DEPLOYING ", 30, 600, GRN);
    printf("\n");
    msleep(200);

    sndStartup();

    /* Title */
    printf(BOLD BGRN);
    printf("      _______________________________________________\n");
    printf("     |                                               |\n");
    printf("     |");
    printf(BOLD BRED " >>>  ");
    printf(BOLD BWHT "G U E S S   T H E   N U M B E R");
    printf(BOLD BRED "  <<< ");
    printf(BOLD BGRN "|\n");
    printf("     |");
    printf(DIM GRN  "             [ v1.0  //  CRACKED ]              ");
    printf(BOLD BGRN "|\n");
    printf("     |_______________________________________________|\n");
    printf(RST "\n");

    msleep(300);

    for (int i = 0; i < 3; i++) {
        glitchLine(55);
        msleep(60);
    }

    printf("\n");
    showCursor();
}

/* ── Encrypt/Generating animation ── */
void generatingAnimation(int maxNum) {
    hideCursor();
    printf("\n");
    typeText("  [CRYPTO] Generating secure target...", 15, DIM CYN);
    printf("\n");

    for (int i = 0; i < 12; i++) {
        printf("\r  " DIM GRN ">> TARGET HASH: 0x");
        for (int j = 0; j < 8; j++) {
            printf("%X", rand() % 16);
        }
        printf("  [%d-%d]" RST, 0, maxNum);
        fflush(stdout);
        msleep(80);
    }
    printf("\r  " BGRN ">> TARGET LOCKED: 0x");
    for (int j = 0; j < 8; j++) printf("%X", rand() % 16);
    printf("  [%d-%d]" RST, 0, maxNum);

    printf("\n");
    typeText("  [CRYPTO] Target encrypted. Begin cracking.\n", 15, DIM CYN);
    printf("\n");
    showCursor();
}

/* ── Hint display ── */
void showHint(int higher) {
    if (higher) {
        printf("\n");
        printf("  " BOLD BCYN "  +-------------------------------+" RST "\n");
        printf("  " BOLD BCYN "  |  " BWHT "[^] SIGNAL: AIM HIGHER        " BCYN "|" RST "\n");
        printf("  " BOLD BCYN "  +-------------------------------+" RST "\n");
        printf("\n");
    } else {
        printf("\n");
        printf("  " BOLD BRED "  +-------------------------------+" RST "\n");
        printf("  " BOLD BRED "  |  " BWHT "[v] SIGNAL: AIM LOWER         " BRED "|" RST "\n");
        printf("  " BOLD BRED "  +-------------------------------+" RST "\n");
        printf("\n");
    }
}

/* ── Win display ── */
void showWin(int secret, int attempts) {
    hideCursor();
    cls();

    matrixSplash(4);
    printf("\n");

    sndWin();

    printf(BOLD BGRN);
    printf("      _______________________________________________\n");
    printf("     |                                               |\n");
    printf("     |" BOLD BYEL "         >>> ACCESS GRANTED <<<               " BGRN "|\n");
    printf("     |_______________________________________________|\n");
    printf(RST "\n");

    msleep(300);

    scrambleReveal(">> DECRYPTION COMPLETE", BOLD BGRN);
    msleep(200);

    printf("\n");
    printf("  " DIM GRN "+-------------------------------------------+" RST "\n");
    printf("  " DIM GRN "|" RST "                                           " DIM GRN "|" RST "\n");
    printf("  " DIM GRN "|" BOLD BWHT "    C O N G R A T U L A T I O N S !       " DIM GRN " |" RST "\n");
    printf("  " DIM GRN "|" RST "                                           " DIM GRN "|" RST "\n");
    printf("  " DIM GRN "|" RST "    Target cracked: " BOLD BYEL "%-6d                " DIM GRN "|" RST "\n", secret);
    printf("  " DIM GRN "|" RST "    Attempts used:  " BOLD BYEL "%-6d                " DIM GRN "|" RST "\n", attempts);
    printf("  " DIM GRN "|" RST "                                           " DIM GRN "|" RST "\n");

    if (attempts <= 3)
        printf("  " DIM GRN "|" BOLD BRED "    Rank: [ELITE HACKER]                  " DIM GRN " |" RST "\n");
    else if (attempts <= 7)
        printf("  " DIM GRN "|" BOLD BCYN "    Rank: [SKILLED CRACKER]               " DIM GRN " |" RST "\n");
    else if (attempts <= 15)
        printf("  " DIM GRN "|" BOLD BYEL "    Rank: [SCRIPT KIDDIE]                 " DIM GRN " |" RST "\n");
    else
        printf("  " DIM GRN "|" BOLD DIM WHT "    Rank: [BRUTE FORCER]                  " DIM GRN " |" RST "\n");

    printf("  " DIM GRN "|" RST "                                           " DIM GRN "|" RST "\n");
    printf("  " DIM GRN "+-------------------------------------------+" RST "\n");
    printf("\n");

    for (int i = 0; i < 3; i++) {
        glitchLine(50);
        msleep(40);
    }
    printf("\n");
    showCursor();
}


/* ========== MAIN ========== */
int main(void) {
    int maxNum, secret, guess, attempts;
    char again;

    enableAnsi();
    srand((unsigned int)time(NULL));

    bootSequence();

    do {
        /* ── Get Range ── */
        printf("  " DIM GRN "[>]" RST " Set target range " DIM "(0 to ?): " RST);
        while (scanf("%d", &maxNum) != 1 || maxNum < 1) {
            flushIn();
            printf("  " BRED "[!] Invalid. Enter a number >= 1: " RST);
        }
        flushIn();

        /* ── Generate ── */
        secret = rand() % (maxNum + 1);
        attempts = 0;

        generatingAnimation(maxNum);

        /* ── Game Loop ── */
        while (1) {
            printf("  " DIM GRN "[ATTEMPT %d]" BWHT " Crack >> " RST, attempts + 1);

            if (scanf("%d", &guess) != 1) {
                flushIn();
                printf("  " BRED "[ERR] Numeric input required.\n" RST);
                continue;
            }
            flushIn();
            attempts++;

            if (guess < secret) {
                sndWrong();
                showHint(1);
            } else if (guess > secret) {
                sndWrong();
                showHint(0);
            } else {
                showWin(secret, attempts);
                break;
            }
        }

        /* ── Play Again ── */
        printf("  " DIM GRN "[>]" BWHT " Retry breach? " DIM "(y/n): " RST);
        scanf(" %c", &again);
        flushIn();

        if (again == 'y' || again == 'Y') {
            cls();
            printf("\n");
            typeText("  [SYS] Reinitializing...\n\n", 20, DIM GRN);
            msleep(300);
        }

    } while (again == 'y' || again == 'Y');

    cls();
    printf("\n");
    typeText("  [SYS] Connection terminated.\n", 25, DIM GRN);
    typeText("  [SYS] Goodbye, operator.\n\n", 25, DIM GRN);
    msleep(500);

    return 0;
}
