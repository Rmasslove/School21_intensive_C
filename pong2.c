// Дебажьте, наслаждайтесь программированием, вроде собирается, но везде баги есть.
// Из каждой функции нужны ретёрны переменных, которые надо сохранить/изменить.
// Не забывайте про клэнг формат.

#include <stdio.h>
#include <stdlib.h>

char getInput();
int updateRacket(float currentPlayer, int playerOneY, int playerTwoY, int displaySizeY);
void updateBall(int ballDirectionX, int ballDirectionY, int ballX, int playerOneY, int playerTwoY, int ballY,
                int displaySizeX, int displaySizeY);
float updateGameField(float currentPlayer, int playerOneY, int playerTwoY, int displaySizeX, int displaySizeY,
                      int ballDirectionX, int ballDirectionY, int ballX, int ballY);
// void printGameField(int currentPlayer, int playerOneY, int playerTwoY, int displaySizeX, int displaySizeY,
//                     int ballDirectionX, int ballDirectionY, int ballX, int ballY);
void printGameField(int ll1, int ll2, int ll3, int lr1, int lr2, int lr3, int ballX, int ballY,
                    float currentPlayer);

int main() {
    // положение левой ракетки
    int ll1 = 13;
    int ll2 = 14;
    int ll3 = 15;
    // положение правой ракетки
    int lr1 = 15;
    int lr2 = 16;
    int lr3 = 17;

    int displaySizeX = 80;
    int displaySizeY = 25;

    int playerOneY = displaySizeY / 2;
    int playerTwoY = displaySizeY / 2;

    //	int playerOneScore = 0;
    //	int playerTwoScore = 0;

    float currentPlayer = 0.1;

    int ballX = displaySizeX / 2;
    int ballY = displaySizeY / 2;

    int ballDirectionX = 1;
    int ballDirectionY = 1;

    // Цикл игры до победы какого-либо игрока
    while (1) {
        currentPlayer = updateGameField(currentPlayer, playerOneY, playerTwoY, displaySizeX, displaySizeY,
                                        ballDirectionX, ballDirectionY, ballX, ballY);
        int a = currentPlayer / 1;
        currentPlayer = currentPlayer - a;
        int switchPl = currentPlayer * 10;
        if (switchPl == 1) {
            playerOneY = a;
        } else if (switchPl == 2) {
            playerTwoY = a;
        }

        printGameField(ll1, ll2, ll3, lr1, lr2, lr3, ballX, ballY, currentPlayer);
    }

    return 0;
}

/// @brief Получение направления движения из окна терминала
/// @return Символ-направление движения
char getInput() {
    char input;

    while (input != ' ' && input != 'a' && input != 'z' && input != 'k' && input != 'm') {
        scanf("%c", &input);
    }

    return input;
}

/// @brief Перемещение ракетки в зависимости от нажатой клавиши в заданном диапазоне
/// @param currentPlayer Игрок, совершающий ход
/// @param playerOneY Координаты центра ракетки первого игрока
/// @param playerTwoY Координаты центра ракетки второго игрока
/// @param displaySizeY Разрешение окна по вертикали
int updateRacket(float currentPlayer, int playerOneY, int playerTwoY, int displaySizeY) {
    char input = getInput();
    int result;
    int switchPl = currentPlayer * 10;

    printf("switchPl === %d\n", switchPl);

    if (input == ' ') {
        return 200;
    }

    switch (switchPl) {
        case 1:
            if ((input == 'a') && (playerOneY > 0 + 1)) {
                --playerOneY;
                result = playerOneY;

            } else if ((input == 'z') && (playerOneY < displaySizeY - 1)) {
                ++playerOneY;
                result = playerOneY;
            }
            break;

        case 2:
            if ((input == 'k') && (playerTwoY > 0 + 1)) {
                --playerTwoY;
                result = playerTwoY;

            } else if ((input == 'm') && (playerTwoY < displaySizeY - 1)) {
                ++playerTwoY;
                result = playerTwoY;
            }
            break;
    }
    printf("result === %d\n", result);
    return result;
}

