#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
const int NUMBER_OF_COOKIES = 6;

int main () {
	int T, N, c, v;
	int best_idx;
	int freq[NUMBER_OF_COOKIES];
	int winner;
	int max, score;
	scanf("%d ", &T);
	while (T-- > 0) {
		max = INT_MIN;
		winner = -1;
		scanf("%d ", &N);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < NUMBER_OF_COOKIES; ++j) freq[j] = 0;
			scanf("%d ", &c);
			score = c;
			for (int j = 0; j < c; ++j) {
				scanf("%d", &v); v--;
				freq[v]++;
			}
//            for (int l = 0; l < NUMBER_OF_COOKIES; ++l) {
//                cout << freq[l] << " ";
//            }
//            cout << endl;
			for (int j = 0; j < NUMBER_OF_COOKIES - 1; ++j) {
				best_idx = j;
				for (int k = j + 1; k < NUMBER_OF_COOKIES; ++k) {
					if (freq[best_idx] > freq[k]) best_idx = k;
				}
				int temp = freq[j];
				freq[j] = freq[best_idx];
				freq[best_idx] = temp;
			}
//            for (int l = 0; l < NUMBER_OF_COOKIES; ++l) {
//                cout << freq[l] << " ";
//            }
//            cout << endl;
			int price = 4;
			int j = 0;
			int count = 0;	
			while(j < 3) {
				if (freq[j] - count > 0) {
					score += price * (freq[j] - count);
					count = freq[j];
				}
				price >>= 1;
				j++;
			}
			if (score == max) winner = -1;
			else if (score > max) {
				winner = i;
				max = score;
			}			
		}
		if (winner == -1) printf("tie\n");
		else if (winner > 0) printf("%d\n", winner + 1);
		else printf("chef\n");
	}
	return 0;
}	

