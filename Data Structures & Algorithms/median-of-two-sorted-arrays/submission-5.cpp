class Solution {
public:
    double median(vector<int> &arr){
        int n = arr.size();
        int mid = n / 2;
        if(n % 2 == 0){
            return (double)(arr[mid] + arr[mid - 1]) / 2.0;
        } else {
            return (double)arr[mid];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> &a = n1 < n2 ? nums1 : nums2;
        vector<int> &b = n1 < n2 ? nums2 : nums1;

        if(n1 == 0 || n2 == 0){
            return median(b);
        }

        int n = n1 + n2;
        // Your exact logic: discard exactly the elements strictly before the median(s)
        int k = (n - 1) / 2;
        
        int start = 0;
        int end = min((int)a.size(), k);

        while(start <= end){
            int mid = start + (end - start) / 2;
            int mid1 = mid;
            int mid2 = k - mid;

            int l1 = mid1 > 0 ? a[mid1 - 1] : INT_MIN;
            int r2 = mid2 < b.size() ? b[mid2] : INT_MAX;

            if(l1 > r2){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        // start - 1 is the exact number of elements we discard from array 'a'
        int mid1 = start - 1;
        int mid2 = k - mid1;

        // The discarded elements are behind us. 
        // The median elements are strictly in the remaining pools.
        int r1 = mid1 < a.size() ? a[mid1] : INT_MAX;
        int r2 = mid2 < b.size() ? b[mid2] : INT_MAX;

        if(n % 2 != 0){
            // Odd total: The median is just the very first element of the remaining pile
            return (double)min(r1, r2);
        } else {
            // Even total: We need the FIRST and SECOND elements of the remaining pile.
            // As you realized, they could both be in 'a', both in 'b', or one in each.
            int first_remaining, second_remaining;
            
            if (r1 < r2) {
                first_remaining = r1;
                // If we take r1, the next candidate from 'a' is a[mid1 + 1]
                int r1_next = (mid1 + 1 < a.size()) ? a[mid1 + 1] : INT_MAX;
                second_remaining = min(r1_next, r2);
            } else {
                first_remaining = r2;
                // If we take r2, the next candidate from 'b' is b[mid2 + 1]
                int r2_next = (mid2 + 1 < b.size()) ? b[mid2 + 1] : INT_MAX;
                second_remaining = min(r1, r2_next);
            }
            
            return (first_remaining + second_remaining) / 2.0;
        }     
    }
};