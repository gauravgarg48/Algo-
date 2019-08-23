#include <bits/stdc++.h>
using namespace std;

// Complete the steadyGene function below.
int steadyGene(string gene) {
    int ch[] = {'A', 'C', 'G', 'T'}, c[4];
    int i, j, k, n2, n = gene.length(), x;
    memset(c, 0, 4*sizeof(int));
    int ans = 0, len;
    n2 = n/4;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < 4; ++j)
            if(gene[i] == ch[j]) {
                c[j]++;
                break;
            }
		if(c[j] > n2) {
			for(k = n-1; k >= i; --k)
				if(gene[i] == gene[k])
					break;
			len = k-i+1;
		}
		if(ans > len)
			ans = len;
    }
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}
