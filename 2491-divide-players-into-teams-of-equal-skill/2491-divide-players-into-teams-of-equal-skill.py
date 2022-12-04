class Solution:
    def dividePlayers(self, s: List[int]) -> int:
        s.sort()
        st=0;end=len(s)-1;prod=0;p=-1;
        while st<end:
            prod+=s[st]*s[end]
            if p==-1:
                p=s[st]+s[end]
            elif s[st]+s[end]!=p:
                return -1
            else:
                p=s[st]+s[end]
            st+=1
            end-=1
        return prod
        