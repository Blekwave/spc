#include <iostream>
#include <memory>

template<class T>
class MatrixWrapper {
    size_t _r, _c;
    std::unique_ptr<T []> _m;

public:
    MatrixWrapper(size_t r, size_t c) : _r(r), _c(c), _m(new T[r * c]) {  }

    inline size_t rows() {
        return _r;
    }

    inline size_t cols() {
        return _c;
    }

    inline T &at(size_t i, size_t j) {
        return _m[i * _c + j];
    }
};

struct MatrixElem {
    char letter;
    bool visited;

    MatrixElem() : visited(false) { }
};

typedef MatrixWrapper<MatrixElem> Matrix;

bool dfs(Matrix &m, size_t r, size_t c, const char *np);

bool callDfs(Matrix &m, size_t r, size_t c, const char *p) {
    if(m.at(r, c).visited)
        return false;
    if(m.at(r, c).letter != *p)
        return false;

    m.at(r, c).visited = true;
    bool res = dfs(m, r, c, p+1);
    m.at(r, c).visited = false;

    if(res)
        return true;

    return false;
}

bool dfs(Matrix &m, size_t r, size_t c, const char *np) {
    if(!*np)
        return true;

    if(r && c)
        if(callDfs(m, r-1, c-1, np))
            return true;
    if(r)
        if(callDfs(m, r-1, c, np))
            return true;
    if(r && c+1 < m.cols())
        if(callDfs(m, r-1, c+1, np))
            return true;
    if(c)
        if(callDfs(m, r, c-1, np))
            return true;
    if(c+1 < m.cols())
        if(callDfs(m, r, c+1, np))
            return true;
    if(r+1 < m.rows() && c)
        if(callDfs(m, r+1, c-1, np))
            return true;
    if(r+1 < m.rows())
        if(callDfs(m, r+1, c, np))
            return true;
    if(r+1 < m.rows() && c+1 < m.cols())
        if(callDfs(m, r+1, c+1, np))
            return true;

    return false;
}

bool hasText(Matrix &m, const char *text) {
    for(size_t i = 0; i < m.rows(); ++i) {
        for(size_t j = 0; j < m.cols(); ++j) {
            if(callDfs(m, i, j, text))
                return true;
        }
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int t, r, c;

    std::cin >> t;
    while(t--) {
        std::cin >> r >> c;
        Matrix m(r, c);

        for(size_t i = 0; i < m.rows(); ++i)
            for(size_t j = 0; j < m.cols(); ++j)
                std::cin >> m.at(i, j).letter;

        std::cout << (hasText(m, "ALLIZZWELL") ? "YES" : "NO") << "\n";
    }

    return 0;
}
