#include<deque>
namespace bit
{
	// 模拟堆
	template<class T, class Con = deque<T>>
	class stack

	{

	public:

		stack()	// 默认构造函数
		{}
		void push(const T& x) // 入栈
		{
			_c.push_back(x);
		}
		void pop() // 出栈
		{
			_c.pop_back();
		}
		T& top() // 返回栈顶元素
		{
			return _c.top();
		}
		const T& top()const //返回栈顶元素
		{
			return _c.top();
		}
		size_t size()const // 返回栈内元素个数
		{
			return _c.size();
		}
		bool empty()const //检查栈是否为空
		{
			return _c.empty();
		}
		~stack()
		{} // 析构函数
	private:
		Con _c;
	};

	// 模拟栈
	template<class T, class Con = deque<T>>
	class queue
	{
	public:
		queue() // 默认析构
		{}
		void push(const T& x)
		{
			_c.push_back(x);
		}
		void pop()
		{
			_c.pop_front();
		}
		T& back()
		{
			return _c.back();
		}
		const T& back()const
		{
			return _c.back();
		}
		T& front()
		{
			return _c.front();
		}
		const T& front()const
		{
			return _c.front();
		}
		size_t size()const
		{
			return _c.size();
		}
		bool empty()const
		{
			return _c.empty();
		}
	private:
		Con _c;
	};
};
int main()
{
	return 0;
}