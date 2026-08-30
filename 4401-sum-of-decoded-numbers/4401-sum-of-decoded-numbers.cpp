typedef long long ll;
class Solution {
public:
    int mod = 1e9+7;
    int decode(ll n) {
        int width = n%10;
        ll d = n/10;
        string num = to_string(d);
        int x = stoi(num.substr(0,width));
        int y = stoi(num.substr(width));
        return powe(x,y);
    }
    int powe(int x, int y) { 
        x = x%mod, y=y%(mod-1);
        ll ans = 1;
        while(y>0) { 
            if (y&1) {
                ans = (1ll * x * ans)%mod;
            }
            y>>=1;
            x = (1ll * x * x)%mod;
        }
        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        int mod=1e9+7,i,n=nums.size(),sum=0;
        for(i=0;i<n;i++) {
            sum = (sum+decode(nums[i])%mod)%mod;
        }
        return int(sum%mod);
    }
};