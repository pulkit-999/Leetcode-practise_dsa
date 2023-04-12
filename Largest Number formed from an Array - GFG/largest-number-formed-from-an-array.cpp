//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
     static	bool comp(string a,string b)
	{
	    string p=a.append(b);
	      string q=b.append(a);
	    if(p>=q)
	    return true;
	    return false;
	}
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(),arr.end(),comp);
	    string res="";
	    for(auto &x:arr)
	    res.append(x);
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends