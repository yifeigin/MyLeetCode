class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int width = 0, height = 0;
        if (C>=E && C<=G && E>=A) width = C- E;
        else if (G>=A && C>=G && E<=A) width = G-A;
        else if (G>C && A>E) width = C-A;
        else if (C>=G && E>=A) width = G-E;
        if (H>=B && H<=D && B>=F) height = H-B;
        else if (D>=F && H>=D && B<=F) height = D-F;
        else if (D>=H && F>=B) height = H-F;
        else if (D<H && F<B) height = D-B;
        
        return (D-B)*(C-A) + (H-F)*(G-E) - width * height;
        
    }
};