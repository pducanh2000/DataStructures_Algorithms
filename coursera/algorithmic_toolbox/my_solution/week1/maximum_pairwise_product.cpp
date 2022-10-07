#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    vector<int> max_nums(2);
    if(numbers[0] > numbers[1]){
	max_nums = {1, 0};
    }
    else{
	    max_nums = {0, 1};
    }

    for (int i = 2; i < n; ++i) {
	    if (numbers[i] <= numbers[max_nums[0]]){
		    continue;
	    }
	    else if(numbers[i] >= numbers[max_nums[1]]){
		    max_nums[0] = max_nums[1];
		    max_nums[1] = i;
	    }
	    else{
		    max_nums[0]= i;
	    }
    }
    // cout << max_nums[1] << " " << max_nums[0] << endl;
    max_product = ((long long)numbers[max_nums[1]]) * numbers[max_nums[0]];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}




