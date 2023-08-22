// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    vector<int> vec;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(vec.empty()){
            vec.push_back(num);
        }else{
            vec.insert(lower_bound(vec.begin(), vec.end(), num), num);
        }
    }
    
    double findMedian() {
        int n = vec.size();
        if(n&1) return vec[n>>1];
        return (vec[(n>>1)-1]+vec[n>>1])/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */