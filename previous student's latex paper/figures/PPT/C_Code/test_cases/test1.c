
int foo(int a, int b)
{
	int c=30;
	int temp;

	if(a>40)
	{
		temp = c*a;
		c = temp+5;
	}
	else
	{
		temp = c*b;
		c =  temp + 25;
	}

	return c;
}

int main()
{
	int z;
	z = foo(10,20);
	return z;
}

