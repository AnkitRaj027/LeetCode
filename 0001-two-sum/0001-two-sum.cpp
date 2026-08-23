class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force
        // int n=nums.size();
        // vector<int> v;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int sum=nums[i]+nums[j];
        //         if(sum==target){
        //             v.push_back(i);
        //             v.push_back(j);
        //         }
        //     }
        // }
        // return v;
    // }

    //Better
        unordered_map<int,int>mpp;
        int n=nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            int a=nums[i];
            int b=target-a;
            if(mpp.find(b)!=mpp.end()){
                v.push_back(i);
                v.push_back(mpp[b]);
            }
            mpp[a]=i;
        }
        return v;
    }

    


};