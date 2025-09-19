#include<iostream>
#include<vector>
#define f first
#define s second
using namespace std;
int Build_Tree(vector<pair<int,int> >&T,vector<int>& P,vector<int>& I,vector<int>& M,int l,int r,int &i){
    //returns the root of this subtree
	//	cout << "Trying to find " << P[i] << " in " << l << " -> " << r << endl;
	if(r<l) return -1;
	int here = P[i];
	int where = M[here];
	if(where>r||where<l) return -1;
	else i++;
	T[here].f = Build_Tree(T,P,I,M,l,where-1,i);
	T[here].s = Build_Tree(T,P,I,M,where+1,r,i);
	return here;
}
void dfs(int i,vector<pair<int,int> > &T){
	if(T[i].f!=-1) dfs(T[i].f,T);
	if(T[i].s!=-1) dfs(T[i].s,T);
	cout << i << " ";
}
int main(){
	int n;
	cin >> n;
	vector<int> pre;
	vector<int> in;
	vector<pair<int,int> > V(n+1,pair<int,int>(-1,-1));
	int tmp;
	for(int i = 0;i<n;i++){
		cin >> tmp;
		pre.push_back(tmp);
	}
	for(int i = 0;i<n;i++){
		cin >> tmp;
		in.push_back(tmp);
	}
	vector<int> map_in(n+1,-1);
	for(int i = 0;i<n;i++){
		map_in[in[i]] = i;
	}
	int begin = 0;
	int root = Build_Tree(V,pre,in,map_in,0,n-1,begin);
	dfs(root,V);
	cout << endl;
	return 0;
}