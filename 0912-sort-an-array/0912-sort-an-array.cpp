class Solution {
public:
      void  merge(vector<int>&v,   vector<int>&temp, int start,int mid,int end){
        int i = start, j = mid+1, k= start;
        while(i <= mid && j<= end){
            if(v[i] <= v[j]) temp[k++] = v[i++];
            else
                temp[k++] = v[j++];// 
        }
        while(i <= mid) temp[k++] = v[i++];
        while(j <= end) temp[k++] = v[j++];
        while( start <= end){
            v[start] = temp[start];
            start++;
        }
      }
    void  mergeSort(vector<int>&v,   vector<int>&temp, int start, int end){
        if(start >= end){
            return;
        }
        int mid =(start + end) >>1;// it means  divde by  two  hogya hai
        mergeSort(v,temp, start, mid);
        mergeSort(v,temp, mid+1, end);
        merge(v,temp, start, mid , end);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int>temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size()-1);
        return nums;
    }
};