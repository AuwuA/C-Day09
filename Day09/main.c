#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

/*结构体*/
// 关键字 struct 代表这是一个结构体类型
// stu是这个结构体的名字
// 整个结构体的类型是 struct stu
// 结构体类型是struct stu {} 中是结构体的成员，一共有3个成员，每个成员的类型可以是任意的类型
// 注意 结构struct stu它只是一个类型只是一个模板，没有空间，不可以给结构体成员赋值，如不能让int = 10
struct stu
{
    int id;
    int age;
    char name[128];
}a, b;// 定义类型时同时定义两个结构体变量struct stu a, b;

struct stu c;

// 匿名结构体
struct
{
    int id;
    int age;
    char name[128];
} Mike, Bob;

// 结构体初始化
void test01()
{
//    1、全部初始化
//    struct stu d = {
//        1,
//        20,
//        "ubunqu"
//    };
//  2、部分初始化
//    struct stu d = {
//        .age = 20
//    };

//   如何操作结构体成员使用 .
//   如果使用结构体指针操作结构体成员使用 ->
//    struct stu d;
//    d.age = 20;
//    d.id = 2;
//    d.name = "ubunqu";//数组名是一个常量不能赋值，要赋值只能在初始化的时候
//    strcpy(d.name, "ubunqu");
//    printf("id = %d, age = %d, name = %s\n", d.id, d.age, d.name);

    struct stu d;
    (&d)->age = 20;
    (&d)->id = 2;
    strcpy((&d)->name, "ubunqu");
    printf("id = %d, age = %d, name = %s\n", d.id, d.age, d.name);
}

// 结构体数组
void test02()
{
    struct stu num[5] = {
    {1, 20, "Lucy"},
    {2, 21, "Bob"},
    {3, 22, "Peter"},
    {4, 25, "Mike"},
    {5, 26, "ubunqu"}
    };
    for (unsigned long long var = 0; var < sizeof num / sizeof(struct stu); ++var) {
        printf("id = %d, age = %d, name = %s\n", num[var].id, num[var].age, num[var].name);
    }
}

// 结构体嵌套结构体
struct heima_stu
{
//    int id;
//    int age;
//    char name[128];
    struct stu s;
    char subject[128];
};

void test03()
{
    struct heima_stu heima;
    heima.s.id = 1;
    heima.s.age = 22;
    strcpy(heima.s.name, "ubunqu");
    strcpy(heima.subject, "C++");
    printf("id = %d, age = %d, name = %s, subjects = %s\n", heima.s.id, heima.s.age, heima.s.name, heima.subject);
}

void memcpy_str(struct stu *x, struct stu *y)
{
    memcpy(x, y, sizeof(struct stu));
}

void test04()
{
    struct stu a = {1, 34, "bob"};
    struct stu b;
    memcpy_str(&b, &a);
    printf("id = %d, age = %d, name = %s\n", b.id, b.age, b.name);
}

// 结构体嵌套指针
struct t
{
    int a;
};

struct tea
{
    int id;
    char *p;
    struct t *b;
};

void test05()
{
    struct tea *tmp = (struct tea *)malloc(sizeof(struct tea));
    tmp->id = 100;
//    tmp->p = "hello";
//    printf("%s\n", tmp->p);
    tmp->b = malloc(sizeof(struct t));
    tmp->b->a = 200;
    tmp->p = malloc(sizeof(char) * 1024);
    strcpy(tmp->p, "hello");
    printf("%d\n", tmp->b->a);
    printf("%s\n", tmp->p);
    free(tmp->p);
    free(tmp->b);
    free(tmp);
    tmp = NULL;
}

// 结构体数组做函数参数
struct cl3 {
    int id;
    char name[128];
};

void set_num(struct cl3 *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        (p + i)->id = i + 10;
        sprintf((p + i)->name, "cl3 %d", i);
    }
}

void show_num(struct cl3 *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        (p + i)->id = i + 10;
        printf("id = %d, name = %s\n", (p + i)->id, (p + i)->name);
    }
}

void test06()
{
    struct cl3 num[5];
    memset(num, 0, sizeof(num));
    set_num(num, sizeof(num) / sizeof(struct cl3));
    show_num(num, sizeof(num) / sizeof(struct cl3));
}

// const 修饰的结构体指针
void test07()
{
//    struct cl3 a;
//    struct cl3 const *p = &a;
//    p->id = 100; // const修饰的是指针指向的变量，不能通过p修改p所知子昂的那块空间中的内容
//    struct cl3 * const p = &a;
//    struct cl3 b;
//    p = &b;
}

// 共用体
union mi {
    char a;
    short b;
    int c;
};

void test08()
{
    union mi tmp;
    tmp.a = 0x01;
    tmp.b = 0x0102;
    tmp.c = 0x01020304;
    printf("%x\n", tmp.a);// 4 小端数据
    printf("%x\n", tmp.b);
    printf("%x\n", tmp.c);
}

// 用共用体验证大小端数据
union mydata {
    char buf[4];
    int c;
};

void test09()
{
    union mydata data;
    data.c = 0x12345678;
    for (int var = 0; var < sizeof(data.buf) / sizeof(char); ++var) {
        printf("%x\n", data.buf[var]);
    }
}

// 枚举体

enum weather {
    SUN, RAIN,SNOW
};


void test10()
{
    enum weather tmp = SNOW;
    printf("tmp = %d\n", tmp);
}

// 给类型取别名
enum BOOL {
    false, true
};

typedef enum BOOL bool;


typedef struct stt{
    int id;
    int age;
} AAA;

typedef struct stt TT;
typedef struct stt BB;
void tet11()
{
    TT tmp;
    tmp.id = 10;
    tmp.age = 20;
    BB p;
    p.id = 10;
    p.age = 20;
}

// typedef和#define的区别
#define CHAR char*
typedef char * CHAR32;


void test12()
{
    CHAR x, y;// char *x, y;
    CHAR32 j, k;//
    printf("%d %d\n", sizeof(x), sizeof(y));
    printf("%d %d\n", sizeof(j), sizeof(k));
}

int main()
{
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
//    test08();
//    test09();
//    test10();
    test12();

    return 0;
}
