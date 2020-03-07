/*
 * https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/#2d
 * */
int BIT[MX+5][MX+5];
void update(int x,int y,int val){
	while(x<=MX){
		int y1=y;
		while(y1<=MX){
			BIT[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x+=(x&-x);
	}
}
int query(int x,int y){
	int ret = 0, y1;
	while(x>0){
		y1= y;
		while(y1>0){
			ret += BIT[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return ret;
}
