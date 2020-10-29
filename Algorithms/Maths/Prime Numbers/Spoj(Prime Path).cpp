# include <iostream>
# include <bits/stdc++.h>

using namespace std;
vector<int>mark(10000,0);
unordered_map<int,int>primes;
int n = 10000;

void sieve()
{
	mark[2] = 1;

	for(int i=3;i<n;i+=2)
		mark[i] = 1;

	for(int i=3;i<=sqrt(n);i++)
	{
		if(mark[i])
		{
			for(int j=i*i;j<n;j+=2*i)
				mark[j] = 0;
		}
	}

	for(int i=2;i<n;i++)
	{
		if(mark[i])
        {
            //cout<<i<<endl;
            primes.insert({i,0});
        }
	}
}

int change_ith_digit(int u, int i, int j)
{
	// Change ith digit of u to j.
	int temp = u;
	int idx = i;
	while(idx>0)
	{
		temp/=10;
		idx--;
	}

	int ith_digit = temp%10;
	return u-(ith_digit*pow(10,i)) + (j*pow(10,i));


}
int bfs(int u, int v)
{
	int ans = 0;
	unordered_map<int,int>visited;
	queue<int>q;
	visited.insert({u,0});
	q.push(u);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		//cout<<u<<" "<<visited[u]<<endl;

		// Try to change each digit of the current number.
		for(int i=0;i<4;i++)
		{
			// Change ith digit to j
			for(int j=0;j<=9;j++)
			{
			    if(i==3 && j==0)
                    continue;

				int y = change_ith_digit(u, i,j);
				// If this number has not been yet visited and is a prime,
				if(visited.find(y)==visited.end() && primes.find(y)!=primes.end())
				{

					q.push(y);
					visited[y] = visited[u] + 1;
					if(y==v)
                    {
                        //cout<<u<<" "<<y<<endl;
                        return visited[y];

                    }
				}
            }
        }

    }
    //cout<<visited[3701]<<" "<<visited[3601]<<endl;
    return ans;
}

int main()
{
	//cout<<change_ith_digit(3733, 2, 4);
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int ans = bfs(n,k);
		if(primes.find(n)!= primes.end() && primes.find(k)!=primes.end())
            cout<<ans<<endl;
        else
            cout<<"Impossible"<<endl;
	}
}
