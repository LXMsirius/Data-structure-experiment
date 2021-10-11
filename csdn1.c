#include<stdio.h>
#include <stdlib.h>
#include <string.h>

size_t my_strlen(const char* pSrc)//通过字符指针可以测出字符数组大小
{
	size_t ret = 0;
	if (NULL == pSrc)
	{
		return ret;
	}

	while (*pSrc++)//注意,*pSrc++返回的是自加之前的值,"++"优先级高于"*",所以while中是" *(pSrc++) ",也就是指针自加后,再取值,自加的仍然是"指针",也就是指针向后移动一格
	{//本质上,这个函数是利用了char数组作为字符串时,约定最后一位是"\0"而生效的
		ret++;
	}//看来,确实不存在任何一种方法能测出c语言数组的大小,只能再分配内存空间时记住这个大小
	return ret;
}

char* my_push_back2(char* array, char c){
    size_t size = my_strlen(array);
    size += 1;//这个size是不包含"\0"的size,所以,在分配内存空间realloc时,还需要再加1
    array = (char*)realloc(array, size+1);
	array[(size+1)-2] = c;
    array[(size+1)-1] = '\0';
    return array;
}

char* my_push_back3(char** array, char c){
    size_t size = my_strlen(*array);
    size += 1;//这个size是不包含"\0"的size,所以,在分配内存空间realloc时,还需要再加1
    *array = (char*)realloc(*array, size+1);
	*(*array+(size+1-2)) = c;//思考为什么不是**(array+(size+1-2)) (同样是char类型)
    *(*array+(size+1-1)) = '\0';
    return *array;
}
/*
修正一个思想
c语言的函数参数,是不能在函数内部被修改的!!!因为传进来的参数,是拷贝构造
我们平时说"传指针就可以在函数内修改参数",实际上是误导学生的说法,
因为这个时候,函数的参数是指针,而这时候你会发现,你函数返回以后,这个指针变量没有被修改,也就是说,函数的参数还是没有被修改!!!!
一旦学生遇到一个"需要操作指针变量"的函数时,这种思想荼毒很深!!!!!

应该这么记忆(三点)
1.函数函数参数,是不能在函数内部被修改的
2.但是,在函数内部仍然使用可以用某个变量的指针,直接指向函数外部,修改这个外部变量的值
3.函数的参数,可以是你需要修改的那个变量的指针

套用上面的新思想,我来设计这个动态数组的push函数
push函数设计:
功能:
已知char数组的首地址array(char*类型)
使用realloc为这个char数组重新分配空间(让他的size + 1)
在数组的倒数第2位写入要"push"的字符(char类型)
在数组的倒数第1位写入字符串结束符'\0'

出现问题:
realloc在某些情况下,重新分配内存空间的首地址,并不是原来的那个地址
所以array的值需要被更新

解决问题思路:
利用"新思想",既然我们希望在函数内修改变量array的值,
我们可以把函数参数用于接收变量arr的指针(char**类型)


分析*(*array+(size+1-1))
这个表达式想达到的目标:
用char**类型指针(也就是array),访问char数组中任意元素的值
所需知识点:
1.*(char*类型 + num)可以访问char数组的任意下标
思想:
我们需要凑成如上这个"用指针访问数组的形式"
已知条件array,是char**类型,我们先把他变为 char*类型,于是加个"*"号变成 "*array"
有了char* 进一步凑公式
*(*array + num),这就是能访问char数组的任意一个值了

知识点解析:
为什么*(char*类型 + num)可以访问数组元素??
推荐大家系统学习这个博客的知识
https://blog.csdn.net/daiyutage/article/details/8604720
*/


int main()
{
    char *line = (char *)malloc(6); 
    //strcpy(line, "CHINA");//注意"\0"的问题,CHINA有5个字符,但是c语言自带的strcpy会给最后一个字符加上\0,原本我malloc写的是5,但是发现如果写5,strcpy不会出错,但是realloc会报错!!!!不知道这是为什么
    line = (char *)realloc(line, 7);
    

    char *arr = (char *)malloc(4); 
	arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = '\0';
    printf("%s\n",arr);
	int num = my_strlen(arr);
    printf("array length %d\n",num);

    arr = my_push_back2(arr, 'd');
    printf("%s\n",arr);
	my_push_back3(&arr, 'e');
    printf("%s\n",arr);

    return(0);
    
}

