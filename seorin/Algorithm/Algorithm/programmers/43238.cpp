#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long start = 1, end = times[times.size()-1] * n;
    while (start < end) {
        long long mid = (start + end)/2;
        long long person =0;
        for (auto time : times) {
            person += mid/time;
        }
        if (person < n) {
            start = mid+1;
        } else {
            end = mid;
        }
    }
    answer = end;
    return answer;
}

int main() {
    vector<int> times;
    // /*
    times.push_back(7);
    times.push_back(10);
    cout <<  solution(6, times) << "\n";
    // */
/*
    times.push_back(1);
    times.push_back(3);
    times.push_back(5);
    cout <<  solution(10, times) << "\n";
    */
}