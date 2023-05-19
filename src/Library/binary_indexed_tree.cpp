// http://hos.ac/slides/20140319_bit.pdf
// N<=10^6の時, indexは1スタート
int N;
int bit[1000010];
void add(int a, int w) {
    for (int x = a; x <= N; x += x & -x) bit[x] += w;
}
int sum(int a) {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}
