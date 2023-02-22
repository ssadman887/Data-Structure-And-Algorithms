#include<bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (non_full_stacks.empty()) {
            stacks.push_back(stack<int>());
            non_full_stacks.push_back(stacks.size() - 1);
            non_empty_stacks.push_back(stacks.size() - 1);
        }
        int stack_index = non_full_stacks.front();
        stacks[stack_index].push(val);
        if (stacks[stack_index].size() == capacity) {
            non_full_stacks.pop_front();
        }
        if (stack_index != non_empty_stacks.back()) {
            non_empty_stacks.push_back(stack_index);
        }
    }

    int pop() {
        if (non_empty_stacks.empty()) {
            return -1;
        }
        int stack_index = non_empty_stacks.back();
        int val = stacks[stack_index].top();
        stacks[stack_index].pop();
        if (stacks[stack_index].empty()) {
            non_empty_stacks.pop_back();
        }
        if (stack_index != non_full_stacks.front()) {
            non_full_stacks.push_front(stack_index);
        }
        return val;
    }

    int popAtStack(int index) {
        if (index >= stacks.size() || stacks[index].empty()) {
            return -1;
        }
        int val = stacks[index].top();
        stacks[index].pop();
        if (stacks[index].size() == capacity - 1) {
            non_full_stacks.push_front(index);
        }
        if (index != non_empty_stacks.back()) {
            non_empty_stacks.push_back(index);
        }
        return val;
    }

private:
    int capacity;
    vector<stack<int>> stacks;
    deque<int> non_full_stacks;
    vector<int> non_empty_stacks;
};

int main() {
    DinnerPlates dp(2); // initialize DinnerPlates object with capacity of 2

    dp.push(1);
    dp.push(2);
    dp.push(3);
    dp.push(4);
    dp.push(5);

    std::cout << dp.popAtStack(0) << std::endl; // output: 2
    dp.push(20);
    dp.push(21);
    std::cout << dp.popAtStack(0) << std::endl;
    std::cout << dp.popAtStack(2) << std::endl;
    std::cout << dp.pop() << std::endl; // output: 4
    std::cout << dp.pop() << std::endl; // output: 3
    std::cout << dp.pop() << std::endl; // output: 5
    std::cout << dp.pop() << std::endl; // output: 1
    std::cout << dp.pop() << std::endl; // output: -1 (all stacks are empty)
}
