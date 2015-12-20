class Stack {
private:
	vector<int> myStack;
public:
	// Push element x onto stack.
	void push(int x) {
		myStack.push_back(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		myStack.pop_back();
	}

	// Get the top element.
	int top() {
		return myStack.back();
	}

	// Return whether the stack is empty.
	bool empty() {
		return myStack.size()==0;
	}
};