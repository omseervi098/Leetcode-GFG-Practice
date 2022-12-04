class Solution:
    def dividePlayers(self, s: List[int]) -> int:
        sm=2*sum(s)//len(s)
        c=Counter(s)
        prod=0
        for a,b in c.items():
            if b!=c[sm-a]:
                return -1
            prod+=a*b*(sm-a)
        return prod//2
        