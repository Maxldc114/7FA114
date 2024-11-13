#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
#define fi first
#define se second
#define N 100005
#define M 100000000000007ll
using namespace std;
ll a[N],ans[N];
bool vis[N];
pr nxt[N],pre[N];
ll get(string s){
	ll f=1,l=s.length(),ans=0;
	if(s[0]=='-')f=-1,l--;
	else s=" "+s;
	for(ll i=1;i<=l;i++)ans=ans*10+(ll)(s[i]-'0');
	return ans*f;
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.ans","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		string s;
		for(ll i=1;i<=n;i++){
			cin>>s;
			if(s[0]=='?')a[i]=0,vis[i]=1;
			else a[i]=get(s),vis[i]=0;
			ans[i]=0;
		}
		bool fl=0;
		for(ll i=1;i<=k;i++){
			ll ed=0;
			for(ll j=i;j<=n;j+=k)nxt[j].fi=nxt[j].se=pre[j].fi=pre[j].se=0,ed=j;
			nxt[ed]={M,0};
			if(!vis[ed])nxt[ed]={a[ed],0};
			for(ll j=ed-k;j>=1;j-=k){
				nxt[j]={nxt[j+k].fi,nxt[j+k].se+1};
				if(!vis[j])nxt[j]={a[j],0};
			}
			pre[i]={-M,0};
			if(!vis[i])pre[i]={a[i],0};
			for(ll j=i+k;j<=n;j+=k){
				pre[j]={pre[j-k].fi,pre[j-k].se+1};
				if(!vis[j])pre[j]={a[j],0};
			}
			for(ll j=i;j<=n;j+=k){
				if(vis[j]==0){
					ans[j]=a[j];
					continue;
				}
				if(nxt[j].fi-pre[j].fi-1<nxt[j].se){
					cout<<"Incorrect sequence\n";
					fl=1;
					break;
				}
				if(pre[j].fi>=0){
					for(ll h=j;h<=j+nxt[j].se*k;h+=k)ans[h]=ans[h-k]+1;
					if(nxt[j+nxt[j].se*k].fi!=M)ans[j+nxt[j].se*k]=a[j+nxt[j].se*k];
					j+=nxt[j].se*k;
					continue;
				}
				if(nxt[j].fi<=0){
					if(nxt[j+nxt[j].se*k].fi!=M)ans[j+nxt[j].se*k]=a[j+nxt[j].se*k];
					for(ll h=j+nxt[j].se*k-k;h>=j;h-=k)ans[h]=ans[h+k]-1;
					j+=nxt[j].se*k;
					continue;
				}
				ll mid=j+(nxt[j].se)/2*k;
				if(nxt[mid].fi<nxt[mid].se){
					if(nxt[j+nxt[j].se*k].fi!=M)ans[j+nxt[j].se*k]=a[j+nxt[j].se*k];
					for(ll h=j+nxt[j].se*k-k;h>=j;h-=k)ans[h]=ans[h+k]-1;
					j+=nxt[j].se*k;
					continue;
				}
				if(-pre[mid].fi<pre[mid].se){
					for(ll h=j;h<=j+nxt[j].se*k;h+=k)ans[h]=ans[h-k]+1;
					if(nxt[j+nxt[j].se*k].fi!=M)ans[j+nxt[j].se*k]=a[j+nxt[j].se*k];
					j+=nxt[j].se*k;
					continue;
				}
				ans[mid]=0;
				if(nxt[j+nxt[j].se*k].fi!=M)ans[j+nxt[j].se*k]=a[j+nxt[j].se*k];
				for(ll h=mid+k;h<=j+nxt[j].se*k;h+=k)ans[h]=ans[h-k]+1;
				for(ll h=mid-k;h>=j;h-=k)ans[h]=ans[h+k]-1;
				if(nxt[j+nxt[j].se*k].fi!=M)ans[j+nxt[j].se*k]=a[j+nxt[j].se*k];
				j+=nxt[j].se*k;
			}
			if(fl)break;
		}
//		cout<<"\n\n\n";
//		for(ll i=1;i<=n;i++)cout<<pre[i].fi<<"^"<<pre[i].se<<" ";cout<<"\n";
//		for(ll i=1;i<=n;i++)cout<<nxt[i].fi<<"^"<<nxt[i].se<<" ";cout<<"\n";
//		cout<<"\n\n\n";
		if(fl)continue;
		for(ll i=1;i<=n-k;i++)if(ans[i]>=ans[i+k]){
			cout<<"Incorrect sequence\n";
			fl=1;
			break;
		}
		if(fl)continue;
		for(ll i=1;i<=n;i++)cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}