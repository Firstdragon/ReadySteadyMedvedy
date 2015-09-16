template <class T> class ListElement {

public:

	T data;
	ListElement<T>* next;

	ListElement(const T& el)
	{
		data = el;
		next = NULL;
	}

};

template <class T> class IList
{
public:

	IList()
	{
		size = 0;
		head = NULL;
		back = NULL;
	}

	~IList()
	{

		ListElement<T>* temp = head;
		while (head != NULL)
		{
			head->next = temp->next;
			delete temp;
			temp = head;
		}


	}

	int size()
	{
		return size;
	}

	void add(const T& elem)
	{

		ListElement<T>* temp = new ListElement<T>(elem);

		if (size == 0)
		{
			head = temp;
			back = head;
			size++;
		}
		else
		{
			back->next = temp;
			back = temp;
			size++;
		}


	}

	int numberOf(const T& elem)
	{
		int counter = 0;
		ListElement<T>* temp = head;
		while (temp != NULL)
		{
			if (temp->data == elem)
				counter++;
			temp = temp->next;
		}
		return counter;
	}

private:
	ListElement<T>* head;
	ListElement<T>* back;
	int size;
};
