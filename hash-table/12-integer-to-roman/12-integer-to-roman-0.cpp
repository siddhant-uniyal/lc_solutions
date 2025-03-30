#define all(v) v.begin() , v.end()
class Solution {
private:

    vector<int>tens{0,1,10,100,1000};
    vector<int>fours{0,4,40,400};
    vector<int>fives{0,5,50,500};
    vector<int>nines{0,9,90,900};
    map<int , char>mp{
        {1 , 'I'},
        {5 , 'V'},
        {10 , 'X'},
        {50 , 'L'},
        {100 , 'C'},
        {500 , 'D'},
        {1000 , 'M'}
    };
    vector<vector<int>>look{
        fours , fives , nines , tens
    };

    int find(int check, vector<int> &v)
    {
        auto iter = lower_bound(all(v) , check);

        if(iter == v.end() or *iter != check) --iter;

        return *iter;
    }

public:
    string intToRoman(int n) {
        
    string ans = "";

    while (n)
    {

        int isFour, isNine;
        isFour = isNine = 0;

        int minDist = INT_MAX;
        int found = 0;
        int closest = 0;

        for (int i = 0; i < 4 ; ++i)
        {
            closest = find(n, look[i]);
            int dist = n - closest;
            if (dist < minDist)
            {
                minDist = dist;
                found = closest;
                isFour = i == 0;
                isNine = i == 2;
            }
        }

        if (isFour)
        {
            ans += mp[found/4];
            ans += mp[5*found/4];
        }

        else if (isNine)
        {
            ans += mp[found/9];
            ans += mp[10*found/9];
        }

        else{
            ans += mp[found];
        }

        n -= found;
    }

        return ans;
    }
};