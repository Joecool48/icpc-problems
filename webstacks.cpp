#include<iostream>
#include<stack>

using namespace std;


int main () {
    stack<string> backStack, frontStack;

    string currentCmd = "";
    string currentPage = "http://www.acm.org/";

    while (currentCmd != "QUIT") {
        cin >> currentCmd;
        if(currentCmd == "BACK") {
            if (backStack.empty()) {
                cout << "Ignored" << endl;
                continue;
            }
            frontStack.push(currentPage);
            currentPage = backStack.top();
            backStack.pop();
            cout << currentPage << endl;
        }
        else if (currentCmd == "FORWARD") {
            if (frontStack.empty()) {
                cout << "Ignored" << endl;
                continue;
            }
            backStack.push(currentPage);
            currentPage = frontStack.top();
            frontStack.pop();
            cout << currentPage << endl;
        }
        else if (currentCmd == "VISIT") {
            backStack.push(currentPage);
            frontStack = stack<string>();
            cin >> currentPage;
            cout << currentPage << endl;
        }
    }
}
