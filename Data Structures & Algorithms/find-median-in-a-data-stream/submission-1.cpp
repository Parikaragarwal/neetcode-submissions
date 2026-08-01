class MedianFinder {
public:
int els;
vector<int> median;
//Max Heap
priority_queue<int> left;
//Min Heap
priority_queue<int,vector<int>,greater<int>> right;

    MedianFinder() {
        els=0;
    }
    
    void addNum(int num) {
        els++;
        if(els<=2){
            median.push_back(num);
            if(els==2){
                sort(median.begin(),median.end());
            }
            return;
        }
        if(median.size()==1){
            if(num==median[0]){
                median.push_back(num);
                return;
            }else if(num<median[0]){
                left.push(num);
                median.push_back(left.top());
                left.pop();
                swap(median[0],median[1]);
            }else{
                right.push(num);
                median.push_back(right.top());
                right.pop();
            }
        }else{
            if(num<median[0]){
                left.push(num);
                right.push(median[1]);
                median.pop_back();
            }else if(num>median[1]){
                right.push(num);
                left.push(median[0]);
                median[0]=median[1];
                median.pop_back();
            }else{
                left.push(median[0]);
                right.push(median[1]);
                median={num};
            }
        }
    }
    
    double findMedian() {
        if(median.size()==1){
            return (double)median[0];
        }
        return (double)(median[0]+median[1])/2.0;
    }
};
