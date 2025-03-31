#pragma once

template<typename T> requires std::is_arithmetic_v<T>
class complex_number
{
	T t_re, t_im;
	
public:
	complex_number()
		:t_re(0), t_im(0)
		{}
		
	explicit complex_number(T n)
		:t_re(n), t_im(0)
		{}
		
	complex_number(T r, T i)
		: t_re(r), t_im(i)
		{}
		
	
	T re(void) const {
		return t_re;
	}
	
	T im(void) const {
		return t_im;
	}
	
	complex_number conj(void) const {
		return complex_number<T>(t_re, -t_im);
	}
	
	complex_number& operator+=(const complex_number& other) {
		T a = t_re;
		T b = t_im;
		T c = other.t_re;
		T d = other.t_im;
		t_re = a+c;
		t_im = b+d;
		return *this;
	}
	
	complex_number& operator*=(const complex_number& other) {
		T a = t_re;
		T b = t_im;
		T c = other.t_re;
		T d = other.t_im;
		t_re = a*c-b*d;
		t_im = a*d+b*c;
		return *this;
	}
	
	complex_number operator+(const T& other) {
		return complex_number(t_re + other, t_im);
	}
	
	complex_number operator-(const T& other) {
		return complex_number(t_re - other,t_im);
	}
	
	complex_number operator*(const complex_number& other) const {
    return complex_number(
        t_re * other.t_re - t_im * other.t_im,
        t_re * other.t_im + t_im * other.t_re);
    }
	
	complex_number operator*(const T& other) {
    return complex_number(t_re * other, t_im * other);
	}
	
	complex_number operator+(const complex_number& other) {
		return complex_number(t_re + other.t_re, t_im + other.t_im);
	}
	
	complex_number operator-(const complex_number& other) {
		return complex_number(t_re - other.t_re, t_im - other.t_im);
	}

	
};

template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& t) {
	if (t.im() <= 0)
		if (t.im()==0)
			os << t.re() ;
		else if (t.re() == 0)
			os << "-i" << -t.im();
		else 
			os << t.re() << "-i" << -t.im();
	else
		if (t.re()==0)
			os << "i" << t.im();
		else
			os << t.re() << "+i" << t.im();
	return os;
}

//somma e moltiplicazione tra reale e complesso
template<typename T>
complex_number<T> operator+(const T& lhs, const complex_number<T>& rhs) {
    return complex_number<T>(lhs + rhs.re(), rhs.im());
}


template<typename T>
complex_number<T> operator*(const T& lhs, const complex_number<T>& rhs) {
    return complex_number<T>(lhs * rhs.re(), lhs * rhs.im());
}
