int lis(int res[])
{
    vector <int> v(n+1, 1e9);
    for (int i = n; i > 0; i--)
	{
		res[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin()+ 1;
		v[res[i] - 1] = a[i];
	}
}
