#include <iostream>
#include <string>



template<typename T, int size>
class TPQueue {
private:
	T arr[size] = { 0 };
	int last, first;
public:
	TPQueue() :last(0), first(0) {}
	void push(T x) {
		int i = last;
		for (; (i >= first) && arr[i % size].prior < x.prior; --i) {
			arr[(i + 1) % size] = arr[i % size];
		}
		arr[(i + 1) % size] = x;
		last++;
	}
	T pop() {
		return arr[(first++) % size];
	}
	void print() {
		for (int i = first % size; i < last - first; ++i) {
			std::cout << arr[i].ch << ' ' << arr[i].prior << std::endl;
		}
	}
};

struct SYM {
	char ch;
	int prior;
};

int main()
{
	TPQueue<SYM, 5> pqueue;
	pqueue.push(SYM{ 'a', 4 });
	pqueue.push(SYM{ 'b', 7 });
	pqueue.push(SYM{ 'c', 6 });
	pqueue.push(SYM{ 'd', 5 });
	pqueue.push(SYM{ 'e', 8 });

	pqueue.print();
	std::cout << std::endl;

	SYM c1 = pqueue.pop();
	SYM c2 = pqueue.pop();

	pqueue.push(SYM{ 'f', 9 });
	pqueue.push(SYM{ 'g', 1 });
	//std::cout << "------------------------------------------------------------" << std::endl;
	//pqueue.print();

	SYM c3 = pqueue.pop();
	SYM c4 = pqueue.pop();
	//std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << c1.ch << " " << c1.prior << '\n' << c2.ch << " " << c2.prior << '\n' << c3.ch << " " << c3.prior << '\n' << c4.ch << " " << c4.prior << '\n';
	return 0;
}