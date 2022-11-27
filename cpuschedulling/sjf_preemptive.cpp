#include<bits/stdc++.h>
using namespace std;
int main()
{
    int at[]={0,1,2,4};
    int bt[]={5,3,4,10};
    vector<int>available;
    int time=0;
    cout<<"p  at  ct"<<endl;
    while(1)
    {
      bool done=false;
      for(int i=0;i<4;i++)
      {
        if(bt[i]!=0){done=true;break;}
      }
      if(!done)break;

      available.clear();
      for(int i=0;i<4;i++)
      {
        if(time>=at[i]&&bt[i]!=0)
        available.push_back(i);
      }
      if(available.size()==0){time++;continue;}
      int optimalind,optimal=INT_MAX;
      for(int i=0;i<available.size();i++)
      {
        if(bt[available[i]]<optimal)
        {
            optimal=bt[available[i]];
            optimalind=available[i];
        }
      }
      bt[optimalind]--;
      cout<<optimalind+1<<"  "<<time<<"  "<<time+1<<endl;
      time++;
    }

}   