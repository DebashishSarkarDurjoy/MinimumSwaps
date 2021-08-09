#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countMinSwaps(vector<int> arr) {
  int ans = 0;
  int n = arr.size();
  pair<int, int> ap[n];
  for (int i = 0; i < n; i++) {
    ap[i].first = arr[i];
    ap[i].second = i;
  }

  sort(ap, ap+n);

  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {

    // if already visited or already in right place
    int old_index = ap[i].second;
    if ((visited[i] == true) || (old_index == i)) {// old_index == new_index
      continue;
    }
    // if not visited before
    int node = i;
    int cycle = 0;
    while (!visited[node]) {
      visited[node] = true;
      node = ap[node].second;
      cycle++;
    }
    ans += (cycle - 1);

  }

  return ans;
}

int main(void) {
  vector<int> arr{10,11,5,4,3,2,1};
  cout << countMinSwaps(arr) << endl;

  return 0;
}
