/*
Discrete Logarithm:
The discrete logarithm is an integer x solving the equation
a^x≡b(mod m)
where a and m are relatively prime. (Note: if they are not relatively prime, then the algorithm described below is incorret, though it can be modified so that it can work).
which has complexity O(√mlog(m)).

Algorithm:
Consider the equation:
a^x ≡ b (mod m)
where a and m are relatively prime.

Let x=np−q, where n is some pre-selected constant (we will describe how to select n later). p is known as giant step, since increasing it by one increases x by n. Similarly, q is known as baby step.

Obviously, any value of x in the interval [0;m) can be represented in this form, where p∈[1;⌈m/n⌉]and q∈[0;n].

Then, the equation becomes:
a^(np−q) ≡ b (mod m).

Using the fact that aa and mm are relatively prime, we obtain:
a^(np) ≡ ba^q (mod m)

This new equation can be rewriten in a simplified form:
f1(p) = f2(q).

This problem can be solved using the method meet-in-the-middle as follows:
	We calculate f1 for all possible values of p. Sort these values.
	For each value of q, calculate f2, and look for the corresponding value of p using the sorted array of f1 using binary search.
*/
int Solve(int a,int b,int md){
	n=(int)sqrt(md+.0);
	int an=1;
	for(int i=0;i<n;++i){
		an=(an*a)%md;
	}
	//~ unordered_map<int,int>val;
	//~ map<int,int>val;
	for(int i=1,cr=an;i<=n;++i){
		if(!val.count(cr)){
			val[cr]=i;
		}
		cr=(cr*an)%md;
	}
	for(int i=0,cr=b;i<=n;++i){
		if(val.count(cr)){
			Ans=val[cr]*n-i;
			if(Ans<md){
				return Ans;
			}
		}
		cr=(cr*a)%md;
	}
	return -1;
}

