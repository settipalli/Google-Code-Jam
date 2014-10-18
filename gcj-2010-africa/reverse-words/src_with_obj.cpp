/*
 * main.cpp
 *
 *  Created on: 24-Apr-2014
 *      Author: Santhoshkumar Settipalli
 */

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt = 0;
    scanf("%d\n", &tt);

    for (int qq = 1; qq <= tt; qq++) {
        cout << "Case #" << qq << ":";
        string input;
        getline(cin, input);
        istringstream iss(input);
        stack<string> s;
        while (iss) {
            string temp;
            iss >> temp;
            s.push(temp);
        }

        while (s.empty() == false) {
            cout << s.top();
            s.pop();
            if (!s.empty()) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

