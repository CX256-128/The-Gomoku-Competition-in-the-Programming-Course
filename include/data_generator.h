#pragma once
#include<iostream>
#include<fstream>
#include<string>
// There we define a function class to generate the data
// It use the "count.num" to store the total number of the .ai file in the folder
// And it will generate new file on that basis
// And this Generator is reusable, just triggering the function initiate() before
class Generator{
    public:
        void read_file_maximum();
        void write_new_file();
        void push_history(int row_index,int line_index);
        void initiate();
    private:
        //cache:
        int file_maximum;
        bool is_new;
        int history[676][2];//The first is the line index行->i   The second is the row index列->j
        int num;
};

void Generator::read_file_maximum(){
    std::ifstream ifso;
    ifso.open("count.num",std::ios::in);
    if(!ifso.is_open()){
        this->is_new=true;
        this->file_maximum=0;
        ifso.close();
        return ;
    }
    std::string read;
    ifso>>read;
    this->file_maximum=stoi(read);
    this->is_new=false;
    ifso.close();
}

void Generator::write_new_file(){
    std::string file_name = std::to_string(this->file_maximum) + ".ai";
    std::ofstream ofso;
    ofso.open(file_name,std::ios::out);
    ofso<<this->num<<std::endl;
    for(int i=0;i<this->num;i++){
        ofso<<this->history[i][0]<<" "<<this->history[i][1]<<std::endl;
    }
    ofso.close();
    ofso.open("count.num",std::ios::out);
    ofso<<this->file_maximum+1;
    ofso.close();
}
void Generator::push_history(int row_index,int line_index){
    this->history[this->num][0]=line_index;
    this->history[this->num][1]=row_index;
    this->num++;
}
void Generator::initiate(){
    this->num=0;
}