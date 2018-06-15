class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
		:_capacity(100)
    {
        _s = (int*)malloc(_capacity * sizeof(int));
        _min = (int*)malloc(_capacity * sizeof(int));
        _size = 0;
    }
    
    ~MinStack()
    {
		//析构函数，虽然没有要求写，但是不写不好，会内存泄露
        free(_s);
        free(_min);
    }
    
    void push(int x) {
        checkCapacity();//检查容量
        *(_s + _size) = x;//先入栈x
		//最小值栈存最小值
        if (_size == 0)
        {
            *(_min + _size) = x;
        }
        else
        {
            if (*(_min + _size - 1) < x)
            {
                *(_min + _size) = *(_min + _size - 1);
            }
            else
            {
                *(_min + _size) = x;
            }
        }
        _size++;
    }
    
    void pop() {
        if (_size != 0)
            _size--;
    }
    
    int top() {
        return *(_s + _size - 1);
    }
    
    int getMin() {
        return *(_min + _size - 1);
    }
private:
    void checkCapacity()
    {
        if (_size == _capacity)
        {
            _capacity += 500;
            _s = (int*)realloc(_s, _capacity * sizeof(int));
            _min = (int*)realloc(_min, _capacity * sizeof(int));
        }
    }
private:
    int* _s;
    int* _min;
    int _size;
    int _capacity;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */