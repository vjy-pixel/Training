#include<iostream>
#include<ctime>
using namespace std;

int main(){
    clock_t start = clock();
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        long c,n;
        cin >> c >> n;
        
        double least,temp;
        
        temp = c-(c%n);
        
        least = temp/n;
        //cout << "least:" << least << endl;
        int flag=0;
        double sum=0;
        
        while(least>0){
            
            temp = n+least-1;
            sum = (temp/2)*(temp+1);
            double temp2 = (least-1)*(least/2);
            
            sum = sum - temp2 ;
       
            if(sum<=c){
                flag=1;
                cout << (c-sum) << endl;
                break; 
            }
            least--;
        }
        
        if(flag==0)
            cout << c << endl;
    }
    start = clock() - start;
    cout << "time:" << (float)start<< endl;
}