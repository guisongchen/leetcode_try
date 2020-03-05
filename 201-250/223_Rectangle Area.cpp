/*

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.

*/


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum1 = (C-A) * (D-B);
        int sum2 = (G-E) * (H-F);
        
        // not overlap case, one rectangle vertex is away of !! diagonal !! pos of another rectangle
        if (B >= H || A >= G || D <= F || C <= E)
            return sum1 + sum2;
        
        // same side (not diagonal) if does overlop
        int overlap = (min(D, H) - max(B, F)) * (min(C, G) - max(A, E));
        
        return sum1 - overlap + sum2;
    }
};
