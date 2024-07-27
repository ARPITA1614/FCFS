#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Write C++ code here
    int n ;
    cout << "Enter no. of programs= "<<endl;
    cin>>n;
    int at[n], bt[n],ct[n],tat[n],wt[n];
    cout << "Enter arrival time and burst time= "<<endl;
    for (int i = 0; i < n; ++i) {
            cin >> at[i] >> bt[i];
    }
    int currt=0;
    for (int i = 0; i < n; ++i) {
        if(at[i]>currt){
            currt=at[i];
        }
        ct[i]=currt+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        currt=ct[i];
    }
    int l=sizeof(at) / sizeof(at[0]);
    sort(at, at + l);
    int minat=*min_element(at, at + l);
    if(minat !=0){
        cout<<"From 0 to "<<minat<<" processor will be at ideal state"<<endl;
    }
    cout<<endl;
    cout<<"PROCESS\t ARRIVAL\tBURST\tCOMPLETION\tTURNAROUNDTIME\tWAITINGTIME "<<endl;
    float total_tat=0,total_wt=0;
    for(int i=0; i<n;++i){
        cout<<"P"<<i<<" \t\t "<<at[i]<<" \t\t "<<bt[i]<<" \t\t "<<ct[i]<<" \t\t "<<tat[i]<<" \t\t "<<wt[i]<<endl;
    total_tat+=tat[i];
    total_wt+=wt[i];
    }
    cout<<"\nAverage turnaroundtime = "<<total_tat<<endl;
    cout<<"Average waittime = "<<total_wt<<endl;
    return 0;
}