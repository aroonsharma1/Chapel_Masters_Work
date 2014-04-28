
int foo(int a, int b)
{
	int c,temp3;
	int temp1,temp2;

	c = a*b;
	temp1 = a+b;
	temp2 = a/b;

	if(a>40)
	{
		temp3 = temp1 + temp2;
	}
	else
	{
		temp3 = temp1 - temp2;
	}

	c = c + temp3;
	return c;
}

int main()
{
	int z;
	z = foo(10,20);
	return z;
}

