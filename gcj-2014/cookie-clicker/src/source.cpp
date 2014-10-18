#include <iostream>
#include <cstdio>   // required for redirecting input
#include <cstdlib>  // required for srand
#include <cmath>    // required for fmod

#ifdef DEBUG
#include <ctime>    // required for clock
#endif

#ifdef DEBUG
void redirect_input() {
    freopen("input/B-large.in", "r", stdin);
}
#endif

typedef long double ld;

const bool debug = false; // mark this as false before submission.

using namespace std;

ld time_to_obtain_X_cookies(ld cookies_owned, ld X, ld ccpr) {
    // ccpr -> current cookie production rate.
    ld reach_X_cookies_in_sec = ccpr;
    if (X < cookies_owned) {
        reach_X_cookies_in_sec = 0;
    } else {
        reach_X_cookies_in_sec = (X - cookies_owned) / ccpr;
    }
    return reach_X_cookies_in_sec;
}

ld time_to_obtain_X_cookies_after_buying_farm(ld cookies_owned, ld C, ld F,
        ld X, ld ccpr) {
    ld next_farm_in_sec = C / ccpr;
    cookies_owned += ccpr * next_farm_in_sec; // cookies earned by the time next farm is purchased.

    cookies_owned -= C; // cookies left over after purchasing the farm.
    ccpr += F; // increased cookie_production_rate.

    ld reach_X_cookies_after_buying_in_sec = next_farm_in_sec;

    if (X < cookies_owned) {
        reach_X_cookies_after_buying_in_sec += 0;
    } else {
        reach_X_cookies_after_buying_in_sec += (X - cookies_owned) / ccpr;
    }

    return reach_X_cookies_after_buying_in_sec;
}

ld buy_farm(ld& cookies_owned, ld & C, ld & F, ld & ccpr) {
    ld next_farm_in_sec = C / ccpr;
    cookies_owned += ccpr * next_farm_in_sec; // cookies earned by the time next farm is purchased.
    cookies_owned -= C; // left over after purchasing the farm C.
    ccpr += F; // increased cookie_production_rate.

    return next_farm_in_sec;
}

/* Attempt to answers 2 questions:
 * 1. At current cookie production rate, how long does it take to reach X
 *    cookies without buying new farms.
 * 2. How long does it take to buy new farm at current cookie production rate
 *    plus how long does it take to reach 'X' cookies after that.
 */

ld find_best_case_time_to_reach_X_cookies(ld & C, ld & F, ld & X) {
    ld time_consumed = 0.0;
    // Initial cookie production rate.
    ld cookie_production_rate = 2.0; // per second.
    ld cookies_owned = 0.0; // cookies in my wallet.

    ld ttoxc = 0.0; // time to obtain x cookies with current production rate.
    ld ttoxcabf = 0.0; // time to obtain x cookies after buying farm.

    do {
        ttoxc = time_to_obtain_X_cookies(cookies_owned, X,
                cookie_production_rate);
        ttoxcabf = time_to_obtain_X_cookies_after_buying_farm(cookies_owned, C,
                F, X, cookie_production_rate);

        if (ttoxc <= ttoxcabf)
            time_consumed += ttoxc;
        else
            time_consumed += buy_farm(cookies_owned, C, F,
                    cookie_production_rate);
    } while (ttoxc > ttoxcabf);

    return time_consumed;
}

int main(int argc, char* argv[]) {
#ifdef DEBUG
    redirect_input();
    clock_t start, stop;
    srand(time(0)); // use current time as seed for the random generator. Ref: http://en.cppreference.com/w/cpp/numeric/random/rand
    start = clock();
#endif

    int t = 0;
    scanf("%d\n", &t);

#ifdef DEBUG
    if (debug == true) printf("Number of test cases: %d\n", t);
#endif

    for (int test_case = 1; test_case <= t; test_case++) {
        ld C = 0, F = 0, X = 0, best_case_seconds_to_reach_X_cookies = 0.0;
        scanf("%Lf %Lf %Lf\n", &C, &F, &X);
        best_case_seconds_to_reach_X_cookies =
                find_best_case_time_to_reach_X_cookies(C, F, X);
        printf("Case #%d: ", test_case);
        if (debug == true) {
            printf("C=%.7Lf; F=%.7Lf; X=%.7Lf; Output=%.7Lf", C, F, X,
                    best_case_seconds_to_reach_X_cookies);
        } else {
            printf("%.7Lf", best_case_seconds_to_reach_X_cookies);
        }
        if (test_case != t) printf("\n");
    }

#ifdef DEBUG
    if (debug == true) {
        stop = clock();
        std::cout
                << "=================================================================="
                << std::endl;
        std::cout << "    Usage: " << ((double) stop - start) / CLOCKS_PER_SEC
                << " seconds." << std::endl;
        std::cout
                << "=================================================================="
                << std::endl;
    }
#endif
    return 0;
}
