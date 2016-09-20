# Coro
用c语言setjmp和longjmp实现的一个最基本的协程，详见[blog](http://www.cnblogs.com/adinosaur/p/5889014.html)。

## Usage
模块只有三个接口：

1. coro_new创建一个协程。
2. coro_yield将控制返回给主（调度）协程。
3. coro_main运行主（调度协程）。
```
void co1(void* msg)
{
	for (int i = 0; i != 5; ++i)
	{
		printf("%s\n", (char*)msg);
		coro_yield();
	}
}

int main(int ac, char** av)
{
	coro_new(co1, "hello");
	coro_new(co1, "world");
	coro_main();
	return 0;
}
```
