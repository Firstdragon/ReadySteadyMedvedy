template <class T> class IList {
public:
	virtual int size() = 0;
	virtual int numberOf(const T& elem);
	virtual void add(const T& elem) = 0;
	virtual void removeAll(const T& elem) = 0;
};