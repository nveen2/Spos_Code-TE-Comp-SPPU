#include<bits/stdc++.h>
using namespace std;
int main()
{
    int at[]={0,1,2,4};
    int bt[]={5,3,4,10};
    int qt;cin>>qt;
    queue<int>q;
    int time=0;
    set<int>st;
    bool case1=false;
    cout<<"p  at  ct"<<endl;
    while(1)
    {
        bool done=false;
        for(int i=0;i<4;i++)
        {
            if(bt[i]!=0){done=true;break;}
        }
        if(!done)break;

        bool f=false;
        for(int i=0;i<4;i++)
        {
            f=false;
            if(time>=at[i])
              {
                if(st.find(i)==st.end())
                {
                    f=true;
                    st.insert(i);
                    q.push(i);
                }
              } 
        }
        if(st.size()==0){time++;continue;}

        if(case1==true) {q.push(q.front());
            q.pop();}
        
        case1=false;
        if(bt[q.front()]-qt<=0)
        {
            cout<<q.front()+1<<"  "<<time<<"  "<<time+bt[q.front()]<<endl;
            time+=bt[q.front()];bt[q.front()]=0;
            q.pop();
        }
        else
        {
            case1=true;
            cout<<q.front()+1<<"  "<<time<<"  "<<time+qt<<endl;
            bt[q.front()]=bt[q.front()]-qt;
            time+=qt;
        }

    }
}   