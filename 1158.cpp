#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int N,M;
	scanf("%d %d",&N,&M);

	vector<int> v;

	for(int i = 1; i <= N; i++)
		v.push_back(i);

	int cur = 0;
	printf("<");

	while(v.size() != 0) {
		cur = (cur + M - 1) % v.size();
		printf("%d", v[cur]);
		v.erase(v.begin() + cur);
		if(v.size() != 0)
			printf(", ");
	}
	printf(">");

	return 0;
}