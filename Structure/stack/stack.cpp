/*************************************************************************
    > File Name: stack.cpp
# Author: Wvfp
# mail: 3512241696@qq.com
    > Created Time: 2024年07月20日 星期六 20时37分43秒
 ************************************************************************/
#include <cassert>
#include <iostream>

class Stack{
public:
	Stack():top(0){
		arr = new int[10];
	}
	bool empty(){
	if(top==0)
		return true;
	else
		return false;
	}
	void push(const int& x){
		if(top<11){
		top ++;
		arr[top-1]=x;
		}
		return;
	}
	int pop(){
		assert(!empty());
		top --;
		return arr[top];

	}
	~Stack(){
		delete[] arr;
	}
private:
	unsigned int top;
	unsigned int max_size;
	int *arr;
};

int main(){
	Stack S;
	S.push(12);
	int a=S.pop();
	std::cout<<a<<std::endl;
	return 0;
}
