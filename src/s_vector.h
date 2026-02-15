#pragma once
#include<string>
#include<mutex>
#include<vector>

template <typename T>
class s_vector{
private:
	mutable std::mutex mt;
	std::vector<T>v;
public:
	s_vector();
	s_vector(s_vector& cv);
	void s_push_back(T a);
	void s_pop_back();
	T s_front();
	T s_back();
	std::vector<T> s_get();
	void s_equ(std::vector<T> ev);
	int s_size();
};

template<typename T>
inline s_vector<T>::s_vector() {
}

template<typename T>
inline s_vector<T>::s_vector(s_vector<T>& cv) {
	std::lock_guard<std::mutex> lock(cv);
	v = cv.v;
}

template<typename T>
inline void s_vector<T>::s_push_back(T a) {
	std::lock_guard<std::mutex> lock(mt);
	v.push_back(a);
}

template<typename T>
inline void s_vector<T>::s_pop_back() {
	std::lock_guard<std::mutex> lock(mt);
	v.pop_back();
}

template<typename T>
inline T s_vector<T>::s_front() {
	std::lock_guard<std::mutex> lock(mt);
	return v.front();
}

template<typename T>
inline T s_vector<T>::s_back() {
	std::lock_guard<std::mutex> lock(mt);
	return v.back();
}

template<typename T>
inline std::vector<T> s_vector<T>::s_get() {
	std::lock_guard<std::mutex> lock(mt);
	std::vector<T> vs = v;
	return vs;
}

template<typename T>
inline void s_vector<T>::s_equ(std::vector<T> ev) {
	std::lock_guard<std::mutex> lock(mt);
	v = {};
	for (auto i : ev) v.push_back(i);
}

template<typename T>
inline int s_vector<T>::s_size()
{
	return v.size();
}

