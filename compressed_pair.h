#pragma once

#include <type_traits>
#include <utility>

template <typename T, char t = 'f', bool = std::is_empty_v<T> && !std::is_final_v<T>>
struct OptimizedElement {
    OptimizedElement() = default;
    OptimizedElement(const T& val) : value(val){};
    OptimizedElement(T&& val) : value(std::move(val)){};
    const T& Get() const {
        return value;
    }
    T& Get() {
        return value;
    }
    T value{};
};

template <typename T, char t>
struct OptimizedElement<T, t, true> : public T {
    OptimizedElement() = default;
    OptimizedElement(const T& val) : T(val){};
    OptimizedElement(T&& val) : T(std::move(val)){};
    const T& Get() const {
        return *this;
    }
    T& Get() {
        return *this;
    }
};

template <typename F, typename S>
class CompressedPair : private OptimizedElement<F>, private OptimizedElement<S, 's'> {
public:
    CompressedPair() = default;
    CompressedPair(const F& first, const S& second) : OptimizedElement<F>(first), OptimizedElement<S, 's'>(second){};
    CompressedPair(F&& first, const S& second) : OptimizedElement<F>(std::move(first)), OptimizedElement<S, 's'>(second){};
    CompressedPair(const F& first, S&& second) : OptimizedElement<F>(first), OptimizedElement<S, 's'>(std::move(second)){};
    CompressedPair(F&& first, S&& second) : OptimizedElement<F>(std::move(first)), OptimizedElement<S, 's'>(std::move(second)){};
    F& GetFirst() {
        return OptimizedElement<F>::Get();
    }
    const F& GetFirst() const {
        return OptimizedElement<F>::Get();
    }
    S& GetSecond() {
        return OptimizedElement<S, 's'>::Get();
    };
    const S& GetSecond() const {
        return OptimizedElement<S, 's'>::Get();
    };
};