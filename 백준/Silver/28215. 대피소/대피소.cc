#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int calculate_distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int find_max_min_distance(const vector<pair<int, int>>& houses, const vector<pair<int, int>>& shelters)
{
    int max_distance = 0;
    for(const auto& house : houses)
    {
        int min_distance = 1e9;
        for(const auto& shelter : shelters)
        {
            min_distance = min(min_distance, calculate_distance(house, shelter));
        }
        max_distance = max(max_distance, min_distance);
    }
    return max_distance;
}


int main(void)
{
    int N, K;
    cin >> N  >> K;
    vector<pair<int, int>> pos(N);
    for(int i=0;i<N;i++)
    {
        cin >> pos[i].first>>pos[i].second;
    }

    vector<int> comb(N,0);
    fill(comb.end()-K, comb.end(), 1);

    int min_max_distance = 1e9;

    do{
        vector<pair<int, int>> selected_shelters;
        for(int i=0;i<N;i++)
        {
            if(comb[i] == 1)
            {
                selected_shelters.push_back(pos[i]);
            }
        }
        int current_distance = find_max_min_distance(pos, selected_shelters);
        min_max_distance = min(min_max_distance, current_distance);
    }while(next_permutation(comb.begin(), comb.end()));

    cout << min_max_distance << endl;

}