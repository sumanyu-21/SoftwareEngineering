
/* ***************************UNORDERED MAP WITH CUSTOM DATA TYPE**************************/
/*NOTE: -> OPERATOR IS USED TO ACCESS KEY AND VALUE****************************************/
struct key
{
	int i;
	int j;
	bool operator==(const key &other)const
	{
		return (i==other.i && j==other.j);
	}

};
namespace std
{
	template<>
	struct hash<key>
	{
		std::size_t operator()(const key &k)const
		{

            auto h1=std::hash<int>{}(k.i);
            auto h2=std::hash<int>{}(k.j);
            return h1^h2;
		}
	};
}


/****************************PRIORITY_QUEUE/SET/MULTISET CUSTOM ORDERING**********************************/
/*IMPORTANT POINTS--PRIORITY QUEUE ->USE GREATER THAN SIGN FOR MIN HEAP AND VICE VERSA
					SET/MULTISET   ->USE GREATER THAN SIGN IF LARGER NUMBER IS GIVEN PREFERNECE*/
struct cell
{
	ll x,y;
	ll value;
	cell(ll x,ll y) : x(x), y(y)
	{
		value=(min(m+1,y+r)-max(y,r))*1LL*(min(n+1,x+r)-max(x,r));
	}
	bool operator <(const cell &other)const
	{
		return value<other.value;
	}
};


/******************************PRINTING DECIMAL VALUES************************/
cout<<std::setprecision(6)<<std::fixed<<ans<<endl;




/******************IMPORTANT MOVES IN A GRID************************/
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dx[8]={1,1,1,-1,-1,-1,0,0}
int dy[8]={-1,0,1,-1,0,1,-1,1};

int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};




/************************************UPPER BOUND AND LOWER BOUND*********************************/
/* lower_bound returns iterator to the first element in range[first,last) which compares>=val,otherwise it returns iterator to end
   upper_bound returns iterator to the first element in range[first,last) which compares> val,otherwise it returns iterator to end*/
std::vector<int>::iterator low,up;
low=std::lower_bound (v.begin(), v.end(), val);       
up= std::upper_bound (v.begin(), v.end(), val);
std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
std::cout << "upper_bound at position " << (up - v.begin()) << '\n';


/**********************************MULTIPLY 2 NUMBERS ONLY IF THEY DO NOT EXCEED 10^18************************************/
ll N=2e18;
bool safe_mul(ll a, ll b)
{
    if(a<=(N+b-1)/b)
        return true;
    else
        return false;
}