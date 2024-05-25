





class Solution {
 public:
        long long max_Books(int arr[], int n, int k) {

        long long ans=0;
        long long temp=0;
            int cnt=0;


        for(int i=0;i<n;i++){


            if(arr[i]<=k){

              if(cnt==0)
                {//first stack
                    temp=arr[i];
                    cnt++;
                }
                else{//consecutive 
                    temp+=arr[i];
                    cnt++;
                }
            }
                else {//if not consecutive
                    ans=max(ans, temp);
                       cnt=0;
                    temp=0;
                }
           }


         ans=max(ans, temp);
        return ans;

    }
};
