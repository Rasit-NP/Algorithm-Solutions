class Solution {
    private String numToString(long n){
        int idx = 0;
        long sz = 0;
        while (sz < n){
            ++idx;
            sz = (sz+1) * 26;
        }

        byte[] bytes = new byte[idx];
        n -= sz/26;
        
        for (int i=idx-1; i>=0; --i, n/=26){
            bytes[i] = (byte)('a' + (n%26));
        }
        
        String res = new String(bytes);
        
        return res;
    }
    
    private long stringToNum(String s, String[] bans){
        long res = (long) Math.pow(26, s.length())-26;
        res /= 25;
        
        for (long i=s.length()-1, base = 1; i>=0; --i, base*=26){
            char c = s.charAt((int)i);
            res += base * (c-'a');
        }
                
        for (String ban : bans){
            if (s.length() == ban.length()){
                int cmp = s.compareTo(ban);
                
                if (cmp > 0)
                    --res;
            }
            else if (s.length() > ban.length()){
                --res;
            }
        }
        
        return res;
    }
    
    public String solution(long n, String[] bans) {
        long l = 0, r = --n + 500_000;
        
        while (r-l > 1){
            long mid = (l+r)/2;
            String spell = numToString(mid);
            long num = stringToNum(spell, bans);
                        
            if (num > n){
                r = mid;
            }
            else {
                l = mid;
            }
        }
        
        return numToString(l);
    }
}