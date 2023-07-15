// Question 1
// Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays
// 1.Ans
void Intersection(vector <int> arr1,vector <int> arr2,vector <int> arr3){
int i=0,j=0,k=0;
  while(i<arr1.size() && j<arr2.size() && k<arr3.size()){
    if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
      cout<<arr[i]<<" ";
      i++; j++; k++;
    }
    else if(arr1[i]<arr2[j]){
      i++;
    }else if(arr[j]<arr[k]){
      j++;
    }else{
      k++;
    }
  }
}

// 2.Ans

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end());
        vector<int> dist_num1,dist_num2;
        for(int num:set1){
            if(set2.count(num)==0){
                dist_num1.push_back(num);
            }
        }
        for(int num:set2){
            if(set1.count(num)==0){
                dist_num2.push_back(num);
            }
        }
        return {dist_num1,dist_num2};


    }
};

// 3.Ans

  vector<vector<int>> transpose(vector<vector<int>> A) {
        int M = A.size(), N = A[0].size();
        vector<vector<int>> B(N, vector<int>(M, 0));
        for (int j = 0; j < N; j++)
            for (int i = 0; i < M; i++)
                B[j][i] = A[i][j];
        return B;
    }

// 4.Ans


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxsum = 0;
        for(int i = 0 ; i<nums.size(); i= i +2){
            maxsum = maxsum+nums[i];
        }
        return maxsum;
    }
};

// 5.Ans

class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        int row=0;
       
        while(n-i>=0){
           
            row++;
            n=n-i;
            i++;

        }
    return row; 
    }
};

// 6.Ans
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back((nums[i]*nums[i]));
        }
        sort(arr.begin(),arr.end());
    return arr;
   
    }
    
};

// 7.Ans

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_row = m;
        int min_col = n;
        for (int i=0; i<ops.size(); i++){
            if (ops[i][0]<min_row) min_row=ops[i][0];
            if (ops[i][1]<min_col) min_col=ops[i][1];
        }        
        return min_row*min_col;
        
    }
};

// 8.Ans

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};

