#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int sum_n = 0;
    while (t--)
    {
        int n;
        cin >> n;
        sum_n += n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int cnt_zrs = count(arr.begin(), arr.end(), 0);
        if (cnt_zrs == 0 || cnt_zrs == n)
        {
            cout << "0\n";
            continue;
        }
        if ((cnt_zrs) < (n) / 2)
        {
            cout << "-1\n";
            continue;
        }
        int cnt = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            if (!arr[i])
                continue;
            if ((arr[i] == arr[i + 1]) && arr[i])
            {
                i++;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
