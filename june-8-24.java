class Solution {
    public int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int index=n-1;
        for(int i=0;i<arr2.length;i++){
            if(arr1[i]!=arr2[i]){
                index=i;
                break;
            }
        }
        
        return index;
    }
}