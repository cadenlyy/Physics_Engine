#pragma once
template <typename T>
class matrix2 {
private:
	int index(int row, int col);
	T* matrixData;
	int nRows, nCols, nElements;
public:
	//constructors
	matrix2();
	matrix2(int nRow, int nCol);
	matrix2(int nRow, int nCol, const T* data);
	matrix2(const matrix2<T>& inputMatrix);

	//destructor
	~matrix2();

	//config
	void resize(int nRow, int nCol);

	//element access
	T get(int row, int col);
	void set(int row, int col, T value);
	int nRows();
	int nCols();

	//overloads
	bool operator== (const matrix2<T>& rhs);

	template <class U> friend matrix2<U> operator+ (const matrix2<U>& lhs, const matrix2<U>& rhs); //matrix, matrix
	template <class U> friend matrix2<U> operator+ (const U& lhs, const matrix2<U>& rhs); //scalar, matrix
	template <class U> friend matrix2<U> operator+ (const matrix2<U>& lhs, const U& rhs); //matrix, scalar

	template <class U> friend matrix2<U> operator- (const matrix2<U>& lhs, const matrix2<U>& rhs); //matrix, matrix
	template <class U> friend matrix2<U> operator- (const U& lhs, const matrix2<U>& rhs); //scalar, matrix
	template <class U> friend matrix2<U> operator- (const matrix2<U>& lhs, const U& rhs); //matrix, scalar

	template <class U> friend matrix2<U> operator* (const matrix2<U>& lhs, const matrix2<U>& rhs); //matrix, matrix
	template <class U> friend matrix2<U> operator* (const U& lhs, const matrix2<U>& rhs); //scalar, matrix
	template <class U> friend matrix2<U> operator* (const matrix2<U>& lhs, const U& rhs); //matrix, scalar

};

//functions
template<typename T>
inline matrix2<T>::matrix2(){ //default constructor
	nRows = 1;
	nCols = 1;
	nElements = 1;
	matrixData = new T[nElements];
	matrixData[0] = 0.0;
}

template<typename T>
inline matrix2<T>::matrix2(int nRow, int nCol){
	nRows = nRow;
	nCols = nCol;
	nElements = nRow * nCol;
	matrixData = new T[nElements];
	for (int i = 0; i < nElements; i++) matrixData[i] = 0.0;
}

//const from linear array
template<typename T>
inline matrix2<T>::matrix2(int nRow, int nCol, const T* data){
	nRows = nRow;
	nCols = nCol;
	nElements = nRow * nCol;
	matrixData = new T[nElements];
	for (int i = 0; i < nElements; i++) matrixData[i] = data[i];
}

//copy constructor
template<typename T>
inline matrix2<T>::matrix2(const matrix2<T>& inputMatrix){
	nRows = nRow;
	nCols = nCol;
	nElements = nRow * nCol;
	matrixData = new T[nElements];
	for (int i = 0; i < nElements; i++) matrixData[i] = inputMatrix.matrixData[i];
}

//destructor
template<typename T>
inline matrix2<T>::~matrix2() {
	if matrixData != nullptr{
		delete[] matrixData;
	}
}

//config functions
template<typename T>
inline void matrix2<T>::resize(int nRow, int nCol){
	nRows = nRow;
	nCols = nCol;
	matrixData = new T[nElements];
	for (int i = 0;i < nElements; i++) {
		matrixData[i] = 0.0;
	}
}

//element functions
template<typename T>
inline T matrix2<T>::get(int row, int col){
	linearIndex = index(row, col);
	return matrixData[linearIndex];
}

template<typename T>
inline void matrix2<T>::set(int row, int col, T value){
	linearIndex = index(row, col);
	matrixData[linearIndex] = value;
}

template<typename T>
inline int matrix2<T>::nRows(){
	return nRows;
}

template<typename T>
inline int matrix2<T>::nCols(){
	return nCols;
}

template<typename T>
inline int matrix2<T>::index(int row, int col){
	if ((row < nRows && row >= 0) && (col < nCols && col >= 0)) 
		return (row * nCols) + col;
	else return -1;
}

template<typename T>
inline bool matrix2<T>::operator==(const matrix2<T>& M)
{
	return false;
}

template<class U>
inline matrix2<U> operator+(const matrix2<U>& lhs, const matrix2<U>& rhs){
	T* temp = new T[lhs.nElements];
	for (int i = 0; i < lhs.nElements; i++){
		temp[i] = lhs.matrixData[i] + rhs.matrixData[i];
	}
	matrix2<U> result(lhs.nRows, lhs.nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator+(const U& lhs, const matrix2<U>& rhs){
	T* temp = new T[rhs.nElements];
	for (int i = 0; i < rhs.nElements; i++) {
		temp[i] = lhs + rhs.matrixData[i];
	}
	matrix2<U> result(rhs.nRows, rhs.nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator+(const matrix2<U>& lhs, const U& rhs){
	T* temp = new T[lhs.nElements];
	for (int i = 0; i < lhs.nElements; i++) {
		temp[i] = lhs.matrixData[i] + rhs;
	}
	matrix2<U> result(lhs.nRows, lhs.nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator-(const matrix2<U>& lhs, const matrix2<U>& rhs){
	T* temp = new T[lhs.nElements];
	for (int i = 0; i < lhs.nElements; i++) {
		temp[i] = lhs.matrixData[i] - rhs.matrixData[i];
	}
	matrix2<U> result(lhs.nRows, lhs.nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator-(const U& lhs, const matrix2<U>& rhs){
	T* temp = new T[rhs.nElements];
	for (int i = 0; i < rhs.nElements; i++) {
		temp[i] = lhs - rhs.matrixData[i];
	}
	matrix2<U> result(rhs.nRows, rhs.nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator-(const matrix2<U>& lhs, const U& rhs){
	T* temp = new T[lhs.nElements];
	for (int i = 0; i < lhs.nElements; i++) {
		temp[i] = lhs.matrixData[i] - rhs;
	}
	matrix2<U> result(lhs.nRows, lhs.nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator*(const matrix2<U>& lhs, const matrix2<U>& rhs)
{
	return matrix2<U>();
}

template<class U>
inline matrix2<U> operator*(const U& lhs, const matrix2<U>& rhs)
{
	return matrix2<U>();
}

template<class U>
inline matrix2<U> operator*(const matrix2<U>& lhs, const U& rhs)
{
	return matrix2<U>();
}
