// This is a C++ style Header File
#pragma once
#include"data_generator.h"
#include"board.h"
#include"function.h"
// This is the Header file we define multiple kinds of the running mode
// We first define the to_generate_data_Game first benefiting in data generating
// And we're planned to write down other kinds,such as AI_vs_you_Game and AI_traning_Game
struct Player
{
    int player_type;
    //要么是1，要么是2   
    /* data */
    void set_player_type(int i){
        player_type = i % 2;
    }
};
class to_generate_data_Game{
    public:
        bool is_to_store = false;
        Generator generator; 
        Player player1,player2;
        void initiate();
        void player_input(int i);
        void set_board(int row_index, int line_index,int i);
        bool get_board(int row_index,int line_index,int i);
        void displayer();
    private:
        Board board;
};

class basic_game{
    public:
        Player player1,player2;
        void initiate();
        void player_input(int i);
        void set_board(int row_index, int line_index,int i);
        bool get_board(int row_index,int line_index,int i);
        void displayer();
        int check_winner();
        Board board;
}
inline void to_generate_data_Game::initiate(){
    this->board.initiate();
    this->player1.set_player_type(1);
    this->player2.set_player_type(2);
    this->generator.initiate();
    if(this->is_to_store){
        this->generator.read_file_maximum();
    }
}
inline void basic_game::initiate(){
    this->board.initiate();
    this->player1.set_player_type(1);
    this->player2.set_player_type(2);
}
inline void to_generate_data_Game::player_input(int i){
    redo:
    std::cout<<"now it's player"<<i<<"'s turn (whose chess mark is "<<trans(i)<<std::endl;
    std::cout<<"input_example: (a , 01) we input as a01"<<std::endl;
    std::cout<<"input (row_index , line_index) >"<<std::endl;
    char input[3]= { };
    std::cin>>input[0]>>input[1]>>input[2];
    if(!((int)input[0] >= (int)'a' && (int)input[0] <= (int)'z' && (int)input[1] >= (int)'0' && (int)input[1] <= (int)'9' && (int)input[2] >= (int)'0' && (int)input[2] <= (int)'9')){
        goto redo;
    }
    std::string in = "";
    in+= input[1];
    in+= input[2];
    int line_index = stoi(in);
    if(line_index == 0){
        throw interupt::UserQuitException();
    }
    line_index = line_index % 26;
    line_index = line_index - 1;
    int row_index = (int)(input[0])-(int)('a');
    if(this->get_board(row_index,line_index,i)){
        this->set_board(row_index,line_index,i);
        std::cout<<"fine,input any key to continue:";
        system("pause");
    }
    else{
        std::cout<<"you can't place it here"<<std::endl;
        goto redo;
    }
}
inline void basic_game::player_input(int i){
    redo:
    std::cout<<"now it's player"<<i<<"'s turn (whose chess mark is "<<trans(i)<<std::endl;
    std::cout<<"input_example: (a , 01) we input as a01"<<std::endl;
    std::cout<<"input (row_index , line_index) >"<<std::endl;
    char input[3]= { };
    std::cin>>input[0]>>input[1]>>input[2];
    if(!((int)input[0] >= (int)'a' && (int)input[0] <= (int)'z' && (int)input[1] >= (int)'0' && (int)input[1] <= (int)'9' && (int)input[2] >= (int)'0' && (int)input[2] <= (int)'9')){
        goto redo;
    }
    std::string in = "";
    in+= input[1];
    in+= input[2];
    int line_index = stoi(in);
    if(line_index == 0){
        throw interupt::UserQuitException();
    }
    line_index = line_index % 26;
    line_index = line_index - 1;
    int row_index = (int)(input[0])-(int)('a');
    if(this->get_board(row_index,line_index,i)){
        this->set_board(row_index,line_index,i);
        std::cout<<"fine,input any key to continue:";
        system("pause");
    }
    else{
        std::cout<<"you can't place it here"<<std::endl;
        goto redo;
    }
}
inline void to_generate_data_Game::set_board(int row_index,int line_index,int i){
    this->board.table[line_index][row_index] = i;
    if(this->is_to_store)
        this->generator.push_history(row_index,line_index);
}
inline void basic_game::set_board(int row_index,int line_index,int i){
    this->board.table[line_index][row_index] = i;
}
inline bool to_generate_data_Game::get_board(int row_index,int line_index,int i){
    switch (this->board.table[line_index][row_index])
    {
    case 0:
        /* code */
        return true;
        break;
    default:
        return false;
        break;
    }
}
inline bool basic_game::get_board(int row_index,int line_index,int i){
    switch (this->board.table[line_index][row_index])
    {
    case 0:
        /* code */
        return true;
        break;
    default:
        return false;
        break;
    }
}
inline void to_generate_data_Game::displayer(){
    this->board.display();
}
inline void basic_game::displayer(){
    this->board.display();
}
inline int basic_game::check_winner(){
    // Check rows, columns, and diagonals for a winning condition
    // Return 0 if no winner, 1 if player 1 wins, 2 if player 2 wins
    // 1/2 is player mark in the board data int board[][]
    const int BOARD_SIZE = 26;
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            int current = this->board.table[i][j];
            if(current == 0){
                continue;
            }
            // horizontal
            if(j + 4 < BOARD_SIZE){
                bool ok = true;
                for(int k = 1; k < 5; k++){
                    if(this->board.table[i][j + k] != current){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    return current;
                }
            }
            // vertical
            if(i + 4 < BOARD_SIZE){
                bool ok = true;
                for(int k = 1; k < 5; k++){
                    if(this->board.table[i + k][j] != current){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    return current;
                }
            }
            // diagonal down-right
            if(i + 4 < BOARD_SIZE && j + 4 < BOARD_SIZE){
                bool ok = true;
                for(int k = 1; k < 5; k++){
                    if(this->board.table[i + k][j + k] != current){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    return current;
                }
            }
            // diagonal up-right
            if(i - 4 >= 0 && j + 4 < BOARD_SIZE){
                bool ok = true;
                for(int k = 1; k < 5; k++){
                    if(this->board.table[i - k][j + k] != current){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    return current;
                }
            }
        }
    }
    return 0;
}
