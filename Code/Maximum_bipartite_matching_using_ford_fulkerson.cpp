#include<bits/stdc++.h>
using namespace std;

#define applicants 6
#define jobs 6

/*
A DFS based recursive function that returns true if a matching
for vertex u is possible
*/

bool bpm(bool bpGraph[applicants][jobs],int u,bool seen[],int matchR[]){
    //Try every job one by one
    for(int v = 0;v < jobs;v++)
    {
        //if applicant u is interested in job v and v is not visited
        if(bpGraph[u][v] && !seen[v])
        {
            //Mark v as visited
            seen[v] = true;
            /*
            if job 'v' is not assigned to an applicant or previously assigned
            applicnt for job v(which is matchR[v]) has an alternate job available.
            Since v is marked as visited in the above line, matchR[v] in the
            following recursice call will not get job 'v' again
            */
           if(matchR[v] < 0 || bpm(bpGraph,matchR[v],seen,matchR))
           {
               matchR[v] = u;
               return true;
           }
        }
    }
    return false;
}

int maxBPM(bool bpGraph[applicants][jobs])
{
    /*
    An array to keep track of the applicants assigned to jobs.
    The value of matchR[i] is the applicant number assigned to job i,
    the value -1 indicates nobody is assigned.
    */
   int matchR[jobs];

   memset(matchR,-1,sizeof(matchR));

   //count of jobs assigned to applicants
   int result = 0;
   for(int u = 0;u < applicants;u++)
   {
       //Mark all jobs as not seen for next applicant.
       bool seen[jobs];
       memset(seen,0,sizeof(seen));

       //Find if the applicant 'u' can get a job
       if(bpm(bpGraph,u,seen,matchR))
            result++;
   }
   return result;
}


int main()
{
    bool bpGraph[applicants][jobs] = {{0,1,1,0,0,0},
                                      {1,0,0,1,0,0},
                                      {0,0,1,0,0,0},
                                      {0,0,1,1,0,0},
                                      {0,0,0,0,0,0},
                                      {0,0,0,0,0,1}};
    cout << "Maximum number of applicants that can get job is " << maxBPM(bpGraph);
    return 0;
}