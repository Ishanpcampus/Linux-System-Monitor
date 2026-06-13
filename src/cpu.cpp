#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<unistd.h>
#include<iomanip>
using namespace std;



int main(){

    ifstream stat("/proc/stat");
    if(!stat.is_open()){
        cout<<"Failed to check cpu status  as we couldn't open /proc/stat";
        return 1;
    }

    string line;
    getline(stat,line);
    stringstream ss(line);
    string cpulabel;
    ss >> cpulabel;

    long long user1 , nice1 ,  system1 , idle1;
    ss >> user1 >> nice1 >> system1 >> idle1 ;

    long total1=user1+nice1+system1+idle1;

    sleep(1);

    stat.seekg(0);
    getline(stat,line);
    stringstream ss2(line);
    ss2 >> cpulabel;

    long long user2 , nice2 ,  system2 , idle2;
    ss2 >> user2 >> nice2 >> system2 >> idle2 ;

    long total2=user2+nice2+system2+idle2;
    
    double cpu_per = 100.0 * (1.0 - (double)(idle2-idle1) / (double)(total2-total1) );
 cout<< fixed << setprecision(2) <<"CPU usuage:"<< cpu_per <<"%";
return 0;
}
