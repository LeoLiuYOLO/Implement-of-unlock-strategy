#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
using namespace std;

const double eps = 1e-8;

int c[30], num_complete_subset[30];
vector<int> completed_list[110];
double total_time, end_time;

int rand_20() {
    return rand() % 20 + 1;
}


int rand_10_20() {
    return rand() % 11 + 10;
}

void gen(int x) {
    memset(c, 0, sizeof(c));
    double now_time = 0, cnt = 0;
    while(now_time < total_time - eps && cnt < 20) {
        cnt++;
        int now_subset = rand_20();
        while(c[now_subset] != 0) {
            now_subset = rand_20();
        }
        c[now_subset] = 1;
        now_time += rand_10_20() * sqrt(x * (now_subset + 80));
        if(now_time < total_time + eps) {
            completed_list[x].push_back(now_subset);
            num_complete_subset[now_subset]++;
        }
    }
    if(now_time < end_time) {
        end_time = now_time;
        total_time = end_time;
        for(int i = 1; i < x; i++) {
            gen(i);
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    total_time = 48 * 60;
    end_time = total_time;
    for(int i = 1; i <= 50; i++) {
        gen(i);
    }
    int int_end_time = end_time;
    printf("The event end in %d hours %d minutes\n\n", int_end_time / 60, int_end_time % 60);
    for(int i = 1; i <= 20; i++) {
        printf("Number of teams completed subset ");
        printf("%d: %d\n", i, num_complete_subset[i]);
    }
    for(int i = 1; i <= 50; i++) {
        printf("Team %d completed %d subsets of quests.\n", i, (int)completed_list[i].size());
        printf("Team %d completed subsets: ", i);
        sort(completed_list[i].begin(), completed_list[i].end());
        for(int j = 0; j < (int)completed_list[i].size(); j++) {
            printf("%d ", completed_list[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;
}
