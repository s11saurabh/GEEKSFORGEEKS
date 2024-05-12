//Minimum steps to destination

//Given an infinite number line. You start at 0 and can go either to the left or to the right. The condition is that in the ith move,
// you must take i steps. Given a destination d, find the minimum number of steps required to reach that destination.

//Constraints: 1 ≤ d ≤ 10000

class Solution {
  public:
    int minSteps(int d) {
  int sum=0,steps=0,i=0;
        while(sum<d){
            sum+=steps;
            steps++;
        }
        while((sum-d)%2==1){
            sum+=steps;
            steps++;
        }
       
        
      return steps-1;
    }
}