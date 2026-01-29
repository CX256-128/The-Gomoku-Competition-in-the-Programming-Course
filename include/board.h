#pragma once
#include<iostream>
#include"function.h"
// There we define struct Board
// Board has a int[][] to store the chess game
// And it's integrated with a function display() to display board directly
// Reference:
//      In function Board::display()
//          We use the trans() and dis_trans() in the "function.h"
struct Board{
    int table[26][26]={ };
    /*
    0->没有落子
    1->player1落子
    2->player2落子
    */
    //ASCII码
    void display();
    void initiate();
    Board(){ this->initiate(); }
};
void Board::display(){
    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            if(i==0||i==27){
                if(j==0||j==27){
                    std::cout<<"   ";
                }
                else{
                    std::cout<<(char)((int)('a')+j-1)<<" ";
                }
            }
            else if(j==0||j==27){
                std::cout<<dis_trans(i)<<" ";
            }
            else{
                std::cout<<trans(this->table[i-1][j-1])<<" ";
            }
        }
        std::cout<<std::endl;
    }
}
void Board::initiate(){
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            this->table[i][j]=0;
        }
    }
}