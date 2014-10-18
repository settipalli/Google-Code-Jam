#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <ctime>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include <vector>
#include <set>
#include <bitset>
#include <deque>
#include <stack>
#include <list>
#include <map>

#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

const int LINE_SIZE = 4096;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt;
    scanf("%d\n", &tt);
    for (int qq = 1; qq <= tt; qq++) {
        printf("Case #%d: ", qq);
        char line[LINE_SIZE], *p;
        fgets(line, LINE_SIZE, stdin);
        vector<char *> v;
        p = strtok(line, " \n");
        while (p != NULL) {
            v.push_back(p);
            p = strtok(NULL, " \n");
        }
        for (vector<char *>::reverse_iterator r = v.rbegin(); r != v.rend();
                r++) {
            printf("%s", *r);
            if (r != v.rend()) printf(" ");
        }
        puts("");
    }
    return 0;
}
