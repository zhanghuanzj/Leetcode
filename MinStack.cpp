class MinStack {
private:
	vector<int> minStack;
	vector<int> minIndex;
public:
	void push(int x) {
		minStack.push_back(x);
		if (minStack.size()==1)
		{
			minIndex.push_back(0);
		}
		else if(x<minStack[minIndex.back()])
		{
			minIndex.push_back(minStack.size()-1);
		}
		else
		{
			minIndex.push_back(minIndex.back());
		}
	}

	void pop() {
		minStack.pop_back();
		minIndex.pop_back();
	}

	int top() {
		return minStack.back();
	}

	int getMin() {
		return minStack[minIndex.back()];
	}
};