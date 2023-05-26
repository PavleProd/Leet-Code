#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> numbers;
    int first, second;
    for(const string& token : tokens) {
        if(token == "+") {
            second = numbers.top();
            numbers.pop();
            first = numbers.top();
            numbers.pop();
            numbers.push(first + second);
        }
        else if(token == "-") {
            second = numbers.top();
            numbers.pop();
            first = numbers.top();
            numbers.pop();
            numbers.push(first - second);
        }
        else if(token == "*") {
            second = numbers.top();
            numbers.pop();
            first = numbers.top();
            numbers.pop();
            numbers.push(first * second);
        }
        else if(token == "/") {
            second = numbers.top();
            numbers.pop();
            first = numbers.top();
            numbers.pop();
            numbers.push(first / second);
        }
        else {
            numbers.push(stoi(token));
        }
    }

    return numbers.top();
}
