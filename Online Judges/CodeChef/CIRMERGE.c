#include <stdio.h>

long long ts, mot,nombor[404],muksto[804],uttor[804][804],moddo[804][804];

int main(){
	
	scanf("%lld",&ts);
	while(ts--){
		scanf("%lld",&mot);
		for(int i = 1; i <= mot; i++){
			scanf("%lld",&nombor[i]);
			muksto[i] = muksto[i-1]+nombor[i]; 
		}
		for(int i = 1;i<=mot;i++){
			muksto[mot+i] = muksto[mot+i-1]+nombor[i]; 
		}
		for(int lomba = 0;lomba<=mot+mot;lomba++){
			for(int bam  = 0;bam+lomba<=mot+mot; bam++ ){
				int dan = bam + lomba;
				if(lomba < 2){
					uttor[bam][dan] = 0;
					moddo[bam][dan] = bam;
					continue;
				}
				int nBam = moddo[bam][dan-1];
				int nDan = moddo[bam+1][dan];
				uttor[bam][dan] = 1e18;
				for ( int maj = nBam; maj <= nDan; maj++)
				{
					long long apatoto = uttor[bam][maj]+uttor[maj][dan]+muksto[dan]-muksto[bam];
					if(uttor[bam][dan]>apatoto){
						uttor[bam][dan] = apatoto;
						moddo[bam][dan] = maj;
					}
				}	
			}
		}
		long long nUttor = 1e18;
		for(int i = 0;i<=mot;i++){
			nUttor = (nUttor>uttor[i][i+mot])?uttor[i][mot+i]:nUttor;
		} 
		printf("%lld\n",nUttor);
	}
	return 0;
}
