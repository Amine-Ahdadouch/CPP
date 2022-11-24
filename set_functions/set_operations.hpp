#include <set>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    for (auto& element : s) {
        os << element << " ";
    }
    return os;
}

template <typename T>
std::set<T> operator+(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    for (auto& element : s1) {
        result.insert(element);
    }
    for (auto& element : s2) {
        result.insert(element);
    }
    return result;
}

template <typename T>
std::set<T> operator-(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    for (auto& element : s1) {
        if (s2.find(element) == s2.end()) {
            result.insert(element);
        }
    }
    return result;
}

template <typename T>
std::set<T> operator^(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    for (auto& element : s1) {
        if (s2.find(element) == s2.end()) {
            result.insert(element);
        }
    }
    for (auto& element : s2) {
        if (s1.find(element) == s1.end()) {
            result.insert(element);
        }
    }
    return result;
}

template <typename T>
std::set<T> operator*(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    for (auto& element1 : s1) {
        for (auto& element2 : s2) {
            result.insert(element1 + element2);
        }
    }
    return result;
}

template <typename T>
std::set<T> operator^(const std::set<T>& s, int n) {
    std::set<T> result;
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }
    if (n == 0) {
        result.insert(T());
    }
    else {
        for (auto& element : s) {
            std::set<T> temp = s ^ (n - 1);
            for (auto& element2 : temp) {
                result.insert(element + element2);
            }
        }
    }
    return result;
}