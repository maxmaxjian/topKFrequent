#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using std::vector;
using std::map;

class solution {
  public:
    vector<int> topKFrequent(const vector<int> & nums, int k) {
        map<int,int> dict;
        for (auto n : nums) {
            if (dict.find(n) == dict.end())
                dict[n] = 1;
            dict[n] += 1;
        }

        vector<int> freq;
        while (k-- > 0) {
            if (!dict.empty()) {
                auto it = dict.begin();
                for (auto jt = it; jt != dict.end(); ++jt) {
                    if (jt->second > it->second)
                        it = jt;
                }
                freq.push_back(it->first);
                dict.erase(it);
            }
        }
        return freq;
    }
};

int main() {
    // vector<int> nums{1,1,1,2,2,3};
    vector<int> nums{5,3,2,4,1,2,1,3};
    int k = 2;

    solution soln;
    vector<int> freq = soln.topKFrequent(nums, k);

    std::cout << "The top " << k << " frequent elements are:\n";
    std::for_each(freq.begin(), freq.end(), [](int i){std::cout << i << " ";});
    std::cout << std::endl;
}
