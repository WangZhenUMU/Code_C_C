#include<vector>
#include<functional>
namespace bit
{
	template <class T, class Container = vector<T>, class Compare = less<T> >
	class priority_queue
	{
	public:
		// 构造
		priority_queue():_c()
		{}
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last):_c(first,last)
		{
			int count = _c.size();
			for (int root = (count - 2) >> 1; root >= 0; root--)
			{
				AdjustDown(root);
			}
		}
		bool empty() const // 判空
		{
			return _c.empty();
		}
		size_t size() const
		{
			return _c.size();
		}
		T& top() const // 返回堆顶元素
		{
			return _c.front();
		}

		void push(const T& x) // 入堆 
		{
			_c.push_back(x);
			AdjustUp(_c.size() - 1);
		}
		void pop() // 出堆
		{
			if (empty())
				return;
			std::swap(_c.front(), _c.back());
			_c.pop_back();
			AdjustDown(0);
		}
	private:
		Container _c;
		Compare comp;
		void AdjustUP(int child) // 向上调整
		{
			int parent = (child - 1) >> 1;
			while (child)
			{
				if (Com(_c[child], _c[parent]))
				{
					std::swap(_c[child], _c[parent]);
					child = parent;
					parent = (child - 1) >> 1;
				}
				else
				{
					return;
				}
			}
		}
		void AdjustDown(int parent) // 向下调整
		{
			int child = (parent << 1) + 1;
			while (child < _c.size())
			{
				//找出较大的child
				if (child + 1 < _c.size() && Com(_c[child], _c[child + 1]))
					child++;
				if (Com(_c[parent], _c[child]))
				{
					std::swap(_c[parent], _c[child]);
					parent = child;
					child = (parent << 1) + 1;
				}
				else
					return;
			}
		}
	};
}; 
int main()
{
	return 0;
}