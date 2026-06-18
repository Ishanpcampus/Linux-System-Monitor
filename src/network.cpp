#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<unistd.h>
using namespace std;

int main(){

    ifstream dev("/proc/net/dev");
    if(!dev.is_open()){
        cout<<"failed to load the file.";
        return 1;
    }

    string line;
    long long rx,tx;
    long long skip;
    while(getline(dev,line)){
        
        if(line.find("wlan0") != string::npos ) {
            size_t pos = line.find(':');
            istringstream ss(line.substr(pos+1));
            ss >> rx;
            int i=7;
            while(i>0){
                ss >> skip;
                i--;
            }
            ss >> tx;
            break;
        }
         
    }
    sleep(1);
    long long rx2, tx2;
    dev.seekg(0);
    while(getline(dev,line)){
        
        if(line.find("wlan0") != string::npos ) {
            size_t pos = line.find(':');
            istringstream ss2(line.substr(pos+1));
            ss2 >> rx2;
            int i=7;
            while(i>0){
                ss2 >> skip;
                i--;
            }
            ss2 >> tx2;
            break;
        }
         
    }
    
    cout<<"Download: " << ( rx2-rx )/ 1024 <<"KB/s\n";
    cout<<"Upload: " << ( tx2-tx )/ 1024 <<"KB/s\n";


    return 0;
}