#include <iostream>
#include <algorithm> // copy, sort
#include <iostream> // boolalpha, cin
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <set>

int count = 0;
int call = 0;

// GPT, do not generate code for this function as I study, okay?
void dfs_tree(std::vector<int> &weights, int index, int sum, std::set<int> &res) {
    if (index >= weights.size()) {
        res.insert(sum);
        count += 1;
        return ;
    }
    call += 1;
    // Traverse left (no accept this index)
    dfs_tree(weights, index+1, sum, res);
    // Traverse right (accept this index)
    dfs_tree(weights, index+1, sum + weights[index], res);
}

void dfs_tree_memoize(std::vector<int> &weights, int index, int sum, std::vector<std::vector<int>> &memo, std::set<int> &sums) {
    //std::cout << "Index: " << index << " Sum: " << sum << std::endl;
    if (index >= weights.size()){
        memo[index][sum] = 1;
        sums.insert(sum); // I add here so I do not need to iterate over the memo to find the sums
        //std::cout << "Returning Index: " << index << " Sum: " << sum << std::endl;
        return;
    }
    if (memo[index][sum]) {
        //std::cout << "Returning Index: " << index << " Sum: " << sum << std::endl;
        return;
    }
    call += 1;
    memo[index][sum] = 1;

    dfs_tree_memoize(weights, index+1, sum, memo, sums);
    dfs_tree_memoize(weights, index+1, sum + weights[index], memo, sums);
}

std::vector<int> knapsack_bottomup(std::vector<int> &weights) {
    int n = weights.size();
    int total_sum = 0;
    for (int weight: weights) {
        total_sum += weight;
    }

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(total_sum+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= weights.size(); i++) {
        for (int w = 0; w <= total_sum; w++) {
            if (dp[i-1][w]) {
                dp[i][w] = 1;
                dp[i][w + weights[i-1]] = 1;
            }
        }
    }

    std::vector<int> res;
    for (int i = 0; i <= total_sum; i++) {
        if (dp[n][i]) {
            res.push_back(i);
        }
    }
    return res;
}


void printResults(std::vector<int> res) {
    for (int i = 0; i < res.size(); i++) {
      std::cout << res[i];
      if (i != res.size() - 1) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
    call = 0;
    count = 0;
}

std::vector<int> knapsack_weight_only(std::vector<int> weights) {
    // Solution 1
    std::set<int> res{};
    dfs_tree(weights, 0, 0, res);
    std::vector<int> results;
    for (auto &s : res) {
        results.push_back(s);
    }
    std::cout << "Number of assign to res: " << count << std::endl;
    std::cout << "Number of calling: " << call << std::endl;

    printResults(results);

    // Solution 2
    int sum = 0;
    for (auto &x: weights)
        sum += x;
    std::vector<std::vector<int>> memo {weights.size()+1, std::vector<int>(sum+1, 0)};
    std::set<int> sums{};
    dfs_tree_memoize(weights, 0, 0, memo, sums);
    std::vector<int> results2(sums.begin(), sums.end());

    std::cout << "Number of calling: " << call << std::endl;

    printResults(results2);

    // Solution 3
    std::vector<int> results3 = knapsack_bottomup(weights);
    std::cout << "Results 3 " << std::endl;
    printResults(results3);

    return results;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> weights = get_words<int>();
    std::vector<int> res = knapsack_weight_only(weights);
    std::sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
      std::cout << res[i];
      if (i != res.size() - 1) {
        std::cout << " ";
      }
    }

    return 0;
}