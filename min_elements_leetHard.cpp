Let us assume that target represents height of columns on a square grid. One operation corresponds to laying out continuous row of bricks. What is the number of these rows? To find this number we count the number of left edges of these rows.

Example: [3,1,5,4,2]. Left edges are marked by !.

        +---+
        ! x |
        +---+---+
        ! x | x |
+---+   +---+---+
! x |   ! x | x |
+---+   +---+---+---+
! x |   ! x | x | x |
+---+---+---+---+---+
! x | x | x | x | x |
+---+---+---+---+---+
Applying this approach we get
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res=target[0];
        for(int i=1;i<target.size();i++)
            res+=max(target[i]-target[i-1],0);
        return res;
        
    }
};