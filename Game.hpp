#include <cstdio>
#include <cstdlib>
#include <iostream>

class Game 
{
    public:

    Game(){
        initBoard();
        plays = 0;
        indexPlayer = 0;

        
    }
    ~Game(){
        printf("Game destroyed");
    }

    void printBoard(){
        for (int i = 0; i<9; i++) {
            printf("| %c |", board[i]);

            if((i + 1) % 3 == 0){
                printf("\n");
            }
        }
    }

    int start () {
        if(!init()) {return 1;}

        while (true) {
            unsigned int pos;

            printBoard();
            
            printf("Pos [0-9]: ");
            scanf("%i", &pos);

            turn(pos);
            std::cin.get();
            system("clear");

            
            if(won){
                printf(" player %i won \n", indexPlayer == 0 ? 1 : 0);
                break;
            }

            
            }
        return 0;
    }

    int turn(int pPos){

        if(indexPlayer == 2) indexPlayer = 0; 
        if (posEmpty(pPos)) {
            printf("%i is already full \n", pPos);
            std::cin.get();
            return 1;
        }

        board[pPos] = symbols[indexPlayer];
        plays++;
        won = score();
        indexPlayer++;
        return 0;
    }

    private:

    int plays;
    int indexPlayer;
    char board[9];
    char symbols[3] {'X', 'O', ' '};
    bool won;
    unsigned short int casesOfWin[8][3] = 
        {
            //horizontal
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            //vertical
            {0, 3 ,6},
            {1, 4, 7},
            {2, 5, 8},
            //diagonals
            {0, 4, 8}, 
            {2, 4, 6},
        };

    void initBoard() {
        for (int i = 0; i<9; i++) {
            board[i] = symbols[2];
        }
    }

    bool posEmpty(int index) {return board[index] != symbols[2];}

    bool score(){
        for(int i = 0; i < 8; i++){

            char &tempPos = board[casesOfWin[i][0]];
            int tempCount = 0;

            
            for(int j = 0; j < 3; j++){
                char &atualPos = board[casesOfWin[i][j]];

                if(tempPos == atualPos && tempPos != symbols[2]){
                    tempCount++;
                }
            }
            
            
            if(tempCount == 3){
                return true;
                break;
            }
        }
        return false;
    }

    bool init(){
        while (true) {
            char input;

            printf("Do u want play ? : [y/n]");
            scanf("%c", &input);
            std::cin.get();
            
            if(input != 'y' && input != 'n') {printf("please answear correctly %c \n", input); continue;}
            else if (input == 'n') { printf("bye \n"); return false; break;}

            break;
        }

        return true;
    }
};