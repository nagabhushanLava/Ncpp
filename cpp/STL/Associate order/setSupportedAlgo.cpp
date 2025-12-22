// Demonstrates common operations supported by std::set and the classic
// <algorithm> "set algorithms" that work on sorted ranges.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <typename T>
static void print_set(const std::set<T>& s, const std::string& label)
{
    cout << label << ": { ";
    for (const auto& x : s) cout << x << ' ';
    cout << "}\n";
}

template <typename It>
static void print_range(It first, It last, const std::string& label)
{
    cout << label << ": [ ";
    for (; first != last; ++first) cout << *first << ' ';
    cout << "]\n";
}

int main()
{
    // -------- 1) std::set member operations --------
    // sorted + unique
    std::set<int> s{12, 13, 14, 0, 13, 14, 32, 1, 15, 16, 17, 18, 19};
    print_set(s, "s initial");

    // insert
    s.insert(45);
    s.insert(13); // duplicate
    print_set(s, "s after insert(45) and insert(13)");

    // erase by key
    s.erase(19);
    print_set(s, "s after erase(19)");

    // find / count
    cout << "count(13)=" << s.count(13) << " count(999)=" << s.count(999) << "\n";
    if (auto it = s.find(32); it != s.end()) {
        cout << "found 32\n";
    }

    // next / advance (iterator movement)
    if (s.size() >= 5) {
        auto it = next(s.begin(), 4);
        cout << "next(begin,4)=" << *it << "\n";
    }

    // lower_bound / upper_bound / equal_range
    auto lb = s.lower_bound(14); // first element >= 14
    auto ub = s.upper_bound(14); // first element > 14
    if (lb != s.end()) cout << "lower_bound(14)=" << *lb << "\n";
    if (ub != s.end()) cout << "upper_bound(14)=" << *ub << "\n";

    auto [eq1, eq2] = s.equal_range(14);
    print_range(eq1, eq2, "equal_range(14)");

    cout << "\n";

    // -------- 2) std::set with custom comparator (descending) --------
    std::set<int, std::greater<int>> desc{12, 13, 14, 0, 32, 1, 45};
    cout << "descending set: ";
    for (int x : desc) cout << x << ' ';
    cout << "\n\n";

    // -------- 3) <algorithm> 'set algorithms' --------
    // These require sorted input ranges. std::set iterators are always sorted.
    std::set<int> a{1, 2, 3, 5, 7};
    std::set<int> b{2, 3, 4, 6, 7, 8};
    print_set(a, "a");
    print_set(b, "b");

    std::vector<int> out;

    out.clear();
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(out));
    print_range(out.begin(), out.end(), "set_union(a,b)");

    out.clear();
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(out));
    print_range(out.begin(), out.end(), "set_intersection(a,b)");

    out.clear();
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(out));
    print_range(out.begin(), out.end(), "set_difference(a-b)");

    out.clear();
    std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(out));
    print_range(out.begin(), out.end(), "set_symmetric_difference(a,b)");

    cout << "includes(a,b)="
         << std::includes(a.begin(), a.end(), b.begin(), b.end())
         << " (is b subset of a?)\n\n";

    // -------- 4) merge (C++17) --------
    std::set<int> m1{1, 2, 3};
    std::set<int> m2{3, 4, 5};
    m1.merge(m2);
    print_set(m1, "m1 after merge(m2)");
    print_set(m2, "m2 after merge (keeps elements that couldn't move)");

    return 0;
}