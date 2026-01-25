#include<iostream>
#include<fstream>
using namespace std;
bool is_bchar(char data){
    if(((int)data >= 'A' && (int)data <= 'Z'))
        return true;
    else
        return false;
}
bool is_lchar(char data){
    if(((int)data >= 'a' && (int)data <= 'z'))
        return true;
    else
        return false;
}
bool is_number(char data){
    if((int)data >= (int)'0' && (int)data <='9')
        return true;
    else 
        return false;
}
int processed_data[676][2]={ };
int num=0;
void initialize(){
    for(int i=0;i<676;i++){
        for(int j=0;j<2;j++){
            processed_data[i][j]=-1;
        }
    }
    num = 0;
}
void process(string raw_data){//其中processed_data是二维数组
    for(int i=0;i<raw_data.length();i++){
        if(is_lchar((char)(raw_data[i]))){
            processed_data[num][0] = (int)((char)(raw_data[i])) - (int)'a';
        }else if(is_bchar((char)(raw_data[i]))){
            processed_data[num][0] = (int)((char)(raw_data[i])) - (int)'A';
        }else if(is_number((char)(raw_data[i]))){
            if(is_number((char)(raw_data[i+1]))){
                string snum = string(1,raw_data[i]) + string(1,raw_data[i+1]);
                processed_data[num][1] = stoi(snum);
                num++;
                i++;
            }
            else{
                string snum = string(1,raw_data[i]);
                processed_data[num][1] = stoi(snum);
                num++;
            }
        }
    }
}
void write(int i){
    string filename = to_string(i) + ".ai";
    ofstream ofs;
    ofs.open(filename,ios::out);
    ofs<<num<<endl;
    for(int i=0;i<num;i++){
        ofs<<processed_data[i][0]<<" "<<processed_data[i][1]<<endl;
    }
    ofs.close();
}
int main(){
    int count = 0;
    for(int i=1;;i++){
        int j=0;
        ifstream ifs;
        string name = to_string(i) + ".txt";
        ifs.open(name,ios::in);
        if(!ifs.is_open())
            return 0;
        string data;
        for(;getline(ifs,data);j++){
            initialize();
            process(data);
            write(count+j);
        }
        count +=j;
        ifs.close();
    }
}