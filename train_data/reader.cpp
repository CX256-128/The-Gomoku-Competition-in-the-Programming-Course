#include<iostream>
#include<fstream>
using namespace std;
int cxdata[676][2] = { };
int num = 0;
char table[26][26] = { };
void cxread(ifstream& cxifs){
    cxifs>>num;
    for(int i=0;i<num;i++){
        cxifs>>cxdata[i][0]>>cxdata[i][1];
    }
}
string dis_trans(int in){
    if(in<10)
        return "0"+to_string(in);
    else
        return to_string(in);
}
char trans(int input){
    switch (input)
    {
    case 0:
        /* code */
        return '.';
    case 1:
        return 'o';
    case 2:
        return 'x';
    default:
        return ' ';
    }
}
char transf(int i){
    switch (i)
    {
    case 0:
        /* code */
        return 'o';
    case 1:
        return 'x';
    default:
        return '.';
    }
}
void fill(int step){
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            table[i][j] = '.';
        }
    }
    for(int i=0;i<step;i++){
        table[cxdata[i][1]][cxdata[i][0]] = transf(i%2);
    }
}
void show(int step){
    //step starts from 0 to _num-1
    
    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            if(i==0||i==27){
                if(j==0||j==27){
                    cout<<"   ";
                }
                else{
                    cout<<(char)((int)('a')+j-1)<<" ";
                }
            }
            else if(j==0||j==27){
                cout<<dis_trans(i)<<" ";
            }
            else{
                cout<<table[i-1][j-1]<<" ";
            }
        }
        cout<<endl;
    }

}
int main(){
    start:
    cout<<"Reader v:1.0"<<endl;
    redo:
    cout<<"input file you want to open >";
    string filename;
    cin>>filename;
    ifstream cxifs;
    cxifs.open(filename,ios::in);
    if(!cxifs.is_open()){
        cout<<"Can't open this file:"<<filename<<endl;
        cout<<"We need redo it,input any key to continue"<<endl;
        char a = getchar();
        system("cls");
        goto redo;
    }
    cxread(cxifs);
    cxifs.close();
    for(int i=0;i<num;i++){
        fill(i);
        show(i);
        cout<<"input any key to continue"<<endl;
        system("pause");
        system("cls");
    }
    redo1:
    cout<<"This is the end,do you want to open another file?(y/n)"<<endl;
    char k;
    cin>>k;
    if(k =='y'){
        system("cls");
        goto start;
    }
    else if(k=='n'){
        return 0;
    }
    else{
        cout<<"input a wrong option,please redo it"<<endl;
        goto redo1;
    }
}