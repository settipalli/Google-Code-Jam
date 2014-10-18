#include <iostream>
#include <cstdio>   // required for redirecting input
#include <cstdlib>  // required for srand

#ifdef DEBUG
#include <ctime>    // required for clock
#endif

#ifdef DEBUG
void redirect_input() {
    freopen("input/A-small.in", "r", stdin);
}
#endif

const bool debug = false; // mark this as false before submission.
const int MAX_LINE_SIZE = 4096;
const int grid_rows = 4;
const char bad_magician[] = "Bad magician!";
const char volunteer_cheated[] = "Volunteer cheated!";

using namespace std;

void read_rows(int &r, int (&row)[grid_rows]) {
    // Read the rows.
    for (int m = 1; m <= grid_rows; m++) {
        char line[MAX_LINE_SIZE];
        fgets(line, MAX_LINE_SIZE, stdin);
        if (m == r) {
            sscanf(line, "%d %d %d %d", &row[0], &row[1], &row[2], &row[3]);
        }
    }
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
        // For each test case, read 10 lines.
        int first_row[grid_rows] = { 0 }; // store the contents of row which the volunteer selected.
        int second_row[grid_rows] = { 0 };

        int r = 0; // points to the rows which the volunteer chooses.
        scanf("%d\n", &r);

#ifdef DEBUG
        if (debug == true) printf("R1: %d\n", r);
#endif

        read_rows(r, first_row);

#ifdef DEBUG
        if (debug == true) {
            printf("R1 Contents: ");
            for (int count = 0; count < grid_rows; count++) {
                printf("%d ", first_row[count]);
            }
            printf("\n");
        }
#endif

        scanf("%d\n", &r);

#ifdef DEBUG
        if (debug == true) printf("R2: %d\n", r);
#endif
        read_rows(r, second_row);

#ifdef DEBUG
        if (debug == true) {
            printf("R2 Contents: ");
            for (int count = 0; count < grid_rows; count++) {
                printf("%d ", second_row[count]);
            }
            printf("\n");
        }
#endif

        int matching_card = -1;
        bool multiple_matching_cards = false;

        // Compare every digit in second_row with all digits in first row.
        for (int count = 0; count < grid_rows; count++) {
            for (int first_row_count = 0; first_row_count < grid_rows;
                    first_row_count++) {
                if (second_row[count] == first_row[first_row_count]) {
                    if (matching_card > -1) {
                        multiple_matching_cards = true;
                        break;
                    } else {
                        matching_card = second_row[count];
                    }
                }
            }
        }
        // Result.
        printf("Case #%d: ", test_case);
        if (multiple_matching_cards == true) {
            printf("%s", bad_magician);
        } else if (matching_card <= -1) {
            printf("%s", volunteer_cheated);
        } else {
            printf("%d", matching_card);
        }
        printf("\n");
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
