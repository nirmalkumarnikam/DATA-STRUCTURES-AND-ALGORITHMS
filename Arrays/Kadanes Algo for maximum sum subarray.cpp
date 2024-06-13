class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //......kadanes algorithm.........

        // Algo:
        //     1)intially sum =0;
        //                MAXI = -2;
        //     2)iterate over array{
        //            sum = sum + arr[i];
        //            maxi update = max(maxi, sum);
        //            if(sum<0){
        //                sum = 0;
        //            }
        //         }
        //     return maxi;



//         int sum=0;
//         int maxi=nums[0];
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             sum=sum+nums[i];
            
//             maxi=max(maxi,sum);
            
//             if(sum<0)
//                 sum=0;
            
//         }
//         return maxi;



        
        
        //.........ncube complex.............
        
        // int maxi =nums[0];
        // int sum=0;
        
        // for (int i=0; i<nums.size(); i++)
        // {
        //     for(int j=i; j<nums.size(); j++)
        //     {
        //         sum=0;
        //      for(int k=i; k<=j ; k++)
        //         {
        //             sum=sum + nums[k];
                    
        //         }
        //         maxi=max(maxi, sum);
        //     }    
        // }
        
        // return maxi;






    //..............nsquare Complex......................

        int maxi =nums[0];
        int sum=0;
        
        for (int i=0; i<nums.size(); i++)
        {
            sum=0;
            for(int j=i; j<nums.size(); j++)
            {
             
                    sum=sum + nums[j];
                
                maxi=max(maxi, sum);
            }    
        }
        
        return maxi;    
    }
};