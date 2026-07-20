class Solution {
	public:
	double medianOf2(vector<int>& a, vector<int>& b) {
		// Your code goes here
		int n1 = a.size(), n2 = b.size();
		int left = 0, right = n1;
		double ans ;
		while (left <= right) {
			int partitionA = left + (right - left)/2;
			
			int left_partition = (n1 + n2 + 1)/2;
			
			int partitionB = left_partition - partitionA;
			
			int AL = (partitionA == 0)?INT_MIN:a[partitionA - 1];
			int AR = (partitionA == n1)?INT_MAX:a[partitionA];
			
			int BL = (partitionB == 0)?INT_MIN:b[partitionB - 1];
			int BR = (partitionB == n2)?INT_MAX:b[partitionB];
			
			if (AL <= BR && BL <= AR) {
				int check = (n1 + n2)%2;
				if (check == 0) {
					ans = (max(AL, BL) + min(AR, BR))/2.0;
					break;
				}
				else {
					ans = max(AL, BL);
					break;
				}
			}
			else if (AL > BR) {
				right = partitionA - 1;
			}
			else {
				left = partitionA + 1;
			}
		}
		return ans;
		
	}
};
