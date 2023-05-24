#include <bits/stdc++.h>

using namespace std;

/*
 * Ideja: na pocetku jedini element je minimalni, kad dodamo novi element, ako je on <= od njega, on postaje novi
 * minimalni i stavljamo ga u minimalni stek. Dok god nakon njega dolaze veci elementi on ostaje minimalan
 * */
class MinStack {
private:
    stack<int> normalStack;
    stack<int> minStack;
public:
    MinStack() {

    }

    void push(int val) {
        normalStack.push(val);
        if(minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if(normalStack.top() == minStack.top()) {
            minStack.pop();
        }
        normalStack.pop();
    }

    int top() {
        return normalStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};