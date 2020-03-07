#define MX (ll)1000000
ll vs[MX+1];
ll PHI[MX+1];
vl PRM;
void eulerPhi(){
    PHI[1]=1ll;
    for(ll i=2; i <= MX ; i++){
        if(vs[i]==0){
            vs[i]=i;
            PHI[i]=i-1;
            PRM.pb(i);
        }
        else{
            if(vs[i]==vs[i/vs[i]]){
                PHI[i]=PHI[i/vs[i]]*vs[i];
            }
            else{
                PHI[i]=PHI[i/vs[i]]*(vs[i]-1);
            }
        }
        for(int j=0; j<(int)PRM.size() && PRM[j]<=vs[i] && i*PRM[j]<=MX; j++){
            vs[i*PRM[j]]=PRM[j];
        }
    }
}
/*
You can get it from the formula for PHI:
PHI [n] = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pn) where p1,p2.. pn are the prime factors of n.
Say we know the smallest prime factor of n, that is vs[n]. What is the formula for n/vs[n]?
Well there are two cases:
Case 1:
n/vs[n] is still divisible by vs[n], that is vs[n] is a factor of n with a power greater than or equal to 2, so n/vs[n] has exactly the same prime factors as n.
Then PHI[n/vs[n]] = (n/vs[n]) * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pn) It differs from the above formula by the first term. So just multiply phi[n/vs[n]] by vs[n] to get phi[n]. PHI[n] = PHI[n/vs[n]] * vs[n]
Case 2: 
n/vs[n] is not divisible by vs[n], then the above formula for n/vs[n] is almost the same, it just doesn't have (1 — 1/vs[n]) as one of its terms. So we have to multiply phi[n/vs[n]] not only by vs[n] but also by (1 — 1/vs[n]).
Then PHI[n] = PHI[n/vs[n]] * vs[n] * (1 - 1/vs[n]] => PHI[n] = PHI[n/vs[n]] * (vs[n] - 1)
*/
