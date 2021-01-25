struct node{
	int u,step;
	node(){};
	node(int a,int sp)
	{
		u=a;step=sp;
	}
	bool operator < (const node&a)const
	{
		return step<a.step;
	}
};
