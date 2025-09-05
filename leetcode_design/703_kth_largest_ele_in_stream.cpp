#include<queue>
#include<vector>
#include <functional> // for greater<T>

using std::vector;
using std::priority_queue;
using std::greater; //in functional header
class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int ksize; 
    KthLargest(int k, vector<int>& nums) {
        ksize = k;
        for (int i = 0 ; i < nums.size() ;i++){
            pq.push(nums[i]);
            if ((int)pq.size() > ksize) pq.pop();
        }
    }   
    
    int add(int val) {

        pq.push(val);
        if ((int)pq.size() >ksize)  pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */