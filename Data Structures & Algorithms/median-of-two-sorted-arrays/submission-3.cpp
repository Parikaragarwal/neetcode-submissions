class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    double median(vector<int> &arr){
        int n = arr.size();
        int mid= n/2;
        if(n%2==0){
            return (double)(arr[mid]+arr[mid-1])/2.0;
        }else{
            return (double)arr[mid];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2= nums2.size();

        vector<int> &a = n1<n2?nums1:nums2;
        vector<int> &b = n1<n2?nums2:nums1;

        if(n1==0 || n2==0){
            return median(b);
        }

        int k=(n1+n2-1)/2;
        int start=0;
        int end = min(a.size(),k);

        while(start<end){
            int mid=start+(end-start)/2;
            int mid1=mid;
            int mid2=k-mid;
            int l1=mid1>0?a[mid1-1]:INT_MIN;
            int l2=mid2>0?b[mid2-1]:INT_MIN;
            int r1=mid1<a.size()?a[mid1]:INT_MAX;
            int r2=mid2<b.size()?b[mid2]:INT_MAX;

            if(l1>r2){
                end=mid;
            }else{
                start=mid+1;
            }
        }

        int el1=a[start-1];
        int el2=b[k-start+1];

        if((n1+n2)%2==0){
            return (double)(el1+el2)/2.0;
        }else{
            return (double)(min(el1,el2));
        }     

    }
};
