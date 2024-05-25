/*

You have n stacks of books. Each stack of books has some nonzero height arr[i] equal to the number of books on that stack ( considering all the books are identical and each book has a height of 1 unit ). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books arr[i] <= k. Once such a sequence of stacks is chosen, You can collect any number of books from the chosen sequence of stacks.
What is the maximum number of books that you can collect this way?

Example 1

Input
8 1
3 2 2 3 1 1 1 3
Output
3
Explanation 
We can collect maximum books from consecutive stacks numbered 5, 6, and 7 having height less than equal to K.
Example 2

Input
8 2
3 2 2 3 1 1 1 3
Output
4
Explanation
We can collect maximum books from consecutive stacks numbered 2 and 3 having height less than equal to K.
Your Task:
You don't have to read input or print anything. Your task is to complete the function max_Books() which takes the integer arr, n, and k returns the maximum number of books you can collect.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 10^5
1 <= k <= 10^9
1 <= arr[i] <= 10^9





*/





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