/// @brief Изменение положения мяча на экране
/// @param ballDirectionX Задание перемещения мяча по горизонтали (0 - влево, 1 - вправо)
/// @param ballDirectionY Задание перемещения мяча по вертикали (0 - вниз, 1 - вверх)
/// @param ballX Координаты мяча по оси X
/// @param ballY Координаты мяча по оси Y
/// @param playerOneY Координаты центра ракетки первого игрока
/// @param playerTwoY Координаты центра ракетки второго игрока
/// @param displaySizeX Разрешение окна по горизонтали
/// @param displaySizeY Разрешение окна по вертикали
void updateBall(int ballDirectionX, int ballDirectionY, int ballX, int ballY, int playerOneY, int playerTwoY,
                int displaySizeX, int displaySizeY) {
    switch (ballDirectionX) {
        case 0:
            if (ballX > 0) {
                --ballX;
            }
            break;

        case 1:
            if (ballX < displaySizeX) {
                ++ballX;
            }
            break;
    }
    switch (ballDirectionY) {
        case 0:
            if (ballY > 0) {
                --ballY;
            }
            break;
        case 1:
            if (ballY < displaySizeY) {
                ++ballY;
            }
            break;
    }

    if (ballDirectionX == 0 && ballX == 0 + 2 &&
        (ballY == playerOneY + 1 || ballY == playerOneY || ballY == playerOneY - 1)) {
        ballDirectionX = 1;
    }
    if (ballDirectionX == 1 && ballX == displaySizeX - 2 &&
        (ballY == playerTwoY + 1 || ballY == playerTwoY || ballY == playerTwoY - 1)) {
        ballDirectionX = 0;
    }
}

/// @brief Выполнение обработки событий на игровом поле (перемещение мяча, игроков, определение хода и т.д.)
/// @param currentPlayer Номер игрока, совершающего текущий ход
/// @param playerOneY Координаты центра ракетки первого игрока
/// @param playerTwoY Координаты центра ракетки второго игрока
/// @param displaySizeX Разрешение окна по горизонтали
/// @param displaySizeY Разрешение окна по вертикали
/// @param ballDirectionX Задание перемещения мяча по горизонтали (0 - влево, 1 - вправо)
/// @param ballDirectionY Задание перемещения мяча по вертикали (0 - вниз, 1 - вверх)
/// @param ballX Координаты мяча по оси X
/// @param ballY Координаты мяча по оси Y
/// @return Номер игрока, совершающего следующий ход
float updateGameField(float currentPlayer, int playerOneY, int playerTwoY, int displaySizeX, int displaySizeY,
                      int ballDirectionX, int ballDirectionY, int ballX, int ballY) {
    int dif = updateRacket(currentPlayer, playerTwoY, playerTwoY, displaySizeY);
    printf("dif>>%d\n", dif);
    int switchPl = currentPlayer * 10;
    switchPl = switchPl == 1 ? 2 : 1;
    currentPlayer = switchPl * 0.1;

    float result;

    if (dif < 200) {
        result = currentPlayer + dif;

    } else {
        result = currentPlayer + 0;
    }

    updateBall(ballDirectionX, ballDirectionY, ballX, ballY, playerOneY, playerTwoY, displaySizeX,
               displaySizeY);
    printf("%f\n", result);
    return result;
}

void printGameField(int ll1, int ll2, int ll3, int lr1, int lr2, int lr3, int ballX, int ballY,
                    float currentPlayer) {
    // system("clear");

    int lx1 = 80;
    while (lx1 > 0) {  // Отрисовка верхний горизонтальной линии
        printf("-");
        lx1 -= 1;
    }
    printf("\n");

    // Блок отррисовки вертикальных элементов
    int ly = 23;

    while (ly > 0) {
        printf("|");
        int space = 79;
        while (space > 0) {
            if ((space != 78 || (ly != ll1 && ly != ll2 && ly != ll3)) &&
                (space != 3 || (ly != lr1 && ly != lr2 && ly != lr3)) && space != 1 && space != 40 &&
                (space != ballX || ly != ballY)) {
                printf(" ");
            }
            if (space == 1) {
                printf("|");
            }
            if (space == 40 && (space != ballX || ly != ballY)) {
                printf("|");
            }
            if (space == 78 && (ly == ll1 || ly == ll2 || ly == ll3)) {
                printf("]");
            }
            if (space == 3 && (ly == lr1 || ly == lr2 || ly == lr3)) {
                printf("[");
            }

            // // Отрисовка мяча
            if (space == ballX && ly == ballY) {
                printf("#");
            }
            space -= 1;
        }
        printf("\n");
        ly -= 1;
    }
    int lx2 = 80;

    while (lx2 > 0) {  // Отрисовка нижний горизонтальной линии
        printf("-");
        lx2 -= 1;
    }
    printf("\n");
    printf("playerOneY = score | playerOneY = score\n");

    int switchPl = currentPlayer * 10;
    printf("\n\ncurrentPlayer %i\n", switchPl);
    // printf("playerOneY %i\n", playerOneY);
    // printf("playerTwoY %i\n", playerTwoY);
    // printf("displaySizeX %i\n", displaySizeX);
    // printf("displaySizeY %i\n", displaySizeY);
    // printf("ballDirectionX %i\n", ballDirectionX);
    // printf("ballDirectionY %i\n", ballDirectionY);
    // printf("ballX %i\n", ballX);
    // printf("ballY %i\n", ballY);
}
