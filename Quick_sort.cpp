/*
author : Mr Rupesh Garhwal 
id: rg_rupeee
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)

#define MAX_N 1e5 + 1
#define INF 1e9
#define MOD 1e9 + 7
#define LINF 1e18

#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, a, n) for (i = a; i <= n; ++i)
#define REPR(i, n, a) for (i = n; i >= a; --i)

ll partition(ll arr[], ll low, ll high)
{
 
    cout << "partition: " << low << " : " << high << endl;
    ll i, j, x;
    x = arr[low];
    i = low;
    j = high;
    while (i < j)
    {
      while (arr[i]<=x && i<high)
      {
        i++;
      }
      while (arr[j]>x && j>0)
      {
        j--;
      }
      if (i < j)
      {
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[low], arr[j]);
    cout << j << endl;
    return j;
  
}

void QuickSort(ll arr[], ll low, ll high)
{
  if (low <= high)
  {
    ll k = partition(arr, low, high);
    QuickSort(arr, low, k - 1);
    QuickSort(arr, k + 1, high);
  }
}

void solve()
{
  // All The Best
  // Stay Focused
  ll n;
  // cout << "Enter size of array: ";
  cin >> n;
  ll i;
  ll arr[n];
  // cout << "Enter elements of array: ";
  rep(i, n)
  {
    cin >> arr[i];
  }

  cout << "Array before sorting: " << endl;
  rep(i, n)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  QuickSort(arr, 0, n - 1);

  cout << "Array after sorting: " << endl;
  rep(i, n)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{

  //fast_io;

  solve();

  return 0;
}