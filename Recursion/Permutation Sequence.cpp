class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
int i,kk=k,nn=n, fact=1; 
	for(i=1;i<n;i++)
	{
		fact*=i;
		arr.push_back(i);
	}
	arr.push_back(n);
	kk-=1;
	string ans;
	for(i=0;i<n;i++)
	{
		ans=ans+to_string(arr[kk/fact]);
		arr.erase(arr.begin()+ kk/fact);
        if(arr.size()==0)
            break;
		kk=kk%fact;
		fact/= arr.size();
}
return ans;
    }
};


