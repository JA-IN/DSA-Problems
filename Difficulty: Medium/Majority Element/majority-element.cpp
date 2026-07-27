class Solution {
	public:
	int majorityElement(vector<int>& arr) {
		// code here
		int count = 0 ;
		int element = arr[0] ;
		
		for (int i = 0 ; i<arr.size() ; i++) {
			if (count == 0) {
				element = arr[i];
				count++;
			}
			else if (arr[i] == element) {
				count++;
			}
			else {
				count--;
			}
		}
		
		count = 0 ;
		for (int i = 0 ; i<arr.size() ; i++) {
			if (arr[i] == element) {
				count++;
			}
		}
		int n = arr.size()/2;
		
		if (count > n)
			return element;
		
		return -1;
	}
};
