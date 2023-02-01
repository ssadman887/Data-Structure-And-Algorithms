#include <stdio.h>

long long laptop_power(int n, long long P1, long long P2, long long P3, int T1, int T2, int intervals[][2]) {
    long long total_power = 0;
    int current_time = intervals[0][0];
    for (int i = 0; i < n; i++) {
        int l = intervals[i][0], r = intervals[i][1];
        // calculate time spent in each mode
        int normal_time = l > current_time ? 0 : (l - current_time > T1 ? T1 : l - current_time);
        int screensaver_time = (l - current_time - T1 > T2) || (l - current_time - T1 < 0) ? 0 : (l - current_time - T1 > 0 ? l - current_time - T1 : T2);
        int sleep_time = (r - current_time - T1 - T2 > 0) ? r - current_time - T1 - T2 : 0;
        // add power consumption for each mode
        total_power += normal_time * P1 + screensaver_time * P2 + sleep_time * P3;
        current_time = r;
    }
    return total_power;
}

int main() {
    int n;
    long long P1, P2, P3;
    int T1, T2;
    scanf("%d %lld %lld %lld %d %d", &n, &P1, &P2, &P3, &T1, &T2);
    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }
    printf("%lld\n", laptop_power(n, P1, P2, P3, T1, T2, intervals));
    return 0;
}
