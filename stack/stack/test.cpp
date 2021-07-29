#include<deque>
namespace bit
{
	// ģ���
	template<class T, class Con = deque<T>>
	class stack

	{

	public:

		stack()	// Ĭ�Ϲ��캯��
		{}
		void push(const T& x) // ��ջ
		{
			_c.push_back(x);
		}
		void pop() // ��ջ
		{
			_c.pop_back();
		}
		T& top() // ����ջ��Ԫ��
		{
			return _c.top();
		}
		const T& top()const //����ջ��Ԫ��
		{
			return _c.top();
		}
		size_t size()const // ����ջ��Ԫ�ظ���
		{
			return _c.size();
		}
		bool empty()const //���ջ�Ƿ�Ϊ��
		{
			return _c.empty();
		}
		~stack()
		{} // ��������
	private:
		Con _c;
	};

	// ģ��ջ
	template<class T, class Con = deque<T>>
	class queue
	{
	public:
		queue() // Ĭ������
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