#include <functional> // for greater<T>
#include <queue>
#include <vector>

using std::greater; // in functional header
using std::priority_queue;
using std::vector;
class KthLargest {
  public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int ksize;
    KthLargest(int k, vector<int>& nums) {
        ksize = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if ((int) pq.size() > ksize)
                pq.pop();
        }
    }

    int add(int val) {

        pq.push(val);
        if ((int) pq.size() > ksize)
            pq.pop();

        return pq.top();
    }
};
