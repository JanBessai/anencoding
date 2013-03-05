#ifndef __ENCODED_H__
#define __ENCODED_H__

template <class T>
class Encoded {
 public:
  typedef T EncodedType;
};

template <class T>
T decode(typename Encoded<T>::EncodedType value) {
  return (T)value;
}

template <class T> class Protected;

template <class T>
Protected<T> protect(const T &value) {
  return Protected<T>(value);
}

template <class T>
class Protected {
  friend Protected<T> protect<T>(const T&);
  Protected(const typename Encoded<T>::EncodedType &value) : value(value) {}
 public:
  typedef typename Encoded<T>::EncodedType EncodedType;
  EncodedType value;
  Protected(const Protected<T> &other) : value(other.value) {}

  operator T() {
    return (T)value;
  }

  Protected<T> operator+(const Protected<T> &y) const {
    Protected<T> result(*this);
    result.value += y.value;
    return result;
  }

  Protected<T> operator-(const Protected<T> &y) const {
    Protected<T> result(*this);
    result.value -= y.value;
    return result;
  }

  Protected<T> operator*(const Protected<T> &y) const {
    Protected<T> result(*this);
    result.value *= y.value;
    return result;
  }

  Protected<T> operator/(const Protected<T> &y) const {
    Protected<T> result(*this);
    result.value /= y.value;
    return result;
  }

  Protected<T> operator%(const Protected<T> &y) const {
    Protected<T> result(*this);
    result.value %= y.value;
    return result;
  }

  Protected<bool> operator<=(const Protected<T> &other) const {
    Protected<bool> result = protect<bool>(value <= other.value);
    return result;
  }

  Protected<T> operator!() const {
    Protected<T> result(*this);
    result.value = !result.value;
    return result;
  }

  Protected<T> operator&&(const Protected<T> &other) const {
    Protected<T> result(*this);
    result.value = value && other.value;
    return result;
  }

  Protected<T> operator||(const Protected<T> &other) const {
    Protected<T> result(*this);
    result.value = value || other.value;
    return result;
  }

  Protected<T> operator^(const Protected<T> &other) const {
    Protected<T> result(*this);
    result.value = value ^ other.value;
    return result;
  }

  Protected<T> operator|(const Protected<T> &other) const {
    Protected<T> result(*this);
    result.value = value | other.value;
    return result;
  }

  Protected<T> operator&(const Protected<T> &other) const {
    Protected<T> result(*this);
    result.value = value & other.value;
    return result;
  }

 Protected<T> operator~() const {
    Protected<T> result(*this);
    result.value = ~value;
    return result;
  }

  // Other operators just dispatch
  Protected<T> &operator+=(const Protected<T> &other) {
    Protected<T> result = (*this) + other;
    value = result.value;
    return *this;
  }

  Protected<T> &operator-=(const Protected<T> &other) {
    Protected<T> result = (*this) - other;
    value = result.value;
    return *this;
  }

  Protected<T> &operator*=(const Protected<T> &other) {
    Protected<T> result = (*this) * other;
    value = result.value;
    return *this;
  }

  Protected<T> &operator/=(const Protected<T> &other) {
    Protected<T> result = (*this) / other;
    value = result.value;
    return *this;
  }

  Protected<T> &operator%=(const Protected<T> &other) {
    Protected<T> result = (*this) % other;
    value = result.value;
    return *this;
  }

  Protected<T> &operator&=(const Protected<T> &other) {
    Protected<T> result = (*this) & other;
    value = result.value;
    return *this;
  }

  Protected<T> &operator|=(const Protected<T> &other) {
    Protected<T> result = (*this) | other;
    value = result.value;
    return *this;
  }

 Protected<T> &operator^=(const Protected<T> &other) {
    Protected<T> result = (*this) ^ other;
    value = result.value;
    return *this;
  }

  Protected<T> &operator++() {
    Protected<T> result = (*this) + Protected<T>(1);
    value = result.value;
    return *this;
  }

  Protected<T> operator++(int) {
    Protected<T> result(*this);
    Protected<T> added = (*this) + Protected<T>(1);
    value = added.value;
    return result;
  }

  Protected<T> &operator--() {
    Protected<T> result = (*this) - Protected<T>(1);
    value = result.value;
    return *this;
  }

  Protected<T> operator--(int) {
    Protected<T> result(*this);
    Protected<T> added = (*this) - Protected<T>(1);
    value = added.value;
    return result;
  }

  Protected<T> operator+() const {
    return Protected<T>(0) + *this;
  }

  Protected<T> operator-() const {
    return Protected<T>(0) - *this;
  }

  Protected<bool> operator==(const Protected<T> &other) const {
    return (*this <= other) && (other <= *this);
  }

  Protected<bool> operator!=(const Protected<T> &other) const {
    return !(*this == other);
  }

  Protected<bool> operator>=(const Protected<T> &other) const {
    return other <= this;
  }

  Protected<bool> operator<(const Protected<T> &other) const {
    return (*this <= other) && !(other <= *this);
  }

  Protected<bool> operator>(const Protected<T> &other) const {
    return (other <= *this) && !(other >= *this);
  }



};

#endif


