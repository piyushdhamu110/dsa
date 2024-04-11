#include<bits/stdc++.h>
using namespace std;

int mindis(int dis[], bool incl[])
{
    int min_index=0,min_dis=INT_MAX;

    for(int i=0;i<9;i++)
    {
        if(incl[i]==false && dis[i]<min_dis){
            min_dis=dis[i];
            min_index=i;
        }
    }
    return min_index;
}

void djikstra(int graph[9][9])
{
    int dis[9]={INT_MAX};
    dis[0]=0;

    bool incl[9]={false};


}
int main()
{
    int graph[9][9]= {  { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
}