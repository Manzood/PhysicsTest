#include <SFML/Graphics.hpp>

#include "bits/stdc++.h"
using namespace std;

vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while (!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) \
    debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__);

// I'll clean this up sometime later, it works for now

// C++ template to print vector container elements
// template <typename T>
// ostream& operator<<(ostream& os, const vector<T>& v)
//{
//    os << "[";
//    for (int i = 0; i < v.size(); ++i) {
//        os << v[i];
//        if (i != v.size() - 1)
//            os << ", ";
//    }
//    os << "]\n";
//    return os;
//}

// appears to work for 2D vectors too, so I'll use it
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    out << "[";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        // debug(i);
        out << v[i];
        if (i != last) out << ", ";
    }
    out << "]";
    return out;
}

// C++ template to print set container elements
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
    os << "[";
    for (auto it : v) {
        os << it;
        if (it != *v.rbegin()) os << ", ";
    }
    os << "]";
    return os;
}

// C++ template to print map container elements
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v) {
    for (auto it : v) {
        os << it.first << " : " << it.second << "\n";
    }

    return os;
}

// C++ template to print pair<>
// class by using template
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v) {
    os << "(";
    os << v.first << ", " << v.second << ")";
    return os;
}

// C++ template to print vector2f<>
// class by using template
ostream &operator<<(ostream &os, const sf::Vector2f &v) {
    os << "(";
    os << v.x << ", " << v.y << ")";
    return os;
}
