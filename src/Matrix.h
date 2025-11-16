#pragma once
template <typename T>
class matrix2 {
private:
	int index(int row, int col);
	T* matrixData;
	int m_nRows, m_nCols, m_nElements;
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
	template <class U> friend matrix2<U> transpose(const matrix2<U>& inputMatrix);

	//element access
	T get(int row, int col);
	void set(int row, int col, T value);
	int getRows();
	int getCols();

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
	m_nRows = 1;
	m_nCols = 1;
	m_nElements = 1;
	matrixData = new T[m_nElements];
	matrixData[0] = 0.0;
}

template<typename T>
inline matrix2<T>::matrix2(int nRow, int nCol){
	m_nRows = nRow;
	m_nCols = nCol;
	m_nElements = nRow * nCol;
	matrixData = new T[m_nElements];
	for (int i = 0; i < m_nElements; i++) matrixData[i] = 0.0;
}

//const from linear array
template<typename T>
inline matrix2<T>::matrix2(int nRow, int nCol, const T* data){
	m_nRows = nRow;
	m_nCols = nCol;
	m_nElements = nRow * nCol;
	matrixData = new T[m_nElements];
	for (int i = 0; i < m_nElements; i++) matrixData[i] = data[i];
}

//copy constructor
template<typename T>
inline matrix2<T>::matrix2(const matrix2<T>& inputMatrix){
	m_nRows = inputMatrix.m_nRows;
	m_nCols = inputMatrix.m_nCols;
	m_nElements = m_nRows * m_nCols;
	matrixData = new T[m_nElements];
	for (int i = 0; i < m_nElements; i++) matrixData[i] = inputMatrix.matrixData[i];
}

//destructor
template<typename T>
inline matrix2<T>::~matrix2() {
	if (matrixData != nullptr){
		delete[] matrixData;
	}
}

//config functions
template<typename T>
inline void matrix2<T>::resize(int nRow, int nCol){
	m_nRows = nRow;
	m_nCols = nCol;
	m_nElements = nRow * nCol;
	matrixData = new T[m_nElements];
	for (int i = 0;i < m_nElements; i++) {
		matrixData[i] = 0.0;
	}
}

template<class U>
inline matrix2<U> transpose(const matrix2<U>& inputMatrix){
	U* temp = new U[inputMatrix.m_nElements];
	for (int i = 0; i < inputMatrix.m_nRows; i++) {
		for (int j = 0; j < inputMatrix.m_nCols; j++) {
			temp[(j * inputMatrix.m_nRows) + i] = inputMatrix.matrixData[(i * inputMatrix.m_nCols) + j];
		}
	}
	matrix2<U> result(inputMatrix.m_nCols, inputMatrix.m_nRows, temp);
	delete[] temp;
	return result;
}

//element functions
template<typename T>
inline T matrix2<T>::get(int row, int col){
	int linearIndex = index(row, col);
	return matrixData[linearIndex];
}

template<typename T>
inline void matrix2<T>::set(int row, int col, T value){
	int linearIndex = index(row, col);
	matrixData[linearIndex] = value;
}

template<typename T>
inline int matrix2<T>::getRows(){
	return m_nRows;
}

template<typename T>
inline int matrix2<T>::getCols(){
	return m_nCols;
}

template<typename T>
inline int matrix2<T>::index(int row, int col){
	if ((row < m_nRows && row >= 0) && (col < m_nCols && col >= 0))
		return (row * m_nCols) + col;
	else return -1;
}

template<typename T>
inline bool matrix2<T>::operator==(const matrix2<T>& M){
	if ((this->m_nRows != M.m_nRows) || (this->m_nCols != M.m_nCols)) {
		return false;
	}
	for (int i = 0; i < this->m_nElements; i++) {
		if (this->matrixData[i] != M.matrixData[i]) return false;
	}
	return true;
}

template<class U>
inline matrix2<U> operator+(const matrix2<U>& lhs, const matrix2<U>& rhs){
	U* temp = new U[lhs.m_nElements];
	for (int i = 0; i < lhs.m_nElements; i++){
		temp[i] = lhs.matrixData[i] + rhs.matrixData[i];
	}
	matrix2<U> result(lhs.m_nRows, lhs.m_nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator+(const U& lhs, const matrix2<U>& rhs){
	U* temp = new U[rhs.m_nElements];
	for (int i = 0; i < rhs.m_nElements; i++) {
		temp[i] = lhs + rhs.matrixData[i];
	}
	matrix2<U> result(rhs.m_nRows, rhs.m_nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator+(const matrix2<U>& lhs, const U& rhs){
	U* temp = new U[lhs.m_nElements];
	for (int i = 0; i < lhs.m_nElements; i++) {
		temp[i] = lhs.matrixData[i] + rhs;
	}
	matrix2<U> result(lhs.m_nRows, lhs.m_nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator-(const matrix2<U>& lhs, const matrix2<U>& rhs){
	U* temp = new U[lhs.m_nElements];
	for (int i = 0; i < lhs.m_nElements; i++) {
		temp[i] = lhs.matrixData[i] - rhs.matrixData[i];
	}
	matrix2<U> result(lhs.m_nRows, lhs.m_nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator-(const U& lhs, const matrix2<U>& rhs){
	U* temp = new U[rhs.m_nElements];
	for (int i = 0; i < rhs.m_nElements; i++) {
		temp[i] = lhs - rhs.m_matrixData[i];
	}
	matrix2<U> result(rhs.m_nRows, rhs.m_nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator-(const matrix2<U>& lhs, const U& rhs){
	U* temp = new U[lhs.m_nElements];
	for (int i = 0; i < lhs.m_nElements; i++) {
		temp[i] = lhs.matrixData[i] - rhs;
	}
	matrix2<U> result(lhs.m_nRows, lhs.m_nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator*(const matrix2<U>& lhs, const matrix2<U>& rhs){
	int lhsRows = lhs.m_nRows;
	int lhsCols = lhs.m_nCols;
	int rhsRows = rhs.m_nRows;
	int rhsCols = rhs.m_nCols;
	U* temp = new U[lhs.m_nElements];
	for (int i = 0; i < lhsRows; i++) {
		for (int j = 0; j < rhsCols; j++) {
			U element = 0.0;
			for (int k = 0; k < lhsCols; k++) {
				//std::cout << lhs.matrixData[(i * lhsCols) + k] * rhs.matrixData[(k * rhsCols) + j];
				element += lhs.matrixData[(i * lhsCols) + k] * rhs.matrixData[(k * rhsCols) + j];
			}
			temp[(i * rhsCols) + j] = element;
		}
	}
	matrix2<U> result(lhsRows, rhsCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator*(const U& lhs, const matrix2<U>& rhs){
	U* temp = new U[lhs.m_nElements];
	for (int i = 0; i < lhs.m_nElements; i++) {
		temp[i] = lhs * rhs.matrixData[i];
	}
	matrix2<U> result(lhs.m_nRows, lhs.m_nCols, temp);
	delete[] temp;
	return result;
}

template<class U>
inline matrix2<U> operator*(const matrix2<U>& lhs, const U& rhs){
	U* temp = new U[lhs.m_nElements];
	for (int i = 0; i < lhs.m_nElements; i++) {
		temp[i] = lhs.matrixData[i] * rhs;
	}
	matrix2<U> result(lhs.m_nRows, lhs.m_nCols, temp);
	delete[] temp;
	return result;
}
