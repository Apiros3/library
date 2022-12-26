/*vvvvvvvvvvvvvvvvvvv LIBRARIES, TYPE DEFINITIONS, MACROS vvvvvvvvvvvvvvvvvvv*/
#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <type_traits>

using namespace std;

using namespace chrono;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class k_t, class m_t>
// using ordered_map = tree<k_t, m_t, less<T>, rb_tree_tag,
//	tree_order_statistics_node_update>;
// template<class T>
// using ordered_set = ordered_map<T, null_type>;

using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;
using fe = long double;
using i128 = __int128_t;
using u128 = __uint128_t;
template<class T>
using eueuq_ytiroirp = priority_queue<T, vector<T>, greater<T>>;

#define bend(a) (a).begin(), (a).end()
#define rbend(a) (a).rbegin(), (a).rend()
#define binlow(a, v) (lower_bound(bend(a), v) - (a).begin())
#define binup(a, v) (upper_bound(bend(a), v) - (a).begin())
/*^^^^^^^^^^^^^^^^^^^ LIBRARIES, TYPE DEFINITIONS, MACROS ^^^^^^^^^^^^^^^^^^^*/

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv FAST IO vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
template<class T>
void readu(T& a) {
	char c; do c = getchar(); while (!isdigit(c)); a = c & 15;
	for (;;) {c = getchar(); if (!isdigit(c)) break; a = a * 10 + (c & 15);}
}
template<class T>
void readi(T& a) {
	char c; bool n = false; do c = getchar(); while (!isdigit(c) && c != '-');
	if (c == '-') n = true, c = getchar(); a = c & 15;
	for (;;) {c = getchar(); if (!isdigit(c)) break; a = a * 10 + (c & 15);}
	if (n) a = -a;
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ FAST IO ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvv COMMON FUNCTIONS vvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
template<class T1, class T2>
T1& cmin(T1& a, const T2& b) {return a < b ? a : a = b;}
template<class T1, class T2>
T1& cmax(T1& a, const T2& b) {return a < b ? a = b : a;}
u64 gt() {return steady_clock::now().time_since_epoch().count();};
const f64 gtp = (f64) steady_clock::period::num / steady_clock::period::den;
void sleep(long double t) {t = t / gtp + gt(); while (gt() < t);}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^ COMMON FUNCTIONS ^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv LIBRARY vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
template<i32 m>
class mint {
	using t = mint;
	static_assert(m < 1 << 30);
	static constexpr i32 inv(i32 x) { i32 b = 1, a = m, c = 0, d;
		while (x) d = a / x; a -= d * x; c -= d * b; swap(a, x); swap(b, c);
		return c;
	}
public:
	i32 v; mint(i32 v = 0) : v(v) {if ((v %= m) < 0) v += m;}
	t& operator+=(const t& r) {if ((v += r.v) >= m) v -= m; return *this;}
	t& operator-=(const t& r) {if ((v -= r.v) < 0) v += m; return *this;}
	t& operator*=(const t& r) {v = (u64) v * r.v % m; return *this;}
	t& operator/=(const t& r) {return *this *= inv(r.v);}
	t& operator++() {if (++v == m) v = 0; return *this;}
	t& operator--() {if (--v == -1) v = m - 1; return *this;}
	t operator+(const t& r) const {return t(*this) += r;}
	t operator-(const t& r) const {return t(*this) -= r;}
	t operator*(const t& r) const {return t(*this) *= r;}
	t operator/(const t& r) const {return t(*this) /= r;}
	t operator++(int) {t u = v; operator++(); return u;}
	t operator--(int) {t u = v; operator--(); return u;}
	bool operator==(const t& r) const {return v == r.v;}
	bool operator!=(const t& r) const {return v != r.v;}
	bool operator<(const t& r) const {return v < r.v;}
	bool operator>(const t& r) const {return v > r.v;}
	bool operator<=(const t& r) const {return v <= r.v;}
	bool operator>=(const t& r) const {return v >= r.v;}
};
template<class T>
constexpr T inv(T x, T y) {
	T Y = y, a = 1, b = 0, d = 0;
	while (x) d = y / x, y -= d * x, b -= d * a, swap(x, y), swap(a, b);
	assert(y == 1); return b + Y;
}
template<class T, class T2>
struct lazy_mont {
	const T n, n2, ni, r2, r3;
	constexpr T redc(T2 x) const {
		return T(x) * ni * T2(n) + x >> 8 * sizeof(T);
	}
	constexpr lazy_mont(T n) : n(n), n2(n * 2), r2(T2(-1) % n + 1), ni([n]() {
		T r = -n; while (n * r + 1) r *= 2 + n * r; return r;}()),
		r3(mul(r2, r2)) {assert(n & 1 && n <= numeric_limits<T>::max() / 4);}
	T mul(const T &x, const T &y) const {return redc(T2(x) * y);}
	T operator()(const T &x) const {return mul(x, r2);}
	T get(T x) const {x = redc(x); return x - n * (x >= n);}
	T add(const T &x, T y) const {y = x + y; return y < x ? y - n2 : y;}
	T neg(const T &x) const {return n2 - x;}
	T sub(const T &x, T y) const {y = x - y; return y < x ? y : y + n2;}
	T inv(const T &x) const {return mul(inv(x), r3);}
	bool neq(const T &x, const T &y) const {
		return x - y && x + n - y && y + n - x;
	}
	bool eq(const T &x, const T &y) const {return !neq(x, y);}
};
using lm32 = lazy_mont<u32, u64>;
using lm64 = lazy_mont<u64, u128>;
bool mr32(const lm32 &lm, u32 a) {
	if (!(a %= lm.n)) return 1;
    a = lm(a); u8 r = __builtin_ctz(lm.n - 1); u32 d = lm.n >> r, p = lm(1);
	for (; d; d >>= 1, a = lm.mul(a, a)) if (d & 1) p = lm.mul(p, a);
	if (lm.eq(p, lm(1))) return 1;
	while (lm.neq(p, lm(lm.n - 1)) && --r) p = lm.mul(p, p);
	return lm.eq(p, lm(lm.n - 1));
}
bool mr64(const lm64 &lm, u64 a) {
	if (!(a %= lm.n)) return 1;
    a = lm(a); u8 r = __builtin_ctzll(lm.n - 1); u64 d = lm.n >> r, p = lm(1);
	for (; d; d >>= 1, a = lm.mul(a, a)) if (d & 1) p = lm.mul(p, a);
	if (lm.eq(p, lm(1))) return 1;
	while (lm.neq(p, lm(lm.n - 1)) && --r) p = lm.mul(p, p);
	return lm.eq(p, lm(lm.n - 1));
}
// deterministic miller rabin
// bases obtained from
// https://miller-rabin.appspot.com/
bool dmr32(const lm32 &lm) {
	if (lm.n > 316349280) return mr32(lm, 2) && mr32(lm, 7) && mr32(lm, 61);
	if (lm.n > 49140) return mr32(lm, 11000544) && mr32(lm, 31481107);
	return mr32(lm, 921211727);
}
bool dmr64(const lm64 &lm) {
	if (lm.n > 585226005592931976) return mr64(lm, 2) && mr64(lm, 325) &&
		mr64(lm, 9375) && mr64(lm, 28178) && mr64(lm, 450775) &&
		mr64(lm, 9780504) && mr64(lm, 1795265022);
	if (lm.n > 7999252175582850) return mr64(lm, 2) &&
		mr64(lm, 123635709730000) && mr64(lm, 9233062284813009) &&
		mr64(lm, 43835965440333360) && mr64(lm, 761179012939631437) &&
		mr64(lm, 1263739024124850375);
	if (lm.n > 55245642489450) return mr64(lm, 2) && mr64(lm, 4130806001517) &&
		mr64(lm, 149795463772692060) && mr64(lm, 186635894390467037) &&
		mr64(lm, 3967304179347715805);
	if (lm.n > 350269456336) return mr64(lm, 2) && mr64(lm, 141889084524735) &&
		mr64(lm, 1199124725622454117) && mr64(lm, 11096072698276303650u);
	if (lm.n > 0x3FFFFFFF) return mr64(lm, 4230279247111683200) &&
		mr64(lm, 14694767155120705706u) && mr64(lm, 16641139526367750375u);
	return dmr32(lm.n);
}
bool is_prime(u64 n) {
	for (u8 i : {2, 3, 5, 7}) {if (n % i == 0) return n == i;}
	return n < 121 ? n > 2 : dmr64(n);
}
vector<u64> factorise(u64 n) {
	/*
		factorises integers 1 <= n <= 2^62
		bad cases: all prime factors are large
		very bad cases:
			1e18: 999995891929828291, 3 times worse than other bad cases
			2^62: 4611653436861561323, 7 times worse than other bad cases
			    = 0x3fffe25e0357b9eb
	*/
	vector<u64> pf;
	for (u8 i : {2, 3, 5}) while (!(n % i)) pf.push_back(i), n /= i;
	for (u16 i = 7; i * i <= n && i <= 211; i += 6) for (u16 j : {0, 4})
		while (n % (i + j) == 0) pf.push_back(i + j), n /= i + j;
	if (n == 1) return pf;
	vector<u64> q{n};
	while (!q.empty()) {
		n = q.back(); q.pop_back();
		if (n < 49729) {pf.push_back(n); continue;}
		u64 r = sqrt(n) + 0.5;
		if (r * r == n) {q.resize(q.size() + 2, r); continue;}
		lm64 lm(n);
		if (dmr64(lm)) {pf.push_back(n); continue;}
		u64 g = n, ni = lm.ni;
		auto f = [lm](u64 x) {return lm.redc(u128(x) * x + 1);};
		const u64 m = 1 << (51 - __builtin_clzll(n) >> 2);
		for (u64 x0 = 0; g == n; ++x0) {
			u64 x, y = x0, q = g = 1, ys;
			for (u64 r = 1; g == 1; r <<= 1) {
				x = y;
				for (u64 _ = r; _--;) y = f(y);
				for (u64 k = 0; k < r && g == 1; k += m) {
					ys = y;
					for (u64 _ = min(m, r - k); _--;)
						y = f(y), q = lm.mul(max(x, y) - min(x, y), q);
					g = gcd(q, n);
				}
			}
			if (g == n) for (g = 1; g == 1;)
				ys = f(ys), g = gcd(max(x, ys) - min(x, ys), n);
		}
		q.push_back(g); q.push_back(n / g);
	}
	sort(bend(pf));
	return pf;
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ LIBRARY ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv MAIN vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
void solve() {
	u64 n; readu(n);
	auto prime_factors = factorise(n);
	printf("%u", prime_factors.size());
	for (u64 i : prime_factors) printf(" %llu", i);
	printf("\n");
}
int main() {
	u32 t = 1;
	readu(t);
	static const bool PRINT_T = 0;
	u64 st, et, gst, get;
	if (PRINT_T) gst = gt();
	while (t--) {
		if (PRINT_T) st = gt();
		solve();
		if (PRINT_T) et = gt(), printf("time: %.6lfs\n", (et - st) * gtp);
	}
	if (PRINT_T) get = gt(), printf("total time: %.6lfs\n", (get - gst) * gtp);
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ MAIN ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
