class MovingAverage{
public:
	vector<int>arr;
	int i;
	double sum = 0;
	int size = size;
	MovingAverage(int size)
	{
		this->size = size;
		i = 0;
		sum = 0;
		arr.resize(size);
		fill(arr.begin(), arr.end(),0);
	}

	double next(int val)
	{
		sum+= val - arr[i%size];
		arr[i%size]= val;
		i++;
		return sum/min(i,size);

	}

}