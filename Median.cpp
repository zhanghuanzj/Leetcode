#include <iostream>
#include <queue>
#include <functional>
using namespace std;
//priority_queue 默认为大顶堆
class MedianFinder {
public:
  priority_queue<int> upperHeap;                              //大顶堆（存小元素）
  priority_queue<int,vector<int>,greater<int>> lowerHeap;     //小顶堆（存大元素）
  // Adds a number into the data structure.
  void addNum(int num) {
    if (lowerHeap.empty()||lowerHeap.top()<num)
    {
      lowerHeap.push(num);
    }
    else
    {
      upperHeap.push(num);
    }

    //两者偏移量大于1，进行调整
    if (lowerHeap.size()>upperHeap.size()+1)
    {
      upperHeap.push(lowerHeap.top());
      lowerHeap.pop();
    }
    else if(upperHeap.size()>lowerHeap.size()+1)
    {
      lowerHeap.push(upperHeap.top());
      upperHeap.pop();
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    if (lowerHeap.size()==upperHeap.size())
    {
      return (lowerHeap.top()+upperHeap.top())/2.0;
    }
    else
    {
      return lowerHeap.size()>upperHeap.size()?lowerHeap.top():upperHeap.top();
    }
  }
};
int main()
{
  MedianFinder medianFinder;
  while (true)
  {
    int i;
    cin>>i;
    medianFinder.addNum(i);
    cout<<medianFinder.findMedian()<<endl;
  }

}