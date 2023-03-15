#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/161988

#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    const int sequenceSize = sequence.size();
    vector<long long> dp1(sequenceSize, 0);
    vector<long long> dp2(sequenceSize, 0);

    dp1[0] = max(0, sequence[0]);
    dp2[0] = max(0, -sequence[0]);

    long long max_dp_1 = dp1[0];
    long long max_dp_2 = dp2[0];

    for (int i = 1; i < sequenceSize; ++i) {
        if (i % 2 == 0) {
            dp1[i] = max(dp1[i - 1] + sequence[i], (long long)sequence[i]);
            dp2[i] = max(dp2[i - 1] - sequence[i], (long long)-sequence[i]);
        }
        else {
            dp1[i] = max(dp1[i - 1] - sequence[i], (long long)-sequence[i]);
            dp2[i] = max(dp2[i - 1] + sequence[i], (long long)sequence[i]);
        }

        max_dp_1 = max(max_dp_1, dp1[i]);
        max_dp_2 = max(max_dp_2, dp2[i]);
    }

    long long maxPulseSequenceSum = max(max_dp_1, max_dp_2);
    return maxPulseSequenceSum;
}

void main()
{
    const vector<int> sequence{ 2, 3, -6, 1, 3, -1, 2, 4 };
    cout << solution(sequence);
}