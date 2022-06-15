/*826. Most Profit Assigning Work
Medium

757

97

Add to List

Share
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.



Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
Example 2:

Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0*/


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        int mx=v[0].second;

        for(int i=1;i<n;i++){
            v[i].second=max(v[i].second,mx);
            mx=v[i].second;
        }

        sort(v.begin(),v.end());

        int res=0;
        int m=worker.size();
        for(int i=0;i<m;i++){
            if(v[0].first > worker[i]){
                continue;
            }

            int l=0,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(v[mid].first <= worker[i]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }

            res+=v[r].second;


        }


        return res;




    }
};
